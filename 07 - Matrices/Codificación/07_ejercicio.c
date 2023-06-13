/*Una empresa desea registrar las ventas realizadas de cada uno de sus 20 productos a lo lardo del año. Los
productos están identificados por un código numérico correlativo del 1 al 20. Como primera información se
ingresa el precio unitario de cada uno de los productos. Luego por cada venta se ingresa:
- Código de producto
- Día de venta
- Mes de venta
- Cantidad de unidades vendidas

El ingreso de datos finaliza con un código de producto igual a 0. Informar:
a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
b. El producto con el cual se obtuvo la mayor recaudación.
c. El trimestre de menor recaudación del año.*/

#include <stdio.h>

#define CANT_PROD 3
#define MESES 12

float ingValFloat(int);
int ingresaYValida(int,int);
int ingValInt(int);
void cargaPrecios(float[],int);
int ingresoPedidos(int[][MESES],float[],float [],int,int);
void mostrar(int[][MESES],int,int);
int maximo(int[][MESES],float[],int,int);
int menor(float[],int);

int main()
{
    float vPrecios[CANT_PROD],vRectrim[4]={0};
    int mat[CANT_PROD][MESES]={{0}},codProdMax,ban;

    cargaPrecios(vPrecios,CANT_PROD);
    ban=ingresoPedidos(mat,vPrecios,vRectrim,CANT_PROD,MESES);
    if(ban==1)
      {
        mostrar(mat,CANT_PROD,MESES); //a
        codProdMax=maximo(mat,vPrecios,CANT_PROD,MESES);
        printf("El producto de mayor recaudacion en %d\n",codProdMax); //b
        printf("El trimestre de menor recaudacion es %d ",menor(vRectrim,4));//c
      }
    else
        printf("\n SIN VENTAS.");


    return 0;
}
/////////////////////////////////////////////////////////////////
void cargaPrecios(float vp[],int ce)
{
    int i;

    for(i=0;i<ce;i++)
    {
        printf("Ingrese el precio del producto de codigo %d\n",i+1);
        //scanf("%f",&vp[i]);
        vp[i]=ingValFloat(0);
    }
}
/////////////////////////////////////////////////////////////////
int ingresoPedidos(int m[][MESES],float vPrecio[],float vrtrim[],int cf,int cc)
{
    int cod,dia,mes,cant,ban=0;

    printf("Codigo de producto ");
    cod=ingresaYValida(0,cf);

    while(cod!=0)
    {
        printf("Dia de venta ");
        dia=ingresaYValida(1,31);
        printf("Mes de venta ");
        mes=ingresaYValida(1,cc);//ingresaYValida(1,MESES);
        printf("Cantidad de unidades vendidas ");
        cant=ingValInt(0);

        //Actualizar la matriz.
        m[cod-1][mes-1]+=cant;
        //Actualizar el vector de trimestres en paralelo a la act. de la matriz.
        vrtrim[(mes-1)/3]+= cant * vPrecio[cod-1];

        printf("Codigo de producto ");
        cod=ingresaYValida(0,cf);
        ban=1;
    }

    return ban;
}
/////////////////////////////////////////////////////////////////
void mostrar(int m[][MESES],int cf,int cc)
{
    int i,j;

    printf("MES       ");
    for(i=1;i<=cc;i++)
        printf("%4d",i);

    for(i=0;i<cf;i++)
    {
        printf("\nProducto %d",i+1);
        for(j=0;j<cc;j++)
            printf("%4d",m[i][j]);
    }

    printf("\n");
}
/////////////////////////////////////////////////////////////////
int maximo(int m[][MESES],float vp[],int cf,int cc)
{
    int i,j,sum,codMayor;
    float precioTot,mayor;

    for(i=0;i<cf;i++)
    {
        sum=0;
        for(j=0;j<cc;j++)
            sum+=m[i][j];

        precioTot = sum * vp[i];

        if(i==0 || precioTot>mayor)
        {
            mayor=precioTot;
            codMayor=i+1;
        }
    }

    return codMayor;
}
/////////////////////////////////////////////////////////////////
float ingValFloat(int desde)
{
    float d;

    do
    {
        scanf("%f",&d);
    }while(d<=desde);

    return d;
}
/////////////////////////////////////////////////////////////////
int ingValInt(int desde)
{
    int d;

    do
    {
        scanf("%d",&d);
    }while(d<=desde);

    return d;
}
/////////////////////////////////////////////////////////////////
int ingresaYValida(int desde,int hasta)
{
    //Bloque declarativo de variables locales.
    int nro;

    do{
        scanf("%d",&nro);

      }while(nro<desde || nro >hasta);

    return nro; //return Expresión;
}
/////////////////////////////////////////////////////////////////
int menor(float vRtrim[],int ce)
{
    int i,trimin,ban=0;
    float min;

    for(i=0;i<ce;i++)
        {if(vRtrim[i]>0)
          {if(ban==0 || vRtrim[i]<min)
             { min=vRtrim[i];
               trimin=i+1;
               ban=1;
             }
          }
        }

    return trimin;
}
