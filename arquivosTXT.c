#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "funcoes.h"
#include "reservasTXT.h"
#include "menu.h"
#include "ArquivosBin.h"
#include "arquivosTXT.h"
#include "memoria.h"


// função responsavel por cadastras os dados do hotel em TXT
int cadastro_hotel_txt(cad_hotel hotel_inf){
    FILE *P;
    //comando que abre o arquivo para escrita
    P=fopen("hotel.txt","w");
    //verifica se a criação do arquvio foi bem sucedida 
    if(P == NULL){
       printf("Problemas na abertura do arquivo.");
       exit (1);
    }
    //
    fprintf (P,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%f\n",
             hotel_inf.nome_fantasia,hotel_inf.razao_social,hotel_inf.inscricao_estadual,hotel_inf.cnpj,hotel_inf.endereco.estado,
             hotel_inf.endereco.cidade,hotel_inf.endereco.cep,hotel_inf.endereco.bairro,hotel_inf.endereco.rua,
             hotel_inf.endereco.numero,hotel_inf.telefone,hotel_inf.email,hotel_inf.nome_responsavel,hotel_inf.telefone_responsavel,
             hotel_inf.horario_checkin.hora,hotel_inf.horario_checkin.minutos,hotel_inf.horario_checkout.hora,hotel_inf.horario_checkout.minutos,hotel_inf.mlpv);
    fclose(P);
    printf("Cadastros dos dados do hotel realizado com sucesso.\n\n");
    return 0;
// fim da funçao que abre um arquivo TXT para escrever e gravar dados do hotel que o usuario digitou
}

//funçao responsavel por trazer dados do hotel para memoria ram    
int hotel_ram_txt(cad_hotel *ramHT){
    FILE *P;
    
    P = fopen("hotel.txt", "r");
    
    if(P == NULL){
       printf("Problemas na abertura do arquivo.");
        exit (1);
    }
    
        fscanf(P,"%[^\n]s",ramHT[0].nome_fantasia);
        fscanf(P,"\n%[^\n]s",ramHT[0].razao_social);
        fscanf(P,"\n%[^\n]s",ramHT[0].inscricao_estadual);
        fscanf(P,"\n%[^\n]s",ramHT[0].cnpj);
        fscanf(P,"\n%[^\n]s",ramHT[0].endereco.estado);
        fscanf(P,"\n%[^\n]s",ramHT[0].endereco.cidade);
        fscanf(P,"\n%[^\n]s",ramHT[0].endereco.cep);
        fscanf(P,"\n%[^\n]s",ramHT[0].endereco.bairro);
        fscanf(P,"\n%[^\n]s",ramHT[0].endereco.rua);
        fscanf(P,"\n%d",&ramHT[0].endereco.numero);
        fscanf(P,"\n%[^\n]s",ramHT[0].telefone);
        fscanf(P,"\n%[^\n]s",ramHT[0].email);
        fscanf(P,"\n%[^\n]s",ramHT[0].nome_responsavel);
        fscanf(P,"\n%[^\n]s",ramHT[0].telefone_responsavel);
        fscanf(P,"%d\n",&ramHT[0].horario_checkin.hora);
        fscanf(P,"%d\n",&ramHT[0].horario_checkin.minutos);
        fscanf(P,"%d\n",&ramHT[0].horario_checkout.hora);
        fscanf(P,"%d\n",&ramHT[0].horario_checkout.minutos);
        fscanf(P,"%f\n",&ramHT[0].mlpv);
        
    fclose(P);

    return 0;
// fim da função para trazer dados do hotel para memoria RAM
}

//função responsavel por atualizar dados do hotel
int atualiza_hotel_txt(cad_hotel *AtualizaHT){
    int status;
    
    FILE *P;
    
    //comando que abre o arquivo para escrita
    P=fopen("hotel_temp.txt","w");
    //verifica se a criação do arquvio foi bem sucedida 
    if(P == NULL){
       printf("Problemas na abertura do arquivo.");
       exit (1);
    }
    //
    fprintf (P,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%d:%d\n%d:%d\n%f\n",
             AtualizaHT[0].nome_fantasia,AtualizaHT[0].razao_social,AtualizaHT[0].inscricao_estadual,AtualizaHT[0].cnpj,AtualizaHT[0].endereco.estado,
             AtualizaHT[0].endereco.cidade,AtualizaHT[0].endereco.cep,AtualizaHT[0].endereco.bairro,AtualizaHT[0].endereco.rua,
             AtualizaHT[0].endereco.numero,AtualizaHT[0].telefone,AtualizaHT[0].email,AtualizaHT[0].nome_responsavel,AtualizaHT[0].telefone_responsavel,
             AtualizaHT[0].horario_checkin.hora,AtualizaHT[0].horario_checkin.minutos,AtualizaHT[0].horario_checkout.hora,AtualizaHT[0].horario_checkout.minutos,AtualizaHT[0].mlpv);
    fclose(P);
    
    status = remove("hotel.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para atualização do cadastro");
        exit(1);
    }
    status = rename("hotel_temp.txt","hotel.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para atualização do cadastro");
        exit(1);
    }
    printf("Atualização dos dados do hotel feita com sucesso\n\n");
    return 0;
// fim da funçao que abre um arquivo TXT para escrever e gravar dados do hotel que o usuario digitou
}



//função responsavel por cadastrar os dados dos operadores em TXT
int cadastro_operadores_txt(OPsistema op){
    FILE *P; //Peiro do arquivo TXT;
    
        P = fopen("operadores.txt","a");
  
    if(P==NULL){
        printf("Problemas na abertura do arquivo.");
        exit (1);
    }
    fprintf(P,"%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n",op.codigo, op.nome, op.usuario, op.senha, op.permissoes.cadastros,
           op.permissoes.reservas, op.permissoes.transacoes, op.permissoes.feedback, op.permissoes.im_exportacao);
    
    fclose(P);
    printf("Cadastro de operadores realizado com sucesso.\n");
    return 0;
    // fim da função de cadastro de operadores
}

//função responsavel por trazer os dados dos operadore para memoria ram
int operadores_ram_txt(int qtd, OPsistema *ramOP){
    
    FILE *P;
    
    P = fopen("operadores.txt", "r");
    
      if(P==NULL){
        printf("Problemas na abertura do arquivo.");
        exit (1);
    }
    for(int i=0;i<qtd;i++){
            fscanf(P,"%d",&ramOP[i].codigo);
            fscanf(P,"\n%[^\n]s",ramOP[i].nome);
            fscanf(P,"\n%[^\n]s",ramOP[i].usuario);
            fscanf(P,"\n%d",&ramOP[i].senha);
            fscanf(P,"\n%d",&ramOP[i].permissoes.cadastros);
            fscanf(P,"\n%d",&ramOP[i].permissoes.reservas);
            fscanf(P,"\n%d",&ramOP[i].permissoes.transacoes);
            fscanf(P,"\n%d",&ramOP[i].permissoes.feedback);
            fscanf(P,"\n%d",&ramOP[i].permissoes.im_exportacao);
            
            
    }
           
    fclose(P);
    return 0; 
    // fim da função para trazer operadores para memoria RAM
}

//função para procurar operador em txt
int procura_operador_txt(int codigo,int qtd, OPsistema *procuraOP){
    
    
    for(int i=0;i<qtd;i++){
       if(procuraOP[i].codigo == codigo){

           return i;
       }
    }
    
    return -1;
}

//função para atualizar dados dos operadores
int atualiza_operador_txt(int qtd,OPsistema *ramOP){
    int status=0;
    FILE *P;
    
    P = fopen("operadores_temp.txt", "w");
    
    if(P==NULL){
        printf("Problemas na abertura do arquivo.\n");
        exit (1);
    }
    for(int i=0;i<qtd;i++){
        fprintf(P,"%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n",ramOP[i].codigo, ramOP[i].nome, ramOP[i].usuario, ramOP[i].senha, ramOP[i].permissoes.cadastros,
           ramOP[i].permissoes.reservas, ramOP[i].permissoes.transacoes, ramOP[i].permissoes.feedback, ramOP[i].permissoes.im_exportacao);
    }
    fclose(P);

    status = remove("operadores.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para atualizar o cadastro do operador.\n");
        exit(1);
    }
    status = rename("operadores_temp.txt","operadores.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para atualizar o cadastro do operador.\n");
        exit(1);
    }
    printf("Atualização dos dados do operador feita com sucesso.\n");
    return 0; 
}

//função para deletar operador
int deleta_operador_txt(int qtd, int posicao, OPsistema *ramDELOP){
    int status=0;
//laço para pegar todos operadores apos o que vai ser excluido e trazer para tras
    for(int i=posicao;i<qtd;i++){//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente
       
        ramDELOP[i].codigo = ramDELOP[i+1].codigo;
        strcpy(ramDELOP[i].nome,ramDELOP[i+1].nome);
        strcpy(ramDELOP[i].usuario,ramDELOP[i+1].usuario);
        ramDELOP[i].senha = ramDELOP[i+1].senha;
        ramDELOP[i].permissoes.cadastros = ramDELOP[i+1].permissoes.cadastros;
        ramDELOP[i].permissoes.reservas = ramDELOP[i+1].permissoes.reservas;
        ramDELOP[i].permissoes.transacoes = ramDELOP[i+1].permissoes.transacoes;
        ramDELOP[i].permissoes.feedback = ramDELOP[i+1].permissoes.feedback;
        ramDELOP[i].permissoes.im_exportacao = ramDELOP[i+1].permissoes.im_exportacao;
    }

    OPsistema *p;
//diminuindo em um o tamanho do ponteiro
    p = malloc((qtd-1)*sizeof(OPsistema));//realoca memoria com uma posicao a menos

    //pegando os dados dos operadores e passando para o ponteiro
    for(int i=0;i<qtd-1;i++){//preenche o ponteiro alocado com os dados dos operadores
        p[i].codigo = ramDELOP[i].codigo;
        strcpy(p[i].nome,ramDELOP[i].nome);
        strcpy(p[i].usuario,ramDELOP[i].usuario);
        p[i].senha = ramDELOP[i].senha;
        p[i].permissoes.cadastros = ramDELOP[i].permissoes.cadastros;
        p[i].permissoes.reservas = ramDELOP[i].permissoes.reservas;
        p[i].permissoes.transacoes = ramDELOP[i].permissoes.transacoes;
        p[i].permissoes.feedback = ramDELOP[i].permissoes.feedback;
        p[i].permissoes.im_exportacao = ramDELOP[i].permissoes.im_exportacao;
    }
    
    FILE *temp;

    temp = fopen("operadores_temp.txt","w");
    if(temp == NULL ){
       return 1;
    }
    //retirando da quantidade o OP deletado
    qtd=qtd-1;
    //gravando o arquivo
    for(int i=0;i<qtd;i++){
        fprintf(temp,"%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n",p[i].codigo, p[i].nome, p[i].usuario, p[i].senha,
                p[i].permissoes.cadastros, p[i].permissoes.reservas, p[i].permissoes.transacoes,
                p[i].permissoes.feedback, p[i].permissoes.im_exportacao);
    }
    fclose(temp);
    status = remove("operadores.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para deletar o operador.\n");
        exit(1);
    }
    status = rename("operadores_temp.txt","operadores.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para deletar o operador.\n");
        exit(1);
    }
    printf("Deleção do operador feita com sucesso.\n");
    return 0;
}




//funçao para cadastrar hospedes
int cadastro_hospedes_txt(hospedes cadastro_hospede){
 FILE *P; //Ponteiro do arquivo TXT;
    
        P = fopen("hospedes.txt","a");
  
    if(P==NULL){
        printf("Problemas na abertura do arquivo.");
        exit (1);
    }
    fprintf(P,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n",
            cadastro_hospede.codigo,
            cadastro_hospede.nome, 
            cadastro_hospede.endereco_hospede.estado, 
            cadastro_hospede.endereco_hospede.cidade, 
            cadastro_hospede.endereco_hospede.cep,
            cadastro_hospede.endereco_hospede.bairro, 
            cadastro_hospede.endereco_hospede.rua, 
            cadastro_hospede.endereco_hospede.numero, 
            cadastro_hospede.cpf, 
            cadastro_hospede.telefone,
            cadastro_hospede.email,
            cadastro_hospede.sexo,
            cadastro_hospede.estado_civil,
            cadastro_hospede.data_nacimento.dia,
            cadastro_hospede.data_nacimento.mes,
            cadastro_hospede.data_nacimento.ano);
   
    
    fclose(P);
    printf("Cadastro de hospede realizado com sucesso.\n");
    return 0;
    // fim da função de cadastro de operadores
}

//funçao para trazer os dados dos hosedes para memoria ram
int hospedes_ram_txt(hospedes *ramHO, int qtd){
    
    FILE *P;
    int i=0;
    P=fopen("hospedes.txt","r");
    
    for(i=0;i<qtd;i++){
        fscanf(P, "%d", &ramHO[i].codigo);
        fscanf(P, "\n%[^\n]s", ramHO[i].nome);
        fscanf(P, "\n%[^\n]s", ramHO[i].endereco_hospede.estado);
        fscanf(P, "\n%[^\n]s", ramHO[i].endereco_hospede.cidade);
        fscanf(P, "\n%[^\n]s", ramHO[i].endereco_hospede.cep);
        fscanf(P, "\n%[^\n]s", ramHO[i].endereco_hospede.bairro);
        fscanf(P, "\n%[^\n]s", ramHO[i].endereco_hospede.rua);
        fscanf(P, "\n%[^\n]s",&ramHO[i].endereco_hospede.numero);
        fscanf(P, "\n%[^\n]s", ramHO[i].cpf);
        fscanf(P, "\n%[^\n]s", ramHO[i].telefone);
        fscanf(P, "\n%[^\n]s", ramHO[i].email);
        fscanf(P, "\n%[^\n]s", ramHO[i].sexo);
        fscanf(P, "\n%[^\n]s", ramHO[i].estado_civil);
        fscanf(P, "\n%d",&ramHO[i].data_nacimento.dia);
        fscanf(P, "\n%d",&ramHO[i].data_nacimento.mes);
        fscanf(P, "\n%d",&ramHO[i].data_nacimento.ano);
    }
    fclose(P);
        
    return 0;
}

//funcao pra procurar hospede
int procura_hospede_txt(int codigo,int qtd, hospedes *procuraHO){
    
    
    for(int i=0;i<qtd;i++){
       if(procuraHO[i].codigo == codigo){
           return i;
           
       }
    }
    return -1;
}

//funcao para atualizar hospede
int atualiza_hospede_txt(int qtd,hospedes *ramHO){
    int status=0;
    FILE *P;
    
    P = fopen("hospedes_temp.txt", "w");
    
    if(P==NULL){
        printf("Problemas na abertura do arquivo.\n");
        exit (1);
    }
    for(int i=0;i<qtd;i++){
        fprintf(P,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n",
            ramHO[i].codigo,
            ramHO[i].nome, 
            ramHO[i].endereco_hospede.estado, 
            ramHO[i].endereco_hospede.cidade, 
            ramHO[i].endereco_hospede.cep,
            ramHO[i].endereco_hospede.bairro, 
            ramHO[i].endereco_hospede.rua, 
            ramHO[i].endereco_hospede.numero, 
            ramHO[i].cpf, 
            ramHO[i].telefone,
            ramHO[i].email,
            ramHO[i].sexo,
            ramHO[i].estado_civil,
            ramHO[i].data_nacimento.dia,
            ramHO[i].data_nacimento.mes,
            ramHO[i].data_nacimento.ano);
    }
    fclose(P);

    status = remove("hospedes.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para atualizar o cadastro do hospede.\n");
        exit(1);
    }
    status = rename("hospedes_temp.txt","hospedes.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para atualizar o cadastro do hospede.\n");
        exit(1);
    }
    printf("Atualização dos dados do hospede feita com sucesso.\n");
    return 0; 
}

//funcao para deletar hospede
int deleta_hospede_txt(int qtd, int posicao, hospedes *ramDELHO){
    int status=0;
//laço para pegar todos operadores apos o que vai ser excluido e trazer para tras
    for(int i=posicao;i<qtd;i++){//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente
       
        ramDELHO[i].codigo = ramDELHO[i+1].codigo;
        strcpy(ramDELHO[i].nome,ramDELHO[i+1].nome);
        strcpy(ramDELHO[i].endereco_hospede.estado,ramDELHO[i+1].endereco_hospede.estado);
        strcpy(ramDELHO[i].endereco_hospede.cidade,ramDELHO[i+1].endereco_hospede.cidade);
        strcpy(ramDELHO[i].endereco_hospede.cep,ramDELHO[i+1].endereco_hospede.cep);
        strcpy(ramDELHO[i].endereco_hospede.bairro,ramDELHO[i+1].endereco_hospede.bairro);
        strcpy(ramDELHO[i].endereco_hospede.rua,ramDELHO[i+1].endereco_hospede.rua);
        ramDELHO[i].endereco_hospede.numero = ramDELHO[i+1].endereco_hospede.numero;
        strcpy(ramDELHO[i].cpf,ramDELHO[i+1].cpf);
        strcpy(ramDELHO[i].telefone,ramDELHO[i+1].telefone);
        strcpy(ramDELHO[i].email,ramDELHO[i+1].email);
        strcpy(ramDELHO[i].sexo,ramDELHO[i+1].sexo);
        strcpy(ramDELHO[i].estado_civil,ramDELHO[i+1].estado_civil);
        ramDELHO[i].data_nacimento.dia = ramDELHO[i+1].data_nacimento.dia;
        ramDELHO[i].data_nacimento.mes = ramDELHO[i+1].data_nacimento.mes;
        ramDELHO[i].data_nacimento.ano = ramDELHO[i+1].data_nacimento.ano;
    }

    hospedes *P;
//diminuindo em um o tamanho do ponteiro
    P = malloc((qtd-1)*sizeof(hospedes));//realoca memoria com uma posicao a menos

    //pegando os dados dos operadores e passando para o ponteiro
    for(int i=0;i<qtd-1;i++){//preenche o ponteiro alocado com os dados dos operadores
        P[i].codigo = ramDELHO[i].codigo;
        strcpy(P[i].nome,ramDELHO[i].nome);
        strcpy(P[i].endereco_hospede.estado,ramDELHO[i].endereco_hospede.estado);
        strcpy(P[i].endereco_hospede.cidade,ramDELHO[i].endereco_hospede.cidade);
        strcpy(P[i].endereco_hospede.cep,ramDELHO[i].endereco_hospede.cep);
        strcpy(P[i].endereco_hospede.bairro,ramDELHO[i].endereco_hospede.bairro);
        strcpy(P[i].endereco_hospede.rua,ramDELHO[i].endereco_hospede.rua);
        P[i].endereco_hospede.numero = ramDELHO[i].endereco_hospede.numero;
        strcpy(P[i].cpf,ramDELHO[i].cpf);
        strcpy(P[i].telefone,ramDELHO[i].telefone);
        strcpy(P[i].email,ramDELHO[i].email);
        strcpy(P[i].sexo,ramDELHO[i].sexo);
        strcpy(P[i].estado_civil,ramDELHO[i].estado_civil);
        P[i].data_nacimento.dia = ramDELHO[i].data_nacimento.dia;
        P[i].data_nacimento.mes = ramDELHO[i].data_nacimento.mes;
        P[i].data_nacimento.ano = ramDELHO[i].data_nacimento.ano;
    }
    
    FILE *temp;

    temp = fopen("hospedes_temp.txt","w");
    if(temp == NULL ){
       return 1;
    }
    //retirando da quantidade o OP deletado
    qtd=qtd-1;
    //gravando o arquivo
    for(int i=0;i<qtd;i++){
        fprintf(temp,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n",
            P[i].codigo,
            P[i].nome, 
            P[i].endereco_hospede.estado, 
            P[i].endereco_hospede.cidade, 
            P[i].endereco_hospede.cep,
            P[i].endereco_hospede.bairro, 
            P[i].endereco_hospede.rua, 
            P[i].endereco_hospede.numero, 
            P[i].cpf, 
            P[i].telefone,
            P[i].email,
            P[i].sexo,
            P[i].estado_civil,
            P[i].data_nacimento.dia,
            P[i].data_nacimento.mes,
            P[i].data_nacimento.ano);
    }
    fclose(temp);
    status = remove("hospedes.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para deletar o hospede.\n");
        exit(1);
    }
    status = rename("hospedes_temp.txt","hospedes.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para deletar o hospede.\n");
        exit(1);
    }
    printf("Deleção do hospede feita com sucesso.\n");
    return 0;
}




