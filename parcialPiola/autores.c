#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "autores.h"
#include "validaciones.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"
#include "informes.h"
#define VACIO -1
#define LLENO 1

static int generarIdAuto(void)
{
    static int id1=0;
    return id1++;
}
int inicializarArrayAuto(Autores *arrayAuto, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        arrayAuto[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int buscarElVacioAuto(Autores *arrayAuto,int cant,int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(arrayAuto[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int altaAutor(Autores *arrayAuto,int cant,int posLibre)
{
    int ret;
    if (!getName(arrayAuto[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,31,1))
    {
        if (!getName(arrayAuto[posLibre].apellido,"ingrese un apellido: ","error, vuelva a ingresar\n\n",2,31,1))
        {

            arrayAuto[posLibre].id=generarIdAuto();
            arrayAuto[posLibre].isEmpty=LLENO;
            ret=0;

        }
    }

    else
    {
        ret=1;
    }
    return ret;
}
int buscaId (Autores *arrayAuto, int cant, int *idEncontrado)
{
    int i;
    int retorno = -1;
    Autores auxAut;
    printf("\ningrese id de autor a buscar: ");
    scanf("%d", &auxAut.id);
    for(i=0; i < cant; i++)
    {
        if (arrayAuto[i].id == auxAut.id)
        {
            retorno=0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}
int modificacion(Autores *arrayAuto,int cant)
{
    int aceptar;
    char modificacion;
    int ret=-1;
    int posId1;
    int i;
    int posPrueba=0;
    for(i=0; i<cant; i++)
    {
        if(arrayAuto[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayAuto[i].id);
        }
    }
    if(!buscaId(arrayAuto,cant,&posId1))
    {
        do
        {
            system("clear");
            printf("--------------\n");
            printf("-5) NOMBRE   -\n");
            printf("-6) APELLIDO -\n");
            printf("--------------\n");
            printf("ingrese el campo a modificar: ");
            scanf("%d",&aceptar);
            system("clear");
            switch(aceptar)
            {
            case 5:
                getName(arrayAuto[posPrueba].nombre,"modifique el nombre: ","error, vuelva a ingresar\n\n",2,31,1);
                break;
            case 6:
                getName(arrayAuto[posPrueba].apellido,"modifique el apellido: ","error, vuelva a ingresar\n\n",2,31,1);
                break;
            }
            printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
            scanf("%s",&modificacion);
            system("clear");
        }
        while(modificacion=='s');
        ret=0;
    }
    else
    {
        printf("no se encontro id");
    }
    return ret;
}
int baja(Autores *arrayAuto,int cant)
{
    int posId1;
    char resp;
    int posBaja=0;
    int i;
    for(i=0; i<cant; i++)
    {
        if(arrayAuto[i].isEmpty!=VACIO)
        {
            printf("id disponibles: %d\n",arrayAuto[i].id);
        }
    }
    if(!buscaId(arrayAuto,cant,&posId1))
    {
        printf("esta seguro que quiere dar de baja ese id: \n s|n: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            printf("se ah dado de baja este autor");
            arrayAuto[posBaja].isEmpty=VACIO;
        }
        else
        {
            printf("vuelva al menu");
        }
    }
    return 0;
}
void OrdenamientoAutor(Autores *array,int cant)
{
    int i;
    int j;
    int d;

    int a;
    int b;
    int c;
    Autores aux1;
    Autores aux;
    printf("  ordenado alfabeticamente ascendente por apellido:\n");

    for(i = 1; i < cant; i++)
    {
        aux = array[i];
        j = i;
        while(j > 0 && strcmp( aux.apellido, array[j - 1].apellido)<0)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
    for (d=0; d<cant; d++)
    {
        if(array[d].isEmpty!=VACIO)
        {
            printf("nombre:%s apellido:%s id:%d\n",array[d].nombre,array[d].apellido,array[d].id);
        }
    }

    printf("  ordenado alfabeticamente ascendente por nombre:\n");

    for(a = 1; a < cant; a++)
    {
        aux1 = array[a];
        b = a;
        while(b > 0 && strcmp( aux1.nombre, array[b - 1].nombre)<0)
        {
            array[b] = array[b - 1];
            b--;
        }
        array[b] = aux1;
    }
    for (c=0; c<cant; c++)
    {
        if(array[c].isEmpty!=VACIO)
        {
            printf("nombre:%s apellido:%s id:%d\n",array[c].nombre,array[c].apellido,array[c].id);
        }
    }
}
