# 系统调用`get_ticks`原理
**1.** 进程TestA发起系统调用`get_ticks()`

**2.** `get_ticks`在`syscall.asm`中定义为以`eax`为功能号的`INT_VECTOR_SYS_CALL`号中断调用

**3.** `protect.c`初始化`INT_VECTOR_SYS_CALL`号中断, 与`kernel.asm`中定义的`sys_call`例程绑定

**4.** `sys_call`作为中断例程之一, 与其他中断例程框架一致

**5.** `sys_call`以功能号`eax`为索引, 通过`call`指令调用`global.c`中定义的函数列表`sys_call_table`中的函数(这些函数在`proto.h`声明, 在`proc.c`定义), 至此完成系统调用