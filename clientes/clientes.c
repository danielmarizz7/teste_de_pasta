#include <stdio.h>
#include <stdlib.h>
#include <string.h> //usar o "strcmp"
#include <unistd.h>
#include "utilidades.h"
#include "clientes.h"
#include <locale.h>
// #include <windows.h>

FILE * arquivo_cliente; //Apontador do arquivo

void modulo_clientes(void){
    char opcao;
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];

    do {
        opcao = tela_de_clientes();
        switch(opcao){
            case '1':   cadastrar_clientes(nome, cpf, email, telefone);
                        break;
            case '2':   exibir_clientes(nome, cpf, email, telefone);
                        break;
            case '3':   alterar_cliente();
                        break;
            case '4':   excluir_cliente();
                        break;

        }
    } while (opcao != '0');
}



char tela_de_clientes(void){
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);

    char op_cliente;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Módulo De Clientes                ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Cadastrar Cliente                           ║\n");
    printf("║ 2 - Exibir Clientes                             ║\n");
    printf("║ 3 - Editar Cliente                              ║\n");
    printf("║ 4 - Excluir Cliente                             ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_cliente);
    return op_cliente;
}



void cadastrar_clientes(char nome[], char cpf[], char email[], char telefone[]){
    int id_cliente = 0;
    limpar_buffer();
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Cadastrar Clientes                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do cliente: ");
    scanf("%[^\n]", nome);
    limpar_buffer();

    printf("Digite o CPF do cliente: ");
    scanf("%[^\n]", cpf);
    limpar_buffer();

    printf("Digite o email do cliente: ");
    scanf("%[^\n]", email);
    limpar_buffer();

    printf("Digite o telefone do cliente: ");
    scanf("%[^\n]", telefone);
    limpar_buffer();

    arquivo_cliente = fopen("clientes.csv", "rt");

    if (arquivo_cliente == NULL) {
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "wt");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "rt");
    }

    id_cliente = gerar_id(arquivo_cliente);

    fclose(arquivo_cliente);
    
    arquivo_cliente = fopen("clientes.csv", "at"); //Cria o arquivo
    if (arquivo_cliente == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
        fclose(arquivo_cliente);
    }
    else
    {
        //Escreve coisas no arquivo
        fprintf(arquivo_cliente, "%d;", id_cliente);
        fprintf(arquivo_cliente, "%s;", nome);
        fprintf(arquivo_cliente, "%s;", cpf);
        fprintf(arquivo_cliente, "%s;", email);
        fprintf(arquivo_cliente, "%s\n", telefone);
        fclose(arquivo_cliente);
        printf("\nCliente %s cadastrado com sucesso!", nome);
        printf("\nPressione ENTER para continuar.");
    }
    
    

    getchar();  // Apenas para pausar antes de sair
}






void exibir_clientes(char nome[], char cpf[], char email[], char telefone[]){
    int id_procurar = 0;
    int id_cliente = 0;

    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pequisar Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que deseja buscar: ");
    scanf(" %d", &id_procurar);

    arquivo_cliente = fopen("clientes.csv", "rt");

    if (arquivo_cliente == NULL) {
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "wt");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "rt");
    }

    while (!feof(arquivo_cliente)){
        fscanf(arquivo_cliente, "%d", &id_cliente);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", nome);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", cpf);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", email);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^\n]", telefone);
        fgetc(arquivo_cliente);

        if (id_cliente == id_procurar)
        {
            printf("\nID do cliente: %d", id_cliente);
            printf("\nNome do cliente: %s", nome);
            printf("\nCPF do cliente: %s", cpf);
            printf("\nEmail do cliente: %s", email);
            printf("\nTelefone do cliente: %s", telefone);

            fclose(arquivo_cliente);
            limpar_buffer();
            getchar();
            return;
            
        }
        
    }
    fclose(arquivo_cliente);
    
    limpar_buffer();
    printf("\nNenhum cliente com esse id foi encontrado.");
    getchar();
    
    // esta tela ainda vai receber atualizações ao longo do projeto
}





void alterar_cliente(void){
    char cpf[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja alterar: ");
    scanf(" %s", cpf);
    // esta tela ainda vai receber atualizações ao longo do projeto
}





void excluir_cliente(void){
    char cpf[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja excluir: ");
    scanf(" %s", cpf);
    // esta tela ainda vai receber atualizações ao longo do projeto
}