//funcao para cadastrar produtos em txt
int cadastro_produtos_txt(produtos produtos_txt){
    
 FILE *P; //Ponteiro do arquivo TXT;
    
        P = fopen("produtos.txt","a");
  
    if(P==NULL){
        printf("Problemas na abertura do arquivo.");
        exit (1);
    }
    fprintf(P,"%d\n%s\n%d\n%d\n%f\n%f\n",
            produtos_txt.codigo,
            produtos_txt.descricao, 
            produtos_txt.estoque, 
            produtos_txt.estoque_min, 
            produtos_txt.preco_custo,
            produtos_txt.preco_venda);
    
    
    fclose(P);
    printf("Produto cadastrado com sucesso.\n");
    return 0;
    // fim da função de cadastro de operadores
}

//funcao para passar os produtos do txt para ram
int produtos_ram_txt(produtos *ramPROD, int qtd){
    
    FILE *P;
    int i=0;
    P=fopen("produtos.txt","r");
    
    for(i=0;i<qtd;i++){
        fscanf(P,"%d", &ramPROD[i].codigo);
        fscanf(P,"\n%[^\n]s", ramPROD[i].descricao);
        fscanf(P,"\n%d", &ramPROD[i].estoque);
        fscanf(P,"\n%d", &ramPROD[i].estoque_min);
        fscanf(P,"\n%f", &ramPROD[i].preco_custo);
        fscanf(P,"\n%f", &ramPROD[i].preco_venda);
    }
    fclose(P);
        
    return 0;
}

//funcao para procurar produto
int procura_produto_txt(int codigo,int qtd, produtos *procuraPRO){
    
    
    for(int i=0;i<qtd;i++){
       if(procuraPRO[i].codigo == codigo){
           return i;
           
       }
    }
    
    return -1;
}

//procura o produto pelo nome
int procura_produto_nome_txt(char *produto, int qtd, produtos *produtosRAM) {
    char *procura;
    for (int i = 0; i < qtd; i++) {
        // Utilizando strstr para busca insensível a maiúsculas/minúsculas
        procura = strstr(produtosRAM[i].descricao, produto);
        if (procura != NULL) {
            return i;
        }
    }

    return -1;
}

//funcao para atualizar o arquivo txt de produtos
int atualiza_produto_txt(int qtd, produtos *ramPROD){
    int status=0;
    FILE *P;
    
    P = fopen("produtos_temp.txt", "w");
    
    if(P==NULL){
        printf("Problemas na abertura do arquivo.\n");
        exit (1);
    }
    for(int i=0;i<qtd;i++){
        fprintf(P,"%d\n%s\n%d\n%d\n%f\n%f\n",
            ramPROD[i].codigo,
            ramPROD[i].descricao, 
            ramPROD[i].estoque, 
            ramPROD[i].estoque_min, 
            ramPROD[i].preco_custo,
            ramPROD[i].preco_venda);
    }
    fclose(P);

    status = remove("produtos.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para atualizar o produto.\n");
        exit(1);
    }
    status = rename("produtos_temp.txt","produtos.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para atualizar o produto.\n");
        exit(1);
    }
    printf("Atualização do produto feita com sucesso.\n");
    return 0; 
}

//função para deletar produtos
int deleta_produto_txt(int qtd, int posicao, produtos *ramDELPROD){
    int status=0;
//laço para pegar todos operadores apos o que vai ser excluido e trazer para tras
    for(int i=posicao;i<qtd;i++){//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente
       
        ramDELPROD[i].codigo = ramDELPROD[i+1].codigo;
        strcpy(ramDELPROD[i].descricao,ramDELPROD[i+1].descricao);
        ramDELPROD[i].estoque = ramDELPROD[i+1].estoque;
        ramDELPROD[i].estoque_min = ramDELPROD[i+1].estoque_min;
        ramDELPROD[i].preco_custo = ramDELPROD[i+1].preco_custo;
        ramDELPROD[i].preco_venda = ramDELPROD[i+1].preco_venda;
        
    }

    produtos *P;
//diminuindo em um o tamanho do ponteiro
    P = malloc((qtd-1)*sizeof(produtos));//realoca memoria com uma posicao a menos

    //pegando os dados dos operadores e passando para o ponteiro
    for(int i=0;i<qtd-1;i++){//preenche o ponteiro alocado com os dados dos operadores
        P[i].codigo = ramDELPROD[i].codigo;
        strcpy(P[i].descricao,ramDELPROD[i].descricao);
        P[i].estoque = ramDELPROD[i].estoque;
        P[i].estoque_min = ramDELPROD[i].estoque_min;
        P[i].preco_custo = ramDELPROD[i].preco_custo;
        P[i].preco_venda = ramDELPROD[i].preco_venda; 
    }
    
    FILE *temp;

    temp = fopen("produtos_temp.txt","w");
    if(temp == NULL ){
       return 1;
    }
    //retirando da quantidade o OP deletado
    qtd=qtd-1;
    //gravando o arquivo
    for(int i=0;i<qtd;i++){
        fprintf(temp,"%d\n%s\n%d\n%d\n%f\n%f\n",
            P[i].codigo,
            P[i].descricao, 
            P[i].estoque, 
            P[i].estoque_min, 
            P[i].preco_custo,
            P[i].preco_venda);
    }
    fclose(temp);
    status = remove("produtos.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para deletar o produto.\n");
        exit(1);
    }
    status = rename("produtos_temp.txt","produtos.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para deletar o produto.\n");
        exit(1);
    }
    printf("Deleção do produto feita com sucesso.\n");
    return 0; 
}

//funcao para mostrar os produtos que tem estoque
int mostra_produto_txt(int qtd,produtos *produtosRAM){
    for(int i=0;i<qtd;i++){
        if(produtosRAM[i].estoque>0){
            printf("Código:%d\n",produtosRAM[i].codigo);
            printf("%s\n",produtosRAM[i].descricao);
            printf("Preço:%.2f\n",produtosRAM[i].preco_venda);
            printf("Estoque diponível:%d\n\n",produtosRAM[i].estoque);
        }
    }
}



//fucao para cadastrar fornecedor
int cadastro_fornecedor_txt(fornecedores cadastro_fornecedor){
    FILE *P;
    //comando que abre o arquivo para escrita
    P=fopen("fornecedores.txt","a");
    //verifica se a criação do arquvio foi bem sucedida 
    if(P == NULL){
       printf("Problemas na abertura do arquivo.");
       exit (1);
    }
    //
    fprintf (P,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n",
            cadastro_fornecedor.codigo,
            cadastro_fornecedor.nome_fantasia,
            cadastro_fornecedor.razao_social,
            cadastro_fornecedor.inscricao_estadual,
            cadastro_fornecedor.cnpj,
            cadastro_fornecedor.endereco.estado,
            cadastro_fornecedor.endereco.cidade,
            cadastro_fornecedor.endereco.cep,
            cadastro_fornecedor.endereco.bairro,
            cadastro_fornecedor.endereco.rua,
            cadastro_fornecedor.endereco.numero,
            cadastro_fornecedor.telefone,
            cadastro_fornecedor.email);
    fclose(P);
    printf("Cadastros do fornecedor realizado com sucesso.\n\n");
    return 0;
// fim da funçao que abre um arquivo TXT para escrever e gravar dados do hotel que o usuario digitou
}

//funcao que traz fornecedor para ram
int fornecedores_ram_txt(fornecedores *ramFOR, int qtd){
    
    FILE *P;
    int i=0;
    P=fopen("fornecedores.txt","r");
    
    for(i=0;i<qtd;i++){
        fscanf(P,"%d",&ramFOR[i].codigo);
        fscanf(P,"\n%[^\n]s",ramFOR[i].nome_fantasia);
        fscanf(P,"\n%[^\n]s",ramFOR[i].razao_social);
        fscanf(P,"\n%[^\n]s",ramFOR[i].inscricao_estadual);
        fscanf(P,"\n%[^\n]s",ramFOR[i].cnpj);
        fscanf(P,"\n%[^\n]s",ramFOR[i].endereco.estado);
        fscanf(P,"\n%[^\n]s",ramFOR[i].endereco.cidade);
        fscanf(P,"\n%[^\n]s",ramFOR[i].endereco.cep);
        fscanf(P,"\n%[^\n]s",ramFOR[i].endereco.bairro);
        fscanf(P,"\n%[^\n]s",ramFOR[i].endereco.rua);
        fscanf(P,"\n%d",&ramFOR[i].endereco.numero);
        fscanf(P,"\n%[^\n]s",ramFOR[i].telefone);
        fscanf(P,"\n%[^\n]s",ramFOR[i].email);
    }
    fclose(P);
        
    return 0;
}

//funcao para procurar fornecedor
int procura_fornecedor_txt(int codigo,int qtd, fornecedores *procuraFOR){
    
    
    for(int i=0;i<qtd;i++){
       if(procuraFOR[i].codigo == codigo){
           return i;
           
       }
    }
    
    return -1;
}

///procura o fornecedor pelo nome
int procura_fornecedor_nome_txt(char *fornecedor, int qtd, fornecedores *fornecedorRAM) {
    char *procura;
    for (int i = 0; i < qtd; i++) {
        // Utilizando strstr para busca insensível a maiúsculas/minúsculas
        procura = strstr(fornecedorRAM[i].razao_social, fornecedor);
        if (procura != NULL) {
            return i;
        }
    }

    return -1;
}

//funcao para atualizar fornecedor
int atualiza_fornecedor_txt(int qtd,fornecedores *fornecedorAT){
    int status=0;
    FILE *P;
    
    P = fopen("fornecedores_temp.txt", "w");
    
    if(P==NULL){
        printf("Problemas na abertura do arquivo.\n");
        exit (1);
    }
    for(int i=0;i<qtd;i++){
        fprintf(P,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n",
            fornecedorAT[i].codigo,
            fornecedorAT[i].nome_fantasia,
            fornecedorAT[i].razao_social,
            fornecedorAT[i].inscricao_estadual,
            fornecedorAT[i].cnpj,
            fornecedorAT[i].endereco.estado,
            fornecedorAT[i].endereco.cidade,
            fornecedorAT[i].endereco.cep,
            fornecedorAT[i].endereco.bairro,
            fornecedorAT[i].endereco.rua,
            fornecedorAT[i].endereco.numero,
            fornecedorAT[i].telefone,
            fornecedorAT[i].email);
    }
    fclose(P);

    status = remove("fornecedores.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para atualizar o fornecedor.\n");
        exit(1);
    }
    status = rename("fornecedores_temp.txt","fornecedores.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para atualizar o fornecedor.\n");
        exit(1);
    }
    printf("Atualização dos dados do fornecedor feita com sucesso.\n");
    return 0; 
}

//funcao para deletar fornecedor
int deleta_fornecedor_txt(int qtd, int posicao, fornecedores *ramDELFOR){
    
    int status=0;
//laço para pegar todos fornecedores apos o que vai ser excluido e trazer para tras
    for(int i=posicao;i<qtd;i++){//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente
       
        ramDELFOR[i].codigo = ramDELFOR[i+1].codigo;
        strcpy(ramDELFOR[i].nome_fantasia,ramDELFOR[i+1].nome_fantasia);
        strcpy(ramDELFOR[i].razao_social,ramDELFOR[i+1].razao_social);
        strcpy(ramDELFOR[i].inscricao_estadual,ramDELFOR[i+1].inscricao_estadual);
        strcpy(ramDELFOR[i].cnpj,ramDELFOR[i+1].cnpj);
        strcpy(ramDELFOR[i].endereco.estado,ramDELFOR[i+1].endereco.estado);
        strcpy(ramDELFOR[i].endereco.cidade,ramDELFOR[i+1].endereco.cidade);
        strcpy(ramDELFOR[i].endereco.cep,ramDELFOR[i+1].endereco.cep);
        strcpy(ramDELFOR[i].endereco.bairro,ramDELFOR[i+1].endereco.bairro);
        strcpy(ramDELFOR[i].endereco.rua,ramDELFOR[i+1].endereco.rua);
        ramDELFOR[i].endereco.numero = ramDELFOR[i+1].endereco.numero;
        strcpy(ramDELFOR[i].telefone,ramDELFOR[i+1].telefone);
        strcpy(ramDELFOR[i].email,ramDELFOR[i+1].email);
    }    

    fornecedores *P;
//diminuindo em um o tamanho do ponteiro
    P = malloc((qtd-1)*sizeof(fornecedores));//realoca memoria com uma posicao a menos

    //pegando os dados dos operadores e passando para o ponteiro
    for(int i=0;i<qtd-1;i++){//preenche o ponteiro alocado com os dados dos operadores
        P[i].codigo = ramDELFOR[i].codigo;
        strcpy(P[i].nome_fantasia,ramDELFOR[i].nome_fantasia);
        strcpy(P[i].razao_social,ramDELFOR[i].razao_social);
        strcpy(P[i].inscricao_estadual,ramDELFOR[i].inscricao_estadual);
        strcpy(P[i].cnpj,ramDELFOR[i].cnpj);
        strcpy(P[i].endereco.estado,ramDELFOR[i].endereco.estado);
        strcpy(P[i].endereco.cidade,ramDELFOR[i].endereco.cidade);
        strcpy(P[i].endereco.cep,ramDELFOR[i].endereco.cep);
        strcpy(P[i].endereco.bairro,ramDELFOR[i].endereco.bairro);
        strcpy(P[i].endereco.rua,ramDELFOR[i].endereco.rua);
        P[i].endereco.numero = ramDELFOR[i].endereco.numero;
        strcpy(P[i].telefone,ramDELFOR[i].telefone);
        strcpy(P[i].telefone,ramDELFOR[i].email);
    }
    
    FILE *temp;

    temp = fopen("fornecedores_temp.txt","w");
    if(temp == NULL ){
       return 1;
    }
    //retirando da quantidade o OP deletado
    qtd=qtd-1;
    //gravando o arquivo
    for(int i=0;i<qtd;i++){
        fprintf (temp,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n",
            P[i].codigo,
            P[i].nome_fantasia,
            P[i].razao_social,
            P[i].inscricao_estadual,
            P[i].cnpj,
            P[i].endereco.estado,
            P[i].endereco.cidade,
            P[i].endereco.cep,
            P[i].endereco.bairro,
            P[i].endereco.rua,
            P[i].endereco.numero,
            P[i].telefone,
            P[i].email);
    }
    fclose(temp);
    status = remove("fornecedores.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para deletar o fornecedor.\n");
        exit(1);
    }
    status = rename("fornecedores_temp.txt","fornecedor.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para deletar o fornecedor.\n");
        exit(1);
    }
    printf("Deleção do fornecedor feita com sucesso.\n");
    return 0; 
    
}




//funcao para cadastrar categoria de acomadações em txt
int cadastro_categoria_txt(categoria_acomodacao cadatro_categoria){
    
 FILE *P; //Ponteiro do arquivo TXT;
    
        P = fopen("categorias.txt","a");
  
    if(P==NULL){
        printf("Problemas na abertura do arquivo.");
        exit (1);
    }
    fprintf(P,"%d\n%s\n%f\n%d\n%d\n",
            cadatro_categoria.codigo,
            cadatro_categoria.descricao, 
            cadatro_categoria.valor_diaria, 
            cadatro_categoria.adultos, 
            cadatro_categoria.criancas);
    
    
    fclose(P);
    printf("Categoria cadastrado com sucesso.\n");
    return 0;
    // fim da função de cadastro de categorias
}

//funcao para passar as categorias do txt para ram
int categorias_ram_txt(categoria_acomodacao *ramCAT, int qtd){
    
    FILE *P;
    int i=0;
    P=fopen("categorias.txt","r");
    
    for(i=0;i<qtd;i++){
        fscanf(P,"%d", &ramCAT[i].codigo);
        fscanf(P,"\n%[^\n]s", ramCAT[i].descricao);
        fscanf(P,"\n%f", &ramCAT[i].valor_diaria);
        fscanf(P,"\n%d", &ramCAT[i].adultos);
        fscanf(P,"\n%d", &ramCAT[i].criancas);
        //printf("Codigo da categoria:%d\n",ramCAT[i].codigo);
        //printf("Descrição da categoria:%s\n",ramCAT[i].descricao);
        //printf("Valor da diária da categoria:%f\n",ramCAT[i].valor_diaria);
        //printf("Adultos comportadas:%d\n",ramCAT[i].adultos);
        //printf("Crianças comportadas:%d\n\n\n",ramCAT[i].criancas);
    }
    fclose(P);
        
    return 0;
}

//funcao para procurar categoria
int procura_categoria_txt(int codigo,int qtd, categoria_acomodacao *procuraCAT){

    for(int i=0;i<qtd;i++){
       if(procuraCAT[i].codigo == codigo){
           return i;          
       }
    }

    return -1;
}

//funcao para atualizar a categoria txt 
int atualiza_categoria_txt(int qtd, categoria_acomodacao *categoriaAT){
    int status=0;
    FILE *P;
    
    P = fopen("categorias_temp.txt", "w");
    
    if(P==NULL){
        printf("Problemas na abertura do arquivo.\n");
        exit (1);
    }
    for(int i=0;i<qtd;i++){
        fprintf(P,"%d\n%s\n%f\n%d\n%d\n",
            categoriaAT[i].codigo,
            categoriaAT[i].descricao, 
            categoriaAT[i].valor_diaria, 
            categoriaAT[i].adultos, 
            categoriaAT[i].criancas);
    }
    fclose(P);

    status = remove("categorias.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para atualizar a categoria.\n");
        exit(1);
    }
    status = rename("categorias_temp.txt","categorias.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para atualizar a categoria.\n");
        exit(1);
    }
    printf("Atualização da categoria feita com sucesso.\n");
    return 0; 
}

