cmake_minimum_required(VERSION 3.16)

project(main VERSION 0.1 LANGUAGES CXX)

# Qt settings
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Define source files
set(PROJECT_SOURCES main.cpp watch.cpp watch.h lights.h lights.cpp patternMaker.h patternMaker.cpp)

qt_add_executable(main ${PROJECT_SOURCES})

# Link Qt libraries
target_link_libraries(main PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)


set_target_properties(main PROPERTIES ${BUNDLE_ID_OPTION}
  MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
  MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
  MACOSX_BUNDLE TRUE WIN32_EXECUTABLE TRUE)

# Install rules
include(GNUInstallDirs)
install(TARGETS main
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Finalize executable for Qt 6

qt_finalize_executable(main)

