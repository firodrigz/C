/*Se ingresan 3 números distintos. Determinar el mayor*/

#include <stdio.h>
#include <locale.h> //CONFIGURACIÓN DEL IDIOMA.

int main(){
	
	int n1,n2,n3,mayor;
	
    setlocale(LC_ALL,"spanish");//SETEAR EL IDIOMA A ESPAÑOL.
	
	printf("Ingrese un número: ");
	scanf("%d",&n1);
	mayor=n1;	
	
	printf("Ingrese un número: ");
	scanf("%d",&n2);
	if(n2>mayor){
		mayor=n2;
	}
	
	printf("Ingrese un número: ");
	scanf("%d",&n3);
	if(n3>mayor){
		mayor=n3;
	}
	
	printf("\nEl mayor número es: %d", mayor);
	
	return 0;
	
}
