cmake_minimum_required(VERSION 2.6)
project(computer_vision_examples)

FIND_PACKAGE( OpenCV 3.0.0 REQUIRED )
# Show a message with the opencv version detected
MESSAGE("OpenCV version : ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

#Activar si se tienen instaladas las librerias extra
set(NONFREE false)

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

add_executable(pr07_sobel pr07_sobel.cpp)
TARGET_LINK_LIBRARIES(pr07_sobel ${OpenCV_LIBS})

add_executable(pr08_canny pr08_canny.cpp)
TARGET_LINK_LIBRARIES(pr08_canny ${OpenCV_LIBS})

add_executable(pr09_thresholding pr09_thresholding.cpp)
TARGET_LINK_LIBRARIES(pr09_thresholding ${OpenCV_LIBS})

add_executable(pr10_harris pr10_harris.cpp)
TARGET_LINK_LIBRARIES(pr10_harris ${OpenCV_LIBS})

add_executable(pr11_orb pr11_orb.cpp)
TARGET_LINK_LIBRARIES(pr11_orb ${OpenCV_LIBS})

if(NONFREE)
  add_executable(nonfree_01_surf nonfree_01_surf.cpp)
  target_link_libraries(nonfree_01_surf ${OpenCV_LIBS})
endif()

install(TARGETS pr01_read RUNTIME DESTINATION bin)