# 📝 Progreso - Tarea 1 (Lenguaje y Paradigmas)

## ✅ Avances realizados

- Proyecto inicializado con estructura modular.
- Archivos creados:
  - `main.c`, `orders.c`, `orders.h`
  - `metrics.c`, `metrics.h`
  - `ventas.csv`, `Makefile`
- Parser `parse_csv()` implementado correctamente, capaz de leer archivos CSV con múltiples campos, incluyendo ingredientes.
- Uso correcto de memoria dinámica (`strdup`, `free`) para evitar fugas.
- Sistema de métricas conectado a través de la función `execute_metric()`.
- Métricas ya implementadas:
  - `pms`: Pizza más vendida
  - `pls`: Pizza menos vendida
- Terminal configurada con mensajes `[DEBUG]` para facilitar el rastreo de errores y flujo del programa.

## ⚠️ Pendientes

- Implementar las siguientes métricas:
  - `dms`: Día con más ventas en dinero
  - `dls`: Día con menos ventas en dinero
  - `apo`: Promedio de pizzas por orden
  - `apd`: Promedio de pizzas por día
  - `ims`: Ingrediente más vendido
  - `hp`: Total de pizzas vendidas por categoría
- Agregar punteros a funciones para las métricas.
- Modularizar funciones auxiliares (`utils.c`, `utils.h`).
- Escribir:
  - `README.md` con explicación general del proyecto.
  - `informe.md` con decisiones de diseño, análisis de métricas, uso de IA, reflexiones finales.
- Eliminar `printf` de debug cuando todo esté probado.

## 🧠 Notas

- El archivo `ventas.csv` debe estar en codificación **UTF-8 sin BOM** para evitar caracteres extraños en consola.
- Todos los commits hasta ahora han sido trabajados en la rama `tarea-1`.
- `make` y `.\app1.exe` están funcionando correctamente.

---

🕒 Última actualización: *[30 de marzo de 2025 – 23:xx]*  
👤 Autor: Vicente
