//
//  HVCrashDoctor.h
//  HVCrash
//
//  Created by Karl Stenerud on 2012-11-10.
//  Copyright (c) 2012 Karl Stenerud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HVCrashDoctor : NSObject

- (NSString *)diagnoseCrash:(NSDictionary *)crashReport;

@end
