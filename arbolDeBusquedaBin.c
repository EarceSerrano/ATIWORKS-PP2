#include <stdio.h>
#include <stdlib.h>

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

int main(){
  equipos();
  return 0;
}




/* ORIGINAL
#include<stdio.h>
#include<stdlib.h>

typedef struct nodo nodo;

struct nodo {
    int info;
    struct nodo *izq;
    struct nodo *der;
};

//Definici�n de ra�z de �rbol
nodo *raiz=NULL;

void insertar(int x)
{
    nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        nodo *anterior, *aux;
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
}

void imprimirPreorden(nodo *recorrer)
{
    if (recorrer != NULL)
    {
        printf("%i-",recorrer->info);
        imprimirPreorden(recorrer->izq);
        imprimirPreorden(recorrer->der);
    }
}


void imprimirEnOrden(nodo *recorrer)
{
    if (recorrer != NULL)
    {
        imprimirEnOrden(recorrer->izq);
        printf("%i-",recorrer->info);
        imprimirEnOrden(recorrer->der);
    }
}

void imprimirPostOrden(nodo *recorrer)
{
    if (recorrer != NULL)
    {
        imprimirPostOrden(recorrer->izq);
        imprimirPostOrden(recorrer->der);
        printf("%i-",recorrer->info);
    }
}

void liberar(nodo *aux)
{
    if (aux != NULL)
    {
        liberar(aux->izq);
        liberar(aux->der);
        free(aux);
    }
}

int estaVacio(nodo *raiz)
{
	if(raiz == NULL)
		return 1;
	else
		return 0;
}

int esHoja(nodo *hoja)
{
	if(hoja->izq == NULL && hoja->der == NULL)
	{
		return 1;
	}
	else
		return 0;
}

nodo* buscar(nodo *arbol, int buscado)
{
	nodo *aux = arbol;
	
	if(aux != NULL)
	{
		if(buscado < aux->info){
			buscar(aux->izq, buscado);
		}
		else if(buscado > aux->info){
			buscar(aux->der, buscado);
		}
		else
			return aux;	
	}
	else
		return NULL;	
}

void borrarMenor()
{
	nodo *borrar, *atras, *recorrer;
	
     if (raiz != NULL) {
         if (raiz->izq == NULL)
         {
             borrar = raiz;
             raiz = raiz->der;
             free(borrar);
         }
         else {
             atras = raiz;
             recorrer = raiz->izq;
             while (recorrer->izq != NULL)
             {
                 atras = recorrer;
                 recorrer = recorrer->izq;
             }
             atras->izq = recorrer->der;
             free(recorrer);
         }
     }
 }

int main()
{
	nodo *busca;
	
    insertar(100);
    insertar(50);
    insertar(25);
    insertar(75);
    insertar(150);
    printf("\nRecorrido preorden: ");
    imprimirPreorden(raiz);
    printf("\nRecorridoo enorden: ");
    imprimirEnOrden(raiz);
    printf("\nRecorrido postorden: ");
    imprimirPostOrden(raiz);
    
    
    //buscar 50
    busca = buscar(raiz,40);
    if(busca != NULL)
    	printf("\nEncontro el nodo %i\n", busca->info);
    else
    	printf("\nNo encontro el nodo\n");
    
    
    borrarMenor();
    printf("\nRecorrido enorden: ");
    imprimirEnOrden(raiz);
    
    borrarMenor();
    printf("\nRecorrido enorden: ");
    imprimirEnOrden(raiz);
    
    borrarMenor();
    printf("\nRecorrido enorden: ");
    imprimirEnOrden(raiz);
    
    
    liberar(raiz);
	return 0;
}*/