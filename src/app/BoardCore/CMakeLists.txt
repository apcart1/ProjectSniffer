# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (InterfaceSniffer VERSION 1.0)

include(CTest)
enable_testing()

# Set root directories for:
set(CORE_MODULES_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Core)
set(APPLICATION_MODULE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Application)
set(HARDWARE_MODULES_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Hardware)

set(CORE_IOC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Core/IoC)
set(HARDWARE_API_MODULES_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Hardware/API)
set(HARDWARE_CANBUS_MODULES_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Hardware/CANBus)
set(HARDWARE_UART_MODULES_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Hardware/UART)

set(INCLUDES
	${APPLICATION_MODULE_ROOT}/includes
	${CORE_IOC_ROOT}/includes
	${HARDWARE_API_MODULES_ROOT}
	${HARDWARE_CANBUS_MODULES_ROOT}/includes
	${HARDWARE_UART_MODULES_ROOT}/includes
)

set(APP_FILES 
	${APPLICATION_MODULE_ROOT}/main.cpp
)
set(CORE_FILES 
	${CORE_IOC_ROOT}/CoreModule.cpp
	${CORE_IOC_ROOT}/IOCContainer.cpp
	${CORE_IOC_ROOT}/StartupContainer.cpp
)
set(HARDWARE_CANBUS_FILES
	${HARDWARE_CANBUS_MODULES_ROOT}/canbus_temp.cpp
)
set(HARDWARE_UART_FILES
	${HARDWARE_UART_MODULES_ROOT}/uart_temp.cpp
)
add_library(HardwareLib
	 ${APP_FILES} 
	 ${CORE_FILES} 
	 ${HARDWARE_API_FILES} 
	 ${HARDWARE_CANBUS_FILES}
	 ${HARDWARE_UART_FILES}
)

target_include_directories(HardwareLib PUBLIC ${INCLUDES})


add_executable(Application  ${APPLICATION_MODULE_ROOT}/main.cpp)
target_include_directories(Application PUBLIC HardwareLib)
target_link_libraries(Application HardwareLib)

set_property(TARGET HardwareLib PROPERTY CXX_STANDARD 17)


  
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
