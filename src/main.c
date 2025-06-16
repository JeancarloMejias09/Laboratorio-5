#include <stdio.h>
#include "../include/arreglo_dinamico_lab.h"

int main() {
    // 1. Crear arreglo
    ArregloDinamico* arreglo_lab = arreglo_crear();
    
    // 2. Agregar elementos
    arreglo_agregar(arreglo_lab, 15);
    arreglo_agregar(arreglo_lab, 2);
    arreglo_agregar(arreglo_lab, 34);
    
    // 3. Imprimir
    printf("Contenido del arreglo:\n");
    arreglo_imprimir(arreglo_lab);
    
    // 4. Liberar memoria
    arreglo_liberar(arreglo_lab);
    
    return 0;
}
