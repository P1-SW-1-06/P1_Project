add_executable(main main.c import_handler.c import_handler.h user_input.c user_input.h dijkstra.c dijkstra.h)

add_library(user_input user_input.c)
add_library(dijkstra dijkstra.c)