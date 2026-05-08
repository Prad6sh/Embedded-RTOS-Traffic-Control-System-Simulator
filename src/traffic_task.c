#include <stdio.h>
#include <windows.h>
#include "../include/traffic_task.h"

void runTrafficLight()
{
    TrafficLightState state = RED;
    while (1000)
    {
        switch (state)
        {
        case RED:
            printf("RED LIGHT\n");
            Sleep(3000);
            state = GREEN;
            break;
        
        case GREEN:
            printf("GREEN LIGHT\n");
            Sleep(3000);
            state = YELLOW;
            break;
        
        case YELLOW:
            printf("YELLOW LIGHT\n");
            Sleep(1000);
            state = RED;
            break;
        }
    }


}