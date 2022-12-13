#include <assert.h>
#include "../src/score_algorithm.h"

int main(){

    int array_prices[5] = {1,2,3,4,5,};

    double price1 = max_housing_price(array_prices,5);

    assert(price1 == 22.75000);

    int array_prices2[5] = {6,7,8,9,10,};

    double price2 = max_housing_price(array_prices2,5);

    assert(price2 == 45.500000);



}