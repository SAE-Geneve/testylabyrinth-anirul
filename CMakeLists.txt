cmake_minimum_required(VERSION 3.14)

if(WIN32)
	add_compile_options("/std:c++latest")
endif(WIN32)
set(CMAKE_CXX_STANDARD 17)

project(ClassyLabyrinth)
find_package(GTest CONFIG REQUIRED)

add_library(LabyLib
	${PROJECT_SOURCE_DIR}/LabyLib/command.cpp
	${PROJECT_SOURCE_DIR}/LabyLib/command.h
	${PROJECT_SOURCE_DIR}/LabyLib/character.cpp
	${PROJECT_SOURCE_DIR}/LabyLib/character.h
	${PROJECT_SOURCE_DIR}/LabyLib/enemy.cpp
	${PROJECT_SOURCE_DIR}/LabyLib/enemy.h
	${PROJECT_SOURCE_DIR}/LabyLib/hero.cpp
	${PROJECT_SOURCE_DIR}/LabyLib/hero.h
	${PROJECT_SOURCE_DIR}/LabyLib/world.cpp
	${PROJECT_SOURCE_DIR}/LabyLib/world.h
)

add_executable(ClassyLabyrinthTest
	${PROJECT_SOURCE_DIR}/Test/command_test.cpp
	${PROJECT_SOURCE_DIR}/Test/command_test.h
	${PROJECT_SOURCE_DIR}/Test/main_test.cpp
	${PROJECT_SOURCE_DIR}/Test/character_test.cpp
	${PROJECT_SOURCE_DIR}/Test/character_test.h
	${PROJECT_SOURCE_DIR}/Test/enemy_test.cpp
	${PROJECT_SOURCE_DIR}/Test/enemy_test.h
	${PROJECT_SOURCE_DIR}/Test/hero_test.cpp
	${PROJECT_SOURCE_DIR}/Test/hero_test.h
	${PROJECT_SOURCE_DIR}/Test/world_test.cpp
	${PROJECT_SOURCE_DIR}/Test/world_test.h	
)

target_link_libraries(ClassyLabyrinthTest
PRIVATE
	LabyLib
	GTest::gtest
	GTest::gtest_main
)

add_executable(ClassyLabyrinth
	${PROJECT_SOURCE_DIR}/Labyrinth/main.cpp
)

target_link_libraries(ClassyLabyrinth
PRIVATE
	LabyLib
)
