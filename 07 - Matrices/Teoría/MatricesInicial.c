/*

 MATRICES ( ARRAYS BIDIMENSIONALES)
 ---------------------------------

 - Es una estructura EST�TICA en memoria principal que agrupa un conjunto de direcciones de memoria o elementos continuas cuyo contenido
   pertenece a un tipo de dato homog�neo.

 - Es un conjunto de variables de tipo homog�neo (todas tienen el mismo tipo de dato) agrupadas u organizadas de forma continua o contigua
   (por filas y columnas) en la memoria principal bajo un nombre.

 - Es una variable muy grande que tiene dos dimensiones: Filas y Columnas, contienen un conjunto de variables peque�as ordenadas en forma
   consecutiva cuyo contenido pertenece a un tipo de dato homog�neo.

   Cada elemento se identifica por su �ndice de fila y posici�n de columna dentro de la matriz.


DECLARACI�N - (SE REALIZA EN TIEMPO DE COMPILACI�N)
------------

   -----------------------------------------------------------------------------------
  | <tipo de dato> Identificador o variable [cantidad de filas][cantidad de columnas];| ---> MATRIZ EST�TICA: Se debe conocer en tiempo de compilaci�n.
   -----------------------------------------------------------------------------------

   - Tipo de dato : int,float, char;

   - Identificador: Nombre de la variable dimensionada, es una referencia o puntero.

   - cantidad de filas (tama�o m�ximo de filas): Es la cantidad de direcciones de memoria continuas que se van a reservar en la
                                                memoria principal para representar a los elementos de la matriz de forma
                                                horizontal. Es un int mayor que cero y menor un n�mero int razonable para la memoria.

  - cantidad de columnas (tama�o m�ximo de columnas): Es la cantidad de direcciones de memoria continuas que se van a reservar en la
                                                     memoria principal para representar a los elementos de la matriz de forma
                                                     vertical. Es un int mayor que cero y menor un n�mero int razonable para la memoria.

- Dimensi�n: Es el producto entre la cantidad de filas y la cantidad de           columnas.   

FORMATO L�GICO
--------------

  int matriz [2][2];//Matriz de 2X2 (dimensi�n) = 4 elementos.


        COLUMNA 0 | COLUMNA1
       |--------------------|
FILA 0 |    int   |  int    | -->CELDA 0,1
       ---------------------|
FILA 1 |    int   |   int   | -->CELDA 1,1
       |--------------------|
            |          |
         CELDA 1,0    CELDA 1,1

- Celda: Es la representaci�n de cada elemento de la matriz, se ubica por su �ndice de fila e �ndice de columna,
         el tipo de dato de su contenido es igual al tipo de dato de la matriz (tipo de dato homog�neo).

- �ndice de fila: Es una expresi�n de tipo int >=0 y < cantidad de filas.

- �ndice de columna: Es una expresi�n int >=0 y < cantidad de columnas.



FORMATO F�SICO - MEMORIA PRINCIPAL
----------------------------------

   int matriz[2][2]; // Se reservan 4 direcciones de memoria continua, el �ndice de fila

   ------
  | AB07 |-------------------------------------------
   ------                                           |
   matriz        ZONA DE MEMORIA RESERVADA          |
                  ---------------------------       |
                  | FILA COLUMNA CONTENIDO  |       |
                  |                ----     |       |
                  | 0      0      |    |AB07 <------| DIRECCI�N DE INICIO.
                  |                ----     |
                  | 0      1      |    |    |
                  |                ----     |
                  | 1      0      |    |    |
                  |                ----     |
                  | 1      1      |    |    |
                  |                ----     |
                  |-------------------------|

 El nombre o identificador de la mtriz es una referencia a la primera direcci�n de memoria  de la zona de memoria reservada para la misma.

 "EL IDENTIFICADOR DE LA MATRIZ ES UN PUNTERO A LA PRIMERA DIRECCI�N DE LA ZONA  RESERVADA QUE EST� EN LA POSICI�N CERO".

 Puntero: Es una variable cuyo contenido es una direcci�n de memoria.


 ACCESO
 ------

     ---------------------------------------------------
     |Identificador [INDICE DE FILA][INDICE DE COLUMNA] |
     ---------------------------------------------------

     0<= INDICE DE FILA < CANTIDAD DE FILAS.

     0<= INDICE DE COLUMNA < CANTIDAD DE COLUMNAS.


     DIRECTO: Se coloca directamente la posici�n de fila y columna a trav�s de una constante int, para acceder al contenido de una celda.

     INDIRECTO: Se coloca una operaci�n o expresi�n como �ndice de fila y/o columna que genere como resultado un int.
                Puede ser una constante, una operaci�n, una funci�n, un vector que sean int.


 RECORRIDO
 ---------

 Se realiza a trav�s de la estructura de iteraci�n definida: Dos ciclos for anidados (uno para recorrer una  dimensi�n y otro para recorrer
 la otra direcci�n. Tambi�n se puede recorrer con iteraci�n condicionada: Dos ciclos while anidados o do-while.

*/

#include<stdio.h>
#include<stdlib.h>

//CONSTANTES.
#define CANT_FILAS 2
#define CANT_COLUMNAS 2

//PROGRAMA PRINCIPAL.
int main()
{
  int matriz[CANT_FILAS][CANT_COLUMNAS];//DECLARACI�N.

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

