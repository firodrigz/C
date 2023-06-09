/*Realizar una función que permita sumar 1 día a una fecha válida mostrando la fecha resultante. Si la fecha
recibida no es válida informarlo con un mensaje (validar utilizando la función del punto 9).*/


#include <stdio.h>
#include <locale.h>

//PROTOTIPO DE FUNCIONES.
int es_bisiesto(int);
int cant_dias_mes(int,int);
int es_fecha_valida(int,int,int);
int suma_dias(int,int,int);

int main()
{
    int dia, mes,anio;

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
    
    printf("\n\nSi le sumamos un día");
    
    if(suma_dias(dia, mes,anio)==1){
    	printf("\n\n La fecha es = %2d/%2d/%4d.",dia+1, mes, anio);
	}
	else{
		printf("\nLa fecha no es válida");
	}

    return 0;
}

//DEFINICIÓN DE FUNCIONES.

int suma_dias(int d,int m,int a){
	
	d=d+1;
	
	return (es_fecha_valida(d,m,a));	
	
}

int es_fecha_valida(int d,int m ,int a)
{
    int resu=0; 

    if(a >=1582 && a <=2023)
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
    int cd;

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
    int res=0; 

    if( (a%4==0 && a%100!=0 )|| a%400==0)
         res = 1;

    return res;
}

