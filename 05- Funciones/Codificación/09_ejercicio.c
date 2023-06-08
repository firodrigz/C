/* Realizar una función que reciba 3 números enteros correspondientes al día, mes y año de
una fecha y valide si la misma es correcta. En caso de que la fecha es correcta debe
retornar un 1 y si es incorrecta debe retornar un 0. Para la validación usar la función
del punto 8 que retorna la cantidad de días de un mes. */


#include <stdio.h>
#include <locale.h>

//PROTOTIPO DE FUNCIONES.
int es_bisiesto(int);
int cant_dias_mes(int,int);
int es_fecha_valida(int,int,int);

int main()
{
    int dia, mes,anio;//VARIABLES LOCALES DEL MAIN.

    setlocale(LC_ALL,"spanish");

    do{
        printf("Ingrese el día:");
        scanf("%d",&dia);
        printf("Ingrese el mes:");
        scanf("%d",&mes);
        printf("Ingrese el año:");
        scanf("%d",&anio);
    }while(es_fecha_valida(dia, mes,anio)==0);

    printf("\n La fecha %2d/%2d/%4d es válida.",dia, mes, anio);

    return 0;
}

//DEFINICIÓN DE FUNCIONES.

int es_fecha_valida(int d,int m ,int a)
{
    int resu=0; //VARIABLE LOCAL DE LA FUNCIÓN.

    if(a >=1582 && a <=2021)
       {
           if(m >=1 && m <= 12)
           {
               if(d >=1 && d <= cant_dias_mes(m,a)  )
                 {
                   resu = 1;
                 }
                else
                {
                    printf("\nDia erroneo.\n");
                }
           }
           else
                {
                    printf("\nMes erroneo.\n");
                }
       }
       else
                {
                    printf("\nAño erroneo.\n");
                }

    return resu;
}

//////////////////////////////////////////////////////////////////////////////////////

int cant_dias_mes(int m,int a)
{
    int cd;//VARIABLE LOCAL DE LA FUNCIÓN.

    //LA VARIABLE m ESTÁ COMPRENDIDA ENTRE 1 Y 12.
    switch(m)
    {
        case 4:
        case 6:
        case 9:
        case 11: cd=30;
                 break;

        case 2:
                cd=28 + es_bisiesto(a);
                break;
        default :
                 cd=31;
   }

   return cd;
}

//////////////////////////////////////////////////////////////////////////////////////

int es_bisiesto(int a)
{
    int res=0; //VARIABLE LOCAL DE LA FUNCIÓN.

    if( (a%4==0 && a%100!=0 )|| a%400==0)
         res = 1;

    return res;
}
