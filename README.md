# Laboratorio 5 - Implementación de Arreglo Dinámico en C

## 👨‍💻 Autor  
**Jeancarlo Mejías**  
*IE-0117 Programación Bajo Plataformas Abiertas*  
*Universidad de Costa Rica*

## 📂 Estructura del proyecto
Para la aplicación correcta del código, y la memoria dinámica, se expone la estructura de datos desarrollada para su ejecución:
<pre>
Laboratorio_5
├── include
│   └── arreglo_dinamico_lab.h
├── Makefile
├── programa_lab5
├── README.md
└── src
    ├── arreglo_dinamico_lab.c
    └── main.c

</pre>


## 🔍 Verificación de memoria (Valgrind)
Además, para la verificación de memoria y posibles errores del programa, se hace uso del comando: "valgrind --leak-check=full --show-leak-kinds=all ./programa_lab5", lo cual expone como resultados: 
<pre>
Arreglo original: [34, 1034, 5]
Elemento en posición 1: 1034 (error: 0)
Arreglo después de eliminar: [34, 5]
==24345== 
==24345== HEAP SUMMARY:
==24345==     in use at exit: 0 bytes in 0 blocks
==24345==   total heap usage: 3 allocs, 3 frees, 1,080 bytes allocated
==24345== 
==24345== All heap blocks were freed -- no leaks are possible
==24345== 
==24345== For lists of detected and suppressed errors, rerun with: -s
==24345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

<pre>


