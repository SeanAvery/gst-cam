cmake_minimum_required(VERSION 2.8)
project( CudaMotionDetect )
include_directories(/usr/include/gstreamer-1.0 /usr/include/glib-2.0 /usr/lib/aarch64-linux-gnu/glib-2.0/include)
add_subdirectory(pybind11)
add_executable( stream src/stream.cpp )
target_link_libraries(stream gstreamer-1.0 gobject-2.0 glib-2.0 gstapp-1.0)
pybind11_add_module(pycamera src/PyCamera.cpp)
target_link_libraries(pycamera gstreamer-1.0 gobject-2.0 glib-2.0 gstapp-1.0)

