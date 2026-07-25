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

...
