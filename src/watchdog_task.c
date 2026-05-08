#include <stdio.h>
#include <windows.h>
#include "../include/config.h"
#include "../include/shared_data.h"


DWORD WINAPI watchdogTask(LPVOID arg)
{
    while (1)
    {
        Sleep(WATCHDOG_DELAY );

        WaitForSingleObject(trafficMutex, INFINITE);

        if (northTaskAlive && eastTaskAlive)
        {
            printf("\n[WATCHDOG] System Healthy\n");
        }
        else
        {
            printf("\n[WATCHDOG ERROR] Task Failure Detected!\n");
        }

        northTaskAlive = 0;
        eastTaskAlive = 0;

        ReleaseMutex(trafficMutex);
    }
}