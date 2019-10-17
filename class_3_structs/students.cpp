#include <stdlib.h>
#include <iostream>
#include <string.h>

#define N_CAR 3
#define N_NOM 5
#define N_APEL 10
#define MIN_EDAD 17
#define MAX_EDAD 49

// existen 4 arreglos constantes, es decir arreglos cuyos valores
// almacenados no varian durante la ejecución del programa. Estos son:

const char ellos[N_NOM][10] = {"Pedro", "Juan", "Manuel", "Diego", "Agustin"};
const char ellas[N_NOM][10] = {"Maria", "Claudia", "Josefina", "Paola", "Linda"};
const char apel[N_APEL][10] = {"Torres", "Flores", "Campos", "Acosta", "Aguirre", "Molina", "Silva", "Rojas", "Rios", "Castillo"};

struct
{
    char id;
    char nombre[20];
} const Carrera[N_CAR] = {{'B', "Bachillerato"}, {'I', "Ingenieria"}, {'M', "Magister"}};

// Vamos a crear un programa que genere un arreglo de n alumnos (n es dado en los parámetros del
// programa) en base a la siguiente estructura:

// alumn struct
struct Student
{
    int id; // cree un entero alearotio positivo
    char nombres[20];
    char apellidos[20];
    bool masc;      // True: masculino, False: femenino
    char idCarrera; // 'B', 'I' o 'M', desde el arreglo Carrera[]
    int edad;       // en el rango [MIN_EDAD..MAX_EDAD]
};

using namespace std;

void genAlumnos(Student *students, int n);
void avgGeneros(Student *students, int n, float *men, float * women);
void countFamily(Student *students, int n, char lastname[10]);
void misAlumnos(Student *students, int n, Student *students_career, int *nSel);

int main(int argc, char *argv[])
{

    srand(time(NULL));
    // srand(100);

    // students number
    int n = atoi(argv[1]);

    Student *students = new Student[n];

    // generate students
    genAlumnos(students, n);

    // print students
    for (int i = 0; i < n; i++)
    {
        printf("New student:\n");
        cout << "nombre: " << students[i].nombres << endl;
        cout << "apellidos: " << students[i].apellidos << endl;
        printf("id: %i\ngender: %i\ncarrera: %c\nedad: %i\n\n", students[i].id, students[i].masc, students[i].idCarrera, students[i].edad);
    }

    // get age average of women and men
    float avg_women, avg_men;

    // get averages
    avgGeneros(students, n, &avg_women, &avg_men);

    // print averages
    printf("women average age: %f\nmen average age %f\n", avg_women, avg_men);

    // count family
    char lastname [10];
    strcpy(lastname, apel[rand() % N_APEL]);

    cout << "Family to looking for: " << lastname << endl;
    countFamily(students, n, lastname);

    // array of studentf of a specific career
    Student * students_career;
    // number of students of that career
    int nSel = 0;
    
    // count student from a career
    misAlumnos(students, n, students_career, &nSel);

    return 0;
}

// E2.- Cree el procedimiento void countFamily(Alum *Alumno, int n, char lastname[10]) que
// contabiliza la cantidad de miembros con al menos uno de sus apellidos igual a ‘lastname’. (No use
// funciones de la librería estándar del lenguaje para las búsquedas, hágalo todo manualmente con ciclos
// para recorrer los arreglos de char)
void countFamily(Student *students, int n, char lastname[10])
{
    bool are_family = false;
    // int k = 0;
    bool lastname_is_in;

    int familiars_counter = 0;

    // for chekc lastname length
    int last_name_length = 0;
    int i = 0;

    // for (int i = 0; i < 10; i++)
    // {
    //     // if (lastname[i] )
    //     // cout << i << "  " << lastname[i] << " " << int(lastname[i]) << endl;
    // }

    // get length of real lastname
    for (int i = 0; i < 10; i++)
    {
        if (int(lastname[i]) != 0)
        {
            last_name_length++;
        }
    }
    
    // printf("lastname length: %i\n", last_name_length);

    // iterate through each student
    for (int i = 0; i < n; i++)
    {
        // cout << students[i].apellidos << endl;

        // iterate over apellidos of student
        for (int j = 0; j < 20; ++j)
        {

            lastname_is_in = true;
            
            // iterate over apellido to looking for
            for (int k = 0; k < last_name_length; ++k)
            {
                // printf("k value inside for: %i\n", k);

                // compare if characters are equals
                if (students[i].apellidos[j+k] != lastname[k])
                {
                    // printf("lastnames not equals\n");
                    lastname_is_in = false;
                    // go to next character of student's apellidos
                    break;
                }

                // cout << "apellido student: " << students[i].apellidos[j+k] << "last name: " << lastname[k] << endl;
            }

            // printf("comparison: %i\n", k);
            // if all characters were equals
            if (lastname_is_in)
            {
                // family flag
                // are_family = true;
                familiars_counter++;

                cout << "familiar founded: " << students[i].apellidos << endl;                

                //  go to next student
                break;
            }
        }

    }

    printf("familiars: %i\n", familiars_counter);

}

