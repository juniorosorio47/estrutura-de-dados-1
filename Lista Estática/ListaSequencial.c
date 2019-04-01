#include <stdlib.h>
#include <stdio.h>
#include <ListaSequencial.h>

//Definição da struct lista
struct lista
{
    //Representa a primeira posição vaga.
    int qtd;
    struct aluno dados[MAX];
};

/*--------------------------- FUNÇÃO PRINCIPAL ---------------------------*/

int main(){
    //Declaração de um ponteiro para a struct lista
    Lista *li;
    aluno dados_aluno;

    //Dados do aluno
    dados_aluno.matricula = 001;
    dados_aluno.n1 = 80;
    dados_aluno.n2 = 90;
    dados_aluno.n3 = 60;
    dados_aluno.nome = "Fulaninho";

    //Função para criar a lista
    li = cria_lista();


    //Verificar o tamanho da lista
    int tamanhoLista = tamanho_lista(li);
    printf("O tamanho da lista eh: %d", tamanhoLista);


    //Verifica se a lista está cheia
    //Retorna "true" ou "false"
    if(lista_cheia(li)){
        printf("A lista está cheia.");
    }else{
        printf("A lista não está cheia.");
    }


    //Verifica se a lista está vazia
    //Retorna "true" ou "false"
    if(lista_vazia(Lista* li)){
        printf("A lista está vazia.");
    }else{
        printf("A lista não está vazia.");
    }

    //Inserir dados no final da lista.
    int insereFinal = insere_lista_final(li, dados_aluno);
    if(insereFinal){
        printf("Dados inseridos no final da lista com sucesso.");
    }else{
        printf("A lista não existe ou está cheia.");
    }


    //Inserir dados no inicio da lista.
    int insereInicio = insere_lista_inicio(li, dados_aluno);
    if(insereInicio){
        printf("Dados inseridos no começo da lista com sucesso.");
    }else{
        printf("A lista não existe ou está cheia.");
    }

    //Inserir dados no inicio da lista.
    int insereOrdenada = insere_lista_ordenada(li, dados_aluno);
    if(insereOrdenada){
        printf("Dados inseridos de forma ordenada com sucesso.");
    }else{
        printf("A lista não existe ou está cheia.");
    }

    //Remover do final da lista
    int removeFinal = remove_lista_final(li, dados_aluno);
    if(removeFinal){
        printf("Dado removido do final da lista com sucesso.");
    }else{
        printf("A lista não existe ou está ja esta vazia.");
    }

    //Remover qualquer ítem
    int removeLista = remove_lista(li, dados_aluno.matricula);
    if(removeFinal){
        printf("Dado de aluno removido.");
    }else{
        printf("A lista não existe ou está ja esta vazia.");
    }

    //Consultar dados
    int posicao = 2;
    int consultaPos = consulta_lista_posicao(li, posicao, &dados_aluno);
    if(consultaPos){
        printf("Matrícula: %d", dados_aluno.matricula);
        printf("Nome: %s", dados_aluno.nome);
        printf("Nota 1 bimestre: %f", dados_aluno.n1);
        printf("Nota 2 bimestre: %f", dados_aluno.n2);
        printf("Nota 3 bimestre: %f", dados_aluno.n3);
    }else{
        printf("A lista ou a posicao não existem ou a posicao eh maior que o tamanho da lista.");
    }

    //Consultar dados pela matrícula.
    int consultaMat = consulta_lista_mat(li, mat, &dados_aluno);
    if(consultaMat){
        printf("Matrícula: %d", dados_aluno.matricula);
        printf("Nome: %s", dados_aluno.nome);
        printf("Nota 1 bimestre: %f", dados_aluno.n1);
        printf("Nota 2 bimestre: %f", dados_aluno.n2);
        printf("Nota 3 bimestre: %f", dados_aluno.n3);
    }else{
        printf("A lista ou a matricula não existem.");
    }


    //Função para excluir/liberar a lista
    libera_lista(li);

}


/*--------------------------- IMPLEMENTAÇÃO DAS FUNÇÕES ---------------------------*/

/*--------- FUNÇÕES BÁSICAS DE LISTAS ---------*/
//Criação da lista
Lista* cria_lista(){
    //Ponteiro para lista
    Lista *li;

    //Alocação dinâmica de memória com o tamanho da struct lista
    li = (Lista*) malloc (sizeof (struct lista));

    //Verifica se funcionou a alocação de memória
    if(li != NULL)
        li->qtd = 0;
    return li;
}

