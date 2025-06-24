//
//  HVLogger.h
//
//  Created by Karl Stenerud on 11-06-25.
//
//  Copyright (c) 2011 Karl Stenerud. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall remain in place
// in this source code.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

/**
 * HVLogger
 * ========
 *
 * Prints log entries to the console consisting of:
 * - Level (Error, Warn, Info, Debug, Trace)
 * - File
 * - Line
 * - Function
 * - Message
 *
 * Allows setting the minimum logging level in the preprocessor.
 *
 * Works in C or Objective-C contexts, with or without ARC, using CLANG or GCC.
 *
 *
 * =====
 * USAGE
 * =====
 *
 * Set the log level in your "Preprocessor Macros" build setting. You may choose
 * TRACE, DEBUG, INFO, WARN, ERROR. If nothing is set, it defaults to ERROR.
 *
 * Example: HVLogger_Level=WARN
 *
 * Anything below the level specified for HVLogger_Level will not be compiled
 * or printed.
 *
 *
 * Next, include the header file:
 *
 * #include "HVLogger.h"
 *
 *
 * Next, call the logger functions from your code (using objective-c strings
 * in objective-C files and regular strings in regular C files):
 *
 * Code:
 *    HVLOG_ERROR(@"Some error message");
 *
 * Prints:
 *    2011-07-16 05:41:01.379 TestApp[4439:f803] ERROR: SomeClass.m (21): -[SomeFunction]: Some error message
 *
 * Code:
 *    HVLOG_INFO(@"Info about %@", someObject);
 *
 * Prints:
 *    2011-07-16 05:44:05.239 TestApp[4473:f803] INFO : SomeClass.m (20): -[SomeFunction]: Info about <NSObject:
 * 0xb622840>
 *
 *
 * The "BASIC" versions of the macros behave exactly like NSLog() or printf(),
 * except they respect the HVLogger_Level setting:
 *
 * Code:
 *    HVLOGBASIC_ERROR(@"A basic log entry");
 *
 * Prints:
 *    2011-07-16 05:44:05.916 TestApp[4473:f803] A basic log entry
 *
 *
 * NOTE: In C files, use "" instead of @"" in the format field. Logging calls
 *       in C files do not print the NSLog preamble:
 *
 * Objective-C version:
 *    HVLOG_ERROR(@"Some error message");
 *
 *    2011-07-16 05:41:01.379 TestApp[4439:f803] ERROR: SomeClass.m (21): -[SomeFunction]: Some error message
 *
 * C version:
 *    HVLOG_ERROR("Some error message");
 *
 *    ERROR: SomeClass.c (21): SomeFunction(): Some error message
 *
 *
 * =============
 * LOCAL LOGGING
 * =============
 *
 * You can control logging messages at the local file level using the
 * "HVLogger_LocalLevel" define. Note that it must be defined BEFORE
 * including HVLogger.h
 *
 * The HVLOG_XX() and HVLOGBASIC_XX() macros will print out based on the LOWER
 * of HVLogger_Level and HVLogger_LocalLevel, so if HVLogger_Level is DEBUG
 * and HVLogger_LocalLevel is TRACE, it will print all the way down to the trace
 * level for the local file where HVLogger_LocalLevel was defined, and to the
 * debug level everywhere else.
 *
 * Example:
 *
 * // HVLogger_LocalLevel, if defined, MUST come BEFORE including HVLogger.h
 * #define HVLogger_LocalLevel TRACE
 * #import "HVLogger.h"
 *
 *
 * ===============
 * IMPORTANT NOTES
 * ===============
 *
 * The C logger changes its behavior depending on the value of the preprocessor
 * define HVLogger_CBufferSize.
 *
 * If HVLogger_CBufferSize is > 0, the C logger will behave in an async-safe
 * manner, calling write() instead of printf(). Any log messages that exceed the
 * length specified by HVLogger_CBufferSize will be truncated.
 *
 * If HVLogger_CBufferSize == 0, the C logger will use printf(), and there will
 * be no limit on the log message length.
 *
 * HVLogger_CBufferSize can only be set as a preprocessor define, and will
 * default to 1024 if not specified during compilation.
 */

// ============================================================================
#pragma mark - (internal) -
// ============================================================================

