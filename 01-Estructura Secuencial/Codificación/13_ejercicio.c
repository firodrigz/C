/*Confeccionar un programa que solicite el ingreso de un n�mero entero positivo de 4 cifras y pueda calcular e 
informar la suma de sus d�gitos hasta llegar a una sola cifra. Ej:2561 ? 5*/

#include <stdio.h>

int main(){
	int nro,m,c,d,u,comp,total;
	
	printf("Ingrese un n�mero entero positivo de 4 cifras: ");
	scanf("%d",&nro);
	
	m=(nro/1000);
	c=((nro%1000)/100);
	d=(((nro%1000)%100)/10);
	u=(((nro%1000)%100)%10);
	comp= m+c+d+u;
	total= ((comp/10)+(comp%10));
	
	printf("La suma de sus d�gitos hasta llegar a una sola cifra es: %d",total);	
	
	return 0;
}
