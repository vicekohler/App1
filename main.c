#include <stdio.h>  // Librería para operaciones de entrada/salida, como printf()
#include <stdlib.h> // Librería estándar para la gestión de memoria y funciones del sistema, como malloc()
#include <string.h> // Librería para manejo de cadenas de texto, como strcmp(), strtok(), etc.
#include "orders.h"  // Cabecera para manejar las órdenes de pizza (estructura `order` y funciones relacionadas)
#include "metrics.h" // Cabecera para calcular las métricas de las órdenes (como pms, pls, dms, etc.)

int main(int argc, char *argv[]) {
    // Verificar que el número de argumentos sea suficiente
    if (argc < 3) {
        // Si no se pasan suficientes argumentos, mostrar mensaje de uso y terminar el programa
        printf("Uso: %s archivo.csv metrica1 metrica2 ...\n", argv[0]);
        return 1;  // Retorna 1 para indicar un error en los argumentos
    }

    int num_orders = 0; // Variable para almacenar el número de órdenes leídas desde el archivo
    // Llamar a parse_csv para cargar las órdenes desde el archivo CSV
    struct order *orders = parse_csv(argv[1], &num_orders);

    // Verificar si las órdenes fueron cargadas correctamente
    if (!orders) {
        printf("No se pudo cargar el archivo CSV\n");
        return 1;  // Retorna 1 si no se pudo cargar el archivo
    }

    // Informar que el archivo se cargó con éxito
    printf("CSV cargado con exito. Total ordenes: %d\n", num_orders);

    // Procesar cada métrica pasada como argumento
    for (int i = 2; i < argc; i++) {  // Comienza desde el segundo argumento (el primero es el archivo CSV)
        // Llamar a execute_metric para obtener el resultado de la métrica
        char *result = execute_metric(argv[i], &num_orders, orders);
        
        if (result) {
            // Si el resultado es válido, imprimir el resultado
            printf("%s\n", result);
            free(result);  // Liberar la memoria asignada para el resultado
        } else {
            // Si la métrica no es reconocida, mostrar un mensaje de error
            printf("Métrica '%s' no reconocida.\n", argv[i]);
        }
    }

    // Liberar la memoria ocupada por las órdenes después de terminar
    free_orders(orders, num_orders);
    
    // Retornar 0 para indicar que el programa terminó con éxito
    return 0;
}