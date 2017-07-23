cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(qt_delete_example)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

find_package(Qt4 REQUIRED)
INCLUDE         (${QT_USE_FILE})
ADD_DEFINITIONS (${QT_DEFINITIONS})


set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_SOURCE_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_SHARED_LIBRARY_SUFFIX .so)

# Create Widget 
QT4_WRAP_CPP(button_moc   src/button.h)
QT4_WRAP_UI(button_ui src/button.ui)
add_library(button SHARED src/button.cpp ${button_moc} ${button_ui})
target_link_libraries(button ${QT_LIBRARIES})

# Create widget 
QT4_WRAP_CPP(buttonstack_moc src/buttonstack.h)
QT4_WRAP_UI(buttonstack_ui src/buttonstack.ui)
add_library(buttonstack SHARED src/buttonstack.cpp ${buttonstack_moc} ${buttonstack_ui})
target_link_libraries(buttonstack ${QT_LIBRARIES} button)

# main
add_executable(buttons src/main.cpp )
target_link_libraries(buttons ${QT_LIBRARIES} buttonstack)
