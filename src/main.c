#include <windows.h>
#include "../include/traffic_task.h"
#include "../include/shared_data.h"
#include "../include/sensor_task.h"
#include "../include/emergency_task.h"
#include "../include/logger_task.h"
#include "../include/watchdog_task.h"


int main()
{
    HANDLE northThread,
       eastThread,
       sensorThread,
       emergencyThread,
       loggerThread,
       watchdogThread;

    trafficMutex = CreateMutex(
        NULL,
        FALSE,
        NULL
    );

    northThread = CreateThread(
        NULL,
        0,
        northSouthTrafficTask,
        NULL,
        0,
        NULL
    );

    eastThread = CreateThread(
        NULL,
        0,
        eastWestTrafficTask,
        NULL,
        0,
        NULL
    );

    sensorThread = CreateThread(
        NULL,
        0,
        sensorTask,
        NULL,
        0,
        NULL
    );

    emergencyThread = CreateThread(
        NULL,
        0,
        emergencyTask,
        NULL,
        0,
        NULL
    );

    loggerThread = CreateThread(
        NULL,
        0,
        loggerTask,
        NULL,
        0,
        NULL
    );

    watchdogThread = CreateThread(
        NULL,
        0,
        watchdogTask,
        NULL,
        0,
        NULL
    );

    WaitForSingleObject(northThread, INFINITE);
    WaitForSingleObject(eastThread, INFINITE);
    WaitForSingleObject(sensorThread, INFINITE);
    WaitForSingleObject(emergencyThread, INFINITE);
    WaitForSingleObject(loggerThread, INFINITE);
    WaitForSingleObject(watchdogThread, INFINITE);

    return 0;
}