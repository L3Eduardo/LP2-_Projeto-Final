#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Struct do Parafuso
typedef struct{
char codigo[10], tparafuso[10], material[10];
int quantidadeest;
float preco;
}Produto;
//Struct do pedido
typedef struct{
char cliente[10];
int quantidade;
}Pedido;
//Função de Exclusão
void Exclusao(Produto produtos[], Pedido pedidos[], int N, int *total){
    int i, j;
    char codigo[10];
    printf("\n			Exclusao de dados\n\n");
    printf("\nCodigo: ");
    scanf("%s", codigo);
    for(i = 0; i < *total; i++){
        if(!strcmp(codigo, produtos[i].codigo)){
            for(j = i; j < *total-1; j++){
                    produtos[j] = produtos[j+1];
            }
            (*total)--;
            system("cls");
            return;
        }
    }
    printf("\nERRO: Produto nao cadastrado!\n");
}
// Função de Cadastro
void Cadastro(Produto produtos[], Pedido pedidos[], int N, int *total, int estoque, int est){
    if (*total == N){
        printf("\nERRO: Nao ha registro disponivel para cadastro\n");
        return;
    }
    printf("\n			Cadastro de Produto			\n\n");
    printf("\nCodigo: ");
    scanf("%s", produtos[*total].codigo);
    printf("\nParafuso: ");
    scanf("%s", produtos[*total].tparafuso);
    printf("\nMaterial: ");
    scanf("%s", produtos[*total].material);
    printf("\nQuantidade: ");
    scanf("%d", &produtos[*total].quantidadeest);
    printf("\nPreco de unidade: R$");
    scanf("%f", &produtos[*total].preco);
    
    printf("\n			Cadastro de Pedido			\n\n");
    
    printf("\nCliente: ");
    scanf("%s", pedidos[*total].cliente);
    printf("\nQuantidade no pedido: ");
    scanf("%d", &pedidos[*total].quantidade);
    system("cls");
    
    printf("			Processamento\n\n");
    
   		if(est = pedidos[*total].quantidade - estoque){	
   		 est >= 0; 
   			printf("Pedido pode ser atendido");
    		}
    	else{
    		printf("Pedido nao pode ser atendido");
    		printf("Estoque insuficiente!");
    		}
   	(*total)++;
}
// Função de Consulta
void Consulta(Produto produtos[], Pedido pedidos[], int N, int total){
    int i;
    char codigo[10];
    printf("\nConsulta de dados\n");
    printf("\nCodigo: ");
    scanf("%s", codigo);
    for(i = 0; i < total; i++){
        if(!strcmp(codigo, produtos[i].codigo)){
        	printf("			Dados do produto\n\n");
            printf("\nParafuso: %s", produtos[i].tparafuso);
            printf("\nQuantidade: %d", produtos[i].quantidadeest);
            printf("\nPreco de compra: R$%.2f", produtos[i].preco);         
            printf("\n			Dados do pedidos\n\n");
            printf("\nCliente: %s", pedidos[i].cliente);
            printf("\nQuantidade: %d", pedidos[i].quantidade);
            printf("\n Valor do pedido: R$%.2f", pedidos[i].quantidade*produtos[i].preco);
            printf("\n");
            system("pause");
            system("cls");
            return;
            
        }
    }
    printf("\nERRO: Produto nao cadastrado!\n");
}
//Função de Alteração
void Alteracao(Produto produtos[], Pedido pedidos[], int N, int total){
    int i;
    char codigo[30];

    printf("\n			Atualizacao de dados\n");
    printf("\nCodigo: ");
    scanf("%s", codigo);

    for(i = 0; i < total; i++){
        if(!strcmp(codigo, produtos[i].codigo)){
        	printf("		Dados do produto\n\n");
            printf("\nQuantidade: ");
            scanf("%d", &produtos[i].quantidadeest);
            printf("\nPreco de compra: R$");
            scanf("%f", &produtos[i].preco);
            printf("\n		Dados do Pedido\n\n");
            printf("\nCliente: ");
            scanf("%d", &pedidos[i].cliente);
            printf("\nQuantidade: ");
            scanf("%d", &pedidos[i].quantidade);
            printf("\n");
            system("pause");
            system("cls");
            return;
        }
    }
    printf("\nERRO: Produto nao cadastrado!\n");
}


int main(){
    int N, opcao = 1,  total = 0, estoque,est;
    
    printf("\n			Sistema de Controle de Pedido de Parafusos\n\n");
    // Quantidade de ficha que será disponibilizada
    printf("Quantidade de pedidos para realizar: ");
    scanf("%d", &N);
    //Quantidade de produto no estoque
    printf("Total de produto no estoque: ");
    scanf("%d", &estoque);
    //Chamando as struct
    Produto produtos[N];
	Pedido pedidos[N];
	//Laço do menu
    while(opcao != 5){
        printf("\nMenu\n");
        printf("\n1 - Cadastro de novo pedido");
        printf("\n2 - Consulta Pedido");
        printf("\n3 - Atualiza Pedido");
        printf("\n4 - Exclui Pedido");
        printf("\n5 - SAIR");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
		// Possivel caso
        switch(opcao){
        case 1:
            Cadastro(produtos, pedidos, N, &total, estoque, est);
            break;
        case 2:
            Consulta(produtos, pedidos, N, total);
            break;
        case 3:
            Alteracao(produtos, pedidos, N, total);
            break;
        case 4:
            Exclusao(produtos, pedidos, N, &total);
            break;
        }
    }

    return 0;
}
