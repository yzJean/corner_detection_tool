cmake_minimum_required(VERSION 2.8)
project(startProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( OpenCV REQUIRED )
message(STATUS " Opencv package: ${OpenCV_DIR}")
message(STATUS " Opencv version: ${OpenCV_VERSION}")

# add opencv include directories
include_directories( ${OpenCV_INCLUDE_DIRS} )
message(STATUS " Opencv include dirs: ${OpenCV_INCLUDE_DIRS}")

include_directories( ${PROJECT_SOURCE_DIR} )
message(STATUS " Project source directory: ${PROJECT_SOURCE_DIR}")

# add_subdirectory( ${PROJECT_SOURCE_DIR}/include )
# message(STATUS " Project source directory: ${PROJECT_SOURCE_DIR}/include")

add_executable( startProject main.cpp reader.cpp)
target_link_libraries( startProject ${OpenCV_LIBS} )
message(STATUS " Opencv libs: ${OpenCV_LIBS}")
