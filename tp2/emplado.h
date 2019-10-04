#ifndef EMPLADO_H_INCLUDED
#define EMPLADO_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

#endif // EMPLADO_H_INCLUDED
int menu();
int hardcodearEmpleados( eEmployee vec[], int tam, int cantidad);
int altaEmpleado(eEmployee vec[], int tam, int id);
int bajaEmpleado(eEmployee vec[], int tam);
int buscarEmpleado(int id, eEmployee vec[], int tam);
int buscarLibre(eEmployee vec[], int tam);
int modificarEmpleado(eEmployee vec[], int tam);
void inicializarEmpleados(eEmployee vec[], int tam);
void mostrarEmpleado(eEmployee x);
void mostrarEmpleados(eEmployee vec[], int tam);
eEmployee newEmpleado(int id,char nombre[],char lastName[],int salary,int sector);
