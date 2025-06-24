//
//  HVCrashReportFields.h
//
//  Created by Karl Stenerud on 2012-10-07.
//
//  Copyright (c) 2012 Karl Stenerud. All rights reserved.
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

#ifndef HDR_HVCrashReportFields_h
#define HDR_HVCrashReportFields_h

#ifdef __OBJC__
#include <Foundation/Foundation.h>
typedef NSString *HVCrashReportField;
#define HVCRF_CONVERT_STRING(str) @str
#else /* __OBJC__ */
typedef const char *HVCrashReportField;
#define HVCRF_CONVERT_STRING(str) str
#endif /* __OBJC__ */

#ifndef NS_TYPED_ENUM
#define NS_TYPED_ENUM
#endif

#ifndef NS_SWIFT_NAME
#define NS_SWIFT_NAME(_name)
#endif

#define HVCRF_DEFINE_CONSTANT(type, name, swift_name, string) \
    static type const type##_##name NS_SWIFT_NAME(swift_name) = HVCRF_CONVERT_STRING(string);

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark - Report Types -

typedef HVCrashReportField HVCrashReportType NS_TYPED_ENUM NS_SWIFT_NAME(ReportType);

HVCRF_DEFINE_CONSTANT(HVCrashReportType, Minimal, minimal, "minimal")
HVCRF_DEFINE_CONSTANT(HVCrashReportType, Standard, standard, "standard")
HVCRF_DEFINE_CONSTANT(HVCrashReportType, Custom, custom, "custom")

#pragma mark - Memory Types -

typedef HVCrashReportField HVCrashMemType NS_TYPED_ENUM NS_SWIFT_NAME(MemoryType);

HVCRF_DEFINE_CONSTANT(HVCrashMemType, Block, block, "objc_block")
HVCRF_DEFINE_CONSTANT(HVCrashMemType, Class, class, "objc_class")
HVCRF_DEFINE_CONSTANT(HVCrashMemType, NullPointer, nullPointer, "null_pointer")
HVCRF_DEFINE_CONSTANT(HVCrashMemType, Object, object, "objc_object")
HVCRF_DEFINE_CONSTANT(HVCrashMemType, String, string, "string")
HVCRF_DEFINE_CONSTANT(HVCrashMemType, Unknown, unknown, "unknown")

#pragma mark - Exception Types -

typedef HVCrashReportField HVCrashExcType NS_TYPED_ENUM NS_SWIFT_NAME(ExceptionType);

HVCRF_DEFINE_CONSTANT(HVCrashExcType, CPPException, cppException, "cpp_exception")
HVCRF_DEFINE_CONSTANT(HVCrashExcType, Deadlock, deadlock, "deadlock")
HVCRF_DEFINE_CONSTANT(HVCrashExcType, Mach, mach, "mach")
HVCRF_DEFINE_CONSTANT(HVCrashExcType, NSException, nsException, "nsexception")
HVCRF_DEFINE_CONSTANT(HVCrashExcType, Signal, signal, "signal")
HVCRF_DEFINE_CONSTANT(HVCrashExcType, User, user, "user")
HVCRF_DEFINE_CONSTANT(HVCrashExcType, MemoryTermination, memoryTermination, "memory_termination")

#pragma mark - Common -

typedef HVCrashReportField HVCrashField NS_TYPED_ENUM NS_SWIFT_NAME(CrashField);

HVCRF_DEFINE_CONSTANT(HVCrashField, Address, address, "address")
HVCRF_DEFINE_CONSTANT(HVCrashField, Contents, contents, "contents")
HVCRF_DEFINE_CONSTANT(HVCrashField, Exception, exception, "exception")
HVCRF_DEFINE_CONSTANT(HVCrashField, FirstObject, firstObject, "first_object")
HVCRF_DEFINE_CONSTANT(HVCrashField, Index, index, "index")
HVCRF_DEFINE_CONSTANT(HVCrashField, Ivars, ivars, "ivars")
HVCRF_DEFINE_CONSTANT(HVCrashField, Language, language, "language")
HVCRF_DEFINE_CONSTANT(HVCrashField, Name, name, "name")
HVCRF_DEFINE_CONSTANT(HVCrashField, UserInfo, userInfo, "userInfo")
HVCRF_DEFINE_CONSTANT(HVCrashField, ReferencedObject, referencedObject, "referenced_object")
HVCRF_DEFINE_CONSTANT(HVCrashField, Type, type, "type")
HVCRF_DEFINE_CONSTANT(HVCrashField, UUID, uuid, "uuid")
HVCRF_DEFINE_CONSTANT(HVCrashField, Value, value, "value")
HVCRF_DEFINE_CONSTANT(HVCrashField, MemoryLimit, memoryLimit, "memory_limit")
HVCRF_DEFINE_CONSTANT(HVCrashField, Error, error, "error")
HVCRF_DEFINE_CONSTANT(HVCrashField, JSONData, jsonData, "json_data")

