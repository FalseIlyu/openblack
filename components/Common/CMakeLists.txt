file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
file(GLOB HEADERS "${CMAKE_CURRENT_LIST_DIR}/include/*.h")

add_library(Common STATIC ${SOURCES} ${HEADERS})
target_include_directories(Common
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_link_libraries(
  Common
  PRIVATE
        "$<$<CXX_COMPILER_ID:MSVC>:-SAFESEH:NO>"
        glm::glm
        spdlog::spdlog
)

if(MSVC)
    set(CMAKE_CONFIGURATION_TYPES
            Debug Release
            CACHE STRING "" FORCE)

    target_compile_definitions(Common
            PRIVATE
            # Get rid of useless crud from windows.h
            NOMINMAX
            WIN32_LEAN_AND_MEAN
            # disable CRT warnings on windows cause they're annoying as shit and we use C
            # functions everywhere
            _CRT_SECURE_NO_WARNINGS
            )
endif()

if(HAS_FILESYSTEM)
    message(STATUS "Got <filesystem>: add compiler definition HAS_FILESYSTEM")
    target_compile_definitions(Common PRIVATE HAS_FILESYSTEM)
else()
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        message(
                STATUS
                "No <filesystem>: linking stdc++fs on unknown compiler id: ${CMAKE_CXX_COMPILER_ID}"
        )
        target_link_libraries(Common PRIVATE stdc++fs)
    else()
        message(
                STATUS "No <filesystem> on unknown compiler id: ${CMAKE_CXX_COMPILER_ID}")
    endif()
endif()

if(MSVC)
    target_compile_options(Common PRIVATE /W4 /WX)
else()
    target_compile_options(Common PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
