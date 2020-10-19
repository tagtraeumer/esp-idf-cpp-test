//
// Created by lieve on 11/06/2020.
//

#ifndef WATERTHING_IDF_SERIAL_H
#define WATERTHING_IDF_SERIAL_H

#include <cstdio>
#include <cstdarg>
#include <string>

static const char *EOL = "\n";

static void s_println(const char *text = "", ...) {
    std::string buf(text);
    buf.append(EOL);
    const char *cBuf = buf.c_str();

    va_list args;
    va_start(args, text);
    vprintf(cBuf, args);
    va_end(args);
};

static void s_print(const char *text, ...) {
    va_list args;
    va_start(args, text);
    vprintf(text, args);
    va_end(args);

    fflush(stdout);
}

#endif //WATERTHING_IDF_SERIAL_H
