#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

/* coloque demais includes aqui */

/* cria uma lista de tamanho 0 e retorna o ponteiro para ela */
struct lista *lista_cria (){
	struct lista *l = malloc(sizeof(struct lista));   /* aloca memoria para a nova lista */
   	if (l == NULL)
    		return NULL;

   	l->ini = NULL;   /* o inicio aponta para null */
   	l->tamanho = 0;   /* inicia com tamanho 0 */

   	return l;
}

/* aterra cada ponteiro da lista e a propria lista e então retorna void*/
void lista_destroi (struct lista **lista){
	if(lista_vazia(*lista)){
		free(*lista);

		return;
	}

	struct nodo *l;
   	l = (*lista)->ini; 
   	while (l->prox != NULL){   /* sai do laço quando inicio apontar para NULL: não tem próximo elemento na lista */ 
    		struct nodo *aux = l;   /* auxiliar é criado para que a memoria possa ser destruida mas 'prox' não seja perdido */
     	l = l->prox;   /* p, que é inicio, aponta para o próximo nodo da lista */
     	free(aux);   /* desalocamos aux que aponta para o antigo inicio */ 
   	}

   	free(l);
   	free(*lista);
   	*lista = NULL;
     
   	return;
}

/* insere um elemento no inicio da lista e incrementa o tamanho */
/*retorna 1 caso sucesso e 0 caso falhe */
int lista_insere_inicio(struct lista *lista, int chave){
    	if (lista == NULL) /* verifica se lista existe */
        	return 0;

    	struct nodo *novoNodo = malloc(sizeof(struct nodo)); /* verifica se existe memória para nodo */
    	if (novoNodo == NULL)
        	return 0;

    	novoNodo->chave = chave;

    	if (lista_vazia(lista)) /* inicio aponta para NULL caso seja o primeiro elemento */
        	novoNodo->prox = NULL;
    	else
        	novoNodo->prox = lista->ini; /* novoNodo aponta para o antigo inicio */

    	lista->ini = novoNodo; /* novoNodo é o novo inicio */
    	lista->tamanho++;

    	return 1;
}


/* insere um elemento no fim da lista e incrementa o tamanho */
/*retorna 1 caso sucesso e 0 caso falhe */
int lista_insere_fim (struct lista *lista, int chave){
   	if (lista == NULL)   /* verifica se lista existe */
     	return 0;

   	struct nodo *novoNodo = malloc(sizeof(struct nodo));   /* verifica se existe memória para nodo */

   	if (novoNodo == NULL)   /* retorna 0 em caso de não ter espaço para nodo */
     	return 0;

     if(lista_vazia(lista)){  /* caso não exista nodo inicial */ 
     	lista->ini = novoNodo;
     	novoNodo->chave = chave;
     	lista->ini->prox = NULL;
    		lista->tamanho++;

    		return 1;
     }

	struct nodo *temp = lista->ini;	/* temp percorre a lista até o ultimo elemento */
	while(temp->prox != NULL){
		temp = temp->prox;
	}

	temp->prox = novoNodo; /* ultimo elemento prox aponta para o novo nodo */
   	novoNodo->chave = chave;  
   	novoNodo->prox = NULL;
   	lista->tamanho++;
   
   	return 1;
}

/* insere um novo elemento na lista de forma que a chave está ordenada*/
/* retorna 1 se sucesso e 0 se falha */
int lista_insere_ordenado(struct lista *lista, int chave) {
    if (lista == NULL) /* verifica se lista existe */
        return 0;

    struct nodo *novoNodo = malloc(sizeof(struct nodo)); /* verifica se existe memória para nodo */
    if (novoNodo == NULL)
        return 0;

    novoNodo->chave = chave;
    novoNodo->prox = NULL;

    if (lista_vazia(lista)) {  /* caso de lista sem elementos */
        lista->ini = novoNodo;
        lista->tamanho++;

        return 1;
    }

    struct nodo *aux = lista->ini;
    struct nodo *temp = NULL;

    while (aux != NULL && chave > aux->chave) {
        temp = aux;
        aux = aux->prox;
    }

    if (temp == NULL) {
        novoNodo->prox = lista->ini;
        lista->ini = novoNodo;
    } 
    else{
        novoNodo->prox = aux;
        temp->prox = novoNodo;
    }

    lista->tamanho++;

    return 1;
}

/* remove o primeiro elemento da lista */
/* decrementa o tamanho */
/* retorna 1 se sucesso e 0 se falha */
int lista_remove_inicio (struct lista *lista, int *chave){
	if (lista == NULL)  /* verifica se lista existe */
    		return 0;

    	if(lista_vazia(lista)) /* verifica se existe memória para nodo */
    		return 0;
   
	/* primeira posição passa para a segunda, caso exista */
	*chave = lista->ini->chave;
 	struct nodo *l = lista->ini;  /* cria-se um novo para apontar para inicio */
   	lista->ini = lista->ini->prox; /* o segundo elemento da fila se torna o primeiro */
   	lista->tamanho--;
   	free(l); /* desaloca o primeiro elemento */

   	return 1;
}

/* remove o ultimo elemento da lista */
/* decrementa o tamanho */
/* retorna 1 se sucesso e 0 se falha */
int lista_remove_fim(struct lista *lista, int *chave) {
    if (lista == NULL || lista_vazia(lista))
        return 0;

    struct nodo *aux = lista->ini;
    struct nodo *temp = NULL;

    while (aux->prox != NULL) {
        temp = aux;
        aux = aux->prox;
    }

    *chave = aux->chave;

    if (temp == NULL) {
        free(aux);
        lista->ini = NULL;
    } else {
        temp->prox = NULL;
        free(aux);
    }

    lista->tamanho--;
    return 1;
}


/* remove da lista o elemento com a chave recebida */
/* decrementa o tamanho */
/* retorna 1 se sucesso e 0 se falha */
int lista_remove_ordenado (struct lista *lista, int chave){
	struct nodo *aux = lista->ini;

	if(aux->chave == chave){
		lista->ini = aux->prox;
		lista->tamanho--;
		free(aux);

		return 1;
	}

	struct nodo *temp = aux;
	while(aux->chave != chave){  /* aux->prox recebe elemento elemento com a chave recebida */
		temp = aux;
		aux = aux->prox;
	}

	/* novoNodo aponta para o prox de aux entao prox de aux recebe novoNodo, 
	para o ponteiro não ser perdido */
	temp->prox = aux->prox; 
	lista->tamanho--;
    	free(aux);


	return 0;
}

int lista_vazia (struct lista *lista){
   	if (lista->tamanho == 0) 
      	return 1;
   	else 
      	return 0;
}

int lista_tamanho (struct lista *lista){
   	return lista->tamanho;
}

int lista_pertence (struct lista *lista, int chave){
	struct nodo *aux = lista->ini;
	while (aux->chave != chave && aux->prox != NULL){
		aux = aux -> prox;
	}

	if (aux->chave == chave)
		return 1;
	else
		return 0;
}

void lista_inicia_iterador (struct lista *lista){
	lista->ptr = lista->ini;

	return;
}

/* incrementa lista->ptr em um e verifica se é válido */
int lista_incrementa_iterador(struct lista *lista, int *chave) {
    	if (lista == NULL || lista->ptr == NULL) {
        	return 0;  
    	}

    	*chave = lista->ptr->chave;   

    	lista->ptr = lista->ptr->prox;  

    	return 1;  
}
