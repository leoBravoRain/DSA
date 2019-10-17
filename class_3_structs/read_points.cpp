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

// El nombre del file_path de puntos es pasado por argumento al programa
#include <iostream>    // para la entrada y salida
#include <fstream>     // para trabajar con archivos
#include <string.h>    // para trabajar con string
#include <stdlib.h>    // para trabajar con string

struct point{
    float x;
    float y;
};

using namespace std;

void read_points(char * file_path, point ** points, int * n);
void findExtremes(point *P, int n, int *up, int *down);
point central(point *P, int n);
void losMasCercanos(point *P, int n, point q, int p_manh, int * p_real);

int main(int argc, char *argv[]){

    char file_path[400];

    srand(time(NULL));

    point *points;
    int n = 0;

    // idx of min
    int down = 0;
    // idx of max
    int up = 0;

    // q point
    point q;
    // q.x = rand() % 100;
    q.x = 50;
    // q.y = rand() % 100;
    q.y = 50;
    int p_real;

    printf("q: %f, %f\n", q.x, q.y);
    
    strcpy(file_path, argv[1]);

    read_points(file_path, &points, &n);

    // printf("%i\n", n);
    findExtremes(points, n, &up, &down);

    central(points, n);

    losMasCercanos(points, n, q, 0, &p_real);

    return 0;
}

void read_points(char * file_path, point ** points, int *n)
{
    ifstream infile;
	string line;

    // red file
    infile.open(file_path);

    // count lines
    int i=0;
	while(infile.good()) {
		getline(infile, line);
		// cout << line << endl;
		if (!line.length())
			break; 	// fin de archivo
		i++;
	}
    
    // cout << points << endl;

    infile.close();
    // number of points
    // int n = i;
    *n = i;
    // create array of points
    *points = new point [*n];

    // printf("n: %i\n", n);

    float x, y;
    int len;

    infile.open(file_path);

    for (int j = 0; j < *n; j++)
    {
        // cout << j << endl;
        getline(infile, line);
        // cout << line << endl;
		for (i=1; line[i]!=' '; i++);
		x = atof(line.substr(0,i).c_str());
		len = line.length()-i-1;
		y = atof(line.substr(i+1,len).c_str());
        // cout << x << " " << y << endl;
        (*points)[j].x = x;
        (*points)[j].y = y;
        // points[j]->y = y;
    }

    infile.close();

    printf("printin points array\n");

    // print points
    for (int i = 0; i < *n; i++)
    {
        cout << (*points)[i].x << " " << (*points)[i].y << endl;
    }
}

// E4.- Cree el procedimiento void findExtremes(Puntos *P, int n, int *left, int *right, int *up, int *down)
// que encuentras los puntos extremos del arreglo P[0..n-1], dejando el índice de la celda de P en cada
// caso. Así en P[up] está el punto más alto, en P[down] el más bajo, etc.
void findExtremes(point *P, int n, int *up, int *down)
{
    int min = 100000000000000000000;
    int max = -1;
    // int down = -1;
    
    // euclidean distance
    int euclidean_distance_2 = 0;

    // iterate through each point
    for (int i = 0; i < n; i++)
    {
        // compute distance from (0,0)
        euclidean_distance_2 = P[i].x*P[i].x + P[i].y*P[i].y;

        // printf("euclidean distance in %i: %i\n", i, euclidean_distance_2);

        // check if it's smaller than minimun
        if (euclidean_distance_2 < min)
        {
            min = euclidean_distance_2;
            *down = i;
            // printf("new min: %i\n", *down);
        }
        else if (euclidean_distance_2 > max)
        {
            max = euclidean_distance_2;
            *up = i;
            // printf("new max: %i\n", *down);
        }
    }

    printf("Min: %i | Max: %i\n", *down, *up);

}

// E5.- Cree el procedimiento Puntos central(Puntos *P, int n) que determina el centroide de los n puntos
// almacenados en P, es decir el punto promedio.
point central(point *P, int n)
{

    float sum_x = 0;
    float sum_y = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum_x += P[i].x;
        sum_y += P[i].y;
    }

    point p;
    p.x = (float)sum_x/(float)n;
    p.y = (float)sum_y/(float)n;

    printf("Centroid: (%f, %f)\n", p.x, p.y);

    return p;
}

// E6.- Cree el procedimiento void losMasCercanos(Puntos *P, int n, Puntos q, int p_manh, int p_real)
// que encuentra, utilizando la distancia de Manhattan, cual es él indice del punto más cercano a q,
// dejandolo en p_manh; y en p_real el punto más cercano a q según la distancia euclidea (calculando el
// segmento con aritmética flotante).
void losMasCercanos(point *P, int n, point q, int p_manh, int *p_real)
{

    
    // p_real = 1000000000000000000000000000;
    float euclidean_distance_2 = 0;
    float min = 1000000000000000000000;

    for (int i = 0; i < n; i++)
    {
        euclidean_distance_2 = (P[i].x - q.x)*(P[i].x - q.x) + (P[i].y - q.y)*(P[i].y - q.y);

        // printf("euclidean distance: %f\n", euclidean_distance_2);

        // if it's smaller
        if (euclidean_distance_2 < min)
        {
            // printf("new min\n");
            min = euclidean_distance_2;
            *p_real = i;
        }
    }

    printf("min to q (%f, %f): %i\n", q.x, q.y, *p_real);

}