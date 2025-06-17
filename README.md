# Laboratorio 5 - Implementación de Arreglo Dinámico en C

## 👨‍💻 Autor  
**Jeancarlo Mejías**  
*IE-0117 Programación Bajo Plataformas Abiertas*  
*Universidad de Costa Rica*

## 📂 Estructura del proyecto
Para la aplicación correcta del código, y la memoria dinámica, se expone la estructura de datos desarrollada para su ejecución:
<pre>
laboratorio_5/
│
├── include/
│   └── arreglo_dinamico_lab.h
│
├── src/
│   ├── arreglo_dinamico_lab.c
│   └── main.c
│
├── Makefile
└── README.md
</pre>


## 🔍 Verificación de memoria (Valgrind)
Además, para la verificación de memoria y posibles errores del programa, se hace uso del comando: "valgrind --leak-check=full --show-leak-kinds=all ./programa_lab5", lo cual expone como resultados: 
<pre>
Contenido del arreglo:
[15, 2, 34]
==18501== 
==18501== HEAP SUMMARY:
==18501==     in use at exit: 0 bytes in 0 blocks
==18501==   total heap usage: 3 allocs, 3 frees, 1,080 bytes allocated
==18501== 
==18501== All heap blocks were freed -- no leaks are possible
==18501== 
==18501== For lists of detected and suppressed errors, rerun with: -s
==18501== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
<pre>


