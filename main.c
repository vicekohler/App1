#include <stdio.h>
#include <stdlib.h>
#include "metrics.h"
#include "orders.h"

int main() {
    int size = 5;

    struct order orders[5] = {
        {2, "1/1/2015"},
        {3, "1/1/2015"},
        {1, "2/1/2015"},
        {4, "2/1/2015"},
        {2, "3/1/2015"}
    };

    char* resultado1 = apo(&size, orders);
    printf("%s\n", resultado1);
    free(resultado1);

    char* resultado2 = apd(&size, orders);
    printf("%s\n", resultado2);
    free(resultado2);

    return 0;
}
