#include <stdio.h>
#include <stdlib.h>
#include "metrics.h"
#include "orders.h"

int main() {
    int size = 3;

    struct order orders[3] = {
        {2},
        {3},
        {1}
    };

    char* resultado = apo(&size, orders);
    printf("%s\n", resultado);

    free(resultado); // ¡Muy importante para evitar fugas de memoria!
    return 0;
}
