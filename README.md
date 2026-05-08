# Embedded RTOS Traffic Control System Simulator

## Overview

The Embedded RTOS Traffic Control System Simulator is a software-only embedded systems project developed in C to demonstrate core Real-Time Operating System (RTOS) concepts using concurrent task execution.

The simulator models a smart traffic intersection system with:

* Concurrent traffic signal control
* Sensor-driven adaptive behavior
* Emergency vehicle priority handling
* Shared resource synchronization using mutexes
* Watchdog-based system monitoring
* Logger and diagnostic services

The project is built using:

* C Programming Language
* Windows Threads API (`CreateThread`)
* VS Code
* Git & GitHub

This project was designed to simulate how real embedded firmware architectures are structured in automotive, industrial automation, and smart traffic management systems.

---

# Features

## Core Features

* Multithreaded traffic signal simulation
* Concurrent task execution
* Traffic light state machine implementation
* Shared global data handling
* Mutex-based synchronization
* Adaptive traffic timing based on sensor data
* Emergency vehicle override system
* Real-time logger task
* Watchdog health monitoring system
* Modular embedded-style architecture

---

# RTOS Concepts Demonstrated

This project demonstrates several important RTOS and embedded systems concepts:

| Concept                 | Implementation                      |
| ----------------------- | ----------------------------------- |
| Multitasking            | Multiple concurrent traffic tasks   |
| Concurrency             | Independent thread execution        |
| Synchronization         | Mutex-protected shared resources    |
| State Machines          | Traffic signal state transitions    |
| Event-Driven Systems    | Sensor and emergency event handling |
| Shared Memory           | Global traffic data communication   |
| Watchdog Monitoring     | Task heartbeat validation           |
| Background Services     | Logger monitoring task              |
| Real-Time Behavior      | Dynamic adaptive traffic control    |
| Modular Firmware Design | Separate source/header architecture |

---

# System Architecture

```text
+------------------------------------------------+
|             TRAFFIC RTOS SIMULATOR             |
+------------------------------------------------+

        +--------------------------+
        |      Sensor Task         |
        | Updates Traffic Density  |
        +------------+-------------+
                     |
                     v
        +--------------------------+
        |      Shared Data         |
        | Vehicle Count            |
        | Traffic Density          |
        | Emergency Mode           |
        +------------+-------------+
                     |
     +---------------+---------------+
     |                               |
     v                               v
+------------+               +------------+
| North-South|               | East-West  |
| Traffic    |               | Traffic    |
| Task       |               | Task       |
+------------+               +------------+

                     |
                     v
        +--------------------------+
        |    Emergency Task        |
        | Priority Vehicle Control |
        +--------------------------+

                     |
                     v
        +--------------------------+
        |      Logger Task         |
        | System Diagnostics       |
        +--------------------------+

                     |
                     v
        +--------------------------+
        |     Watchdog Task        |
        | Task Health Monitoring   |
        +--------------------------+
```

---

# Folder Structure

```text
traffic-rtos-simulator/
│
├── README.md
│
├── include/
│   ├── config.h
│   ├── traffic_task.h
│   ├── shared_data.h
│   ├── sensor_task.h
│   ├── emergency_task.h
│   ├── logger_task.h
│   └── watchdog_task.h
│
├── src/
│   ├── main.c
│   ├── traffic_task.c
│   ├── shared_data.c
│   ├── sensor_task.c
│   ├── emergency_task.c
│   ├── logger_task.c
│   └── watchdog_task.c
│
├── docs/
├── screenshots/
└── .gitignore
```

---

# Task Description

## 1. Traffic Tasks

Simulate independent traffic intersections:

* North-South traffic controller
* East-West traffic controller

Responsibilities:

* Signal state transitions
* Traffic timing control
* Emergency mode response
* Heartbeat updates for watchdog monitoring

---

## 2. Sensor Task

Simulates vehicle density sensors.

Responsibilities:

* Generate random traffic density values
* Update shared system data
* Trigger adaptive traffic behavior

---

## 3. Emergency Task

Simulates emergency vehicle detection.

Responsibilities:

* Trigger emergency override mode
* Prioritize traffic signal flow
* Simulate high-priority RTOS events

---

## 4. Logger Task

Background monitoring and diagnostics service.

Responsibilities:

* Display system statistics
* Monitor traffic density
* Report emergency state
* Print diagnostic logs

---

## 5. Watchdog Task

Monitors system health using heartbeat signals.

Responsibilities:

* Detect stalled or failed tasks
* Validate task responsiveness
* Simulate embedded watchdog systems

---

# Synchronization Mechanism

The simulator uses a mutex (`trafficMutex`) to safely protect shared resources.

Protected Shared Resources:

* Vehicle count
* Traffic density
* Emergency state
* Watchdog heartbeat variables

This prevents:

* Race conditions
* Data corruption
* Concurrent write conflicts

---

# Build Instructions

## Requirements

* GCC / MinGW
* VS Code
* Windows OS

---

## Compile

```bash
gcc src/main.c src/traffic_task.c src/shared_data.c src/sensor_task.c src/emergency_task.c src/logger_task.c src/watchdog_task.c -o traffic_sim
```

---

## Run

```bash
./traffic_sim.exe
```

---

# Sample Output

```text
========================================
 EMBEDDED RTOS TRAFFIC CONTROL SYSTEM
========================================

[NORTH-SOUTH] GREEN
Vehicle Count: 1

[EAST-WEST] GREEN
Vehicle Count: 2

[SENSOR] Traffic Density Updated: 82

[HIGH TRAFFIC] Extending GREEN time...

========== EMERGENCY VEHICLE DETECTED ==========

[EMERGENCY MODE] PRIORITY GREEN ACTIVE

========== SYSTEM LOG ==========
Vehicle Count   : 12
Traffic Density : 78
Emergency Mode  : ACTIVE
================================

[WATCHDOG] System Healthy
```

---

# Embedded Systems Concepts Learned

This project helped demonstrate:

* Embedded firmware architecture
* Real-time task execution
* Multithreading and concurrency
* Mutex synchronization
* State machine design
* Event-driven programming
* Watchdog safety systems
* Shared memory handling
* RTOS-style software design
* Modular embedded C programming

---

# Future Improvements

Potential future enhancements:

* Pedestrian crossing request system
* Traffic priority scheduling
* GUI dashboard visualization
* Network-based traffic coordination
* FreeRTOS/Linux port
* UART communication simulation
* CAN bus simulation
* Sensor fault injection testing
* Priority-based scheduling algorithms

---

# Technologies Used

* C Programming
* Windows Threads API
* Mutex Synchronization
* VS Code
* Git & GitHub

---

# Author

Pradosh G

Embedded Systems & RTOS Learning Project

---

# License

This project is intended for educational and learning purposes.
