/*Una pizzería vende empanadas por unidad o por docena, la docena cuesta $300 pero si se compra 
individualmente se cobra $30 la unidad. Si se compran más empanadas que no se agrupen en docenas las 
adicionales se cobran como por unidad. Indicar el precio total a abonar.*/

#include <stdio.h>
#define valorDocena 300
#define valorUnidad 30

int main(){
	int cantEmpanadas,docenas,unidades,valorTotal;
	
	printf("Ingrese cantidad total de empanadas compradas: ");
	scanf("%d",&cantEmpanadas);
	
	docenas= (cantEmpanadas / 12);
	unidades= (cantEmpanadas % 12);
	valorTotal= (docenas*valorDocena)+(unidades*valorUnidad);
	
	printf("Precio a abonar: %d", valorTotal);
	
	return 0;
}