#ifndef HDR_KSLogger_h
#define HDR_KSLogger_h

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __OBJC__

#import <CoreFoundation/CoreFoundation.h>

void i_kslog_logObjC(const char *level, const char *file, int line, const char *function, CFStringRef fmt, ...);

void i_kslog_logObjCBasic(CFStringRef fmt, ...);

#define i_KSLOG_FULL(LEVEL, FILE, LINE, FUNCTION, FMT, ...) \
    i_kslog_logObjC(LEVEL, FILE, LINE, FUNCTION, (__bridge CFStringRef)FMT, ##__VA_ARGS__)
#define i_KSLOG_BASIC(FMT, ...) i_kslog_logObjCBasic((__bridge CFStringRef)FMT, ##__VA_ARGS__)

#else  // __OBJC__

void i_kslog_logC(const char *level, const char *file, int line, const char *function, const char *fmt, ...);

void i_kslog_logCBasic(const char *fmt, ...);

#define i_KSLOG_FULL i_kslog_logC
#define i_KSLOG_BASIC i_kslog_logCBasic

#endif  // __OBJC__

/* Back up any existing defines by the same name */
#ifdef HV_NONE
#define HVLOG_BAK_NONE HV_NONE
#undef HV_NONE
#endif
#ifdef ERROR
#define HVLOG_BAK_ERROR ERROR
#undef ERROR
#endif
#ifdef WARN
#define HVLOG_BAK_WARN WARN
#undef WARN
#endif
#ifdef INFO
#define HVLOG_BAK_INFO INFO
#undef INFO
#endif
#ifdef DEBUG
#define HVLOG_BAK_DEBUG DEBUG
#undef DEBUG
#endif
#ifdef TRACE
#define HVLOG_BAK_TRACE TRACE
#undef TRACE
#endif

#define HVLogger_Level_None 0
#define HVLogger_Level_Error 10
#define HVLogger_Level_Warn 20
#define HVLogger_Level_Info 30
#define HVLogger_Level_Debug 40
#define HVLogger_Level_Trace 50

#define HV_NONE HVLogger_Level_None
#define ERROR HVLogger_Level_Error
#define WARN HVLogger_Level_Warn
#define INFO HVLogger_Level_Info
#define DEBUG HVLogger_Level_Debug
#define TRACE HVLogger_Level_Trace

#ifndef HVLogger_Level
#define HVLogger_Level HVLogger_Level_Error
#endif

#ifndef HVLogger_LocalLevel
#define HVLogger_LocalLevel HVLogger_Level_None
#endif

#define a_KSLOG_FULL(LEVEL, FMT, ...) i_KSLOG_FULL(LEVEL, __FILE__, __LINE__, __PRETTY_FUNCTION__, FMT, ##__VA_ARGS__)

// ============================================================================
#pragma mark - API -
// ============================================================================

/** Set the filename to log to.
 *
 * @param filename The file to write to (NULL = write to stdout).
 *
 * @param overwrite If true, overwrite the log file.
 */
bool kslog_setLogFilename(const char *filename, bool overwrite);

/** Clear the log file. */
bool kslog_clearLogFile(void);

/** Tests if the logger would print at the specified level.
 *
 * @param LEVEL The level to test for. One of:
 *            HVLogger_Level_Error,
 *            HVLogger_Level_Warn,
 *            HVLogger_Level_Info,
 *            HVLogger_Level_Debug,
 *            HVLogger_Level_Trace,
 *
 * @return TRUE if the logger would print at the specified level.
 */
#define HVLOG_PRINTS_AT_LEVEL(LEVEL) (HVLogger_Level >= LEVEL || HVLogger_LocalLevel >= LEVEL)

/** Log a message regardless of the log settings.
 * Normal version prints out full context. Basic version prints directly.
 *
 * @param FMT The format specifier, followed by its arguments.
 */
#define HVLOG_ALWAYS(FMT, ...) a_KSLOG_FULL("FORCE", FMT, ##__VA_ARGS__)
#define HVLOGBASIC_ALWAYS(FMT, ...) i_KSLOG_BASIC(FMT, ##__VA_ARGS__)

/** Log an error.
 * Normal version prints out full context. Basic version prints directly.
 *
 * @param FMT The format specifier, followed by its arguments.
 */
#if HVLOG_PRINTS_AT_LEVEL(HVLogger_Level_Error)
#define HVLOG_ERROR(FMT, ...) a_KSLOG_FULL("ERROR", FMT, ##__VA_ARGS__)
#define HVLOGBASIC_ERROR(FMT, ...) i_KSLOG_BASIC(FMT, ##__VA_ARGS__)
#else
#define HVLOG_ERROR(FMT, ...)
#define HVLOGBASIC_ERROR(FMT, ...)
#endif

/** Log a warning.
 * Normal version prints out full context. Basic version prints directly.
 *
 * @param FMT The format specifier, followed by its arguments.
 */
#if HVLOG_PRINTS_AT_LEVEL(HVLogger_Level_Warn)
#define HVLOG_WARN(FMT, ...) a_KSLOG_FULL("WARN ", FMT, ##__VA_ARGS__)
#define HVLOGBASIC_WARN(FMT, ...) i_KSLOG_BASIC(FMT, ##__VA_ARGS__)
#else
#define HVLOG_WARN(FMT, ...)
#define HVLOGBASIC_WARN(FMT, ...)
#endif

/** Log an info message.
 * Normal version prints out full context. Basic version prints directly.
 *
 * @param FMT The format specifier, followed by its arguments.
 */
#if HVLOG_PRINTS_AT_LEVEL(HVLogger_Level_Info)
#define HVLOG_INFO(FMT, ...) a_KSLOG_FULL("INFO ", FMT, ##__VA_ARGS__)
#define HVLOGBASIC_INFO(FMT, ...) i_KSLOG_BASIC(FMT, ##__VA_ARGS__)
#else
#define HVLOG_INFO(FMT, ...)
#define HVLOGBASIC_INFO(FMT, ...)
#endif

/** Log a debug message.
 * Normal version prints out full context. Basic version prints directly.
 *
 * @param FMT The format specifier, followed by its arguments.
 */
#if HVLOG_PRINTS_AT_LEVEL(HVLogger_Level_Debug)
#define HVLOG_DEBUG(FMT, ...) a_KSLOG_FULL("DEBUG", FMT, ##__VA_ARGS__)
#define HVLOGBASIC_DEBUG(FMT, ...) i_KSLOG_BASIC(FMT, ##__VA_ARGS__)
#else
#define HVLOG_DEBUG(FMT, ...)
#define HVLOGBASIC_DEBUG(FMT, ...)
#endif

/** Log a trace message.
 * Normal version prints out full context. Basic version prints directly.
 *
 * @param FMT The format specifier, followed by its arguments.
 */
#if HVLOG_PRINTS_AT_LEVEL(HVLogger_Level_Trace)
#define HVLOG_TRACE(FMT, ...) a_KSLOG_FULL("TRACE", FMT, ##__VA_ARGS__)
#define HVLOGBASIC_TRACE(FMT, ...) i_KSLOG_BASIC(FMT, ##__VA_ARGS__)
#else
#define HVLOG_TRACE(FMT, ...)
#define HVLOGBASIC_TRACE(FMT, ...)
#endif

// ============================================================================
#pragma mark - (internal) -
// ============================================================================

/* Put everything back to the way we found it. */
#undef ERROR
#ifdef HVLOG_BAK_ERROR
#define ERROR HVLOG_BAK_ERROR
#undef HVLOG_BAK_ERROR
#endif
#undef WARNING
#ifdef HVLOG_BAK_WARN
#define WARNING HVLOG_BAK_WARN
#undef HVLOG_BAK_WARN
#endif
#undef INFO
#ifdef HVLOG_BAK_INFO
#define INFO HVLOG_BAK_INFO
#undef HVLOG_BAK_INFO
#endif
#undef DEBUG
#ifdef HVLOG_BAK_DEBUG
#define DEBUG HVLOG_BAK_DEBUG
#undef HVLOG_BAK_DEBUG
#endif
#undef TRACE
#ifdef HVLOG_BAK_TRACE
#define TRACE HVLOG_BAK_TRACE
#undef HVLOG_BAK_TRACE
#endif

#ifdef __cplusplus
}
#endif

#endif  // HDR_KSLogger_h
