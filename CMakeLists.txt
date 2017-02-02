cmake_minimum_required(VERSION 2.8)

include(GNUInstallDirs)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DLIBEXECDIR="${CMAKE_BINARY_DIR}")
elseif(EXISTS ${CMAKE_INSTALL_FULL_LIBEXECDIR})
    add_definitions(-DLIBEXECDIR="${CMAKE_INSTALL_FULL_LIBEXECDIR}")
else()
    add_definitions(-DLIBEXECDIR="${CMAKE_INSTALL_PREFIX_PATH}/daemon")
endif()

add_executable(daemon daemon.cpp)
add_executable(start start.cpp)
add_executable(stop stop.cpp)
add_executable(restart restart.cpp)
add_executable(status status.cpp)
add_executable(enable enable.cpp)
add_executable(disable disable.cpp)
#add_executable(exec exec.cpp)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -pedantic -Wconversion -Wsign-conversion -Weffc++")
install(TARGETS daemon DESTINATION bin)
#if(IS_DIRECTORY /run/systemd/system)
#    add_definitions(-DINIT=SYSD)
#endif

