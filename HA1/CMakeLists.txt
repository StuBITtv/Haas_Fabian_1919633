CMAKE_MINIMUM_REQUIRED(VERSION 3.24)

SET(PROJECT_NAME "ComplexCalculator")
SET(LIBRARY_NAME "ComplexNumbers")
SET(TEST_NAME "ComplexCalculatorTest")

PROJECT(${PROJECT_NAME} C)

# Complex numbers
FILE(GLOB LIBRARY_SRC src/complex-numbers/*.c src/complex-numbers/*.h)
ADD_LIBRARY(${LIBRARY_NAME} ${LIBRARY_SRC})

# Calculator
FILE(GLOB PROJECT_SRC src/*.c src/*.h)
ADD_EXECUTABLE(${PROJECT_NAME} ${PROJECT_SRC})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ComplexNumbers)

# Tests
add_subdirectory("test/lib/check")

FILE(GLOB TEST_SRC test/*.c test/*.h)
ADD_EXECUTABLE(${TEST_NAME} ${TEST_SRC})

TARGET_LINK_LIBRARIES(${TEST_NAME} ComplexNumbers check)