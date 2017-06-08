## `task_tty`通过`init_tty`初始化`tty_table`中所有`TTY`时做了什么?
- 与`i/'一样初始化`TTY`结构体后, 调用`init_screen`对每个`TTY`对应的的`CONSOLE`的显存进行初始化, 最后设置每个`CONSOLE`的光标位置

## `CONSOLE`的切换如何实现?
- `task_tty`轮询每个`TTY`, `keyboard_read`从字符缓冲区读取键盘输入后调用`in_process`处理之
- `in_process`判断输入为`Ctrl+F1~F12`, 则调用`select_console`切换`CONSOLE`
- `select_console`最终通过调用`set_video_start_addr`操作VGA寄存器(Start Address High/Start Address Low)设置重新显示的显存起始地址, 实现了屏幕切换效果. **注意**, 此时显存并没有发生任何变化, 每个`TTY`和`CONSOLE`的各项参数依旧, 所以切换效果才得以实现