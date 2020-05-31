#include <iostream>

#include "CoreModule.hpp"
#include "StartupContainer.hpp"

void StartupContainer::Register(ModulePtr module) {
    std::cout << "Register\n";
}

void StartupContainer::Init() {
    std::cout << "Register Core Module\n";

    Register(std::make_shared<CoreModule>());
    std::cout << "Init\n";
}


void StartupContainer::WaitForExit() {
    std::cout << "Start Application!!!\n";
}
