<<<<<<< HEAD
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "metrics.h"

// Función para calcular la pizza más vendida
char* pms(int *size, struct order *orders) {
    int max_count = 0; // Variable para almacenar la cantidad máxima de pizzas vendidas
    char *most_sold = NULL; // Variable para almacenar el nombre de la pizza más vendida

    // Iterar sobre las órdenes para contar las cantidades de cada pizza
    for (int i = 0; i < *size; i++) {
        int count = 0; // Contador para la cantidad de pizzas de un tipo específico
        for (int j = 0; j < *size; j++) {
            // Comparar los nombres de las pizzas para acumular la cantidad
            if (strcmp(orders[i].pizza_name, orders[j].pizza_name) == 0) {
                count += orders[j].quantity; // Sumar la cantidad de pizzas vendidas
            }
        }

        // Actualizar la pizza más vendida si se encuentra una con mayor cantidad
        if (count > max_count) {
            max_count = count; // Actualizar la cantidad máxima
            most_sold = orders[i].pizza_name; // Actualizar el nombre de la pizza más vendida
        }
    }

    // Crear el resultado con la información de la pizza más vendida
    char *result = malloc(256); // Reservar memoria para el resultado
    snprintf(result, 256, "Pizza mas vendida: %s (%d unidades)", most_sold, max_count); // Formatear el resultado
    return result; // Devolver el resultado
}

// Función para calcular la pizza menos vendida
char* pls(int *size, struct order *orders) {
    int min_count = INT_MAX; // Variable para almacenar la cantidad mínima de pizzas vendidas
    char *least_sold = NULL; // Variable para almacenar el nombre de la pizza menos vendida
    char least_sold_pizzas[1024] = ""; // Cadena para almacenar múltiples pizzas menos vendidas

    // Iterar sobre las órdenes para contar las cantidades de cada pizza
    for (int i = 0; i < *size; i++) {
        int count = 0; // Contador para la cantidad de pizzas de un tipo específico
        for (int j = 0; j < *size; j++) {
            // Comparar los nombres de las pizzas para acumular la cantidad
            if (strcmp(orders[i].pizza_name, orders[j].pizza_name) == 0) {
                count += orders[j].quantity; // Sumar la cantidad de pizzas vendidas
            }
        }

        // Actualizar la pizza menos vendida si se encuentra una con menor cantidad
        if (count < min_count && count > 0) {
            min_count = count; // Actualizar la cantidad mínima
            snprintf(least_sold_pizzas, sizeof(least_sold_pizzas), "%s", orders[i].pizza_name); // Actualizar el nombre
        } else if (count == min_count && count > 0) {
            strcat(least_sold_pizzas, ", "); // Agregar una coma para separar nombres
            strcat(least_sold_pizzas, orders[i].pizza_name); // Agregar el nombre de la pizza
        }
    }

    // Crear el resultado con la información de la pizza menos vendida
    char *result = malloc(256); // Reservar memoria para el resultado
    snprintf(result, 256, "Pizza menos vendida: %s (%d unidades)", least_sold_pizzas, min_count); // Formatear el resultado
    return result; // Devolver el resultado
}

// Función para calcular el día con más ventas en términos de ingresos
char* dms(int *size, struct order *orders) {
    float max_total = 0; // Variable para almacenar el ingreso máximo
    char best_day[MAX_FIELD_LENGTH] = ""; // Variable para almacenar el día con más ventas

    // Iterar sobre las órdenes para sumar los ingresos por día
    for (int i = 0; i < *size; i++) {
        float sum = 0; // Variable para acumular los ingresos de un día específico
        for (int j = 0; j < *size; j++) {
            // Comparar las fechas de las órdenes para acumular los ingresos
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                sum += orders[j].total_price; // Sumar el precio total de las órdenes
            }
        }

        // Actualizar el día con más ventas si se encuentra uno con mayor ingreso
        if (sum > max_total) {
            max_total = sum; // Actualizar el ingreso máximo
            strncpy(best_day, orders[i].order_date, MAX_FIELD_LENGTH); // Actualizar el día con más ventas
        }
    }

    // Crear el resultado con la información del día con más ventas
    char *result = malloc(128); // Reservar memoria para el resultado
    snprintf(result, 128, "Dia con mas ventas: %s ($%.2f)", best_day, max_total); // Formatear el resultado
    return result; // Devolver el resultado
}