#pragma mark - Notable Address -

HVCRF_DEFINE_CONSTANT(HVCrashField, Class, class, "class")
HVCRF_DEFINE_CONSTANT(HVCrashField, LastDeallocObject, lastDeallocObject, "last_deallocated_obj")

#pragma mark - Backtrace -

HVCRF_DEFINE_CONSTANT(HVCrashField, InstructionAddr, instructionAddr, "instruction_addr")
HVCRF_DEFINE_CONSTANT(HVCrashField, LineOfCode, lineOfCode, "line_of_code")
HVCRF_DEFINE_CONSTANT(HVCrashField, ObjectAddr, objectAddr, "object_addr")
HVCRF_DEFINE_CONSTANT(HVCrashField, ObjectName, objectName, "object_name")
HVCRF_DEFINE_CONSTANT(HVCrashField, SymbolAddr, symbolAddr, "symbol_addr")
HVCRF_DEFINE_CONSTANT(HVCrashField, SymbolName, symbolName, "symbol_name")

#pragma mark - Stack Dump -

HVCRF_DEFINE_CONSTANT(HVCrashField, DumpEnd, dumpEnd, "dump_end")
HVCRF_DEFINE_CONSTANT(HVCrashField, DumpStart, dumpStart, "dump_start")
HVCRF_DEFINE_CONSTANT(HVCrashField, GrowDirection, growDirection, "grow_direction")
HVCRF_DEFINE_CONSTANT(HVCrashField, Overflow, overflow, "overflow")
HVCRF_DEFINE_CONSTANT(HVCrashField, StackPtr, stackPtr, "stack_pointer")

#pragma mark - Thread Dump -

HVCRF_DEFINE_CONSTANT(HVCrashField, Backtrace, backtrace, "backtrace")
HVCRF_DEFINE_CONSTANT(HVCrashField, Basic, basic, "basic")
HVCRF_DEFINE_CONSTANT(HVCrashField, Crashed, crashed, "crashed")
HVCRF_DEFINE_CONSTANT(HVCrashField, CurrentThread, currentThread, "current_thread")
HVCRF_DEFINE_CONSTANT(HVCrashField, DispatchQueue, dispatchQueue, "dispatch_queue")
HVCRF_DEFINE_CONSTANT(HVCrashField, NotableAddresses, notableAddresses, "notable_addresses")
HVCRF_DEFINE_CONSTANT(HVCrashField, Registers, registers, "registers")
HVCRF_DEFINE_CONSTANT(HVCrashField, Skipped, skipped, "skipped")
HVCRF_DEFINE_CONSTANT(HVCrashField, Stack, stack, "stack")

#pragma mark - Binary Image -

HVCRF_DEFINE_CONSTANT(HVCrashField, CPUSubType, cpuSubType, "cpu_subtype")
HVCRF_DEFINE_CONSTANT(HVCrashField, CPUType, cpuType, "cpu_type")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageAddress, imageAddress, "image_addr")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageVmAddress, imageVmAddress, "image_vmaddr")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageSize, imageSize, "image_size")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageMajorVersion, imageMajorVersion, "major_version")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageMinorVersion, imageMinorVersion, "minor_version")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageRevisionVersion, imageRevisionVersion, "revision_version")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageCrashInfoMessage, imageCrashInfoMessage, "crash_info_message")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageCrashInfoMessage2, imageCrashInfoMessage2, "crash_info_message2")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageCrashInfoBacktrace, imageCrashInfoBacktrace, "crash_info_backtrace")
HVCRF_DEFINE_CONSTANT(HVCrashField, ImageCrashInfoSignature, imageCrashInfoSignature, "crash_info_signature")

#pragma mark - Memory -

