#ifndef METRICS_H
#define METRICS_H

#include "orders.h"

<<<<<<< HEAD
// Ejecuta una métrica específica según el nombre proporcionado.
char* execute_metric(const char *name, int *size, struct order *orders);

// Calcula una métrica relacionada con "pms" (por ejemplo, promedio de algo).
char* pms(int *size, struct order *orders);

// Calcula una métrica relacionada con "pls" (por ejemplo, longitud o suma).
char* pls(int *size, struct order *orders);

// Calcula una métrica relacionada con "pps" (por ejemplo, porcentaje o proporción).
char* pps(int *size, struct order *orders);

// Calcula una variación más específica de "pps".
char* ppss(int *size, struct order *orders);

// Calcula una métrica de diferencia o desviación relacionada con "dms".
char* dms(int *size, struct order *orders);

// Calcula una métrica similar a "dms", pero relacionada con "dls".
char* dls(int *size, struct order *orders);

// Calcula el promedio por orden.
char* apo(int *size, struct order *orders);

// Calcula el promedio por día.
char* apd(int *size, struct order *orders);

// Calcula una métrica instantánea o inicial.
char* ims(int *size, struct order *orders);

// Calcula algo relacionado con "hp" (por ejemplo, un valor máximo o punto alto).
char* hp(int *size, struct order *orders);

// Calcula una métrica derivada de "dms" con un enfoque más específico.
char* dmsp(int *size, struct order *orders);

// Calcula una métrica derivada de "dls" con un enfoque más específico.
char* dlsp(int *size, struct order *orders);

#endif
=======
char* apo(int *size, struct order *orders);
char* apd(int *size, struct order *orders);

#endif

>>>>>>> 1ee7e62f33150b1313281c532a17fdae0bd66a9f
