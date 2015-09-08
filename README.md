# RWSingleton
A macro to create singleton class quickly in ObjC

##Motivation
[CWLSynthesizeSingleton](https://github.com/incbee/CWLSynthesizeSingleton) inspires me to change it a little bit. It is better to use `dispatch_once_t`. Meanwhile, to avoid performance degradation I did not perform lock on getting shared instance, I leave these tasks to developer themselves according to their implemetations.

## Usage
Supposing a desired singleton class named `MyOjbect`.
in `MyOjbect.h`, a single line is adde as:
```objc
#import "RWSingletonMacro.h"
@interface MyObject : NSObject
RW_DECLARE_SINGLETON_FOR_CLASS_WITH_ACCESSOR(MyObject, sharedObject)
@end
```

in `MyObject.m`:
```objc
#import "MyObject.h"
@implementation MyObject
RW_SYNTHESIZE_SINGLETON_FOR_CLASS_WITH_ACCESSOR(MyObject, sharedObject)
@end
```
Also, you can overwrite `-(id)init` method to do your custom initialization:
```objc
#import "MyObject.h"
@implementation MyObject
RW_SYNTHESIZE_SINGLETON_FOR_CLASS_WITH_ACCESSOR(MyObject, sharedObject)

- (id) init
{
  self = [super init];
  //do your things
  return self
}
@end
```



