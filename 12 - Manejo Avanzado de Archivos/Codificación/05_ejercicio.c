#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct Contacto{
	int tel;
	char nombre[51];
};

struct nuevoContacto{
	int tel;
	char nombre[51];
};

void crearArchivo(struct Contacto);
void guardarContacto(struct Contacto);
void mostrarContacto(struct Contacto);
void buscarContacto(struct Contacto);
int busqueda(struct Contacto, char[]);
void cambiarContacto(struct Contacto);
void borrarContacto(struct Contacto,struct nuevoContacto);
int validar(int,int,int);

int main(){
	int opc,valid;
	struct Contacto ctc;
	struct nuevoContacto nuev;
	
	crearArchivo(ctc);
	mostrarContacto(ctc);
	do{
		printf("============MENU============\n");
		printf("1 - Crear nuevo contacto\n");
		printf("2 - Buscar contacto\n");
		printf("3 - Modificar contacto\n");
		printf("4 - Borrar contacto\n");
		printf("0 - SALIR\n");
		printf("Ingrese opcion: ");
		scanf("%d",&opc);
		valid = validar(opc,0,4);
	}while(valid == -1);
	while(opc != 0){
		fflush(stdin);
		switch(opc){
			case 1:
				guardarContacto(ctc);
				mostrarContacto(ctc);
				break;
			case 2:
				buscarContacto(ctc);
				mostrarContacto(ctc);
				break;
			case 3:
				cambiarContacto(ctc);
				mostrarContacto(ctc);
				break;
			case 4:
				borrarContacto(ctc,nuev);
				mostrarContacto(ctc);
				break;
		}
		do{
			printf("============MENU============\n");
			printf("1 - Crear nuevo contacto\n");
			printf("2 - Buscar contacto\n");
			printf("3 - Modificar contacto\n");
			printf("4 - Borrar contacto\n");
			printf("0 - SALIR\n");
			printf("Ingrese opcion: ");
			scanf("%d",&opc);
			valid = validar(opc,0,4);
		}while(valid == -1);
	}
	
}

void crearArchivo(struct Contacto ctc){
	int valid;
	FILE *ap;
	
	ap = fopen("Contactos.dat","wb");
	
	if(ap == NULL){
		printf("Error al abrir el archivo\n");
		getch();
		exit(1);
	}

	printf("Ingrese nombre (max 50 carac)(TERMINA EN FIN): ");
	gets(ctc.nombre);
	fflush(stdin);
	while(strcmpi(ctc.nombre,"FIN") != 0){
		do{
			printf("Ingrese telefono: ");
			scanf("%d",&ctc.tel);
			valid = validar(ctc.tel,10000000,99999999);
		}while(valid == -1);
		fwrite(&ctc,sizeof(struct Contacto),1,ap);
		fflush(stdin);
		printf("Ingrese nombre (max 50 carac)(TERMINA EN FIN): ");
		gets(ctc.nombre);
		fflush(stdin);
	}
	
	fclose(ap);
}

void guardarContacto(struct Contacto ctc){
	int valid;
	FILE *ap;
	
	ap = fopen("Contactos.dat","a+b");
	
	if(ap == NULL){
		printf("Error al abrir el archivo\n");
		getch();
		exit(1);
	}

	printf("Ingrese nombre (max 50 carac)(TERMINA EN FIN): ");
	gets(ctc.nombre);
	fflush(stdin);
		while(strcmpi(ctc.nombre,"FIN") != 0){
		do{
			printf("Ingrese telefono: ");
			scanf("%d",&ctc.tel);
			valid = validar(ctc.tel,10000000,99999999);
		}while(valid == -1);
		fwrite(&ctc,sizeof(struct Contacto),1,ap);
		fflush(stdin);
		printf("Ingrese nombre (max 50 carac)(TERMINA EN FIN): ");
		gets(ctc.nombre);
		fflush(stdin);
	}
	
	fclose(ap);
}

void mostrarContacto (struct Contacto ctc){
	FILE *ap;
	
	ap = fopen("Contactos.dat","a+b");
	
	if(ap == NULL){
		printf("Error al abrir el archivo\n");
		getch();
		exit(1);
	}
	printf("CONTACTOS\n");
	fread(&ctc,sizeof(struct Contacto),1,ap);
	while(!feof(ap)){
		printf("Nombre: %s | Telefono: %d\n",ctc.nombre,ctc.tel);
		fread(&ctc,sizeof(struct Contacto),1,ap);
	}
	
	fclose(ap);
}

