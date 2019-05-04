cmake_minimum_required( VERSION 3.0 )

project( flappy )

include_directories( ./include ./src  )
add_executable( flappy ./src/main.cpp ./src/obstacle.cpp ./src/bird.cpp )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries( flappy OpenGL ${GLUT_LIBRARY} )