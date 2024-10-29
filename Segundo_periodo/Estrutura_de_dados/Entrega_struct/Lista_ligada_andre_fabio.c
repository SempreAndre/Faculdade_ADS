#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Define a estrutura*/
typedef struct Monitor {
    int id_monitor;
    char lote[8];
    char modelo[30];
    char gamer[1];
    int tamanho;
    char dt_fab[10];
    float peso;
    char marca[200];
} Monitor;
/*Cria uma estrutura para armazenar a lista de monitores*/
typedef struct Lista {
    Monitor *monitores;/*ponteiro que aponta para a estrutura de monitor*/
    int id;/*tamanho da lista*/
    int capacidade;/*define o tamanho da lista(estoque de monitores)*/
} Lista;
/*Criar lista*/
Lista* criarLista(int capacidade) {
    Lista *lista = (Lista*)malloc(sizeof(Lista));/*Tenta reservar espaço pra lista(estoque)*/
    if (lista == NULL){
        printf("Não foi possivel alocar memoria");
        return NULL;
    }    
    lista->monitores = (Monitor*)malloc(capacidade * sizeof(Monitor));/*Reserva espaço para o monitor*/
    if (lista->monitores == NULL){
        printf("Não foi possível reservar espaço na memoria");
        return NULL;
    }    
    lista->id = 0;/*define o tamanho inicial do estoque(lista)*/
    lista->capacidade = capacidade;/*define o tamanho max do estoque(lista)*/
    return lista;
}
/* inserir no fim*/
void inserirElemento(Lista *lista, Monitor monitor) {
    if (lista == NULL){
        printf("lista não foi criada");
        return;
    }
    if (lista->id == lista->capacidade) {
        printf("Lista cheia!\n");
        return;
    }
    lista->monitores[lista->id] = monitor;/*lista->monitores[0] = monitor(1 rodada)*/
    lista->id++;/*incrementa o id*/
}
/*inserir em uma posição*/
void inserirElementoID(Lista *lista, Monitor monitor, int posicao) {
      if (lista == NULL){
        printf("lista não foi criada");
        return;
    }
    if (posicao < 0 || posicao > lista->id) {
        printf("Posição inválida!\n");
        return;
    }
    if (lista->id == lista->capacidade) {
        printf("Lista cheia!\n");
        return;
    }
    for (int i = lista->id; i > posicao; i--) {
        lista->monitores[i] = lista->monitores[i - 1];
    }
    lista->monitores[posicao] = monitor;
    lista->id++;
}
/*insere no inicio*/
void inserirElementoInicio(Lista *lista, Monitor monitor) {
      if (lista == NULL){
        printf("lista não foi criada");
        return;
    }
    inserirElementoID(lista, monitor, 0);/*chama a função de inserir em qualquer posição para inserir no primeiro elemento*/
}
/*Listar*/
void listarElementos(Lista *lista) {
      if (lista == NULL){
        printf("lista não foi criada");
        return;
    } 
    if (lista->id < 0)
    {
        printf("Lista não possui nenhum monitor");
    }       
    for (int i = 0; i < lista->id; i++) {/*Percorre todo o vetor imprimindo todos os elementos*/
        printf("----------------------------------------------\n");
        printf("Monitor ID: %d\n", lista->monitores[i].id_monitor);
        printf("Lote: %s\n", lista->monitores[i].lote);
        printf("Modelo: %s\n", lista->monitores[i].modelo);
        printf("Gamer: %s\n", lista->monitores[i].gamer);
        printf("Tamanho: %d\n", lista->monitores[i].tamanho);
        printf("Data de Fabricação: %s\n", lista->monitores[i].dt_fab);
        printf("Peso: %.2f\n", lista->monitores[i].peso);
        printf("Marca: %s\n", lista->monitores[i].marca);
        printf("----------------------------------------------\n");
    }
}
/*Remover*/
void removerElemento(Lista *lista, int posicao) {
    if (posicao < 0 || posicao >= lista->id) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = posicao; i < lista->id - 1; i++) {
        lista->monitores[i] = lista->monitores[i + 1];
    }
    lista->id--;
}
/*Atualiza*/
void atualizarElemento(Lista *lista, int posicao, Monitor monitor) {
    if (posicao < 0 || posicao >= lista->id) {
        printf("Posição inválida!\n");
        return;
    }
    lista->monitores[posicao] = monitor;
}
/*Bucar*/
Monitor* buscarElemento(Lista *lista, int id_monitor) {
    for (int i = 0; i < lista->id; i++) {
        if (lista->monitores[i].id_monitor == id_monitor) {
            return &lista->monitores[i];
        }
    }
    return NULL;
}
/*Tamanho Lista*/
int tamanho(Lista *lista) {
    if (lista == NULL){
        printf("lista não foi criada");
        return 0;
    }
    return lista->id;
}
/*Excluir lista*/
void excluirLista(Lista *lista) {
    if (lista == NULL){
        printf("lista não foi criada");
        return;
    }
    free(lista->monitores);
    free(lista);
}
/*carregar*/
void carregarDados(Lista *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fscanf(arquivo, "%d %s %s %s %d %s %f %s", &lista->monitores[lista->id].id_monitor,
                  lista->monitores[lista->id].lote, lista->monitores[lista->id].modelo,
                  lista->monitores[lista->id].gamer, &lista->monitores[lista->id].tamanho,
                  lista->monitores[lista->id].dt_fab, &lista->monitores[lista->id].peso,
                  lista->monitores[lista->id].marca) != EOF) {
        lista->id++;
    }

    fclose(arquivo);
}
/*Salvar*/
void salvarDados(Lista *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    if (lista == NULL){
        printf("lista não foi criada");
        return;
    }
    for (int i = 0; i < lista->id; i++) {
        fprintf(arquivo, "%d %s %s %s %d %s %.2f %s\n", lista->monitores[i].id_monitor,
                lista->monitores[i].lote, lista->monitores[i].modelo,
                lista->monitores[i].gamer, lista->monitores[i].tamanho,
                lista->monitores[i].dt_fab, lista->monitores[i].peso,
                lista->monitores[i].marca);
    }
    fclose(arquivo);
}
/*main*/
int main() {
    Lista *lista = criarLista(100); // Capacidade inicial de 100 monitores

    // Exemplo de uso
    Monitor monitor1 = {1, "1234567", "ModeloA", "N", 27, "2023-01-01", 4.5, "AOC"};
    Monitor monitor2 = {2, "7654321", "ModeloB", "S", 32, "2024-05-10", 5.2, "PHILIPS"};
    Monitor monitor3 = {3, "ABDR485", "ModeloC", "S", 32, "2024-09-29", 7.0, "PHILIPS"};

    inserirElemento(lista, monitor1);
    inserirElemento(lista, monitor2);
    inserirElemento(lista, monitor3);

    listarElementos(lista);

    salvarDados(lista, "monitores.txt");
    excluirLista(lista);

    return 0;
}
