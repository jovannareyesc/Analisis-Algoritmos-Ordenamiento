# PROYECTO: ANÁLISIS DE ORDENAMIENTO

Dentro de las ciencias de la computacionales, el concepto de algoritmo es uno tal que por su definición se obtiene lo siguiente: 
I"Un procedimiento para resolver un problema matemático en un número finito de pasos que frecuentemente involucra operaciones recursivas."I
Lo que cabe recalcar dentro de esta definición es la referencia a un número finito de pasos, ya que de aquí se desprende el proyecto sobre el cual se está por explicar y el cual está adjunto en los archivos dentro de este repositorio. Al tener una limitación finita, uno podría llegar a preguntarse cuál es tal rango del que se habla. Algunos podrían dejarse llevar por la sobrebia y pensar en un problema t
an complicado el cual conlleve miles y miles de estos pasos, sin embargo, el lenguaje en el cual dichos pasos están expresados es el lenguaje de las matemáticas—lenguaje, en el que su belleza se esconde en su aspecto abstracto y reducido. Consecuentemente, los computólogos buscan continuamente una forma de que tales algoritmos, al igual que sus pasos, estén en el estado más sintetizado posible. La razón siendo que al tener un espacio y memoria reducida sobre el cual trabajar cuando se trata de computadoras, sucede el mismo caso cuando se trata de insertar algoritmos dentro de estos mismos espacios reducidos. Se necesita de una serie de pasos la cual sea lo más efectiva y eficiente posible para que tanto como la computadora y el usuario, puedan tener una experiencia optimizada y no haya cabida para errores o trabas durante el proceso. De aquí, surge lo que son diferentes tipos de algoritmos de ordenación de los cuales en este proyecto se abordan siete de ellos. Abajo, se adjunta una mejor descripción de su funcionamiento en orden en el cual se presentan en el código:

## Algoritmos de Ordenamiento en el proyecto
**1.Ordenamiento por Inserción**
La ordenación por inserción es un algoritmo de ordenación sencillo que funciona colocando progresivamente cada elemento de una lista desordenada en su posición correspondiente dentro de una sección ordenada de la lista. Este proceso es similar a organizar las cartas en las manos. Se dividen las cartas en dos categorías: las ordenadas y las que permanecen desordenadas. Posteriormente, se selecciona una carta de la categoría desordenada y se inserta en la posición correcta dentro de la categoría ordenada.


**2.Ordenamiento por Burbuja**
El ordenamiento de burbuja es el algoritmo de ordenamiento más básico, que funciona intercambiando continuamente elementos adyacentes cuando están mal ordenados. Debido a su complejidad temporal promedio y en el peor de los casos relativamente alta, este algoritmo no es ideal para gestionar grandes conjuntos de datos.

**3.Ordenamiento por Selección**
El ordenamiento por selección es un algoritmo de ordenamiento basado en comparaciones. Organiza un array identificando consistentemente el elemento más pequeño (o más grande) de la sección sin ordenar e intercambiándolo con el primer elemento de esa sección. Este procedimiento se repite hasta que el array esté completamente ordenado.

**4.Ordenamiento por Mezcla**
La ordenación por fusión es una técnica de ordenación que utiliza la estrategia de "divide y vencerás". Funciona dividiendo recursivamente el array de entrada en submatrices más pequeñas, ordenándolas y fusionándolas para formar un array completamente ordenado.

**5.Ordenamiento Rápido**
QuickSort es un algoritmo de ordenamiento que utiliza el método "dividir y vencer". Selecciona un elemento pivote y organiza la matriz particionándola en torno a este pivote, colocándolo finalmente en su lugar correspondiente dentro de la matriz ordenada.

**6.Ordenamiento por Montículos**
El ordenamiento por montículos (Heap Sort) es un algoritmo de ordenamiento basado en la Estructura de Datos del Montículo Binario (BIN) y se clasifica como un método basado en la comparación. Puede considerarse una mejora del ordenamiento por selección, donde el elemento máximo (o mínimo) se identifica y se intercambia con el último (o primer) elemento. Este procedimiento se repite para los elementos restantes. Al utilizar un montículo binario en el ordenamiento por montículos, podemos localizar y reposicionar eficientemente el elemento máximo en tiempo O(Log n), en lugar de O(n), logrando así una complejidad temporal total de O(n Log n).

**7.Ordenamiento Shell**
El ordenamiento por inserción (Shell Sort) es principalmente una adaptación del ordenamiento por inserción. En el ordenamiento por inserción tradicional, los elementos se desplazan una posición a la vez. Esto puede provocar numerosos movimientos cuando un elemento necesita reubicarse significativamente hacia adelante. El concepto del ordenamiento por inserción (Shell Sort) es facilitar el intercambio de elementos distantes. En el ordenamiento por inserción (Shell Sort), inicialmente se ordena el arreglo para que esté ordenado en i para un valor considerable de i. Se disminuye progresivamente el valor de i hasta que llega a 1. Un arreglo se considera ordenado en i si todas las sublistas formadas por cada elemento i-ésimo están ordenadas.

# Finalidad del proyecto
Ahora, con estos conceptos definidos, podemos entender de mejor forma lo que realmente se quiere lograr con este proyecto. 
El programa lo que busca ejecutar por medio de esa cantidad finita de pasos previamente mencionadas en las definiciones preliminares, es imprimir en un formato tipo .csv una hoja de cálculo la cual contiene una dimensión de cien renglones por mil columnas. Cabe destacar que en el último renglón [el cual por razones de no complicar la sintáxis del código no las incluiré] número mil uno, en la columna uno denomminada "Promedios", se encuentra lo que son los promedios de los tiempos de ordenamiento de los algoritmos mencionados. En el primer renglón que abarca hasta la última columna, se encuentra un título para cada celda con un número de tamaño el cual, literalmente, representa la longitud del arreglo con un paso de diez en diez hasta llegar a mil. Aritméticamente, obtenemos que mil entre diez, efectivamente son cien, lo cual representan las cien columnas. 
Ahora, más explícitamente, lo que el programa hace es aleatoriamente generar un arreglo con una cantidad _n_ de valores los cuales se generan dentro del código por medio de un área, por así llamarle, de tamaño _n_ espacios con un contador el cual va dando pasos—o incrementos—de diez en diez empezando desde diez por automático.

# Pasos para ejecutar el código
Abajo, se adjuntan los pasos a seguir para ejecutar el código exitosamente desde una terminal de preferencia:
1.
   ```sh
   git clone https://github.com/jovannareyesc/Analisis-Algoritmos-Ordenamiento
   ```
2. 
   ```sh
   cd Analisis-Algoritmos-Ordenamiento
   ```
3. 
   ```sh
   g++ main.cpp -o main -std=c++20
   ```
4. 
   ```sh
   ./main
   ```
# Conclusiones
Finalmente, al conocer dichos conceptos y correr el programa para postumamente observar el comportamiento, efectividad y el nivel de optimidad que tiene cada algoritmo de ordenamiento para exitosamente ordenar datos u arreglos desordenados podemos concluir que los algoritmos que mejor cumplen dichas características en orden de mejor a peor se despliegan de tal forma:
! [grafica_ordenamientos](grafica_ordenamientos.png)
