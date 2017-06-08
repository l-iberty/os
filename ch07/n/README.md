# 新变化
- 进程调度模块--时钟中断例程的核心`schedule()`--运行在ring0, 与之前一样
- 终端任务`task_tty()`运行在ring1, 与之前一样
- `TestA`, `TestB`和`TestC`作为用户进程运行在ring3, 之前在ring1