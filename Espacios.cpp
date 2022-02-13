#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "Centro_estetico.h"

bool inicio (Usuario &Pro);

void listarturnos (Usuario Pro);

void atencion (Usuario Pro);


main () {
	
	int opc= 0, ingreso= 1;
	bool sesion= false;
	Usuario Pro;

	do {
		
		system("CLS");
		
		printf("\033[1;33m");
		printf(".................");
		printf(" \n Modulo Espacios  ");
		printf("\n................. \n");
		printf("\033[1;36m");
		printf("\n 1) -> Iniciar sesion.");
		printf("\n 2) -> Visualizar lista de espera de turnos (informe).");
		printf("\n 3) -> Registrar evolucion del tratamiento.");
		printf("\n 4) -> Cerrar la aplicacion.");
		printf("\033[1;32m");
		printf("\n\nIngrese una Opcion: ");
		printf("\033[1;31m");
		scanf("%d", &opc);
		printf("\033[1;36m");
		
		if (!sesion and opc!= 1 and opc!= 4){
			
			system("CLS");
				
			printf("Primero debe iniciar sesion...");
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
	printf("\033[1;37m");
}

bool inicio (Usuario &Pro) {
	
	FILE *Arch;
	Usuario Buscar, Dato;
	bool Sesion = false;
	
	Arch = fopen("Profesionales.dat", "r+b");
	
	printf("Ingrese los datos requeridos del profesional");
	printf("\n");
	printf("\n\n [Usuario] = ");
	printf("\033[1;37m");
	_flushall();
	gets(Buscar.Usuario);
	printf("\033[1;36m");
	printf("\n [Clave] = ");
	printf("\033[1;37m");
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
		printf("\033[1;31m");
		printf("Usuario o clave incorrecto...");
		printf("\033[1;37m");
	} else {
		
		system("CLS");
		printf("\033[1;36m");
		printf("Bienvenido" );
		printf("\033[1;32m ");
		printf("[%s]", Dato.ApeNom);
		printf("\033[1;36m");
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
	printf("\n");
	printf("\n\n[Fecha actual]");
	printf("\n\n\t[Dia - DD] = ");
	printf("\033[1;37m");
	scanf("%d", &Actual.DD);
	printf("\033[1;36m");
	printf("\n\t[Mes - MM] = ");
	printf("\033[1;37m");
	scanf("%d", &Actual.MM);
	printf("\033[1;36m");
	printf("\n\t[Año - AAAA] = ");
	printf("\033[1;37m");
	scanf("%d", &Actual.AAAA);
	printf("\033[1;36m");
	
	fread(&Dato, sizeof(Turnos), 1, Arch);
	
	system("CLS");
	
	printf("Lista de turnos");
	printf("\n\n\n");
	
	while (!feof(Arch)) {
		
		if (Pro.ID == Dato.ID and Actual.DD == Dato.FechaTurno.DD and Actual.MM == Dato.FechaTurno.MM and Actual.AAAA == Dato.FechaTurno.AAAA) {
			
			Existe = true;
			
			rewind(Aux);
			
			fread(&DatoCli, sizeof(Cliente), 1, Aux);
			
			while (!feof(Aux)) {
				
				if (Dato.DNI == DatoCli.DNI) {
					
					printf("[Apellido y Nombre] = ");
					printf("\033[1;37m");
					printf("%s",DatoCli.ApeNom );
					printf("\033[1;36m");
					printf(" ==== [DNI] = ");
					printf("\033[1;37m");
					printf("%d\n\n",DatoCli.DNI );
					printf("\033[1;36m");
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
	printf("\n");
	printf("\n[Apellido y Nombre del cliente] = ");
	_flushall();
	printf("\033[1;37m");
	gets(Nom);
	printf("\033[1;36m");
	printf("\n\n[DNI del cliente] = ");
	printf("\033[1;37m");
	scanf("%d", &DNI);
	printf("\033[1;36m");
	printf("\n\n[Fecha actual]");
	printf("\n\n\t[Dia] = ");
	printf("\033[1;37m");
	scanf("%d", &Actual.DD);
	printf("\033[1;36m");
	printf("\n\t[Mes] = ");
	printf("\033[1;37m");
	scanf("%d", &Actual.MM);
	printf("\033[1;36m");
	printf("\n\t[Año] = ");
	printf("\033[1;37m");
	scanf("%d", &Actual.AAAA);
	printf("\033[1;36m");
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
					printf("\n");
					printf("\n\n[Apellido y Nombre] >> ");
					printf("\033[1;37m");
					printf("%s",DatoCli.ApeNom);
					printf("\033[1;36m");
					printf("\n[DNI] >> ");
					printf("\033[1;37m");
					printf("%d",DatoCli.DNI);
					printf("\033[1;36m");
					printf("\n[Domicilio] >> ", DatoCli.Domicilio);
					printf("\033[1;37m");
					printf("%s",DatoCli.Domicilio);
					printf("\033[1;36m");
					printf("\n[Edad] >> ");
					printf("\033[1;37m");
					printf("%d",DatoCli.Edad);
					printf("\033[1;36m");
					printf("\n[Peso] >> ");
					printf("\033[1;37m");
					printf("%.2f kg\n\n\n",DatoCli.Peso);
					printf("\033[1;36m");
					
					system("PAUSE");
					
					system("CLS");

					printf("Ingrese la evolucion del tratamiento (380 o menos caracteres)");
					printf("\n\n >> ");
					printf("\033[1;37m");
					gets(Dato.DetalleAtencion);
					printf("\033[1;36m");
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
