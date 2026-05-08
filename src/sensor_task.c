#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "../include/shared_data.h"

DWORD WINAPI sensorTask(LPVOID arg)
{
    while (1)
    {
        WaitForSingleObject(trafficMutex, INFINITE);

        trafficDensity = rand() % 100;

        printf("\n[SENSOR] Traffic Density Updated: %d\n",
               trafficDensity);

        ReleaseMutex(trafficMutex);

        Sleep(5000);
    }
}