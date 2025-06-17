#include <stdio.h>
#include "../include/arreglo_dinamico_lab.h"

int main() {
    // 1. Crear arreglo dinamico :)
    ArregloDinamico* arreglo_lab = arreglo_crear();
    
    // 2. Agregar elementos que componen al arreglo :D
    arreglo_agregar(arreglo_lab, 34);
    arreglo_agregar(arreglo_lab, 1034);
    arreglo_agregar(arreglo_lab, 5);
    
    // 3. Imprimir
    printf("Arreglo original: ");
    arreglo_imprimir(arreglo_lab);
    
    // 4. Obtener elemento
    int error;
    int valor = arreglo_obtener(arreglo_lab, 1, &error);
    printf("Elemento en posición 1: %d (error: %d)\n", valor, error);
    
    // 5. Eliminar elemento
    arreglo_eliminar(arreglo_lab, 1);
    printf("Arreglo después de eliminar: ");
    arreglo_imprimir(arreglo_lab);
    
    // 6. Liberar memoria
    arreglo_liberar(arreglo_lab);
    
    return 0;
}
