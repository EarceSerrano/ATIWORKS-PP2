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
typedef struct AdjListNode nodo;
typedef struct AdjListNodo ruta;
typedef struct Grafo graph;
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
void menuDomicilio();
struct AdjListNodo* newAdjListNodoMod(char origen[20], char destino[20], int tiempo, int dist, char tipo[12]);
void modificaRuta(struct Grafo* graph);


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
    FILE * fp = fopen("domicilioLugar.txt", "w");
    fclose(fp);
    FILE * fpt = fopen("domicilioRuta.txt", "w");
    fclose(fpt);
    FILE * fptr = fopen("equipos.txt", "w");
    fclose(fptr);
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
  printf("\nIngrese equipo/colaborador: ");
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
      case 5:menuPrincipal();
    }
  }
  
}

//----------------------------- TERMINA REGISTRO EQUIPOS ----------------------------

//----------------------------- DOMICILIOS DE COLABORADORES -------------------------
// LUGAR
// A structure to represent an adjacency list node
struct AdjListNode
{
    int codigo;
    char nomLugar[20];
    int codPostal;
    struct AdjListNode* next;
};
  
// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head; 
};
  
// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices 
// in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};
  
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int codigo, char nomLugar[20], int codPostal)
{
    struct AdjListNode* newNode =
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->codigo = codigo;
    strcpy(newNode->nomLugar, nomLugar);
    newNode->codPostal = codPostal;
    newNode->next = NULL;
    return newNode;
}
  
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = 
        (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
  
    // Create an array of adjacency lists.  Size of 
    // array will be V
    graph->array = 
      (struct AdjList*) malloc(V * sizeof(struct AdjList));
  
    // Initialize each adjacency list as empty by 
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
  
    return graph;
}
  
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph)
{
    int vertice, codigo, codPostal;
    char nomLugar[20];
    printf("Vertice en el cual va a insertar: ");
    scanf("%d", &vertice);
    printf("\nInserte codigo: ");
    scanf("%d%*c", &codigo);
    printf("\nInserte nombre del lugar: ");
    scanf("%s", nomLugar);
    printf("\nInserte codigo postal: ");
    scanf("%d", &codPostal);
    printf("\n");
    // Add an edge from src to dest.  A new node is 
    // added to the adjacency list of src.  The node
    // is added at the beginning
    struct AdjListNode* newNode = newAdjListNode(codigo, nomLugar, codPostal);
    newNode->next = graph->array[vertice].head;
    graph->array[vertice].head = newNode;
  
    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newAdjListNode(vertice, nomLugar, codPostal);
    newNode->next = graph->array[codigo].head;
    graph->array[codigo].head = newNode;

    
}

struct AdjListNode* newAdjListNodeMod(int codigo, char nomLugar[20], int codPostal)
{
    struct AdjListNode* newNode =
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->codigo = codigo;
    strcpy(newNode->nomLugar, nomLugar);
    newNode->codPostal = codPostal;
    newNode->next = NULL;
    return newNode;
}

void modificaLugar(struct Graph* graph)
{
    int vertice, codigo, codPostal;
    char nomLugar[20];
    printf("Nombre del lugar a modificar: ");
    fgets(nomLugar, 20, stdin);
    printf("Vertice: ");
    scanf("%d", &vertice);
    printf("\nInserte nuevo codigo: ");
    scanf("%d%*c", &codigo);
    printf("\nInserte nuevo nombre del lugar: ");
    scanf("%s", nomLugar);
    printf("\nInserte nuevo codigo postal: ");
    scanf("%d", &codPostal);
    printf("\n");
    // Add an edge from src to dest.  A new node is 
    // added to the adjacency list of src.  The node
    // is added at the beginning
    struct AdjListNode* newNode = newAdjListNodeMod(codigo, nomLugar, codPostal);
    newNode->next = graph->array[vertice].head;
    graph->array[vertice].head = newNode;
  
    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newAdjListNodeMod(vertice, nomLugar, codPostal);
    newNode->next = graph->array[codigo].head;
    graph->array[codigo].head = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        
        printf("\n Lista de adyacencia del vertice %d\n head ", v);
        while (pCrawl)
        {
            FILE * fpuntero = fopen("domicilioLugar.txt", "a+");
            printf("-> %d, %s, %d", pCrawl->codigo, pCrawl->nomLugar, pCrawl->codPostal);
            fprintf(fpuntero, "%d", pCrawl->codigo);
            fprintf(fpuntero, "\n");
            fwrite(&pCrawl->nomLugar, sizeof(nodo), 1, fpuntero);
            fprintf(fpuntero, "%d", pCrawl->codPostal);
            fprintf(fpuntero, "\n");
            pCrawl = pCrawl->next;
            fclose(fpuntero);
        }
        printf("\n");
    }
}

  
// A utility function to print the adjacency list 
// representation of graph
void printGraphMod(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        
        printf("\n Lista de adyacencia del vertice %d\n head ", v);
        while (pCrawl)
        {
            FILE * fpuntero = fopen("domicilioLugar.txt", "r+");
            printf("-> %d, %s, %d", pCrawl->codigo, pCrawl->nomLugar, pCrawl->codPostal);
            fprintf(fpuntero, "%d", pCrawl->codigo);
            fprintf(fpuntero, "\n");
            fwrite(&pCrawl->nomLugar, sizeof(nodo), 1, fpuntero);
            fprintf(fpuntero, "%d", pCrawl->codPostal);
            fprintf(fpuntero, "\n");
            pCrawl = pCrawl->next;
            fclose(fpuntero);
        }
        printf("\n");
    }
}