// Función para ejecutar una métrica específica según su nombre
char* execute_metric(const char *name, int *size, struct order *orders) {
    // Verificar el nombre de la métrica y llamar a la función correspondiente
    if (strcmp(name, "pms") == 0) return pms(size, orders); // Pizza más vendida
    if (strcmp(name, "pls") == 0) return pls(size, orders); // Pizza menos vendida
    if (strcmp(name, "dms") == 0) return dms(size, orders); // Día con más ventas
    if (strcmp(name, "dls") == 0) return dls(size, orders); // Día con menos ventas
    if (strcmp(name, "apo") == 0) return apo(size, orders); // Promedio de pizzas por orden
    if (strcmp(name, "apd") == 0) return apd(size, orders); // Promedio de pizzas por día
    if (strcmp(name, "ims") == 0) return ims(size, orders); // Ingrediente más vendido
    if (strcmp(name, "hp") == 0) return hp(size, orders); // Ventas por categoría
    if (strcmp(name, "dmsp") == 0) return dmsp(size, orders); // Fecha con más pizzas vendidas
    if (strcmp(name, "dlsp") == 0) return dlsp(size, orders); // Fecha con menos pizzas vendidas

    // Si la métrica no está implementada, devolver un mensaje de error
    char *msg = malloc(100); // Reservar memoria para el mensaje de error
    snprintf(msg, 100, "Metrica '%s' no implementada aun.", name); // Formatear el mensaje de error
    return msg; // Devolver el mensaje de error
}

// Función para calcular el día con menos ventas en términos de ingresos
char* dls(int *size, struct order *orders) {
    float min_total = INT_MAX; // Variable para almacenar el ingreso mínimo
    char worst_day[MAX_FIELD_LENGTH] = ""; // Variable para almacenar el día con menos ventas

    // Iterar sobre las órdenes para sumar los ingresos por día
    for (int i = 0; i < *size; i++) {
        float sum = 0; // Variable para acumular los ingresos de un día específico
        for (int j = 0; j < *size; j++) {
            // Comparar las fechas de las órdenes para acumular los ingresos
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                sum += orders[j].total_price; // Sumar el precio total de las órdenes
            }
        }

        // Actualizar el día con menos ventas si se encuentra uno con menor ingreso
        if (sum < min_total && sum > 0) {
            min_total = sum; // Actualizar el ingreso mínimo
            strncpy(worst_day, orders[i].order_date, MAX_FIELD_LENGTH); // Actualizar el día con menos ventas
        }
    }

    // Crear el resultado con la información del día con menos ventas
    char *result = malloc(128); // Reservar memoria para el resultado
    snprintf(result, 128, "Dia con menos ventas: %s ($%.2f)", worst_day, min_total); // Formatear el resultado
    return result; // Devolver el resultado
}

// Función para calcular el promedio de pizzas por orden
char* apo(int *size, struct order *orders) {
    int total_pizzas = 0; // Variable para almacenar el total de pizzas
    int max_order_id = 0; // Variable para almacenar el ID máximo de orden

    // Iterar sobre las órdenes para contar las pizzas y encontrar el ID máximo
    for (int i = 0; i < *size; i++) {
        total_pizzas += orders[i].quantity; // Sumar la cantidad de pizzas

        if (orders[i].order_id > max_order_id) {
            max_order_id = orders[i].order_id; // Actualizar el ID máximo de orden
        }
    }

    // Calcular el promedio de pizzas por orden
    float promedio = (float)total_pizzas / max_order_id;

    // Crear el resultado con la información del promedio de pizzas por orden
    char *result = malloc(128); // Reservar memoria para el resultado
    snprintf(result, 128, "Promedio de pizzas por orden: %.2f", promedio); // Formatear el resultado
    return result; // Devolver el resultado
}

