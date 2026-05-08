#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "../include/shared_data.h"

DWORD WINAPI emergencyTask(LPVOID arg)
{
    while (1)
    {
        Sleep(15000);

        WaitForSingleObject(trafficMutex, INFINITE);

        emergencyMode = 1;

        printf("\n========== EMERGENCY VEHICLE DETECTED ==========\n");

        ReleaseMutex(trafficMutex);

        Sleep(7000);

        WaitForSingleObject(trafficMutex, INFINITE);

        emergencyMode = 0;

        printf("\n========== EMERGENCY CLEARED ==========\n");

        ReleaseMutex(trafficMutex);
    }
}