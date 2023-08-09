##############################################################################
# FILE:        moos-ivp-extend/src/CMakeLists.txt
# DATE:        2010/09/07
#              2020/05/09 minor mods
# DESCRIPTION: CMakeLists.txt file for the moos-ivp-extend source directory
##############################################################################


#============================================================================
# Add the libraries in the current directory to the include path
#============================================================================
FILE(GLOB LOCAL_LIBRARY_DIRS ./lib_*)
INCLUDE_DIRECTORIES(${LOCAL_LIBRARY_DIRS})

#============================================================================
# List the subdirectories to build...
#============================================================================

#Coisas original do make
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(lib_behaviors-test)
ADD_SUBDIRECTORY(pExampleApp)
ADD_SUBDIRECTORY(pXRelayTest)
ADD_SUBDIRECTORY(pOdometry)
ADD_SUBDIRECTORY(iSerial)
ADD_SUBDIRECTORY(iDivisorNMEA)
ADD_SUBDIRECTORY(pUDP_Receiver)
ADD_SUBDIRECTORY(pXYZ)
#ADD_SUBDIRECTORY(pSimpass)


#Find MOOSGeodesy
find_package(MOOSGeodesy)
include_directories(${MOOSGeodesy_LIBRARIES})
include_directories(${MOOSGeodesy_INCLUDE_DIRS})
link_directories(${MOOSGeodesy_LIBRARIES})




##############################################################################
#                           END of CMakeLists.txt
##############################################################################

