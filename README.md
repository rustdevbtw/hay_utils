hay/utils.h -- utility functions for Hay projects
=================================================
A **Hay Suite** project.

## Building
To build it, you'll need:
1. `cmake`
2. `make`

You can build it by doing:
```sh
# Create the build dir (that's where the build will happen)
mkdir -pv build
# cd into the build dir
cd build
# configure cmake
cmake ..
# build
cmake --build .
```
> NOTE: It builds that as a static library (recommended).
  If you want that to be shared, use `-DSHARED_utils=ON` as the CMake option.  

## Contributing
### Generating manpages
You can generate the manpage, by modifying the `man/hay_utils.md` file.  
Once you're done, you'll need `ronn` (`ronn-ng` recommended).  
You can generate them with:
```sh
ronn --roff man/hay_utils.md --manual=hay/utils.h --organization="The Hay Project"
```
You don't always have to do this, though. Every push to `master` automatically triggers a test CI.  
Among testing, it also generates this manpage.

### Testing
This project comes with (some) tests. They're in `tests` dir.  
You can run them with:
```sh
# assuming you've already built it atleast once
cd build
ctest
```
If you want to disable building the tests, you can use `-DBUILD_tests=OFF` as the CMake option.

### Notes for `clangd` users
If you want to contribute to it, or develop on it, you should let `clangd` know about it, by doing:
```sh
# cd into the build dir (assumes you've already built it atleast once)
cd build
# copy
cp compile_commands.json ../
# cd back
cd ..
```

## License
All **Hay Suite** projects (including this one) are licensed under the **Mozilla Public License, version 2.0**.
