#--------------------------------------------------------
# The CMakeLists.txt for:                       pIMU
# Author(s):                              Douglas Lima
#--------------------------------------------------------

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS thread system)

#Include the serial library
add_subdirectory(serial)

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  #${catkin_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  /tmp/usr/local/include
  ${CMAKE_CURRENT_SOURCE_DIR}/serial/include
)

link_directories(
  /tmp/usr/local/lib

  )

## Declare a C++ library
add_library(xbow440
  src/xbow440.cpp
)

target_link_libraries(
  xbow440
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_THREAD_LIBRARY}
  serial
)


SET(SRC
  IMU.cpp
  IMU_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pIMU ${SRC})

TARGET_LINK_LIBRARIES(pIMU
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread
   xbow440)

