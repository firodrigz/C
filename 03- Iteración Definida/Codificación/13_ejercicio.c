/*Calcular el factorial de un n�mero ingresado por teclado. El factorial se calcula como el producto de todos
los enteros positivos desde 1 hasta el n�mero. En matem�tica el factorial se expresa con el s�mbolo. Por
ejemplo, el factorial de 5 es 120 ya que 5! = 1 x 2 x 3 x 4 x 5 =120*/

#include <stdio.h>
#include <locale.h>

int main(){
	int factorial = 0;
	int nro,i;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese un n�mero para calcular su factorial: ");
	scanf("%d",&nro);
	
	for(i=1;i<=nro;i++){
		factorial*=i;
	}
	
	printf("Factorial: %d",factorial);
	
	return 0;
}
