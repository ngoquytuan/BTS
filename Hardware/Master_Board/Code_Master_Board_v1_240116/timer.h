#ifndef __TIMER_H
#define __TIMER_H

//#include "stm32f10x_it.h"
#include "types.h"

#define MAXCALLBACKFUNC                    32
#define ALL                             MAXCALLBACKFUNC

//typedef void (SYSTEMCALLBACK*)(void*);

typedef struct
{
    SYSTEMCALLBACK     CallbackFunc;
    WORD            wTickCount;
    WORD             nSecondCount;
    BYTE            nState;
    PVOID            pData;
} CallbackFuncTypeDef, *PCallbackFuncTypeDef;


extern CallbackFuncTypeDef arCallbackFunc[MAXCALLBACKFUNC];

VOID CancelTimer(SYSTEMCALLBACK Callback, PVOID pData);
VOID StartShortTimer(WORD wTickCount, SYSTEMCALLBACK Callback, PVOID pData);
VOID StartLongTimer(WORD wSecondCount, SYSTEMCALLBACK Callback, PVOID pData);
BOOL IsRunning(SYSTEMCALLBACK Callback, PVOID pData );
VOID ProcessTimerEvents(VOID);
VOID Delay_ms(__IO DWORD dwTime);
DWORD GetTickCount(VOID);

#endif 

