#include <stdio.h>
#include <stdlib.h>
#include "../include/arreglo_dinamico_lab.h"

//Crear nuevo arreglo dinamico con capacidad inicial 10.

ArregloDinamico* arreglo_crear() {
    //Reservar memoria para la estructura del arreglo dinamico.
    ArregloDinamico* arreglo_lab = malloc(sizeof(ArregloDinamico));
    if (!arreglo_lab) return NULL;
    //Iniciar las propiedades del arreglo: capacidad y tamaño.
    arreglo_lab->capacidad = 10;
    arreglo_lab->tamano = 0;
    //Reservar la memoria para el buffer de elementos ingresados.
    arreglo_lab->elementos = malloc(arreglo_lab->capacidad * sizeof(int));
    if (!arreglo_lab->elementos) {
        free(arreglo_lab); //Liberar la estructura para prevenir errores.
        return NULL;
    }
    return arreglo_lab;
}

//Agregar un elemento al arreglo.

void arreglo_agregar(ArregloDinamico* arreglo_lab, int valor) {
    if (!arreglo_lab) return; //verificar con ! que sea un puntero valido.
    //Comprobar que el arreglo sea del size establecido, y si no duplicar su capacidad y reubicar capacidad con aritmetica de punteros.
    if (arreglo_lab->tamano == arreglo_lab->capacidad) {
        arreglo_lab->capacidad *= 2;
        int* nuevos = realloc(arreglo_lab->elementos, arreglo_lab->capacidad * sizeof(int));
        if (!nuevos) return;
        arreglo_lab->elementos = nuevos;
    }
    //Agregar un nuevo elemento y aumentar el tamaño.
    arreglo_lab->elementos[arreglo_lab->tamano++] = valor;
}
//Eliminar elemento del arreglo de elementos.
void arreglo_eliminar(ArregloDinamico* arreglo_lab, int indice) {
    //Verificar puntero valido e indice dentro de limites establecidos. 
    if (!arreglo_lab || indice < 0 || indice >= arreglo_lab->tamano) return;
    
    //Dezplazar los elementos para complementar el faltante del elemento eliminado. 
    for (int i = indice; i < arreglo_lab->tamano - 1; i++) {
        arreglo_lab->elementos[i] = arreglo_lab->elementos[i + 1];
    }
    arreglo_lab->tamano--; //Reducir el contador.
    
    //Reestablecer nueva capacidad.
    if (arreglo_lab->tamano < arreglo_lab->capacidad / 4 && arreglo_lab->capacidad > 10) {
        arreglo_lab->capacidad /= 2;
        arreglo_lab->elementos = realloc(arreglo_lab->elementos, arreglo_lab->capacidad * sizeof(int));
    }
}
//Obtener elemento.
int arreglo_obtener(ArregloDinamico* arreglo_lab, int indice, int* error) {
    if (!arreglo_lab || indice < 0 || indice >= arreglo_lab->tamano) {
        if (error) *error = 1; //Indicar si se presenta un error a la hora de arreglo de puntero.
        return 0;
    }
    if (error) *error = 0;
    return arreglo_lab->elementos[indice]; //Indicar exito de la ejecucion y presentar elemento
}
//Imprimir en la terminar los elementos del arreglo.
void arreglo_imprimir(ArregloDinamico* arreglo_lab) {
    if (!arreglo_lab) return;
    
    printf("[");
    for (int i = 0; i < arreglo_lab->tamano; i++) {
        printf("%d", arreglo_lab->elementos[i]);
        if (i < arreglo_lab->tamano - 1) printf(", ");
    }
    printf("]\n");
}
//Liberar la memoria del arreglo dinamico y de elemtentos
void arreglo_liberar(ArregloDinamico* arreglo_lab) {
    if (!arreglo_lab) return;
    free(arreglo_lab->elementos);
    free(arreglo_lab);
}
