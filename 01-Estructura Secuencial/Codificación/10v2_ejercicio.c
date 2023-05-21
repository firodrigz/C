/*
 Confeccionar un programa que solicite el ingreso del valor del radio
 de un c�rculo y con dicho valor calcule la superficie del c�rculo,
 la longitud de la circunferencia (per�metro) y el volumen de la esfera
*/

#include <stdio.h>
#include <math.h>//BIBLIOTECAS QUE CONTIENE FUNCIONES DE MATEM�TICA.

//DEFINICI�N DE UNA CONSTANTE A NIVEL DE MACRO.
#define PI 3.14159

int main()
{
    float radio,perim,sup,vol;
    //const float PI = 3.14;//OCUPA ESPACIO DE MEMORIA.

    printf("Ingrese el radio\n");
    scanf("%f",&radio);

    /*
      ALGUNAS FUNCIONES DE LA BIBLIOTECA math.h

      Potencia -> pow (base,exponente); Retorna float
      Ra�z cuadrada -> sqrt(argumento); Retorna float
      Logaritmo natural -> log(argumento); Retorna float
      M�dulo -> abs(argumento);
      seno -> sin(argumento); Retorna float
      ....
    */

    sup = PI * pow(radio,2);//sup = PI * radio*radio//sup=3.14*radio*radio; //calculo de la superficie

    perim = 2 * PI *  radio//perim=2 * 3.14 *  radio; //calculo del per�metro

    vol = 4 * PI * pow(radio,3) /3;//vol = 4 * PI * radio *radio *radio /3;//vol= 4 * 3.14 * radio *radio *radio /3; //calculo del volumen

    printf("\nSuperficie: %.2f\n",sup);
    printf("\nPerimetro: %.2f\n",perim);
    printf("\nVolumen: %.2f\n",vol);

    return 0;
}
