#include <stdlib.h>
#include <stdio.h>


typedef struct Tipo_Lista Lista;

struct Tipo_Lista{
	int info;
	Lista *prox; 
};

Lista *criar();

Lista *inserir(Lista *lista, int info);

void destroi(Lista* lista);

int main(int argc, char const *argv[]){

	Lista *lista = criar();
	lista = inserir(lista, 100);
	lista = inserir(lista, 150);
	lista = inserir(lista, 120);
	destroi(lista);
	return 0;
}

Lista *criar(){

	return 0x00;
}

Lista *inserir(Lista *lista, int info){
	Lista *lista_nova= (Lista *)malloc(sizeof(Lista));
	lista_nova->info = info;

	if(!lista){
		lista_nova->prox = lista_nova;
	}else{
		lista_nova->prox = lista->prox;
		lista->prox = lista_nova;
	}
	return(lista_nova);
}

void destroi(Lista* lista){
    if(lista == NULL) return;

    Lista *loop = lista->prox, *deleta;

    while(loop != lista){ 
        deleta = loop;
        loop = loop->prox;
        free(deleta);
        deleta = NULL;
    }

    free(lista); 
    lista = loop = NULL;
}

void imprimir(Lista *lista){

}


Lista *remover(Lista *lista, int info){
	Lista *lista_aux = lista-prox;
	Lista *lista_atual = lista;

	while(lista_aux != lista_atual){
		if(lista_aux->info == info){
			
			free(lista_atual);
		}
		lista_aux = lista_aux->prox;
	}


}