#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include "thermal_guard.h"

#define MAX_PATH_LEN 128
#define MAX_TEMP 150000
#define INVALID_TEMP_THRESHOLD -1000

static int read_temp(const char *path) {
    struct file *f;
    mm_segment_t fs;
    char buf[16];
    int temp = -999999;

    f = filp_open(path, O_RDONLY, 0);
    if (IS_ERR(f)) return temp;

    fs = get_fs();
    set_fs(KERNEL_DS);
    vfs_read(f, buf, sizeof(buf)-1, &f->f_pos);
    buf[sizeof(buf)-1] = '\0';
    kstrtoint(buf, 10, &temp);
    set_fs(fs);
    filp_close(f, NULL);

    return temp;
}

int get_valid_temperature(void) {
    char path[MAX_PATH_LEN];
    int max_valid_temp = -999999;
    int i;

    for (i = 0; i < 30; i++) {
        snprintf(path, MAX_PATH_LEN, "/sys/class/thermal/thermal_zone%d/temp", i);
        int t = read_temp(path);
        if (t > INVALID_TEMP_THRESHOLD && t < MAX_TEMP) {
            if (t > max_valid_temp) max_valid_temp = t;
            pr_info("[KSU-Thermal] zone%d: %d m°C\n", i, t);
        } else {
            pr_warn("[KSU-Thermal] zone%d: INVALID temp (%d)\n", i, t);
        }
    }

    if (max_valid_temp < 0) {
        pr_warn("[KSU-Thermal] No valid temp found, fallback to 45000 m°C\n");
        max_valid_temp = 45000;
    }

    pr_info("[KSU-Thermal] Final usable temp: %d m°C\n", max_valid_temp);
    return max_valid_temp;
}

void thermal_guard_init(void) {
    get_valid_temperature();
}