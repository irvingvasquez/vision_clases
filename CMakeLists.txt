cmake_minimum_required(VERSION 2.6)
project(computer_vision_examples)

FIND_PACKAGE( OpenCV 3.0.0 REQUIRED )
# Show a message with the opencv version detected
MESSAGE("OpenCV version : ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_executable(pr01_read pr01_read.cpp)

TARGET_LINK_LIBRARIES(pr01_read ${OpenCV_LIBS} )

install(TARGETS pr01_read RUNTIME DESTINATION bin)

