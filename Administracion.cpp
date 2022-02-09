//Modulo Administracion

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "Centro_estetico.h"

bool VerificarUsuario (Usuario Dato, int RP);

bool VerificarClave (Usuario Dato);

void RegPro ();

void RegRecep ();

void Atenciones ();

void Ranking ();


main () {

	setlocale(LC_ALL, "");

	Crear();
	
	int Opcion = 0, Ingreso;
	
	do {
		
		system("CLS");
		
		printf("Modulo Administracion");
		printf("\n");
		printf("\n\n 1.- Registrar Profesional");
		printf("\n 2.- Registrar Usuario Recepcionista");
		printf("\n 3.- Atenciones por Profesional");
		printf("\n 4.- Ranking de Profesionales por Atenciones");
		printf("\n\n 5.- Cerrar la Aplicacion");
		printf("\n\nIngrese una Opcion: ");
		scanf("%d", &Opcion);
		
		Ingreso = 1;
		
		switch (Opcion) {
			
			case 1:
				
				while (Ingreso == 1) {
						
					system("CLS");
				
					RegPro();
					
					system("CLS");
					
					printf("¿continuar registrando Profesionales?");
					printf("\n\n [0] => No, Salir");
					printf("\n [1] => Si, continuar");
					printf("\n\n==> ");
					scanf("%d", &Ingreso);
						
				}
				
			break;
			
			case 2:
				
				while (Ingreso == 1) {
						
					system("CLS");
				
					RegRecep();
					
					system("CLS");
					
					printf("¿continuar registrando Usuarios recepcionistas?");
					printf("\n\n [0] => No, Salir");
					printf("\n [1] => Si, continuar");
					printf("\n\n==> ");
					scanf("%d", &Ingreso);
						
				}
				
			break;
			
			case 3:
				
				system("CLS");
				
				Atenciones();
				
			break;
			
			case 4:
				
				system("CLS");
				
				Ranking();
				
			break;
			
		}
		
		printf("\n\n\n");
		
		system("PAUSE");
		
	} while (Opcion != 5);

}



bool VerificarUsuario (Usuario Dato, int RP) {
	
	FILE *Aux;
	Usuario Verificar;
	bool Cond = true;
	int j = 0;
	
	if (RP == 0) {
		
		Aux = fopen("Profesionales.dat", "r+b");
		
	} else if (RP == 1) {
	
		Aux = fopen("recepcionistas.dat", "r+b");
	
	}
	
	if (strlen(Dato.Usuario) < 6 or strlen(Dato.Usuario) > 10) {
		
		Cond = false;
		
		printf("\nEl Usuario debe tener entre 6 y 10 caracteres\n");
		
	}
	
	fread(&Verificar, sizeof(Usuario), 1, Aux);
	
	while (!feof(Aux)) {
		
		if (strcmp(Verificar.Usuario, Dato.Usuario) == 0) {
			
			Cond = false;
			
			printf("\nEl Usuario ingresado ya existe\n");
			
			break;
			
		}
		
		fread(&Verificar, sizeof(Usuario), 1, Aux);
		
	}
	
	if (Dato.Usuario[0] >= 'a' and Dato.Usuario[0] <= 'z') {
		
		
		
	} else {
		
		Cond = false;
		
		printf("\nEl Usuario debe comenzar con una minuscula\n");
		
	}
	
	for (int i = 0; i < strlen(Dato.Usuario); i++) {
		
		if (Dato.Usuario[i] >= 'A' and Dato.Usuario[i] <= 'Z') {
			
			j++;
			
		}
		
	}
	
	if (j < 2) {
		
		Cond = false;
		
		printf("\nEl Usuario debe contener 2 o más mayusculas\n");
		
	}
	
	j = 0;
	
	for (int i = 0; i < strlen(Dato.Usuario); i++) {
		
		if (Dato.Usuario[i] >= '0' and Dato.Usuario[i] <= '9') {
			
			j++;
			
		}
		
	}
	
	if (j > 3) {
		
		Cond = false;
		
		printf("\nEl Usuario no puede contener más de 3 números\n");
		
	}
	
	fclose(Aux);
	
	if (!Cond) {
		
		printf("\n\n\n");
	
		system("PAUSE");
		
	}
	
	return Cond;
	
}

