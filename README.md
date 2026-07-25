# box3d

This is a `build2` package repository for [Box3D](https://github.com/erincatto/box3d),
a 3D physics engine for games written in portable C17.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libbox3d` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libbox3d/PACKAGE-README.md) file.

## Development

The development setup for `box3d` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules https://github.com/build2-packaging/box3d.git
cd box3d

bdep init -C @gcc c config.c=gcc
bdep update
bdep test
```
