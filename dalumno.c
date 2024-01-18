#include <stdio.h>

struct dalumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};

void ingresarDatos(struct dalumno *alumno)
{
    printf("\nIngresar datos del alumno:\n");

    printf("Matricula: ");
    scanf("%d", &alumno->matricula);

    printf("Nombre: ");
    while (getchar() != '\n')
        ;
    fgets(alumno->nombre, sizeof(alumno->nombre), stdin);

    printf("Direccion: ");
    fgets(alumno->direccion, sizeof(alumno->direccion), stdin);

    printf("Carrera: ");
    fgets(alumno->carrera, sizeof(alumno->carrera), stdin);

    printf("Promedio: ");
    scanf("%f", &alumno->promedio);
}

void mostrarDatos(struct dalumno alumno)
{
    printf("\nDatos del alumno:\n");
    printf("Matricula: %d\n", alumno.matricula);
    printf("Nombre: ");
    puts(alumno.nombre);
    printf("Direccion: ");
    puts(alumno.direccion);
    printf("Carrera: ");
    puts(alumno.carrera);
    printf("Promedio: %.2f\n", alumno.promedio);
}

int main()
{
    int numerodealumnos;

    printf("Ingrese el numero de estudiantes que va a ingresar: ");
    scanf("%d", &numerodealumnos);

    // Limpiar el buffer del teclado después de leer el número de estudiantes
    while (getchar() != '\n')
        ;

    // Declarar un arreglo de estructuras para almacenar los datos de los alumnos
    struct dalumno alumnos[numerodealumnos];

    FILE *archivo;

    // Abrir el archivo en modo de escritura ("w")
    archivo = fopen("datos_alumnos.txt", "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo. Saliendo...\n");
        return 1; // Salir con un código de error
    }

    // Ciclo para ingresar y guardar datos de los alumnos
    for (int i = 0; i < numerodealumnos; i++)
    {
        ingresarDatos(&alumnos[i]);

        // Guardar los datos en el archivo
        fprintf(archivo, "%d\n%s%s%s%f\n", alumnos[i].matricula, alumnos[i].nombre, alumnos[i].direccion, alumnos[i].carrera, alumnos[i].promedio);
    }

    // Cerrar el archivo después de escribir
    fclose(archivo);

    // Abrir el archivo en modo de lectura ("r")
    archivo = fopen("datos_alumnos.txt", "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo. Saliendo...\n");
        return 1; // Salir con un código de error
    }

    // Ciclo para leer y mostrar los datos de los alumnos desde el archivo
    for (int i = 0; i < numerodealumnos; i++)
    {
        fscanf(archivo, "%d", &alumnos[i].matricula);
        fscanf(archivo, "%s", alumnos[i].nombre);
        fscanf(archivo, "%s", alumnos[i].direccion);
        fscanf(archivo, "%s", alumnos[i].carrera);
        fscanf(archivo, "%f", &alumnos[i].promedio);

        // Mostrar los datos leídos
        mostrarDatos(alumnos[i]);
    }

    // Cerrar el archivo después de leer
    fclose(archivo);

    return 0;
}