int validar(int num, int min, int max){
	int valid = -1;
	
	if(num >= min && num <= max){
		valid = 0;
	}
	
	return valid;
}

void buscarContacto(struct Contacto ctc){
	FILE *ap;
	char nomb[51];
	int pos;
	
	ap = fopen("Contactos.dat","r+b");
	if(ap == NULL){
		printf("Error al abrir el archivo\n");
		getch();
		exit(1);
	}
	
	printf("Ingrese nombre (Termina en FIN): ");
	gets(nomb);
	
	while(strcmpi(nomb,"FIN") != 0){
		pos = busqueda(ctc,nomb);
		printf("Ingrese nombre (Termina en FIN): ");
		gets(nomb);
	}
	
	fclose(ap);
}

void borrarContacto(struct Contacto ctc,struct nuevoContacto nuev){
	FILE *ap,*np;
	char nomb[51];
	int pos;
	
	ap = fopen("Contactos.dat","rb");
	np = fopen("NuevoContac.tmp","wb");
	
	if(ap == NULL || np == NULL){
		printf("Error al abrir el archivo\n");
		getch();
		exit(1);
	}
	
	printf("Ingrese nombre para borrar (Termina en FIN): ");
	gets(nomb);
	while(strcmpi(nomb,"FIN") != 0){
		pos = busqueda(ctc,nomb);
		printf("Pos %d\n", pos);
		if(pos != -1){
			fflush(ap);
			rewind(ap);	
			fread(&ctc, sizeof(struct Contacto), 1, ap);
			while (!feof(ap)) {
			    if (strcmpi(ctc.nombre, nomb) != 0) {
			        printf("Nombre: %s | Telefono: %d\n", ctc.nombre, ctc.tel);
			
			        strcpy(nuev.nombre, ctc.nombre);
			        nuev.tel = ctc.tel;
			        fwrite(&nuev, sizeof(struct Contacto), 1, np);
			        fflush(np);
			    } else {
			        printf("Nombre encontrado, no se ha guardado: %s\n", ctc.nombre);
			    }
			    fread(&ctc, sizeof(struct Contacto), 1, ap);
			}
			
			printf("Nombre borrado\n");
		}
		else{
			printf("Nombre no encontrado\n");
		}
		
		fflush(stdin);
		printf("Ingrese nombre para borrar (Termina en FIN): ");
		gets(nomb);
	}
	fclose(ap);
	fclose(np);
	
	remove("Contactos.dat");
	rename("NuevoContac.tmp","Contactos.dat");
	

}

void cambiarContacto(struct Contacto ctc){
	FILE *ap;
	char nomb[51];
	int pos, valid;
	
	ap = fopen("Contactos.dat","r+b");
	
	if(ap == NULL){
		printf("Error al abrir el archivo\n");
		getch();
		exit(1);
	}
	
	printf("Ingrese nombre para cambiar (Termina en FIN): ");
	gets(nomb);
	
	while(strcmpi(nomb,"FIN") != 0){
		pos = busqueda(ctc,nomb);
			
		if(pos != -1){
			fseek(ap,sizeof(struct Contacto)*(pos-1),1);
			
			printf("Ingrese nuevo nombre: ");
			gets(ctc.nombre);
			do{
				printf("Ingrese telefono: ");
				scanf("%d",&ctc.tel);
				valid = validar(ctc.tel,10000000,99999999);
			}while(valid == -1);
			fwrite(&ctc,sizeof(struct Contacto),1,ap);
		}
		else{
			printf("Nombre no encontrado\n");
		}
		fflush(stdin);
		printf("Ingrese nombre para cambiar (Termina en FIN): ");
		gets(nomb);
	}
	
	fclose(ap);
	
}

int busqueda(struct Contacto ctc,char nombre[]){
	int pos = -1;
	
	FILE *ap;
	
	ap = fopen("Contactos.dat","rb");
	
	fread(&ctc,sizeof(struct Contacto),1,ap);
	while(!feof(ap) && pos == -1){
		if(strcmpi(ctc.nombre, nombre) == 0){
			pos = ftell(ap)/sizeof(struct Contacto);
			printf("Nombre: %s | Telefono: %d\n",ctc.nombre,ctc.tel);
		}
		else{
			fread(&ctc,sizeof(struct Contacto),1,ap);
		}
	}
	
	fclose(ap);
	
	return pos;
}
