# Pretreatment-applications
c语言的预处理，包含宏定义的多种技巧，包含条件编译#ifdef，还有其他一些常见的预处理标识...其中宏可以做到泛型的处理

| 都是预处理指令，常见的有  3  种 ：#include这种预处理指令，#define这种宏定义，#if等这种条件编译指令 |


本仓实现如下功能。
#1. #if, #ifdef, #if (defined ), #error, #, ##,

#2. pretreatment-->LIST

#2.1 #define dprintk(level_mask, fmt, arg...)    if (unlikely(debug_mask & level_mask)) \
    printk(KERN_DEBUG fmt , ## arg)

#3. 最终能够模仿http://blog.csdn.net/njuitjf/article/details/16849333里面的DEVICE_ATTR的实现方式来实现一个自己的宏，
并具有一定的功能。当然不是和DEVICE_ATTR一样的宏，要领会其奥义，然后根据自己将来的需求创造一个宏函数
