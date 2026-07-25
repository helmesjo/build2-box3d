# libbox3d - 3D physics engine for games

This is a `build2` package for the [Box3D](https://github.com/erincatto/box3d)
C library. It provides a portable 3D rigid body physics engine for games
(collision detection, joints, continuous physics, and related features).


## Usage

To start using `libbox3d` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libbox3d ^0.1.0
```

Then import the library in your `buildfile`:

```
import libs = libbox3d%lib{box3d}
```

Public headers are installed under `include/box3d/`. Include them as:

```c
#include <box3d/box3d.h>
```


## Importable targets

This package provides the following importable targets:

```
lib{box3d}
```

This is the Box3D physics library.


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libbox3d.disable_simd     ?= false
[bool] config.libbox3d.double_precision ?= false
[bool] config.libbox3d.enable_assert    ?= false
[bool] config.libbox3d.validate         ?= true
```

`config.libbox3d.disable_simd` builds the scalar math fallback instead of
SSE2/NEON (`BOX3D_DISABLE_SIMD`). Slower. Implementation detail only (not
part of the public export interface).

`config.libbox3d.double_precision` enables large-world mode
(`BOX3D_DOUBLE_PRECISION`). World positions use double precision. This changes
the library ABI. The define is re-exported to consumers so headers and the
binary stay consistent.

`config.libbox3d.enable_assert` keeps `B3_ASSERT()` active in release builds
where `NDEBUG` is defined (`B3_ENABLE_ASSERT`). Matches the behaviour of
upstream's MSVC RelWithDebInfo configuration. The define is re-exported to
consumers so assertions are consistent across the boundary.

`config.libbox3d.validate` enables heavy internal validation (`BOX3D_VALIDATE`).
Validation only activates in builds where `NDEBUG` is not defined, it is a no-op
in release builds regardless of this setting.
