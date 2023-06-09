/*
  Ingresar n�meros hasta ingresar un cero. Como m�ximo 100.
  El cero indica el fin de datos.
  informar la cantidad de n�meros mayores al primero y al �ltimo elemento del vector.
*/

#include <stdio.h>

//DEFINICI�N DE CONSTANTE.
#define TAM 100

//PROTOTIPO DE FUNCIONES.
int ingresarDatos(int[],int);//Carga parcial del vector.
int cantMayores(int[],int,int);

//PROGRAMA PRINCIPAL.
int main()
{
  int cant,vecnros[TAM];

  cant=ingresarDatos(vecnros,TAM);

  if(cant >0)
      {
       printf("\nLa cantidad de valores mayores al primer elemento del vector es %d \n",cantMayores(vecnros,cant,vecnros[0]));
       printf("\nLa cantidad de valores mayores al ultimo elemento del vector es %d \n",cantMayores(vecnros,cant,vecnros[cant-1]));
      }
  else
      printf("\nNO SE INGRESARON N�MEROS !!! \n");


  return 0;
}
//DEFINICI�N DE FUNCIONES.
////////////////////////////////////////////////////////////////////////////////
int ingresarDatos(int v[],int ce)//Carga parcial del vector.
{
 int i=0,nro;

 printf("Ingrese un valor (0-fin):");
 scanf("%d",&nro);

 while(nro!=0 && i<ce)//i<ce -> Controlar el l�mite del vector.

      {
        v[i] = nro;//Carga segura del vector.

        i++;

        //if(i<ce)
        printf("Ingrese un valor (0-fin):");
        scanf("%d",&nro);
      }

 return i;
}

////////////////////////////////////////////////////////////////////////////////
int cantMayores(int v[],int t,int x)
{
    int i,c=0;

    for(i=0;i<t;i++)
        if(v[i]>x)
           c++;

    return c;
}
