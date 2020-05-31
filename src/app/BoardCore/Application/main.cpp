// main.cpp : Defines the entry point for the application.

#include "main.hpp"
#include <iostream>

#include "IModule.hpp"
#include "StartupContainer.hpp"

#include "API_temp.hpp"

#define _TIMESTAMP_ __DATE__ " " __TIME__

using namespace std;

int main()
{
	printf("*******************************************\n");
	printf("** START SYSTEM <<" _TIMESTAMP_ ">> **\n");
	printf("*******************************************\n");

    ModulePtr api_module = std::make_shared<APIModule>();

    StartupContainer stContainer;

    stContainer.Register(api_module);


    stContainer.Init(); // creates core module
    stContainer.WaitForExit();

	return 0;
}
