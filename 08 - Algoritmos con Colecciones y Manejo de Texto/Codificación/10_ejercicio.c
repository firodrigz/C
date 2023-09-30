/*Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.*/

#include <stdio.h>
#include <string.h>

int busquedaDNI(int [], int, int);
int busqueda(char [][15], char [], int);
int validarDNI(int, int);
void ordenar(char [][15], int);
int cargaAlumnos(char [][15], int [], int, int);
void busquedaAlumnos(char[][15], int [], char [], int);
void mostrarListadoOrdenado(char [][15], int);

int main(){
	int vectorDNI[50];
	char nombreAlumno[50][15];
	char nombreBusqueda[15];
	
	int ingresoAlumnos;
	
	ingresoAlumnos = cargaAlumnos(nombreAlumno, vectorDNI, 50, 15);
	
	if(ingresoAlumnos!=0){
		busquedaAlumnos(nombreAlumno, vectorDNI, nombreBusqueda, ingresoAlumnos);
		ordenar(nombreAlumno, ingresoAlumnos);
		mostrarListadoOrdenado(nombreAlumno, ingresoAlumnos);
	}else{
		printf("\nNo se registraron alumnos");
	}
	
	
	return 0;
}

int busquedaDNI(int vector[], int nro, int ce){
	int encuentra=-1, i=0;
	
	while(encuentra== -1 && i<ce){
		if(vector[i]==nro){
			encuentra=i;
		}else{
			i++;
		}
	}
	
	return encuentra;
}

int busqueda(char nombreAlumno[][15], char nro[], int ce){
	int encuentra=-1, i=0;
	
	while(encuentra==-1 && i<ce){
		if(strcmpi(nombreAlumno[i],nro)==0){
			encuentra=i;
		}else{
			i++;
		}
	}
	
	return encuentra;
}

void ordenar(char vn[][15], int ce){
	int i,j;
	char aux[15];
	
	for(i=0;i<ce-1;i++){
		for(j=0;j<ce-i-1;j++){
			if(strcmpi(vn[j],vn[j+1]) > 0){
				strcpy(aux,vn[j]);
				strcpy(vn[i],vn[j+1]);
				strcpy(vn[j+1],aux);
			}
		}
	}
}

int validarDNI(int LI, int LS){
	int nro, band=0;
	
	do{
		if(band==0){
			printf("\nValor entre %d y %d: ", LI, LS);
			band++;
		}else{
			printf("\nValor inválido, intente nuevamente: ");
		}
		scanf("%d", &nro);
	}while(nro<LI || nro>LS);
}

int cargaAlumnos(char alumnos[][15], int vectorDNI[], int cantAlumnos, int cantCaracteres){
	int i=0, band, dni;
	char auxAlumno[cantCaracteres];
	
	printf("Carga de alumnos");	
	band=0;
	do{
		if(band==0){
			printf("\nIngrese nombre de alumno (finaliza con FIN): ");
			band++;
		}else{
			printf("\nNombre ingresado fuera de límites, intente con otro: ");
		}
		gets(auxAlumno);
	}while(strlen(auxAlumno)>= cantCaracteres);
	
	while(i<cantAlumnos && strcmpi(auxAlumno,"FIN")!=0){
		
		do{
			printf("\nIngrese DNI");
			dni = validarDNI(11111111,99999999);
		}while(busquedaDNI(vectorDNI, dni, i)!=-1);
		
		vectorDNI[i]= dni;
		strcpy(alumnos[i],auxAlumno);
		i++;
		
		do{
			if(band==0){
				printf("\nIngrese nombre de alumno (finaliza con FIN): ");
				band++;
			}else{
				printf("\nNombre ingresado fuera de límites, intente con otro: ");
			}
			gets(auxAlumno);
		}while(strlen(auxAlumno)>= cantCaracteres);
	}
	
	return i;	
}

void busquedaAlumnos(char alumnos[][15], int vectorDNI[], char nombreBusqueda[], int cantAlumnos){
	int posEncontrado;
	
	printf("\nBúsqueda de nombres");
	printf("\nIngrese nombre a buscar (termina con NO BUSCAR MÁS): ");
	fgets(nombreBusqueda, 15, stdin);
	nombreBusqueda[strlen(nombreBusqueda) -1]='\0';
	
	while(strcmpi(nombreBusqueda, "NO BUSCAR MAS")!=0){
		posEncontrado= busqueda(alumnos,nombreBusqueda,cantAlumnos);
		if(posEncontrado!=-1){
			printf("\nEncontrado!, DNI: %d", vectorDNI[posEncontrado]);
		}else{
			printf("\nNo existe el alumno buscado");
		}
		
		printf("\nIngrese nombre a buscar (termina con NO BUSCAR MÁS): ");
		fgets(nombreBusqueda, 15, stdin);
		nombreBusqueda[strlen(nombreBusqueda) -1]='\0';
	}	
}

void mostrarListadoOrdenado(char alumnos[][15], int cantAlumnos){
	int i;
	
	for(i=0;i<cantAlumnos;i++){
		puts(alumnos[i]);
	}
}
