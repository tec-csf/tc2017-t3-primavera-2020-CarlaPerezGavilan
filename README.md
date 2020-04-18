# Tarea 3. Técnicas de diseño de algoritmo

---

##### Integrantes:
1. Carla Pérez Gavilán Del Castillo, A01023033

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
        -problema4_median
        -problema7_train
    - examples			# Archivos de ejemplo que pueden utilizarse para 
    verificar que la solución funciona.
        -problema4_median
        -problema7_train
```

## 2. Solución

### Problema 4: encontrar la mediana dados dos vectores X y Y de tamaño N

### Planteamiento

Sean X e Y dos vectores de tamaño n, ordenados de forma no decreciente. Se necesita implementar un algoritmo para calcular la mediana de los 2n elementos que contienen X e Y. Recuerde que la mediana de un vector de k elementos es aquel elemento que ocupa la posición (k+1)÷2 una vez el vector está ordenado de forma creciente. Dicho de otra forma, la mediada es aquel elemento que, una vez ordenado el vector, deja la mitad de los elementos a cada uno de sus lados. Como en este caso k = 2n (y por tanto par) se busca el elemento en posición n de la unión ordenada de X e Y

#### Solución

**TÉCNICA: DIVIDE Y VENCERÁS**

1. Se calcula la mediana de cada uno de los arreglos por separado, obteniendo la mediana de X y la mediana de Y

2. Se comparan ambos resultados, y se ejecuta lo siguiente: 

3. Si son iguales, regresar cualquiera de las dos. 

4. Si una es mayor que la otra, calcular la mediana de el subarreglo de 0 a la mediana mayor y de la mediana menor al final del arreglo. 

5. Se repite el mismo proceso por cada subarreglo hasta que el tamaño de los subarreglos se vuelve 2 o menor. 

6. Si ambos tienen un tamaño de dos se utiliza la siguiente fórmula: 

*median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])*

7. Si ambos tienen un tamaño de uni se utiliza la siguiente fórmula: 

*median = (ar1[0] + ar2[0])/2*

8. Si uno tiene un tamaño de uno y otro uno tamaño de dos:

### Requerimientos

> IMPORTANTE: Ambos arreglos deben ser del mismo tamaño y estar ordenados de forma ascendente. 

	-g++ ./problem4_median/Median.cpp
	-./a.out

Ya existe un Makefile por lo tanto se puede simplemente correr:
    -make

### Archivos Estructura 

Puede encontrar el archivo de implementación y el archivo header bajo los nombres, en la carpeta de problema4_median: 
- *Medain.cpp*
- *Median.hpp*

### Complejidad 
O(n) = Log(n)

VER EL DESGLOSE DE COMPLEJIDAD: 
[complejidad problema 4](./sources/problem4_median/Complejidad_4.pdf)


### Problema 7: encontrar el camino más corto en una estación de trenes a través del algoritmo de Djkstra

### Planteamiento
Una compañía de ferrocarriles sirve n estaciones S1,...,Sn y trata de mejorar su servicio al cliente mediante terminales de información. Dadas una estación origen So y una estación destino Sd, un terminal debe ofrecer (inmediatamente) la información sobre el horario de los trenes que hacen la conexión entre So y Sd y que minimizan el tiempo de trayecto total.

#### Solución

**TÉCNICA: PROGRAMACIÓN DINÁMICA**

Durante todo el proces se guarda el camino de vertices en un arreglo, un arreglo de boleanos para registrar que vértices han sido visitados, y un arreglo con las distancias hacia cada uno de los nodos. 

1. Se selecciona el vértice de inicio y se le asigna un tiempo 0 mientras que a todos los demás se les inicializa con una distancia infinita. Todos los nodos se marcan como no visitados. 

2. Se buscan los nodos adyacentes del primer nodo, para cada nodo se ejecuta lo siguiente: 

3. Se viaja al nodo con menor distancia, y se suma dicha distancia a la distancia inicial. 

5. Se repite el mismo proceso (pasos 2 y 3) con el nodo visitado. 

6. Cuando el nodo visitado es igual al buscado, termina el algoritmo. 

7. Se imprime el camino, el tiempo total de viaje y los posibles horarios.


![AltText] (https://cdn.programiz.com/sites/tutorial2program/files/Dijkstra%27s-algorithm.jpg)

![Fuente](https://www.programiz.com/dsa/dijkstra-algorithm)

### Archivos Estructura 

- *Train.cpp* archivo con implementación del código
- *Train.hpp* archivo header de clase
- *adj_matrix.cpp* archivo donde se implementan métodos para la lectura de csv y preparación de matriz de adyacencia. 
-*test.csv* esta es una tabla de horarios con la siguiente estructrua, sin encabezados:


    | Horario Salida    | Horario Llegada  | Estación Salida  | Estación Llegada|
    | ------------------|:----------------:| ----------------:|----------------:|
    | 10:00             |11:00             | A                | B               |
### Requerimientos

> IMPORTANTE: 
    Si las estaciones no están conectadas entre sí no habrá solución 
    Los horarios en el csv deben representarse en horario de 24 horas, es decir, 13:00 y no 1:00 pm

	-g++ -std=c++17 source/problem7_train/Train.cpp
	-./a.out

Ya existe un Makefile por lo tanto se puede simplemente correr:
    -make

### Complejidad 
O(n) = nˆ2

VER EL DESGLOSE DE COMPLEJIDAD: 
[complejidad problema 4](./sources/problem7_train/Complejidad_7.pdf)


## 3. Referencias

### Problema 4: mediana

* [ejemplo de implementación de problema 4](https://www.geeksforgeeks.org/median-of-two-sorted-arrays/)

### Problema 4: estación de ferrocaril 

* [ejemplo de implementación de problema 7](https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/)



