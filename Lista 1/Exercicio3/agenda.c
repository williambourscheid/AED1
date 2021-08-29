#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define NOME sizeof(char)*10
#define IDADE sizeof(int)
#define TEL sizeof(int)
#define POS sizeof(int)


void *pBuffer={'\0'};

//void crialista();//Função para criação e alocação da lista
void insere();//Função para colocar novo contato na agenda
void listar();//Função para imprimir todos os contatos
void busca();//Função para imprimir contato específico pela posição
void limpador();//Função para limpar toda a lista
void retira();//Função para retirada de um contato da lista (escolha pela posição)


int main(){
    int op=0;
    do{
        while (op!=5){
            printf("Digite a opcao desejada:\n");//menu
            printf("\t-1)Adicionar contato\n");
            printf("\t-2)Remover contato\n");
            printf("\t-3)Buscar contato\n");
            printf("\t-4)Listar contatos\n");
            printf("\t-5)Sair\n");
            scanf("%i", &op);
            switch (op){/*switch quebra o while toda vez que faz a seleção, logo precisa de 2 loops para o menu,
                         porém é mais fácil de evitar mensagens indesejadas*/
            case 1:
                printf("Inclusao selecionada\n");
                insere();
                
                break;
            case 2:
                printf("Remover selecionada\n");
                retira();
                break;
            case 3:
                printf("Busca selecionada\n");
                busca();
                break;
            case 4:
                printf("Imprimir selecionada\n");
                listar();
               
                break;
            default:
                break;
            }
        }
    } while ((op =! 5));//menu roda enquanto a opção for diferente de 5
    printf("Limpando lista\n");
    free(pBuffer);
    printf("Limpo\n");
}


void insere(){ //Primeira letra maiuscula
    void *percorredor=NULL;
    //int Npessoas=*(int *)pBuffer;
    char novonome[10];
    int idade=0, tel=0, nnome=0;
        printf("Digite o nome\n");
        scanf("%s", novonome);
        nnome=strlen(novonome);
        printf("Digite idade\n");
        scanf("%d", &idade);
        printf("Digite o telefone\n");
        scanf("%d", &tel);

    if (pBuffer==NULL){//se  agenda vazia
        int Npessoas=1;
        pBuffer= malloc(sizeof(int) + (NOME + IDADE + TEL));
        if(pBuffer==NULL){
            printf("Nao foi possivel alocar\n");
        }
        percorredor=pBuffer;
        *(int *)percorredor=Npessoas;
        percorredor=(percorredor+sizeof(int));//pula 1 inteiro da memória
        for(int i=0;i<nnome;i++){
            *(char*)percorredor=novonome[i];
            percorredor=(percorredor+sizeof(char));
        }
       // *(char*)percorredor='\0';
        int fnome=(10-nnome);
            while (fnome>0)
            {
                *(char*)percorredor='\0';
                percorredor=(percorredor+sizeof(char));
                fnome--;
            }
        //percorredor=(percorredor+sizeof(char)*((10)-(nnome+1)));//percorredor vai pular pra memória depois dos 10 chars alocados do nome
        *(int*)percorredor=idade;
        percorredor=(percorredor+sizeof(int));
        (*(int*)percorredor)=tel;
        percorredor=NULL;
        printf("Tem %d pessoas na lista\n", *(int*)pBuffer);
        free(novonome);
       // listar();//listar logo após incluir
    }
    else{//se agenda não vazia
        percorredor=pBuffer;
        int Npessoas=*(int *)pBuffer;
        Npessoas++;
        pBuffer=realloc(pBuffer, (POS + (Npessoas*(NOME+IDADE+TEL))));
        if (pBuffer==NULL){
            printf ("** Erro: Memoria Insuficiente **\n");
            pBuffer=percorredor;
        }
        else{
            percorredor=pBuffer;
            percorredor=(percorredor + POS + ((Npessoas-1)*(NOME + IDADE + TEL)));//recebe o endereço do final da lista antiga
            percorredor=(percorredor-sizeof(char));//volta um char
            for(int i=0;i<nnome;i++){//passa caractere a caracter pra memória
                *(char*)percorredor=novonome[i];
                percorredor=(percorredor+sizeof(char));
            }
            int fnome=(10-nnome);
            while (fnome>0)
            {
                *(char*)percorredor='\0';
                percorredor=(percorredor+sizeof(char));
                fnome--;
            }
            
            //*(char*)percorredor='\0';
            //percorredor=(percorredor+sizeof(char));
            //percorredor=(percorredor+(sizeof(char)*(10-(nnome+1))));//percorredor vai pular pra memória depois dos 10 chars alocados do nome
            *(int*)percorredor=idade;
            percorredor=(percorredor+sizeof(int));
            (*(int*)percorredor)=tel;
            percorredor=NULL;
            *(int*)pBuffer=Npessoas;
            printf("Tem %d pessoas na lista\n", *(int*)pBuffer);
           // listar();
        }
    }

}

