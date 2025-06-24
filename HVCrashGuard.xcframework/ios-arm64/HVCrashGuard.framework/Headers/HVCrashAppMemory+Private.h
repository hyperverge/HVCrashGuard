#import <Foundation/Foundation.h>
#import "HVCrashAppMemory.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Internal and for tests.
 */
@interface HVCrashAppMemory ()
- (instancetype)initWithFootprint:(uint64_t)footprint
                        remaining:(uint64_t)remaining
                         pressure:(HVCrashAppMemoryState)pressure NS_DESIGNATED_INITIALIZER;
@end

typedef HVCrashAppMemory *_Nonnull (^HVCrashAppMemoryProvider)(void);
FOUNDATION_EXPORT void __HVCrashAppMemorySetProvider(HVCrashAppMemoryProvider provider);

NS_ASSUME_NONNULL_END