// Función para calcular el promedio de pizzas por día
char* apd(int *size, struct order *orders) {
    int total_pizzas = 0; // Variable para almacenar el total de pizzas
    int unique_days = 0; // Variable para almacenar la cantidad de días únicos

    // Asumimos que hay pocos días y usamos array auxiliar
    char **seen_dates = malloc(sizeof(char*) * (*size)); // Reservar memoria para las fechas vistas

    // Iterar sobre las órdenes para contar las pizzas y los días únicos
    for (int i = 0; i < *size; i++) {
        total_pizzas += orders[i].quantity; // Sumar la cantidad de pizzas

        int already_counted = 0; // Variable para verificar si el día ya fue contado
        for (int j = 0; j < unique_days; j++) {
            if (strcmp(orders[i].order_date, seen_dates[j]) == 0) {
                already_counted = 1; // Marcar el día como ya contado
=======
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
>>>>>>> 1ee7e62f33150b1313281c532a17fdae0bd66a9f
                break;
            }
        }

<<<<<<< HEAD
        if (!already_counted) {
            seen_dates[unique_days++] = orders[i].order_date; // Agregar el día a las fechas vistas
        }
    }

    // Calcular el promedio de pizzas por día
    float promedio = (float)total_pizzas / unique_days;

    // Crear el resultado con la información del promedio de pizzas por día
    char *result = malloc(128); // Reservar memoria para el resultado
    snprintf(result, 128, "Promedio de pizzas por dia: %.2f", promedio); // Formatear el resultado

    free(seen_dates); // Liberar la memoria reservada para las fechas vistas
    return result; // Devolver el resultado
}

// Función para calcular el ingrediente más vendido
char* ims(int *size, struct order *orders) {
    struct ingrediente_count {
        char nombre[MAX_FIELD_LENGTH]; // Nombre del ingrediente
        int count; // Cantidad de veces que aparece el ingrediente
    };

    struct ingrediente_count top_ingredientes[100]; // Array para almacenar los ingredientes más vendidos
    int total = 0; // Variable para almacenar el total de ingredientes

    // Iterar sobre las órdenes para contar los ingredientes
    for (int i = 0; i < *size; i++) {
        for (int j = 0; j < orders[i].ingredient_count; j++) {
            char *actual = orders[i].pizza_ingredients[j]; // Nombre del ingrediente actual
            int cantidad = orders[i].quantity; // Cantidad de pizzas con el ingrediente actual

            int found = 0; // Variable para verificar si el ingrediente ya fue contado
            for (int k = 0; k < total; k++) {
                if (strcmp(top_ingredientes[k].nombre, actual) == 0) {
                    top_ingredientes[k].count += cantidad; // Sumar la cantidad de pizzas con el ingrediente
                    found = 1; // Marcar el ingrediente como ya contado
                    break;
                }
            }

            if (!found) {
                strncpy(top_ingredientes[total].nombre, actual, MAX_FIELD_LENGTH); // Copiar el nombre del ingrediente
                top_ingredientes[total].count = cantidad; // Asignar la cantidad de pizzas con el ingrediente
                total++; // Incrementar el total de ingredientes
            }
        }
    }

    // Buscar el ingrediente más vendido
    int max = 0; // Variable para almacenar la cantidad máxima de apariciones
    char *mas_vendido = ""; // Variable para almacenar el nombre del ingrediente más vendido

    for (int i = 0; i < total; i++) {
        if (top_ingredientes[i].count > max) {
            max = top_ingredientes[i].count; // Actualizar la cantidad máxima de apariciones
            mas_vendido = top_ingredientes[i].nombre; // Actualizar el nombre del ingrediente más vendido
        }
    }

    // Crear el resultado con la información del ingrediente más vendido
    char *result = malloc(128); // Reservar memoria para el resultado
    snprintf(result, 128, "Ingrediente mas vendido: %s (%d apariciones)", mas_vendido, max); // Formatear el resultado
    return result; // Devolver el resultado
}

