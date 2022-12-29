# cDHBW Project Implementations

Content for the C course taught by Jannik Wiessler at the DHBW.

## Projects

Projects are described in the `Programmentwurf` directory. Currently implemented are:

- "Complex Calculator", files are in the `HA1` directory
- "Newton-Raphson", files are in the `HA2` directory

## Building

[CMake](https://cmake.org/) is used as build system. The steps are as follows:

1. Install CMake and a working compiler.
2. Clone this project including all of its submodules.
3. At the project top level, create a build directory like `build`.
4. Open a terminal and change into the build directory.
5. From there, run `cmake ..`. Now is the time on Windows to tell CMake if you use something other than the Microsoft
   compiler. For example, if you are using the MinGW compiler, run `cmake .. -G "MinGW Makefiles"` instead.
6. After CMake is done configuring, run `cmake --build .` to actual build the project. To pick a specific target, use
   the `-t` flag. The output has the same structure as the project itself.
