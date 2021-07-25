file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
file(GLOB HEADERS "${CMAKE_CURRENT_LIST_DIR}/include/*.h")

add_library(Audio STATIC ${SOURCES} ${HEADERS})
target_include_directories(Audio
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
if(MSVC)
    target_compile_options(Audio PRIVATE /W4 /WX)
else()
    target_compile_options(Audio PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