void listar(){
    if(pBuffer==NULL){
        printf("Lista vazia, volte depois que adicionar algo!\n");
    }
    else{
            if(*(int*)pBuffer==1)
            {//se só tem um contato
                    int Npessoas=*(int *)pBuffer;
                    void *percorredor=NULL;
                    percorredor=pBuffer+sizeof(int);//percorredor começa depois do Npessoas
                    printf("\n");
                    for (int i = 0; i < Npessoas; i++){
                    int nnome=0;
                    printf("%d\n", i+1);
                    nnome= strlen(percorredor);
                    printf("Nome:");
                    int n=0;
                    while (n<nnome)
                    { //de n até tamanho do nome printa char a char
                        printf("%c", *(char*)percorredor);
                        percorredor=percorredor+sizeof(char);
                        n++;
                    }
                    while (*(char*)percorredor=='\0')
                    {
                        percorredor=percorredor+sizeof(char);
                    }
                    printf("\n");
                    printf("Idade: %d\n", *(int*)percorredor);
                    percorredor=(percorredor+IDADE);
                    printf("Telefone: %d\n", *(int*)percorredor);
                    percorredor=(percorredor+TEL);
                    percorredor=NULL;
                }
            }
            else
            {
                int Npessoas=*(int *)pBuffer;
                void *percorredor=NULL;
                percorredor=pBuffer+sizeof(int);//percorredor começa depois do Npessoas
                printf("\n");
                for (int i = 0; i < Npessoas; i++){
                    //int nnome=0;
                    printf("%d\n", i+1);
                    printf("Nome:");
                    //nnome= strlen(percorredor);
                    printf("%s\n", (char*)percorredor);
                    percorredor=((char*)percorredor+NOME);
                    printf("Idade: %d\n", *(int*)percorredor);
                    percorredor=(percorredor+IDADE);
                    printf("Telefone: %d\n", *(int*)percorredor);
                    percorredor=(percorredor+TEL);
                    if (*(char*)percorredor=='\0'){
                        percorredor=(percorredor+sizeof(char));
                    }
                    else{
                        if (*(char*)percorredor<'A' || *(char*)percorredor>'Z'){//se não maíscula
                            percorredor=(percorredor-sizeof(char));
                        }
                    }
                }
                percorredor=NULL;
            }
    }
}

