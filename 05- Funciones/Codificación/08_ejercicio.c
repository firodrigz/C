/*Realizar una funci�n que, dado un mes y un a�o, calcule la cantidad de d�as de dicho mes. El a�o se utilizar�
en el caso de que el mes sea febrero ya que los a�os bisiestos tienen 29 d�as en lugar de 28.
Un a�o es bisiesto cuando: (el a�o es divisible por 4 y NO por 100) o (el a�o es divisible por 400).*/

#include <stdio.h>

int dias(int, int);


int main()
{
	int anio, mes, cant;

	printf( "Ingrese el numero de mes: " );
	scanf( "%d" , &mes );

	printf( "Ingrese el a�o: " );
	scanf( "%d" , &anio );

	cant =dias(mes,anio);
    printf( "El mes %d del anio %d tiene %d dias" , mes, anio, cant );
    return 0;
    
}


int dias(int mes, int anio)
{
    int diasMes;
    switch( mes )
	{
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10:
        case 12:
            diasMes = 31;
            break;

        case 2:
            if( ( anio %4 == 0 && anio % 100 != 0 ) || ( anio % 400 == 0 ) )
                diasMes = 29;
            else
                diasMes = 28;
            break;

        case 4 :
        case 6 :
        case 9 :
        case 11:
            diasMes = 30;
            break;
    }
    return diasMes;

}
