# 本例的完成标志<上篇>的完结, 并实现了基本的`printf`
----
## `printf`实现：
- 内部调用`vsprintf`进行格式化, 将格式化字符串通过用户级系统调用`write`输出到屏幕

## `write`的实现:
- 通过`INT_VECTOR_SYS_CALL`中断调用与之绑定的中断例程`sys_call`
- `sys_call`调用`sys_call_table`中的`sys_write`(`tty.c`). `sys_write`的三个参数的顺序与`sys_call`的压栈顺序对应, 其中`p_proc_ready`指向调用者进程, 这是在进程调度模块中设定好的
- `sys_write`最终调用`tty_write`将输出对应到与`p_proc_ready`进程绑定的`TTY`