//função para deletar categoria
int deleta_categoria_txt(int qtd, int posicao, categoria_acomodacao *categoriaDEL){
    int status=0;
    
//laço para pegar todas categorias apos o que vai ser excluido e trazer para tras
    for(int i=posicao;i<qtd;i++){//sobrescreve os dados da categoria seguinte ao que será deletado, e assim sucessivamente
       
        categoriaDEL[i].codigo = categoriaDEL[i+1].codigo;
        strcpy(categoriaDEL[i].descricao,categoriaDEL[i+1].descricao);
        categoriaDEL[i].valor_diaria = categoriaDEL[i+1].valor_diaria;
        categoriaDEL[i].adultos = categoriaDEL[i+1].adultos;
        categoriaDEL[i].criancas = categoriaDEL[i+1].criancas;
    }

    categoria_acomodacao *P;
    //alocando a memoria para o tamanho atual sem a categoria deletado
    P = malloc((qtd-1)*sizeof(categoria_acomodacao));

    //pegando os dados das categorias e passando para o ponteiro
    for(int i=0;i<qtd-1;i++){//preenche o ponteiro alocado com os dados dos operadores
        P[i].codigo = categoriaDEL[i].codigo;
        strcpy(P[i].descricao,categoriaDEL[i].descricao);
        P[i].valor_diaria = categoriaDEL[i].valor_diaria;
        P[i].adultos = categoriaDEL[i].adultos;
        P[i].criancas = categoriaDEL[i].criancas;
    }
    
    FILE *temp;

    temp = fopen("categorias_temp.txt","w");
    if(temp == NULL ){
       return 1;
    }
    //retirando da quantidade o OP deletado
    qtd=qtd-1;
    //gravando o arquivo
    for(int i=0;i<qtd;i++){
        fprintf(temp,"%d\n%s\n%f\n%d\n%d\n",
            P[i].codigo,
            P[i].descricao, 
            P[i].valor_diaria, 
            P[i].adultos, 
            P[i].criancas);
    }
    fclose(temp);
    status = remove("categorias.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para deletar a categoria.\n");
        exit(1);
    }
    status = rename("categorias_temp.txt","categorias.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para deletar a categoria.\n");
        exit(1);
    }
    printf("Deleção da categoria feita com sucesso.\n");
    return 0; 
}




//funcao para cadastrar categoria de acomadações em txt
int cadastro_acomodacoes_txt(acomodacoes cadatro_acomodacoes){
    
 FILE *P; //Ponteiro do arquivo TXT;
    
        P = fopen("acomodacoes.txt","a");
  
    if(P==NULL){
        printf("Problemas na abertura do arquivo.");
        exit (1);
    }
    fprintf(P,"%d\n%s\n%s\n%d\n%d\n%f\n%d\n",
            cadatro_acomodacoes.codigo,
            cadatro_acomodacoes.descricao, 
            cadatro_acomodacoes.facilidades, 
            cadatro_acomodacoes.categoria,
            cadatro_acomodacoes.diarias,
            cadatro_acomodacoes.lucro,
            cadatro_acomodacoes.ocupacao);
   
    
    
    fclose(P);
    printf("Acomodação cadastrado com sucesso.\n");
    return 0;
    // fim da função de cadastro de categorias
}

//funcao para passar as acomodações do txt para ram
int acomodacoes_ram_txt(acomodacoes *ramCOM, int qtd){
    
    FILE *P;
    int i=0;
    P=fopen("acomodacoes.txt","r");
    
    for(i=0;i<qtd;i++){
        fscanf(P,"%d", &ramCOM[i].codigo);
        fscanf(P,"\n%[^\n]s", ramCOM[i].descricao);
        fscanf(P,"\n%[^\n]s", ramCOM[i].facilidades);
        fscanf(P,"\n%d", &ramCOM[i].categoria);
        fscanf(P,"\n%d", &ramCOM[i].diarias);
        fscanf(P,"\n%f", &ramCOM[i].lucro);
        fscanf(P,"\n%d", &ramCOM[i].ocupacao);
    }
    fclose(P);
        
    return 0;
}

//funcao para procurar categoria
int procura_acomodacao_txt(int codigo,int qtd, acomodacoes *procuraCOM){

    for(int i=0;i<qtd;i++){
       if(procuraCOM[i].codigo == codigo){
           return i;          
       }
    }

    return -1;
}

//funcao para atualizar as acomodações txt 
int atualiza_acomodacoes_txt(int qtd, acomodacoes *acomodacoesAT){
    int status=0;
    FILE *P;
    
    P = fopen("acomodacoes_temp.txt", "w");
    
    if(P==NULL){
        printf("Problemas na abertura do arquivo.\n");
        exit (1);
    }
    for(int i=0;i<qtd;i++){
        fprintf(P,"%d\n%s\n%s\n%d\n%d\n%f\n%d\n",
            acomodacoesAT[i].codigo,
            acomodacoesAT[i].descricao, 
            acomodacoesAT[i].facilidades, 
            acomodacoesAT[i].categoria,
            acomodacoesAT[i].diarias,
            acomodacoesAT[i].lucro,
            acomodacoesAT[i].ocupacao);
    }
    fclose(P);

    status = remove("acomodacoes.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para atualizar a acomodação.\n");
        exit(1);
    }
    status = rename("acomodacoes_temp.txt","acomodacoes.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para atualizar a acomadação.\n");
        exit(1);
    }
    printf("Atualização da acomadação feita com sucesso.\n");
    return 0; 
}

//função para deletar acomodação
int deleta_acomodacoes_txt(int qtd, int posicao, acomodacoes *acomadacaoDEL){
    int status=0;
    
//laço para pegar todas acomodacoes apos o que vai ser excluido e trazer para tras
    for(int i=posicao;i<qtd;i++){//sobrescreve os dados da acomodacoes seguinte ao que será deletado, e assim sucessivamente
       
        acomadacaoDEL[i].codigo = acomadacaoDEL[i+1].codigo;
        strcpy(acomadacaoDEL[i].descricao,acomadacaoDEL[i+1].descricao);
        strcpy(acomadacaoDEL[i].facilidades,acomadacaoDEL[i+1].facilidades);
        acomadacaoDEL[i].categoria = acomadacaoDEL[i+1].categoria;
        acomadacaoDEL[i].diarias = acomadacaoDEL[i+1].diarias;
        acomadacaoDEL[i].lucro = acomadacaoDEL[i+1].lucro;
        acomadacaoDEL[i].ocupacao = acomadacaoDEL[i+1].ocupacao;
    }

    acomodacoes *P;
    //alocando a memoria para o tamanho atual sem a categoria deletado
    P = malloc((qtd-1)*sizeof(acomodacoes));

    //pegando os dados das categorias e passando para o ponteiro
    for(int i=0;i<qtd-1;i++){//preenche o ponteiro alocado com os dados dos operadores
        P[i].codigo = acomadacaoDEL[i].codigo;
        strcpy(P[i].descricao,acomadacaoDEL[i].descricao);
        strcpy(P[i].facilidades,acomadacaoDEL[i].facilidades);
        P[i].categoria = acomadacaoDEL[i].categoria;
        P[i].diarias = acomadacaoDEL[i].diarias;
        P[i].lucro = acomadacaoDEL[i].lucro;
        P[i].ocupacao = acomadacaoDEL[i].ocupacao;
    }
    
    FILE *temp;

    temp = fopen("acomodacoes_temp.txt","w");
    if(temp == NULL ){
       return 1;
    }
    //retirando da quantidade o OP deletado
    qtd=qtd-1;
    //gravando o arquivo
    for(int i=0;i<qtd;i++){
        fprintf(temp,"%d\n%s\n%s\n%d\n%d\n%f\n%d\n",
            P[i].codigo,
            P[i].descricao, 
            P[i].facilidades, 
            P[i].categoria,
            P[i].diarias,
            P[i].lucro,
            P[i].categoria);
    }
    fclose(temp);
    status = remove("acomodacoes.txt");
    
    if(status != 0){
        printf("Erro na remoção do arquivo para deletar a acomodação.\n");
        exit(1);
    }
    status = rename("acomodacoes_temp.txt","acomodacoes.txt");
    
    if(status !=0){
        printf("Erro na renomeção do arquivo para deletar a acomodação.\n");
        exit(1);
    }
    printf("Deleção da acomodação feita com sucesso.\n");
    return 0; 
}



//funcao para cadastra conta do hospede txt
int cadastro_conta_txt(conta_hospede conta){
   FILE *P; //Ponteiro do arquivo TXT;

    P = fopen("conta_hospedes.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    fprintf(P, "%d\n%d\n%f\n",
            conta.codigo_hos,
            conta.codigo_res,
            conta.valor_devido);


    fclose(P);
    printf("Conta cadastrada com sucesso.\n");
    return 0;
}

//funcao que traz todas contas dos hospedes pra ram
int conta_ram_txt(conta_hospede *conta,int qtd){
    FILE *P;
    int i = 0;
    P = fopen("conta_hospedes.txt", "r");

    for (i = 0; i < qtd; i++) {
        fscanf(P, "%d", &conta[i].codigo_hos);
        fscanf(P, "\n%d", &conta[i].codigo_res);
        fscanf(P, "\n%f", &conta[i].valor_devido);
    }
    fclose(P);

    return 0;
}

//funcao para procurar conta do hospede
int procura_conta_txt(int cod_res, conta_hospede *conta,int qtd) {

    for (int i = 0; i < qtd; i++) {
        if (conta[i].codigo_res == cod_res) {
            return i;
        }
    }

    return -1;
}

//funcao para atualizar conta do hospede
int atualiza_conta_txt(int qtd,conta_hospede *conta){
    int status = 0;
    FILE *P;

    P = fopen("conta_hospedes_temp.txt", "w");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.\n");
        exit(1);
    }
    for (int i = 0; i < qtd; i++) {
        fprintf(P, "%d\n%d\n%f\n",
            conta[i].codigo_hos,
            conta[i].codigo_res,
            conta[i].valor_devido);
    }
    fclose(P);

    status = remove("conta_hospedes.txt");

    if (status != 0) {
        printf("Erro na remoção do arquivo para atualizar a conta.\n");
        exit(1);
    }
    status = rename("conta_hospedes_temp.txt", "conta_hospedes.txt");

    if (status != 0) {
        printf("Erro na renomeção do arquivo para atualizar a conta.\n");
        exit(1);
    }
    printf("Atualização da conta feita com sucesso.\n");
    return 0; 
}

//funcao para deletar conta do hospede
int deleta_conta_txt(int qtd, int posicao, conta_hospede *conta) {
    int status = 0;

    //laço para pegar todas acomodacoes apos o que vai ser excluido e trazer para tras
    for (int i = posicao; i < qtd; i++) {//sobrescreve os dados da acomodacoes seguinte ao que será deletado, e assim sucessivamente

        conta[i].codigo_hos = conta[i + 1].codigo_hos;
        conta[i].codigo_res = conta[i + 1].codigo_res;
        conta[i].valor_devido = conta[i + 1].valor_devido;
    }

    conta_hospede *P;
    //alocando a memoria para o tamanho atual sem a categoria deletado
    P = malloc((qtd - 1) * sizeof (conta_hospede));

    //pegando os dados das categorias e passando para o ponteiro
    for (int i = 0; i < qtd - 1; i++) {//preenche o ponteiro alocado com os dados dos operadores
        P[i].codigo_hos = conta[i].codigo_hos;
        P[i].codigo_res = conta[i].codigo_res;
        P[i].valor_devido = conta[i].valor_devido;
    }

    FILE *temp;

    temp = fopen("conta_hospedes_temp.txt", "w");
    if (temp == NULL) {
        return 1;
    }
    //retirando da quantidade o OP deletado
    qtd = qtd - 1;
    //gravando o arquivo
    for (int i = 0; i < qtd; i++) {
        fprintf(temp, "%d\n%d\n%f\n",
            P[i].codigo_hos,
            P[i].codigo_res,
            P[i].valor_devido);
    }
    fclose(temp);
    status = remove("conta_hospedes.txt");

    if (status != 0) {
        printf("Erro na remoção do arquivo para deletar a conta.\n");
        exit(1);
    }
    status = rename("conta_hospedes_temp.txt", "conta_hospedes.txt");

    if (status != 0) {
        printf("Erro na renomeção do arquivo para deletar a conta.\n");
        exit(1);
    }
    printf("Deleção da conta feita com sucesso.\n");
    return 0;
}


//faz o cadastro da venda do produto
int cadastrar_venda_txt(vendas venda){
    FILE *P; //Ponteiro do arquivo TXT;

    P = fopen("vendas.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    fprintf(P, "%d;%d;%d;%d;%f;\n",
            venda.pagamento,
            venda.cod_hos,
            venda.cod_prod,
            venda.qtd,
            venda.valor);


    fclose(P);
    printf("Notinha cadastrada com sucesso.\n");
    return 0;
}

//traz as vendas pra ram
int ram_venda_txt(vendas *venda,int qtd) {
    FILE *P;

    P = fopen("vendas.txt", "r");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }

    for (int i = 0; i < qtd; i++) {
        fscanf(P, "%d;%d;%d;%d;%f;", &venda[i].pagamento, &venda[i].cod_hos, &venda[i].cod_prod, &venda[i].qtd, &venda[i].valor);
    }
    
    
    fclose(P);
    return 0;
}



//funcao para adicionar valor no caixa txt
int adicionar_caixa_txt(float valor,int cod_hos,int controle){
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    
    if (controle == 0) {
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("caixa.txt", "a");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        fprintf(P, "%d\n%f\n%d\n%d\n%d\n",
                cod_hos,
                valor,
                tm.tm_mday,
                tm.tm_mon + 1,
                tm.tm_year + 1900);
 

        fclose(P);
        printf("Caixa cadastrado com sucesso.\n");
        return 0;

    } else if (controle == 1) {
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("caixa.txt", "a");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        fprintf(P, "%d\n-%f\n%d\n%d\n%d\n",
                cod_hos,
                valor,
                tm.tm_mday,
                tm.tm_mon + 1,
                tm.tm_year + 1900);


        fclose(P);
        printf("Conta cadastrado com sucesso.\n");
        return 0;
    }
}

//funcao para cadastrar caixa com todos os dados, sem pegar a data atual
int cadastrar_caixa_txt(conta_receber caixa){
    FILE *P; //Ponteiro do arquivo TXT;

    P = fopen("caixa.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    fprintf(P, "%d\n%f\n%d\n%d\n%d\n",
            caixa.codigo_hos,
            caixa.valor_devido,
            caixa.date.dia,
            caixa.date.mes,
            caixa.date.ano);


    fclose(P);
    printf("Caixa cadastrado com sucesso.\n");
    return 0;
}

//trazendo dados do caixa para memoria
int caixa_ram_txt(conta_receber *caixaRAM,int qtd){
    FILE *P;
    int i = 0;
    P = fopen("caixa.txt", "r");

    for (i = 0; i < qtd; i++) {
        fscanf(P, "%d", &caixaRAM[i].codigo_hos);
        fscanf(P, "\n%f", &caixaRAM[i].valor_devido);
        fscanf(P, "\n%d", &caixaRAM[i].date.dia);
        fscanf(P, "\n%d", &caixaRAM[i].date.mes);
        fscanf(P, "\n%d", &caixaRAM[i].date.ano);
    }
    fclose(P);

    return 0;
}

//funcao para printar os valores do caixa
void mostra_caixa_txt(){
    int qtd_caixa;
    qtd_caixa = contadorlinhas_txt("caixa.txt");
    qtd_caixa = qtd_caixa / 5;
    conta_receber caixaRAM[qtd_caixa];
    caixa_ram_txt(caixaRAM, qtd_caixa);
    
    for (int i = 0; i < qtd_caixa; i++) {
        printf("Código: %d\n", caixaRAM[i].codigo_hos);

        // Verifica se o valor é positivo ou negativo e imprime o sinal correspondente
        if (caixaRAM[i].valor_devido >= 0) {
            printf("Valor: +%.2f\n", caixaRAM[i].valor_devido);
        } else {
            printf("Valor: %.2f\n", caixaRAM[i].valor_devido);
        }

        printf("Data: %d/%d/%d\n", caixaRAM[i].date.dia, caixaRAM[i].date.mes, caixaRAM[i].date.ano);
    }
}




//funcao para adicionar no arquivo contas a receber quando alguem pagar no cartao
int adicionar_contas_a_receber_txt(data datas,int cod_hos,float valor){
    FILE *P; //Ponteiro do arquivo TXT;

    P = fopen("contas_receber.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    fprintf(P, "%d\n%f\n%d\n%d\n%d\n",
            cod_hos,
            valor,
            datas.dia,
            datas.mes,
            datas.ano);


    fclose(P);
    printf("Conta a receber cadastrada com sucesso.\n");
    return 0;
}

//traznedo contas a receber para memoria ram
int contas_receber_ram_txt(conta_receber *contasRAM,int qtd_conta){
    FILE *P;
    int i = 0;
    P = fopen("contas_receber.txt", "r");

    for (i = 0; i < qtd_conta; i++) {
        fscanf(P, "%d", &contasRAM[i].codigo_hos);
        fscanf(P, "\n%f", &contasRAM[i].valor_devido);
        fscanf(P, "\n%d", &contasRAM[i].date.dia);
        fscanf(P, "\n%d", &contasRAM[i].date.mes);
        fscanf(P, "\n%d", &contasRAM[i].date.ano);
    }
    fclose(P);
    
    return 0;
}

//deletando conta receber 
int deleta_conta_receber_txt(int qtd, int posicao, conta_receber *conta) {
    int status = 0;

    //laço para pegar todas acomodacoes apos o que vai ser excluido e trazer para tras
    for (int i = posicao; i < qtd; i++) {//sobrescreve os dados da acomodacoes seguinte ao que será deletado, e assim sucessivamente

        conta[i].codigo_hos = conta[i + 1].codigo_hos;
        conta[i].valor_devido = conta[i + 1].valor_devido;
        conta[i].date.dia = conta[i + 1].date.dia;
        conta[i].date.mes = conta[i + 1].date.mes;
        conta[i].date.ano = conta[i + 1].date.ano;
    }

    conta_receber *P;
    //alocando a memoria para o tamanho atual sem a categoria deletado
    P = malloc((qtd - 1) * sizeof (conta_receber));

    //pegando os dados das categorias e passando para o ponteiro
    for (int i = 0; i < qtd - 1; i++) {//preenche o ponteiro alocado com os dados dos operadores
        P[i].codigo_hos = conta[i].codigo_hos;
        P[i].valor_devido = conta[i].valor_devido;
        P[i].date.dia = conta[i].date.dia;
        P[i].date.mes = conta[i].date.mes;
        P[i].date.ano = conta[i].date.ano;
    }

    FILE *temp;

    temp = fopen("contas_receber_temp.txt", "w");
    if (temp == NULL) {
        return 1;
    }
    //retirando da quantidade o OP deletado
    qtd = qtd - 1;
    //gravando o arquivo
    for (int i = 0; i < qtd; i++) {
        fprintf(temp, "%d\n%f\n%d\n%d\n%d\n",
            P[i].codigo_hos,
            P[i].valor_devido,
            P[i].date.dia,
            P[i].date.mes,
            P[i].date.ano);
    }
    fclose(temp);
    status = remove("contas_receber.txt");

    if (status != 0) {
        printf("Erro na remoção do arquivo para dar baixa na conta.\n");
        exit(1);
    }
    status = rename("contas_receber_temp.txt", "contas_receber.txt");

    if (status != 0) {
        printf("Erro na renomeção do arquivo para dar baixa na conta.\n");
        exit(1);
    }
    printf("Baixa da conta feita com sucesso.\n");
    return 0;
}

