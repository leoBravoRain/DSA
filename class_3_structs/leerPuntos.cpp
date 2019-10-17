// El siguiente ejemplo, leerPuntos.cpp, lee un archivo de texto que contiene puntos en dos dimensiones,
// en donde por cada linea sus coordenadas x e y están separadas por un espacio en blanco. Por ejemplo,
// el siguiente archivo contiene 3 puntos:
// 2.5 6.8
// 0 456.78
// 2.876 7.1
// Entonces, leerPuntos.cpp recibe por parámetro el nombre (con ruta) de su archivo de puntos, ejecuta
// una función: int readPoints(char filePoints[400]); la cual lee e imprime sus puntos, lína por línea, y
// retorna la cantidad de puntos que encontró.
// Ud deberá trabajar sobre este fuente y proponer una estructura para almacenar sus puntos (x,y),
// compile con "make puntos" y ejecute: "./punto ./puntos.txt"

// luego compile con "make structPuntos" y ejecute con "./puntos ./puntos.txt"

#include <iostream>    // para la entrada y salida
#include <fstream>     // para trabajar con archivos
#include <string.h>    // para trabajar con string
#include <stdlib.h>    // para usar atof()

using namespace std;

struct Puntos{
	float x;
	float y;
};

void readPoints(char filePoints[400], Puntos **P, int *nP);

// El nombre del archivo de puntos es pasado por argumento al programa
int main(int argc, char *argv[]){
	char archivo[400];
	Puntos *P;
	int n;

	if(argc != 2){
		cout << "¡ERROR CON PARAMETROS! " << endl;
		cout << "… debe de dar el nombre (con ruta incluida) del archivo de puntos " << endl;
		exit(1);
	}

	cout << "Leer archivo de puntos" << endl;
	strcpy(archivo, argv[1]);
	readPoints(archivo, &P, &n);

	// Ahora imprima los puntos...
	cout << "Puntos en la estructura..." << endl;
	for (int i=0; i<n; i++)
		cout << i << "(" << P[i].x << ", " << P[i].y << ")" << endl;

	cout << endl << "OK :)" << endl;
	return 0;
}

// Este método lee línea a línea los puntos en el archivo y extreae sus coordenadas x e y
void readPoints(char filePoints[400], Puntos **P, int *nP){
	int i, len, k;
	ifstream infile;
	string line;

	infile.open(filePoints);
	if(!infile){	// validamos que el archivo exista
		cerr << "Error, Archivo no encontrado: " << filePoints << endl;
		exit(EXIT_FAILURE);
	}

	// contamos las lineas del archivo...
	i=0;
	while(infile.good()) {
		getline(infile, line);
		cout << line << endl;
		if (!line.length())
			break; 	// fin de archivo
		i++;
	}
	cout << "...contiene " << i << " filas" << endl;
	infile.close();
	*nP = i;

	// creamos el arreglo de Puntos
	*P = new Puntos[*nP];
	Puntos *A = *P;			 // es para usar A[k].x en vez de (*P)[k].x

	infile.open(filePoints);

	// guardamos cada punto en una celda de P[]
	for (k=0; k<*nP; k++){
		getline(infile, line);
		for (i=1; line[i]!=' '; i++);
		A[k].x = atof(line.substr(0,i).c_str());
		len = line.length()-i-1;
		A[k].y = atof(line.substr(i+1,len).c_str());
	}

	infile.close();
	cout << k << " puntos leidos!" << endl;
}
