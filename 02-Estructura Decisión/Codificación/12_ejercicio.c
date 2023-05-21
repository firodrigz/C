/*Un fabricante de repuestos para tractores ha descubierto que ciertos art�culos identificados por los
n�meros de cat�logo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos. Se desea
confeccionar un programa al que inform�ndole el n�mero de cat�logo indique si el art�culo es o no
defectuoso. Los art�culos del cat�logo van desde el 1200 al 90000. Si se ingresa otro n�mero informar
�FUERA DE CATALOGO�.*/

#include <stdio.h>
#include <locale.h>


int main(){
	int id;
	
	setlocale(LC_ALL, "spanish");
	
	printf("Ingrese n�mero de cat�logo del art�culo: ");
	scanf("%d",&id);
	
	if((id>1200)&&(id<90000)){
		if((id>12121&&id<18081)&&(id>30012&&id<45565)&&(id>67000&&id<68000)){
			printf("\nArt�culo defectuoso");
		}
		else{
			printf("\nOK");
		}
	}
	else{
		printf("\nFUERA DE CAT�LOGO");
	}
	
	return 0;
}
