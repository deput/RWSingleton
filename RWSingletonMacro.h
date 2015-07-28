#import <objc/runtime.h>

#define RW_DECLARE_SINGLETON_FOR_CLASS_WITH_ACCESSOR(classname, accessorMethodName) \
+ (classname *)accessorMethodName;

#if __has_feature(objc_arc)
    #define RW_SYNTHESIZE_SINGLETON_RETAIN_METHODS
#else
    #define RW_SYNTHESIZE_SINGLETON_RETAIN_METHODS \
    - (id)retain \
    { \
        return self; \
    } \
    \
    - (NSUInteger)retainCount \
    { \
        return NSUIntegerMax; \
    } \
    \
    - (oneway void)release \
    { \
    } \
    \
    - (id)autorelease \
    { \
        return self; \
    }
#endif

#define RW_SYNTHESIZE_SINGLETON_FOR_CLASS_WITH_ACCESSOR(classname, accessorMethodName) \
\
static classname *accessorMethodName##Instance = nil; \
\
+ (classname *)accessorMethodName \
{ \
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken,^{\
        accessorMethodName##Instance = [super allocWithZone:NULL]; \
        accessorMethodName##Instance = [accessorMethodName##Instance init]; \
    });\
    return accessorMethodName##Instance; \
}\
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
    return [self accessorMethodName]; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
    return self; \
} \
RW_SYNTHESIZE_SINGLETON_RETAIN_METHODS

#define RW_DECLARE_SINGLETON_FOR_CLASS(classname) RW_DECLARE_SINGLETON_FOR_CLASS_WITH_ACCESSOR(classname, shared##classname)
#define RW_SYNTHESIZE_SINGLETON_FOR_CLASS(classname) RW_SYNTHESIZE_SINGLETON_FOR_CLASS_WITH_ACCESSOR(classname, shared##classname)
