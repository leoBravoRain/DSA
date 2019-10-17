#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

#define N_NOM 12
#define N_APEL 8
#define N_PAIS 10
#define MIM_EDAD 16
#define MAX_EDAD 45
#define N_SCORE 7

const char NOMBRE[N_NOM][10] = {"Pedro", "Juan", "Manuel", "Diego", "Agustín", "Ismael", "Jesús", "Ernesto", "Bryan", "Crístian", "Camilo", "Raúl"};
const char APELLIDO[N_APEL][10] = {"Torres", "Campos", "Acosta", "Aguirre", "Molina", "Silva", "Rios", "Castillo"};
const char PAIS[N_PAIS][10] = {"Argentina", "Bolivia", "Brasil", "Chile", "Colombia", "Ecuador", "Paraguay", "Perú", "Uruguay", "Venezuela"};
const char SET_GANADO[N_SCORE][4] = {"6-0", "6-1", "6-2", "6-3", "6-4", "7-5", "7-6"};
const char SET_PERDIDO[N_SCORE][4] = {"0-6", "1-6", "2-6", "3-6", "4-6", "5-7", "6-7"};

struct Player{
	// llenar con datos aleatorios desde los arreglos de cabecera
	int ID;	// un correlativo que parte de 0, corresponde a la posición de la celda
	int nombre[4];	// almacena los ID's de sus 2 nombres (dos primera celdas) y sus dos apellidos (las dos siguientes)
	int edad;		// valor aleatorio en el rango [MIN_EDAD..MAX_EDAD]
	char pais[10];  // almacena el nombre completo del país
};

void genJugadores(Player *J, int n);
void genScores(Player *J, int k, int *Ganador, int *Perdedor, int *SetPerdido, int **Score);

