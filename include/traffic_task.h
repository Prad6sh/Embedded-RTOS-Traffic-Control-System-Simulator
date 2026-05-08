#ifndef TRAFFIC_TASK_H
#define TRAFFIC_TASK_H

typedef enum
{
    RED,
    GREEN,
    YELLOW
}TrafficLightState;

void runTrafficLight();

#endif