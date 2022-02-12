#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "Centro_estetico.h"

bool Inicio ();

void RegCliente ();

void RegTurno ();

void Listado ();


main () {
	setlocale(LC_ALL, "");

	Crear();
	
	int Opcion = 0, Ingreso = 1;
	bool Sesion = false;

	do {
	
		system("CLS");
		
		printf("\033[1;33m");
		printf(".....................");
		printf(" \n Modulo de Recepcion");
		printf("\n.....................");
		printf("\033[1;36m");
		printf("\n\n 1) -> Iniciar sesion.");
		printf("\n 2) -> Registrar cliente.");
		printf("\n 3) -> Registrar turno.");
		printf("\n 4) -> Listado de atenciones por profesional y fecha.");
		printf("\n 5) -> Cerrar la aplicacion.");
		printf("\033[1;32m");
		printf("\n\nIngrese una opcion: ");
		scanf("%d", &Opcion);
		printf("\033[1;36m");
		
		if (!Sesion and Opcion != 1 and Opcion != 5) {
			
			system("CLS");
				
			printf("Primero inicie sesion...");
			
		} else {
			
			Ingreso = 1;
			
			switch (Opcion) {
			
				case 1:
					
					system("CLS");
					
					Sesion = Inicio();
					
				break;
					
				case 2:
					
					while (Ingreso == 1) {
						
						system("CLS");
					
						RegCliente();
						
						system("CLS");
						
						printf("¿Continuar registrando clientes?");
						printf("\n\n [0] -> No, salir");
						printf("\n [1] -> Si, continuar");
						printf("\n\n-> ");
						scanf("%d", &Ingreso);
						
					}
					
				break;
					
				case 3:
						
					while (Ingreso == 1) {
						
						system("CLS");
					
						RegTurno();
						
						system("CLS");
						
						printf("¿Continuar registrando turnos?");
						printf("\n\n [0] -> No, salir");
						printf("\n [1] -> Si, continuar");
						printf("\n\n-> ");
						scanf("%d", &Ingreso);
						
					}
						
				break;
					
				case 4:
						
					system("CLS");
					
					Listado();
						
				break;
				
			}
			
		}
		
		printf("\n\n\n");
		
		system("PAUSE");
		
	} while (Opcion != 5);
	printf("\033[0m");

}


bool Inicio () {
	
	FILE *Arch;
	Usuario Buscar, Dato;
	bool Sesion = false;
	
	Arch = fopen("Recepcionistas.dat", "r+b");
	
	printf("Ingrese los datos requeridos del recepcionista");
	printf("\n");
	printf("\n\n [Usuario] = ");
	_flushall();
	printf("\033[0m");
	gets(Buscar.Usuario);
	printf("\033[1;36m");
	printf("\n [Clave] = ");
	printf("\033[0m");
	gets(Buscar.Clave);
	printf("\033[1;36m");
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
		printf("Usuario o Clave incorrectos...");
		
	} else {
		
		system("CLS");
		printf("\033[1;32m");
		printf("Bienvenido [%s]", Dato.ApeNom);
		printf("\033[1;36m");
	}
	
	fclose(Arch);
	
	return Sesion;
	
}

void RegCliente () {
	
	FILE *Arch;
	Fecha Actual;
	Cliente DatoCliente;
	
	Arch = fopen("Clientes.dat", "r+b");
	
	fseek(Arch, 0, SEEK_END);
	
	printf("Ingrese los datos requeridos para el registro");
	printf("\n");
	printf("\n\n[Apellido y Nombre] = ");
	_flushall();
	printf("\033[0m");
	gets(DatoCliente.ApeNom);
	printf("\033[1;36m");
	printf("\n[Domicilio] = ");
	printf("\033[0m");
	gets(DatoCliente.Domicilio);
	printf("\033[1;36m");
	printf("\n[DNI] = ");
	printf("\033[0m");
	scanf("%d", &DatoCliente.DNI);
	printf("\033[1;36m");
	printf("\n[Localidad] = ");
	_flushall();
	printf("\033[0m");
	gets(DatoCliente.Localidad);
	printf("\033[1;36m");
	printf("\n[Fecha de Nacimiento]");
	printf("\n\n\t[Dia - DD] = ");
	printf("\033[0m");
	scanf("%d", &DatoCliente.Fecha_nac.DD);
	printf("\033[1;36m");
	printf("\n\t[Mes - MM] = ");
	printf("\033[0m");
	scanf("%d", &DatoCliente.Fecha_nac.MM);
	printf("\033[1;36m");
	printf("\n\t[Año - AAAA] = ");
	printf("\033[0m");
	scanf("%d", &DatoCliente.Fecha_nac.AAAA);
	printf("\033[1;36m");
	printf("\n\n[Fecha Actual]");
	printf("\n\n\t[Dia - DD] = ");
	printf("\033[0m");
	scanf("%d", &Actual.DD);
	printf("\033[1;36m");
	printf("\n\t[Mes - MM] = ");
	printf("\033[0m");
	scanf("%d", &Actual.MM);
	printf("\033[1;36m");
	printf("\n\t[Año - AAAA] = ");
	printf("\033[0m");
	scanf("%d", &Actual.AAAA);
	
	if (DatoCliente.Fecha_nac.MM < Actual.MM) {
		
		DatoCliente.Edad = Actual.AAAA - DatoCliente.Fecha_nac.AAAA;
		
	} else if (DatoCliente.Fecha_nac.MM == Actual.MM) {
		
		if(DatoCliente.Fecha_nac.DD <= Actual.DD) {
			
			DatoCliente.Edad = Actual.AAAA - DatoCliente.Fecha_nac.AAAA;
			
		} else {
			
			DatoCliente.Edad = (Actual.AAAA - DatoCliente.Fecha_nac.AAAA) - 1;
				
		}
			
	} else if (DatoCliente.Fecha_nac.MM > Actual.MM) {
			
		DatoCliente.Edad = (Actual.AAAA - DatoCliente.Fecha_nac.AAAA) - 1;
			
	}

	printf("\n\n[Peso] = ");
	printf("\033[0m");
	scanf("%f", &DatoCliente.Peso);
	printf("\033[1;36m");
	printf("\n[Telefono] = ");
	_flushall();
	printf("\033[0m");
	gets(DatoCliente.Telefono);
	printf("\033[1;36m");
	fwrite(&DatoCliente, sizeof(Cliente), 1, Arch);
	
	fclose(Arch);
	
}

