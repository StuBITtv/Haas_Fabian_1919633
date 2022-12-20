CMAKE_MINIMUM_REQUIRED(VERSION 3.24)

SET(PROJECT_NAME "ComplexCalculator")
SET(COMPLEX_LIBRARY_NAME "ComplexNumbers")
SET(CLI_LIBRARY_NAME "CalculatorCli")
SET(TEST_NAME "ComplexCalculatorTest")

PROJECT(${PROJECT_NAME} C)

# Complex numbers
FILE(GLOB COMPLEX_LIBRARY_SRC src/complex-numbers/*.c src/complex-numbers/*.h)
ADD_LIBRARY(${COMPLEX_LIBRARY_NAME} ${COMPLEX_LIBRARY_SRC})

# CLI
FILE(GLOB CLI_LIBRARY_SRC src/cli/*.c src/cli/*.h)
ADD_LIBRARY(${CLI_LIBRARY_NAME} ${CLI_LIBRARY_SRC})

# Calculator
FILE(GLOB PROJECT_SRC src/*.c src/*.h)
ADD_EXECUTABLE(${PROJECT_NAME} ${PROJECT_SRC})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${COMPLEX_LIBRARY_NAME} ${CLI_LIBRARY_NAME})

# Tests
FILE(
        GLOB TEST_SRC
        test/*.c test/*.h
        test/arithmetic/*.c test/arithmetic/*.h
        test/cli/*.c test/cli*.h
)

ADD_EXECUTABLE(${TEST_NAME} ${TEST_SRC})

TARGET_LINK_LIBRARIES(${TEST_NAME} ${COMPLEX_LIBRARY_NAME} ${CLI_LIBRARY_NAME} check test-runner)