void printGraphElim(struct Graph* graph)
{
    int v;
    char nom[15];
    printf("Inserte nombre del lugar por eliminar: ");
    scanf("%s", nom);
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        
        printf("\n Lista de adyacencia del vertice %d\n head ", v);
        while (pCrawl)
        {
            FILE * fpuntero = fopen("domicilioLugar.txt", "r+");
            free(head);
            printf("-> %d, %s, %d", pCrawl->codigo, pCrawl->nomLugar, pCrawl->codPostal);
            fwrite(&pCrawl, sizeof(nodo), 1, fpuntero);
            pCrawl = pCrawl->next;
            fclose(fpuntero);
        }
        printf("\n");
    }
}

void domicilios(){
    int V = 2;
    struct Graph* graph = createGraph(V);
    addEdge(graph);
    addEdge(graph);
    //addEdge(graph);

    printGraph(graph);
}

void domiciliosMod(){
    int V = 1;
    struct Graph* graph = createGraph(V);
    modificaLugar(graph);

    printGraphMod(graph);
}

void domiciliosElim(){
    int V = 1;
    struct Graph* graph = createGraph(V);

    printGraphElim(graph);
}

// RUTA 


struct AdjListNodo
{
    char origen[20], destino[20];
    int tiempo, dist;
    char tipo[12];
    struct AdjListNodo* next;
};
  
// A structure to represent an adjacency list
struct AdjLista
{
    struct AdjListNodo *head; 
};
  
// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices 
// in graph)
struct Grafo
{
    int V;
    struct AdjLista* array;
};

struct AdjListNodo* newAdjListNodo(char origen[20], char destino[20], int tiempo, int dist, char tipo[12])
{
    struct AdjListNodo* newNode =
     (struct AdjListNodo*) malloc(sizeof(struct AdjListNodo));
    strcpy(newNode->origen, origen);
    strcpy(newNode->destino, destino);
    newNode->tiempo = tiempo;
    newNode->dist = dist;
    strcpy(newNode->tipo, tipo);
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Grafo* crearGrafo(int V)
{
    struct Grafo* graph = 
        (struct Grafo*) malloc(sizeof(struct Grafo));
    graph->V = V;
  
    // Create an array of adjacency lists.  Size of 
    // array will be V
    graph->array = 
      (struct AdjLista*) malloc(V * sizeof(struct AdjLista));
  
    // Initialize each adjacency list as empty by 
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
  
    return graph;
}

void addEdges(struct Grafo* graph)
{
    int vertice;
    char origen[20], destino[20];
    int tiempo, dist;
    char tipo[12];
    printf("Vertice en el cual va a insertar: ");
    scanf("%d%*c", &vertice);
    printf("\nOrigen: ");
    scanf("%s", origen);
    printf("\nDestino: ");
    scanf("%s", destino);
    printf("\nTiempo que durara en minutos: ");
    scanf("%d", &tiempo);
    printf("\nDistancia en Km: ");
    scanf("%d%*c", &dist);
    printf("\nTipo de ruta (terrestre, aerea, maritima): ");
    scanf("%s", tipo);
    printf("\n");
    // Add an edge from src to dest.  A new node is 
    // added to the adjacency list of src.  The node
    // is added at the beginning
    struct AdjListNodo* newNode = newAdjListNodo(origen, destino, tiempo, dist, tipo);
    newNode->next = graph->array[vertice].head;
    graph->array[vertice].head = newNode;
  
    // Since graph is undirected, add an edge from
    /* dest to src also
    newNode = newAdjListNodo(vertice, nomLugar, codPostal);
    newNode->next = graph->array[codigo].head;
    graph->array[codigo].head = newNode;*/
}

void printGrafo(struct Grafo* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNodo* pCrawl = graph->array[v].head;
        
        printf("\n Lista de adyacencia del vertice %d\n head ", v);
        while (pCrawl)
        {
            FILE * fpuntero = fopen("domicilioRuta.txt", "a+");
            printf("-> %s, %s, %d, %d, %s", pCrawl->origen, pCrawl->destino, pCrawl->tiempo, pCrawl->dist, pCrawl->tipo);
            fwrite(&pCrawl->origen, sizeof(ruta), 1, fpuntero);
            fwrite(&pCrawl->destino, sizeof(ruta), 1, fpuntero);
            fprintf(fpuntero, "%d", pCrawl->tiempo);
            fprintf(fpuntero, "\n");
            fprintf(fpuntero, "%d", pCrawl->dist);
            fprintf(fpuntero, "\n");
            fwrite(&pCrawl->tipo, sizeof(ruta), 1, fpuntero);
            pCrawl = pCrawl->next;
            fclose(fpuntero);
        }
        printf("\n");
    }
}

