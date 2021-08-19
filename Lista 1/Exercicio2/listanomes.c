//Fiz uso de alguns fóruns para tirar dúvidas especificas quanto a aplicação de certas funções que tinha esquecido, por exemplo como enviar um string por parâmetro.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    int i=0, j=0;
   // char lista[1]={'\0'};//string vazia
    char *ptr={'\0'}, *tmp={'\0'};//ponteiro pra lista
    int op=0;
    ptr=NULL;
    do{//Inicia o programa com op zerada
        printf("Digite a opcao desejada:\n");//menu
        printf("\t-1)Adicionar nome\n");
        printf("\t-2)Remover nome\n");
        printf("\t-3)Listar\n");
        printf("\t-4)Sair\n");
        scanf("%i", &op);

        if(op>4){//se a op for fora dos valores do menu
            printf("Opcao invalida!\n");
        }
        printf("\nA opcao selecionada foi: %d\n\n", op);//print
        if(op==1){//----------------------------------------------------------INSERIR----------------------------------------------------------
             char p[30];//vetor para pegar o novo nome a ser inserido
             printf("Digite o nome a ser inserido: ");
             scanf("%s",p);
             i=strlen(p);//retorna o tamanho do nome novo

             if(ptr == NULL){//-------------------LISTA VAZIA----------------------
                ptr=malloc((i)*sizeof(char));//cria a lista com o tamanho do primeiro nome
                tmp=ptr;
                for(j=0;j<i;j++){
                    *tmp=p[j];//caractere do novo nome vai para a lista apontada
                    tmp++;
                }
                *tmp='\0';
              for(int k=0;k<30;k++){//for para limpar vetor p (evitar lixo de memória)
                    p[k]=0;
                }
                free(p);//limpa a string do nome novo
             }
             else{//------------------------------LISTA EXISTENTE----------------------
                //se eu tirar as informações pra outra string maior, limpar a string antiga, recriar uma string de mesmo nome da original porém com tamanho da nova maior, será?
                tmp=ptr;
                j=0;
                while (*tmp != '\0'){
                    j++;
                    tmp++;
                }
                //j tem o tamanho da lista atual
                printf("\nO tamanho anterior da lista era: %d\n", j);
                char *novo={'\0'}, *tmp_n={'\0'};
                novo=malloc((i+j)*sizeof(char));//novo vai receber a alocação da nova lista com o tamanho da lista atual mais o novo nome
                tmp_n=novo;//aponta pro inicio da nova
                tmp=ptr;//aponta pro inicio da antiga
                for(int k=0;k<j;k++){//for até o final da lista antiga
                    *tmp_n=*tmp;//lista nova recebe caracter por caracter da lista antiga
                    tmp_n++;
                    tmp++;
                }
                for(int k=0;k<i;k++){//vai até o tamanho do novo nome
                    *tmp_n=p[k];
                    tmp_n++;
                }
                printf("\nO tamanho da lista agora: %d\n", j+i);
                *tmp_n='\0';
                free(ptr);
                for(int k=0;k<29;k++){//for para limpar vetor p (evitar lixo de memória)
                    p[k]=0;
                }
                free(p);
                ptr=novo;
                free(novo);
             }
             free(p);
            op=0;
        }
        if(op==2){//----------------------------------------------------------REMOVER----------------------------------------------------------
            //Se presume que todos os nomes vão começar por letra MAIÙSCULA, esse vai ser o critério inicial de retirada de nomes
            if(ptr!=NULL){//se a lista não é vazia
                char p[30], *retirado, *verifica;//vetor para pegar o nome
                int tam=0, k=0;
                printf("\nDigite o nome a ser RETIRADO: ");
                scanf("%s",p);
                i=strlen(p);//retorna o tamanho do nome
                retirado=ptr;
                while (retirado!=NULL){//RODA ENQUANTO A LISTA NÃO ACABA
                    if(p[0]>=65 || p[0]<=90){//Se a primeira letra é MAIÚSCULA
                        tmp=ptr;
                        while (*tmp != '\0'){//descobre o tamanho da lista
                            tam++;
                            tmp++;
                        }
                        tmp=ptr;
                        if(i>tam){//se o tamanho do nome é maior que a lista
                            printf("Nome invalido!\n");
                        }
                        else{//primeiro achar a maiúscula correspondente
                            printf("A primeira letra do nome procurado eh: %c\n", p[0]);
                            while(*tmp!='\0'){//enquanto a lista não está vazia (estava dando erro ao fazer os testes todos no while)
                                if(*tmp == p[0]){//se é a mesma letra
                                    if(*tmp>='A'){//se é maiuscula maior ou igual que A
                                        if(*tmp<='Z'){//se é maiuscula menor ou igual a Z
                                            printf("O nome foi encontrado na lista\n");
                                            break;
                                        }
                                    }
                                }
                            tmp++;
                            }
                            if(tmp!=NULL){//se a lista não acabou, ou seja, achou a primeira letra
                                if(*tmp == p[0] && *tmp>=65 && *tmp<=90){//se é a mesma letra e dentro do escopo
                                    k=0;
                                    for(verifica=tmp;k<i ;verifica++){
                                        if(*verifica==p[k]){//se as letras são as mesmas até o final do nome
                                            k++;
                                        }
                                        else{//se não é o nome
                                            k=0;
                                            break;
                                        }
                                    }
                                    if(k==i){//se achou o nome, agora vem a relocação
                                        char *tm={'\0'};
                                        tm=ptr;
                                        j=0;
                                        while (*tm != '\0'){//j contém o tamanho da lista
                                            j++;
                                            tm++;
                                        }
                                        char *novo={'\0'}, *tmp_n={'\0'};
                                        novo=malloc((j-i)*sizeof(char));//novo vai receber a alocação da nova lista com o tamanho da lista atual mais o novo nome
                                        tmp_n=novo;//aponta pro inicio da nova
                                        tm=ptr;//aponta pro inicio da antiga
                                        for(int k=0;k<=j-i;k++){//for até o final da lista nova
                                            if(tmp==tm){//se o ponteiro que aponta o inicio do nome é igual ao ponteiro que passa os caracteres
                                                tm=tm+i;//posição do ponteiro + tamanho do nome
                                            }
                                            else{
                                                *tmp_n=*tm;//lista nova recebe caracter por caracter da lista antiga enquanto não acha o nome
                                                tmp_n++;
                                                tm++;
                                            }
                                        }
                                        *tmp_n='\0';
                                        free(ptr);
                                        for(int k=0;k<29;k++){//for para limpar vetor p (evitar lixo de memória)
                                            p[k]=0;
                                        }
                                        free(p);
                                        ptr=novo;
                                        //novo=NULL;
                                        free(tm);
                                    }
                                    free(p);
                                    op=0;
                                }
                            }
                            else{
                                printf("Nome não encontrado\n");
                                break;
                            }
                        }
                    }
                    printf("Caractere inválido\n");
                    break;
                }
            }
            else{//mensagem para lista vazia
                printf("\nLista vazia, não eh possivel retirar nomes!\n");
            }
        op=0;
        }
        if(op==3){//----------------------------------------------------------LISTAR----------------------------------------------------------
            tmp=ptr;
                while (*tmp != '\0'){
                    printf("%c",*tmp);
                    tmp++;
                }
            tmp='\0';
            free(tmp);
        op=0;
        }
    printf("\n");
    }while(op!=4); //faz enquanto a op não é 4(sair)
    free(ptr);
    return 0;//se op=4 então para o programa
}