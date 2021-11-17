#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct colaborador COLABORADOR;
typedef struct nodec NODEC;
void menuPrincipal();
void modificarColab(COLABORADOR *colaborador, int num);
void modificaC(NODEC *aux);
void eliminarColab();
void colaboradorAarchivoMod();
void colaboradorAarchivoMod();


//Struct
struct colaborador
{
    int cedula; 
    char nombre[20];
    char apellidos[20];
    char correo[20];
    char rol[20];
    char fechaCumple[20];
};

struct nodec // Nodo donde se almacena cada pregunta
{
    struct nodec *next;
    struct nodec *prev;
    COLABORADOR info;
};

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
}

void menuColabs(COLABORADOR *colaborador){
    //Menu para modificar o eliminar colaborador
    int num;
    printf("\n\n1. Modificar colaborador\n");
    printf("2. Eliminar colaborador\n");
    printf("0. Volver al menu\n");
    printf("Ingrese la opcion que desea: \n");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("Eligio modificar colaborador\n");
        modificaC(head);
    }
    else if (num == 2)
    {
        printf("Eligio eliminar");
        eliminarColab(colaborador);
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
        if(aux != NULL)
        {
            fwrite(&aux->info, sizeof(COLABORADOR), 1, fpuntero);
        }
    }
    fclose(fpuntero);
}

//Modifica colaborador 
void modificarColab(COLABORADOR *colaborador, int num)        
{
    if (num == colaborador->cedula)
    {
        printf("\n========================================================\n\n");
        printf("\t\t Detalles de colaborador\n");
        printf("========================================================\n\n");

        printf("\nCedula colaborador: %d\t\n", colaborador->cedula);
        printf("\nNombre: %s\t\n", colaborador->nombre);
        printf("\nApellidos: %s\t\n", colaborador->apellidos);
        printf("\nCorreo: %s\t\n", colaborador->correo);
        printf("\nRol: %s\t\n", colaborador->rol);
        printf("\nFecha nacimiento: %s\t\n", colaborador->fechaCumple);

        
        printf("\nNuevo nombre: ");
        fgets(colaborador->nombre, 20, stdin);
        printf("\nApellidos: ");
        fgets(colaborador->apellidos, 20, stdin);
        printf("\nCorreo: ");
        fgets(colaborador->correo, 20, stdin);
        printf("\nRol: ");
        fgets(colaborador->rol, 20, stdin);
        printf("\nFecha nacimiento: ");
        fgets(colaborador->fechaCumple, 20, stdin);

        colaboradorAarchivoMod();
    }
}

void colaboradorAarchivoMod() //copia informacion a .txt
{
    NODEC *aux = head;
    FILE * fpuntero = fopen("colaboradores.txt", "r+");
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

void modificaC(NODEC *aux)  //modifica la pregunta en base a su id de pregunta
{
    COLABORADOR *ptr, *id;
    int num;
    printf("Ingrese el numero de cedula del colaborador a modificar: ");
    scanf("%d%*c", &num);
    if (aux == NULL)
    {
        printf("No se encontro colaborador\n");
    }
    else
    {
        while (aux != NULL)
        {
            ptr = &aux->info;
            modificarColab(ptr, num);
            aux = aux->next;
        }
    }
}



//Arreglar funcion para eliminar colab en especifico
void eliminarColab() 
{
    NODEC *aux = head;
    int num;
    printf("Ingrese el numero de cedula del colaborador a modificar: ");
    scanf("%d", &num);
    FILE * fpuntero = fopen("colaboradores.txt", "r+");
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


void eliminarTodoColabs(){
    FILE * fpuntero = fopen("colaboradores.txt", "w");
    fclose(fpuntero);
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
        printf("\t11. Modificar colaborador\n");
        printf("\t12. Eliminar colaboradores\n");
        printf("\n\t0. SALIR\n");
        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Eligio registrar colaborador\n");
            COLABORADOR colaborador;
            NODEC *aux;
            //ingresan datos
            registroColaborador(&colaborador);
            //info colab a nodo
            aniadirColaborador(colaborador);
            //guardo nodo en el archivo
            colaboradorAarchivo();
            menuColabs(&colaborador);
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
            eliminarTodoColabs();
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






