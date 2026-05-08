#ifndef TRAFFIC_TASK_H
#define TRAFFIC_TASK_H

#include <windows.h>

DWORD WINAPI northSouthTrafficTask(LPVOID arg);

DWORD WINAPI eastWestTrafficTask(LPVOID arg);

#endif