//funcao para printar os valores das contas a receber
int mostra_contas_a_receber_txt(int qtd_conta, conta_receber *conta) {
       

    for (int i = 0; i < qtd_conta; i++) {
        printf("Codigo da conta:%d\n",i);
        printf("Código do hóspede: %d\n", conta[i].codigo_hos);
        printf("Valor: +%.2f\n", conta[i].valor_devido);
        printf("Data: %d/%d/%d\n\n", conta[i].date.dia, conta[i].date.mes, conta[i].date.ano);
    }
    return qtd_conta;
}




//cadastrando conta a pagar
int adicionar_contas_pagar_txt(float valor,int vezes, int cod_for){
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    
    
    valor=valor/vezes;
    
    for(int i=0;i<vezes;i++){
        // Adicionar 30 dias
        tm.tm_mday += 30;
        time_t newTime = mktime(&tm);

        // Extrair dia, mês e ano da nova data
        struct tm newTm = *localtime(&newTime);
        int newDay = newTm.tm_mday;
        int newMonth = newTm.tm_mon + 1; // tm_mon é base 0 (janeiro = 0)
        int newYear = newTm.tm_year + 1900;

        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("contas_pagar.txt", "a");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        fprintf(P, "%d\n%f\n%d\n%d\n%d\n",
                cod_for,
                valor,
                newDay,
                newMonth,
                newYear);
        fclose(P);
        
    }
    
    printf("Conta a pagar cadastrada com sucesso.\n");
    
    return 0;
    
}

int cadastrar_contas_pagar_txt(conta_receber conta){
    FILE *P; //Ponteiro do arquivo TXT;

    P = fopen("contas_pagar.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    fprintf(P, "%d\n%f\n%d\n%d\n%d\n",
            conta.codigo_hos,
            conta.valor_devido,
            conta.date.dia,
            conta.date.mes,
            conta.date.ano);
    fclose(P);

    printf("Conta a pagar cadastrada com sucesso.\n");

    return 0;
}

// trazendo contas a pagar para memoria ram
int contas_pagar_ram_txt(conta_receber *contasRAM, int qtd_conta) {
    FILE *P;
    int i = 0;
    P = fopen("contas_pagar.txt", "r");

    for (i = 0; i < qtd_conta; i++) {
        fscanf(P, "%d", &contasRAM[i].codigo_hos);
        fscanf(P, "\n%f", &contasRAM[i].valor_devido);
        fscanf(P, "\n%d", &contasRAM[i].date.dia);
        fscanf(P, "\n%d", &contasRAM[i].date.mes);
        fscanf(P, "\n%d", &contasRAM[i].date.ano);
    }
    fclose(P);

    return 0;
}

 //funcao para printar os valores das contas a pagar
int mostra_contas_a_pagar_txt(int qtd_conta, conta_receber *conta) {


    for (int i = 0; i < qtd_conta; i++) {
        printf("Codigo da conta:%d\n", i);
        printf("Codigo do fornecedor:%d",conta[i].codigo_hos);
        printf("Valor: +%.2f\n", conta[i].valor_devido);
        printf("Data: %d/%d/%d\n\n", conta[i].date.dia, conta[i].date.mes, conta[i].date.ano);
    }
    return qtd_conta;
}

//deletando conta receber 
int deleta_conta_pagar_txt(int qtd, int posicao, conta_receber *conta) {
    int status = 0;

    //laço para pegar todas acomodacoes apos o que vai ser excluido e trazer para tras
    for (int i = posicao; i < qtd; i++) {//sobrescreve os dados da acomodacoes seguinte ao que será deletado, e assim sucessivamente
        
        conta[i].codigo_hos = conta[i + 1].codigo_hos;
        conta[i].valor_devido = conta[i + 1].valor_devido;
        conta[i].date.dia = conta[i + 1].date.dia;
        conta[i].date.mes = conta[i + 1].date.mes;
        conta[i].date.ano = conta[i + 1].date.ano;
    }

    conta_receber *P;
    //alocando a memoria para o tamanho atual sem a categoria deletado
    P = malloc((qtd - 1) * sizeof (conta_receber));

    //pegando os dados das categorias e passando para o ponteiro
    for (int i = 0; i < qtd - 1; i++) {//preenche o ponteiro alocado com os dados dos operadores
        P[i].codigo_hos = conta[i].codigo_hos;
        P[i].valor_devido = conta[i].valor_devido;
        P[i].date.dia = conta[i].date.dia;
        P[i].date.mes = conta[i].date.mes;
        P[i].date.ano = conta[i].date.ano;
    }

    FILE *temp;

    temp = fopen("contas_pagar_temp.txt", "w");
    if (temp == NULL) {
        return 1;
    }
    //retirando da quantidade o OP deletado
    qtd = qtd - 1;
    //gravando o arquivo
    for (int i = 0; i < qtd; i++) {
        fprintf(temp, "%d\n%f\n%d\n%d\n%d\n",
                P[i].codigo_hos,
                P[i].valor_devido,
                P[i].date.dia,
                P[i].date.mes,
                P[i].date.ano);
    }
    fclose(temp);
    status = remove("contas_pagar.txt");

    if (status != 0) {
        printf("Erro na remoção do arquivo para dar baixa na conta.\n");
        exit(1);
    }
    status = rename("contas_pagar_temp.txt", "contas_pagar.txt");

    if (status != 0) {
        printf("Erro na renomeção do arquivo para dar baixa na conta.\n");
        exit(1);
    }
    printf("Baixa da conta feita com sucesso.\n");
    return 0;
}



//funcao para cadastrar nota fiscal
int cadastrar_notafiscal_txt(NotaFiscal notas){
    FILE *P; // Ponteiro do arquivo TXT

    P = fopen("notas_fiscais.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }

    fprintf(P, "%s\n%s\n%f\n%f\n%f\n%d\n",
            notas.fornecedor,
            notas.cnpj,
            notas.frete,
            notas.imposto,
            notas.total,
            notas.num_produtos);

    for (int i = 0; i < notas.num_produtos; i++) {
        fprintf(P, "%s;%f;%d;%f;",
                notas.entra_prod[i].nome,
                notas.entra_prod[i].preco,
                notas.entra_prod[i].quantidade,
                notas.entra_prod[i].subtotal);
    }

    fprintf(P, "\n");

    fclose(P);
    printf("Nota cadastrada com sucesso.\n");
    return 0;
}

//funcao para trazer dados das notas fiscais para memoria
int ram_notafiscal_txt(int qtd_notas, NotaFiscal *notas) {
    
    FILE *arquivo = fopen("notas_fiscais.txt", "r");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < qtd_notas; i++) {
        // Lê os dados da nota fiscal
        fscanf(arquivo, "\n%[^\n]\n%[^\n]\n%f\n%f\n%f\n%d\n",
                notas[i].fornecedor,
                notas[i].cnpj,
                &notas[i].frete,
                &notas[i].imposto,
                &notas[i].total,
                &notas[i].num_produtos);

        // Aloca memória para os produtos
        notas[i].entra_prod = malloc(notas[i].num_produtos * sizeof (entrada_produto));
        if (notas[i].entra_prod == NULL) {
            perror("Erro ao alocar memória para produtos");
            exit(EXIT_FAILURE);
        }

        // Lê os dados dos produtos da nota fiscal
        for (int j = 0; j < notas[i].num_produtos; j++) {
            // Lê os dados do produto
            fscanf(arquivo, "%[^;];%f;%d;%f;",
                    notas[i].entra_prod[j].nome,
                    &notas[i].entra_prod[j].preco,
                    &notas[i].entra_prod[j].quantidade,
                    &notas[i].entra_prod[j].subtotal);
        }
    }

    fclose(arquivo);

    return 0; 
}



//funcao para filtra e printar ou salvar a listagem de hospedes
int listagem_hospede_txt(int *codigo, int *listagem,char *sexo,int opcao) {
    int qtd_hos,contador=0;
    qtd_hos = contadorlinhas_txt("hospedes.txt");
    qtd_hos=qtd_hos/16;
    
    hospedes *hospedesRAM = malloc(qtd_hos * sizeof(hospedes));
    hospedes_ram_txt(hospedesRAM, qtd_hos);
    
    hospedes *hospedesAUX;

    
    if(listagem[0]!=0){
        hospedesAUX = malloc(qtd_hos * sizeof(hospedes));
        for(int i=0;i<qtd_hos;i++){
            if(codigo[0] <= hospedesRAM[i].codigo && hospedesRAM[i].codigo <= codigo[1]){
                hospedesAUX[contador]=hospedesRAM[i];           
                contador++;
            }
        }
        if(contador==0){
            printf("\nNenhum hóspede com esse intervalo de codigo.\n");
            return 0;
        }
        //realocando o hospedes ram para ficar do tamanho da quantidadede de hospedes filtrador
        hospedesRAM = realloc(hospedesRAM, contador * sizeof (hospedes));
        
        //copiando os dados do aux para ram para que caso utilizar ma proxima filtragem ou nao
        memcpy(hospedesRAM,hospedesAUX , contador * sizeof (hospedes));

        //igualando qtd de hospedes ao contador para ficar com a nova qtd de hospedes
        qtd_hos=contador;
        free(hospedesAUX);
    }
    
    
    if(listagem[1]!=0){
        hospedesAUX= malloc(qtd_hos * sizeof(hospedes));
        contador=0;
        for(int i=0;i<qtd_hos;i++){
            if (strcmp(sexo, hospedesRAM[i].sexo) == 0) {
                hospedesAUX[contador]=hospedesRAM[i];
                contador++;
            }
        }
        if (contador == 0 && listagem[0] != 0) {
            printf("\nNenhum hóspede encontrado com esse sexo e intervalo de codigo.\n");
            return;
        } else if (contador == 0) {
            printf("\nNenhum hóspede encontrado com esse sexo.\n");
        }
        //realocando o hospedes ram para ficar do tamanho da quantidadede de hospedes filtrador
        hospedesRAM = realloc(hospedesRAM, contador * sizeof(hospedes));
        
        //copiando os dados do aux para ram para que caso utilizar ma proxima filtragem ou nao
        memcpy(hospedesRAM, hospedesAUX, contador * sizeof(hospedes));
        
        //igualando qtd de hospedes ao contador para ficar com a nova qtd de hospedes
        qtd_hos=contador;
        free(hospedesAUX);
    }
    
    if(opcao==1){
        for (int i = 0; i < qtd_hos; i++) {
            printf("\n------------------------------\n");
            printf("Código: %d\n", hospedesRAM[i].codigo);
            printf("Nome: %s\n", hospedesRAM[i].nome);
            printf("Endereço: %s, %s, %s, %s, %s, %d\n",
                    hospedesRAM[i].endereco_hospede.estado,
                    hospedesRAM[i].endereco_hospede.cidade,
                    hospedesRAM[i].endereco_hospede.cep,
                    hospedesRAM[i].endereco_hospede.bairro,
                    hospedesRAM[i].endereco_hospede.rua,
                    hospedesRAM[i].endereco_hospede.numero);
            printf("CPF: %s\n", hospedesRAM[i].cpf);
            printf("Telefone: %s\n", hospedesRAM[i].telefone);
            printf("Email: %s\n", hospedesRAM[i].email);
            printf("Sexo: %s\n", hospedesRAM[i].sexo);
            printf("Estado Civil: %s\n", hospedesRAM[i].estado_civil);
            printf("Data de Nascimento: %d/%d/%d\n",
                    hospedesRAM[i].data_nacimento.dia,
                    hospedesRAM[i].data_nacimento.mes,
                    hospedesRAM[i].data_nacimento.ano);
            printf("\n");
        }
    }else if(opcao==2){
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("listagem_hospedes.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for(int i=0;i<qtd_hos;i++){
            fprintf(P, "%d;%s;%s;%s;%s;%s;%s;%d;%s;%s;%s;%s;%s;%d;%d;%d;\n",
                    hospedesRAM[i].codigo,
                    hospedesRAM[i].nome,
                    hospedesRAM[i].endereco_hospede.estado,
                    hospedesRAM[i].endereco_hospede.cidade,
                    hospedesRAM[i].endereco_hospede.cep,
                    hospedesRAM[i].endereco_hospede.bairro,
                    hospedesRAM[i].endereco_hospede.rua,
                    hospedesRAM[i].endereco_hospede.numero,
                    hospedesRAM[i].cpf,
                    hospedesRAM[i].telefone,
                    hospedesRAM[i].email,
                    hospedesRAM[i].sexo,
                    hospedesRAM[i].estado_civil,
                    hospedesRAM[i].data_nacimento.dia,
                    hospedesRAM[i].data_nacimento.mes,
                    hospedesRAM[i].data_nacimento.ano);
        }
        

        fclose(P);
        printf("Listagem de hóspede gerada com sucesso.\n");  
    }
    
   
    return 0;
}

//funcao para filtra e printar ou salvar a listagem de acomodacoes
int listagem_acomodacoes_txt(int *codigo, int *listagem,int categoria,int opcao,data_chek_in_out datas){
    int qtd_aco;
    qtd_aco = contadorlinhas_txt("acomodacoes.txt");
    qtd_aco = qtd_aco / 7;
    acomodacoes *acomodacoesRAM = malloc(qtd_aco * sizeof(acomodacoes));
    
    acomodacoes_ram_txt(acomodacoesRAM, qtd_aco);
    
    acomodacoes *acomodacoesAUX;
    
    if (listagem[0] != 0) {
        acomodacoesAUX = malloc(qtd_aco * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_aco; i++) {
            if (codigo[0] <= acomodacoesRAM[i].codigo && acomodacoesRAM[i].codigo <= codigo[1]) {
                acomodacoesAUX[contador] = acomodacoesRAM[i];
                contador++;
            }
        }
        if (contador == 0) {
            printf("\nNenhuma acomodação encontrada para esse intervalo de código.\n");
            return;
        }
        
        // Realocando o acomodacoesRAM para ficar do tamanho da quantidade de acomodações filtradas
        acomodacoesRAM = realloc(acomodacoesRAM, contador * sizeof (acomodacoes));
        
        // Copiando os dados do AUX para RAM
        memcpy(acomodacoesRAM, acomodacoesAUX, contador * sizeof (acomodacoes));
        
        // Igualando a quantidade de acomodações ao contador
        qtd_aco = contador;
        free(acomodacoesAUX);
    }

    if (listagem[1] != 0) {
        acomodacoesAUX = malloc(qtd_aco * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_aco; i++) {
            if (acomodacoesRAM[i].categoria == categoria) {
                acomodacoesAUX[contador] = acomodacoesRAM[i];
                contador++;
            }
        }
        if (contador == 0 && listagem[0]!=0) {
            printf("\nNenhuma acomodação encontrada para essa categoria e intervalo de codigo.\n");
            return;
        }else if(contador==0){
            printf("\nNenhuma acomodação encontrada para essa categoria.\n");
        }
        
        // Realocando o acomodacoesRAM para ficar do tamanho da quantidade de acomodações filtradas
        acomodacoesRAM = realloc(acomodacoesRAM, contador * sizeof (acomodacoes));
        
        // Copiando os dados do AUX para RAM
        memcpy(acomodacoesRAM, acomodacoesAUX, contador * sizeof (acomodacoes));
        
        // Igualando a quantidade de acomodações ao contador
        qtd_aco = contador;
        free(acomodacoesAUX);
    }
    if(listagem[2]!=0){
        int contador=0,qtd_res,existe;
        existe = arquivo_existe_txt("reservas.txt");
        
        
        if(existe==1){
            qtd_res = contadorlinhas_txt("reservas.txt");
            qtd_res = qtd_res / 16;
            reservas reservaRAM[qtd_res];
            reservas_ram_txt(qtd_res, reservaRAM);
            
            int acomodacaoINDIS[qtd_res],contador_indis=0;
            acomodacoesAUX = malloc((qtd_aco+qtd_res) * sizeof (acomodacoes));
       
            if(qtd_res>0){
                for (int i = 0; i < qtd_aco; i++) {
                    if (acomodacoesRAM[i].ocupacao == 0) {
                        acomodacoesAUX[contador]=acomodacoesRAM[i];
                        contador++;
                    }else{
                        for(int j=0;j<qtd_res;j++){
                            if ((datas.ano_in <= reservaRAM[i].datas.ano_out || datas.ano_out >= reservaRAM[i].datas.ano_in) &&
                                    (datas.mes_in <= reservaRAM[i].datas.mes_out || datas.mes_out >= reservaRAM[i].datas.mes_in) &&
                                    (datas.dia_in <= reservaRAM[i].datas.dia_out || datas.dia_out >= reservaRAM[i].datas.dia_in)) {
                                acomodacaoINDIS[contador_indis] = reservaRAM[i].codigo_aco;
                                contador_indis++;
                            }
                        }                            
                    }
                }
                for (int i = 0; i < qtd_aco; i++) {
                    int acomodacaoDisponivel = 1; // Assume que a acomodação está disponível

                    // Verifica se a acomodação está na lista de indisponíveis
                    for (int j = 0; j < contador_indis; j++) {
                        if (acomodacoesRAM[i].codigo == acomodacaoINDIS[j]) {
                            acomodacaoDisponivel = 0; // A acomodação está indisponível
                            break;
                        }
                    }

                    // Adiciona a acomodação à lista de disponíveis
                    if (acomodacaoDisponivel==1 && acomodacoesRAM[i].ocupacao != 0) {
                        acomodacoesAUX[contador] = acomodacoesRAM[i];
                        contador++;
                    }
                }
            }
            if(contador==0){
                printf("\nNenhuma acomodação encontrada com esses filtros.\n");
                return 0;
            }
            // Realocando o acomodacoesRAM para ficar do tamanho da quantidade de acomodações filtradas
            acomodacoesRAM = realloc(acomodacoesRAM, contador * sizeof (acomodacoes));

            // Copiando os dados do AUX para RAM
            memcpy(acomodacoesRAM, acomodacoesAUX, contador * sizeof (acomodacoes));

            // Igualando a quantidade de acomodações ao contador
            qtd_aco = contador;
            free(acomodacoesAUX);
        }
        
    }
    
    if(opcao==1){
        for (int i = 0; i < qtd_aco; i++) {
            printf("\n------------------------------\n");
            printf("Código: %d\n", acomodacoesRAM[i].codigo);
            printf("Descrição: %s\n", acomodacoesRAM[i].descricao);
            printf("Facilidades: %s\n", acomodacoesRAM[i].facilidades);
            printf("Categoria: %d\n", acomodacoesRAM[i].categoria);
            printf("Diárias: %d\n", acomodacoesRAM[i].diarias);
            printf("Lucro: %.2f\n", acomodacoesRAM[i].lucro);
            printf("Ocupação: %d\n", acomodacoesRAM[i].ocupacao);
            printf("\n");
        }
    }else if(opcao==2) {
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("listagem_acomodacoes.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for(int i=0;i<qtd_aco;i++){
            fprintf(P, "%d;%s;%s;%d;%d;%f;%d\n",
                    acomodacoesRAM[i].codigo,
                    acomodacoesRAM[i].descricao,
                    acomodacoesRAM[i].facilidades,
                    acomodacoesRAM[i].categoria,
                    acomodacoesRAM[i].diarias,
                    acomodacoesRAM[i].lucro,
                    acomodacoesRAM[i].ocupacao);
        }
        


        fclose(P);
        printf("Listagem de acomodação gerada com sucesso.\n");
        return  0;
    }
    
}

