#--------------------------------------------------------
# The CMakeLists.txt for:                       pUDP_Receiver
# Author(s):                              Douglas Lima
#--------------------------------------------------------

SET(SRC
  UDP_Receiver.cpp
  UDP_Receiver_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pUDP_Receiver ${SRC})

TARGET_LINK_LIBRARIES(pUDP_Receiver
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

