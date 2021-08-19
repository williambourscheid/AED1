#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nome[10];
    int idade;
    int tel;
    int *prox;
}Agenda;

void crialista();

int main(){
    int op=0, Npessoas=0;
    void *pBuffer={'\0'};
    
    do{
        while (op!=5){
            printf("Digite a opcao desejada:\n");//menu
            printf("\t-1)Adicionar nome\n");
            printf("\t-2)Remover nome\n");
            printf("\t-3)Buscar\n");
            printf("\t-4)Listar\n");
            printf("\t-5)Sair\n");
            scanf("%i", &op);
            switch (op){/*switch quebra o while toda vez que faz a seleção, logo precisa de 2 loops para o menu,
                         porém é mais fácil de evitar mensagens indesejadas*/
            case 1:
                printf("Inclusao selecionada\n");
                if(pBuffer==NULL){//se a lista está vazia
                    pBuffer=crialista();

                }
                else{//lista não vazia

                }
                break;
            case 2:
                printf("Remocao selecionada\n");
                break;
            case 3:
                printf("Busca selecionada\n");
                break;
            case 4:
                printf("Listar selecionada\n");
                break;
            default:
                break;
            }
        }
    } while ((op =! 5));
    free(pBuffer);
    printf("Lavando as pilhas e esfregando o buffer\n");
}

void crialista(){
    Agenda *p={'\0'};
    p=(Agenda *) malloc(sizeof(Agenda));
    return p;
}