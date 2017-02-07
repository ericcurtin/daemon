cmake_minimum_required(VERSION 2.8)

include(GNUInstallDirs)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DLIBEXECDIR="${CMAKE_BINARY_DIR}")
elseif (EXISTS ${CMAKE_INSTALL_FULL_LIBEXECDIR})
    add_definitions(-DLIBEXECDIR="${CMAKE_INSTALL_FULL_LIBEXECDIR}")
else ()
    add_definitions(-DLIBEXECDIR="${CMAKE_INSTALL_PREFIX_PATH}/daemon")
endif ()

add_library(exec src/lib/exec.cpp)

add_executable(daemon src/daemon.cpp)
target_link_libraries(daemon exec)

add_executable(start src/lib/exec/start.cpp)
add_executable(stop src/lib/exec/stop.cpp)
add_executable(restart src/lib/exec/restart.cpp)
add_executable(status src/lib/exec/status.cpp)
add_executable(enable src/lib/exec/enable.cpp)
add_executable(disable src/lib/exec/disable.cpp)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -pedantic -Wconversion -Wsign-conversion -Weffc++")
install(TARGETS daemon DESTINATION bin)
#if(IS_DIRECTORY /run/systemd/system)
#    add_definitions(-DINIT=SYSD)
#endif

