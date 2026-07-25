# box3d - <SUMMARY>

This is a `build2` package repository for [`box3d`](https://<UPSTREAM-URL>),
a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`box3d` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](<PACKAGE>/PACKAGE-README.md) file.

The development setup for `box3d` uses the standard `bdep`-based workflow.
For example:

```
git clone .../box3d.git
cd box3d

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
