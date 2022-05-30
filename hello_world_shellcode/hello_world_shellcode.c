#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

unsigned char buffer[] = "\x66\xba\x0e\x00\x00\x00\x66\xb9\x1c\x00\x00\x00\x66\xbb\x01"
                         "\x00\x00\x00\x66\xb8\x04\x00\x00\x00\xcd\x80\x00\x00\x48\x65"
                         "\x6c\x6c\x6f\x20\x77\x6f\x72\x6c\x64\x21\x21\x0a";

int main(int argc, char *argv[]) {
    PVOID shellcode_exec;
    DWORD threadID;
    HANDLE hThread;
    
    shellcode_exec = VirtualAlloc(0, sizeof(buffer), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    RtlCopyMemory(shellcode_exec, buffer, sizeof(buffer));
    hThread = CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)shellcode_exec, NULL, 0, &threadID);
    WaitForSingleObject(hThread, INFINITE);
}
