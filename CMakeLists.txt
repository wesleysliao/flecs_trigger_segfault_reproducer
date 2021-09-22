cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

# Diable building without build type
if(CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES Debug Release)
elseif(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "Missing Build Type! Run cmake with:\n-DCMAKE_BUILD_TYPE=Debug|Release")
endif()

project(APP VERSION 0.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-D_GNU_SOURCE)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  add_compile_options(-g -O0 -da -v -Q -Wall)
endif()

if(CMAKE_BUILD_TYPE MATCHES "Release")
  add_compile_options(-s -O3 -Wall -DNDEBUG)
endif()


add_subdirectory(flecs)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(APP_MODULE_SOURCES
    "${CMAKE_SOURCE_DIR}/src/modules/m_phys/m_sys_phys.c"
)

set(APP_PLATFORM_SOURCES
  "${CMAKE_SOURCE_DIR}/src/platform/pc/main.c"
)

set(APP_INCLUDE_DIRS
    "${CMAKE_SOURCE_DIR}/src/modules/m_phys"
    "${CMAKE_SOURCE_DIR}/src/platform/pc"
)


add_executable(hrun
  ${APP_MODULE_SOURCES}
  ${APP_PLATFORM_SOURCES}
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

include_directories(
  ${APP_INCLUDE_DIRS}
)

target_link_libraries(hrun
  m
  dl
  -pthread
  flecs_static)
