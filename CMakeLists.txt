CMAKE_MINIMUM_REQUIRED(VERSION 3.24)

PROJECT("C course")

INCLUDE_DIRECTORIES("lib/test-runner" "lib/check" "lib/cli-input")

ADD_SUBDIRECTORY("lib/check")
ADD_SUBDIRECTORY("lib/test-runner")
ADD_SUBDIRECTORY("lib/cli-input")

ADD_SUBDIRECTORY("HA1")
ADD_SUBDIRECTORY("HA2")
