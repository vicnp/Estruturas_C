#include <stdlib.h>
#include <stdio.h>

typedef struct Tipo_Lista Lista;

struct Tipo_Lista{
	int info;
	Lista *prox;
	Lista *ant;
};


Lista *criar(){
	return 0x00;
}


Lista *inserir(Lista *lista, int info){
	Lista *lista_ = (Lista *)malloc(sizeof(Lista));
	lista_->info = info;
	lista_->ant = 0x00;
	if(lista){
		lista_->prox = lista;
		lista->ant = lista_;
	}else{
		lista_->prox = 0x00;
	}
	
	return lista_;
}


void imprimir(Lista *lista){
	if(!lista){
		printf("Lista vazia!\n");
		return;
	}

	Lista *lista_ = lista;

	while(lista_){
		printf("\n%d\n", lista_->info);
		lista_ = lista_->prox;
	}
}

void imprimir_rev(Lista *lista){
	if(!lista){
		printf("Lista vazia!\n");
		return;
	}

	Lista *lista_ = lista;
	while(lista_->prox){
		lista_= lista_->prox;
	}
	while(lista_){
		printf("\n%d\n", lista_->info);
		lista_ = lista_->ant;
	}
}


Lista *remove_elemento(Lista *lista, int info){
	Lista *lista_ = lista;
    Lista *aux;

    if(!lista_)
        return lista_;

    if(lista_->info == info){
        if(lista_->prox == NULL){
            free(lista_);
            lista_ = NULL;
        }
        else{
            lista_ = lista_->prox;
            free(lista_->ant);
            lista_->ant = NULL;
        }
    }else{
        aux = lista_;

        while(aux!= NULL && aux->info != info)
            aux = aux->prox;

        if(aux == NULL)
            return lista_;

        if(aux->prox == NULL){
            aux->ant->prox = NULL;
            free(aux);
        }else{
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
        }
    }
    return lista_;
}

Lista *obter(Lista *lista, int info){
	 Lista *aux2;
	 aux2 = lista;

        while(aux2!= NULL && aux2->info != info)
            aux2 = aux2->prox;

        if(aux2 == NULL)
            return NULL;
      return aux2;

}

Lista *liberar(Lista *lista){
	Lista *lista_ = lista;
	Lista *lista_liberada;
	while(lista_->prox){
		lista_liberada = lista_;
		lista_= lista_->prox;
		free(lista_liberada);
	}
	lista_liberada = 0x00;
	lista_ = 0x00;
	return lista_;
}

int main(){

	Lista *lista;

	lista = criar();
	lista = inserir(lista, 1);
	lista = inserir(lista, 2);
	lista = inserir(lista, 3);
	lista = inserir(lista, 4);
	lista = inserir(lista, 5);
	lista = inserir(lista, 6);

	lista = liberar(lista);
	//lista = remove_elemento(lista, 4);

	printf("Normal\n");
	imprimir(lista);
	printf("Reverso\n");
	imprimir_rev(lista);
	
	return 0;
}