void domiciliosRuta(){
    int V = 2;
    struct Grafo* graph = crearGrafo(V);
    addEdges(graph);
    addEdges(graph);
    //addEdge(graph);

    printGrafo(graph);
}



struct AdjListNodo* newAdjListNodoMod(char origen[20], char destino[20], int tiempo, int dist, char tipo[12])
{
    struct AdjListNodo* newNode =
     (struct AdjListNodo*) malloc(sizeof(struct AdjListNodo));
    strcpy(newNode->origen, origen);
    strcpy(newNode->destino, destino);
    newNode->tiempo = tiempo;
    newNode->dist = dist;
    strcpy(newNode->tipo, tipo);
    newNode->next = NULL;
    return newNode;
}

void modificaRuta(struct Grafo* graph)
{
    int vertice;
    char origen[20], destino[20];
    int tiempo, dist;
    char tipo[12];
    printf("Vertice en el cual va a insertar: ");
    scanf("%d%*c", &vertice);
    printf("\nNuevo origen: ");
    scanf("%s", origen);
    printf("\nNuevo destino: ");
    scanf("%s", destino);
    printf("\nNuevo tiempo que durara en minutos: ");
    scanf("%d", &tiempo);
    printf("\nNueva distancia en Km: ");
    scanf("%d%*c", &dist);
    printf("\nNuevo tipo de ruta (terrestre, aerea, maritima): ");
    scanf("%s", tipo);
    printf("\n");
    // Add an edge from src to dest.  A new node is 
    // added to the adjacency list of src.  The node
    // is added at the beginning
    struct AdjListNodo* newNode = newAdjListNodoMod(origen, destino, tiempo, dist, tipo);
    newNode->next = graph->array[vertice].head;
    graph->array[vertice].head = newNode;
  
    // Since graph is undirected, add an edge from
    /* dest to src also
    newNode = newAdjListNodo(vertice, nomLugar, codPostal);
    newNode->next = graph->array[codigo].head;
    graph->array[codigo].head = newNode;*/
}

void printGrafoMod(struct Grafo* graph)
{
    int v;
    for (v = 0; v <= graph->V; ++v)
    {
        struct AdjListNodo* pCrawl = graph->array[v].head;
        
        printf("\n Lista de adyacencia del vertice %d\n head ", v);
        while (pCrawl)
        {
            FILE * fpuntero = fopen("domicilioRuta.txt", "r+");
            printf("-> %s, %s, %d, %d, %s", pCrawl->origen, pCrawl->destino, pCrawl->tiempo, pCrawl->dist, pCrawl->tipo);
            fwrite(&pCrawl->origen, sizeof(ruta), 1, fpuntero);
            fwrite(&pCrawl->destino, sizeof(ruta), 1, fpuntero);
            fprintf(fpuntero, "%d", pCrawl->tiempo);
            fprintf(fpuntero, "\n");
            fprintf(fpuntero, "%d", pCrawl->dist);
            fprintf(fpuntero, "\n");
            fwrite(&pCrawl->tipo, sizeof(ruta), 1, fpuntero);
            pCrawl = pCrawl->next;
            fclose(fpuntero);
        }
        printf("\n");
    }
}

void domiciliosRutaMod(){
    int V = 1;
    struct Grafo* graph = crearGrafo(V);
    modificaRuta(graph);

    printGrafoMod(graph);
}

