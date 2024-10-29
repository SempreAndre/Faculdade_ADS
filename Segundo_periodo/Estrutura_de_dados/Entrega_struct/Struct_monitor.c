/****************************************************************** 
 * Nome: Struct_monitor                                           *
 * Descricao:                                                     *
 *                                                                *
 *                                                                *
 *                                                                *
 *                                                                *
 *                                                                *
 *                                                                *
 *                                                                *
 *                                                                *
 * Autor: André de França e Fábio Araújo                          *
 * Ultima alteração: 08/10/2024                                   *
 ******************************************************************/

/* blibliotecas usadas*/
#include <stdio.h>
#include <stdlib.h>
/*Definir constantes*/
#define TAM 5
/* definição das listas*/
typedef struct lista lista;
typedef struct monitor monitor;
struct monitor{
   int id_monitor;
   char lote[8];
   char modelo[30];
   char gamer[1];
   int  tamanho;
   char dt_fab[10];
   float peso;
   char marca[200];
   monitor *prox;
};
struct lista
{
    int id_monitor;
    monitor *prim;
};


/*Funções*/
int atualizarMonitor(Lista*, int, int);

/*-------------*/
int main(){

}
/*-------*/
lista* criarLista(){
    /*solicitando espaco para a lista*/
    lista *nova = (lista*)malloc(sizeof(lista));

    /*Verificando se o espaco foi resevado*/
    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }

    /*Preparando os dados iniciais da lista*/
    nova->id_monitor = 0; 
    nova->prim = (monitor*)malloc(sizeof(monitor));

    
    /*Verificando se o espaco foi resevado*/
    if(nova->prim == NULL){
        printf("Nao tem espaco\n");
        free(nova); //liberando o espaco de lista
        return NULL;
    }

    /*Retonando o espaco resevado*/
    return nova;
}