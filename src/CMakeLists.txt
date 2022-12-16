add_executable(main main.c import_handler.c import_handler.h user_input.c user_input.h distance_calculation.c distance_calculation.h utility.c utility.h score_algorithm.c score_algorithm.h)


add_library(user_input user_input.c)
add_library(dijkstra distance_calculation.c)
add_library(import_handler import_handler.c)
add_library(score_algorithm score_algorithm.c)