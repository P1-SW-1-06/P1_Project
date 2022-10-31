#include <stdio.h>



int main() {
    struct person{
        int Time;
        int Env;
        int Cost;
        char* navn;
    };

    int personer;
    printf("Enter the amount of people you want to optimize for!\n");
    scanf("%d",&personer);

    struct person Parray[personer];

    int a = Parray[1].Env = 1;
    int b = Parray[1].Time= 2;
    int c = Parray[1].Cost = 1;
    char* d = Parray[0].navn = "mogens";

    printf("%d %d %d %s", a, b, c, d);
}
