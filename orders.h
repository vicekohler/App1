#ifndef ORDERS_H
#define ORDERS_H

// Definición de constantes para límites de longitud de cadenas y cantidad de ingredientes
#define MAX_LINE_LENGTH 1024 // Longitud máxima de una línea en el archivo CSV
#define MAX_FIELD_LENGTH 256 // Longitud máxima de un campo individual
#define MAX_INGREDIENTS 10 // Número máximo de ingredientes por pizza

// Estructura que representa un pedido de pizza
struct order {
    int pizza_id; // Identificador único de la pizza
    int order_id; // Identificador único del pedido
    char pizza_name_id[MAX_FIELD_LENGTH]; // Nombre o identificador de la pizza
    int quantity; // Cantidad de pizzas pedidas
    char order_date[MAX_FIELD_LENGTH]; // Fecha del pedido (formato: YYYY-MM-DD)
    char order_time[MAX_FIELD_LENGTH]; // Hora del pedido (formato: HH:MM:SS)
    float unit_price; // Precio unitario de la pizza
    float total_price; // Precio total del pedido (unit_price * quantity)
    char pizza_size[MAX_FIELD_LENGTH]; // Tamaño de la pizza (por ejemplo: "Pequeña", "Mediana", "Grande")
    char pizza_category[MAX_FIELD_LENGTH]; // Categoría de la pizza (por ejemplo: "Vegetariana", "Carnes")
    char *pizza_ingredients[MAX_INGREDIENTS]; // Arreglo dinámico de strings para los ingredientes
    int ingredient_count; // Número de ingredientes en la pizza
    char pizza_name[MAX_FIELD_LENGTH]; // Nombre completo de la pizza
};

// Prototipo de función para analizar un archivo CSV y devolver un arreglo de pedidos
struct order* parse_csv(const char *filename, int *order_count);

// Prototipo de función para liberar la memoria asignada a los pedidos
void free_orders(struct order *orders, int order_count);

#endif