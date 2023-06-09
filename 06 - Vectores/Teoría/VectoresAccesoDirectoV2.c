#include <stdio.h>

//DEFINICIÓN DE CONSTANTE.
#define DIM 100

//PROTOTIPO DE FUNCIONES.
//void inicializar (float [],int);
int ingval(int,int);
float ingfloat(float);
int cargaVector (float [],int);
float maximo (float [],int);
void mostrar(float [],int,float);
void mostrarTodos(float[],int);

//PROGRAMA PRNCIPAL.
int main()
{
    float sueldos[DIM]={0}, maxsuel;
    int hay;

    //inicializar(sueldos,DIM);
    hay=cargaVector(sueldos,DIM);

    if(hay)//if(hay !=0)
      {
       maxsuel=maximo(sueldos,DIM);
       mostrar(sueldos,DIM,maxsuel);
       mostrarTodos(sueldos,DIM); //ordenados por legajo
      }
    else
       printf("\n\nNo se ingresaron empleados.");


    return 0;
}

//DEFINICIÓN DE FUNCIONES.
/////////////////////////////////////////////////////////////////////////////////////
void inicializar (float v[],int ce)
{
    int i;

    for(i=0;i<ce;i++)
        v[i]=0;
}
/////////////////////////////////////////////////////////////////////////////////////
int ingval(int d ,int h)
{
    int n;

    do{

         scanf("%d",&n);
    }while(n<d || n>h);

    return n;
}
/////////////////////////////////////////////////////////////////////////////////////
float ingfloat(float desde)
{
    float s;

    do{
        scanf("%f",&s);
      }while(s<desde);

    return s;
}
/////////////////////////////////////////////////////////////////////////////////////
int cargaVector (float v[],int ce)
{
  int leg,b;
  float suel;

  b=0;

  printf("Ingrese el numero de legajo (%d FIN-%d):",0,ce);
  leg=ingval(0,ce);

  while(leg>0)
       {
         if(v[leg-1]==0)
         {

            printf("Ingrese el sueldo:");
            suel = ingfloat(0);

            v[leg-1]=suel;//Acceso directo a vector.
         }
         else
            printf("Ese legajo ya fue ingresado \n");

         printf("Ingrese el numero de legajo (%d FIN-%d):",0,ce);
         leg=ingval(0,ce);

         b=1;
       }

  return b;
}
/////////////////////////////////////////////////////////////////////////////////////
float maximo (float v[],int ce)
{
    float mayor=v[0];
    int i;

    for(i=0;i<ce;i++)
        {if(v[i]>0 && v[i]>mayor)
           mayor=v[i];
        }

    return mayor;
}
/////////////////////////////////////////////////////////////////////////////////////
void mostrar(float v[],int ce,float x)
{
 int i;

 printf("\n\n LISTADO DE LOS LEGAJOS DE LOS EMPLEADOS CUYOS SUELDOS SON IGUALES A $%.2f\n",x);

 for(i=0;i<ce;i++)
    {
      if(v[i]==x)
         printf("%d\n",i+1);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
void mostrarTodos(float vs[],int ce)
{
    printf("\nListado de todos los empleados ordenados por legajo\n");
    int i;
    for(i=0;i<ce;i++)
    {
        if(vs[i]!=0)
            printf("%d  %.2f\n",i+1,vs[i]);
    }
}

