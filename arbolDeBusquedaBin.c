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
}