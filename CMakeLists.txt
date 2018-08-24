cmake_minimum_required (VERSION 2.6)
project(libsrs)
option(BUILD_WITH_IMP "/MT /MTd" ON)
option(BUILD_WITH_TEST "build with demo " OFF)
option(BUILD_WITH_STATIC "build with static" ON)
option(BUILD_WITH_SHARD "build with shard" OFF)

#configure_file(${CMAKE_CURRENT_LIST_DIR}srs_auto_headers.hpp.in )
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/core)
include_directories(${CMAKE_CURRENT_LIST_DIR}/kernel)
include_directories(${CMAKE_CURRENT_LIST_DIR}/libs)
include_directories(${CMAKE_CURRENT_LIST_DIR}/protocol)

file(GLOB ROOT_HEADERS "${CMAKE_CURRENT_LIST_DIR}/*.h*" )
file(GLOB ROOT_SRCS "${CMAKE_CURRENT_LIST_DIR}/*.c*")

file(GLOB CORE_HEADERS "${CMAKE_CURRENT_LIST_DIR}/core/*.h*" )
file(GLOB CORE_SRCS "${CMAKE_CURRENT_LIST_DIR}/core/*.c*")

file(GLOB KERNEL_HEADERS "${CMAKE_CURRENT_LIST_DIR}/kernel/*.h*" )
file(GLOB KERNEL_SRCS "${CMAKE_CURRENT_LIST_DIR}/kernel/*.c*")

file(GLOB LIBS_HEADERS "${CMAKE_CURRENT_LIST_DIR}/libs/*.h*" )
file(GLOB LIBS_SRCS "${CMAKE_CURRENT_LIST_DIR}/libs/*.c*")

file(GLOB PROTOCOL_HEADERS "${CMAKE_CURRENT_LIST_DIR}/protocol/*.h*" )
file(GLOB PROTOCOL_SRCS "${CMAKE_CURRENT_LIST_DIR}/protocol/*.c*")

if(MSVC AND BUILD_WITH_IMP)
    set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )

    foreach(CompilerFlag ${CompilerFlags})
			string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
			string(REPLACE "/Ob0" "" ${CompilerFlag} "${${CompilerFlag}}")
			string(REPLACE "/TC" "" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()
endif()

if(BUILD_WITH_STATIC)
    add_library(srs STATIC ${ROOT_HEADERS} ${ROOT_SRCS}
    ${CORE_HEADERS} ${CORE_SRCS}
    ${KERNEL_HEADERS} ${KERNEL_SRCS}
    ${LIBS_HEADERS} ${LIBS_SRCS}
    ${PROTOCOL_HEADERS} ${PROTOCOL_SRCS})
    install(TARGETS srs
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib )
endif()

if(BUILD_WITH_SHARD)
    set(LIB_NAME srs)
    if(BUILD_WITH_STATIC)
        set(LIB_NAME srs-shared)
    endif()

    add_library(${LIB_NAME} SHARED ${ROOT_HEADERS} ${ROOT_SRCS}
    ${CORE_HEADERS} ${CORE_SRCS}
    ${KERNEL_HEADERS} ${KERNEL_SRCS}
    ${LIBS_HEADERS} ${LIBS_SRCS}
    ${PROTOCOL_HEADERS} ${PROTOCOL_SRCS})

    install(TARGETS ${LIB_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib )
endif()

if(BUILD_WITH_TEST)
add_executable(srs_test_paly ${CMAKE_CURRENT_LIST_DIR}/test/main.c)
TARGET_LINK_LIBRARIES(srs_test_paly srs)
endif()

install(FILES ${ROOT_HEADERS}  ${CORE_HEADERS} ${KERNEL_HEADERS} ${LIBS_HEADERS}  ${PROTOCOL_HEADERS} DESTINATION include )