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

1. Se calcula la mediana de cada uno de los arreglos por separado, obteniendo la mediana de X y la mediana de Y

2. Se comparan ambos resultados, y se ejecuta lo siguiente: 

3. Si son iguales, regresar cualquiera de las dos. 

4. Si una es mayor que la otra, calcular la mediana de el subarreglo de 0 a la mediana mayor y de la mediana menor al final del arreglo. 

5. Se repite el mismo proceso por cada subarreglo hasta que el tamaño de los subarreglos se vuelve 2 o menor. 

6. Si ambos tienen un tamaño de dos se utiliza la siguiente fórmula: 

*median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])*

6. Si ambos tienen un tamaño de uni se utiliza la siguiente fórmula: 

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
[complejidad problema 4](./sources/problem_median/Complejidad_4.pdf)

### 2.1 Pasos a seguir para utilizar la aplicación

*[Incluya aquí una guía paso a paso para poder utilizar la aplicación, desde la clonación del repositorio, la compilación del código hasta la ejecución de los ejemplos para visualizar los resultados.]*

## 3. Referencias

### Problema 4: mediana

* [a link](https://www.geeksforgeeks.org/median-of-two-sorted-arrays/)
