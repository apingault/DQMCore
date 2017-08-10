# - Find mongoose source/include folder
# This module finds mongoose if it is installed and determines where 
# the files are. This code sets the following variables:
#
#  Mongoose_FOUND             - have mongoose been found
#  Mongoose_INCLUDE_DIR       - path to where mongoose/Server.h is found
#  Mongoose_LIBRARY           - name of library (project) to add as dependency
FIND_PATH(Mongoose_INCLUDE_DIR
	NAMES mongoose/Server.h
	PATHS
		${CMAKE_SOURCE_DIR}/mongoose-cpp
		${Mongoose_DIR}
		${Mongoose_INCLUDE_DIR}
		${NSCP_INCLUDEDIR}
)

IF(Mongoose_INCLUDE_DIR)
	SET(Mongoose_FOUND TRUE)
	SET(Mongoose_LIBRARY _mongoose)
ELSE(Mongoose_INCLUDE_DIR)
	SET(Mongoose_FOUND FALSE)
	SET(Mongoose_LIBRARY)
ENDIF(Mongoose_INCLUDE_DIR)
MARK_AS_ADVANCED(
  Mongoose_INCLUDE_DIR
  Mongoose_LIBRARY
)