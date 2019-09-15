add_subdirectory(vendor)

if(NOT TARGET hidapi)
    message(FATAL_ERROR "This app doesn't do anything without HIDAPI - fix the errors above!")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(bluedotio STATIC bluedotio.hpp bluedotio.cpp)
target_link_libraries(bluedotio hidapi)

target_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