HVCRF_DEFINE_CONSTANT(HVCrashField, Free, free, "free")
HVCRF_DEFINE_CONSTANT(HVCrashField, Usable, usable, "usable")

#pragma mark - Error -

HVCRF_DEFINE_CONSTANT(HVCrashField, Code, code, "code")
HVCRF_DEFINE_CONSTANT(HVCrashField, CodeName, codeName, "code_name")
HVCRF_DEFINE_CONSTANT(HVCrashField, CPPException, cppException, "cpp_exception")
HVCRF_DEFINE_CONSTANT(HVCrashField, ExceptionName, exceptionName, "exception_name")
HVCRF_DEFINE_CONSTANT(HVCrashField, Mach, mach, "mach")
HVCRF_DEFINE_CONSTANT(HVCrashField, NSException, nsException, "nsexception")
HVCRF_DEFINE_CONSTANT(HVCrashField, Reason, reason, "reason")
HVCRF_DEFINE_CONSTANT(HVCrashField, Signal, signal, "signal")
HVCRF_DEFINE_CONSTANT(HVCrashField, Subcode, subcode, "subcode")
HVCRF_DEFINE_CONSTANT(HVCrashField, UserReported, userReported, "user_reported")

#pragma mark - Process State -

HVCRF_DEFINE_CONSTANT(HVCrashField, LastDeallocedNSException, lastDeallocedNSException, "last_dealloced_nsexception")
HVCRF_DEFINE_CONSTANT(HVCrashField, ProcessState, processState, "process")

#pragma mark - App Stats -

HVCRF_DEFINE_CONSTANT(HVCrashField, ActiveTimeSinceCrash, activeTimeSinceCrash, "active_time_since_last_crash")
HVCRF_DEFINE_CONSTANT(HVCrashField, ActiveTimeSinceLaunch, activeTimeSinceLaunch, "active_time_since_launch")
HVCRF_DEFINE_CONSTANT(HVCrashField, AppActive, appActive, "application_active")
HVCRF_DEFINE_CONSTANT(HVCrashField, AppInFG, appInFG, "application_in_foreground")
HVCRF_DEFINE_CONSTANT(HVCrashField, BGTimeSinceCrash, bgTimeSinceCrash, "background_time_since_last_crash")
HVCRF_DEFINE_CONSTANT(HVCrashField, BGTimeSinceLaunch, bgTimeSinceLaunch, "background_time_since_launch")
HVCRF_DEFINE_CONSTANT(HVCrashField, LaunchesSinceCrash, launchesSinceCrash, "launches_since_last_crash")
HVCRF_DEFINE_CONSTANT(HVCrashField, SessionsSinceCrash, sessionsSinceCrash, "sessions_since_last_crash")
HVCRF_DEFINE_CONSTANT(HVCrashField, SessionsSinceLaunch, sessionsSinceLaunch, "sessions_since_launch")

#pragma mark - Report -

HVCRF_DEFINE_CONSTANT(HVCrashField, Crash, crash, "crash")
HVCRF_DEFINE_CONSTANT(HVCrashField, Debug, debug, "debug")
HVCRF_DEFINE_CONSTANT(HVCrashField, Diagnosis, diagnosis, "diagnosis")
HVCRF_DEFINE_CONSTANT(HVCrashField, ID, id, "id")
HVCRF_DEFINE_CONSTANT(HVCrashField, ProcessName, processName, "process_name")
HVCRF_DEFINE_CONSTANT(HVCrashField, Report, report, "report")
HVCRF_DEFINE_CONSTANT(HVCrashField, Timestamp, timestamp, "timestamp")
HVCRF_DEFINE_CONSTANT(HVCrashField, Version, version, "version")
HVCRF_DEFINE_CONSTANT(HVCrashField, AppMemory, appMemory, "app_memory")
HVCRF_DEFINE_CONSTANT(HVCrashField, MemoryTermination, memoryTermination, "memory_termination")

