#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

//Se nombran structs y se llaman funciones
typedef struct colaborador COLABORADOR;
typedef struct nodec NODEC;
typedef struct nodeb NODEB;
typedef struct bitacora BITACORA;
void menuPrincipal();
void modificarColab(COLABORADOR *colaborador, int num);
void modificaC(NODEC *aux);
void eliminarColab();
void colaboradorAarchivoMod();
void colaboradorAarchivoMod();
void eliminarC(NODEC *aux);
void eliminarColab(COLABORADOR *colaborador, int num, NODEC *aux);
void bitacoras(BITACORA *ptr);
void aniadirBitacora(BITACORA bitacora);



// ----------------------- REGISTRO COLABORADOR ------------------------------
//Struct del colaborador
struct colaborador
{
    int cedula; 
    char nombre[20];
    char apellidos[20];
    char correo[20];
    char rol[20];
    char fechaCumple[20];
};

struct nodec // Nodo 
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

//Pide datos del colaborador
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

//Menu para modificar o eliminar colaborador
void menuColabs(COLABORADOR *colaborador){
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
        printf("Eligio eliminar\n");
        eliminarC(head);
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

//Modifica colaborador, llama a la funcion de cmodificarColab
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



void eliminarColab(COLABORADOR *colaborador, int num, NODEC *aux)        
{
    if (num == colaborador->cedula)
    {
        printf("\n========================================================\n\n");
        printf("\t\t Detalles de colaborador antes de borrar\n");
        printf("========================================================\n\n");

        printf("\nCedula colaborador: %d\t\n", colaborador->cedula);
        printf("\nNombre: %s\t\n", colaborador->nombre);
        printf("\nApellidos: %s\t\n", colaborador->apellidos);
        printf("\nCorreo: %s\t\n", colaborador->correo);
        printf("\nRol: %s\t\n", colaborador->rol);
        printf("\nFecha nacimiento: %s\t\n", colaborador->fechaCumple);

        printf("Borrado \n");
        menuPrincipal();
        //Tirar un free o null o algo asi
        
    }
    NODEC *auxx = head;
    FILE * fpuntero = fopen("colaboradores.txt", "w");
    if (fpuntero != NULL)
    {
        while (auxx != NULL)
        {
            if (num != colaborador->cedula)
            {
                fwrite(&auxx->info, sizeof(COLABORADOR), 1, fpuntero);
                fprintf(fpuntero, "\n");
            }
            auxx = auxx->next;
        }
    }
    fclose(fpuntero);
}

//Elimina colaboradores, llama a la funcion eliminarColab
void eliminarC(NODEC *aux)  
{
    COLABORADOR *ptr, *id;
    int num;
    printf("Ingrese el numero de cedula del colaborador a eliminar: ");
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
            eliminarColab(ptr, num, aux);
            aux = aux->next;
        }
    }
}


//Elimina todos los colaboradores
void eliminarTodoColabs(){
    FILE * fpuntero = fopen("colaboradores.txt", "w");
    
    fclose(fpuntero);
}

// ----------------------- TERMINA REGISTRO COLABORADOR ------------------------------

// ----------------------- REGISTRO EQUIPOS ------------------------------------------

struct dict {
  struct dict *left,*right;
  char nombre[15],descripcion[20];
}*Root=NULL;

typedef struct dict equipo;
int check(char[],char[]);
void insert(equipo *);
void Search();
void view(equipo *);

int check(char a[],char b[]){
     int i,j,c;
     for(i=0,j=0 ; a[i]!='\0'&&b[j]!='\0' ; i++,j++){
       if(a[i]>b[j]){
         c=1;
         break;
       }
        else if(b[j]>a[i]){
          c=-1;
          break;
        }
      else
         c=0;
     }
     if(c==1)
       return 1;
      else if(c==-1)
        return -1;
      else
        return 0;
}

void Search(){
  int flag=0;
  equipo *ptr;
  ptr=Root;
  char w[10];
  printf("\nIngrese equipo: ");
  scanf("%s",w);
  while(ptr!=NULL && flag==0){
    if(check(w,ptr->nombre)>0)
       ptr=ptr->right;
    else if(check(w,ptr->nombre)<0)
          ptr=ptr->left;
    else if(check(w,ptr->nombre)==0){
       flag=1;
       printf("\n%s",ptr->descripcion);
    }

    }
    if(flag==0)
      printf("\nNo se encontro\n");
}

