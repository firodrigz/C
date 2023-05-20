/*Confeccionar un programa que ingrese un valor expresado en Kibibyte (KiB)1
y lo informe expresado en: TiB, GiB, MiB, con leyendas aclaratorias. (1MiB = 1024 KiB; 1GiB = 1024 MiB; 1TiB = 1024 GiB)*/

#include <stdio.h>

int main(){
	int KiB,TiB, GiB, MiB;
	
	printf("Ingrese un valor expresado en Kibibyte (KiB): ");
	scanf("%d",&KiB);
	
	MiB= (KiB/1024);
	GiB= (MiB/1024);
	TiB= (GiB/1024);
	
	printf("MiB: %d \nGiB: %d \nTiB: %d",MiB,GiB,TiB);


	return 0;
}
