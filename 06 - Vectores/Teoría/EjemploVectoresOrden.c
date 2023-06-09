/***************************************************************************************************************************
//  De un curso de ELECTRONICA , de  MAXIMO 60 alumnos se tiene el DNI y las notas de dos parciales de cada alumno.
//  Fin de carga DNI igual a cero.
//  Guardar los datos en los  vectores. DNI y NOTAS (validar)
//  Determinar e imprimir el promedio de las notas y el DNI de cada alumno, ordenado por NOTA PROMEDIO EN FORMA Descendente.
***************************************************************************************************************************/

#include <stdio.h>
#include <conio.h>
#define TAM 60               // N es constante , aqui se indica la cantidad de alumnos
int LeeControlRango(int,int);
int BUSQUEDA (int[], int, int);
int CARGA(int[], int[], int[], int);
void PROMEDIO(float [], int[], int[],int);
void ORDEN_PROM(float[],int[],int);
void INFORME(int[],float[],int);

main()
{ int DNI[TAM],NOTA1[TAM],NOTA2[TAM], CANT;
  float PROM[TAM];
  printf("\n INGRESO DE DATOS\n");
  CANT = CARGA(DNI,NOTA1,NOTA2,TAM);
  PROMEDIO(PROM, NOTA1,NOTA2,CANT);
  printf("\n\t INFORME ANTES DEL ORDEN \n");
  INFORME(DNI,PROM,CANT);
  ORDEN_PROM(PROM,DNI,CANT);
  printf("\n\t INFORME ORDENADO DESCENDENTE POR PROMEDIOS \n");
  INFORME(DNI,PROM,CANT);
  getch();
}
/*************************************************************************************************/
int LeeControlRango(int LI, int LS)
{
 int DATO, BAND=0;
 do{
 	if (BAND==0)
 	   BAND=1;
 	else
	   printf("\nINGRESE NUEVAMENTE  ");
	scanf("%d",&DATO);
 }while(DATO <LI || DATO >LS);
 return (DATO);
}
/*************************************************************************************************/
int BUSQUEDA(int V[], int DATO, int N)
{
 int I,POSI;
 I=0;
 POSI=-1;
 while((POSI == -1) && (I<N))
   if (V[I]==DATO)
      POSI = I;
   else
      I++;
 return (POSI);
}
/*************************************************************************************************/
int CARGA(int DOC[],int N1[],int N2[],int N)
{ int DOCU, I=0, POS;
  printf ("\n INGRESAR el DNI : ");
  scanf("%d",&DOCU);
  while(DOCU !=0)
  {
    if(I== 0)
      DOC[I] = DOCU;
    else
    {

      do{
         printf ("\n INGRESAR el DNI : ");
         scanf("%d",&DOCU);

  	     POS = BUSQUEDA(DOC,DOCU  , I);
  	     if(POS !=-1)
            printf("\n ERROR, EL NRO YA EXISTE ");

        }while(POS != -1);
    }
    if(DOCU != 0)
     {
        DOC[I]= DOCU;

        printf ("\n Ingresar la PRIMER NOTA: ");
        N1[I] = LeeControlRango(0, 10);
        printf ("\n Ingresar la SEGUNDA NOTA: ");
        N2[I] = LeeControlRango(0, 10);
        I++;
     }
  }
 return (I);
}

///////////////////////////////////////////////////////////////////

void PROMEDIO(float PROM [], int N1[],int N2[],int NN)
{ int I;
  for (I=0;I<NN;I++)
    PROM[I]=(float)(N1[I]+N2[I])/2;
}

///////////////////////////////////////////////////////////////////

void ORDEN_PROM(float PR[],int DOC[],int NN)
{ int I,DESORDENADO,COTA, aux1;
  float aux;
  COTA =NN;
  DESORDENADO=1;
  while(DESORDENADO!=0)
   { DESORDENADO=0;
     for(I=1;I<COTA;I++)
       { if(PR[I-1]<PR[I])
          { aux=PR[I-1];
            PR[I-1]=PR[I];
            PR[I]=aux;

            aux1=DOC[I-1];
            DOC[I-1]=DOC[I];
            DOC[I]=aux1;

            DESORDENADO=I;
          }
       }
     COTA=DESORDENADO;
   }
}

//////////////////////////////////////////////////////////////////

void INFORME(int DOC[],float PR[],int NN)
{ int I;
   printf("\n    DNI                  PROMEDIO \n");
  printf(" _____________________________________________ \n");
  for(I=0;I<NN;I++)
   { printf("\n %8d                   %.2f    \n",DOC[I],PR[I]);
    }
}

