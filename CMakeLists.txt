cmake_minimum_required(VERSION 3.20)
set(LIB_NAME "tinyexpr")
project(${LIB_NAME} C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
if (CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_C_EXTENSIONS ON)
endif()
if (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_EXTENSIONS ON)
endif()

set(SRC_FILES_LIB 
  tinyexpr.cpp
)
add_library(${LIB_NAME})
target_sources(${LIB_NAME} PRIVATE ${SRC_FILES_LIB})
target_sources(${LIB_NAME} INTERFACE tinyexpr.h)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

if (NOT MSVC) 
  target_compile_options(${LIB_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter)
endif()

add_executable(example-${LIB_NAME} example.cpp)
target_link_libraries(example-${LIB_NAME} PRIVATE ${LIB_NAME})

add_executable(example2-${LIB_NAME} example2.cpp)
target_link_libraries(example2-${LIB_NAME} PRIVATE ${LIB_NAME})

add_executable(example3-${LIB_NAME} example3.cpp)
target_link_libraries(example3-${LIB_NAME} PRIVATE ${LIB_NAME})

add_executable(example4-${LIB_NAME} example4.cpp)
target_link_libraries(example4-${LIB_NAME} PRIVATE ${LIB_NAME})


include(GNUInstallDirs)
install(TARGETS ${LIB_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(
  FILES "tinyexpr.h"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
