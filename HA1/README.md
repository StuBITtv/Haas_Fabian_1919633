# Complex Calculator

Simple commando line based calculator to add, subtract, multiply, or divide two complex numbers.
The number are entered in the rectangular format $a+bi$.

## Building

To build this project use [CMake](https://cmake.org/). Create a build directory, change into it, then run `cmake ..`

### Testing

Unit tests use [check](https://libcheck.github.io/check/). To run the text, build the target `ComplexCalculatorTest` via
CMake and run the resulting executable.
