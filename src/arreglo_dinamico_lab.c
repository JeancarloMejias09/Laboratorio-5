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
        if (!nuevos) return;
        arreglo_lab->elementos = nuevos;
    }
    arreglo_lab->elementos[arreglo_lab->tamano++] = valor;
}

void arreglo_eliminar(ArregloDinamico* arreglo_lab, int indice) {
    if (!arreglo_lab || indice < 0 || indice >= arreglo_lab->tamano) return;
    
    for (int i = indice; i < arreglo_lab->tamano - 1; i++) {
        arreglo_lab->elementos[i] = arreglo_lab->elementos[i + 1];
    }
    arreglo_lab->tamano--;
    
    if (arreglo_lab->tamano < arreglo_lab->capacidad / 4 && arreglo_lab->capacidad > 10) {
        arreglo_lab->capacidad /= 2;
        arreglo_lab->elementos = realloc(arreglo_lab->elementos, arreglo_lab->capacidad * sizeof(int));
    }
}

int arreglo_obtener(ArregloDinamico* arreglo_lab, int indice, int* error) {
    if (!arreglo_lab || indice < 0 || indice >= arreglo_lab->tamano) {
        if (error) *error = 1;
        return 0;
    }
    if (error) *error = 0;
    return arreglo_lab->elementos[indice];
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
