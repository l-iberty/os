
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               proc.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"

/*======================================================================*
                              schedule
 *======================================================================*/
PUBLIC void schedule()
{
	PROCESS* p;
	int	 greatest_ticks = 0;

	while (!greatest_ticks) {
		// 遍历进程表, 将最大的 ticks 赋给 greatest_ticks, 并令 p_proc_ready 指向 ticks 最大的进程
		// 每次发送时钟中断时 p_proc_ready->ticks--, 最先被选中的进程的 ticks 必然在后面被减小到与其
		// 他之前未被选中的进程的 ticks 相等, 这样以来就会有新的进程被选中并运行
		for (p = proc_table; p < proc_table+NR_TASKS; p++) {
			if (p->ticks > greatest_ticks) {
				greatest_ticks = p->ticks;
				p_proc_ready = p;
			}
		}

		// 遍历进程表后, 若 greatest_ticks 仍为 0, 则说明所有进程的 ticks 都减为了0, (每次时钟中断
		// 发生时 ticks++, p_proc_ready->ticks--) 这时将每个进程的 ticks 赋值为其初始值 priority,
		// 继续调度
		if (!greatest_ticks) {
			for (p = proc_table; p < proc_table+NR_TASKS; p++) {
				p->ticks = p->priority;
			}
		}
	}
}

/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	return ticks;
}

