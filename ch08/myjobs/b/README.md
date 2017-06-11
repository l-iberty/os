- 删除系统调用`get_ticks`, 改用消息机制实现
- `kernel/proc.c`中去除了`dump_proc`和`dump_msg`两个函数, 因为ch08未提及他们

## 大体框架却是明白了, 但细节处以及消息机制的核心`msg_send`和`msg_receive`不是完全懂