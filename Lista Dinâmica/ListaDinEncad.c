#include <stdlib.h>
#include <stdio.h>
#include <ListaDinEncad.h>

//Definição do elemento da lista.
struct elemento
{
    //Campo para dados do elemento.
    struct aluno dados;
    //Campo com o ponteiro para o proximo elemento.
    struct elemento *prox;
};

typedef struct elemento Elem;

/*--------------------------- FUNÇÃO PRINCIPAL ---------------------------*/
int main()
{
    Lista *li;

    //Criação da lista
    li = cria_lista();

    //Tamanho da lista
    int tamanho = tamanho_lista(li);
    printf("Tamanho da lista: %d", tamanho);

    //Lista cheia
    if (lista_cheia(Lista * li))
    {
        printf("Esto non eqciste!!!");
    }
    else
    {
        printf("Uma lista dinâmica não fica cheia, pois não tem limite definido.");
    }

    //Lista vazia
    if (lista_vazia(li))
    {
        printf("A lista está vazia.");
    }
    else
    {
        int tam = tamanho_lista(li);
        printf("A lista não está vazia. Seu tamanho eh: %d", tam);
    }

    //Libera a lista
    libera_lista(li);
}

/*--------------------------- IMPLEMENTAÇÃO DAS FUNÇÕES ---------------------------*/
/*---------- FUNÇÕES BASICAS ----------*/
//Criação da lista
Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

//Liberação da lista
void libera_lista(Lista *li)
{
    if (li != NULL)
    {
        Elem *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

//Tamanho da lista
int tamanho_lista(Lista *li)
{
    //Verifica se a lista existe
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem *no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

//Lista cheia
//Uma lista dinâmica não tem limite, ou seja, nunca fica cheia. Só quando acabar a memória do computador
int lista_cheia(Lista *li)
{
    return 0;
}

//Lista vazia
int lista_vazia(Lista *li)
{
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

/*---------- FUNÇÕES DE INSERÇÃO ----------*/
int insere_lista_inicio(Lista *li, struct aluno al)
{
    //Verifica se a lista existe
    if (li == NULL)
        return 0;
    //Cria um novo elemento com a struct Elem e aloca o tamanho do elemento da memória
    Elem *no = (Elem *)malloc(sizeof(Elem));
    //Verifica se a alocação da memória funcionou.
    if (no == NULL)
        return 0;
    //Atribui o elemento a ser adicionado como primeiro elemento
    no->dados = al;
    //Coloca como proximo a própria lista.
    no->prox = (*li);
    //Substitui a lista li com a lista criada.
    *li = no;
    //Retorna verdadeiro.
    return 1;
}

int insere_lista_final(Lista *li, struct aluno al)
{
    //Verifica se a lista existe
    if (li == NULL)
        return 0;
    //Cria um novo elemento com a struct Elem e aloca o tamanho do elemento da memória
    Elem *no = (Elem *)malloc(sizeof(Elem));
    //Verifica se a alocação da memória funcionou.
    if (no == NULL)
        return 0;
    //Atribui o valor do novo elemento ao "no".
    no->dados = al;
    //Atribui o prox como NULL (Final da lista)
    no->prox = NULL;
    //Se a lista estiver adiciona o "no" na lista e será o ultimo elemento.
    if ((*li) == NULL)
    {
        *li = no;
    }
    //Se não percorrerá a lista até o elemento antes do NULL para adicionar o "no".
    else
    {
        Elem *aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}
