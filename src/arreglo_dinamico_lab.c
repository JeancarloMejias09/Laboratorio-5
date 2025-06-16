#include <stdio.h>
#include <stdlib.h>
#include "../include/arreglo_dinamico_lab.h"

ArregloDinamico* arreglo_crear() {
    ArregloDinamico* arreglo_lab = malloc(sizeof(ArregloDinamico));
    if (!arreglo_lab) return NULL;
    
    arreglo_lab->capacidad = 10;
    arreglo_lab->tamano = 0;
    arreglo_lab->elementos = malloc(arreglo_lab->capacidad * sizeof(int));
    if (!arreglo_lab->elementos) {
        free(arreglo_lab);
        return NULL;
    }
    return arreglo_lab;
}

void arreglo_agregar(ArregloDinamico* arreglo_lab, int valor) {
    if (!arreglo_lab) return;
    
    if (arreglo_lab->tamano == arreglo_lab->capacidad) {
        arreglo_lab->capacidad *= 2;
        int* nuevos = realloc(arreglo_lab->elementos, arreglo_lab->capacidad * sizeof(int));
        if (!nuevos) return; // Manejo básico de error
        arreglo_lab->elementos = nuevos;
    }
    arreglo_lab->elementos[arreglo_lab->tamano++] = valor;
}

void arreglo_imprimir(ArregloDinamico* arreglo_lab) {
    if (!arreglo_lab) return;
    
    printf("[");
    for (int i = 0; i < arreglo_lab->tamano; i++) {
        printf("%d", arreglo_lab->elementos[i]);
        if (i < arreglo_lab->tamano - 1) printf(", ");
    }
    printf("]\n");
}

void arreglo_liberar(ArregloDinamico* arreglo_lab) {
    if (!arreglo_lab) return;
    
    free(arreglo_lab->elementos);
    free(arreglo_lab);
}
