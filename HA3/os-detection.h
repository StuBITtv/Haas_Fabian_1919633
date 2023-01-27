//
// Created by fhs on 27.01.2023.
//

#ifndef C_COURSE_OS_DETECTION_H
#define C_COURSE_OS_DETECTION_H

#if defined(_WIN32) || defined(_WIN64) || defined(__CYWIN__)
#define IS_WINDOWS
#elif defined(__unix__)
#define IS_UNIX
#elif defined(__APPLE__) || defined(__MACH__)
#define IS_OSX
#else
#error "Uknown operating system"
#endif

#endif //C_COURSE_OS_DETECTION_H
