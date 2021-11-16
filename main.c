#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

void menuPrincipal();

//Struct
typedef struct colaborador
{
    int cedula; 
    char nombre[20];
    char apellidos[20];
    char correo[20];
    char rol[20];
    char fechaCumple[20];
}COLABORADOR;

typedef struct nodec // Nodo donde se almacena cada pregunta
{
    struct nodec *next;
    struct nodec *prev;
    COLABORADOR info;
} NODEC;

NODEC *head = NULL;

NODEC *CreateNode() // funcion para crear nodo
{
    NODEC *temp;
    temp = (NODEC *)malloc(sizeof(NODEC));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}



void registroColaborador(COLABORADOR *colaborador){
    int num;
    printf("Ingrese los datos del colaborador\n");
    printf("Cedula: ");
    scanf("%d%*c", &colaborador->cedula);
    printf("Nombre: ");
    fgets(colaborador->nombre, 20, stdin);
    printf("Apellidos: ");
    fgets(colaborador->apellidos, 20, stdin);
    printf("Correo electronico: ");
    fgets(colaborador->correo, 20, stdin);
    printf("Rol en la organizacion: ");
    fgets(colaborador->rol, 20, stdin);
    printf("Fecha de cumpleanos: ");
    fgets(colaborador->fechaCumple, 20, stdin);
    

    //Menu para modificar o eliminar colaborador
    printf("\n\n1. Modificar colaborador\n");
    printf("2. Eliminar colaborador\n");
    printf("0. Volver al menu\n");
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
    else
    {
        menuPrincipal();
    }
    
}



void aniadirColaborador(COLABORADOR colaborador) // agrega info de colaborador  a nodo
{
    NODEC *nuevoNodo;
    nuevoNodo = CreateNode();
    nuevoNodo->info = colaborador;

    if (head == NULL)
    {
        head = nuevoNodo;
    }
    else
    {
        nuevoNodo->next = head;
        head->prev = nuevoNodo;
        head = nuevoNodo;
    }
}

 
void colaboradorAarchivo() //copia informacion a .txt
{
    NODEC *aux = head;
    FILE * fpuntero = fopen("colaboradores.txt", "a+");
    if (fpuntero != NULL)
    {
        while (aux != NULL)
        {
            fwrite(&aux->info, sizeof(COLABORADOR), 1, fpuntero);
            fprintf(fpuntero, "\n");
            aux = aux->next;
        }
    }
    fclose(fpuntero);
}

//Muestra colaboradores
void MostrarColab(COLABORADOR colaborador)        //muestra pregunta de nodo actual
{
    printf("\n========================================================\n\n");
    printf("\t\t Detalles de colaborador\n");
    printf("========================================================\n\n");

    printf("\nCedula colaborador: %d\t\n", colaborador.cedula);
    printf("\nNombre: %s\t\n", colaborador.nombre);
    printf("\nApellidos: %s\t\n", colaborador.apellidos);
    printf("\nCorreo: %s\t\n", colaborador.correo);
    printf("\nRol: %s\t\n", colaborador.rol);
    printf("\nFecha nacimiento: %s\t\n", colaborador.fechaCumple);
}

void leerColab(NODEC *aux) //muesta los colaboradores que hay en memoria
{
    if (aux == NULL)
    {
        printf(" No hay colaboradores...\n");
    }
    else
    {
        printf(" Colaboradores disponibles\n");
        while (aux != NULL)
        {
            MostrarColab(aux->info);
            aux = aux->next;
        }
        printf("\n");
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
        //ELIMINAR, SON PRUEBA
        printf("\t11. Leer colaborador\n");
        printf("\t12. Eliminar colaboradores\n");
        printf("\n\t0. SALIR\n");
        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Eligio registrar colaborador\n");
            COLABORADOR colaborador;
            registroColaborador(&colaborador);
            aniadirColaborador(colaborador);
            colaboradorAarchivo();
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
            leerColab(head);
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






