CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
SET(PROJECT_NAME "newton-raphson")

PROJECT(${PROJECT_NAME} C)

FILE(GLOB PROJECT_SRC *.c *.h)

ADD_LIBRARY(${PROJECT_NAME} ${PROJECT_SRC})
