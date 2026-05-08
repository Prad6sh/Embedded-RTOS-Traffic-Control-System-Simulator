#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <windows.h>

extern int vehicleCount;
extern int trafficDensity;
extern int emergencyMode;
extern int northTaskAlive;
extern int eastTaskAlive;

extern HANDLE trafficMutex;

#endif