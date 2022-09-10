//
//  TestWrapper.m
//  Tink
//
//  Created by Wonder Mac on 06/09/22.
//

#import <Foundation/Foundation.h>
#import "TestWrapper.h"
#import "TestClass.hpp"


@implementation TestWrapper
- (NSString *) sayWelcome {
    TestClass testClass;
    std::string welcomeMessage = testClass.sayWelcome();
    return [NSString
            stringWithCString:welcomeMessage.c_str()
            encoding:NSUTF8StringEncoding];
}
@end
