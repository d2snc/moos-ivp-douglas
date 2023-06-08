#--------------------------------------------------------
# The CMakeLists.txt for:                       iDivisorNMEA
# Author(s):                              Douglas Lima
#--------------------------------------------------------

SET(SRC
  DivisorNMEA.cpp
  DivisorNMEA_Info.cpp
  main.cpp
)
add_subdirectory (NMEAParserLib)
add_subdirectory (libais)
ADD_EXECUTABLE(iDivisorNMEA ${SRC})

TARGET_LINK_LIBRARIES(iDivisorNMEA
   ${MOOS_LIBRARIES}
   ${MOOSGeodesy_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

#Find MOOSGeodesy
find_package(MOOSGeodesy)
include_directories(${MOOSGeodesy_INCLUDE_DIRS} ${MOOSGeodesy_LIBRARIES})
