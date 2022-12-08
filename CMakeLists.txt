cmake_minimum_required(VERSION 2.8)
project(MST)

#Added to detect compiler support for C++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
option(SEPARATE_ACTION_INITIALIZATION "Use the Separate Action Initialization Class" ON)
option(USE_ROOT "Use ROOT to store data and histogram" OFF)

if(USE_ROOT)
add_definitions(-DUSE_ROOT)
find_package(ROOT REQUIRED)
#message(STATUS "GEant include dir : "${ROOT_INCLUDE_DIRS})
include_directories(${ROOT_INCLUDE_DIRS})
endif()

if(SEPARATE_ACTION_INITIALIZATION)
add_definitions(-DSEPARATE_ACTION_INITIALIZATION)
endif()

if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#----------------------------------------------------------------------------

#Can be enabled to copy required files
file(GLOB MAC_FILES ${PROJECT_SOURCE_DIR}/MacFiles/*)
message(STATUS ${MAC_FILES})
file(COPY ${MAC_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/inc)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.cc)


add_executable(main main.cpp ${sources} ${headers})
add_executable(TestProfile TestProfile.cpp)
if(USE_ROOT)
target_link_libraries(main ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})
target_link_libraries(TestProfile ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})
else()
target_link_libraries(main ${Geant4_LIBRARIES})
endif()
#target_link_libraries(main ${Geant4_LIBRARIES} Tomo)
