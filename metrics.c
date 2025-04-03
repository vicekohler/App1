#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrics.h"
#include "orders.h"

char* apo(int *size, struct order *orders) {
    int total_pizzas = 0;
    int total_ordenes = 0;

    for (int i = 0; i < *size; i++) {
        total_pizzas += orders[i].quantity;
        total_ordenes++;
    }

    float promedio = (float)total_pizzas / total_ordenes;

    char* result = malloc(100);
    snprintf(result, 100, "Promedio de pizzas por orden: %.2f", promedio);

    return result;
}
