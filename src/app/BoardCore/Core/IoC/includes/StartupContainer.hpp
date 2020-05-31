#pragma once

#include <vector>
#include "IModule.hpp"

// entering piont in Application
class StartupContainer
{
public:
	void Register(ModulePtr);

	void Init();	// calls module->OnRegister()

	void WaitForExit();  //  run calls module->OnLoad() and then at the end calls
						 //  module->OnUnload()

private:
	std::vector<ModulePtr> modules;
};