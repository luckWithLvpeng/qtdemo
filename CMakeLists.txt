#设置cmake版本号
cmake_minimum_required(VERSION 3.4.0)
 
#设置工程名称
project(cmakeUI)

#设置工程包含当前目录，非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 消除警告
CMAKE_POLICY(SET CMP0071 OLD)

# 给生成的mocs和qrc文件分组
set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "Generated Files")


#打开全局moc,设置自动生成moc文件，一定要设置
set(CMAKE_AUTOMOC ON)
#打开全局uic，非必须
set(CMAKE_AUTOUIC ON)
#打开全局rcc，非必须
set(CMAKE_AUTORCC ON)

#查找需要的Qt库文件
find_package(Qt5Widgets) 
find_package(Qt5Core)
find_package(Qt5Gui)

FILE(GLOB SRC_FILES "./*.cpp")
FILE(GLOB HEAD_FILES "./*.h")
FILE(GLOB UI_FILES "./*.ui")
#隐藏默认Headers 和 sources 的分组-可以关闭
source_group(" " FILES ${SRC_FILES} ${HEAD_FILES} ${UI_FILES})


#添加目录
LIST (APPEND DIR_LIST "about")
LIST (APPEND DIR_LIST "data")
#遍历目录中的文件
FOREACH(dir IN LISTS DIR_LIST)
	include_directories(${dir})
	FILE(GLOB SRC "${dir}/*.cpp")
	LIST(APPEND SRC_LIST ${SRC})
	FILE(GLOB HEAD "${dir}/*.h*" )
	LIST(APPEND HEAD_LIST ${HEAD})
	FILE(GLOB UI "${dir}/*.ui")
	LIST(APPEND UI_LIST ${UI})
	qt5_wrap_ui(WRAP ${UI})
	LIST(APPEND WRAP_LIST ${WRAP})
	source_group("${dir}" FILES ${SRC} ${HEAD} ${UI} )
ENDFOREACH()

#通过UI生成的头文件，一定要添加
qt5_wrap_ui(WRAP ${UI_FILES})
LIST(APPEND WRAP_LIST ${WRAP})


#加载资源文件
LIST(APPEND RCC_FILES testCmake.qrc)

#给生成的文件单独分组
source_group("Generated Files" FILES ${WRAP_LIST} ${RCC_LIST})

#创建工程文件
add_executable(${PROJECT_NAME} 
	${SRC_FILES} ${HEAD_FILES} 
	${RCC_FILES}
	${WRAP_LIST} ${HEAD_LIST} ${SRC_LIST} ${UI_LIST}
	)
#添加Qt5依赖项
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)