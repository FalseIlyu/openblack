# Configure C++ standard

file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
file(GLOB HEADERS "${CMAKE_CURRENT_LIST_DIR}/include/*.h")

# force glm left handedness
add_definitions(-DGLM_FORCE_LEFT_HANDED -DGLM_FORCE_RADIANS
        -DGLM_ENABLE_EXPERIMENTAL)
add_library(Audio STATIC ${SOURCES} ${HEADERS})
target_include_directories(Audio
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_link_libraries(
  Audio
  PRIVATE
          sad
          pack
          Common
          glm::glm
          spdlog::spdlog
          OpenAL::OpenAL
          ${FFmpeg_LIBRARIES}
)

if(HAS_FILESYSTEM)
    message(STATUS "Got <filesystem>: add compiler definition HAS_FILESYSTEM")
    target_compile_definitions(Audio PRIVATE HAS_FILESYSTEM)
else()
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        message(
                STATUS
                "No <filesystem>: linking stdc++fs on unknown compiler id: ${CMAKE_CXX_COMPILER_ID}"
        )
        target_link_libraries(Audio PRIVATE stdc++fs)
    else()
        message(
                STATUS "No <filesystem> on unknown compiler id: ${CMAKE_CXX_COMPILER_ID}")
    endif()
endif()
