#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarefas
{
    int id;
    char descricao[100];
    char situacao[20];

};
/* 'void' sendo usado em uma função em C, indica que a função não retorna nenhum valor. O 'void' é utilizado
aqui por que esta função não retorna nenhum valor. Em vez disso, ela altera o estado dos parâmetros passados. */

void inserirNovaTarefa(struct Tarefas **task, int *tamanhoLista) {
    int tamanho;

    printf("\nQuantas tarefas deseja inserir?: ");
    scanf("%d", &tamanho);

    // Limpar o buffer do teclado
    while (getchar() != '\n');

    printf("\n");

    *task = realloc(*task, (*tamanhoLista + tamanho) * sizeof(struct Tarefas));

    for (int i = *tamanhoLista; i < *tamanhoLista + tamanho; i++) {

        printf("Digite o 'numero identificador' da tarefa: ");
        scanf("%d", &((*task)[i].id));

        printf("Digite a 'descricao' da tarefa: ");
        // Limpar o buffer do teclado
        while (getchar() != '\n');
        fgets((*task)[i].descricao, 100, stdin);
        strcpy((*task)[i].situacao, "Pendente");
        printf("***************************************\n");
    }

    *tamanhoLista += tamanho;
    //printf("TamanhoLista: %d\n", *tamanhoLista);

    printf("Tarefa inserida com sucesso!!!\n");
}

void mostrarTarefas(struct Tarefas *task, int tamanhoLista){
    printf("***************************************\n");
    printf("\nTodas as Tarefas Cadastradas\n\n");

    for(int i=0; i < tamanhoLista; i++){
        printf("Numero Identificador: %d\n",task[i].id);
        printf("Descricao da Tarefa: %s",task[i].descricao);
        printf("Situacao da Tarefa: %s\n",task[i].situacao);
        printf("***************************************\n");
    }
}

void buscarTarefas(struct Tarefas *task, int tamanhoLista) {
    int buscaId;
    int encontrou = 0;

    printf("***************************************\n");
    printf("\nBuscar por Tarefas\n");

    printf("Qual o 'numero identificador' da tarefa?: ");
    scanf("%d", &buscaId);

    for (int i = 0; i < tamanhoLista; i++) {
        if (task[i].id == buscaId) {
            printf("Numero Identificador: %d\n", task[i].id);
            printf("Descricao da Tarefa: %s", task[i].descricao);
            printf("Situacao da Tarefa: %s\n", task[i].situacao);
            printf("***************************************\n");
            encontrou = 1;  // Marcar que a tarefa foi encontrada
            break;
        }
    }

    // Verificar se a tarefa não foi encontrada
    if (encontrou == 0) {
        printf("Esta tarefa nao foi cadastrada!!!\n");
    }
}
void editarTarefa(struct Tarefas *task, int tamanhoLista){
    int buscaId;
    int encontrou = 0;

    printf("***************************************\n");
    printf("\nBuscar por Tarefas\n");

    printf("Qual o 'numero identificador' da tarefa?: ");
    scanf("%d", &buscaId);

    for (int i = 0; i < tamanhoLista; i++) {
        if (task[i].id == buscaId) {
            printf("Numero Identificador: %d\n", task[i].id);
            printf("Descricao da Tarefa: %s", task[i].descricao);
            printf("Situacao da Tarefa: %s\n", task[i].situacao);

            printf("\n");

            printf("Digite a nova 'descricao' da tarefa: ");
            while(getchar() !='\n');
            fgets(task[i].descricao, 100, stdin);

            printf("Digite a nova 'situacao' da tarefa: ");
            fgets(task[i].situacao,100,stdin);

            printf("Tarefa editada com sucesso!!!\n");
            printf("***************************************\n");
            encontrou = 1;  // Marcar que a tarefa foi encontrada
            break;
        }
    }

    // Verificar se a tarefa não foi encontrada
    if (encontrou == 0) {
        printf("Esta tarefa nao foi encontrada!!!\n");
    }
}
void marcarTarefa(struct Tarefas *task, int tamanhoLista){
    int buscaId;
    int encontrou = 0;

    printf("***************************************\n");
    printf("\nMarcar Tarefa com concluida ou nao concluida\n");

    printf("Qual o 'numero identificador' da tarefa?: ");
    scanf("%d", &buscaId);

    for (int i = 0; i < tamanhoLista; i++) {
        if (task[i].id == buscaId) {
            printf("Numero Identificador: %d\n", task[i].id);
            printf("Descricao da Tarefa: %s", task[i].descricao);
            printf("Situacao da Tarefa: %s\n", task[i].situacao);

            printf("\n");

            while(getchar() !='\n');

            printf("Digite (Concluida) para tarefa finalizada ou (Nao Concluida) para tarefa nao finalizada: ");
            fgets(task[i].situacao,100,stdin);

            printf("Tarefa editada com sucesso!!!\n");
            printf("***************************************\n");
            encontrou = 1;  // Marcar que a tarefa foi encontrada
            break;
        }
    }

    // Verificar se a tarefa não foi encontrada
    if (encontrou == 0) {
        printf("Esta tarefa nao foi encontrada!!!\n");
    }
}

int main(){
    struct Tarefas* task = (struct Tarefas* ) malloc(sizeof(struct Tarefas));
    int *tamanhoLista = (int *) malloc(sizeof(int));
    tamanhoLista = 0;

    if(task==NULL){
        printf("Erro: Nao foi possivel alocar na memória!!!\n");
    }

    int opcaoMenu;

    printf("\nSeja Bem-Vindo ao TASK MASTER!");

    do{
        //Opções do Menu
        printf("\n==========================\n");
        printf("\nMenu do Task Master\n");
        printf("1 - Inserir Nova Tarefa\n");
        printf("2 - Mostrar Tarefas Cadastradas\n");
        printf("3 - Buscar por Tarefa\n");
        printf("4 - Editar Informacoes de uma Tarefa\n");
        printf("5 - Remover Tarefa\n");
        printf("6 - Marcar Conclusao de uma Tarefa Especifica\n");
        printf("7 - Salvar Lista de Tarefas em um Arquivo\n");
        printf("0 - Sair do Task Master\n");
        printf("==========================\n");

        printf("O que deseja fazer?: ");
        scanf("%d",&opcaoMenu);

        switch(opcaoMenu){
        
            case 1: 
                inserirNovaTarefa(&task, &tamanhoLista);
                break;
            case 2: 
                mostrarTarefas(task, tamanhoLista);
                break;
            case 3: 
                buscarTarefas(task, tamanhoLista);
                break;
            case 4: 
                editarTarefa(task, tamanhoLista);
                break;
            case 5: 
                printf("5\n");
                break;
            case 6: 
                marcarTarefa(task, tamanhoLista);
                break;
            case 7: 
                printf("7\n");
                break;
            case 0: 
                printf("Saindo...\n");
                break;
            default: 
                printf("Opcao invalida! tente novamente\n");
        }

    }while(opcaoMenu !=0);

    return 0;

}