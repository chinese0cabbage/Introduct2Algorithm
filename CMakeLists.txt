cmake_minimum_required(VERSION 3.7)

include_directories(/下载/boost_1_70_0/boost/)
link_directories(/下载/boost_1_70_0/boost/lib/)
#target_link_libraries(mysql-show boost)

project(Introduct2Algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Introduct2Algorithm main.cpp chapter4/MaxSubArray.cpp chapter4/MaxSubArray.h fundamentalType/Matrix.h fundamentalType/Vec.h)