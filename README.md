# ZuanSurfaceTweak

ZuanSurfaceTweak is a lightweight performance module for Android, designed to improve UI responsiveness by optimizing SurfaceFlinger, CPU scheduling, and I/O handling. Built with KernelSU support and zero UI — just pure backend tuning.

---

## 🔧 Features

- **SurfaceFlinger Guard Module**
  - Injects `ksu_surfaceflinger_guard.ko` via KernelSU
  - Forces `uclamp.min/max` on SurfaceFlinger process
  - Keeps rendering performance consistent

- **Scheduler & CPU Tweaks**
  - Sets CPU governor to `performance`
  - Enables `sched_boost`
  - Disables scheduling and migration delays

- **Touch & I/O Tuning**
  - Enables `touchboost` / `inputboost` (if supported)
  - Sets I/O scheduler to `bfq`

- **Fully Automated**
  - Loads `.ko` automatically via `post-fs-data.sh`
  - Self-healing script permissions (`chmod 0755 "$0"`)

---

## 📦 Installation

- Flash via KernelSU Manager or Magisk (Zips properly structured)
- No configuration needed
- Compatible with GKI and non-GKI setups (as long as KernelSU is integrated)

---

## 📄 Changelog

### v2

- Injected `ksu_surfaceflinger_guard.ko` to force SurfaceFlinger priority
- CPU set to `performance` governor by default
- `sched_latency` and `migration_cost` tuned for lower scheduling overhead
- Touch and input boost enabled where available
- Applied `BFQ` scheduler on main block device
- All scripts include self-permission fixes

---

## ⚠️ Disclaimer

> Use at your own risk.  
> If your device overheats, bootloops, or becomes sentient, we are not responsible.

---

## 🙌 Credits

- Based on open kernel behavior via KernelSU  
- Maintained by [Zuan](https://github.com/idovpn1321)
