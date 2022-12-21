# Newton-Raphson Method

Implementation of the Newton-Raphson method to get the closest zero of any well-behaved function to any point x. If no
derivative of the function is provided, it will be approximated using the limit. However, using the derivative makes it
possible to deviate further with your first guess from the actual zero.

## Building

To build this project use [CMake](https://cmake.org/). Create a build directory, change into it, then run `cmake ..`.

### Testing

Unit tests use [check](https://libcheck.github.io/check/). To run the test, build the target `newton-raphson-test`
via CMake and run the resulting executable.
