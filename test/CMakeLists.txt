add_executable(user_input_test user_input_test.c)       #add test file to be able to run
target_link_libraries(user_input_test user_input)       #link to the libary "functions" to access functions to test
add_test(NAME user_input_test                           #add test and give it a name
        COMMAND user_input_test)

add_executable(dijkstra_test dijkstra_test.c)       #add test file to be able to run
target_link_libraries(dijkstra_test dijkstra)       #link to the libary "functions" to access functions to test
add_test(NAME dijkstra_test                           #add test and give it a name
        COMMAND dijkstra_test)