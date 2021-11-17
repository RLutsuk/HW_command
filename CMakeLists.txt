project(HW4)

option(USE_STATIC "Use static library" ON)

add_executable(sort main.c)

add_library(lib
	STATIC

	algorithms.c
	utils.c

	includes/algorithms.h
	includes/utils.h
)

target_link_libraries(sort lib)
target_link_libraries(sort m)