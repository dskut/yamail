cmake_minimum_required (VERSION 2.6)

project(yamail)
set(TARGET_LIBRARY "yamail")

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

set(CMAKE_CPP_FLAGS_RELEASE  "-DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE  " -g -O2")
set(CMAKE_CXX_FLAGS_DEBUG    " -g -O0")

set(FLAGS
 "-Wall"
 "-Wextra"
 "-Wconversion"
 "-Wcast-qual"
 "-Winline"
 "-Woverloaded-virtual"
 "-Wctor-dtor-privacy"
 "-Wnon-virtual-dtor"
 "-Wold-style-cast"
 "-Wpacked"
 "-Wredundant-decls"
 "-fexceptions"
 "-pthread"
 "-fpic"
 "-pipe"
)
foreach(FLAG ${FLAGS})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAG}")
endforeach()

set(Boost_USE_STATIC_LIBS OFF)
add_definitions(-DBOOST_LOG_DYN_LINK)
find_package(Boost REQUIRED
    system
)
find_package(Threads REQUIRED)


include_directories(SYSTEM ${Boost_INCLUDE_DIRS} "${CMAKE_INSTALL_PREFIX}/include")
include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

add_library(${TARGET_LIBRARY} SHARED ${SOURCES})
target_link_libraries(${TARGET_LIBRARY} 
    ${Boost_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)


if(CMAKE_BUILD_TEST)
    enable_testing()
    add_subdirectory(tests)
endif(CMAKE_BUILD_TEST)