#include <assert.h>
#include "../src/dijkstra.h"

int main(){
    char* name = "alborg";
    char* city_name_array[20] = {"frederikshavn", "aalborg","thisted"};
    assert(index_city_names(name,city_name_array,3)==0);

}