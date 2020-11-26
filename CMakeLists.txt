#����cmake�汾��
cmake_minimum_required(VERSION 3.4.0)
 
#���ù�������
project(cmakeUI)

#���ù��̰�����ǰĿ¼���Ǳ���
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ��������
CMAKE_POLICY(SET CMP0071 OLD)

# �����ɵ�mocs��qrc�ļ�����
set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "Generated Files")


#��ȫ��moc,�����Զ�����moc�ļ���һ��Ҫ����
set(CMAKE_AUTOMOC ON)
#��ȫ��uic���Ǳ���
set(CMAKE_AUTOUIC ON)
#��ȫ��rcc���Ǳ���
set(CMAKE_AUTORCC ON)

#������Ҫ��Qt���ļ�
find_package(Qt5Widgets) 
find_package(Qt5Core)
find_package(Qt5Gui)

FILE(GLOB SRC_FILES "./*.cpp")
FILE(GLOB HEAD_FILES "./*.h")
FILE(GLOB UI_FILES "./*.ui")
#����Ĭ��Headers �� sources �ķ���-���Թر�
source_group(" " FILES ${SRC_FILES} ${HEAD_FILES} ${UI_FILES})


#����Ŀ¼
LIST (APPEND DIR_LIST "about")
LIST (APPEND DIR_LIST "data")
#����Ŀ¼�е��ļ�
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

#ͨ��UI���ɵ�ͷ�ļ���һ��Ҫ����
qt5_wrap_ui(WRAP ${UI_FILES})
LIST(APPEND WRAP_LIST ${WRAP})


#������Դ�ļ�
LIST(APPEND RCC_FILES testCmake.qrc)

#�����ɵ��ļ���������
source_group("Generated Files" FILES ${WRAP_LIST} ${RCC_LIST})

#���������ļ�
add_executable(${PROJECT_NAME} 
	${SRC_FILES} ${HEAD_FILES} 
	${RCC_FILES}
	${WRAP_LIST} ${HEAD_LIST} ${SRC_LIST} ${UI_LIST}
	)
#����Qt5������
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)