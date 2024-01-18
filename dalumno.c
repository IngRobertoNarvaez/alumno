#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*Estructura del uso de estructuras*/
    struct dalumno
    {
        int matricula;
        char nombre[50];
        char direccion[50];
        char carrera[50];
        float promedio;
    };
    /*Se pide al usuario que ingrese el numero de alumnos que va a ingresar*/
    int numerodealumnos;
    printf("Ingrese el numero de estudiantes que va a ingresar");
    scanf("%d", &numerodealumnos);
    /* Declarar un arreglo de estructuras para almacenar los datos de los alumnos */
    struct dalumno alumnos[numerodealumnos];
    /*Leer lo que uno va ir ingresando*/
    for (int i = 0; i < numerodealumnos; i++)
    {
        printf("\n Ingresar datos del alumno %d:\n", i + 1);
        printf("Nombre del Alumno : ");
        scanf("%s", alumnos[i].nombre);
        printf("Direccion del alumno : ");
        scanf("%s", alumnos[i].direccion);
        printf("Carrera del Alumno: ");
        scanf("%s", alumnos[i].carrera);
        printf("Promedio del Alumno: ");
        scanf("%f", alumnos[i].promedio);
    }
    /*Imprimir todo los datos que se obtuvo*/
    printf("\n Alumnos \n");
    printf("\n");
    for (int i = 0; i < numerodealumnos; i++)
    {
        printf("Nombre %s:\n", alumnos[i].nombre);
        printf("Direccion %s:\n", alumnos[i].direccion);
        printf("Carrera %s:\n", alumnos[i].carrera);
        printf("Promedio %.2f:\n", alumnos[i].promedio);
        printf("\n");
    }

    return 0;
}
