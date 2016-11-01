#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stdint.h>
#include <iostream>
#include <fstream>

//#define DEBUG_EVEM 1

#ifndef NULL
#define NULL 0
#endif

#ifdef _WIN32
#define BLARGG_USE_NAMESPACE 1
#endif

#define SAVE_FILE_SIGNATURE "EvEmSaveFile"
#define SAVE_FILE_VERSION 5

#define SafeDelete(pointer) if(pointer != NULL) {delete pointer; pointer = NULL;}
#define SafeDeleteArray(pointer) if(pointer != NULL) {delete [] pointer; pointer = NULL;}

#define InitPointer(pointer) ((pointer) = NULL)
#define IsValidPointer(pointer) ((pointer) != NULL)

#define FLAG_ZERO 0x80
#define FLAG_SUB 0x40
#define FLAG_HALF 0x20
#define FLAG_CARRY 0x10
#define FLAG_NONE 0

#define GAMEBOY_WIDTH 160
#define GAMEBOY_HEIGHT 144

enum Gameboy_Keys
{
    A_Key = 4,
    B_Key = 5,
    Start_Key = 7,
    Select_Key = 6,
    Right_Key = 0,
    Left_Key = 1,
    Up_Key = 2,
    Down_Key = 3
};

#ifdef DEBUG_EVEM
#define Log(msg, ...) (Log_func(msg, ##__VA_ARGS__))
#else
#define Log(msg, ...)
#endif

inline void Log_func(const char* const msg, ...)
{
    static int count = 1;
    char szBuf[512];
    va_list args;
    va_start(args, msg);
    vsprintf_s(szBuf, msg, args);
    va_end(args);

    printf("%d: %s\n", count, szBuf);

    count++;
}

#endif // DEFINITIONS_H
