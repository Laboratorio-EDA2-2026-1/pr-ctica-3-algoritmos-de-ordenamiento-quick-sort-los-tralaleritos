#Ejericio 2: Promedio de los datos como pivote

def quick_sort_media(arr):
    if len(arr) <= 1:
        return arr
    
    pivote = sum(arr)/len(arr)
    
    menores = [x for x in arr if x < pivote]
    iguales = [x for x in arr if x == pivote]
    mayores = [x for x in arr if x > pivote]

    return quick_sort_media(menores) + iguales + quick_sort_media(mayores)

lista = [2.1,3.6,1.4,2.7,2.9,7.8,5,6.9,4]

print(quick_sort_media(lista))

