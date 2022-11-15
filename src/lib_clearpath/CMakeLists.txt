#--------------------------------------------------------
# The CMakeLists.txt for:                   lib_clearpath
# Author(s):                                Mike Benjamin
#--------------------------------------------------------

SET(SRC
  crc.cpp
  cwrap.cpp
  linux_serial.cpp
  Logger.cpp
  Message_cmd.cpp
  Message.cpp
  Message_data.cpp
  Message_request.cpp
  Number.cpp
  Transport.cpp
)

IF( ${WIN32} )
SET (SRC
  windows_serial.cpp
)
ENDIF( ${WIN32} )


SET(HEADERS
  clearpath.h
  crc.h
  cwrap.h
  dead_reckon.h
  Exception.h
  keyboard_ctrl.h
  Logger.h
  Message_cmd.h
  Message_data.h
  Message.h
  Message_request.h
  Number.h
  serial.h
  Transport.h
)

# Build Library
ADD_LIBRARY(clearpath ${SRC})

# Install Headers
#INSTALL( FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/lib_clearpath)

# Install Libararies
INSTALL( TARGETS clearpath
   RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
   LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
   ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
