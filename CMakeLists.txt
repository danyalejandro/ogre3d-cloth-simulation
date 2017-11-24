cmake_minimum_required(VERSION 3.8)
project(ogrecam)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/app/App.cpp
        src/app/App.h
        src/app/CamGuy.cpp
        src/app/CamGuy.h
        src/drawing/Line3D.cpp
        src/drawing/Line3D.h
        src/physics/LinearSpring.cpp
        src/physics/LinearSpring.h
        src/drawing/Point3D.cpp
        src/drawing/Point3D.h
        src/drawing/PhysSphere.cpp
        src/drawing/PhysSphere.h src/physics/PhysNode.cpp src/physics/PhysNode.h src/config.h src/physics/Cloth.cpp src/physics/Cloth.h)
add_executable(ogrecam ${SOURCE_FILES})

### OGRE
find_package(OGRE 1.10 REQUIRED)
include_directories(${OGRE_INCLUDE_DIRS} ${OIS_INCLUDE_DIRS})
link_directories(${OGRE_LIBRARY_DIRS})
file(COPY ${OGRE_CONFIG_DIR}/plugins.cfg /home/dany/CLionProjects/ogrecam/media/resources.cfg /home/dany/CLionProjects/ogrecam/media/my.material /home/dany/Libraries/ogre_build/Dependencies/lib/libzzip.so /home/dany/Libraries/ogre_build/Dependencies/lib/libfreetype.so.2.6 DESTINATION ${CMAKE_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} ${OGRE_LIBRARIES} ${OIS_LIBRARIES} ${OGRE_Overlay_LIBRARIES} ${CEGUI_LIBRARIES})