bool VerificarClave (Usuario Dato) {
	
	bool Cond = true, Mayus = false, Minus = false, Num = false;
	int Size = strlen(Dato.Clave);
	
	for (int i = 0; i < Size; i++) {
		
		if (Dato.Clave[i] >= 'A' and Dato.Clave[i] <= 'Z') {
			
			Mayus = true;
			
		} else if (Dato.Clave[i] >= 'a' and Dato.Clave[i] <= 'z') {
			
			Minus = true;
			
		} else if (Dato.Clave[i] >= '0' and Dato.Clave[i] <= '9') {
			
			Num = true;
			
		}
		
	}
	
	if (!Mayus or !Minus or !Num) {
		
		Cond = false;
		
		printf("\nLa Clave debe contener una mayuscula, una minusculas y un número\n");
		
	}
	
	for (int i = 0; i < Size; i++) {
		
		if (Dato.Clave[i] >= 'A' and Dato.Clave[i] <= 'Z') {
			
			
			
		} else if (Dato.Clave[i] >= 'a' and Dato.Clave[i] <= 'z') {
			
			
			
		} else if (Dato.Clave[i] >= '0' and Dato.Clave[i] <= '9') {
			
			
			
		} else {
			
			Cond = false;
			
			printf("\nLa Clave solo puede contener caracteres alfanumericos (Nada de signos)\n");
			
		}
		
		
	}
	
	if (Size < 6 or Size > 32) {
		
		Cond = false;
		
		printf("\nLa Clave debe tener entre 6 y 32 caracteres\n");
		
	}
	
	for (int i = 0; i < (Size-2); i++) {
		
		if (Dato.Clave[i] >= '0' and Dato.Clave[i] <= '9') {
			
			if (Dato.Clave[i+1] >= '0' and Dato.Clave[i+1] <= '9') {
				
				if (Dato.Clave[i+2] >= '0' and Dato.Clave[i+2] <= '9') {
					
					Cond = false;
					
					printf("\nLa Clave no puede tener 3 números seguidos\n");
					
				}
				
			}
			
		}
		
	}
	
	for (int i = 0; i < (Size-1); i++) {
		
		if (Dato.Clave[i] >= 'A' and Dato.Clave[i] <= 'Y') {
			
			if (Dato.Clave[i+1] == (Dato.Clave[i] + 1) or Dato.Clave[i+1] == (Dato.Clave[i] + 33)) {
				
				Cond = false;
				
				printf("\nLa Clave no debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas \n");
				
			}
			
		} else if (Dato.Clave[i] >= 'a' and Dato.Clave[i] <= 'y') {
			
			if (Dato.Clave[i+1] == (Dato.Clave[i] + 1) or Dato.Clave[i+1] == (Dato.Clave[i] - 31)) {
				
				Cond = false;
				
				printf("\nLa Clave no debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas \n");
				
			}
			
		}
		
	}
	
	if (!Cond) {
		
		printf("\n\n");
		
		system("PAUSE");
		
	}
	
	return Cond;
	
}

