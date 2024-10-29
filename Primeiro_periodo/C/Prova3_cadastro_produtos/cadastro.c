#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define Max_prod 100
typedef struct 
{
    int Cod_prod;
    char Nm_prod[30];
    char Desc_prod[250];
    float Vlr_prod;
    char Nm_lote[8];
    int Qtd_prod;    
}produto;
produto Produtos[Max_prod];
int cod_prod = 1;
void gravarProdutos(produto gravar) {
    FILE *file;
    file = fopen("produtos.txt", "a");
    if (file == NULL) {      
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fprintf(file, "===========================\n");
    fprintf(file, "Código do produto: %d\n", gravar.Cod_prod);
    fprintf(file, "Nome do produto: %s\n", gravar.Nm_prod);
    fprintf(file, "Descrição: %s\n", gravar.Desc_prod);
    fprintf(file, "Preço: %.2f\n", gravar.Vlr_prod);
    fprintf(file, "Quantidade: %d\n", gravar.Qtd_prod);
    fprintf(file, "Lote: %s\n", gravar.Nm_lote);
    fprintf(file, "===========================\n");
    fclose(file);
}
void cadastro(){
    setlocale(LC_ALL,"portuguese_Brazil");
    printf("O código do produto é: %d\n", cod_prod);
    for(int i=1;i<99;i++ ){
        char c;
        while((c = getchar()) != '\n' && c != EOF);
        printf("Digite o nome do produto:\n");
        char nm_prod[30];
        fgets(nm_prod, sizeof(nm_prod), stdin);
        printf("Digite a descrição do produto:\n");
        char desc_prod[250];
        fgets(desc_prod, sizeof(desc_prod), stdin);
        printf("Digite Preço do produto:\n");
        float vlr_prod;
        scanf("%f", &vlr_prod);
        printf("Digite qual a quantidade do produto:\n");
        int qtd_prod;
        scanf("%i", &qtd_prod);
        getchar();
        printf("Digite o Lote do produto:\n");
        char nm_lote[8];
        fgets(nm_lote, sizeof(nm_lote), stdin);
        produto produtos = {.Cod_prod = cod_prod, .Vlr_prod = vlr_prod, .Qtd_prod = qtd_prod};
        strcpy(produtos.Nm_prod, nm_prod);
        strcpy(produtos.Desc_prod, desc_prod);
        strcpy(produtos.Nm_lote, nm_lote);
        Produtos[cod_prod].Cod_prod = cod_prod; 
        Produtos[cod_prod] = produtos;
        gravarProdutos(produtos);     
        printf("\e[1;1H\e[2J");
        getchar();
        printf("produto cadastrado: %i\n", Produtos[cod_prod].Cod_prod);
        printf("Deseja cadastrar um novo produto? (S/N)\n");
        char n_prod;
        scanf(" %c", &n_prod);
        if (n_prod == 'N'|| n_prod == 'n'){
            cod_prod++;
            break;
        }
     cod_prod++;
    }
}
void alterar(){
    setlocale(LC_ALL,"portuguese_Brazil");
    printf("Digite qual o código do produto a qual deseja alterar:\n");
    int mudar_prod;
    scanf("%i", &mudar_prod);
    printf("Código do produto: %i\n",Produtos[mudar_prod].Cod_prod);
    printf("Nome do produto: %s\n",Produtos[mudar_prod].Nm_prod);
    printf("Descrição do produto: %s\n",Produtos[mudar_prod].Desc_prod);
    printf("Lote do produto: %s\n",Produtos[mudar_prod].Nm_lote);
    printf("Quantidade do produto: %i\n",Produtos[mudar_prod].Qtd_prod);
    printf("Valor do produto: %.2f\n",Produtos[mudar_prod].Vlr_prod);
    printf("Oque deseja mudar?\n");
    printf("1 - Produtos do produto\n");
    printf("2 - Descrição do produto\n");
    printf("3 - Numero do lote\n");
    printf("4 - Valor do produto\n");
    printf("5 - Quantidade do produto\n");
    int select;
    getchar();
    scanf(" %i", &select);
    switch (select)
    {
    case 1:
        printf("\e[1;1H\e[2J");
        printf("Qual o Nome correto:\n");
        char nome[30];
        fgets(nome, sizeof(nome), stdin);
        strcpy(Produtos[mudar_prod].Nm_prod, nome);
        break;
    case 2:
        printf("\e[1;1H\e[2J");
        printf("Qual a descrição correta:\n");
        char descricao[250];
        fgets(descricao, sizeof(descricao), stdin);
        strcpy(Produtos[mudar_prod].Desc_prod, descricao);
        break;
    case 3:
        printf("\e[1;1H\e[2J");
        printf("Qual o lote correto:\n");
        char lote[8];
        fgets(lote, sizeof(lote), stdin);
        strcpy(Produtos[mudar_prod].Nm_lote, lote);
        break;
    case 4:
        printf("\e[1;1H\e[2J");
        printf("Qual o valor correto do produto:\n");
        float valor;
        scanf(" %f", &valor);
        Produtos[mudar_prod].Vlr_prod = valor;
        break;
    case 5:
        printf("\e[1;1H\e[2J");
        printf("Qual a quantidade correta do produto:\n");
        int qtd;
        scanf(" %i", &qtd);
        Produtos[mudar_prod].Qtd_prod = qtd;
        break;    
    default:
        printf("\e[1;1H\e[2J");
        printf("Digite uma opção valida!");
        break;
    }
}
void Exibir(){
    setlocale(LC_ALL,"portuguese_Brazil");
    printf("Deseja exibir todos os produtos(1) ou apenas um(2)?");
    int e;
    scanf(" %i", &e);
    switch (e){
    case 1:
    printf("================Produtos================\n");
    for(int j=1; j<cod_prod; j++){
        printf("Codigo do produto: %i\n",Produtos[j].Cod_prod);
        printf("Nome do produto: %s\n",Produtos[j].Nm_prod);
        printf("Descrição do produto: %s\n",Produtos[j].Desc_prod);
        printf("Lote do produto: %s\n",Produtos[j].Nm_lote);
        printf("Quantidade do produto: %i\n",Produtos[j].Qtd_prod);
        printf("Valor do produto: %.2f\n",Produtos[j].Vlr_prod);
        printf("========================================\n");
        }
        break;
    case 2:
        printf("\e[1;1H\e[2J");
        printf("Digite qual o código do produto a qual deseja visualizar:\n");
        int visual;
        scanf(" %i", &visual);
        printf("\n================Produto %i================\n", visual);
        printf("Código do produto: %i\n",Produtos[visual].Cod_prod);
        printf("Nome do produto: %s\n",Produtos[visual].Nm_prod);
        printf("Descrição do produto: %s\n",Produtos[visual].Desc_prod);
        printf("Lote do produto: %s\n",Produtos[visual].Nm_lote);
        printf("Quantidade do produto: %i\n",Produtos[visual].Qtd_prod);
        printf("Valor do produto: %.2f\n",Produtos[visual].Vlr_prod);
        printf("========================================\n");   
        break;   
    default:
        break;
    }    
}
int main(){
setlocale(LC_ALL,"portuguese_Brazil");
int menu = 1;
int escolha;
printf("===============Cadastro Produtos===============\n");
printf("=============By Malucos funcionais=============\n");
while (menu == 1){
    printf("Escolha uma opção para o cadastro do produto:\n");
    printf("1 - Cadastrar\n");
    printf("2 - Alterar\n");
    printf("3 - Conferir\n");
    printf("4 - Sair\n");
    scanf(" %i", &escolha );
    switch(escolha){
        case 1:
            printf("\e[1;1H\e[2J");
            cadastro();
        break;
        case 2:
            printf("\e[1;1H\e[2J");
            alterar();
        break;
        case 3:
            printf("\e[1;1H\e[2J");
            Exibir();
        break;
        case 4:
            printf("\e[1;1H\e[2J");
            printf("Obrigado por escolher nosso cadastro");
            menu=0;
        break;   
        default:
            printf("Escolha uma opção valida!!");
        break;
    }
}
return 0;
}