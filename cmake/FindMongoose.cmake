# - Find mongoose source/include folder
# This module finds mongoose if it is installed and determines where 
# the files are. This code sets the following variables:
#
#  Mongoose_FOUND             - have mongoose been found
#  Mongoose_INCLUDE_DIR       - path to where mongoose/Server.h is found
#  Mongoose_LIBRARY           - name of library (project) to add as dependency
UNSET(Mongoose_INCLUDE_DIR CACHE)
UNSET(Mongoose_INCLUDE_DIRS CACHE)

SET (Mongoose_INCLUDE_HINTS HINTS "${Mongoose_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/include")
SET (Mongoose_LIBRARY_HINTS HINTS "${Mongoose_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/lib")

FIND_PATH(Mongoose_INCLUDE_DIR
	NAMES mongoose/Server.h
	PATHS ${Mongoose_INCLUDE_HINTS}
)

FIND_LIBRARY (
    Mongoose_LIBRARY
    NAMES libMongoose${CMAKE_SHARED_LIBRARY_SUFFIX}
    PATHS ${Mongoose_LIBRARY_HINTS}		
)

IF(Mongoose_INCLUDE_DIRS AND Mongoose_LIBRARY)
	SET(Mongoose_FOUND TRUE)
	SET(Mongoose_LIBRARIES ${Mongoose_LIBRARY})
ELSE(Mongoose_INCLUDE_DIRS AND Mongoose_LIBRARY)
	SET(Mongoose_FOUND FALSE)
ENDIF(Mongoose_INCLUDE_DIRS AND Mongoose_LIBRARY)
MARK_AS_ADVANCED(
  Mongoose_INCLUDE_DIRS
  Mongoose_LIBRARIES
)