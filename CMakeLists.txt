cmake_minimum_required(VERSION 2.6)
project(computer_vision_examples)

FIND_PACKAGE( OpenCV 3.0.0 REQUIRED )
# Show a message with the opencv version detected
MESSAGE("OpenCV version : ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_executable(pr01_read pr01_read.cpp)
TARGET_LINK_LIBRARIES(pr01_read ${OpenCV_LIBS} )

add_executable(pr02_crop pr02_crop.cpp)
TARGET_LINK_LIBRARIES(pr02_crop ${OpenCV_LIBS} )

add_executable(pr03_sum pr03_sum.cpp)
TARGET_LINK_LIBRARIES(pr03_sum ${OpenCV_LIBS} )

add_executable(pr04_wsum pr04_wsum.cpp)
TARGET_LINK_LIBRARIES(pr04_wsum ${OpenCV_LIBS} )

add_executable(pr05_histogram pr05_histogram.cpp)
TARGET_LINK_LIBRARIES(pr05_histogram ${OpenCV_LIBS} )

add_executable(pr06_linear_filtering pr06_linear_filtering.cpp)
TARGET_LINK_LIBRARIES(pr06_linear_filtering ${OpenCV_LIBS} )

install(TARGETS pr01_read RUNTIME DESTINATION bin)