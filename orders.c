#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orders.h"

// Elimina espacios en blanco y caracteres de nueva línea al inicio y al final de una cadena.
char* trim(char* str) {
    char *end;
    while (*str == ' ') str++; // Avanza el puntero hasta el primer carácter no blanco.
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n' || *end == '\r')) end--; // Retrocede eliminando espacios o saltos de línea.
    *(end + 1) = '\0'; // Termina la cadena con un carácter nulo.
    return str;
}

// Divide una cadena de ingredientes separados por comas y los almacena en la estructura 'order'.
void split_ingredients(char *input, struct order *o) {
    char *token = strtok(input, ","); // Divide la cadena en tokens separados por comas.
    int i = 0;
    while (token && i < MAX_INGREDIENTS) {
        o->pizza_ingredients[i] = strdup(trim(token)); // Limpia y almacena cada ingrediente.
        token = strtok(NULL, ","); // Obtiene el siguiente token.
        i++;
    }
    o->ingredient_count = i; // Almacena el número total de ingredientes.
}

// Lee un archivo CSV y convierte cada línea en una estructura 'order'.
struct order* parse_csv(const char *filename, int *order_count) {
    FILE *fp = fopen(filename, "r"); // Abre el archivo en modo lectura.
    if (!fp) {
        printf("No se pudo abrir el archivo: %s\n", filename);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];

    // Saltar la primera línea (encabezado del archivo CSV).
    fgets(line, sizeof(line), fp);

    int capacity = 100; // Capacidad inicial del arreglo dinámico.
    struct order *orders = malloc(sizeof(struct order) * capacity); // Reserva memoria para las órdenes.
    int count = 0;

    while (fgets(line, sizeof(line), fp)) {
        // Ignorar líneas que contengan el encabezado accidentalmente.
        if (strstr(line, "pizza_id") != NULL) continue;

        // Duplicar la capacidad del arreglo si es necesario.
        if (count >= capacity) {
            capacity *= 2;
            orders = realloc(orders, sizeof(struct order) * capacity);
        }

        struct order o; // Estructura temporal para almacenar la orden.

        // Copia de la línea antes de modificarla.
        char backup[MAX_LINE_LENGTH];
        strncpy(backup, line, MAX_LINE_LENGTH);

        // Extraer el nombre de la pizza desde la última coma.
        char *last_comma = strrchr(backup, ',');
        if (last_comma) {
            strncpy(o.pizza_name, trim(last_comma + 1), MAX_FIELD_LENGTH);
        } else {
            strncpy(o.pizza_name, "Sin nombre", MAX_FIELD_LENGTH);
        }

        // Parsear los campos de la línea.
        char *token = strtok(line, ",");
        if (!token) continue;
        o.pizza_id = atoi(token); // ID de la pizza.

        token = strtok(NULL, ","); o.order_id = atoi(token); // ID de la orden.
        token = strtok(NULL, ","); strncpy(o.pizza_name_id, trim(token), MAX_FIELD_LENGTH); // Nombre de la pizza (ID).
        token = strtok(NULL, ","); o.quantity = atoi(token); // Cantidad.
        token = strtok(NULL, ","); strncpy(o.order_date, trim(token), MAX_FIELD_LENGTH); // Fecha de la orden.
        token = strtok(NULL, ","); strncpy(o.order_time, trim(token), MAX_FIELD_LENGTH); // Hora de la orden.
        token = strtok(NULL, ","); o.unit_price = atof(token); // Precio unitario.
        token = strtok(NULL, ","); o.total_price = atof(token); // Precio total.
        token = strtok(NULL, ","); strncpy(o.pizza_size, trim(token), MAX_FIELD_LENGTH); // Tamaño de la pizza.
        token = strtok(NULL, ","); strncpy(o.pizza_category, trim(token), MAX_FIELD_LENGTH); // Categoría de la pizza.
        token = strtok(NULL, "\"");
        if (token) split_ingredients(token, &o); // Procesar los ingredientes.

        orders[count++] = o; // Almacenar la orden en el arreglo.
    }

    fclose(fp); // Cerrar el archivo.
    *order_count = count; // Actualizar el número total de órdenes.

    printf("Lectura finalizada. Se leyeron %d ordenes.\n", count);
    return orders; // Devolver el arreglo de órdenes.
}

// Libera la memoria asignada dinámicamente para las órdenes y sus ingredientes.
void free_orders(struct order *orders, int order_count) {
    for (int i = 0; i < order_count; i++) {
        for (int j = 0; j < orders[i].ingredient_count; j++) {
            free(orders[i].pizza_ingredients[j]); // Liberar cada ingrediente.
        }
    }
    free(orders); // Liberar el arreglo de órdenes.