void RegTurno () {
	
	FILE *Arch;
	Turnos DatoTurno;
	
	Arch = fopen("Turnos.dat", "a+b");
	
	printf("Ingrese los datos requeridos para el registro\n");

	printf("\n\n[ID del profesional] = ");
	printf("\033[0m");
	scanf("%d", &DatoTurno.ID);
	printf("\033[1;36m");	
	printf("\n[Fecha de atencion]");
	printf("\n\n\t[Dia - DD] = ");
	printf("\033[0m");
	scanf("%d", &DatoTurno.FechaTurno.DD);
	printf("\033[1;36m");
	printf("\n\t[Mes - MM] = ");
	printf("\033[0m");
	scanf("%d", &DatoTurno.FechaTurno.MM);
	printf("\033[1;36m");
	printf("\n\t[Año - AAAA] = ");
	printf("\033[0m");
	scanf("%d", &DatoTurno.FechaTurno.AAAA);
	printf("\033[1;36m");
	printf("\n\n[DNI del cliente] = ");
	printf("\033[0m");
	scanf("%d", &DatoTurno.DNI);
	printf("\033[1;36m");
	fwrite(&DatoTurno, sizeof(Turnos), 1, Arch);
	
	fclose(Arch);
	
}

void Listado () {
	
	FILE *Arch;
	Turnos Buscar, Dato;
	bool Existe = false;
	
	Arch = fopen("Atencion.Dat", "r+b");
	
	printf("Ingrese los datos requeridos para la busqueda");
	printf("\n");
	printf("\n\n[ID del profesional] = ");
	scanf("%d", &Buscar.ID);
	printf("\n[Fecha de atencion]");
	printf("\n\n\t[Dia - DD] = ");
	scanf("%d", &Buscar.FechaTurno.DD);
	printf("\n\t[Mes - MM] = ");
	scanf("%d", &Buscar.FechaTurno.MM);
	printf("\n\t[Año - AAAA] = ");
	scanf("%d", &Buscar.FechaTurno.AAAA);
	
	fread(&Dato, sizeof(Turnos), 1, Arch);
	
	while (!feof(Arch)) {
		
		if (Buscar.ID == Dato.ID and Buscar.FechaTurno.DD == Dato.FechaTurno.DD and Buscar.FechaTurno.MM == Dato.FechaTurno.MM and Buscar.FechaTurno.AAAA == Dato.FechaTurno.AAAA) {
			
			system("CLS");
			
			printf("\n Lista de atencion");
			
			printf("\n\n[ID del profesional] -> %d", Dato.ID);
			printf("\n[Fecha de atencion] -> %d/%d/%d", Dato.FechaTurno.DD, Dato.FechaTurno.MM, Dato.FechaTurno.AAAA);
			printf("\n[DNI del cliente] -> %d", Dato.DNI);
			printf("\n[Diagnostico] -> %s\n\n\n", Dato.DetalleAtencion);
			
			Existe = true;
			
			system("PAUSE");
			
		}
		
		fread(&Dato, sizeof(Turnos), 1, Arch);
		
	}
	
	fclose(Arch);
	
	if (!Existe) {
		
		system("CLS");
		
		printf("No hay registros de atencion aun...");
		
	}
	
}
