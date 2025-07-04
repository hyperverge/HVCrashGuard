//
//  HVJSONCodecObjC.h
//
//  Created by Karl Stenerud on 2012-01-08.
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

#ifdef __OBJC__

#import <Foundation/Foundation.h>

/** Optional behavior when encoding JSON data */
typedef NS_ENUM(NSInteger, HVJSONEncodeOption) {
    /** No special encoding options */
    HVJSONEncodeOptionNone = 0,

    /** Indent 4 spaces per object/array level */
    HVJSONEncodeOptionPretty = 1,

    /** Sort object contents by key name */
    HVJSONEncodeOptionSorted = 2,
} NS_SWIFT_NAME(JSONEncodeOption);

/** Optional behavior when decoding JSON data */
typedef NS_ENUM(NSInteger, HVJSONDecodeOption) {
    /** No special decoding options */
    HVJSONDecodeOptionNone = 0,

    /** Do not store null elements when encountered inside an array */
    HVJSONDecodeOptionIgnoreNullInArray = 1,

    /** Do not store null elements when encountered inside an object */
    HVJSONDecodeOptionIgnoreNullInObject = 2,

    /** Ignore null elements in both arrays and objects */
    HVJSONDecodeOptionIgnoreAllNulls = 3,

    /** Return the partially decoded object if an error is encountered */
    HVJSONDecodeOptionKeepPartialObject = 4,
} NS_SWIFT_NAME(JSONDecodeOption);

/**
 * Encodes and decodes UTF-8 JSON data.
 */
@interface HVJSONCodec : NSObject

/** Encode an object to JSON data.
 *
 * @param object The array or dictionary to encode.
 *
 * @param options Options for how to encode the data.
 *
 * @param error Place to store any error that occurs (nil = ignore). Will be
 *              set to nil on success.
 *
 * @return The encoded UTF-8 JSON data or nil if an error occurred.
 */
+ (NSData *)encode:(id)object options:(HVJSONEncodeOption)options error:(NSError **)error;

/** Decode JSON data to an object.
 *
 * @param JSONData The UTF-8 data to decode.
 *
 * @param options Options for how to decode the data.
 *
 * @param error Place to store any error that occurs (nil = ignore). Will be
 *              set to nil on success.
 *
 * @return The decoded object or, if the HVJSONDecodeOptionKeepPartialFile
 *         option is not set, nil when an error occurs.
 */
+ (id)decode:(NSData *)JSONData options:(HVJSONDecodeOption)options error:(NSError **)error;

@end

#endif
