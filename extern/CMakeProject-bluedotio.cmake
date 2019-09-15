set(BLUEDOTIO_DIR "${SM_EXTERN_DIR}/bluedotio")

List(APPEND BLUEDOTIO_SRC
  "${BLUEDOTIO_DIR}/bluedotio.cpp"
)

list(APPEND BLUEDOTIO_HPP
  "${BLUEDOTIO_DIR}/bluedotio.hpp"
)

source_group("Source Files" FILES ${BLUEDOTIO_SRC})
source_group("Header Files" FILES ${BLUEDOTIO_HPP})

add_library("bluedotio" ${BLUEDOTIO_SRC} ${BLUEDOTIO_HPP})

set_property(TARGET "bluedotio" PROPERTY FOLDER "External Libraries")



list(APPEND BLUEDOTIO_INCLUDE_DIRS
  "${BLUEDOTIO_DIR}"
)

target_include_directories("bluedotio" PUBLIC ${BLUEDOTIO_INCLUDE_DIRS})

add_subdirectory("${BLUEDOTIO_DIR}/vendor")
target_link_libraries("bluedotio" "hidapi")
set_property(TARGET "hidapi" PROPERTY FOLDER "External Libraries")