// Función para calcular las ventas por categoría de pizza
char* hp(int *size, struct order *orders) {
    struct categoria_count {
        char nombre[MAX_FIELD_LENGTH]; // Nombre de la categoría
        int total; // Total de ventas de la categoría
    };

    struct categoria_count categorias[20]; // Array para almacenar las categorías y sus ventas
    int cat_count = 0; // Variable para almacenar la cantidad de categorías

    // Iterar sobre las órdenes para contar las ventas por categoría
    for (int i = 0; i < *size; i++) {
        char *cat = orders[i].pizza_category; // Nombre de la categoría actual
        int cantidad = orders[i].quantity; // Cantidad de pizzas de la categoría actual

        int found = 0; // Variable para verificar si la categoría ya fue contada
        for (int j = 0; j < cat_count; j++) {
            if (strcmp(categorias[j].nombre, cat) == 0) {
                categorias[j].total += cantidad; // Sumar la cantidad de pizzas de la categoría
                found = 1; // Marcar la categoría como ya contada
                break;
            }
        }

        if (!found) {
            strncpy(categorias[cat_count].nombre, cat, MAX_FIELD_LENGTH); // Copiar el nombre de la categoría
            categorias[cat_count].total = cantidad; // Asignar la cantidad de pizzas de la categoría
            cat_count++; // Incrementar la cantidad de categorías
        }
    }

    // Armar el resultado con la información de las ventas por categoría
    char *result = malloc(512); // Reservar memoria para el resultado
    strcpy(result, "Ventas por categoria:\n"); // Inicializar el resultado

    for (int i = 0; i < cat_count; i++) {
        char linea[64]; // Variable para almacenar una línea del resultado
        snprintf(linea, sizeof(linea), "%s: %d\n", categorias[i].nombre, categorias[i].total); // Formatear la línea
        strcat(result, linea); // Agregar la línea al resultado
    }

    return result; // Devolver el resultado
}

// Función para calcular la fecha con más pizzas vendidas
char* dmsp(int *size, struct order *orders) {
    int max_pizzas = 0; // Variable para almacenar la cantidad máxima de pizzas vendidas
    char best_day[MAX_FIELD_LENGTH] = ""; // Variable para almacenar la fecha con más pizzas vendidas

    // Iterar sobre las órdenes para contar las pizzas vendidas por fecha
    for (int i = 0; i < *size; i++) {
        int count = 0; // Contador para la cantidad de pizzas vendidas en una fecha específica
        for (int j = 0; j < *size; j++) {
            // Comparar las fechas de las órdenes para acumular la cantidad de pizzas
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                count += orders[j].quantity; // Sumar la cantidad de pizzas vendidas
            }
        }

        // Actualizar la fecha con más pizzas vendidas si se encuentra una con mayor cantidad
        if (count > max_pizzas) {
            max_pizzas = count; // Actualizar la cantidad máxima de pizzas vendidas
            strncpy(best_day, orders[i].order_date, MAX_FIELD_LENGTH); // Actualizar la fecha con más pizzas vendidas
        }
    }

    // Crear el resultado con la información de la fecha con más pizzas vendidas
    char *result = malloc(128); // Reservar memoria para el resultado
    snprintf(result, 128, "Fecha con mas pizzas vendidas: %s (%d pizzas)", best_day, max_pizzas); // Formatear el resultado
    return result; // Devolver el resultado
}

// Función para calcular la fecha con menos pizzas vendidas
char* dlsp(int *size, struct order *orders) {
    int min_pizzas = INT_MAX; // Variable para almacenar la cantidad mínima de pizzas vendidas
    char worst_day[MAX_FIELD_LENGTH] = ""; // Variable para almacenar la fecha con menos pizzas vendidas

    // Iterar sobre las órdenes para contar las pizzas vendidas por fecha
    for (int i = 0; i < *size; i++) {
        int count = 0; // Contador para la cantidad de pizzas vendidas en una fecha específica
        for (int j = 0; j < *size; j++) {
            // Comparar las fechas de las órdenes para acumular la cantidad de pizzas
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                count += orders[j].quantity; // Sumar la cantidad de pizzas vendidas
            }
        }

        // Actualizar la fecha con menos pizzas vendidas si se encuentra una con menor cantidad
        if (count < min_pizzas && count > 0) {
            min_pizzas = count; // Actualizar la cantidad mínima de pizzas vendidas
            strncpy(worst_day, orders[i].order_date, MAX_FIELD_LENGTH); // Actualizar la fecha con menos pizzas vendidas
        }
    }

    // Crear el resultado con la información de la fecha con menos pizzas vendidas
    char *result = malloc(128); // Reservar memoria para el resultado
    snprintf(result, 128, "Fecha con menos pizzas vendidas: %s (%d pizzas)", worst_day, min_pizzas); // Formatear el resultado
    return result; // Devolver el resultado
=======
        if (!ya_registrada) {
            strcpy(fechas[fechas_count], orders[i].order_date);
            fechas_count++;
        }
    }

    float promedio = (float)total_pizzas / fechas_count;

    char* result = malloc(100);
    snprintf(result, 100, "Promedio de pizzas por día: %.2f", promedio);

    return result;
>>>>>>> 1ee7e62f33150b1313281c532a17fdae0bd66a9f
}
