/*

 MATRICES ( ARRAYS BIDIMENSIONALES)
 ---------------------------------

 - Es una estructura ESTÁTICA en memoria principal que agrupa un conjunto de direcciones de memoria o elementos continuas cuyo contenido
   pertenece a un tipo de dato homogéneo.

 - Es un conjunto de variables de tipo homogéneo (todas tienen el mismo tipo de dato) agrupadas u organizadas de forma continua o contigua
   (por filas y columnas) en la memoria principal bajo un nombre.

 - Es una variable muy grande que tiene dos dimensiones: Filas y Columnas, contienen un conjunto de variables pequeñas ordenadas en forma
   consecutiva cuyo contenido pertenece a un tipo de dato homogéneo.

   Cada elemento se identifica por su índice de fila y posición de columna dentro de la matriz.


DECLARACIÓN - (SE REALIZA EN TIEMPO DE COMPILACIÓN)
------------

   -----------------------------------------------------------------------------------
  | <tipo de dato> Identificador o variable [cantidad de filas][cantidad de columnas];| ---> MATRIZ ESTÁTICA: Se debe conocer en tiempo de compilación.
   -----------------------------------------------------------------------------------

   - Tipo de dato : int,float, char;

   - Identificador: Nombre de la variable dimensionada, es una referencia o puntero.

   - cantidad de filas (tamaño máximo de filas): Es la cantidad de direcciones de memoria continuas que se van a reservar en la
                                                memoria principal para representar a los elementos de la matriz de forma
                                                horizontal. Es un int mayor que cero y menor un número int razonable para la memoria.

  - cantidad de columnas (tamaño máximo de columnas): Es la cantidad de direcciones de memoria continuas que se van a reservar en la
                                                     memoria principal para representar a los elementos de la matriz de forma
                                                     vertical. Es un int mayor que cero y menor un número int razonable para la memoria.

- Dimensión: Es el producto entre la cantidad de filas y la cantidad de           columnas.   

FORMATO LÓGICO
--------------

  int matriz [2][2];//Matriz de 2X2 (dimensión) = 4 elementos.


        COLUMNA 0 | COLUMNA1
       |--------------------|
FILA 0 |    int   |  int    | -->CELDA 0,1
       ---------------------|
FILA 1 |    int   |   int   | -->CELDA 1,1
       |--------------------|
            |          |
         CELDA 1,0    CELDA 1,1

- Celda: Es la representación de cada elemento de la matriz, se ubica por su índice de fila e índice de columna,
         el tipo de dato de su contenido es igual al tipo de dato de la matriz (tipo de dato homogéneo).

- índice de fila: Es una expresión de tipo int >=0 y < cantidad de filas.

- índice de columna: Es una expresión int >=0 y < cantidad de columnas.



FORMATO FÍSICO - MEMORIA PRINCIPAL
----------------------------------

   int matriz[2][2]; // Se reservan 4 direcciones de memoria continua, el índice de fila

   ------
  | AB07 |-------------------------------------------
   ------                                           |
   matriz        ZONA DE MEMORIA RESERVADA          |
                  ---------------------------       |
                  | FILA COLUMNA CONTENIDO  |       |
                  |                ----     |       |
                  | 0      0      |    |AB07 <------| DIRECCIÓN DE INICIO.
                  |                ----     |
                  | 0      1      |    |    |
                  |                ----     |
                  | 1      0      |    |    |
                  |                ----     |
                  | 1      1      |    |    |
                  |                ----     |
                  |-------------------------|

 El nombre o identificador de la mtriz es una referencia a la primera dirección de memoria  de la zona de memoria reservada para la misma.

 "EL IDENTIFICADOR DE LA MATRIZ ES UN PUNTERO A LA PRIMERA DIRECCIÓN DE LA ZONA  RESERVADA QUE ESTÁ EN LA POSICIÓN CERO".

 Puntero: Es una variable cuyo contenido es una dirección de memoria.


 ACCESO
 ------

     ---------------------------------------------------
     |Identificador [INDICE DE FILA][INDICE DE COLUMNA] |
     ---------------------------------------------------

     0<= INDICE DE FILA < CANTIDAD DE FILAS.

     0<= INDICE DE COLUMNA < CANTIDAD DE COLUMNAS.


     DIRECTO: Se coloca directamente la posición de fila y columna a través de una constante int, para acceder al contenido de una celda.

     INDIRECTO: Se coloca una operación o expresión como índice de fila y/o columna que genere como resultado un int.
                Puede ser una constante, una operación, una función, un vector que sean int.


 RECORRIDO
 ---------

 Se realiza a través de la estructura de iteración definida: Dos ciclos for anidados (uno para recorrer una  dimensión y otro para recorrer
 la otra dirección. También se puede recorrer con iteración condicionada: Dos ciclos while anidados o do-while.

*/

#include<stdio.h>
#include<stdlib.h>

//CONSTANTES.
#define CANT_FILAS 2
#define CANT_COLUMNAS 2

//PROGRAMA PRINCIPAL.
int main()
{
  int matriz[CANT_FILAS][CANT_COLUMNAS];//DECLARACIÓN.

  int f,c;


  //CARGAR LA MATRIZ.

  for (f=0;f<CANT_FILAS;f++)//CARGA POR FILAS.
  {
    for (c=0;c<CANT_COLUMNAS;c++)//INGRESAR EL VALOR DE CADA ELEMENTO DE LA MATRIZ POR COLUMNA.
         {
          printf("Ingrese el contenido de la fila %d y columna %d ",f,c);
          scanf("%d",&matriz[f][c]);
         }
  }

  //MOSTRAR MATRIZ.
  printf("\nMATRIZ\n");
   for (f=0;f<CANT_FILAS;f++)//RECORRIDO POR FILAS.
    {
      for (c=0;c<CANT_COLUMNAS;c++)//RECORRIDO POR COLUMNAS.

         printf("%d\t",matriz[f][c]);

      printf("\n");
  }


 system("pause");
 return 0;
}

