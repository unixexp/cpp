cmake_minimum_required(VERSION 3.15)
project(BaseAudioProcessing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(
    BaseAudioProcessing
    main.cpp
    AudioCallback.cpp
    Utils.cpp
    )

if(APPLE)
    find_library(COREFOUNDATION_LIBRARY CoreFoundation)
    target_link_libraries(BaseAudioProcessing PRIVATE
        "-framework CoreAudio"
        "-framework AudioToolbox"
        ${COREFOUNDATION_LIBRARY}
    )
endif()
