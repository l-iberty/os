
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               clock.c
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
                           clock_handler
 *======================================================================*/
PUBLIC void clock_handler(int irq)
{
	disp_str("#");
	ticks++;	// 每次相应时钟中断时 ticks 自增, 以此记录时钟中断的发送次数

	if (k_reenter != 0) {
		disp_str("!");
		return;
	}

	p_proc_ready++;
	if (p_proc_ready >= proc_table + NR_TASKS) {
		p_proc_ready = proc_table;
	}
}

PUBLIC void milli_delay(int milli_sec)
{
	int t = get_ticks();

	while (((get_ticks() - t) * 1000 / HZ) < milli_sec) {}
}