void RegPro () {
	
	FILE *Arch, *Info;
	Profesional DatoPro;
	Usuario UsuPro;
	int Opcion = 0, RP = 0;
	
	Arch = fopen("Profesionales.dat", "r+b");
	Info = fopen("Profesionales-Info.dat", "r+b");
	
	fseek(Arch, 0, SEEK_END);
	fseek(Info, 0, SEEK_END);
	
	printf("Ingrese los datos requeridos para el registro");

	printf("\n\n[Apellido y Nombre] = ");
	_flushall();
	gets(DatoPro.ApeNom);
	printf("\n[ID Profesional] = ");
	scanf("%d", &DatoPro.ID);
	printf("\n[DNI del Profesional] = ");
	scanf("%d", &DatoPro.DNI);
	printf("\n[Telefono] = ");
	_flushall();
	gets(DatoPro.Telefono);
	
	system("CLS");
	
	printf("Ingrese los datos requeridos para continuar con el registro");
	
	
	strcpy(UsuPro.ApeNom, DatoPro.ApeNom);
	UsuPro.ID = DatoPro.ID;
	printf("\n\n[Usuario del Profesional] = ");
	_flushall();
	gets(UsuPro.Usuario);
	
	while (!VerificarUsuario(UsuPro, RP)) {
		
		system("CLS");
		
		printf("No se cumplieron las condiciones para la creacion del Usuario");
		printf("\n¿Reintentar?");
		printf("\n\n[0] = No, Salir");
		printf("\n[1] = Si, Reintentar");
		printf("\n\n==> ");
		scanf("%d", &Opcion);
		
		if (Opcion == 0) {
			
			fclose(Arch);
			
			return;
			
		}
		
		system("CLS");
		
		printf("Ingrese los datos requeridos para continuar con el registro");
		
		printf("\n\n[Usuario del Profesional] = ");
		_flushall();
		gets(UsuPro.Usuario);
		
	}
	
	printf("\n[Clave del Profesional] = ");
	_flushall();
	gets(UsuPro.Clave);
	
	while (!VerificarClave(UsuPro)) {
		
		system("CLS");
		
		printf("No se cumplieron las condiciones para la creacion de la contraseña");
		printf("\n¿Reintentar?");
		printf("\n\n[0] = No, Salir");
		printf("\n[1] = Si, Reintentar");
		printf("\n\n==> ");
		scanf("%d", &Opcion);
		
		if (Opcion == 0) {
			
			fclose(Arch);
			
			return;
			
		}
		
		system("CLS");
		
		printf("Ingrese los datos requeridos para continuar con el registro");
	
		printf("\n\n[Usuario] = %s", UsuPro.Usuario);
		printf("\n[Clave] = ");
		_flushall();
		gets(UsuPro.Clave);
		
	}
	
	fwrite(&DatoPro, sizeof(Profesional), 1, Info);
	fwrite(&UsuPro, sizeof(Usuario), 1, Arch);
	
	fclose(Info);
	fclose(Arch);
	
}

void RegRecep () {
	
	FILE *Arch;
	Usuario DatoRecep;
	int Opcion = 0, RP = 1;
	
	Arch = fopen("recepcionistas.dat", "r+b");
	
	fseek(Arch, 0, SEEK_END);
	
	printf("Ingrese los datos requeridos para el registro");
	
	printf("\n\n[Usuario] = ");
	_flushall();
	gets(DatoRecep.Usuario);
	
	while (!VerificarUsuario(DatoRecep, RP)) {
		
		system("CLS");
		
		printf("No se cumplieron las condiciones para la creacion del Usuario");
		printf("\n¿Reintentar?");
		printf("\n\n[0] = No, Salir");
		printf("\n[1] = Si, Reintentar");
		printf("\n\n==> ");
		scanf("%d", &Opcion);
		
		if (Opcion == 0) {
			
			fclose(Arch);
			
			return;
			
		}
		
		system("CLS");
		
		printf("Ingrese los datos requeridos para el registro");
		
		printf("\n\n[Usuario] = ");
		_flushall();
		gets(DatoRecep.Usuario);
		
	}
	
	printf("[Clave] = ");
	_flushall();
	gets(DatoRecep.Clave);
	
	while (!VerificarClave(DatoRecep)) {
		
		system("CLS");
		
		printf("No se cumplieron las condiciones para la creacion de la contraseña");
		printf("\n¿Reintentar?");
		printf("\n\n[0] = No, Salir");
		printf("\n[1] = Si, Reintentar");
		printf("\n\n==> ");
		scanf("%d", &Opcion);
		
		if (Opcion == 0) {
			
			fclose(Arch);
			
			return;
			
		}
		
		system("CLS");
		
		printf("Ingrese los datos requeridos para el registro");
		printf("\n\n[Usuario] = %s", DatoRecep.Usuario);
		printf("\n[Clave] = ");
		_flushall();
		gets(DatoRecep.Clave);
		
	}
	
	printf("[Apellido y Nombre] = ");
	gets(DatoRecep.ApeNom);
	
	fwrite(&DatoRecep, sizeof(Usuario), 1, Arch);
	
	fclose(Arch);
	
}

