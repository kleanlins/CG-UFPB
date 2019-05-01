cmake_minimum_required( VERSION 3.0 )

project( skater )

include_directories( ./include ./src  )
add_executable( skater ./src/main.cpp ./src/obstacle.cpp ./src/skater.cpp )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries( skater OpenGL ${GLUT_LIBRARY} )