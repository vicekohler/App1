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

char* apd(int *size, struct order *orders) {
    int total_pizzas = 0;
    int total_dias = 0;

    char fechas[100][20];
    int fechas_count = 0;

    for (int i = 0; i < *size; i++) {
        total_pizzas += orders[i].quantity;

        int ya_registrada = 0;
        for (int j = 0; j < fechas_count; j++) {
            if (strcmp(fechas[j], orders[i].order_date) == 0) {
                ya_registrada = 1;
                break;
            }
        }

        if (!ya_registrada) {
            strcpy(fechas[fechas_count], orders[i].order_date);
            fechas_count++;
        }
    }

    float promedio = (float)total_pizzas / fechas_count;

    char* result = malloc(100);
    snprintf(result, 100, "Promedio de pizzas por día: %.2f", promedio);

    return result;
}
