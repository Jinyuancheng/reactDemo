cmake_minimum_required(VERSION 3.0)
#工程名 可执行文件的名称
set(project_name cinatra_web)
project(${project_name})
#set(CMAKE_BUILD_TYPE Release)
#MSVC windows
if (MSVC)
	#设置编译环境
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
else ()
	#设置编译环境c++17
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread -std=c++17")
endif ()

#option(ENABLE_SSL   "Set to switch to build use ssl"  OFF)
#option(ENABLE_GZIP  "Set to switch to build use gzip" OFF)
#定义变量
SET(ENABLE_GZIP OFF)
SET(ENABLE_SSL OFF)
SET(ENABLE_CLIENT_SSL OFF)
option(ENABLE_ASIO_STANDALONE "ENABLE_ASIO_STANDALONE" ON)
if (ENABLE_SSL)
	add_definitions(-DCINATRA_ENABLE_SSL)
	message(STATUS "Use SSL")
endif()

if(ENABLE_GZIP)
	add_definitions(-DCINATRA_ENABLE_GZIP)
endif()

if(ENABLE_CLIENT_SSL)
	add_definitions(-DCINATRA_ENABLE_CLIENT_SSL)
endif()

if(ENABLE_ASIO_STANDALONE)
	add_definitions(-DASIO_STANDALONE)
else()
	find_package(Boost REQUIRED COMPONENTS system)
endif()

if (ENABLE_SSL)
find_package(OpenSSL REQUIRED)
endif()
if (ENABLE_CLIENT_SSL)
	find_package(OpenSSL REQUIRED)
endif()

if (ENABLE_GZIP)
	find_package(ZLIB REQUIRED)
endif()

#添加所有头文件
include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/cinatra/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/utils/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/server/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/inifile/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/template/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/router/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/mysql/*"
	#"${CMAKE_CURRENT_SOURCE_DIR}/src"
)
 
#添加所有的源文件
file(GLOB all_src_file
	"${CMAKE_CURRENT_SOURCE_DIR}/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/utils/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/server/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/inifile/*"
	"${CMAKE_CURRENT_SOURCE_DIR}/mysql/*"
	#"${CMAKE_CURRENT_SOURCE_DIR}/student/*"
)

#添加动态库（路径）
link_directories(
	#"${CMAKE_CURRENT_SOURCE_DIR}/lib"
	"/usr/lib64/"
)
#生成可执行文件
add_executable(${project_name} ${all_src_file})
#添加头文件
include_directories(
	${Boost_INCLUDE_DIRS}
	${OPENSSL_INCLUDE_DIR}	
	) 
#链接库
target_link_libraries(${project_name} ${Boost_LIBRARIES} 
	uuid 
	-lstdc++fs
	boost_thread
	pthread
	mysql
	mysqlclient
)
if (ENABLE_SSL)
	target_link_libraries(${project_name} ${OPENSSL_LIBRARIES} pthread -ldl)
endif()

if (ENABLE_CLIENT_SSL)
	target_link_libraries(${project_name} ${OPENSSL_LIBRARIES} pthread -ldl)
endif()

if (ENABLE_GZIP)
	target_link_libraries(${project_name} ${ZLIB_LIBRARIES})
endif()
install(TARGETS ${project_name} DESTINATION include)
