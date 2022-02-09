#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "TG.h"

bool inicio (Usuario &Pro);

void listarturnos (Usuario Pro);

void atencion (Usuario Pro);


main () {
	
	int opc= 0, ingreso= 1;
	bool sesion= false;
	Usuario Pro;

	do {
		
		system("CLS");
		printf("Modulo Espacios");
		printf("\n");
		printf("\n\n 1.- Iniciar Sesion");
		printf("\n 2.- Visualizar Lista de Espera de Turnos (informe)");
		printf("\n 3.- Registrar Evolucion del tratamiento\n");
		printf("\n\n 4.- Cerrar la aplicacion.\n");
		printf("\nIngrese una Opcion: ");
		scanf("%d", &opc);
		
		if (!sesion and opc!= 1 and opc!= 4){
			
			system("CLS");
				
			printf("primero Inicie Sesion...");
			} 
			
		else{
			
			ingreso = 1;
	
		    switch(opc){
			
					case 1:
					
					system("CLS");
					
					sesion=inicio(Pro);
					
					break;
				
					case 2:
					
					system("CLS");
					
					listarturnos(Pro);
					
					break;
				
					case 3:
					
					system("CLS");
					
					atencion(Pro);
					
					break;
				}
			}	
		printf("\n\n\n");
		system("PAUSE");
		
	}while(opc!=4);
	
}

bool inicio (Usuario &Pro) {
	
	FILE *Arch;
	Usuario Buscar, Dato;
	bool Sesion = false;
	
	Arch = fopen("Profesionales.dat", "r+b");
	
	printf("Ingrese los datos requeridos");
	printf("\n=============================");
	printf("\n\n [usuario] = ");
	_flushall();
	gets(Buscar.Usuario);
	printf("\n [contraseña] = ");
	gets(Buscar.Clave);
	
	fread(&Dato, sizeof(Usuario), 1, Arch);
	
	while (!feof(Arch)) {
		
		if (strcmp(Buscar.Usuario, Dato.Usuario) == 0 and strcmp(Buscar.Clave, Dato.Clave) == 0) {
		
			Sesion = true;
			break;
		
		}
		
		fread(&Dato, sizeof(Dato), 1, Arch);
		
	}
	
	if (!Sesion) {
		
		system("CLS");
		
		printf("usuario o contraseña Incorrectos...");
		
	} else {
		
		system("CLS");
		
		printf("Bienvenido [%s]", Dato.ApeNom);
		
	}
	
	Pro = Dato;
	
	fclose(Arch);
	
	return Sesion;
	
}

void listarturnos (Usuario Pro) {
	
	FILE *Arch, *Aux;
	Turnos Dato;
	Fecha Actual;
	Cliente DatoCli;
	bool Existe = false;
	
	Arch = fopen("Turnos.dat", "r+b");
	Aux = fopen("Clientes.dat", "r+b");
	
	if (!Arch) {
			
		printf("No hay registros risponibles aun...");
		
		return;
			
	}
	
	printf("Ingrese los datos requeridos");
	printf("\n==============================");
	printf("\n\n[Fecha actual]");
	printf("\n\n\t[Dia - DD] = ");
	scanf("%d", &Actual.DD);
	printf("\n\t[Mes - MM] = ");
	scanf("%d", &Actual.MM);
	printf("\n\t[Año - AAAA] = ");
	scanf("%d", &Actual.AAAA);
	
	fread(&Dato, sizeof(Turnos), 1, Arch);
	
	system("CLS");
	
	printf("Lista de turnos");
	printf("\n=================\n\n");
	
	while (!feof(Arch)) {
		
		if (Pro.ID == Dato.ID and Actual.DD == Dato.FechaTurno.DD and Actual.MM == Dato.FechaTurno.MM and Actual.AAAA == Dato.FechaTurno.AAAA) {
			
			Existe = true;
			
			rewind(Aux);
			
			fread(&DatoCli, sizeof(Cliente), 1, Aux);
			
			while (!feof(Aux)) {
				
				if (Dato.DNI == DatoCli.DNI) {
					
					printf("[Apellido y Nombre] => %s    ---    [DNI] => %d\n\n", DatoCli.ApeNom, DatoCli.DNI);
					
				}
				
				fread(&DatoCli, sizeof(Cliente), 1, Aux);
				
			}
			
		}
		
		fread(&Dato, sizeof(Turnos), 1, Arch);
		
	}
	
	fclose(Aux);
	fclose (Arch);
	
	if (!Existe) {
		
		system("CLS");
		
		printf("Actualmente no hay turnos para atender con esos datos...");
		return;
		
	}
	
}

