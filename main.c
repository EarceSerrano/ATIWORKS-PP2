#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

void menuPrincipal();

//Structs tienen que ser como un grafo, hay que cambiarlo
//Nodo creado por mi
typedef struct colaborador colaborador;
typedef struct posColaborador posColaborador;
struct colaborador{
    int cedula; 
    char nombre[20];
    char apellidos[20];
    char correo[20];
    char rol[20];
    char fechaCumple[20];
};

struct posColaborador{
    struct colaborador *info;
    struct colaborador *izq;
    struct colaborador *der;
};

//ESTO EN COMENTARIO ESTA MALO, HAY QUE CAMBIARLO PARA QUE SEA UN GRAFO
//Se define raiz del arbol
/*
colaborador *raiz = NULL;

void insertar(int x){
    posColaborador *nuevo;
    nuevo = malloc(sizeof(struct posColaborador));
    nuevo->info = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        posColaborador *anterior, *aux;
        anterior = NULL;
        aux = raiz;
        while (aux != NULL)
        {
            anterior = aux;
            if (x < aux->info)
                aux = aux->izq;
            else
                aux = aux->der;
        }
        if (x < anterior->info)
            anterior->izq = nuevo;
        else
            anterior->der = nuevo;
    }
}*/

void registroColaborador(){
    colaborador *persona;
    int num;
    printf("Ingrese los datos del colaborador\n");
    printf("Cedula: \n");
    scanf("%d", &persona->cedula);
    printf("Nombre: \n");
    fgets(persona->nombre, 20, stdin);
    printf("Apellidos: \n");
    fgets(persona->apellidos, 20, stdin);
    printf("Correo electronico: \n");
    fgets(persona->correo, 20, stdin);
    printf("Rol en la organizacion: \n");
    fgets(persona->rol, 20, stdin);
    printf("Fecha de cumpleanos: \n");
    fgets(persona->fechaCumple, 20, stdin);

    //Menu para modificar o eliminar colaborador
    printf("1. Modificar colaborador\n");
    printf("2. Eliminar colaborador\n");
    printf("Ingrese la opcion que desea: \n");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("Eligio modificar");
        //modificarColab();
    }
    else if (num == 2)
    {
        printf("Eligio eliminar");
        //eliminarColab();
    }
}





void menuPrincipal()        //menu principal
{
    int opcion;
    char repetir = TRUE;

    do
    {
        printf("\t\t\tMENU PRINCIPAL\n");
        printf("\t\t\t--------------\n");
        printf("\n\t1. Registrar colaborador\n");
        printf("\t2. Registro de equipo\n");
        printf("\t3. Archivos de los colaboradores\n");
        printf("\t4. Visualizacion del arbol\n");
        printf("\t5. Operaciones de archivos\n");
        printf("\t6. Domicilios de colaboradores\n");
        printf("\t7. Registro de bitacora de trabajo\n");
        printf("\t8. Chat\n");
        printf("\t9. Simulacion de la ruta del paseo\n");
        printf("\t10. Analisis de datos\n");
        printf("\n\t0. SALIR\n");
        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            registroColaborador();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11: 
            break;
        case 12:
            break;

        case 0:
            repetir = FALSE;
            break;
        }
    } while (repetir);
}

int main(){
    menuPrincipal();
    return 0;
}