void printGrafoElim(struct Grafo* grafo)
{
    int v;
    char origen[15];
    printf("Inserte origen por eliminar: ");
    scanf("%s", origen);
    for (v = 0; v < grafo->V; ++v)
    {
        struct AdjListNodo* pCrawl = grafo->array[v].head;
        
        printf("\n Lista de adyacencia del vertice %d\n head ", v);
        while (pCrawl)
        {
            FILE * fpuntero = fopen("domicilioRuta.txt", "r+");
            free(head);
            printf("-> %s, %s, %d, %d, %s", pCrawl->origen, pCrawl->destino, pCrawl->tiempo, pCrawl->dist, pCrawl->tipo);
            fwrite(&pCrawl, sizeof(ruta), 1, fpuntero);
            pCrawl = pCrawl->next;
            fclose(fpuntero);
        }
        printf("\n");
    }
}

void domiciliosElimRuta(){
    int V = 1;
    struct Grafo* grafo = crearGrafo(V);

    printGrafoElim(grafo);
}


void menuDomicilio(){
    int num;
    while(num!=4){
    printf("\n1.Registrar lugar\n2.Modificar lugar\n3.Borrar lugar\n4.Registrar ruta\n5.Modificar ruta\n6.Eliminar ruta\n7.Salir\nIngrese una opcion: ");
    scanf("%d%*c",&num);
    switch (num) {
      case 1: 
      domicilios();
      break;
      case 2:
      domiciliosMod();
      break;
      case 3:
      printf("Eliminar lugar\n");
      domiciliosElim();
      //FILE * fpuntero = fopen("domicilioLugar.txt", "w+");
      //fclose(fpuntero);
      break;
      case 4:
      domiciliosRuta();
      break;
      case 5:
      domiciliosRutaMod();
      break;
      case 6:
      printf("Eliminar ruta\n");
      domiciliosElimRuta();
      //FILE * fptr = fopen("domicilioRuta.txt", "w+");
      //fclose(fptr);
      break;
      case 7:
      menuPrincipal();
    }
  }
}
//----------------------------- TERMINA DOMICILIOS DE COLABORADORES ---------------------------

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

//--------------------------------------- CHAT ---------------------------------------------
void chat(){
  int flag=0;
  equipo *ptr;
  ptr=Root;
  char w[10];
  char y[10];
  printf("\nIngrese nombre del colaborador emisor: ");
  scanf("%s",y);
  printf("\nIngrese nombre del colaborador receptor: ");
  scanf("%s%*c",w);
  while(flag==0){
    if(check(w,ptr->nombre)>0)
       ptr=ptr->right;
    else if(check(w,ptr->nombre)<0)
          ptr=ptr->left;
    else if(check(w,ptr->nombre)==0){
       flag=1;
       printf("Mensaje: ");
       fgets(ptr->descripcion, 20, stdin);
       FILE * fpuntero = fopen("equipos.txt", "a+");
       fwrite(&ptr->nombre, sizeof(BITACORA), 1, fpuntero);
       fwrite(&ptr->descripcion, sizeof(BITACORA), 1, fpuntero);
       fclose(fpuntero);
    }

    }
    if(flag==0)
      printf("\nNo se puede establecer conexion con el colaborador\n");
}



//--------------------------------------- TERMINA CHAT --------------------------------------

//menu principal
void menuPrincipal()       
{
    int opcion;
    int cantMensajes = 0;
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
        printf("\t9. Eliminar contenido txts\n");
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
            menuDomicilio();
            break;
        case 5:
            printf("Eligio bitacora de trabajo\n");
            BITACORA ptr;
            bitacoras(&ptr);
            aniadirBitacora(ptr);
            break;
        case 6:
            chat();
            cantMensajes += 1;
            break;
        case 7:
            break;
        case 8:
            printf("\nEligio analisis de datos\n");
            int numero = 0;
            while(numero!=7){
                printf("1. Cantidad mensajes\n");
                printf("2. Promedio de lugares que se visitan en rutas de paseo\n");
                printf("3. Cantidad de archivos en total\n");
                printf("4. Cantidad de archivos en promedio\n");
                printf("5. Promedio de colaboradores en equipo\n");
                printf("6. Top 5 con mayor cantidad de colaboradores\n");
                printf("7. Salir\n");
                printf("Ingrese opcion: ");
                scanf("%d",&numero);
                switch (numero) {
                    case 1: 
                        printf("La cantidad de mensajes enviados es: %d\n\n", cantMensajes);
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
                        numero = 7;
                        break;
                    }
            }
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






