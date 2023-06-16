/*PROGRAMA PARA DECLARAR E INICIALIZAR MATRICES*/
#include<stdio.h>
#include<stdlib.h>

//CONSTANTES.
#define FILA 3
#define COL 3
#define CHAR 'c'
#define INT 'i'
#define FLOAT 'f'


//PROTOTIPO DE FUNCIONES.
//Nota = El valor de la cantidad de columnas se debe indicar SIEMPRE.
void MostrarEncabezadoDeColumna(int);
void MostrarMatrizInt(int [][COL],int,int);
void MostrarMatrizFloat(float [][COL],int,int);
void MostrarMatrizChar(char [][COL],int,int);
void Titulo(int,char);

//PROGRAMA PRINCIPAL.
int main()
{
    int MatrizInt1[FILA][COL] = {{1,2,3},{4,5,6},{7,8,9}}; /*
                                                              Declara e inicializa la matriz con los siguientes datos.

                                                                    FILA\COL  0   1   2
                                                                      0       1   2   3
                                                                      1       4   5   6
                                                                      2       7   8   9

                                                              Cada par de llaves indica el valor de toda una fila.

                                                              NOTA = Lo mismo ocurre con las siguientes declaraciones e inicializaciones:

                                                              int matriz[][COL] = {1,2,3,4,5,6,7,8,9};//Asigna el valor de la cant. de filas automáticamente en 3.

                                                              int matriz[FILA][COL] = {1,2,3,4,5,6,7,8,9};

                                                          */

  int MatrizInt2[FILA][COL]={{0}}; /*
                                    Declara e inicializa la matriz con el valor cero en todas las celdas.

                                                FILA\COL  0   1   2
                                                  0       0   0   0
                                                  1       0   0   0
                                                  2       0   0   0

                                    Nota : Sòlo es válido para el valor cero, si se coloca otro valor entre llaves
                                           inicializa con ese valor la primera fila y la primera columna de la matriz
                                           ,las restantes celdas las completa con cero.

                                   Lo mismo ocurre con las siguientes declaraciones e inicializaciones:

                                   int MatrizInt2[FILa][COL]={0};

                                   */

  int MatrizInt3[FILA][COL]={1,2,3}; /*
                                        Declara e inicializa la matriz con los valores 1,2,3 en la primera fila.
                                        El resto de las celdas las completa con ceros.

                                                FILA\COL  0   1   2
                                                  0       1   2   3
                                                  1       0   0   0
                                                  2       0   0   0

                                       Lo mismo ocurre con la declaración e inicialización :

                                       int MatrizInt3[][COL]={1,2,3};

                                       int MatrizInt3[][COL]={{1,2,3}};

                                    */
  float MatrizFloat1[FILA][COL] = {{1.00,2.50,3.5},{211.00,20.45,9.5},{78.6,26.5,30.5}};
                                  /*
                                        Declara e inicializa la matriz con los valores

                                                FILA\COL   0      1     2
                                                  0       1.00   2.50  3.5
                                                  1       211.00 20.45 9.5
                                                  2       78.6   26.5  30.5

                                       Lo mismo ocurre con la declaración e inicialización :

                                       float MatrizFloat1[][COL] = {{1.00,2.50,3.5},{211.00,20.45,9.5},{78.6,26.5,30.5}};

                                       float MatrizFloat1[FILA][COL] = {1.00,2.50,3.5,211.00,20.45,9.5,78.6,26.5,30.5};

                                    */
  float MatrizFloat2[][COL] = {{125.80,250.98,-3.5}};
                                  /*
                                        Declara e inicializa la matriz con los valores 125.80,250.98,-3.5 en la primera
                                        fila y el resto de las celdas las completa con ceros.

                                                FILA\COL   0         1     2
                                                  0       125.80  250.98  -3.5
                                                  1        0         0     0
                                                  2        0         0     0

                                       Lo mismo ocurre con la declaración e inicialización :

                                       float MatrizFloat2[][COL] = {125.80,250.98,-3.5};

                                       float MatrizFloat2[FILA][COL] = {{125.80,250.98,-3.5}};

                                       float MatrizFloat2[FILA][COL] = {125.80,250.98,-3.5};

                                    */
  float MatrizFloat3[FILA][COL]={{0}}; /*
                                        Declara e inicializa la matriz con los valores 1,2,3 en la primera fila.
                                        El resto de las celdas las completa con ceros.

                                                FILA\COL  0   1   2
                                                  0       1   2   3
                                                  1       0   0   0
                                                  2       0   0   0

                                       Lo mismo ocurre con la declaración e inicialización :

                                       float MatrizInt3[FILA][COL]={0};

                                       */

  char MatrizChar1[][COL]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
                          /*Declara e inicializa la matriz con los valores grupados por filas
                            que se indicaron entre llaves.

                            FILA\COL  0   1   2
                              0       a   b   c
                              1       d   e   f
                              2       g   h   i

                             Lo mismo ocurre con la declaración e inicialización :

                             char MatrizChar1[][COL]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
                             char MatrizChar1[][COL]={'a','b','c','d','e','f','g','h','i'};
                             char MatrizChar1[FILA][COL]={'a','b','c','d','e','f','g','h','i'};

                          */

  //MOSTRAR RESULTADOS.
  Titulo(1,INT);
  MostrarMatrizInt(MatrizInt1,FILA,COL);
  Titulo(2,INT);
  MostrarMatrizInt(MatrizInt2,FILA,COL);
  Titulo(3,INT);
  MostrarMatrizInt(MatrizInt3,FILA,COL);
  Titulo(1,FLOAT);
  MostrarMatrizFloat(MatrizFloat1,FILA,COL);
  Titulo(2,FLOAT);
  MostrarMatrizFloat(MatrizFloat2,FILA,COL);
  Titulo(3,FLOAT);
  MostrarMatrizFloat(MatrizFloat3,FILA,COL);
  Titulo(1,CHAR);
  MostrarMatrizChar(MatrizChar1,FILA,COL);

  system("pause");
  return 0;
}
//DESARROLLO DE FUNCIONES.
///////////////////////////////////////////////////////////////////////////
void MostrarMatrizInt(int mat[][COL],int cf,int cc)
{
    int f,c;

    //MOSTRAR ENCABEZADO DE COLUMNAS.
    MostrarEncabezadoDeColumna(cc);
    printf("\n");

    for(f=0;f<cf;f++)
       {
         printf("fila%2d ",f); //MOSTRAR FILAS.
         for(c=0;c<cc;c++)
             {
               printf("%6d",mat[f][c]); //MOSTRAR CELDAS.
             }
        printf("\n");
       }
}
///////////////////////////////////////////////////////////////////////////
void Titulo(int nro ,char tipo)
{
    printf("\n     ---MATRIZ");
    switch(tipo)
    {
        case CHAR: printf("Char");
                  break;
        case INT: printf("Int");
                  break;
        case FLOAT: printf("Float");
                  break;
    }
    printf("%d---\n",nro);
}
//////////////////////////////////////////////////////////////////////////
void MostrarMatrizFloat(float mat[][COL],int cf,int cc)
{
    int f,c;

    //MOSTRAR ENCABEZADO DE COLUMNAS.
    MostrarEncabezadoDeColumna(cc);
    printf("\n");

    for(f=0;f<cf;f++)
       {
         printf("fila%2d ",f); //MOSTRAR FILAS.
         for(c=0;c<cc;c++)
             printf("%7.2f",mat[f][c]);
        printf("\n");
       }
}
//////////////////////////////////////////////////////////////////////////
void MostrarMatrizChar(char mat[][COL],int cf,int cc)
{
    int f,c;

    //MOSTRAR ENCABEZADO DE COLUMNAS.
    MostrarEncabezadoDeColumna(cc);
    printf("\n");

    for(f=0;f<cf;f++)
       {
         printf("fila%2d ",f); //MOSTRAR FILAS.
         for(c=0;c<cc;c++)
             printf("%6c",mat[f][c]);
        printf("\n");
       }
}
//////////////////////////////////////////////////////////////////////////
void MostrarEncabezadoDeColumna(int columna)
{
 int c;

 printf("Columna");
 for(c=0;c<columna;c++)
      printf("%6d",c);

}
