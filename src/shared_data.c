#include "../include/shared_data.h"

int vehicleCount = 0;
int trafficDensity = 0;
int emergencyMode = 0;
int northTaskAlive = 0;
int eastTaskAlive = 0;
extern int emergencyMode;

HANDLE trafficMutex;