void atencion (Usuario Pro) {
	
	FILE *Arch, *Aux, *Atencion, *New;
	Turnos Dato;
	Fecha Actual;
	Cliente DatoCli;
	int i = 0, Estado, DNI;
	char Nom[60];
	bool Existe = false;
	
	Arch = fopen("Turnos.dat", "r+b");
	Aux = fopen("Clientes.dat", "r+b");
	Atencion = fopen("Atencion.dat", "r+b");
	New = fopen("New.dat", "w+b");
	
	if (!Arch) {
			
		printf("No hay registros disponibles aun...");
		
		return;
			
	}
	
	printf("Ingrese los datos requeridos para comenzar la atencion");
	printf("\n========================================================");
	printf("\n\n[Apellido y nombre del cliente] = ");
	_flushall();
	gets(Nom);
	printf("\n\n[DNI del cliente] = ");
	scanf("%d", &DNI);
	printf("\n\n[Fecha actual]");
	printf("\n\n\t[Dia] = ");
	scanf("%d", &Actual.DD);
	printf("\n\t[Mes] = ");
	scanf("%d", &Actual.MM);
	printf("\n\t[Año] = ");
	scanf("%d", &Actual.AAAA);
	_flushall();
	
	fread(&Dato, sizeof(Turnos), 1, Arch);
	
	while (!feof(Arch)) {
		
		if (Pro.ID == Dato.ID and Actual.DD == Dato.FechaTurno.DD and Actual.MM == Dato.FechaTurno.MM and Actual.AAAA == Dato.FechaTurno.AAAA and Dato.DNI == DNI) {
			
			rewind(Aux);
			
			fread(&DatoCli, sizeof(Cliente), 1, Aux);
			
			while (!feof(Aux)) {
				
				if (strcmp(strlwr(Nom), strlwr(DatoCli.ApeNom)) == 0 and DatoCli.DNI == DNI and Dato.DNI == DNI) {
						
					system("CLS");
			
					printf("Datos del cliente");
					printf("\n=================");
					printf("\n\n[Apellido y Nombre] => %s", DatoCli.ApeNom);
					printf("\n[DNI] => %d", DatoCli.DNI);
					printf("\n[Domicilio] => %s", DatoCli.Domicilio);
					printf("\n[Edad] => %d", DatoCli.Edad);
					printf("\n[Peso] => %.2f kg\n\n\n", DatoCli.Peso);
					
					system("PAUSE");
					
					system("CLS");

					printf("Ingrese la evolucion del tratamiento (380 o menos caracteres)");
					printf("\n\n==> ");
					gets(Dato.DetalleAtencion);
					strcpy(Dato.ApeNom, Pro.ApeNom);
					
					fwrite(&Dato, sizeof(Turnos), 1, Atencion);
					
					i = 1;
					
					Existe = true;
					
				}
				
				fread(&DatoCli, sizeof(Cliente), 1, Aux);
				
			}
			
		}
		
		if (i != 1) {
			
			fwrite(&Dato, sizeof(Turnos), 1, New);
			
		} else {
			
			i = 0;
			
		}
		
		fread(&Dato, sizeof(Turnos), 1, Arch);
		
	}
	
	fclose(New);
	fclose(Atencion);
	fclose(Aux);
	fclose(Arch);
	
	if (!Existe) {
		
		system("CLS");
		
		printf("Datos incorrectos o no hay clientes por atender...");
		
		remove("New.dat");
		
		return;
		
	}
	
	Estado = remove("Turnos.dat");
	rename("New.dat", "Turnos.dat");
	
	if (!Estado) {
		
		system("CLS");
		
		printf("Se quito de la lista el cliente atendido");
		
	}
	
}
