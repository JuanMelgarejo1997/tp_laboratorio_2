#include "emplado.h"
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Empleados *******\n\n");
    printf("1-Alta empleados\n");
    printf("2-Modificar empleados\n");
    printf("3-Baja alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados(eEmployee vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}
int altaEmpleado(eEmployee vec[], int tam, int id)
{
    int todoOk = 0;
    int indice;
    int esta;
    char nombre[51];
    char lastName[51];
    float salary;
    int sector;

    system("cls");

    printf("*****Alta Empleado*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lastName);

        printf("Ingrese salary: ");
        fflush(stdin);
        scanf("%d", &salary);

        printf("Ingrese sector: ");
        scanf("%d", &sector);

        vec[indice] = newEmpleado(id, nombre, lastName, salary, sector);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}
eEmployee newEmpleado(int id,char nombre[],char lastName[],int salary,int sector)
{
    eEmployee empleado;
    empleado.id = id;
    strcpy( empleado.nombre, nombre);
    strcpy( empleado.lastName, lastName);
    empleado.salary = salary;
    empleado.sector = sector;
    empleado.isEmpty = 0;

    return empleado;
}
int buscarLibre(eEmployee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int bajaEmpleado(eEmployee vec[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Empleado *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleado con ese id\n\n");

    }
    else
    {

        mostrarEmpleado(vec[indice]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}
int buscarEmpleado(int id, eEmployee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarEmpleado(eEmployee x)
{
    printf("  %d  %10s   %10s      %2d    %2d \n",
           x.id,
           x.nombre,
           x.lastName,
           x.salary,
           x.sector);
}
void mostrarEmpleados(eEmployee vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" id    Nombre    Apellido   Salario  Sector \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }

    printf("\n\n");
}
int modificarEmpleado(eEmployee vec[], int tam)
{

    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Modificar Empleado *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);
    int opcion;

    indice = buscarEmpleado(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleado con ese id\n\n");

    }
    else
    {

        mostrarEmpleado(vec[indice]);

        printf("1- Modificar Nombre\n");
        printf("2- Modificar Apellido\n");
        printf("3- Modificar Salario\n");
        printf("4- Modificar Sector\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            scanf("%c", &vec[indice].nombre);
            break;

        case 2:
            printf("Ingrese nuevo apellido: ");
            scanf("%c", &vec[indice].lastName);
            break;

        case 3:
            printf("Ingrese nuevo salario: ");
            scanf("%d", &vec[indice].salary);
            break;

        case 4:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &vec[indice].sector);
            break;
        case 5:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
}
int hardcodearEmpleados( eEmployee vec[], int tam, int cantidad)
{
    int cont = 0;

    eEmployee suplentes[]=
    {
        { 20000, "Juan","Martin", 20000, 2},
        { 20001, "Alberto","Roa", 21999, 4},
        { 20002, "Ana","Caceres",22333, 1},
        { 20003, "Luis","Rojas", 20229,8},
        { 20004, "Alicia","Nuñez", 21999, 10},
        { 20005, "Diego","Riveros", 23334, 2},
        { 20006, "Sofia","Ortiz", 19999, 5},
        { 20007, "Clara","Palma", 21112, 6},
        { 20008, "Mauro","Serrano", 20334, 7},
        { 20009, "Daniela","Colman", 22666, 4},
        { 20010, "Agustin","Insaurralde", 24445,7},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}
