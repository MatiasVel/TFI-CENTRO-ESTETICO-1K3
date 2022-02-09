void Crear(){
	
	FILE *Arch = fopen("Clientes.dat", "r+b");
	
	if(!Arch) {
		
		fclose(Arch);
		
		Arch = fopen("Clientes.dat", "w+b");
		
	}
	
	fclose(Arch);
	
	Arch = fopen("Turnos.dat", "r+b");
	
	if(!Arch) {
		
		fclose(Arch);
		
		Arch = fopen("Turnos.dat", "w+b");
		
	}
	
	fclose(Arch);
	
	Arch = fopen("Profesionales.dat", "r+b");
	
	if(!Arch) {
		
		fclose(Arch);
		
		Arch = fopen("Profesionales.dat", "w+b");
		
	}
	
	fclose(Arch);
	
	Arch = fopen("Profesionales-Info.dat", "r+b");
	
	if(!Arch) {
		
		fclose(Arch);
		
		Arch = fopen("Profesionales-Info.dat", "w+b");
		
	}
	
	fclose(Arch);
	
	Arch = fopen("Recepcionistas.dat", "r+b");
	
	if(!Arch) {
		
		fclose(Arch);
		
		Arch = fopen("Recepcionistas.dat", "w+b");
		
	}
	
	fclose(Arch);
	
	Arch = fopen("Atencion.dat", "r+b");
	
	if(!Arch) {
		
		fclose(Arch);
		
		Arch = fopen("Atencion.dat", "w+b");
		
	}
	
	fclose(Arch);
	
}

struct Fecha {
	
	int DD;
	int MM;
	int AAAA;
	
};

struct Turnos {
	
	char DetalleAtencion[381];
	int DNI;
	int ID;
	char ApeNom[60];
	Fecha FechaTurno;
	
};

struct Usuario {
	
	char Usuario[60];
	char Clave[60];
	char ApeNom[60];
	int ID;
	
};

struct Profesional {
	
	char ApeNom[60];
	int DNI;
	int ID;
	char Telefono[15];
	
};

struct Cliente {
	
	char ApeNom[60];
	char Domicilio[60];
	int DNI;
	char Localidad[60];
	float Peso;
	Fecha Fecha_nac;
	char Telefono[25];
	int Edad;
	
};
