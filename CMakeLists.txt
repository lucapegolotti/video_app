cmake_minimum_required(VERSION 2.6)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/video_app/src/*.cpp)
project (video_app)
add_executable(video_app ${CMAKE_SOURCE_DIR}/video_app/main.cpp ${SOURCES})

target_include_directories (video_app
PUBLIC
${CMAKE_SOURCE_DIR}/video_app/include
${CMAKE_SOURCE_DIR}/embb/include
${CMAKE_SOURCE_DIR}/ffmpeg/include
)

set(LINK_EMBB
${CMAKE_SOURCE_DIR}/embb/lib/embb_dataflow_cpp.lib
${CMAKE_SOURCE_DIR}/embb/lib/embb_mtapi_cpp.lib
${CMAKE_SOURCE_DIR}/embb/lib/embb_mtapi_c.lib
${CMAKE_SOURCE_DIR}/embb/lib/embb_base_cpp.lib
${CMAKE_SOURCE_DIR}/embb/lib/embb_base_c.lib
)

set(LINK_FFMPEG
${CMAKE_SOURCE_DIR}/ffmpeg/lib/avcodec.lib
${CMAKE_SOURCE_DIR}/ffmpeg/lib/avutil.lib
${CMAKE_SOURCE_DIR}/ffmpeg/lib/avdevice.lib
${CMAKE_SOURCE_DIR}/ffmpeg/lib/avfilter.lib
${CMAKE_SOURCE_DIR}/ffmpeg/lib/avformat.lib
${CMAKE_SOURCE_DIR}/ffmpeg/lib/postproc.lib
${CMAKE_SOURCE_DIR}/ffmpeg/lib/swresample.lib
${CMAKE_SOURCE_DIR}/ffmpeg/lib/swscale.lib
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")

target_link_libraries(video_app ${LINK_EMBB} ${LINK_FFMPEG})
