/*Se ingresan 3 n�meros distintos. Determinar el mayor*/

#include <stdio.h>
#include <locale.h> //CONFIGURACI�N DEL IDIOMA.

int main(){
	
	int n1,n2,n3,mayor;
	
    setlocale(LC_ALL,"spanish");//SETEAR EL IDIOMA A ESPA�OL.
	
	printf("Ingrese un n�mero: ");
	scanf("%d",&n1);
	mayor=n1;	
	
	printf("Ingrese un n�mero: ");
	scanf("%d",&n2);
	if(n2>mayor){
		mayor=n2;
	}
	
	printf("Ingrese un n�mero: ");
	scanf("%d",&n3);
	if(n3>mayor){
		mayor=n3;
	}
	
	printf("\nEl mayor n�mero es: %d", mayor);
	
	return 0;
	
}
