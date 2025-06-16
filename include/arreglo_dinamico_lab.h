#ifndef ARREGLO_DINAMICO_LAB_H
#define ARREGLO_DINAMICO_LAB_H

typedef struct {
    int* elementos;
    int capacidad;
    int tamano;
} ArregloDinamico;

ArregloDinamico* arreglo_crear();
void arreglo_agregar(ArregloDinamico* arreglo_lab, int valor);
void arreglo_imprimir(ArregloDinamico* arreglo_lab);
void arreglo_liberar(ArregloDinamico* arreglo_lab);

#endif