void insert(equipo *temp){
  int flag=0;
  equipo *ptr,*par;
  ptr=Root;

  if(Root==NULL)
     Root=temp;
  else{
     while(ptr!=NULL ){
       if(check(temp->nombre,ptr->nombre)>0){
         par=ptr;
         ptr=ptr->right;
       }

       else if(check(temp->nombre,ptr->nombre)<0)
     {
       par=ptr;
       ptr=ptr->left;
     }
       else if(check(temp->nombre,ptr->nombre)==0){
          flag=1;
            printf("\nExiste!");
          break;
       }

   }
       if(flag==0 && ptr==NULL){

         if(check(par->nombre,temp->nombre)==1)
            par->left=temp;
         else if(check(par->nombre,temp->nombre)==-1)
            par->right=temp;
       }

     }
     

}

void view(equipo *ptr){
  FILE * fpuntero = fopen("equipos.txt", "a+");
  if(Root==NULL)
    printf("\nEquipo vacio\n");

  else if(ptr !=NULL){
   view(ptr->left);

   printf("\nNombre:%s\n",ptr->nombre);
   printf("\nDescripcion:%s\n",ptr->descripcion);
   fwrite(&ptr->nombre, sizeof(equipo), 1, fpuntero);
   fwrite(&ptr->descripcion, sizeof(equipo), 1, fpuntero);
   fprintf(fpuntero, "\n");
   fclose(fpuntero);
   
   view(ptr->right);
  }

}

void eliminar(){
    FILE * fpuntero = fopen("equipos.txt", "w");
    fclose(fpuntero);
}

void equipos() {
  int ch;
  int argc;
  equipo *temp;
  while(ch!=4){
    printf("\n1.Buscar\n2.Insertar\n3.Ver\n4.Borrar datos\n5.Salir\nIngrese una opcion: ");
    scanf("%d",&ch);
    switch (ch) {
      case 1: Search();break;
      case 2:
      temp=(equipo*)malloc(sizeof(equipo));
      temp->left=NULL;
      temp->right=NULL;
      printf("\nInserte colaborador/equipo:\n");
      scanf("%s",temp->nombre);
      printf("\nInserte descripcion:\n");
      scanf("%s",temp->descripcion);
       insert(temp);
      break;
      case 3:
      view(Root);
      break;
      case 4:
      eliminar();
      break;
      case 5:exit(0);
    }
  }
  
}

//----------------------------- TERMINA REGISTRO EQUIPOS ----------------------------

//--------------------------------------- BITACORA TRABAJO --------------------------------------
struct bitacora
{
    int cedula;
    char descripcion[30];
};

struct nodeb // Nodo 
{
    struct nodeb *next;
    struct nodeb *prev;
    BITACORA info;
};

NODEB *head2 = NULL;

NODEB *CrearNode() // funcion para crear nodo
{
    NODEB *temp;
    temp = (NODEB *)malloc(sizeof(NODEB));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void bitacoras(BITACORA *ptr){
    FILE * fpuntero = fopen("colaboradores.txt", "a+");
    printf("Rendimiento de los colaboradores!\n");
    printf("Ingrese el numero de cedula del colaborador: ");
    scanf("%d%*c", &ptr->cedula);
    fprintf(fpuntero, "%d", ptr->cedula);
    printf("\nObservacion del rendimiento: ");
    fgets(ptr->descripcion, 30, stdin);
    fwrite(&ptr->descripcion, sizeof(BITACORA), 1, fpuntero);

    fclose(fpuntero);
}

void aniadirBitacora(BITACORA bitacora) // agrega info de colaborador  a nodo
{
    NODEB *nuevoNodo;
    nuevoNodo = CrearNode();
    nuevoNodo->info = bitacora;

    if (head2 == NULL)
    {
        head2 = nuevoNodo;
    }
    else
    {
        nuevoNodo->next = head2;
        head2->prev = nuevoNodo;
        head2 = nuevoNodo;
    }
}




//--------------------------------------- TERMINA BITACORA TRABAJO ------------------------------

//menu principal
void menuPrincipal()       
{
    int opcion;
    char repetir = TRUE;

    do
    {
        printf("\t\t\tMENU PRINCIPAL\n");
        printf("\t\t\t--------------\n");
        printf("\n\t1. Registrar colaborador\n");
        printf("\t2. Registro de equipo\n");
        printf("\t3. Arbol de archivos\n");
        printf("\t4. Catalogos para lugares de domicilio\n");
        printf("\t5. Bitacora de rendimiento\n");
        printf("\t6. Chat\n");
        printf("\t7. Ruta del paseo\n");
        printf("\t8. Analisis de datos\n");
        //ELIMINAR, SON PRUEBA
        printf("\t9. Eliminar colaboradores\n");
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
            printf("Eligio registrar equipo\n");
            equipos();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Eligio bitacora de trabajo\n");
            BITACORA ptr;
            bitacoras(&ptr);
            aniadirBitacora(ptr);
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
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






