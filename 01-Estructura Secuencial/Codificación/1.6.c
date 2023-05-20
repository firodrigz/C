/*El precio para un vuelo es de $8800 en clase turista y se aplica un incremento del 30% en primera clase. 
Se ingresan la cantidad de pasajes vendidos de clase turista y de primera clase.
Obtener la recaudación total del vuelo.*/

#include <stdio.h>
#define cTurista 8800
#define cPP cTurista + (cTurista * 30/100)

int main(){
	int cantPT, cantPP, total;
	
	printf("Ingrese cantidad de pasajes vendidos de clase turista: ");
	scanf("%d",&cantPT);
	printf("Ingrese cantidad de pasajes vendidos de primera clase: ");
	scanf("%d",&cantPP);
	
	total = (cTurista * cantPT) + (cPP * cantPP);
	
	printf("Total: %d", total);	
	return 0;
	
}