void retira(){//testar se primeiro ou ultimo contato ///// PEGAR POSIÇÃO E PULAR
    void *percorredor=NULL, *realocador=NULL, *passador=NULL, *percorredor_realocador=NULL;
    char nome[10];
    int pessoas=0, contador=0;
    printf("Digite o nome a ser removido\n");
    scanf("%s", nome);
    //nnome=strlen(nome);
    pessoas=*(int*)pBuffer;
    percorredor=pBuffer+sizeof(int);
    if(pBuffer==NULL){
        printf("Lista vazia!\n");
    }
    if(*(int*)pBuffer==1){//se só tiver uma pessoa na lista
        if(strcmp(percorredor,nome)==0)//se a comparação for verdadeira pro primeiro nome
        {
            free(pBuffer);
            pBuffer=NULL;
        }
        else{
            printf("Nome inválido\n");
        }
    }
    else{//se tem mais contatos na lista
        contador=0;
        while(strcmp(percorredor,nome)!=0 && contador<pessoas){//Enquanto não acha o nome e mais contatos que a lista
            percorredor=percorredor+NOME+IDADE+TEL;
            if (*(char*)percorredor=='\0'){
                percorredor=(percorredor+sizeof(char));
            }
            else{
                if (*(char*)percorredor<'A' || *(char*)percorredor>'Z'){//se não maíscula
                    percorredor=(percorredor-sizeof(char));
                }
            }
            contador++;
        }
        if(strcmp(percorredor,nome)==0){//se achou o nome
            realocador=malloc(POS + ((pessoas-1)*(NOME+IDADE+TEL)));
            percorredor_realocador=realocador+POS;
            *(int*)realocador=*(int*)pBuffer-1;
            passador=pBuffer+sizeof(int);
            int i=1;
            while (i <= (pessoas-1)){
                if(strcmp(passador,nome)==0){//Se achou o nome pra retirar, pula
                    passador=passador+(NOME+IDADE+TEL);
                    if (*(char*)passador=='\0'){
                        passador=(passador+sizeof(char));
                    }
                    else{
                        if (*(char*)passador<'A' || *(char*)passador>'Z'){//se não maíscula
                            passador=(passador-sizeof(char));
                        }
                    }
                    i++;
                }
                else{

                    for (int l = 0; l < 9; l++)//passa o nome que não é pra remover pro realocador
                    {
                        *(char*)percorredor_realocador=*(char*)passador;
                        percorredor_realocador=percorredor_realocador+sizeof(char);
                        passador=passador+sizeof(char);
                    }
                    *(int*)percorredor_realocador=*(int*)passador;
                    percorredor_realocador=percorredor_realocador+sizeof(int);
                    passador=passador+sizeof(int);
                    *(int*)percorredor_realocador=*(int*)passador;
                    percorredor_realocador=percorredor_realocador+sizeof(int);
                    passador=passador+sizeof(int);
                    if (*(char*)passador=='\0'){
                        passador=(passador+sizeof(char));
                    }
                    else{
                        if (*(char*)passador<'A' || *(char*)passador>'Z'){//se não maíscula
                            passador=(passador-sizeof(char));
                        }
                    }

                    if (*(char*)percorredor_realocador=='\0'){
                        percorredor_realocador=(percorredor_realocador+sizeof(char));
                    }
                    else{
                        if (*(char*)percorredor_realocador<'A' || *(char*)percorredor_realocador>'Z'){//se não maíscula
                            percorredor_realocador=(percorredor_realocador-sizeof(char));
                        }
                    }
                    i++;
                }
                free(pBuffer);
                pBuffer=realocador;
            }
        }
        
    }
}

    /*
    else{
        //else{
        
            for(contador=0;contador<pessoas;contador++){
                if(strcmp(percorredor,nome)==0)//se a comparação for verdadeira
                {
                    if (contador+1==pessoas)// se for a ultima pessoa
                    {
                        pBuffer=realloc(pBuffer, (POS + ((pessoas-1)*(NOME+IDADE+TEL))));//realoca agenda com menos 1 contato
                        if (pBuffer==NULL){
                            printf ("** Erro: Memoria Insuficiente **\n");
                            break;
                        }
                        *(int*)pBuffer=*(int*)pBuffer-1;
                        break;
                    }
                    else{    
                        realocador=realloc(pBuffer, (POS + ((pessoas)*(NOME+IDADE+TEL))));//copia pra realocador a agenda
                        if (realocador==NULL){
                            printf ("** Erro: Memoria Insuficiente **\n");
                        }

                        pBuffer=realloc(pBuffer, (POS + ((pessoas-1)*(NOME+IDADE+TEL))));//realoca agenda com menos 1 contato
                        if (pBuffer==NULL){
                            printf ("** Erro: Memoria Insuficiente **\n");
                        }
                        
                        passador=realocador+sizeof(int);//percorredor da agenda velha
                        percorredor=pBuffer+sizeof(int);//percorredor da agenda nova
                        int i=0;
                        while (contador!=i)//enquanto não acha a posição do nome
                        {
                            passador=passador+NOME+IDADE+TEL;//pula contato
                                if (*(char*)passador=='\0'){
                                    passador=(passador+sizeof(char));
                                }
                                else{
                                    if (*(char*)passador<'A' || *(char*)passador>'Z'){//se não maíscula
                                        passador=(passador-sizeof(char));
                                    }
                                }
                            
                            percorredor=percorredor+NOME+IDADE+TEL;//pula contato

                                if (*(char*)percorredor=='\0'){
                                    percorredor=(percorredor+sizeof(char));
                                }
                                else{
                                    if (*(char*)percorredor<'A' || *(char*)percorredor>'Z'){//se não maíscula
                                        percorredor=(percorredor-sizeof(char));
                                    }
                                }
                        i++;
                        }

                        passador=passador+NOME+IDADE+TEL;//pula contato
                        if (*(char*)passador=='\0'){
                            passador=(passador+sizeof(char));
                        }
                        else{
                            if (*(char*)passador<'A' || *(char*)passador>'Z'){//se não maíscula
                                passador=(passador-sizeof(char));
                            }
                        }

                        for(int nrestante=i;nrestante<pessoas;nrestante++){//enquanto não passa todos os contatos restantes
                            for(int j=0;j<10;j++){
                                *(char*)percorredor=*(char*)passador;
                                percorredor=percorredor+sizeof(char);
                                passador=passador+sizeof(char);
                            }
                            //percorredor=percorredor+(sizeof(char)*2);
                            //passador=passador+(sizeof(char)*2);
                            *(int*)percorredor=*(int*)passador;
                            percorredor=(percorredor+IDADE);
                            passador=(passador+IDADE);
                            *(int*)percorredor=*(int*)passador;
                            percorredor=(percorredor+TEL);
                            passador=(passador+TEL);

                            if (*(char*)percorredor=='\0')
                            {
                                    percorredor=(percorredor+sizeof(char));
                            }
                            else
                            {
                                    if (*(char*)percorredor<'A' || *(char*)percorredor>'Z'){//se não maíscula
                                        percorredor=(percorredor-sizeof(char));
                                    }
                            }
                            if (*(char*)passador=='\0')
                            {
                                    passador=(passador+sizeof(char));
                            }
                            else
                            {
                                if (*(char*)passador<'A' || *(char*)passador>'Z')
                                {//se não maíscula
                                    passador=(passador-sizeof(char));
                                }
                            }

                        }
                        *(int*)pBuffer=*(int*)pBuffer-1;
                        free(realocador);
                        break;//se retirou nome
                    }
                }

                percorredor=percorredor+NOME+IDADE+TEL;//pula contato
                if (*(char*)percorredor=='\0'){
                    percorredor=(percorredor+sizeof(char));
                }
                else{
                    if (*(char*)percorredor<'A' || *(char*)percorredor>'Z'){//se não maíscula
                                    percorredor=(percorredor-sizeof(char));
                    }
                }
            }
       // }
    }
    
}*/

void busca(){
    void *percorredor;
    int posicao=0;
    printf("Digite a posicao para busca:");
    scanf("%d", &posicao);
    printf("\n");
    if(posicao>*(int*)pBuffer){
        printf("Posicao nao existe!");
    }
    percorredor=pBuffer+sizeof(int);
    for(int i=1 ; ; i++){
        if(i==posicao){
            printf("Nome: %s\n", percorredor);
            percorredor=percorredor+NOME;
            printf("Idade: %d\n", *(int*)percorredor);   
            percorredor=percorredor+IDADE;
            printf("Telefone: %d\n", *(int*)percorredor);
            percorredor=NULL;
            break;
        }
        percorredor=percorredor+NOME+IDADE+TEL;
        if (*(char*)percorredor=='\0'){
                        percorredor=(percorredor+sizeof(char));
                    }
        else{
            if (*(char*)percorredor<'A' || *(char*)percorredor>'Z'){//se não maíscula
                percorredor=(percorredor-sizeof(char));
            }
        }
    }
}