//funcao para filtra e printar ou salvar a listagem de reservas
int listagem_reservas_txt(int *listagem, int *codigo_hospede, int *codigo_acomodacao, data_chek_in_out datas,int opcao){
    int qtd_res;
    qtd_res = contadorlinhas_txt("reservas.txt");
    qtd_res = qtd_res / 16;
    reservas *reservasRAM = malloc(qtd_res * sizeof (reservas));

    reservas_ram_txt(qtd_res, reservasRAM);

    reservas *reservasAUX;

    if (listagem[0] != 0) {
        reservasAUX = malloc(qtd_res * sizeof (reservas));
        int contador = 0;
        for (int i = 0; i < qtd_res; i++) {
            if (codigo_hospede[0] <= reservasRAM[i].cod_hospede && reservasRAM[i].cod_hospede <= codigo_hospede[1]) {
                reservasAUX[contador] = reservasRAM[i];
                contador++;
            }
        }
        if (contador == 0) {
            printf("\nNenhuma reserva encontrada para esse intervalo de código de hóspede.\n");
            return;
        }

        // Realocando o reservasRAM para ficar do tamanho da quantidade de reservas filtradas
        reservasRAM = realloc(reservasRAM, contador * sizeof (reservas));

        // Copiando os dados do AUX para RAM
        memcpy(reservasRAM, reservasAUX, contador * sizeof (reservas));

        // Igualando a quantidade de reservas ao contador
        qtd_res = contador;
        free(reservasAUX);
    }

    if (listagem[1] != 0) {
        reservasAUX = malloc(qtd_res * sizeof (reservas));
        int contador = 0;
        for (int i = 0; i < qtd_res; i++) {
            if (codigo_acomodacao[0] <= reservasRAM[i].codigo_aco && reservasRAM[i].codigo_aco <= codigo_acomodacao[1]) {
                reservasAUX[contador] = reservasRAM[i];
                contador++;
            }
        }
        if (contador == 0 && listagem[0] != 0) {
            printf("\nNenhuma reserva encontrada para esse intervalo de código de acomodação.\n");
            return;
        } else if (contador == 0) {
            printf("\nNenhuma reserva encontrada para esse intervalo de código de acomodação.\n");
        }

        // Realocando o reservasRAM para ficar do tamanho da quantidade de reservas filtradas
        reservasRAM = realloc(reservasRAM, contador * sizeof (reservas));

        // Copiando os dados do AUX para RAM
        memcpy(reservasRAM, reservasAUX, contador * sizeof (reservas));

        // Igualando a quantidade de reservas ao contador
        qtd_res = contador;
        free(reservasAUX);
    }

    if (listagem[2] != 0) {
        reservasAUX = malloc(qtd_res * sizeof (reservas));
        int contador = 0;
        for (int i = 0; i < qtd_res; i++) {
            if ((datas.ano_in <= reservasRAM[i].datas.ano_in && datas.ano_out >= reservasRAM[i].datas.ano_in) ||
                    (datas.ano_in <= reservasRAM[i].datas.ano_out && datas.ano_out >= reservasRAM[i].datas.ano_out)) {

                if ((datas.mes_in <= reservasRAM[i].datas.mes_in && datas.mes_out >= reservasRAM[i].datas.mes_in) ||
                        (datas.mes_in <= reservasRAM[i].datas.mes_out && datas.mes_out >= reservasRAM[i].datas.mes_out)) {

                    if ((datas.dia_in <= reservasRAM[i].datas.dia_in && datas.dia_out >= reservasRAM[i].datas.dia_in) ||
                            (datas.dia_in <= reservasRAM[i].datas.dia_out && datas.dia_out >= reservasRAM[i].datas.dia_out)) {
                        // A reserva está dentro do intervalo fornecido pelo usuário
                        reservasAUX[contador] = reservasRAM[i];
                        contador++;
                    }
                }
            }
        }
        if (contador == 0 && (listagem[0] != 0 || listagem[1] != 0)) {
            printf("\nNenhuma reserva encontrada para esse intervalo de datas.\n");
            return;
        } else if (contador == 0) {
            printf("\nNenhuma reserva encontrada para esse intervalo de datas.\n");
        }

        // Realocando o reservasRAM para ficar do tamanho da quantidade de reservas filtradas
        reservasRAM = realloc(reservasRAM, contador * sizeof (reservas));

        // Copiando os dados do AUX para RAM
        memcpy(reservasRAM, reservasAUX, contador * sizeof (reservas));

        // Igualando a quantidade de reservas ao contador
        qtd_res = contador;
        free(reservasAUX);
    }

    if (opcao == 1) {
        for (int i = 0; i < qtd_res; i++) {
            printf("\n------------------------------\n");
            printf("Código da Reserva: %d\n", reservasRAM[i].codigo_res);
            printf("Código da Acomodação: %d\n", reservasRAM[i].codigo_aco);
            printf("Descrição: %s\n", reservasRAM[i].descricao);
            printf("Facilidades: %s\n", reservasRAM[i].facilidades);
            printf("Categoria: %d\n", reservasRAM[i].categoria.codigo);
            printf("Data de Check-In: %02d/%02d/%04d\n", reservasRAM[i].datas.dia_in, reservasRAM[i].datas.mes_in, reservasRAM[i].datas.ano_in);
            printf("Data de Check-Out: %02d/%02d/%04d\n", reservasRAM[i].datas.dia_out, reservasRAM[i].datas.mes_out, reservasRAM[i].datas.ano_out);
            printf("Código do Hóspede: %d\n", reservasRAM[i].cod_hospede);
            printf("\n");
        }
    } else if (opcao == 2) {
        FILE *P; // Ponteiro do arquivo TXT;

        P = fopen("listagem_reservas.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for (int i = 0; i < qtd_res; i++) {
            fprintf(P, "%d;%d;%s;%s;%d;%02d;%02d;%04d;%02d;%02d;%04d;%d\n",
                    reservasRAM[i].codigo_res,
                    reservasRAM[i].codigo_aco,
                    reservasRAM[i].descricao,
                    reservasRAM[i].facilidades,
                    reservasRAM[i].categoria.codigo,
                    reservasRAM[i].datas.dia_in, reservasRAM[i].datas.mes_in, reservasRAM[i].datas.ano_in,
                    reservasRAM[i].datas.dia_out, reservasRAM[i].datas.mes_out, reservasRAM[i].datas.ano_out,
                    reservasRAM[i].cod_hospede);
        }

        fclose(P);
        printf("Listagem de reservas gerada com sucesso.\n");
    }
}

//funcao para filtra e printar ou salvar a listagem de acomodacoes
int listagem_movimento_acomodacoes_txt(int *listagem, int *codigo, int diarias, float lucro, int opcao){
    int qtd_aco;
    qtd_aco = contadorlinhas_txt("acomodacoes.txt");
    qtd_aco = qtd_aco / 7;
    acomodacoes *movimentacaoRAM = malloc(qtd_aco * sizeof (acomodacoes));

    acomodacoes_ram_txt(movimentacaoRAM, qtd_aco);

    acomodacoes *movimentacaoAUX;

    if (listagem[0] != 0) {
        movimentacaoAUX = malloc(qtd_aco * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_aco; i++) {
            if (codigo[0] <= movimentacaoRAM[i].codigo && movimentacaoRAM[i].codigo <= codigo[1]) {
                movimentacaoAUX[contador] = movimentacaoRAM[i];
                contador++;
            }
        }
        if (contador == 0) {
            printf("\nNenhuma movimentação de acomodação encontrada para esse intervalo de código.\n");
            return;
        }

        // Realocando o movimentacaoRAM para ficar do tamanho da quantidade de movimentações filtradas
        movimentacaoRAM = realloc(movimentacaoRAM, contador * sizeof (acomodacoes));

        // Copiando os dados do AUX para RAM
        memcpy(movimentacaoRAM, movimentacaoAUX, contador * sizeof (acomodacoes));

        // Igualando a quantidade de movimentações ao contador
        qtd_aco = contador;
        free(movimentacaoAUX);
    }

    if (listagem[1] != 0) {
        movimentacaoAUX = malloc(qtd_aco * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_aco; i++) {
            if (movimentacaoRAM[i].diarias >= diarias) {
                movimentacaoAUX[contador] = movimentacaoRAM[i];
                contador++;
            }
        }
        if (contador == 0 && listagem[0] != 0) {
            printf("\nNenhuma movimentação de acomodação encontrada para essa quantidade de diárias e intervalo de código.\n");
            return;
        } else if (contador == 0) {
            printf("\nNenhuma movimentação de acomodação encontrada para essa quantidade de diárias e rendimento.\n");
        }

        // Realocando o movimentacaoRAM para ficar do tamanho da quantidade de movimentações filtradas
        movimentacaoRAM = realloc(movimentacaoRAM, contador * sizeof (acomodacoes));

        // Copiando os dados do AUX para RAM
        memcpy(movimentacaoRAM, movimentacaoAUX, contador * sizeof (acomodacoes));

        // Igualando a quantidade de movimentações ao contador
        qtd_aco = contador;
        free(movimentacaoAUX);
    }
    if (listagem[2] != 0) {
        movimentacaoAUX = malloc(qtd_aco * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_aco; i++) {
            if (movimentacaoRAM[i].lucro >= lucro) {
                movimentacaoAUX[contador] = movimentacaoRAM[i];
                contador++;
            }
        }
        if (contador == 0) {
            printf("\nNenhuma acomodação encontrada com esses filtros.\n");
        }

        // Realocando o movimentacaoRAM para ficar do tamanho da quantidade de movimentações filtradas
        movimentacaoRAM = realloc(movimentacaoRAM, contador * sizeof (acomodacoes));

        // Copiando os dados do AUX para RAM
        memcpy(movimentacaoRAM, movimentacaoAUX, contador * sizeof (acomodacoes));

        // Igualando a quantidade de movimentações ao contador
        qtd_aco = contador;
        free(movimentacaoAUX);
    }

    if (opcao == 1) {
        for (int i = 0; i < qtd_aco; i++) {
            printf("\n------------------------------\n");
            printf("Código: %d\n", movimentacaoRAM[i].codigo);
            printf("Descrição: %s\n", movimentacaoRAM[i].descricao);
            printf("Facilidades: %s\n", movimentacaoRAM[i].facilidades);
            printf("Categoria: %d\n", movimentacaoRAM[i].categoria);
            printf("Diárias: %d\n", movimentacaoRAM[i].diarias);
            printf("Lucro: %.2f\n", movimentacaoRAM[i].lucro);
            printf("Ocupação: %d\n", movimentacaoRAM[i].ocupacao);
            printf("\n");
        }
    } else if (opcao == 2) {
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("listagem_movimentacao_acomodacoes.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for (int i = 0; i < qtd_aco; i++) {
            fprintf(P, "%d;%s;%s;%d;%d;%f;%d\n",
                    movimentacaoRAM[i].codigo,
                    movimentacaoRAM[i].descricao,
                    movimentacaoRAM[i].facilidades,
                    movimentacaoRAM[i].categoria,
                    movimentacaoRAM[i].diarias,
                    movimentacaoRAM[i].lucro,
                    movimentacaoRAM[i].ocupacao);
        }



        fclose(P);
        printf("Listagem de movimentação de acomodação gerada com sucesso.\n");
    }  
}

