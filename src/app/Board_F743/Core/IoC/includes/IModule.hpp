#pragma once

#include <memory>
#include "IOCContainer.hpp"

class IModule {
public:
    virtual ~IModule() = default;

    // Will be called by startup container
    // Phase 1 ( Registartin phase )
    // supposed to register all the components
    virtual void OnRegister(IOCContainerPtr) = 0;

    // Phase 2 ( Startup phase )
    virtual void OnLoad(IOCContainerPtr) = 0;

    // Phase 3 ( Shutdown phase )
    virtual void OnUnload() = 0;
};

using ModulePtr = std::shared_ptr<IModule>;