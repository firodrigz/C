/*Realizar una funci�n que permita sumar 1 d�a a una fecha v�lida mostrando la fecha resultante. Si la fecha
recibida no es v�lida informarlo con un mensaje (validar utilizando la funci�n del punto 9).*/


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
        printf("Ingrese el d�a:");
        scanf("%d",&dia);
        printf("Ingrese el mes:");
        scanf("%d",&mes);
        printf("Ingrese el a�o:");
        scanf("%d",&anio);
    }while(es_fecha_valida(dia, mes,anio)==0);    

    printf("\n La fecha %2d/%2d/%4d es v�lida.",dia, mes, anio);
    
    printf("\n\nSi le sumamos un d�a");
    
    if(suma_dias(dia, mes,anio)==1){
    	printf("\n\n La fecha es = %2d/%2d/%4d.",dia+1, mes, anio);
	}
	else{
		printf("\nLa fecha no es v�lida");
	}

    return 0;
}

//DEFINICI�N DE FUNCIONES.

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
                    printf("\nA�o erroneo.\n");
                }

    return resu;
}

//////////////////////////////////////////////////////////////////////////////////////

int cant_dias_mes(int m,int a)
{
    int cd;

    //LA VARIABLE m EST� COMPRENDIDA ENTRE 1 Y 12.
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