//Liberação da lista
void libera_lista(Lista* li){
    free(li);
}

//Tamanho da lista
int tamanho_lista(Lista* li){
    //Verifica se existe a lista
    
    if(li == NULL)
        //Retornando um número negativo aparecerá um erro e saberemos que não existe a lista
        return -1;
    //Caso existir a lista retonamos o tamanho dela
    //Com o operador "->" acessamos o conteúdo do ponteiro
    else
        return li->qtd;
}

//Lista cheia
int lista_cheia(Lista* li){
    //Verifica se existe a lista
    if(li == NULL)
        return -1;
    //Verifica se o tamanho da lista é o mesmo do tamanho máximo
    //Retornando "true" se for ou "false" se não for.
    return (li->qtd == MAX);
}

//Lista vazia
int lista_vazia(Lista* li){
    //Verifica se existe a lista.
    if(li == NULL)
        return -1;
    //Verifica se o tamanho da lista é igual a zero.
    //Retornando "true" se for ou "false" se não for.
    return (li->qtd == 0);
}


/*--------- FUNÇÕES DE INSERÇÃO NAS LISTAS ---------*/
//Inserir ao final da lista
int insere_lista_final(Lista* li, struct aluno al){
    //Verifica se existe a lista.
    if(li == NULL)
        return 0;
    //Verifica se a lista está cheia, pois não se pode inserir dados em uma lista cheia.
    if(lista_cheia(li))
        return 0;
    //Adiciona o dado na lista.
    li->dados[li->qtd] = al;
    //Acrescenta a quantidade.
    li->qtd++;
    return 1
}

//Inserir no início da lista.
int insere_lista_inicio(Lista* li, struct al){
    //Verifica se existe a lista
    if(li == NULL)
        return 0;
    //Verifica se a lista está cheia, pois não se pode inserir dados em uma lista cheia.
    if(lista_cheia(li)) 
        return 0;

    int i;
    //Percorre toda a lista passando os dados para a casa da frente.
    for(i = li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    //Insere o novo dado na posição zero(inicio).
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

//Inserir de forma ordenada.
int insere_lista_ordenada(Lista* li, struct aluno al){
    //Verifica se existe a lista
    if(li == NULL)
        return 0;
    //Verifica se a lista está cheia, pois não se pode inserir dados em uma lista cheia.
    if(lista_cheia(li)) 
        return 0;
    
    int k, i = 0;
    //Busca aonde vai inserir o dado.
    //Procurando inserir de forma ordenada pela matrícula.
    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;
    //Percorre toda a lista passando os dados para a casa da frente.
    for(k = li->qtd; k >= i; k--)
        li->dados[k+1] = li->dados[k];
    //Inserir na posição i ao sair do loop while
    li->dados[i] = al;
    li->qtd++;
    return 1;
}


/*--------- FUNÇÕES DE REMOÇÃO NAS LISTAS ---------*/
//Remover do final
int remove_lista_final(Lista* li){
    //Verifica se existe a lista
    if(li == NULL)
        return 0;
    //Verifica se a lista está vazia
    if(li->qtd == 0)
        return 0;
    //Remove o ultimo elemento
    li->qtd--;
    return 1;
}

//Remover do inicio
int remove_lista_inicio(Lista* li){
    //Verifica se existe a lista
    if(li == NULL)
        return 0;
    //Verifica se a lista está vazia
    if(li->qtd == 0)
        return 0;
    
    int k=0;
    //Empurrando os elementos da lista para frente
    for(k = 0; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1]
    li->qtd--;
    return 1;
}

//Remover um ítem qualquer
int remove_lista(Lista*, int mat){
    //Verifica se existe a lista
    if(li == NULL)
        return 0;
    //Verifica se a lista está vazia
    if(li->qtd == 0)
        return 0;

    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;
    
    for(k = i; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}


/*--------- FUNÇÕES DE CONSULTA NAS LISTAS ---------*/
//Consultar lista por posição.
int consulta_lista_posicao(Lista* li, int pos, struct aluno *al){
    //Verifica se a lista existe, se a posição é maior que 0 e se a posicao não é maior que o tamanho da lista
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

//Consultar lista por matricula.
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    //Verifica se existe a lista
    if(li == NULL)
        return 0;
    
    int k, i=0;
    //Busca na lista um elemento com a matricula igual a informada
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;
    //Insere no endereço do ponteiro as informações encontradas.
    *al = li->dados[i];
    return 1;
}