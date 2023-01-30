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
   apputil
   mbutil
   m
   pthread)

