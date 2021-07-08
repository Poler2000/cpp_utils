cmake_minimum_required(VERSION 3.10)
project(CppUtils VERSION 1.0.0 DESCRIPTION "set of cpp utilities")

include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/BenchmarkTimer.cpp
        src/Logger.cpp
        src/Random.cpp
        src/SimpleTimer.cpp)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

set_target_properties(${PROJECT_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1)

install(TARGETS ${PROJECT_NAME} EXPORT CppUtilsConfig
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(EXPORT CppUtilsConfig DESTINATION share/CppUtils/cmake)

export(TARGETS ${PROJECT_NAME} FILE CppUtilsConfig.cmake)