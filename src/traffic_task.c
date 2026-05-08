#include <stdio.h>
#include <windows.h>
#include "../include/shared_data.h"

DWORD WINAPI northSouthTrafficTask(LPVOID arg)
{
    while (1)
    {
        WaitForSingleObject(trafficMutex, INFINITE);
        northTaskAlive = 1;

        if (emergencyMode)
        {
            printf("\n[EMERGENCY MODE] PRIORITY GREEN ACTIVE\n");

            ReleaseMutex(trafficMutex);

            Sleep(6000);

            continue;
        }
        

        printf("\n[NORTH-SOUTH] GREEN\n");
        vehicleCount++;

        printf("Vehicle Count: %d\n", vehicleCount);

        ReleaseMutex(trafficMutex);

        if (trafficDensity > 70)
        {
            printf("[HIGH TRAFFIC] Extending GREEN time...\n");
            Sleep(5000);
        }
        else
        {
            Sleep(3000);
        }

        WaitForSingleObject(trafficMutex, INFINITE);

        printf("[NORTH-SOUTH] YELLOW\n");

        ReleaseMutex(trafficMutex);

        Sleep(1000);

        WaitForSingleObject(trafficMutex, INFINITE);

        printf("[NORTH-SOUTH] RED\n");

        ReleaseMutex(trafficMutex);

        Sleep(2000);
    }
}

DWORD WINAPI eastWestTrafficTask(LPVOID arg)
{
    while (1)
    {
        WaitForSingleObject(trafficMutex, INFINITE);
        eastTaskAlive = 1;
        if (emergencyMode)
        {
            printf("\n[EMERGENCY MODE] PRIORITY GREEN ACTIVE\n");

            ReleaseMutex(trafficMutex);

            Sleep(6000);

            continue;
        }
        

        printf("\n[EAST-WEST] GREEN\n");
        vehicleCount++;

        printf("Vehicle Count: %d\n", vehicleCount);

        ReleaseMutex(trafficMutex);

        if (trafficDensity > 70)
        {
            printf("[HIGH TRAFFIC] Extending GREEN time...\n");
            Sleep(5000);
        }
        else
        {
            Sleep(3000);
        }

        WaitForSingleObject(trafficMutex, INFINITE);

        printf("[EAST-WEST] YELLOW\n");

        ReleaseMutex(trafficMutex);

        Sleep(1000);

        WaitForSingleObject(trafficMutex, INFINITE);

        printf("[EAST-WEST] RED\n");

        ReleaseMutex(trafficMutex);

        Sleep(2000);
    }
}