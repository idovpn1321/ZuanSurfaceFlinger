#include <linux/module.h>
#include <linux/kernel.h>
#include "sf_tuner.h"
#include "thermal_guard.h"

static int __init ksu_surfaceflinger_guard_init(void) {
    pr_info("[KSU-SFG] Initializing SurfaceFlinger Guard\n");
    thermal_guard_init();
    sf_tuner_init();
    return 0;
}

static void __exit ksu_surfaceflinger_guard_exit(void) {
    pr_info("[KSU-SFG] Exiting SurfaceFlinger Guard\n");
}

module_init(ksu_surfaceflinger_guard_init);
module_exit(ksu_surfaceflinger_guard_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZuanPrjkt");
MODULE_DESCRIPTION("KernelSU module for thermal-aware SurfaceFlinger tuning");