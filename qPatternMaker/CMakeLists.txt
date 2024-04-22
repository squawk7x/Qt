cmake_minimum_required(VERSION 3.5)

project(gtestPatternSize LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PatternSize tst_patternsize.cpp ./../patternMaker.cpp)
add_test(NAME PatternSize COMMAND PatternSize)

target_link_libraries(PatternSize PRIVATE Qt${QT_VERSION_MAJOR}::Gui
										  Qt${QT_VERSION_MAJOR}::Test)