void Atenciones () {
	
	FILE *Arch, *Pro;
	Fecha Actual;
	Turnos Dato;
	Profesional Buscar;
	int ID, Atencion = 0;
	bool existe = false;
	
	Arch = fopen("Atencion.dat", "r+b");
	Pro = fopen("Profesionales-Info.dat", "r+b");
	
	if (!Arch) {
			
		printf("No hay registros disponibles Aun...");
		
		return;
			
	}
	
	printf("Ingrese los datos requeridos: ");
	printf("\n\n[Mes Actual - MM] = ");
	scanf("%d", &Actual.MM);
	printf("\n[Año Actual - AAAA] = ");
	scanf("%d", &Actual.AAAA);
	
	system("CLS");
	
	fread(&Buscar, sizeof(Profesional), 1, Pro);
	
	while (!feof(Pro)) {
		
		Atencion = 0;
		
		rewind(Arch);
		
		fread(&Dato, sizeof(Turnos), 1, Arch);
		
		while (!feof(Arch)) {
			
			if (Actual.MM == Dato.FechaTurno.MM and Actual.AAAA == Dato.FechaTurno.AAAA and Buscar.ID == Dato.ID) {
				
				Atencion++;
				
				existe = true;
				
			}
			
			fread(&Dato, sizeof(Turnos), 1, Arch);
			
		}
		
		printf("El Profesional (%s) Realizo (%d) Atenciones Durante el mes.\n\n", Buscar.ApeNom, Atencion);
		
		fread(&Buscar, sizeof(Profesional), 1, Pro);
		
	}
	
	fclose(Pro);
	fclose(Arch);
	
	if (!existe) {
		
		printf("No hay registros disponibles Aun...");
		
		return;
		
	}
	
}

void Ranking () {
	
	FILE *Arch, *Pro;
	Turnos Dato;
	Fecha Actual;
	Profesional Buscar, bono;
	int Atencion = 0, Mayor = 0;
	
	Arch = fopen("Atencion.dat", "r+b");
	Pro = fopen("Profesionales-Info.dat", "r+b");
	
	if (!Arch) {
			
		printf("No hay registros disponibles Aun...");
		
		return;
			
	}
	
	printf("Ingrese los datos requeridos: ");
	printf("\n\n[Mes Actual - MM] = ");
	scanf("%d", &Actual.MM);
	printf("\n[Año Actual - AAAA] = ");
	scanf("%d", &Actual.AAAA);
	
	fread(&Buscar, sizeof(Profesional), 1, Pro);
	
	bono = Buscar;
	
	while (!feof(Pro)) {
		
		fread(&Dato, sizeof(Turnos), 1, Arch);
		
		Atencion = 0;
		
		while (!feof(Arch)) {
			
			if (Actual.MM == Dato.FechaTurno.MM and Actual.AAAA == Dato.FechaTurno.AAAA and Buscar.ID == Dato.ID) {
				
				Atencion++;
				
			}
			
			fread(&Dato, sizeof(Turnos), 1, Arch);
			
		}
		
		if (Atencion > Mayor) {
			
			Mayor = Atencion;
			bono = Buscar;
			
		}
		
		fread(&Buscar, sizeof(Profesional), 1, Pro);
		
	}
	
	system("CLS");
	
	printf("El Profesional que recibira el bono mensual con (%d) Atenciones es: ", Mayor);
	printf("\n\n[Apellido y Nombre] => %s", bono.ApeNom);
	printf("\n[ID] => %d", bono.ID);
	printf("\n[DNI] => %d", bono.DNI);
	printf("\n[Telefono] => %s", bono.Telefono);
	
	fclose(Pro);
	fclose(Arch);
	
}
