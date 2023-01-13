#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>

void function()
{
    for (;;);
}

std::vector<std::thread> kros;
int main()
{
    for (unsigned int i = 0; i < 10; ++i)
    {
        std::cout << "Process ID: " << i << "\n";
        kros.emplace_back(function);
        SetThreadAffinityMask(kros.back().native_handle(), DWORD_PTR(1) << i);
    }
    for (auto& ThreadFunction : kros)
    {
        std::cout << "CPU Cores are working... Check your Application Manager... If you can..." << "\n";
        ThreadFunction.join();
    }
        
}