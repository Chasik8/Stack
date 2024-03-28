cmake_minimum_required(VERSION 3.9)	 # Проверка версии CMake.
#set(CMAKE_CXX_COMPILER )										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.
project(class_lib CXX )

#[[set(SOURCE_EXE Double.cpp)]]		# Установка переменной со списком исходников для исполняемого файла

#set(SOURCE_LIB stack.hpp)			# Тоже самое, но для библиотеки
add_library(STACK INTERFACE stack.hpp)
#SET_SOURCE_FILES_PROPERTIES(test_mycode.foo PROPERTIES LANGUAGE CXX)
#ADD_EXECUTABLE(class_lib test_mycode.foo)
#[[add_executable(class_lib ${VerifyCXX})
set_target_properties(${TARGET} PROPERTIES LINKER_LANGUAGE CXX)]]
#[[add_executable(Double ${SOURCE_EXE})]]	# Создает исполняемый файл с именем main

#target_link_libraries(STACK)
