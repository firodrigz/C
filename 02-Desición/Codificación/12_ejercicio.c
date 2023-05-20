/*Un fabricante de repuestos para tractores ha descubierto que ciertos artículos identificados por los
números de catálogo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos. Se desea
confeccionar un programa al que informándole el número de catálogo indique si el artículo es o no
defectuoso. Los artículos del catálogo van desde el 1200 al 90000. Si se ingresa otro número informar
“FUERA DE CATALOGO”.*/

#include <stdio.h>
#include <locale.h>


int main(){
	int id;
	
	setlocale(LC_ALL, "spanish");
	
	printf("Ingrese número de catálogo del artículo: ");
	scanf("%d",&id);
	
	if((id>1200)&&(id<90000)){
		if((id>12121&&id<18081)&&(id>30012&&id<45565)&&(id>67000&&id<68000)){
			printf("\nArtículo defectuoso");
		}
		else{
			printf("\nOK");
		}
	}
	else{
		printf("\nFUERA DE CATÁLOGO");
	}
	
	return 0;
}
