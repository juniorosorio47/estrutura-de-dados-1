#include <stdlib.h>
#include <stdio.h>
#include <ListaDinEncad.h>

//Definição do elemento da lista.
struct elemento{
    //Campo para dados do elemento.
    struct aluno dados;
    //Campo com o ponteiro para o proximo elemento.
    struct elemento *prox;
};
 
typedef struct elemento Elem;

/*--------------------------- FUNÇÃO PRINCIPAL ---------------------------*/
int main(){
    Lista *li;

    //Criação da lista
    li = cria_lista();

    //Tamanho da lista
    int tamanho = tamanho_lista(li);
    printf("Tamanho da lista: %d", tamanho);

    //Lista cheia
    if(lista_cheia(Lista* li)){
        printf("Esto non eqciste!!!");
    }else{
        printf("Uma lista dinâmica não fica cheia, pois não tem limite definido.");
    }

    //Lista vazia
    if(lista_vazia(li)){
        printf("A lista está vazia.");
    }else{
        int tam = tamanho_lista(li);
        printf("A lista não está vazia. Seu tamanho eh: %d", tam);
    }


    //Libera a lista
    libera_lista(li);
}

/*--------------------------- IMPLEMENTAÇÃO DAS FUNÇÕES ---------------------------*/
//Criação da lista
Lista* cria_lista(){
    Lista* li = (Lista*) malloc (sizeof (Lista));
    if( li != NULL)
        *li = NULL;
    return li;
}

//Liberação da lista
void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

//Tamanho da lista
int tamanho_lista(Lista* li){
    //Verifica se a lista existe
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

//Lista cheia
//Uma lista dinâmica não tem limite, ou seja, nunca fica cheia. Só quando acabar a memória do computador
int lista_cheia(Lista* li){
    return 0;
}

//Lista vazia
int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}