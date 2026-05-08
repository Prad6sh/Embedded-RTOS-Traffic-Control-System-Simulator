#include <stdio.h>
#include <windows.h>

#include "../include/shared_data.h"

DWORD WINAPI loggerTask(LPVOID arg)
{
    while (1)
    {
        WaitForSingleObject(trafficMutex, INFINITE);

        printf("\n========== SYSTEM LOG ==========\n");

        printf("Vehicle Count   : %d\n", vehicleCount);

        printf("Traffic Density : %d\n", trafficDensity);

        printf("Emergency Mode  : %s\n",
               emergencyMode ? "ACTIVE" : "OFF");

        printf("================================\n");

        ReleaseMutex(trafficMutex);

        Sleep(10000);
    }
}