cmake_minimum_required (VERSION 3.8)
project ("cxsher")

set(CMAKE_CXX_STANDARD 17)
set(cxsher_VERSION_MAJOR 0)
set(cxsher_VERSION_MINOR 0)
set(cxsher_VERSION_PATCH 5)

include(InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${cxsher_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${cxsher_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${cxsher_VERSION_PATCH}")
include(CPack)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp.in" 
  "${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp"
)

option(cxsher_use_shared "use shared library" ON)


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/libs/libuv")
include_directories(include)
file(GLOB_RECURSE libcxsher_SOURCES CONFIGURE_DEPENDS src/cxsher/*.cpp)

if(${cxsher_use_shared} STREQUAL ON)
  add_library(libcxsher OBJECT SHARED ${libcxsher_SOURCES})
  add_executable(cxsher src/cxsher.cpp $<TARGET_OBJECTS:libcxsher>)
  target_link_libraries(cxsher uv)
else()
  add_library(libcxsher OBJECT STATIC ${libcxsher_SOURCES})
  add_executable(cxsher src/cxsher.cpp $<TARGET_OBJECTS:libcxsher>)
  target_link_libraries(cxsher uv_a)
endif(${cxsher_use_shared} STREQUAL ON)