HVCRF_DEFINE_CONSTANT(HVCrashField, CrashedThread, crashedThread, "crashed_thread")
HVCRF_DEFINE_CONSTANT(HVCrashField, AppStats, appStats, "application_stats")
HVCRF_DEFINE_CONSTANT(HVCrashField, BinaryImages, binaryImages, "binary_images")
HVCRF_DEFINE_CONSTANT(HVCrashField, System, system, "system")
HVCRF_DEFINE_CONSTANT(HVCrashField, Memory, memory, "memory")
HVCRF_DEFINE_CONSTANT(HVCrashField, Threads, threads, "threads")
HVCRF_DEFINE_CONSTANT(HVCrashField, User, user, "user")
HVCRF_DEFINE_CONSTANT(HVCrashField, ConsoleLog, consoleLog, "console_log")
HVCRF_DEFINE_CONSTANT(HVCrashField, Incomplete, incomplete, "incomplete")
HVCRF_DEFINE_CONSTANT(HVCrashField, RecrashReport, recrashReport, "recrash_report")

HVCRF_DEFINE_CONSTANT(HVCrashField, AppStartTime, appStartTime, "app_start_time")
HVCRF_DEFINE_CONSTANT(HVCrashField, AppUUID, appUUID, "app_uuid")
HVCRF_DEFINE_CONSTANT(HVCrashField, BootTime, bootTime, "boot_time")
HVCRF_DEFINE_CONSTANT(HVCrashField, BundleID, bundleID, "CFBundleIdentifier")
HVCRF_DEFINE_CONSTANT(HVCrashField, BundleName, bundleName, "CFBundleName")
HVCRF_DEFINE_CONSTANT(HVCrashField, BundleShortVersion, bundleShortVersion, "CFBundleShortVersionString")
HVCRF_DEFINE_CONSTANT(HVCrashField, BundleVersion, bundleVersion, "CFBundleVersion")
HVCRF_DEFINE_CONSTANT(HVCrashField, CPUArch, cpuArch, "cpu_arch")
HVCRF_DEFINE_CONSTANT(HVCrashField, BinaryCPUType, binaryCPUType, "binary_cpu_type")
HVCRF_DEFINE_CONSTANT(HVCrashField, BinaryCPUSubType, binaryCPUSubType, "binary_cpu_subtype")
HVCRF_DEFINE_CONSTANT(HVCrashField, DeviceAppHash, deviceAppHash, "device_app_hash")
HVCRF_DEFINE_CONSTANT(HVCrashField, Executable, executable, "CFBundleExecutable")
HVCRF_DEFINE_CONSTANT(HVCrashField, ExecutablePath, executablePath, "CFBundleExecutablePath")
HVCRF_DEFINE_CONSTANT(HVCrashField, Jailbroken, jailbroken, "jailbroken")
HVCRF_DEFINE_CONSTANT(HVCrashField, KernelVersion, kernelVersion, "kernel_version")
HVCRF_DEFINE_CONSTANT(HVCrashField, Machine, machine, "machine")
HVCRF_DEFINE_CONSTANT(HVCrashField, Model, model, "model")
HVCRF_DEFINE_CONSTANT(HVCrashField, OSVersion, osVersion, "os_version")
HVCRF_DEFINE_CONSTANT(HVCrashField, ParentProcessID, parentProcessID, "parent_process_id")
HVCRF_DEFINE_CONSTANT(HVCrashField, ProcessID, processID, "process_id")
HVCRF_DEFINE_CONSTANT(HVCrashField, Size, size, "size")
HVCRF_DEFINE_CONSTANT(HVCrashField, Storage, storage, "storage")
HVCRF_DEFINE_CONSTANT(HVCrashField, SystemName, systemName, "system_name")
HVCRF_DEFINE_CONSTANT(HVCrashField, SystemVersion, systemVersion, "system_version")
HVCRF_DEFINE_CONSTANT(HVCrashField, TimeZone, timeZone, "time_zone")
HVCRF_DEFINE_CONSTANT(HVCrashField, BuildType, buildType, "build_type")

HVCRF_DEFINE_CONSTANT(HVCrashField, MemoryFootprint, memoryFootprint, "memory_footprint")
HVCRF_DEFINE_CONSTANT(HVCrashField, MemoryRemaining, memoryRemaining, "memory_remaining")
HVCRF_DEFINE_CONSTANT(HVCrashField, MemoryPressure, memoryPressure, "memory_pressure")
HVCRF_DEFINE_CONSTANT(HVCrashField, MemoryLevel, memoryLevel, "memory_level")
HVCRF_DEFINE_CONSTANT(HVCrashField, AppTransitionState, appTransitionState, "app_transition_state")

#ifdef __cplusplus
}
#endif

#endif  // HDR_HVCrashReportFields_h