// E1.- Cree el procedimiento void avgGeneros(Alum *Alumno, int n, float *men, float * women) que
// calcula el promedio de edad por tipo de sexo
void avgGeneros(Student *students, int n, float *men, float * women)
{
    int sum_women = 0, sum_men = 0, women_count = 0, men_count = 0;

    // iterate through students
    for (int i = 0; i < n; i++)
    {
        // if it's woman
        if (students[i].masc == 1)
        {
            women_count++;
            // add age
            sum_women += students[i].edad;

        }

        // if student is man
        else {
            men_count++;
            // add age
            sum_men += students[i].edad;
        }
    }

    // compute average
    // avoid zero division
    if (women_count != 0) 
    {
        *women = (float)sum_women / (float)women_count;
    }

    else {
        printf("There is not women\n");
        *women = -1.;
    }
    // avoid zero division
    if (men_count != 0)
    {
        *men = (float)sum_men / (float)men_count;
    }
    else {
        printf("There is not men\n");
        *men = -1;
    }

}

//  generate students
void genAlumnos(Student *students, int n)
{
    for (int i = 0; i < n; ++i)
    {
        // add id
        students[i].id = i;

        // add surnames
        strcpy(students[i].apellidos, "");
        strcpy(students[i].apellidos, apel[rand() % N_APEL]);
        strcat(students[i].apellidos, " ");
        strcat(students[i].apellidos, apel[rand() % N_APEL]);

        students[i].masc = rand() % 2;
        students[i].idCarrera = Carrera[rand() % 3].id;
        students[i].edad = MIN_EDAD + rand() % (MAX_EDAD - MIN_EDAD);

        // get 2 differents random numbers for names
        int name_1 = rand() % N_NOM;
        int name_2 = rand() % N_NOM;
        while (name_1 == name_2)
        {
            name_2 = rand() % N_NOM;
        }

        // 0 is man
        if (students[i].masc == 0)
        {
            // add name
            strcpy(students[i].nombres, ellos[name_1]);
            strcat(students[i].nombres, " ");
            strcat(students[i].nombres, ellos[name_2]);
        }

        // if it's female
        else
        {

            // add name
            strcpy(students[i].nombres, ellas[name_1]);
            strcat(students[i].nombres, " ");
            strcat(students[i].nombres, ellas[name_2]);
        }
    }
}

// E3.- Dado un código de carrera leído desde el teclado, cree el procedimiento void misAlumnos(Alum
// *Alumno, int n, Alum *Al_Carr, int *nSel) que genere una copia de todos los alumnos pertenecientes a
// dicha carrera y los guarde en Al_Carr[0..nSel-1].
void misAlumnos(Student *students, int n, Student *students_career, int *nSel)
{

    // code career
    char code_career;
    // counter
    int career_students_counter = 0;
    // get code of career
    cout << "Enter career code (B, I, M): ";
    cin >> code_career;
    
    // count how many students there are of the career
    for (int i = 0; i < n; i++)
    {
        if (students[i].idCarrera == code_career)
        {
            // printf("Student of carrer %c\n", code_career);
            career_students_counter++;
        }
    }

    printf("Students of career %c: %i\n", code_career, career_students_counter);

    // allocate memory
    students_career = new Student [career_students_counter];

    // counter for add student
    int count = 0;

    // copy each student in new array
    for (int i = 0; i < n; ++i)
    {

        if (students[i].idCarrera == code_career)
        {
            // copy student
            students_career[count] = students[i];

            // check if they are copies!
            // students_career[count].idCarrera = 'B';
            // students[i].idCarrera = 'B';
            // cout << "career: " << students_career[count].edad << endl;
            // cout << "original: " << students[i].edad << endl;
            // check if objects are same
            // cout << "student career address: " << &students_career[count] << endl;
            // cout << "student address: " << &students[i] << endl;

            // update counter
            count++;

        }
    }


    // testing
    bool test = true;
    for (int i = 0; i < career_students_counter; ++i)
    {
        if (students_career[i].idCarrera != code_career)
        {
            test = false;
            break;
        }
    }
    
    // print message
    test ? printf("Test ok\n") : printf("Error in test!\n");
    
}