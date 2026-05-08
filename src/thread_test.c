#include <stdio.h>
#include <windows.h>

DWORD WINAPI task1(LPVOID arg)
{
    while (1)
    {
        printf("Traffic Task Running...\n");
        Sleep(1000);
    }
}

DWORD WINAPI task2(LPVOID arg)
{
    while (1)
    {
        printf("Sensor Task Running...\n");
        Sleep(1500);
    }
}

int main()
{
    HANDLE thread1, thread2;

    thread1 = CreateThread(
        NULL,
        0,
        task1,
        NULL,
        0,
        NULL
    );

    thread2 = CreateThread(
        NULL,
        0,
        task2,
        NULL,
        0,
        NULL
    );

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    return 0;
}