#include <stdio.h>
#include <stdlib.h>
typedef struct Tipo_Lista Lista;

struct Tipo_Lista{
	int info;
	Lista *prox;
};


struct Tipo_Pilha{
	Lista *topo;
};

typedef struct Tipo_Pilha Pilha;

Pilha *iniciar_pilha(Pilha *pilha){

	Pilha *pilha_ = (Pilha *)malloc(sizeof(Pilha));
    pilha_->topo = NULL;
    return(pilha_);
}

Pilha *inserir(Pilha *pilha, int info){
	Pilha *pilha_ = pilha;
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	lista->info = info;
	lista->prox = pilha_->topo;

	pilha_->topo = lista;

	return(pilha_);
}

Pilha *desempilhar(Pilha *pilha){
	Pilha *pilha_ = pilha;
	Lista *lista = pilha_->topo;
	pilha_->topo = lista->prox;
	free(lista);
	return(pilha_);
}

int imprimir(Pilha *pilha){
	Pilha *pilha_ = pilha;
	if(pilha_ == 0x00 || pilha_->topo == 0x00){
		return 1;
	}

	Lista *lista = pilha->topo;

	while(lista != 0x00){
		printf("\nDado:%d\n\n", lista->info);
		lista = lista->prox;
	}
}

int verificar_pilha(Pilha *pilha){
	if(pilha == 0x00 || pilha->topo == 0x00){
		return (1);
	}else{
		return (0);
	}
}

Lista *obtopo(Pilha *pilha){
	Pilha* pilha_ = pilha;
	Lista *lista_topo = pilha_->topo;
	return(lista_topo);
}

int verificar_igualdade(Pilha *pilha1, Pilha *pilha2){
	if(pilha1 == 0x00 || pilha2 == 0x00 || pilha1->topo == 0x00 || pilha2->topo == 0x00){
		printf("Uma das pilhas está vazia !\n");
		return 0;
	}

	Lista *lista1 = pilha1->topo;
	Lista *lista2 = pilha2->topo;

	while(lista1 != 0x00 && lista2 != 0x00){
		if(lista1->info != lista2->info){
			//Não faz nada
			}else{
				return 0;
			}

		lista1=lista1->prox;
		lista2=lista2->prox;
	}
return 1;
}

Pilha *desempilha2(Pilha *pilha){
	Pilha* pilhaf;
	int i = 0;
	while(i < 2){		
		Pilha *pilha_ = pilha;
		Lista *lista = pilha_->topo;
		pilha_->topo = lista->prox;
		free(lista);
		pilhaf = pilha_;
		i++;
	}
	return pilhaf;
}

Pilha *libera(Pilha *pilha){
	Pilha *pilha_ = pilha;
	Lista *lista = pilha_->topo;

  Lista *p = lista;

   if(lista!=NULL)
   {
      while(p!=NULL)
      {
         p=lista->prox;
         free(lista);
         lista=p;
      }
      free(pilha_);
   }
    return pilha_;
}

Pilha *desempilhan(Pilha *pilha, int n){
	Pilha* pilhaf;
	
	int i = 0;
	int j = n;
	while(i < j){		
		Pilha *pilha_ = pilha;
		Lista *lista = pilha_->topo;
		pilha_->topo = lista->prox;
		free(lista);
		pilhaf = pilha_;
		i++;
	}
	return pilhaf;
}


int main(){	

	Pilha *pilha;
	pilha = iniciar_pilha(pilha);
	pilha = inserir(pilha, 7);
	pilha = inserir(pilha, 6);
	pilha = inserir(pilha, 5);
	pilha = inserir(pilha, 4);
	pilha = inserir(pilha, 3);
	pilha = inserir(pilha, 2);
	pilha = inserir(pilha, 1);
	
	int error = imprimir(pilha);

	return 0;
}
