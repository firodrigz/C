#include <stdio.h>

//DEFINICIÓN DE CONSTANTE.
#define DIM 100

//PROTOTIPO DE FUNCIONES.
int ingval(int,int,int);
float ingfloat(float);
int busqueda(int[],int,int);
int cargaVector (int[],float [],int);
float maximo (float [],int);
void mostrar(int[],float [],int,float);
void mostrarTodos(int[],float [],int);
//PROGRAMA PRNCIPAL.
int main()
{
    float sueldos[DIM]={0}, maxsuel;
    int legajos[DIM],cant;

    cant=cargaVector(legajos,sueldos,DIM);

    if(cant>0)
      {
       maxsuel=maximo(sueldos,cant);
       mostrar(legajos,sueldos,cant,maxsuel);
       mostrarTodos(legajos,sueldos,cant);
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
int ingval(int d ,int h,int x)
{
    int n;

    do{

         scanf("%d",&n);
    }while((n<d || n>h) && n!=x);

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
/*int busqueda(int v[],int ce,int b)
{
    int i=0,pos=-1;
    while(i<ce && pos==-1)
    {
        if(v[i]==b)
            pos=i;
        else
            i++;
    }
    return pos;
*/

int busqueda(int v[],int ce,int b)
{
    int i=0,pos;
    while(i<ce && v[i]!=b)
        i++;
    if(i==ce)
        //return -1;
        pos=-1;
    else
        //return i;
        pos=i;
    return pos;
}
/////////////////////////////////////////////////////////////////////////////////////
int cargaVector (int vl[],float vs[],int ce)
{
  int leg,i,pos;

  i=0;

  printf("Ingrese el numero de legajo de 4 cifras (FIN 0): ");
  leg=ingval(1000,9999,0);

  while(leg>0 && i<ce)
       {
         pos=busqueda(vl,i,leg);
         if(pos==-1)
         {
             vl[i]=leg;

            printf("Ingrese el sueldo:");
            vs[i] = ingfloat(0);

            i++;
         }
         else
            printf("Ese legajo ya fue ingresado \n");

         printf("Ingrese el numero de legajo (%d FIN-%d):",0,ce);
         leg=ingval(1000,9999,0);

       }

  return i;
}
/////////////////////////////////////////////////////////////////////////////////////
float maximo (float v[],int ce)
{
    float mayor=v[0];
    int i;

    for(i=0;i<ce;i++)
        {if(v[i]>mayor)
           mayor=v[i];
        }

    return mayor;
}
/////////////////////////////////////////////////////////////////////////////////////
void mostrar(int vl[],float vs[],int ce,float x)
{
 int i;

 printf("\n\n LISTADO DE LOS LEGAJOS DE LOS EMPLEADOS CUYOS SUELDOS SON IGUALES A $%.2f\n",x);

 for(i=0;i<ce;i++)
    {
      if(vs[i]==x)
         printf("%d\n",vl[i]);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
void mostrarTodos(int vl[],float vs[],int ce)
{
    printf("\nListado de todos los empleados ordenados por legajo\n");

}
