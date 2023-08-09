#--------------------------------------------------------
# The CMakeLists.txt for:                       pXYZ
# Author(s):                              Douglas Lima
#--------------------------------------------------------

SET(SRC
  XYZ.cpp
  XYZ_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pXYZ ${SRC})

TARGET_LINK_LIBRARIES(pXYZ
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

