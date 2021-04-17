cmake_minimum_required(VERSION 3.16.0)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(ota_update_demo)

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)
idf_component_register(SRCS ${app_sources})
target_add_binary_data(${COMPONENT_TARGET} "../server/ca_cert.pem" TEXT)
