#include <linux/sched.h>
#include <linux/sched/task.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include "thermal_guard.h"

void sf_tuner_init(void) {
    struct task_struct *task;
    for_each_process(task) {
        if (strcmp(task->comm, "surfaceflinger") == 0) {
            int temp = get_valid_temperature();
            if (temp < 55000) {
                uclamp_se_set(task, UCLAMP_MIN, 614);
                uclamp_se_set(task, UCLAMP_MAX, 1024);
                pr_info("[KSU-SF] Tuning (cold): temp=%d\n", temp);
            } else if (temp < 65000) {
                uclamp_se_set(task, UCLAMP_MIN, 512);
                uclamp_se_set(task, UCLAMP_MAX, 768);
                pr_info("[KSU-SF] Tuning (warm): temp=%d\n", temp);
            } else {
                pr_warn("[KSU-SF] Skip tuning (hot): temp=%d\n", temp);
            }
        }
    }
}