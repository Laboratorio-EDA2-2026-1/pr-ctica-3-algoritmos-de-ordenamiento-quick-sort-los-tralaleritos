#include <stdio.h>
#include <stdlib.h>

/*
  Ejercicio: Completar la implementación del algoritmo QuickSort.

  Recordatorio:
    - QuickSort es un algoritmo de ordenamiento basado en "divide y conquista".
    - Se elige un pivote y se reordenan los elementos de modo que:
         * a la izquierda del pivote: menores o iguales,
         * a la derecha del pivote: mayores.
    - Luego se aplica recursivamente en las dos mitades.
*/

/* Función para intercambiar dos elementos */
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
  Función de partición:
    - Debe elegir un pivote (por ejemplo, el último elemento).
    - Reordenar el arreglo colocando menores a la izquierda y mayores a la derecha.
    - Retornar el índice final del pivote.
*/
int particion(int arr[], int bajo, int alto) {
    //Aqui se elige el ultimo elemento del arrelo como pivote
    int pivote = arr [alto];
    //Nos indica la posicion del elemento mas pequeño.
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++){//Se recorre todos los elementos mas 

        if(arr[j] <= pivote ) {//Si el elemento en el que nos encontramos es igual o menor que el pivote
            i++;//Se incrementamos el indice del indice mas pequeño
            intercambiar(&arr[i], &arr[j]);

        }
    }
    intercambiar(&arr[i+1], &arr[alto]);//Se coloca el pivote en su posicion correcta

    return (i + 1);//Se retorna el indice en donde quedo el pivote
}

/*
  Función QuickSort:
    - Caso base: si bajo >= alto, terminar.
    - Paso recursivo: llamar a particion, y aplicar QuickSort en las dos mitades.
*/
void quicksort(int arr[], int bajo, int alto) {
    //Caso normal con mas de un elemento
    if (bajo < alto){
        int pi = particion(arr, bajo, alto);//Tomamos como indice de particion a pi
        
        //Se reordenan los elementos recursivamente antes de la particion
        quicksort(arr, bajo, pi - 1);
        //Se reordenan los elementos recursivamente despues de la particion
        quicksort(arr, pi + 1, alto);
    }
}

/* Función auxiliar para imprimir un arreglo */
void imprimir_arreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Error: memoria insuficiente.\n");
        return 1;
    }

    printf("Ingrese los %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Arreglo original:\n");
    imprimir_arreglo(arr, n);

    quicksort(arr, 0, n - 1);  // Llamada al algoritmo

    printf("Arreglo ordenado:\n");
    imprimir_arreglo(arr, n);

    free(arr);
    return 0;
}
