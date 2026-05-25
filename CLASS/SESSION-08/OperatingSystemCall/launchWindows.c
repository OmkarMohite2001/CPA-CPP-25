#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD exitCode;

    // Initialize structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    // Child process launch
    if(!CreateProcess(
        "hello.exe",   // executable name
        NULL,          // command line
        NULL,          // process security
        NULL,          // thread security
        FALSE,         // inherit handles
        0,             // creation flags
        NULL,          // environment
        NULL,          // current directory
        &si,
        &pi))
    {
        printf("CreateProcess failed (%lu)\n", GetLastError());
        return 1;
    }

    // Wait for child process
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Get exit code
    GetExitCodeProcess(pi.hProcess, &exitCode);

    printf("CHILD HAS TERMINATED\n");
    printf("Return Value = %lu\n", exitCode);

    // Close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}