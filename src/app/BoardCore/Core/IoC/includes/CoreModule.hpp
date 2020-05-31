#pragma once

#include "IModule.hpp"

class CoreModule : public IModule
{
public:
    void OnRegister(IOCContainerPtr) override;

    void OnLoad(IOCContainerPtr) override;

    void OnUnload() override;

};