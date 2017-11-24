cmake_minimum_required(VERSION 3.8)
project(ogre3d-cloth-simulation)

set(CMAKE_CXX_STANDARD 11)

### Set these paths to your own system
set (PROJECT_FULL_PATH /home/dany/CLionProjects/ogre3d-cloth-simulation)
set (OGRE_BUILD_PATH /home/dany/Libraries/ogre_build)

set(SOURCE_FILES
        src/main.cpp src/app/App.cpp src/app/App.h src/app/CamGuy.cpp src/app/CamGuy.h src/drawing/Line3D.cpp src/drawing/Line3D.h src/physics/LinearSpring.cpp src/physics/LinearSpring.h src/drawing/Point3D.cpp src/drawing/Point3D.h src/drawing/PhysSphere.cpp src/drawing/PhysSphere.h src/physics/PhysNode.cpp src/physics/PhysNode.h src/config.h src/physics/Cloth.cpp src/physics/Cloth.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

### OGRE
find_package(OGRE 1.10 REQUIRED)
include_directories(${OGRE_INCLUDE_DIRS} ${OIS_INCLUDE_DIRS})
link_directories(${OGRE_LIBRARY_DIRS})
file(COPY ${OGRE_CONFIG_DIR}/plugins.cfg ${OGRE_BUILD_PATH}/Dependencies/lib/libzzip.so ${OGRE_BUILD_PATH}/Dependencies/lib/libfreetype.so.2.6 DESTINATION ${CMAKE_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} ${OGRE_LIBRARIES} ${OIS_LIBRARIES} ${OGRE_Overlay_LIBRARIES} ${CEGUI_LIBRARIES})
