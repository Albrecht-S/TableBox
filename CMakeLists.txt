
cmake_minimum_required(VERSION 3.2.3)

project(TableBox)

# The following line is required only if (a) you didn't install FLTK
# or if (b) find_package can't find your installation directory because
# you installed FLTK in a non-standard location.  It points to
#   (a) the base folder of the build directory, or
#   (b) <fltk-install-prefix>/share/fltk
# resp., where <fltk-install-prefix> is the installation prefix you
# used to install FLTK.
# (The file FLTKConfig.cmake and others must be found in that path.)

set(FLTK_DIR /git/fltk/master/build/debug)

find_package(FLTK REQUIRED NO_MODULE)

add_executable(TableBox WIN32 MACOSX_BUNDLE test1.cxx TableBox.cxx)
if (APPLE)
  target_link_libraries(TableBox "-framework cocoa")
endif (APPLE)

target_include_directories(TableBox PUBLIC ${FLTK_INCLUDE_DIRS})

target_link_libraries(TableBox fltk)
