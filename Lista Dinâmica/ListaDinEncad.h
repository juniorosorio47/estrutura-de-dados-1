//Definição da struct aluno que será guardado dentro da lista.
struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

//Apelido para lista.
//Um ponteiro para ponteiro, ou seja, é um ponteiro e tem um ponteiro dentro.
typedef struct elemento *Lista;

/*---------- DEFINIÇÃO DAS FUNÇÕES ----------*/
/*---------- FUNÇÕES BASICAS ----------*/
//Criação da lista, inicializa a lista.
Lista *cria_lista();

//Liberação da lista
void libera_lista(Lista *li);

//Tamanho da lista
int tamanho_lista(Lista *li);

//Lista cheia
int lista_cheia(Lista *li);

//Lista vazia
int lista_vazia(Lista *li);

/*---------- FUNÇÕES DE INSERÇÃO ----------*/
//Inserir no inicio da lista
int insere_lista_inicio(Lista *li, struct aluno al);

//Inserir no final da lista
int insere_lista_final(Lista *li, struct aluno al);