//funcao para filtra e printar ou salvar a listagem de produtos
int listagem_produtos_txt(int *codigo, int listagem,int opcao){
    int qtd_prod,contador = 0;
    qtd_prod = contadorlinhas_txt("produtos.txt");
    qtd_prod = qtd_prod / 6;
    produtos *produtosRAM = malloc(qtd_prod * sizeof (produtos));

    produtos_ram_txt(produtosRAM, qtd_prod);

    produtos *produtosAUX;

    if (listagem != 0) {
        produtosAUX = malloc(qtd_prod * sizeof (produtos));
        for (int i = 0; i < qtd_prod; i++) {
            if (codigo[0] <= produtosRAM[i].codigo && produtosRAM[i].codigo <= codigo[1]) {
                produtosAUX[contador] = produtosRAM[i];
                contador++;
            }
        }
        if (contador == 0) {
            printf("\nNenhum produto encontrado para esse intervalo de código.\n");
            free(produtosRAM);
            return 0;
        }

        // Realocando o produtosRAM para ficar do tamanho da quantidade de produtos filtrados
        produtosRAM = realloc(produtosRAM, contador * sizeof (produtos));

        // Copiando os dados do AUX para RAM
        memcpy(produtosRAM, produtosAUX, contador * sizeof (produtos));

        // Igualando a quantidade de produtos ao contador
        qtd_prod = contador;
        free(produtosAUX);
    }

    if (opcao == 1) {
        for (int i = 0; i < qtd_prod; i++) {
            printf("\n------------------------------\n");
            printf("Código: %d\n", produtosRAM[i].codigo);
            printf("Descrição: %s\n", produtosRAM[i].descricao);
            printf("Estoque: %d\n", produtosRAM[i].estoque);
            printf("Estoque Mínimo: %d\n", produtosRAM[i].estoque_min);
            printf("Preço de Custo: %.2f\n", produtosRAM[i].preco_custo);
            printf("Preço de Venda: %.2f\n", produtosRAM[i].preco_venda);
            printf("\n");
        }
    } else if (opcao == 2) {
        FILE *P; // Ponteiro do arquivo TXT;

        P = fopen("listagem_produtos.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }

        for (int i = 0; i < qtd_prod; i++) {
            fprintf(P, "%d;%s;%d;%d;%f;%f;\n",
                    produtosRAM[i].codigo,
                    produtosRAM[i].descricao,
                    produtosRAM[i].estoque,
                    produtosRAM[i].estoque_min,
                    produtosRAM[i].preco_custo,
                    produtosRAM[i].preco_venda);
        }
        fclose(P);
        printf("Listagem de produtos gerada com sucesso.\n");
        free(produtosRAM);
        return 0;
    }

    free(produtosRAM);
    return 0;
}

//funcao para filtra e printar ou salvar a listagem de produtos em estoque minimo
int listagem_estoque_minimo_txt(int *codigo,int listagem,int opcao) {
    int qtd_prod,contador = 0;
    qtd_prod = contadorlinhas_txt("produtos.txt");
    qtd_prod = qtd_prod / 6;
    produtos *produtosRAM = malloc(qtd_prod * sizeof (produtos));

    produtos_ram_txt(produtosRAM, qtd_prod);

    produtos *produtosAUX;
    
    if (listagem != 0) {
        produtosAUX = malloc(qtd_prod * sizeof (produtos));
        
        for (int i = 0; i < qtd_prod; i++) {
            if (codigo[0] <= produtosRAM[i].codigo && produtosRAM[i].codigo <= codigo[1] && produtosRAM[i].estoque <= produtosRAM[i].estoque_min) {
                produtosAUX[contador] = produtosRAM[i];
                contador++;
            }
        }
        if (contador == 0) {
            printf("\nNenhum produto encontrado para este intervalo de código e estoque mínimo.\n");
            return 0;
        }

        // Realocando o produtosRAM para ficar do tamanho da quantidade de produtos filtrados
        produtosRAM = realloc(produtosRAM, contador * sizeof (produtos));

        // Copiando os dados do AUX para RAM
        memcpy(produtosRAM, produtosAUX, contador * sizeof (produtos));

        // Igualando a quantidade de produtos ao contador
        qtd_prod = contador;
        free(produtosAUX);
    }
    contador=0;
    if (opcao == 1) {
        for (int i = 0; i < qtd_prod; i++) {
            if(produtosRAM[i].estoque <= produtosRAM[i].estoque_min){
                printf("\n------------------------------\n");
                printf("Código: %d\n", produtosRAM[i].codigo);
                printf("Descrição: %s\n", produtosRAM[i].descricao);
                printf("Estoque: %d\n", produtosRAM[i].estoque);
                printf("Estoque Mínimo: %d\n", produtosRAM[i].estoque_min);
                printf("Preço de Custo: %.2f\n", produtosRAM[i].preco_custo);
                printf("Preço de Venda: %.2f\n", produtosRAM[i].preco_venda);
                printf("\n");
                contador++;
            }
            
        }
        if(contador==0){
            printf("Nenhum produto em estoque minimo.\n");
            return 0;
        }
    } else if (opcao == 2) {
        contador=0;
        for (int i = 0; i < qtd_prod; i++) {
            if(produtosRAM[i].estoque <= produtosRAM[i].estoque_min){
                contador++;
            }
        }
        if(contador==0){
            printf("Nenhum produto em estoque minimo.\n");
            return 0;
        }
        FILE *P; //Ponteiro do arquivo TXT;
        P = fopen("listagem_produtos_estoque_minimo.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for (int i = 0; i < qtd_prod; i++) {
            if (produtosRAM[i].estoque <= produtosRAM[i].estoque_min) {
                fprintf(P, "%d;%s;%d;%d;%.2f;%.2f;\n",
                        produtosRAM[i].codigo,
                        produtosRAM[i].descricao,
                        produtosRAM[i].estoque,
                        produtosRAM[i].estoque_min,
                        produtosRAM[i].preco_custo,
                        produtosRAM[i].preco_venda);
            }
            
        }
        fclose(P);
        printf("Listagem de produtos em estoque mínimo gerada com sucesso.\n");
        return 0;
    }
}

//funcao para filtra e printar ou salvar a listagem de vendas
int listagem_vendas_txt(int pagamento, int opcao,int listagem) {
    int qtd_vendas;
    int contador = 0;
    qtd_vendas = contadorlinhas_txt("vendas.txt");
    vendas *vendasRAM = malloc(qtd_vendas * sizeof (vendas));

    ram_venda_txt(vendasRAM, qtd_vendas);
  
    vendas *vendasAUX;

    if (listagem == 1) {
        if(pagamento == 1){
           vendasAUX = malloc(qtd_vendas * sizeof (vendas));
            for (int i = 0; i < qtd_vendas; i++) {
                if (vendasRAM[i].pagamento == 1) {
                    vendasAUX[contador] = vendasRAM[i];
                    contador++;
                }
            }

            if (contador == 0) {
                printf("\nNenhuma venda encontrada com pagamento a vista.\n");
                free(vendasAUX);
                return 0;
            }

            // Realocando o vendasRAM para ficar do tamanho da quantidade de vendas filtradas
            vendasRAM = realloc(vendasRAM, contador * sizeof (vendas));

            // Copiando os dados do AUX para RAM
            memcpy(vendasRAM, vendasAUX, contador * sizeof (vendas));

            // Igualando a quantidade de vendas ao contador
            qtd_vendas = contador;
            free(vendasAUX); 
        } else if (pagamento == 2) {

            vendasAUX = malloc(qtd_vendas * sizeof (vendas));
            for (int i = 0; i < qtd_vendas; i++) {
                if (vendasRAM[i].pagamento == 2) {
                    vendasAUX[contador] = vendasRAM[i];
                    contador++;
                }
            }

            if (contador == 0) {
                printf("\nNenhuma venda encontrada com pagamento a prazo.\n");
                free(vendasAUX);
                return 0;
            }

            // Realocando o vendasRAM para ficar do tamanho da quantidade de vendas filtradas
            vendasRAM = realloc(vendasRAM, contador * sizeof (vendas));

            // Copiando os dados do AUX para RAM
            memcpy(vendasRAM, vendasAUX, contador * sizeof (vendas));

            // Igualando a quantidade de vendas ao contador
            qtd_vendas = contador;
            free(vendasAUX);
        }
    } 

    if (opcao == 1) {
        for (int i = 0; i < qtd_vendas; i++) {
            printf("\n------------------------------\n");
            printf("Código do Hóspede: %d\n", vendasRAM[i].cod_hos);
            printf("Código do Produto: %d\n", vendasRAM[i].cod_prod);
            printf("Quantidade: %d\n", vendasRAM[i].qtd);
            printf("Valor: %.2f\n", vendasRAM[i].valor);
            printf("Método de Pagamento: %s\n", (vendasRAM[i].pagamento == 1) ? "Dinheiro" : "Anotar");
            printf("\n");
        }
    } else if (opcao == 2) {
        FILE *P; // Ponteiro do arquivo TXT;
        P = fopen("listagem_vendas.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }

        for (int i = 0; i < qtd_vendas; i++) {
            fprintf(P, "%d;%d;%d;%d;%f;\n",
                    vendasRAM[i].pagamento,
                    vendasRAM[i].cod_hos,
                    vendasRAM[i].cod_prod,
                    vendasRAM[i].qtd,
                    vendasRAM[i].valor);
        }

        fclose(P);
        printf("Listagem de vendas gerada com sucesso.\n");
        return 0;
    }
}

// funcao para ajudar na filtragem verificando se a data esta entre o intervalo
int data_entre(data d1, data d2) {
    if (d1.ano < d2.ano)
        return -1;
    if (d1.ano > d2.ano)
        return 1;
    if (d1.mes < d2.mes)
        return -1;
    if (d1.mes > d2.mes)
        return 1;
    if (d1.dia < d2.dia)
        return -1;
    if (d1.dia > d2.dia)
        return 1;
    return 0; // Datas são iguais
}

//funcao para filtra e printar ou salvar a listagem de contas a receber
int listagem_contas_receber_txt(int *listagem, int *codigo, data inicio, data fim, int opcao){
    int qtd_contas;
    int contador = 0;

    
    qtd_contas = contadorlinhas_txt("contas_receber.txt");
    qtd_contas = qtd_contas / 5;
    conta_receber *contasRAM = malloc(qtd_contas * sizeof (conta_receber));

    contas_receber_ram_txt(contasRAM, qtd_contas);

    conta_receber *contasAUX = NULL;

    // Aplicando o filtro por código
    if (listagem[0] == 1) {
        contasAUX = malloc(qtd_contas * sizeof (conta_receber));
        for (int i = 0; i < qtd_contas; i++) {
            if (codigo[0] <= contasRAM[i].codigo_hos && contasRAM[i].codigo_hos <= codigo[1]) {
                contasAUX[contador] = contasRAM[i];
                contador++;
            }
        }

        if (contador == 0) {
            printf("\nNenhuma conta a receber encontrada para esse intervalo de código.\n");
            free(contasAUX);
            return;
        }

        // Realocando o contasRAM para ficar do tamanho da quantidade de contas filtradas
        contasRAM = realloc(contasRAM, contador * sizeof (conta_receber));

        // Copiando os dados do AUX para RAM
        memcpy(contasRAM, contasAUX, contador * sizeof (conta_receber));

        // Igualando a quantidade de contas ao contador
        qtd_contas = contador;
        free(contasAUX);
    }

    // Aplicando o filtro por data de recebimento
    if (listagem[1] == 1) {
        contasAUX = malloc(qtd_contas * sizeof (conta_receber));
        for (int i = 0; i < qtd_contas; i++) {
            if (data_entre(inicio, contasRAM[i].date) <= 0 &&
                    data_entre(contasRAM[i].date, fim) <= 0) {
                contasAUX[contador] = contasRAM[i];
                contador++;
            }
        }

        if (contador == 0) {
            printf("\nNenhuma conta a receber encontrada para esse intervalo de data.\n");
            free(contasAUX);
            return;
        }

        // Realocando o contasRAM para ficar do tamanho da quantidade de contas filtradas
        contasRAM = realloc(contasRAM, contador * sizeof (conta_receber));

        // Copiando os dados do AUX para RAM
        memcpy(contasRAM, contasAUX, contador * sizeof (conta_receber));

        // Igualando a quantidade de contas ao contador
        qtd_contas = contador;
        free(contasAUX);
    }

    // Imprimindo ou salvando conforme a opção
    if (opcao == 1) {
        for (int i = 0; i < qtd_contas; i++) {
            printf("\n------------------------------\n");
            printf("Código do Hóspede: %d\n", contasRAM[i].codigo_hos);
            printf("Valor Devido: %.2f\n", contasRAM[i].valor_devido);
            printf("Data de Recebimento: %02d/%02d/%04d\n", contasRAM[i].date.dia, contasRAM[i].date.mes, contasRAM[i].date.ano);
            printf("\n");
        }
    } else if (opcao == 2) {
        FILE *P; // Ponteiro do arquivo TXT;
        P = fopen("listagem_contas_receber.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }

        for (int i = 0; i < qtd_contas; i++) {
            fprintf(P, "%d;%f;%02d;%02d;%04d;\n",
                    contasRAM[i].codigo_hos,
                    contasRAM[i].valor_devido,
                    contasRAM[i].date.dia,
                    contasRAM[i].date.mes,
                    contasRAM[i].date.ano);
        }

        fclose(P);
        printf("Listagem de contas a receber gerada com sucesso.\n");
    }
    return 0;
}

//funcao para filtra e printar ou salvar a listagem de contas a pagar
int listagem_contas_pagar_txt(int *listagem, int *codigo, data inicio, data fim, int opcao){
    int qtd_contas;
    int contador = 0;

    
    qtd_contas = contadorlinhas_txt("contas_pagar.txt");
    qtd_contas = qtd_contas / 5;
    conta_receber *contasRAM = malloc(qtd_contas * sizeof (conta_receber));

    contas_pagar_ram_txt(contasRAM, qtd_contas);

    conta_receber *contasAUX = NULL;

    // Aplicando o filtro por código
    if (listagem[0] == 1) {
        contasAUX = malloc(qtd_contas * sizeof (conta_receber));
        for (int i = 0; i < qtd_contas; i++) {
            if (codigo[0] <= contasRAM[i].codigo_hos && contasRAM[i].codigo_hos <= codigo[1]) {
                contasAUX[contador] = contasRAM[i];
                contador++;
            }
        }

        if (contador == 0) {
            printf("\nNenhuma conta a pagar encontrada para esse intervalo de código.\n");
            free(contasAUX);
            return;
        }

        // Realocando o contasRAM para ficar do tamanho da quantidade de contas filtradas
        contasRAM = realloc(contasRAM, contador * sizeof (conta_receber));

        // Copiando os dados do AUX para RAM
        memcpy(contasRAM, contasAUX, contador * sizeof (conta_receber));

        // Igualando a quantidade de contas ao contador
        qtd_contas = contador;
        free(contasAUX);
    }

    // Aplicando o filtro por data de recebimento
    if (listagem[1] == 1) {
        contasAUX = malloc(qtd_contas * sizeof (conta_receber));
        for (int i = 0; i < qtd_contas; i++) {
            if (data_entre(inicio, contasRAM[i].date) <= 0 &&
                    data_entre(contasRAM[i].date, fim) <= 0) {
                contasAUX[contador] = contasRAM[i];
                contador++;
            }
        }

        if (contador == 0) {
            printf("\nNenhuma conta a pagar encontrada para esse intervalo de data.\n");
            free(contasAUX);
            return;
        }

        // Realocando o contasRAM para ficar do tamanho da quantidade de contas filtradas
        contasRAM = realloc(contasRAM, contador * sizeof (conta_receber));

        // Copiando os dados do AUX para RAM
        memcpy(contasRAM, contasAUX, contador * sizeof (conta_receber));

        // Igualando a quantidade de contas ao contador
        qtd_contas = contador;
        free(contasAUX);
    }

    // Imprimindo ou salvando conforme a opção
    if (opcao == 1) {
        for (int i = 0; i < qtd_contas; i++) {
            printf("\n------------------------------\n");
            printf("Código do fornecedor: %d\n", contasRAM[i].codigo_hos);
            printf("Valor Devido: %.2f\n", contasRAM[i].valor_devido);
            printf("Data de Recebimento: %02d/%02d/%04d\n", contasRAM[i].date.dia, contasRAM[i].date.mes, contasRAM[i].date.ano);
            printf("\n");
        }
    } else if (opcao == 2) {
        FILE *P; // Ponteiro do arquivo TXT;
        P = fopen("listagem_contas_pagar.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }

        for (int i = 0; i < qtd_contas; i++) {
            fprintf(P, "%d;%f;%02d;%02d;%04d;\n",
                    contasRAM[i].codigo_hos,
                    contasRAM[i].valor_devido,
                    contasRAM[i].date.dia,
                    contasRAM[i].date.mes,
                    contasRAM[i].date.ano);
        }

        fclose(P);
        printf("Listagem de contas a pagar gerada com sucesso.\n");
    }
    return 0;
}

//funcao para filtra e printar ou salvar a listagem de caixa
void listagem_caixa_txt(data inicio, data fim,int listagem,int opcao) {
    int qtd_caixa;
    int contador = 0;

    qtd_caixa = contadorlinhas_txt("caixa.txt");
    qtd_caixa = qtd_caixa / 5; 
    conta_receber *caixaRAM = malloc(qtd_caixa * sizeof (conta_receber));

    caixa_ram_txt(caixaRAM, qtd_caixa); 

    conta_receber *caixaAUX = NULL;

    if(listagem==1){
        caixaAUX = malloc(qtd_caixa * sizeof (conta_receber));
        for (int i = 0; i < qtd_caixa; i++) {
            if (data_entre(inicio, caixaRAM[i].date) <= 0 &&
                    data_entre(caixaRAM[i].date, fim) <= 0) {
                caixaAUX[contador] = caixaRAM[i];
                contador++;
            }
        }

        if (contador == 0) {
            printf("\nNenhuma entrada no caixa encontrada para esse intervalo de data.\n");
            free(caixaAUX);
            return;
        }

        // Realocando o caixaRAM para ficar do tamanho da quantidade de entradas filtradas
        caixaRAM = realloc(caixaRAM, contador * sizeof (conta_receber));

        // Copiando os dados do AUX para RAM
        memcpy(caixaRAM, caixaAUX, contador * sizeof (conta_receber));

        // Igualando a quantidade de entradas ao contador
        qtd_caixa = contador;
        free(caixaAUX);
    }
    
    if(opcao==1){
        // Imprimindo as informações
        for (int i = 0; i < qtd_caixa; i++) {
            printf("\n------------------------------\n");
            printf("Código:%d\n",caixaRAM[i].codigo_hos);
            printf("Valor: %.2f\n", caixaRAM[i].valor_devido);
            printf("Data de Recebimento: %02d/%02d/%04d\n", caixaRAM[i].date.dia, caixaRAM[i].date.mes, caixaRAM[i].date.ano);
            printf("\n");
        }    
    }else if(opcao==2){
        FILE *P;
        P = fopen("listagem_caixa.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }

        for (int i = 0; i < qtd_caixa; i++) {
            fprintf(P, "%f;%02d;%02d;%04d;\n",
                    caixaRAM[i].valor_devido,
                    caixaRAM[i].date.dia,
                    caixaRAM[i].date.mes,
                    caixaRAM[i].date.ano);
        }

        fclose(P);
        printf("Listagem de caixa gerada com sucesso.\n");
    }
}




//exportar dados em xml
int exportar_dados_xml(int *exportar){
    
    FILE *arquivoXML; //Ponteiro do arquivo TXT;
    arquivoXML = fopen("exportar.xml", "w");
    
    
    fprintf(arquivoXML, "<dados>\n");
    
    
    if(exportar[0]!=0){
        cad_hotel hotelRAM[1];
        hotel_ram_txt(hotelRAM);
        fprintf(arquivoXML, "    <tabela=hotel>\n");
        fprintf(arquivoXML, "        <registro>\n");
        fprintf(arquivoXML, "            <nome_fantasia>%s</nome_fantasia>\n", hotelRAM[0].nome_fantasia);
        fprintf(arquivoXML, "            <razao_social>%s</razao_social>\n", hotelRAM[0].razao_social);
        fprintf(arquivoXML, "            <inscricao_estadual>%s</inscricao_estadual>\n", hotelRAM[0].inscricao_estadual);
        fprintf(arquivoXML, "            <cnpj>%s</cnpj>\n", hotelRAM[0].cnpj);
        fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", hotelRAM[0].endereco.estado,hotelRAM[0].endereco.cidade,hotelRAM[0].endereco.bairro,hotelRAM[0].endereco.cep,hotelRAM[0].endereco.rua,hotelRAM[0].endereco.numero);
        fprintf(arquivoXML, "            <telefone>%s</telefone>\n", hotelRAM[0].telefone);
        fprintf(arquivoXML, "            <email>%s</email>\n", hotelRAM[0].email);
        fprintf(arquivoXML, "            <nome_responsavel>%s</nome_responsavel>\n", hotelRAM[0].nome_responsavel);
        fprintf(arquivoXML, "            <telefone_responsavel>%s</telefone_responsavel>\n", hotelRAM[0].telefone_responsavel);
        fprintf(arquivoXML, "            <checkin>%d:%d</checkin>\n", hotelRAM[0].horario_checkin.hora,hotelRAM[0].horario_checkin.minutos);
        fprintf(arquivoXML, "            <checkout>%d:%d</checkout>\n", hotelRAM[0].horario_checkout.hora,hotelRAM[0].horario_checkout.minutos);
        fprintf(arquivoXML, "            <mlpv>%f</mlpv>\n", hotelRAM[0].mlpv);
        fprintf(arquivoXML, "        </registro>\n");
        fprintf(arquivoXML, "    </tabela=hotel>\n");
    }
    
    if(exportar[1]!=0){
        int qtd_hos;
        qtd_hos = contadorlinhas_txt("hospedes.txt");
        qtd_hos = qtd_hos / 16;
        hospedes hospedesRAM[qtd_hos];
        hospedes_ram_txt(hospedesRAM, qtd_hos);
        
        fprintf(arquivoXML, "    <tabela=hospedes>\n");
        for (int i = 0; i < qtd_hos; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", hospedesRAM[i].codigo);
            fprintf(arquivoXML, "            <nome>%s</nome>\n", hospedesRAM[i].nome);
            fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", hospedesRAM[i].endereco_hospede.estado,hospedesRAM[i].endereco_hospede.cidade,hospedesRAM[i].endereco_hospede.bairro,hospedesRAM[i].endereco_hospede.cep,hospedesRAM[i].endereco_hospede.rua,hospedesRAM[i].endereco_hospede.numero);
            fprintf(arquivoXML, "            <cpf>%s</cpf>\n", hospedesRAM[i].cpf);
            fprintf(arquivoXML, "            <telefone>%s</telefone>\n", hospedesRAM[i].telefone);
            fprintf(arquivoXML, "            <email>%s</email>\n", hospedesRAM[i].email);
            fprintf(arquivoXML, "            <sexo>%s</sexo>\n", hospedesRAM[i].sexo);
            fprintf(arquivoXML, "            <est_civil>%s</est_civil>\n", hospedesRAM[i].estado_civil);
            fprintf(arquivoXML, "            <data_nascimento>%d/%d/%d</data_nascimento>\n", hospedesRAM[i].data_nacimento.dia,hospedesRAM[i].data_nacimento.mes,hospedesRAM[i].data_nacimento.ano);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=hospedes>\n");
    }
    if(exportar[2]!=0){
        int qtd_aco;
        qtd_aco = contadorlinhas_txt("acomodacoes.txt");
        qtd_aco = qtd_aco / 5;
        acomodacoes acomodacoesRAM[qtd_aco];
        acomodacoes_ram_txt(acomodacoesRAM, qtd_aco);
        fprintf(arquivoXML, "    <tabela=acomodacoes>\n");
        for (int i = 0; i < qtd_aco; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", acomodacoesRAM[i].codigo);
            fprintf(arquivoXML, "            <descricao>%s</descricao>\n", acomodacoesRAM[i].descricao);
            fprintf(arquivoXML, "            <facilidades>%s</facilidades>\n", acomodacoesRAM[i].facilidades);
            fprintf(arquivoXML, "            <categoria>%d</categoria>\n", acomodacoesRAM[i].categoria);
            fprintf(arquivoXML, "            <diarias>%d</diarias>\n", acomodacoesRAM[i].diarias);
            fprintf(arquivoXML, "            <lucro>%f</lucro>\n", acomodacoesRAM[i].lucro);
            fprintf(arquivoXML, "            <ocupacao>%d</ocupacao>\n", acomodacoesRAM[i].ocupacao); 
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=acomodacoes>\n");
    }
    
    if(exportar[3]!=0){
        int qtd_cat;
        qtd_cat = contadorlinhas_txt("categorias.txt");
        qtd_cat = qtd_cat / 5;
        categoria_acomodacao categoriasRAM[qtd_cat];
        categorias_ram_txt(categoriasRAM, qtd_cat);
        fprintf(arquivoXML, "    <tabela=categoria_acomodacao>\n");

        for (int i = 0; i < qtd_cat; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", categoriasRAM[i].codigo);
            fprintf(arquivoXML, "            <descricao>%s</descricao>\n", categoriasRAM[i].descricao);
            fprintf(arquivoXML, "            <valor_diaria>%f</valor_diaria>\n", categoriasRAM[i].valor_diaria);
            fprintf(arquivoXML, "            <adultos>%d</adultos>\n", categoriasRAM[i].adultos);
            fprintf(arquivoXML, "            <criancas>%d</criancas>\n", categoriasRAM[i].criancas);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=categoria_acomodacao>\n");
    }
    
    
    if(exportar[4]!=0){
        int qtd_prod;
        qtd_prod = contadorlinhas_txt("produtos.txt");
        qtd_prod = qtd_prod / 6;
        produtos produtosRAM[qtd_prod];
        produtos_ram_txt(produtosRAM, qtd_prod);
        
        fprintf(arquivoXML, "    <tabela=produtos>\n");

        for (int i = 0; i < qtd_prod; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", produtosRAM[i].codigo);
            fprintf(arquivoXML, "            <descricao>%s</descricao>\n", produtosRAM[i].descricao);
            fprintf(arquivoXML, "            <estoque>%d</estoque>\n", produtosRAM[i].estoque);
            fprintf(arquivoXML, "            <estoque_min>%d</estoque_min>\n", produtosRAM[i].estoque_min);
            fprintf(arquivoXML, "            <preco_custo>%f</preco_custo>\n", produtosRAM[i].preco_custo);
            fprintf(arquivoXML, "            <preco_venda>%f</preco_venda>\n", produtosRAM[i].preco_venda);
            fprintf(arquivoXML, "        </registro>\n");
        }

        fprintf(arquivoXML, "    </tabela=produtos>\n");
    }
    if(exportar[5]!=0){
        int qtd_for;
        qtd_for = contadorlinhas_txt("fornecedores.txt");
        qtd_for = qtd_for / 13;
        fornecedores fornecedoresRAM[qtd_for];
        fornecedores_ram_txt(fornecedoresRAM, qtd_for);
        
        fprintf(arquivoXML, "    <tabela=fornecedores>\n");

        for (int i = 0; i < qtd_for; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", fornecedoresRAM[i].codigo);
            fprintf(arquivoXML, "            <nome_fantasia>%s</nome_fantasia>\n", fornecedoresRAM[i].nome_fantasia);
            fprintf(arquivoXML, "            <razao_social>%s</razao_social>\n", fornecedoresRAM[i].razao_social);
            fprintf(arquivoXML, "            <inscricao_estadual>%s</inscricao_estadual>\n", fornecedoresRAM[i].inscricao_estadual);
            fprintf(arquivoXML, "            <cnpj>%s</cnpj>\n", fornecedoresRAM[i].cnpj);
            fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", fornecedoresRAM[i].endereco.estado,fornecedoresRAM[i].endereco.cidade,fornecedoresRAM[i].endereco.bairro,fornecedoresRAM[i].endereco.cep,fornecedoresRAM[i].endereco.rua,fornecedoresRAM[i].endereco.numero);
            fprintf(arquivoXML, "            <telefone>%s</telefone>\n", fornecedoresRAM[i].telefone);
            fprintf(arquivoXML, "            <email>%s</email>\n", fornecedoresRAM[i].email);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=fornecedores>\n");
    }
    if(exportar[6]!=0){
        int qtd_ope;
        qtd_ope = contadorlinhas_txt("operadores.txt");
        qtd_ope = qtd_ope / 9;
        OPsistema operadoresRAM[qtd_ope];
        operadores_ram_txt(qtd_ope, operadoresRAM);
        
        fprintf(arquivoXML, "    <tabela=operadores>\n");

        for (int i = 0; i < qtd_ope; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", operadoresRAM[i].codigo);
            fprintf(arquivoXML, "            <nome>%s</nome>\n", operadoresRAM[i].nome);
            fprintf(arquivoXML, "            <usuario>%s</usuario>\n", operadoresRAM[i].usuario);
            fprintf(arquivoXML, "            <senha>%d</senha>\n", operadoresRAM[i].senha);
            fprintf(arquivoXML, "            <permissoes>%d;%d;%d;%d;%d</permissoes>\n",operadoresRAM[i].permissoes.cadastros,operadoresRAM[i].permissoes.reservas,operadoresRAM[i].permissoes.transacoes,operadoresRAM[i].permissoes.feedback,operadoresRAM[i].permissoes.im_exportacao);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=operadores>\n");

    }
    fprintf(arquivoXML, "</dados>\n");
    
   
    fclose(arquivoXML);
    printf("Dados exportados com sucesso.\n");
    return 0;  
}

//traz o arquivo que ser importado para o buffer
char* trazer_xml_buffer(char *importar){
    FILE *arquivo;
    char *buffer;
    long tamanho_arquivo;


    // Abre o arquivo em modo de leitura
    arquivo = fopen(importar, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Obtém o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    tamanho_arquivo = ftell(arquivo);
    rewind(arquivo);

    // Aloca memória para o buffer
    buffer = (char *) malloc(tamanho_arquivo * sizeof (char));
    if (buffer == NULL) {
        perror("Erro de alocação de memória");
        fclose(arquivo);
        return 1;
    }

    // Lê o conteúdo do arquivo para o buffer
    fread(buffer, 1, tamanho_arquivo, arquivo);

    // Fecha o arquivo, pois já temos o conteúdo no buffer
    fclose(arquivo);
    return buffer;
}

// Função para extrair o valor entre as tags
void extrairValor(const char *buffer, const char *tag_inicio, const char *tag_fim, char *resultado) {
    const char *inicio = strstr(buffer, tag_inicio);
    if (inicio != NULL) {
        inicio += strlen(tag_inicio);
        const char *fim = strstr(inicio, tag_fim);
        if (fim != NULL) {
            size_t tamanho = fim - inicio;
            strncpy(resultado, inicio, tamanho);
            resultado[tamanho] = '\0'; // Adiciona o caractere nulo ao final
        }
    }
}

//funcao para importar dados do hotel de um xml
int importar_dados_hotel_xml(char *arquivo) {
    char *buffer=trazer_xml_buffer(arquivo);

    // Estrutura para armazenar os dados do hotel
    cad_hotel dados_hotel;
    // Estrutura para armazenar os dados do endereço
    
    
    char auxEndereco[500];
    char auxMLPV[20];
    char auxCheckin[10];
    char auxCheckout[10];
    
    
    const char *inicio_tag = "<tabela=hotel>";
    const char *fim_tag = "</tabela=hotel>";

    // Encontra as posições das tags de início e fim
    const char *inicio = strstr(buffer, inicio_tag);
    const char *fim = strstr(buffer, fim_tag);
    char *conteudo_hotel = NULL;
    
    // Verifica se as tags foram encontradas
    if (inicio != NULL && fim != NULL) {
        // Calcula o tamanho do conteúdo
        size_t tamanho_conteudo = fim - (inicio + strlen(inicio_tag));

        // Aloca memória para armazenar o conteúdo
        conteudo_hotel = (char *) malloc((tamanho_conteudo + 1) * sizeof (char));

        // Copia o conteúdo entre as tags
        strncpy(conteudo_hotel, inicio + strlen(inicio_tag), tamanho_conteudo);
        conteudo_hotel[tamanho_conteudo] = '\0'; // Adiciona o caractere nulo ao final

        // Imprime o conteúdo extraído
        //printf("Conteúdo entre <tabela=hotel> e </tabela=hotel>:\n%s\n", conteudo_hotel);

    
    } else {
        printf("Tags não encontradas ou conteúdo vazio.\n");
    }

    
    // Extrai cada valor entre as tags
    extrairValor(buffer, "<nome_fantasia>", "</nome_fantasia>", dados_hotel.nome_fantasia);
    extrairValor(buffer, "<razao_social>", "</razao_social>", dados_hotel.razao_social);
    extrairValor(buffer, "<inscricao_estadual>", "</inscricao_estadual>", dados_hotel.inscricao_estadual);
    extrairValor(buffer, "<cnpj>", "</cnpj>", dados_hotel.cnpj);
    
    
    extrairValor(buffer, "<endereco>", "</endereco>", auxEndereco);
    sscanf(auxEndereco, "%[^;];%[^;];%[^;];%[^;];%[^;];%d", dados_hotel.endereco.estado,
            dados_hotel.endereco.cidade, dados_hotel.endereco.bairro,
            dados_hotel.endereco.cep, dados_hotel.endereco.rua,
            &dados_hotel.endereco.numero);
    
    extrairValor(buffer, "<telefone>", "</telefone>", dados_hotel.telefone);
    extrairValor(buffer, "<email>", "</email>", dados_hotel.email);
    extrairValor(buffer, "<nome_responsavel>", "</nome_responsavel>", dados_hotel.nome_responsavel);
    extrairValor(buffer, "<telefone_responsavel>", "</telefone_responsavel>", dados_hotel.telefone_responsavel);
    
    
    // Extrai os valores de checkin e checkout
    extrairValor(buffer, "<checkin>", "</checkin>", auxCheckin);
    sscanf(auxCheckin, "%d:%d", &dados_hotel.horario_checkin.hora, &dados_hotel.horario_checkin.minutos);
    extrairValor(buffer, "<checkout>", "</checkout>", auxCheckout);
    sscanf(auxCheckin, "%d:%d", &dados_hotel.horario_checkout.hora, &dados_hotel.horario_checkout.minutos);
    
    
    extrairValor(buffer, "<mlpv>", "</mlpv>", auxMLPV);
    dados_hotel.mlpv=atof(&auxMLPV);

    
/*
    // Imprime os dados do hotel
    printf("Nome Fantasia: %s\n", dados_hotel.nome_fantasia);
    printf("Razão Social: %s\n", dados_hotel.razao_social);
    printf("Inscrição Estadual: %s\n", dados_hotel.inscricao_estadual);
    printf("CNPJ: %s\n", dados_hotel.cnpj);
    printf("Endereço: %s, %s, %s, %s, %s, %d\n", dados_hotel.endereco.estado,dados_hotel.endereco.cidade, dados_hotel.endereco.bairro,
           dados_hotel.endereco.cep, dados_hotel.endereco.rua, dados_hotel.endereco.numero);
    printf("Telefone: %s\n", dados_hotel.telefone);
    printf("Email: %s\n", dados_hotel.email);
    printf("Nome Responsável: %s\n", dados_hotel.nome_responsavel);
    printf("Telefone Responsável: %s\n", dados_hotel.telefone_responsavel);
    printf("Checkin: %d:%d\n", dados_hotel.horario_checkin.hora,dados_hotel.horario_checkin.minutos);
    printf("Checkout: %d:%d\n", dados_hotel.horario_checkout.hora,dados_hotel.horario_checkout.minutos);
    printf("MLPV: %f\n", dados_hotel.mlpv);
*/
    // Libera a memória alocada
    free(conteudo_hotel);
    
    cadastro_hotel_txt(dados_hotel);
    
    
    return 0;
}

//funcao para importar dados dos hospedes
int importar_dados_hospedes_xml(char *arquivo){
    char *buffer = trazer_xml_buffer(arquivo);

    
    
    // Estrutura para armazenar os dados do endereço
    dados_edrc dados_endereco;
    // Estrutura para armazenar os dados de data
    data dados_nascimento;

    char auxEndereco[500];
    char auxDATA[20];
    char auxCod[10];
    //printf("Buffer: %s\n", buffer);


    const char *inicio_tag = "<tabela=hospedes>";
    const char *fim_tag = "</tabela=hospedes>";

    // Encontra as posições das tags de início e fim
    const char *inicio = strstr(buffer, inicio_tag);
    const char *fim = strstr(buffer, fim_tag);

    // Verifica se as tags foram encontradas
    if (inicio != NULL && fim != NULL) {
        // Calcula o tamanho do conteúdo
        size_t tamanho_conteudo = fim - (inicio + strlen(inicio_tag));

        // Aloca memória para armazenar o conteúdo
        char *conteudo_hospedes = (char *) malloc((tamanho_conteudo + 1) * sizeof (char));

        // Copia o conteúdo entre as tags
        strncpy(conteudo_hospedes, inicio + strlen(inicio_tag), tamanho_conteudo);
        conteudo_hospedes[tamanho_conteudo] = '\0'; // Adiciona o caractere nulo ao final

        // Imprime o conteúdo extraído
        //printf("Conteúdo entre <tabela=hospedes> e </tabela=hospedes>:\n%s\n", conteudo_hospedes);
        
        // Inicializa o contador de registros
        int contador_registros = 0;

        // Inicia a busca por registros
        const char *registro_inicio = conteudo_hospedes;
        const char *registro_fim = strstr(registro_inicio, "</registro>");

        while (registro_fim != NULL) {
            // Incrementa o contador
            contador_registros++;

            // Atualiza as posições para o próximo registro
            registro_inicio = registro_fim + strlen("</registro>");
            registro_fim = strstr(registro_inicio, "</registro>");
        }
        
        // Estrutura para armazenar os dados dos hóspedes
        hospedes dados_hospedes[contador_registros];
        
        // Reinicializa as posições para o início
        registro_inicio = conteudo_hospedes;
        
        for (int i = 0; i < contador_registros; i++) {
            // Encontra as posições das tags de início e fim do próximo registro
            registro_fim = strstr(registro_inicio, "</registro>");

            if (registro_fim != NULL) {
                // Seção para extrair valores do registro atual
                extrairValor(registro_inicio, "<codigo>", "</codigo>", auxCod);
                sscanf(auxCod, "%d", &dados_hospedes[i].codigo);

                extrairValor(registro_inicio, "<nome>", "</nome>", dados_hospedes[i].nome);
                extrairValor(registro_inicio, "<endereco>", "</endereco>", auxEndereco);
                sscanf(auxEndereco, "%[^;];%[^;];%[^;];%[^;];%[^;];%d", dados_hospedes[i].endereco_hospede.estado,
                        dados_hospedes[i].endereco_hospede.cidade, dados_hospedes[i].endereco_hospede.bairro,
                        dados_hospedes[i].endereco_hospede.cep, dados_hospedes[i].endereco_hospede.rua,
                        &dados_hospedes[i].endereco_hospede.numero);
                
                
                extrairValor(registro_inicio, "<cpf>", "</cpf>", dados_hospedes[i].cpf);
                extrairValor(registro_inicio, "<telefone>", "</telefone>", dados_hospedes[i].telefone);
                extrairValor(registro_inicio, "<email>", "</email>", dados_hospedes[i].email);
                extrairValor(registro_inicio, "<sexo>", "</sexo>", dados_hospedes[i].sexo);
                extrairValor(registro_inicio, "<est_civil>", "</est_civil>", dados_hospedes[i].estado_civil);

                extrairValor(registro_inicio, "<data_nascimento>", "</data_nascimento>", auxDATA);
                sscanf(auxDATA, "%d/%d/%d", &dados_hospedes[i].data_nacimento.dia,&dados_hospedes[i].data_nacimento.mes,&dados_hospedes[i].data_nacimento.ano);

               

                // Atualiza a posição para o próximo registro
                registro_inicio = registro_fim + strlen("</registro>");
            } else {
                // Se não encontrar a próxima tag de fim, encerra o loop
                break;
            }
        }
        
        /*
        for(int i=0;i<contador_registros;i++){
            // Imprime os dados dos hóspedes
            printf("Código: %d\n", dados_hospedes[i].codigo);
            printf("Nome: %s\n", dados_hospedes[i].nome);
            printf("Endereço: %s, %s, %s, %s, %s, %d\n", dados_hospedes[i].endereco_hospede.estado,
                    dados_hospedes[i].endereco_hospede.cidade, dados_hospedes[i].endereco_hospede.bairro,
                    dados_hospedes[i].endereco_hospede.cep, dados_hospedes[i].endereco_hospede.rua,
                    dados_hospedes[i].endereco_hospede.numero);
            printf("CPF: %s\n", dados_hospedes[i].cpf);
            printf("Telefone: %s\n", dados_hospedes[i].telefone);
            printf("Email: %s\n", dados_hospedes[i].email);
            printf("Sexo: %s\n", dados_hospedes[i].sexo);
            printf("Estado Civil: %s\n", dados_hospedes[i].estado_civil);
            printf("Data de Nascimento: %d/%d/%d\n", dados_hospedes[i].data_nacimento.dia,
                    dados_hospedes[i].data_nacimento.mes, dados_hospedes[i].data_nacimento.ano);
        }
        */

        //Libera a memória alocada
        free(conteudo_hospedes);
        
        deleta_arquivo("hospedes.txt");
        for (int i = 0; i < contador_registros; i++) {
            cadastro_hospedes_txt(dados_hospedes[i]);
        }
    } else {
        printf("Tags da tabela 'hospedes' não encontradas ou conteúdo vazio.\n");
    }
}

//funcao para importar dados das acomodacoes
int importar_dados_acomodacoes_xml(char *arquivo) {
    char *buffer = trazer_xml_buffer(arquivo);

    //printf("Buffer: %s\n", buffer);

    const char *inicio_tag = "<tabela=acomodacoes>";
    const char *fim_tag = "</tabela=acomodacoes>";

    // Encontra as posições das tags de início e fim
    const char *inicio = strstr(buffer, inicio_tag);
    const char *fim = strstr(buffer, fim_tag);

    // Verifica se as tags foram encontradas
    if (inicio != NULL && fim != NULL) {
        // Calcula o tamanho do conteúdo
        size_t tamanho_conteudo = fim - (inicio + strlen(inicio_tag));

        // Aloca memória para armazenar o conteúdo
        char *conteudo_acomodacoes = (char *) malloc((tamanho_conteudo + 1) * sizeof (char));

        // Copia o conteúdo entre as tags
        strncpy(conteudo_acomodacoes, inicio + strlen(inicio_tag), tamanho_conteudo);
        conteudo_acomodacoes[tamanho_conteudo] = '\0'; // Adiciona o caractere nulo ao final

        // Imprime o conteúdo extraído
        //printf("Conteúdo entre <tabela=acomodacoes> e </tabela=acomodacoes>:\n%s\n", conteudo_acomodacoes);

        // Inicializa o contador de registros
        int contador_registros = 0;

        // Inicia a busca por registros
        const char *registro_inicio = conteudo_acomodacoes;
        const char *registro_fim = strstr(registro_inicio, "</registro>");

        while (registro_fim != NULL) {
            // Incrementa o contador
            contador_registros++;

            // Atualiza as posições para o próximo registro
            registro_inicio = registro_fim + strlen("</registro>");
            registro_fim = strstr(registro_inicio, "</registro>");
        }

        // Estrutura para armazenar os dados das acomodações
        acomodacoes dados_acomodacoes[contador_registros];
        char auxCod[10], auxCategoria[10], auxOcupacao[10],auxDiarias[10],auxLucro[10];
        
        // Reinicializa as posições para o início
        registro_inicio = conteudo_acomodacoes;

        for (int i = 0; i < contador_registros; i++) {
            // Encontra as posições das tags de início e fim do próximo registro
            registro_fim = strstr(registro_inicio, "</registro>");

            if (registro_fim != NULL) {
                // Seção para extrair valores do registro atual
                
                extrairValor(registro_inicio, "<codigo>", "</codigo>", auxCod);
                sscanf(auxCod, "%d", &dados_acomodacoes[i].codigo);

                extrairValor(registro_inicio, "<descricao>", "</descricao>", dados_acomodacoes[i].descricao);
                extrairValor(registro_inicio, "<facilidades>", "</facilidades>", dados_acomodacoes[i].facilidades);

                extrairValor(registro_inicio, "<categoria>", "</categoria>", auxCategoria);
                sscanf(auxCategoria, "%d", &dados_acomodacoes[i].categoria);
                
                extrairValor(registro_inicio, "<diarias>", "</diarias>", auxDiarias);
                sscanf(auxDiarias, "%d", &dados_acomodacoes[i].diarias);

                extrairValor(registro_inicio, "<lucro>", "</lucro>", auxLucro);
                sscanf(auxLucro, "%f", &dados_acomodacoes[i].lucro);

                extrairValor(registro_inicio, "<ocupacao>", "</ocupacao>", auxOcupacao);
                sscanf(auxOcupacao, "%d", &dados_acomodacoes[i].ocupacao);

                // Atualiza a posição para o próximo registro
                registro_inicio = registro_fim + strlen("</registro>");
            } else {
                // Se não encontrar a próxima tag de fim, encerra o loop
                break;
            }
        }
        /*
        for (int i = 0; i < contador_registros; i++) {
            // Imprime os dados das acomodações
            printf("Código: %d\n", dados_acomodacoes[i].codigo);
            printf("Descrição: %s\n", dados_acomodacoes[i].descricao);
            printf("Facilidades: %s\n", dados_acomodacoes[i].facilidades);
            printf("Categoria: %d\n", dados_acomodacoes[i].categoria);
            printf("Ocupação: %d\n", dados_acomodacoes[i].ocupacao);
        }
        */
        // Libera a memória alocada
        free(conteudo_acomodacoes);
        deleta_arquivo("acomodacoes.txt");
        for (int i = 0; i < contador_registros; i++) {
            cadastro_acomodacoes_txt(dados_acomodacoes[i]);
        }
        
    } else {
        printf("Tags da tabela 'acomodacoes' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados das categorias de acomodacoes
int importar_dados_categoria_acomodacao_xml(char *arquivo) {
    char *buffer = trazer_xml_buffer(arquivo);

    //printf("Buffer: %s\n", buffer);

    const char *inicio_tag = "<tabela=categoria_acomodacao>";
    const char *fim_tag = "</tabela=categoria_acomodacao>";

    // Encontra as posições das tags de início e fim
    const char *inicio = strstr(buffer, inicio_tag);
    const char *fim = strstr(buffer, fim_tag);

    // Verifica se as tags foram encontradas
    if (inicio != NULL && fim != NULL) {
        // Calcula o tamanho do conteúdo
        size_t tamanho_conteudo = fim - (inicio + strlen(inicio_tag));

        // Aloca memória para armazenar o conteúdo
        char *conteudo_categorias = (char *) malloc((tamanho_conteudo + 1) * sizeof (char));

        // Copia o conteúdo entre as tags
        strncpy(conteudo_categorias, inicio + strlen(inicio_tag), tamanho_conteudo);
        conteudo_categorias[tamanho_conteudo] = '\0'; // Adiciona o caractere nulo ao final

        // Imprime o conteúdo extraído
        //printf("Conteúdo entre <tabela=categoria_acomodacao> e </tabela=categoria_acomodacao>:\n%s\n", conteudo_categorias);

        // Inicializa o contador de registros
        int contador_registros = 0;

        // Inicia a busca por registros
        const char *registro_inicio = conteudo_categorias;
        const char *registro_fim = strstr(registro_inicio, "</registro>");

        while (registro_fim != NULL) {
            // Incrementa o contador
            contador_registros++;

            // Atualiza as posições para o próximo registro
            registro_inicio = registro_fim + strlen("</registro>");
            registro_fim = strstr(registro_inicio, "</registro>");
        }

        // Estrutura para armazenar os dados das categorias de acomodação
        categoria_acomodacao dados_categorias[contador_registros];
        char auxCod[10],auxValor[10];
        char auxAdultos[10], auxCriancas[10];
        
        // Reinicializa as posições para o início
        registro_inicio = conteudo_categorias;

        for (int i = 0; i < contador_registros; i++) {
            // Encontra as posições das tags de início e fim do próximo registro
            registro_fim = strstr(registro_inicio, "</registro>");

            if (registro_fim != NULL) {
                // Seção para extrair valores do registro atual
                

                extrairValor(registro_inicio, "<codigo>", "</codigo>", auxCod);
                sscanf(auxCod, "%d", &dados_categorias[i].codigo);

                extrairValor(registro_inicio, "<descricao>", "</descricao>", dados_categorias[i].descricao);
                extrairValor(registro_inicio, "<valor_diaria>", "</valor_diaria>", auxValor);
                sscanf(auxValor, "%f", &dados_categorias[i].valor_diaria);
                
                
                extrairValor(registro_inicio, "<adultos>", "</adultos>", auxAdultos);
                sscanf(auxAdultos, "%d", &dados_categorias[i].adultos);

                extrairValor(registro_inicio, "<criancas>", "</criancas>", auxCriancas);
                sscanf(auxCriancas, "%d", &dados_categorias[i].criancas);

                // Atualiza a posição para o próximo registro
                registro_inicio = registro_fim + strlen("</registro>");
            } else {
                // Se não encontrar a próxima tag de fim, encerra o loop
                break;
            }
        }
        /*
        for (int i = 0; i < contador_registros; i++) {
            // Imprime os dados das categorias de acomodação
            printf("Código: %d\n", dados_categorias[i].codigo);
            printf("Descrição: %s\n", dados_categorias[i].descricao);
            printf("Valor Diária: %.2f\n", dados_categorias[i].valor_diaria);
            printf("Número de Adultos: %d\n", dados_categorias[i].adultos);
            printf("Número de Crianças: %d\n", dados_categorias[i].criancas);
        }
        */
        // Libera a memória alocada
        free(conteudo_categorias);
        
        deleta_arquivo("categorias.txt");
        for (int i = 0; i < contador_registros; i++) {
            cadastro_categoria_txt(dados_categorias[i]);
        }
        
        
    } else {
        printf("Tags da tabela 'categoria_acomodacao' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados de produtos
int importar_dados_produtos_xml(char *arquivo) {
    char *buffer = trazer_xml_buffer(arquivo);

    //printf("Buffer: %s\n", buffer);

    const char *inicio_tag = "<tabela=produtos>";
    const char *fim_tag = "</tabela=produtos>";

    // Encontra as posições das tags de início e fim
    const char *inicio = strstr(buffer, inicio_tag);
    const char *fim = strstr(buffer, fim_tag);

    // Verifica se as tags foram encontradas
    if (inicio != NULL && fim != NULL) {
        // Calcula o tamanho do conteúdo
        size_t tamanho_conteudo = fim - (inicio + strlen(inicio_tag));

        // Aloca memória para armazenar o conteúdo
        char *conteudo_produtos = (char *) malloc((tamanho_conteudo + 1) * sizeof (char));

        // Copia o conteúdo entre as tags
        strncpy(conteudo_produtos, inicio + strlen(inicio_tag), tamanho_conteudo);
        conteudo_produtos[tamanho_conteudo] = '\0'; // Adiciona o caractere nulo ao final

        // Imprime o conteúdo extraído
        //printf("Conteúdo entre <tabela=produtos> e </tabela=produtos>:\n%s\n", conteudo_produtos);

        // Inicializa o contador de registros
        int contador_registros = 0;

        // Inicia a busca por registros
        const char *registro_inicio = conteudo_produtos;
        const char *registro_fim = strstr(registro_inicio, "</registro>");

        while (registro_fim != NULL) {
            // Incrementa o contador
            contador_registros++;

            // Atualiza as posições para o próximo registro
            registro_inicio = registro_fim + strlen("</registro>");
            registro_fim = strstr(registro_inicio, "</registro>");
        }

        // Estrutura para armazenar os dados dos produtos
        produtos dados_produtos[contador_registros];
        char auxEstoque[10], auxEstoqueMin[10];
        char auxCod[10],auxCusto[10],auxVenda[10];
        // Reinicializa as posições para o início
        registro_inicio = conteudo_produtos;

        for (int i = 0; i < contador_registros; i++) {
            // Encontra as posições das tags de início e fim do próximo registro
            registro_fim = strstr(registro_inicio, "</registro>");

            if (registro_fim != NULL) {
                // Seção para extrair valores do registro atual
     
                extrairValor(registro_inicio, "<codigo>", "</codigo>", auxCod);
                sscanf(auxCod, "%d", &dados_produtos[i].codigo);

                extrairValor(registro_inicio, "<descricao>", "</descricao>", dados_produtos[i].descricao);

                
                extrairValor(registro_inicio, "<estoque>", "</estoque>", auxEstoque);
                sscanf(auxEstoque, "%d", &dados_produtos[i].estoque);

                extrairValor(registro_inicio, "<estoque_min>", "</estoque_min>", auxEstoqueMin);
                sscanf(auxEstoqueMin, "%d", &dados_produtos[i].estoque_min);

                extrairValor(registro_inicio, "<preco_custo>", "</preco_custo>", auxCusto);
                sscanf(auxCusto, "%f", &dados_produtos[i].preco_custo);
                extrairValor(registro_inicio, "<preco_venda>", "</preco_venda>", auxVenda);
                sscanf(auxVenda, "%f", &dados_produtos[i].preco_venda);
                // Atualiza a posição para o próximo registro
                registro_inicio = registro_fim + strlen("</registro>");
            } else {
                // Se não encontrar a próxima tag de fim, encerra o loop
                break;
            }
        }
        /*
        for (int i = 0; i < contador_registros; i++) {
            // Imprime os dados dos produtos
            printf("Código: %d\n", dados_produtos[i].codigo);
            printf("Descrição: %s\n", dados_produtos[i].descricao);
            printf("Estoque: %d\n", dados_produtos[i].estoque);
            printf("Estoque Mínimo: %d\n", dados_produtos[i].estoque_min);
            printf("Preço de Custo: %.2lf\n", dados_produtos[i].preco_custo);
            printf("Preço de Venda: %.2lf\n", dados_produtos[i].preco_venda);
        }
        */
        // Libera a memória alocada
        free(conteudo_produtos);
        deleta_arquivo("produtos.txt");
        for (int i = 0; i < contador_registros; i++) {
            cadastro_produtos_txt(dados_produtos[i]);
        }
        
    } else {
        printf("Tags da tabela 'produtos' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados dos fornecedores
int importar_dados_fornecedores_xml(char *arquivo) {
    char *buffer = trazer_xml_buffer(arquivo);

    //printf("Buffer: %s\n", buffer);

    const char *inicio_tag = "<tabela=fornecedores>";
    const char *fim_tag = "</tabela=fornecedores>";

    // Encontra as posições das tags de início e fim
    const char *inicio = strstr(buffer, inicio_tag);
    const char *fim = strstr(buffer, fim_tag);

    // Verifica se as tags foram encontradas
    if (inicio != NULL && fim != NULL) {
        // Calcula o tamanho do conteúdo
        size_t tamanho_conteudo = fim - (inicio + strlen(inicio_tag));

        // Aloca memória para armazenar o conteúdo
        char *conteudo_fornecedores = (char *) malloc((tamanho_conteudo + 1) * sizeof (char));

        // Copia o conteúdo entre as tags
        strncpy(conteudo_fornecedores, inicio + strlen(inicio_tag), tamanho_conteudo);
        conteudo_fornecedores[tamanho_conteudo] = '\0'; // Adiciona o caractere nulo ao final

        // Imprime o conteúdo extraído
        //printf("Conteúdo entre <tabela=fornecedores> e </tabela=fornecedores>:\n%s\n", conteudo_fornecedores);

        // Inicializa o contador de registros
        int contador_registros = 0;

        // Inicia a busca por registros
        const char *registro_inicio = conteudo_fornecedores;
        const char *registro_fim = strstr(registro_inicio, "</registro>");

        while (registro_fim != NULL) {
            // Incrementa o contador
            contador_registros++;

            // Atualiza as posições para o próximo registro
            registro_inicio = registro_fim + strlen("</registro>");
            registro_fim = strstr(registro_inicio, "</registro>");
        }

        // Estrutura para armazenar os dados dos fornecedores
        fornecedores dados_fornecedores[contador_registros];
        char auxCod[10];
        char auxEndereco[500];
        // Reinicializa as posições para o início
        registro_inicio = conteudo_fornecedores;

        for (int i = 0; i < contador_registros; i++) {
            // Encontra as posições das tags de início e fim do próximo registro
            registro_fim = strstr(registro_inicio, "</registro>");

            if (registro_fim != NULL) {
                // Seção para extrair valores do registro atual
                

                extrairValor(registro_inicio, "<codigo>", "</codigo>", auxCod);
                sscanf(auxCod, "%d", &dados_fornecedores[i].codigo);

                extrairValor(registro_inicio, "<nome_fantasia>", "</nome_fantasia>", dados_fornecedores[i].nome_fantasia);
                extrairValor(registro_inicio, "<razao_social>", "</razao_social>", dados_fornecedores[i].razao_social);

                extrairValor(registro_inicio, "<inscricao_estadual>", "</inscricao_estadual>", dados_fornecedores[i].inscricao_estadual);
                extrairValor(registro_inicio, "<cnpj>", "</cnpj>", dados_fornecedores[i].cnpj);

                
                extrairValor(registro_inicio, "<endereco>", "</endereco>", auxEndereco);
                sscanf(auxEndereco, "%[^;];%[^;];%[^;];%[^;];%[^;];%d", dados_fornecedores[i].endereco.estado,
                        dados_fornecedores[i].endereco.cidade, dados_fornecedores[i].endereco.bairro,
                        dados_fornecedores[i].endereco.cep, dados_fornecedores[i].endereco.rua,
                        &dados_fornecedores[i].endereco.numero);

                extrairValor(registro_inicio, "<telefone>", "</telefone>", dados_fornecedores[i].telefone);
                extrairValor(registro_inicio, "<email>", "</email>", dados_fornecedores[i].email);

                // Atualiza a posição para o próximo registro
                registro_inicio = registro_fim + strlen("</registro>");
            } else {
                // Se não encontrar a próxima tag de fim, encerra o loop
                break;
            }
        }
        
        /*
        for (int i = 0; i < contador_registros; i++) {
            // Imprime os dados dos fornecedores
            printf("Código: %d\n", dados_fornecedores[i].codigo);
            printf("Nome Fantasia: %s\n", dados_fornecedores[i].nome_fantasia);
            printf("Razão Social: %s\n", dados_fornecedores[i].razao_social);
            printf("Inscrição Estadual: %s\n", dados_fornecedores[i].inscricao_estadual);
            printf("CNPJ: %s\n", dados_fornecedores[i].cnpj);
            printf("Endereço: %s, %s, %s, %s, %s, %d\n", dados_fornecedores[i].endereco.estado,
                    dados_fornecedores[i].endereco.cidade, dados_fornecedores[i].endereco.bairro,
                    dados_fornecedores[i].endereco.cep, dados_fornecedores[i].endereco.rua,
                    dados_fornecedores[i].endereco.numero);
            printf("Telefone: %s\n", dados_fornecedores[i].telefone);
            printf("Email: %s\n", dados_fornecedores[i].email);
        }
        */
        // Libera a memória alocada
        free(conteudo_fornecedores);
        
        deleta_arquivo("fornecedores.txt");
        for (int i = 0; i < contador_registros; i++) {
            cadastro_fornecedor_txt(dados_fornecedores[i]);
        }  
    } else {
        printf("Tags da tabela 'fornecedores' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados dos operadores
int importar_dados_operadores_xml(char *arquivo) {
    char *buffer = trazer_xml_buffer(arquivo);

    //printf("Buffer: %s\n", buffer);

    const char *inicio_tag = "<tabela=operadores>";
    const char *fim_tag = "</tabela=operadores>";

    // Encontra as posições das tags de início e fim
    const char *inicio = strstr(buffer, inicio_tag);
    const char *fim = strstr(buffer, fim_tag);

    // Verifica se as tags foram encontradas
    if (inicio != NULL && fim != NULL) {
        // Calcula o tamanho do conteúdo
        size_t tamanho_conteudo = fim - (inicio + strlen(inicio_tag));

        // Aloca memória para armazenar o conteúdo
        char *conteudo_operadores = (char *) malloc((tamanho_conteudo + 1) * sizeof (char));

        // Copia o conteúdo entre as tags
        strncpy(conteudo_operadores, inicio + strlen(inicio_tag), tamanho_conteudo);
        conteudo_operadores[tamanho_conteudo] = '\0'; // Adiciona o caractere nulo ao final

        // Imprime o conteúdo extraído
        //printf("Conteúdo entre <tabela=operadores> e </tabela=operadores>:\n%s\n", conteudo_operadores);

        // Inicializa o contador de registros
        int contador_registros = 0;

        // Inicia a busca por registros
        const char *registro_inicio = conteudo_operadores;
        const char *registro_fim = strstr(registro_inicio, "</registro>");

        while (registro_fim != NULL) {
            // Incrementa o contador
            contador_registros++;

            // Atualiza as posições para o próximo registro
            registro_inicio = registro_fim + strlen("</registro>");
            registro_fim = strstr(registro_inicio, "</registro>");
        }

        // Estrutura para armazenar os dados dos operadores
        OPsistema dados_operadores[contador_registros];
        char auxCod[10],auxSen[20];
        char auxPer[50];
        // Reinicializa as posições para o início
        registro_inicio = conteudo_operadores;

        for (int i = 0; i < contador_registros; i++) {
            // Encontra as posições das tags de início e fim do próximo registro
            registro_fim = strstr(registro_inicio, "</registro>");

            if (registro_fim != NULL) {
                // Seção para extrair valores do registro atual
                

                extrairValor(registro_inicio, "<codigo>", "</codigo>", auxCod);
                sscanf(auxCod, "%d", &dados_operadores[i].codigo);

                extrairValor(registro_inicio, "<nome>", "</nome>", dados_operadores[i].nome);
                extrairValor(registro_inicio, "<usuario>", "</usuario>", dados_operadores[i].usuario);
                extrairValor(registro_inicio, "<senha>", "</senha>", auxSen);
                sscanf(auxSen, "%d", &dados_operadores[i].senha);
                
                extrairValor(registro_inicio, "<permissoes>", "</permissoes>", auxPer);
                sscanf(auxPer, "%d;%d;%d;%d;%d", &dados_operadores[i].permissoes.cadastros, &dados_operadores[i].permissoes.reservas,
                        &dados_operadores[i].permissoes.transacoes, &dados_operadores[i].permissoes.feedback,
                        &dados_operadores[i].permissoes.im_exportacao);
                // Atualiza a posição para o próximo registro
                registro_inicio = registro_fim + strlen("</registro>");
            } else {
                // Se não encontrar a próxima tag de fim, encerra o loop
                break;
            }
        }
        /*
        for (int i = 0; i < contador_registros; i++) {
            // Imprime os dados dos operadores
            printf("Código: %d\n", dados_operadores[i].codigo);
            printf("Nome: %s\n", dados_operadores[i].nome);
            printf("Usuário: %s\n", dados_operadores[i].usuario);
            printf("Senha: %d\n", dados_operadores[i].senha);
            printf("Permissões: %d;%d;%d;%d;%d\n", dados_operadores[i].permissoes.cadastros, dados_operadores[i].permissoes.reservas,
                    dados_operadores[i].permissoes.transacoes, dados_operadores[i].permissoes.feedback, dados_operadores[i].permissoes.im_exportacao);
        }
        */
        // Libera a memória alocada
        free(conteudo_operadores);
        
        deleta_arquivo("operadores.txt");
        for (int i = 0; i < contador_registros; i++) {
            cadastro_operadores_txt(dados_operadores[i]);
        }  
    } else {
        printf("Tags da tabela 'operadores' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}