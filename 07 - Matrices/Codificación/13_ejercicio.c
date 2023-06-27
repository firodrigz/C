/* La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours a través de 15 agencias en
todo el país. Diariamente cada agencia envía la cantidad de ventas efectuadas de cada tour, indicando
agencia, tours y la cantidad de pasajes. Algunas agencias envían o en la cantidad cuando no existen pasajes
para un tour determinado, pero no en todas.

La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
- Código de agencia (de 1 a 15)
- Código de tour (1 a 10)
- Cantidad de pasajes (0 a 20)

Informar:
a. El total de pasajes vendidos por tour.
b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos.

FUNCIONES:
I. Para inicializar la matriz
II. Para mostrar el resultado del punto a. */

#include <stdio.h>
#include <stdlib.h>

void IniciarMat(int[][3],int,int);
void CargaTour(int[][3],int,int);
void Mostrar(int[][3],int,int);
void Maximo(int[][3],int[],int,int);
void mostrartour(int[],int);
int Validar(int,int);

int main()
{
    int tourAgencia[10][3]; //Sería tourAgencia[10][15] pero se reduce para ver los resultados rapido
    IniciarMat(tourAgencia,10,3);
    CargaTour(tourAgencia,10,3);
    system("pause");
    return 0;
}

void IniciarMat(int m[][3], int fila, int colu)
{
    int i, j;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<colu;j++)
        {
            m[i][j]=0;
        }
    }
}

void CargaTour(int m[][3], int fila, int colu)
{
    int i=0, tour, agencia, pasaje,vt[10]={0},vc[3];
    while(i<colu)
    {
        printf("Ingrese codigo de tour: ");
        tour=Validar(1,10);
        printf("Ingrese codigo de la agencia: ");
        agencia=Validar(1,3);
        printf("Ingrese cantidad de pasajes: ");
        pasaje=Validar(0,20);
        m[tour-1][agencia-1]+=pasaje;
        vt[tour-1]+=pasaje;
        i++;
    }
    Mostrar(m,i,colu);
    printf("PUNTO A\n");
    mostrartour(vt,3);
    Maximo(m,vc,fila,colu);
}

void Mostrar(int mat[][3], int ce, int colu)
{
    int i, j;
    printf("\tAgencia 1\tAgencia 2\tAgencia 3"); //Se colocaría hasta agencia 15
    {
        for(i=0;i<ce;i++)
        {
            printf("\nTour %d",i+1);
            for(j=0;j<colu;j++)
                printf("\t%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
void mostrartour(int v[],int cf)
{
  int i;
  for(i=0;i<cf;i++)
  {
     printf("Tour%d:%d\n",i+1,v[i]);
  }
  printf("\n");
}
void Maximo(int mat[][3],int v[], int fila, int colu)
{
    int i, j, max=0, maxAgencia;
    for(i=0;i<colu;i++)
    {
        v[i]=0;
        for(j=0;j<fila;j++)
        {
          v[i]+=mat[j][i];
        }
        if(i==0||v[i]>max)
            {
                max=v[i];
                maxAgencia=i+1;
            }
    }
    printf("\nLa agencia %d fue la que mas pasajes vendio, con %d\n",maxAgencia,max);
}

int Validar(int lim1, int lim2)
{
    int dato;
    do
    {
        scanf("%d",&dato);
        if(dato<lim1 || dato>lim2)
            printf("Error, vuelva a ingresar\n");
    }while(dato<lim1 || dato>lim2);
    return dato;
}