int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./torneo n (n potencia de 2)" << endl;
		exit(EXIT_FAILURE);
	}

	int i, j, n=atoi(argv[1]);
	Player *J = new Player[n];	// arreglo con los n jugadores

	// creación de datos aleatorios
	genJugadores(J, n);

	cout << " Listado de los " << n << " Jugadores..." << endl;
	for (i=0; i<n; i++){
		cout << "ID        : " << J[i].ID << endl;
		cout << "Nombres   : " << NOMBRE[J[i].nombre[0]] << " " << NOMBRE[J[i].nombre[1]] << endl;
		cout << "Apellidos : " << APELLIDO[J[i].nombre[2]] << " " << APELLIDO[J[i].nombre[3]] << endl;
		cout << "Edad      : " << J[i].edad << endl;
		cout << "País      : " << J[i].pais << endl;
		cout << endl;
	}

	// Arreglos para registrar los resultados de los n/2 enfrentamientos...
	int *Ganador = new int[n/2];	// almacena el ID de los n/2 ganadores (No se pueden repetir los ID)
	int *Perdedor = new int[n/2];	// almacena el ID de los n/2 perdedores (No se pueden repetir los ID)
	int *SetPerdido = new int[n/2]; // si el ganador perdio un set, aquí se indica cual set perdío el ganador {0, 1, 2}
	int **Score = new int*[n/2]; // matriz de n/2 por 3 que almacena los Id de los resultados para cada uno de los 3 sets
	for (i=0; i<n/2; i++)
		Score[i] = new int[3]; // se crean las 3 columnas de cada fila de la matriz

	// Score[i][j] almacena un entero aleatorio que describe el resultado del set.
	// Si el ganador del match i ganó el set j, entonces es proveniente de SET_GANADO
	// Si el ganador del match i perdió el set j, entonces es proveniente de SET_PERDIDO

	// genera los scores válidos y aleatorios para los n/2 partidos
	genScores(J, n, Ganador, Perdedor, SetPerdido, Score);

	cout << endl << "Resultados de los " << n/2 << " enfrentamientos..." << endl;
	for (i=0; i<n/2; i++){
		cout << "# Match " << i+1 << ". ";
		cout << "ID Ganador: " << Ganador[i] <<", "<< NOMBRE[J[Ganador[i]].nombre[0]] <<" "<< APELLIDO[J[Ganador[i]].nombre[2]] << endl;
		cout << "           ID Perdedor: " << Perdedor[i] <<", "<< NOMBRE[J[Perdedor[i]].nombre[0]] <<" "<< APELLIDO[J[Perdedor[i]].nombre[2]] << endl;
		j = 2;
		if(SetPerdido[i])
			j++;
		cout << "Score a " << j << " sets: ";
		switch (SetPerdido[i]) { // este es el numero del set que el ganador perdío (si es que erdió alguno)
		case 0: // ganó los dos primeros y no hubo tercero
			cout << SET_GANADO[Score[i][0]] <<"; "<< SET_GANADO[Score[i][1]] << endl;
			break;
		case 1: // perdió el primero
			cout << SET_PERDIDO[Score[i][0]] <<"; "<< SET_GANADO[Score[i][1]] <<"; "<< SET_GANADO[Score[i][2]] << endl;
			break;
		case 2: // perdió el segundo
			cout << SET_GANADO[Score[i][0]] <<"; "<< SET_PERDIDO[Score[i][1]] <<"; "<< SET_GANADO[Score[i][2]] <<  endl;
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}

 
// (2.0 Pts.) generar n jugadores con dos nombres (diferentes) y 2 apellidos aleatorios desde los arreglos globales
void genJugadores(Player *J, int n){

	int a, b, c, d;

	// J[0].pais = PAIS[0][0];
	// // printf("%s\n", PAIS[0]);
	// cout << PAIS[0][0] << endl;

	// srand (time(NULL));

	for (int i = 0; i < n; ++i)
	{

		// pick up 2 differents random numbers for names
		a = rand() % N_NOM;
		b = a;

		while (a == b) {

			b = rand() % N_NOM;

		}

		// random for surnames
		c = rand() % N_APEL;
		d = rand() % N_APEL;

		// assign values
		// ID
		J[i].ID = i;

		// names
		J[i].nombre[0] = a; 
		J[i].nombre[1] = b; 
		J[i].nombre[2] = c;
		J[i].nombre[3] = d;


		// edad
		J[i].edad = MIM_EDAD + rand() % (MAX_EDAD - MIM_EDAD);

		// pais
		// i dont knwo whyt this does not work !
		// J[i].pais = PAIS[rand() % N_PAIS];

	}

}

// Crea la matriz de resultados para los n/2 enfrentamientos
// (2.0 Pts) por llenar bien los arreglos Ganador[] y Perdedor[]	
// (2.0 Pts) por llenar bien el arreglo SetPerdido[] y la matriz Score[]	
void genScores(Player *J, int n, int *Ganador, int *Perdedor, int *SetPerdido, int **Score){

	int k;
	
	// Crer arreglo de ganadores
	// deberia ser aleatorio !!!
	for (int i = 0; i < n/2, ++i)
	{

		// k = rand() % n;

		Ganador[i] = i; 

	}

	// Crear arreglo de perdedores
	// deberia ser aleatorio !!!
	for (int i = n/2; i < n, ++i)
	{
		// k = rand() % n;

		Perdedor[i - n/2] = i; 

	}

	// Crear matriz de scores
	for (int i = 0; i < n/2; ++i)
	{

		// crear arreglo para almacenar que partidos son ganados y perdidos

		// almacenar scores
		int scores [3] = {

			rand() % N_SCORE,
			rand() % N_SCORE,
			rand() % N_SCORE,

		};

		// almacenar scores en arreglo
		Score[i] = scores;

		// Rellenar SET Perdido
		// Iterar sobre arreglo complementario y analizar si set es perido, si es perdido rellenar en arreglo SetPerdido el set que rperdió
		
		// por tiemp no alcanze a hacer mas!
	}


}
