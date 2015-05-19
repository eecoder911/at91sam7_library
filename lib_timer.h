#ifndef __FILE_LIB_TIMER_H__
#define __FILE_LIB_TIMER_H__
#include "..\typedef.h"

typedef struct{
    U32 cnt;
    U32 interval;
    bool enabled;
    void *next;
}t_Timer;

//base
void Timer_IspHandler_1ms();
t_Timer *TimerCreate(); //timer disabled,return null when failed
void TimerDelete(t_Timer *tmr);
void TimerEnable(t_Timer *tmr);
void TimerDisable(t_Timer *tmr);
void TimerSet(t_Timer *tmr, U32 interval);
void TimerReset(t_Timer *tmr);//clear cnt
bool TimerEvent(t_Timer *tmr);
//not necessory
void delay_ms(U32 x);
//not necessory
int TimerTotalAmount();
int TimerEnabledAmount();

#endif //__FILE_LIB_TIMER_H__