#!/system/bin/sh

# CPU governor force performance
for i in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do
  echo performance > $i
done

# Set sched boost
echo 1 > /proc/sys/kernel/sched_boost

# Set scheduler migration delay jadi agresif
echo 0 > /proc/sys/kernel/sched_migration_cost_ns
echo 0 > /proc/sys/kernel/sched_latency_ns

# Force touchboost & inputboost (kalau ada)
for f in /sys/module/*/parameters/*boost*; do
  echo 1 > $f 2>/dev/null
done

# 💥 Load modul KernelSU SurfaceFlinger Guard
MODDIR=${0%/*}
insmod "$MODDIR/ksu/surfaceflinger_guard/ksu_surfaceflinger_guard.ko"

# ⛔ (Opsional) Hapus tuning manual SurfaceFlinger karena udah ditangani modul
# Prioritaskan SurfaceFlinger (uclamp hack)
# pid=$(pidof surfaceflinger)
# if [ ! -z "$pid" ]; then
#   echo 1024 > /dev/uclamp/$pid/uclamp.min 2>/dev/null
#   echo 1024 > /dev/uclamp/$pid/uclamp.max 2>/dev/null
# fi

# Set I/O scheduler (bisa disk lain juga)
echo bfq > /sys/block/mmcblk0/queue/scheduler

# Make sure this script stays executable (for multi-device safety)
chmod 0755 "$0"