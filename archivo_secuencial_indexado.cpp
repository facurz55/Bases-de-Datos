#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Constantes para definir los límites del archivo
const int PMAX = 10;  // Tamaño máximo del área primaria
const int OMAX = 20;  // Tamaño máximo del área total (incluyendo Overflow)
const int OVER = PMAX + 1;  // Inicio del área de Overflow
const int N = 3;  // Cantidad de registros por bloque
const int MAX_INDICE = PMAX / N;  // Máximo número de entradas en la tabla de índices

// Estructura que define un Registro
struct Registro {
	int clave;          // Clave única del registro
	string datos;       // Datos almacenados en el registro
	int direccion;      // Dirección a un registro en overflow (-1 si no existe)
};

// Estructura que define un Indice para bloques
struct Indice {
	int clave;          // Clave más baja del bloque
	int dir;            // Dirección del primer registro del bloque
};

// Variables globales
Registro archivo[OMAX];  // Arreglo principal que simula el archivo completo
Indice indice[MAX_INDICE];   // Tabla de índices

// Prototipos de funciones
void inicializarArchivo();
void mostrarArchivo();
void consulta(int clave);
void insercion(int clave, const string& datos);
int buscarIndice(int clave);

int main() {
	inicializarArchivo();
	int opcion, clave;
	string datos;
	
	while (true) {
		// Menú principal
		cout << "\nMENU:\n1. Consultar Registro\n2. Insertar Registro\n3. Mostrar Archivo\n4. Salir\nIngrese una opción: ";
		cin >> opcion;
		
		if (opcion == 1) {
			cout << "Ingrese la clave a consultar: ";
			cin >> clave;
			consulta(clave);
		} else if (opcion == 2) {
			cout << "Ingrese la clave a insertar: ";
			cin >> clave;
			cout << "Ingrese los datos: ";
			cin.ignore();
			getline(cin, datos);
			insercion(clave, datos);
		} else if (opcion == 3) {
			mostrarArchivo();
		} else if (opcion == 4) {
			return 0;
		} else {
			cout << "Opción inválida." << endl;
		}
	}
}

void inicializarArchivo() {
	for (int i = 1; i <= OMAX; ++i) {
		archivo[i] = {0, "", -1};
	}
	indiceCount = 0;
}

void mostrarArchivo() {
	cout << "\nContenido del archivo:" << endl;
	for (int i = 1; i <= OMAX; ++i) {
		if (archivo[i].clave != 0) {
			cout << "Posición " << i << " - Clave: " << archivo[i].clave << ", Datos: " << archivo[i].datos;
			if (archivo[i].direccion != -1) {
				cout << ", Dirección: " << archivo[i].direccion;
			}
			cout << endl;
		}
	}
	
	cout <<endl<< "Indice:" << endl;
	for (int i = 0; i < indiceCount; ++i) {
		cout << "Clave: " << indice[i].clave << " -> Dirección: " << indice[i].dir << endl;
	}
}

///CORREGIR
int buscarIndice(int clave) {
	
}

///CORREGIR
void consulta(int clave) {
	// Encuentra la dirección del bloque
	
	// Buscar en el bloque principal
	
	// Buscar en área de Overflow
	
}

///CORREGIR
void insercion(int clave, const string& datos){
	
	// Contar registros en el bloque y verificar si hay espacio
	
	// Si el bloque está medio lleno o más, crear un nuevo bloque
	
	// Insertar en área de Overflow
	
}



