ui_print "=========================================="
ui_print "        ⚡ ZuanSurfaceTweak Installer ⚡"
ui_print "=========================================="
ui_print ""

DEVICE=$(getprop ro.product.device)
MODEL=$(getprop ro.product.model)
MANU=$(getprop ro.product.manufacturer)
BOARD=$(getprop ro.product.board)
ANDROID=$(getprop ro.build.version.release)
KERNEL=$(uname -r)
RAM=$(grep MemTotal /proc/meminfo | awk '{printf("%.1f GB", $2/1024/1024)}')

ui_print "📱 DEVICE     : $DEVICE ($MODEL)"
ui_print "🏭 BRAND      : $MANU"
ui_print "🧱 BOARD      : $BOARD"
ui_print "📲 ANDROID    : $ANDROID"
ui_print "🧠 RAM        : $RAM"
ui_print "🧬 KERNEL     : $KERNEL"
ui_print ""

ui_print "Injecting SurfaceFlinger steroids..."
sleep 1
ui_print "Bypassing thermal whining..."
sleep 1

ui_print ""
ui_print "✅ Module installed successfully!"
ui_print "✨ Now sit back and pray it doesn't bootloop."
ui_print ""
ui_print "🧠 Pro tip: if your phone catches fire, that's a feature."
ui_print "📉 If you expected magic from a 2019 budget chip, blame yourself."
ui_print ""
ui_print "🔥 Lag is gone not because it's optimized—"
ui_print "   but because it gave up and died."
ui_print ""
ui_print "Thanks for using ZuanSurfaceTweak. We’ll miss your warranty."