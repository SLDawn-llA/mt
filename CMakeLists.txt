#最小cmake版本
cmake_minimum_required(VERSION 3.27)
#项目名称
project(mt)
#设置c++标准
set(CMAKE_CXX_STANDARD 14)


#或者 来导用包
#include_directories()
#link_directories()
##查找所需要的库 在电脑的path或者包管理工具 vcpkg中寻找
#find_package(MPI REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
find_package(soci CONFIG REQUIRED)
#不用上面这个那就只能手动寻找 地址  用下面这个 \改为/
include_directories(E:/vcpkg/installed/x64-windows/include)

#添加可执行文件
#add_executable(mt main.cpp)
#或者可以 把项目名  mt 改为${PROJECT_NAME}
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)
#链接完后  然后就可以用eigen了