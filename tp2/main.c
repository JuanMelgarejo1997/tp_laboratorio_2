#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "emplado.h"
#define TAM 10
#define TAMC 3





int main()
{
    int id = 1000;
    eEmployee lista[TAM];
    char salir = 'n';

    inicializarEmpleados(lista, TAM);

    id = id + hardcodearEmpleados(lista, TAM, 6);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaEmpleado(lista, TAM, id))
            {
                id++;
            }
            break;

        case 2:
            modificarEmpleado(lista, TAM);
            break;

        case 3:
            bajaEmpleado(lista, TAM);
            break;

        case 4:
            //informar(lista, TAM);
            break;

        case 5:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}



