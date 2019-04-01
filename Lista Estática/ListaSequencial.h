//Tamanho máximo do vetor.
#define MAX 100

//Definição da struct aluno que será guardado dentro da lista.
struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

//Apelido para lista.
typedef struct lista Lista;

/*---------- DEFINIÇÃO DAS FUNÇÕES ----------*/
//Criação da lista, inicializa a lista.
Lista* cria_lista();

//Liberar a lista.
void libera_lista(Lista* li);

//Verificar o tamanho da lista.
int tamanho_lista(Lista* li);

//Verificar se a lista está cheia.
int lista_cheia(Lista* li);

//Verificar se a lista está vazia.
int lista_vazia(Lista* li);


/*---------------- INSERÇÕES ----------------*/
//Inserção ao final da lista.
int insere_lista_final(Lista* li, struct aluno al);

//Inserção ao início da lista.
int insere_lista_inicio(Lista* li, struct aluno al);

//Inserção de forma ordenada.
int insere_lista_ordenada(Lista* li, struct aluno al);


/*---------------- REMOÇÕES ----------------*/
//Remover do final
int remove_lista_final(Lista* li);

//Remover do inicio
int remove_lista_inicio(Lista* li);

//Remover um elemento escolhido
int remove_lista(Lista*, int mat);


/*---------------- CONSULTAS ----------------*/
//Consulta lista posição
int consulta_lista_posicao(Lista* li, int pos, struct aluno *al);

//Consultar lista por matricula.
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);


