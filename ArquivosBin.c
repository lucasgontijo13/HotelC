#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"
#include "ArquivosBin.h"
#include "Funcoes.h"
#include "arquivosTXT.h"
#include "memoria.h"

// Funçao que abre um arquivo binário para escrever e gravar dados do hotel 
int hotel_cad_bin(cad_hotel hotel_inf){
    FILE *p;
    
     //comando que abre o arquivo para escrita
    p=fopen("Hotel.bin","wb");
        
    //verifica se a criação do arquivo foi bem sucedida 
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    
    //comandos para a escrita em arquivos .bin 
    
    if(!feof(p)){
        fwrite(&hotel_inf,sizeof(cad_hotel),1,p);
        
    }else{
        printf("O arquivo se encontra cheio.");
    }

        fclose(p);
        
        printf("Arquivo gravado com sucesso\n");
        return 0;
    }

//Função para ler o binário do hotel e levar para a RAM.
int hotel_ram_bin(cad_hotel *hotel_inf) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Hotel.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&hotel_inf[i], sizeof (cad_hotel), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados do hotel.
void dados_hotel_bin(){
    FILE *p;
    
    //comando para a leitura de um arquivo .bin
    p=fopen("Hotel.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    cad_hotel hotel_inf;
    //comandos para leitura em .bin
   while (fread(&hotel_inf, sizeof(cad_hotel), 1, p)==1){
        
                        printf("----------DADOS DO HOTEL----------\n");
                printf("Nome fantasia:%s\n",hotel_inf .nome_fantasia);
                printf("Razão social:%s\n",hotel_inf .razao_social);
                printf("Inscrição estadual:%s\n",hotel_inf .inscricao_estadual);
                printf("CNPJ:%s\n",hotel_inf .cnpj);
                
                printf("-------ENDEREÇO-------\n");
                printf("Estado:%s\n",hotel_inf .endereco.estado);
                printf("Cidade:%s\n",hotel_inf .endereco.cidade);
                printf("CEP:%s\n",hotel_inf .endereco.cep);
                printf("Bairro:%s\n",hotel_inf .endereco.bairro);
                printf("Rua:%s\n",hotel_inf .endereco.rua);
                printf("Numero de endereço:%d\n",hotel_inf .endereco.numero);
                
                printf("-------DADOS PARA CONTATO-------\n");
                printf("Telefone do hotel:%s\n",hotel_inf .telefone);
                printf("E-mail do hotel:%s\n",hotel_inf .email);
                printf("Nome do responsável:%s\n",hotel_inf .nome_responsavel);
                printf("Telefone do responsável:%s\n",hotel_inf .telefone_responsavel);
                
                printf("-------HORÁRIO DE CHECK-IN-------\n");
                printf("%d:%d\n",hotel_inf .horario_checkin.hora,hotel_inf .horario_checkin.minutos);
                printf("-------HORÁRIO DE CHECK-OUT-------\n");
                
                printf("%d:%d\n",hotel_inf .horario_checkout.hora,hotel_inf .horario_checkout.minutos);
                printf("Margem de lucro sobre os produtos:%.2f\n\n",hotel_inf .mlpv);
                
    }
   
    fclose(p);
}

//Função que atualiza os dados do hotel.
int atualiza_hotel_bin(cad_hotel *novo_hotel_inf){
    int status;

    FILE *p;

    //comando que abre o arquivo para escrita
    p=fopen("Hotel_temp.bin","wb");
    
    //verifica se a criação do arquvio foi bem sucedida 
    if(p == NULL){
       printf("Problemas na abertura do arquivo.");
       exit (1);
    }
    
    if(!feof(p)){
        fwrite(novo_hotel_inf,sizeof(cad_hotel),1,p);
        
    }else{
        printf("O arquivo se encontra cheio.");
    }

    status = remove("Hotel.bin");

    if(status != 0){
        printf("Erro na remoção do arquivo para atualização do cadastro");
        exit(1);
    }
    status = rename("Hotel_temp.bin","Hotel.bin");

    if(status !=0){
        printf("Erro na renomeção do arquivo para atualização do cadastro");
        exit(1);
    }
    printf("Atualização dos dados do hotel feita com sucesso\n");
    return 0;
}


// Funçao que abre um arquivo binário para escrever e gravar dados dos operadores 
int operadores_cad_bin(OPsistema op){
    FILE *p;
    
    //comando que abre o arquivo para escrita
    p=fopen("Operadores.bin","ab");
        
    //verifica se a criação do arquivo foi bem sucedida 
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    
    //comandos para a escrita em arquivos .bin 
    
    if(!feof(p)){
        fwrite(&op,sizeof(OPsistema),1,p);
    }else{
        printf("O arquivo se encontra cheio.");
    }
    
    
    fclose(p);
    
    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//Função para ler o binário de operadores e levar para a RAM.
int operadores_ram_bin(OPsistema *op) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Operadores.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&op[i], sizeof (OPsistema), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados dos operadores.
void dados_operadores_bin(){
    FILE *p;
    
    //comando para a leitura de um arquivo .bin
    p=fopen("Operadores.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    OPsistema op;
    //comandos para leitura em .bin 
    while (fread(&op, sizeof(OPsistema), 1, p) == 1) {
        
        printf("-------DADOS DO OPERADOR-------\n\n");
        printf("Codigo do usuario: %d\n", op.codigo);
        printf("Nome do operador: %s\n", op.nome);
        printf("Nome de usario: %s\n", op.usuario);
        printf("Senha para o usuario: %d\n", op.senha);
        
        if(op.permissoes.cadastros == 0 && op.permissoes.reservas==0 && op.permissoes.transacoes==0 && op.permissoes.feedback==0 && op.permissoes.im_exportacao==0){
            printf("\nNenhuma permissao ativa.\n\n");
        }else{
        printf("\nPERMISSOES ATIVAS\n");
        if(op.permissoes.cadastros==1){
        printf("Cadastros\n");
        }
        if(op.permissoes.reservas==1){
        printf("Reservas\n");
        }
        if(op.permissoes.transacoes==1){
        printf("Transacoes\n");
        }
        if(op.permissoes.feedback==1){
        printf("FeedBack\n");
        }
        if(op.permissoes.im_exportacao==1){
        printf("Importações e Exportacoes\n");
        }
        printf("\n\n");
        }
    }
    
    
    fclose(p);
}

//Função que atualiza os dados dos operadores.
int atualiza_operadores_bin(OPsistema novo_op, int codigo_operador) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Operadores.bin", "rb");
    temporario = fopen("Operadores_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    OPsistema operd;

    while (fread(&operd, sizeof(OPsistema), 1, original) == 1) {
        if (operd.codigo == codigo_operador) {
            // O registro com o código desejado foi encontrado e substituido
            fwrite(&novo_op, sizeof(OPsistema), 1, temporario);
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&operd, sizeof(OPsistema), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Operador com código %d não encontrado.\n", codigo_operador);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Operadores.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Operadores_temp.bin", "Operadores.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos dados do operador feita com sucesso\n");
    return 1;
}

//Função que deleta os dados de um operador.
int deleta_operadores_bin( int codigo_operador) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Operadores.bin", "rb");
    temporario = fopen("Operadores_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    OPsistema operd;

    while (fread(&operd, sizeof(OPsistema), 1, original) == 1) {
        if (operd.codigo == codigo_operador) {
            // O registro com o código desejado foi encontrado e apagado.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&operd, sizeof(OPsistema), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Operador com código %d não encontrado.\n", codigo_operador);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Operadores.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Operadores_temp.bin", "Operadores.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Delete do operador feita com sucesso\n");
    return 0;
}



// Funçao que abre um arquivo binário para escrever e gravar dados dos hospedes.
int hospede_cad_bin(hospedes hospede_inf){
    FILE *p;
    
    //comando que abre o arquivo para escrita
    p=fopen("Hospedes.bin","ab");
        
    //verifica se a criação do arquivo foi bem sucedida 
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    //comandos para a escrita em arquivos .bin 
    
    if(!feof(p)){
        fwrite(&hospede_inf,sizeof(hospedes),1,p);
    }else{
        printf("O arquivo se encontra cheio.");
    }
    
    
    fclose(p);
    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//Função para ler o binário dos hospedes e levar para a RAM.
int hospede_ram_bin(hospedes *hospede_inf) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Hospedes.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&hospede_inf[i], sizeof (hospedes), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados dos hospedes.
void dados_hospede_bin(){
    FILE *p;
    
    //comando para a leitura de um arquivo .bin
    p=fopen("Hospedes.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    hospedes hospede_inf;
    
    //comandos para leitura em .bin 
    while (fread(&hospede_inf, sizeof(hospedes), 1, p) == 1) {
        
        printf("-------DADOS DO HOSPEDE-------\n");
        
        printf("Codigo: %d\n", hospede_inf.codigo);
        printf("Nome: %s\n", hospede_inf.nome); 
        printf("CPF: %s\n", hospede_inf.cpf);
        printf("Telefone: %s\n", hospede_inf.telefone);
        printf("Email: %s\n", hospede_inf.email);
        printf("Sexo: %s\n", hospede_inf.sexo);
        printf("Estado civil: %s\n", hospede_inf.estado_civil);
        printf("Data de nascimento: %d/%d/%d\n\n", hospede_inf.data_nacimento.dia, hospede_inf.data_nacimento.mes, hospede_inf.data_nacimento.ano);
         printf("-------ENDEREÇO-------\n");
        printf("Estado: %s\n", hospede_inf.endereco_hospede.estado);
        printf("Cidade: %s\n", hospede_inf.endereco_hospede.cidade);
        printf("CEP: %s\n", hospede_inf.endereco_hospede.cep);
        printf("Bairro: %s\n", hospede_inf.endereco_hospede.bairro);
        printf("Rua: %s\n", hospede_inf.endereco_hospede.rua);
        printf("Numero: %d\n\n", hospede_inf.endereco_hospede.numero);
    }
    
    
    fclose(p);
}

//Função que atualiza os dados dos hospedes.
int atualiza_hospede_bin(hospedes novo_hospede, int codigo_hospede) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Hospedes.bin", "rb");
    temporario = fopen("Hospedes_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    hospedes hspd;

    while (fread(&hspd, sizeof(hospedes), 1, original) == 1) {
        if (hspd.codigo == codigo_hospede) {
            // O registro com o código desejado foi encontrado e substituido
            fwrite(&novo_hospede, sizeof(hospedes), 1, temporario);
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&hspd, sizeof(hospedes), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Hospede com código %d não encontrado.\n", codigo_hospede);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Hospedes.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Hospedes_temp.bin", "Hospedes.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos dados do hospede feita com sucesso\n");
    return 0;
}

//Função que deleta os dados de um hospede.
int deleta_hospede_bin( int codigo_hospede) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Hospedes.bin", "rb");
    temporario = fopen("Hospedes_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    hospedes hspd;

    while (fread(&hspd, sizeof(hospedes), 1, original) == 1) {
        if (hspd.codigo == codigo_hospede) {
            // O registro com o código desejado foi encontrado e apagado.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&hspd, sizeof(hospedes), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Hospede com código %d não encontrado.\n", codigo_hospede);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Hospedes.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Hospedes_temp.bin", "Hospedes.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Delete do hodedes feita com sucesso\n");
    return 0;
}



// Funçao que abre um arquivo binário para escrever e gravar dados dos produtos.
int produtos_cad_bin(produtos produtos_inf){
    FILE *p;
    
    //comando que abre o arquivo para escrita
    p=fopen("Produtos.bin","ab");
        
    //verifica se a criação do arquivo foi bem sucedida 
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    //comandos para a escrita em arquivos .bin 
    
    if(!feof(p)){
        fwrite(&produtos_inf,sizeof(produtos),1,p);
    }else{
        printf("O arquivo se encontra cheio.");
    }
    
    
    fclose(p);
    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//Função para ler o binário dos produtos e levar para a RAM.
int produtos_ram_bin(produtos *produtos_inf) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Produtos.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&produtos_inf[i], sizeof (produtos), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados dos produtos.
void dados_produtos_bin(){
    FILE *p;
    
    //comando para a leitura de um arquivo .bin
    p=fopen("Produtos.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    produtos produtos_inf;
    //comandos para leitura em .bin 
    while (fread(&produtos_inf, sizeof(produtos), 1, p) == 1) {
        
        printf("-------DADOS DO PRODUTO-------\n");
        
        printf("Codigo: %d\n", produtos_inf.codigo);
        printf("Descrição: %s\n", produtos_inf.descricao); 
        printf("Estoque: %d\n", produtos_inf.estoque);
        printf("Estoque mínimo: %d\n", produtos_inf.estoque_min);
        printf("Preço de custo: R$%.2f\n", produtos_inf.preco_custo);
        printf("Preço de venda: R$%.2f\n\n", produtos_inf.preco_venda);
    }
    
    
    fclose(p);
}

//Função que atualiza os dados dos produtos.
int atualiza_produtos_bin(produtos *novo_produto, int codigo_produto) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Produtos.bin", "rb");
    temporario = fopen("Produtos_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    produtos prtd;

    while (fread(&prtd, sizeof(produtos), 1, original) == 1) {
        if (prtd.codigo == codigo_produto) {
            // O registro com o código desejado foi encontrado e substituido
            fwrite(novo_produto, sizeof(produtos), 1, temporario);
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&prtd, sizeof(produtos), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Produto com código %d não encontrado.\n", codigo_produto);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Produtos.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Produtos_temp.bin", "Produtos.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos dados dos produtos feita com sucesso\n");
    return 0;
}

//Função que atualiza o estoque dos produtos.
int atualiza_estoque_bin(int qtd_compra , int codigo_produto) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Produtos.bin", "rb");
    temporario = fopen("Produtos_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    produtos prtd;

    
        while (fread(&prtd, sizeof (produtos), 1, original) == 1) {
                if (prtd.codigo == codigo_produto) {

                    prtd.estoque-=qtd_compra;
                    fwrite(&prtd, sizeof (produtos), 1, temporario);
                    encontrado = 1;
                }else{
                    fwrite(&prtd, sizeof(produtos), 1, temporario);
                }
        }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Produto com código %d não encontrado.\n", codigo_produto);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Produtos.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Produtos_temp.bin", "Produtos.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos dados dos produtos feita com sucesso\n");
    return 0;
}

//Função que deleta um dado de produto.
int deleta_produtos_bin( int codigo_produto) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Produtos.bin", "rb");
    temporario = fopen("Produtos_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    produtos prtd;

    while (fread(&prtd, sizeof(produtos), 1, original) == 1) {
        if (prtd.codigo == codigo_produto) {
            // O registro com o código desejado foi encontrado e apagado.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&prtd, sizeof(produtos), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Produto com código %d não encontrado.\n", codigo_produto);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Produtos.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Produtos_temp.bin", "Produtos.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Delete dos dados dos produtos feita com sucesso\n");
    return 0;
}



// Funçao que abre um arquivo binário para escrever e gravar dados dos fornecedores.
int fornecedores_cad_bin(fornecedores fornecedores_inf){
    FILE *p;
    
    //comando que abre o arquivo para escrita
    p=fopen("Fornecedores.bin","ab");
        
    //verifica se a criação do arquivo foi bem sucedida 
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    //comandos para a escrita em arquivos .bin 
    
    if(!feof(p)){
        fwrite(&fornecedores_inf,sizeof(fornecedores),1,p);
    }else{
        printf("O arquivo se encontra cheio.");
    }
    
    
    fclose(p);
    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//Função para ler o binário dos fornecedores e levar para a RAM.
int fornecedores_ram_bin(fornecedores *fornecedores_inf) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Fornecedores.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&fornecedores_inf[i], sizeof (fornecedores), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados dos fornecedores.
void dados_fornecedores_bin(){
    FILE *p;
    
    //comando para a leitura de um arquivo .bin
    p=fopen("Fornecedores.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    fornecedores fornecedores_inf;
    //comandos para leitura em .bin 
    while (fread(&fornecedores_inf, sizeof(fornecedores), 1, p) == 1) {
        
        printf("-------DADOS DO FORNECEDOR-------\n");
        
        printf("Codigo: %d\n", fornecedores_inf.codigo);
        printf("Nome fantasia: %s\n", fornecedores_inf.nome_fantasia);
        printf("Razao social: %s\n", fornecedores_inf.razao_social);
        printf("Inscrico estadual: %s\n", fornecedores_inf.inscricao_estadual);
        printf("CNPJ: %s\n", fornecedores_inf.cnpj);

        printf("-------ENDERECO-------\n");
        printf("Estado: %s\n", fornecedores_inf.endereco.estado);
        printf("Cidade: %s\n", fornecedores_inf.endereco.cidade);
        printf("CEP: %s\n", fornecedores_inf.endereco.cep);
        printf("Bairro: %s\n", fornecedores_inf.endereco.bairro);
        printf("Rua: %s\n", fornecedores_inf.endereco.rua);
        printf("Numero: %d\n", fornecedores_inf.endereco.numero);

        printf("--------------------------------------------------------------------------\n");
        printf("-------DADOS PARA CONTATO-------\n");
        printf("Telefone do fornecedor: %s\n", fornecedores_inf.telefone);
        printf("E-mail do fornecedor: %s\n\n", fornecedores_inf.email);
    }
    
    
    fclose(p);
}

//Função que atualiza os dados dos fornecedores.
int atualiza_fornecedores_bin(fornecedores novo_fornecedor, int codigo_fornecedor) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Fornecedores.bin", "rb");
    temporario = fopen("Fornecedores_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    fornecedores fornc;

    while (fread(&fornc, sizeof(fornecedores), 1, original) == 1) {
        if (fornc.codigo == codigo_fornecedor) {
            // O registro com o código desejado foi encontrado e substituido
            fwrite(&novo_fornecedor, sizeof(fornecedores), 1, temporario);
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&fornc, sizeof(fornecedores), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("fornecedor com código %d não encontrado.\n", codigo_fornecedor);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Fornecedores.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Fornecedores_temp.bin", "Fornecedores.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos dados dos fornecedores feita com sucesso\n");
    return 0;
}

//Função que deleta um dado de fornecedor.
int deleta_fornecedor_bin( int codigo_fornecedor) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Fornecedores.bin", "rb");
    temporario = fopen("Fornecedores_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    fornecedores fornc;

    while (fread(&fornc, sizeof(fornecedores), 1, original) == 1) {
               if (fornc.codigo == codigo_fornecedor) {
            // O registro com o código desejado foi encontrado e apagado.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&fornc, sizeof(fornecedores), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Fornecedor com código %d não encontrado.\n", codigo_fornecedor);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Fornecedores.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Fornecedores_temp.bin", "Fornecedores.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Delete dos dados dos fornecedores feita com sucesso\n");
    return 0;
}



// Funçao que abre um arquivo binário para escrever e gravar dados das categorias de acomodações.
int categoria_cad_bin(categoria_acomodacao categorias_inf){
    FILE *p;
    
    //comando que abre o arquivo para escrita
    p=fopen("Categorias.bin","ab");
        
    //verifica se a criação do arquivo foi bem sucedida 
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    //comandos para a escrita em arquivos .bin 
    
    if(!feof(p)){
        fwrite(&categorias_inf,sizeof(categoria_acomodacao),1,p);
    }else{
        printf("O arquivo se encontra cheio.");
    }
    
    
    fclose(p);
    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//Função para ler o binário das categorias de acomodação e levar para a RAM.
int categorias_ram_bin(categoria_acomodacao *categorias_inf) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Categorias.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&categorias_inf[i], sizeof (categoria_acomodacao), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados das categorias de acomodação.
void dados_categorias_bin(){
    FILE *p;
    
    //comando para a leitura de um arquivo .bin
    p=fopen("Categorias.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    //comandos para leitura em .bin 
    categoria_acomodacao categorias_inf;
    
    while (fread(&categorias_inf, sizeof(categoria_acomodacao), 1, p) == 1) {
        
        printf("-------DADOS DA CATEGORIA-------\n");
        
        printf("Codigo: %d\n", categorias_inf.codigo);
        printf("Descrição: %s\n", categorias_inf.descricao); 
        printf("Valor diario: R$%.2f\n", categorias_inf.valor_diaria);
        printf("Número de adultos: %d\n", categorias_inf.adultos);
        printf("Número de crianças: %d\n\n", categorias_inf.criancas);
    }
    
    
    fclose(p);
}

//Função que atualiza os dados das categorias de acomodação.
int atualiza_categorias_bin(categoria_acomodacao nova_categorias, int codigo_categorias) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Categorias.bin", "rb");
    temporario = fopen("Categorias_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    categoria_acomodacao categ;

    while (fread(&categ, sizeof(categoria_acomodacao), 1, original) == 1) {
        if (categ.codigo == codigo_categorias) {
            // O registro com o código desejado foi encontrado e substituido
            fwrite(&nova_categorias, sizeof(categoria_acomodacao), 1, temporario);
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&categ, sizeof(categoria_acomodacao), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Categoria com código %d não encontrado.\n", codigo_categorias);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Categorias.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Categorias_temp.bin", "Categorias.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos dados das categorias feita com sucesso\n");
    return 0;
}

//Função que atualiza os dados das categorias de acomodaçãos.
int deleta_categorias_bin( int codigo_categorias) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Categorias.bin", "rb");
    temporario = fopen("Categorias_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    categoria_acomodacao categ;

    while (fread(&categ, sizeof(categoria_acomodacao), 1, original) == 1) {
        if (categ.codigo == codigo_categorias) {
            // O registro com o código desejado foi encontrado e apagado.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&categ, sizeof(categoria_acomodacao), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Categoria com código %d não encontrado.\n", codigo_categorias);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Categorias.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Categorias_temp.bin", "Categorias.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Delete dos dados das categorias feita com sucesso\n");
    return 0;
}



// Funçao que abre um arquivo binário para escrever e gravar dados das acomodações.
int acomodacoes_cad_bin(acomodacoes acomodacoes_inf){
    FILE *p;
    
    //comando que abre o arquivo para escrita
    p=fopen("Acomodacoes.bin","ab");
        
    //verifica se a criação do arquivo foi bem sucedida 
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    //comandos para a escrita em arquivos .bin 
    
    if(!feof(p)){
        fwrite(&acomodacoes_inf,sizeof(acomodacoes),1,p);
    }else{
        printf("O arquivo se encontra cheio.");
    }
    
    
    fclose(p);
    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//Função para ler o binário das acomodações e levar para a RAM.
int acomodacoes_ram_bin(acomodacoes *acomodacoes_inf) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Acomodacoes.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&acomodacoes_inf[i], sizeof (acomodacoes), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados das acomodações.
void dados_acomodacoes_bin(){
    FILE *p;
    
    //comando para a leitura de um arquivo .bin
    p=fopen("Acomodacoes.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    acomodacoes acomodacoes_inf;
    
    //comandos para leitura em .bin 
    while (fread(&acomodacoes_inf, sizeof(acomodacoes), 1, p) == 1) {
        
        printf("-------DADOS DAS ACOMODAÇÕES-------\n");
        
        printf("Codigo: %d\n", acomodacoes_inf.codigo);
        printf("Descrição: %s\n", acomodacoes_inf.descricao); 
        printf("Facilidades: %s\n", acomodacoes_inf.facilidades); 
        printf("Codigo da categoria: %d\n", acomodacoes_inf.categoria);
        printf("Diarias: %d\n", acomodacoes_inf.diarias);
        printf("Lucro: %.2f\n", acomodacoes_inf.lucro);
        printf("Ocupação: %d\n", acomodacoes_inf.ocupacao);
    }
    
    
    fclose(p);
}

//Função para ler e printar os dados das acomodações.
void dados_acm_especificas_bin(reservas *vetor_cod){
    FILE *p;
    //comando para a leitura de um arquivo .bin
    p=fopen("Acomodacoes.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    int i=0;
    acomodacoes acomodacoes_inf;
    //comandos para leitura em .bin 
    while (fread(&acomodacoes_inf, sizeof(acomodacoes), 1, p) == 1) {
        
        if(vetor_cod[i].codigo_aco == acomodacoes_inf.codigo){
        printf("-------DADOS DAS ACOMODAÇÕES-------\n");
        
        printf("Codigo: %d\n", acomodacoes_inf.codigo);
        printf("Descrição: %s\n", acomodacoes_inf.descricao); 
        printf("Facilidades: %s\n", acomodacoes_inf.facilidades); 
        printf("Codigo da categoria: %d\n\n", acomodacoes_inf.categoria);
        i++;
        }
    }
    
    
    fclose(p);
}

//Função que atualiza os dados das acomodações.
int atualiza_acomodacoes_bin(acomodacoes nova_acomodacao, int codigo_acomodacao) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Acomodacoes.bin", "rb");
    temporario = fopen("Acomodacoes_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    acomodacoes acmd;

    while (fread(&acmd, sizeof(acomodacoes), 1, original) == 1) {
        if (acmd.codigo == codigo_acomodacao) {
            // O registro com o código desejado foi encontrado e substituido
            nova_acomodacao.ocupacao = acmd.ocupacao;
            fwrite(&nova_acomodacao, sizeof(acomodacoes), 1, temporario);
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&acmd, sizeof(acomodacoes), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Acomodação com código %d não encontrado.\n", codigo_acomodacao);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Acomodacoes.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Acomodacoes_temp.bin", "Acomodacoes.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos dados das acomodações feita com sucesso\n");
    return 0;
}

//Função que atualiza manualmente a ocupação das acomodações.
int atualiza_ocupantes_acm_bin(int ocupantes , int codigo_acomodacao) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Acomodacoes.bin", "rb");
    temporario = fopen("Acomodacoes_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    acomodacoes acmd;

    while (fread(&acmd, sizeof(acomodacoes), 1, original) == 1) {
        if (acmd.codigo == codigo_acomodacao) {
            // O registro com o código desejado foi encontrado e o número de ocupantes foi mudado
            acmd.ocupacao = ocupantes;
            encontrado = 1;
        }

        // Escreva o registro (atualizado ou não) no arquivo temporário
        fwrite(&acmd, sizeof(acomodacoes), 1, temporario);
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Acomodação com código %d não encontrado.\n", codigo_acomodacao);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Acomodacoes.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Acomodacoes_temp.bin", "Acomodacoes.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos ocupantes feita com sucesso\n");
    return 0;
}

//Função que adiciona uma ocupação das acomodações.
int soma_ocupantes_acm_bin(int codigo_acomodacao, float valor, int diaria) {

    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Acomodacoes.bin", "rb");
    temporario = fopen("Acomodacoes_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    acomodacoes acmd;

    while (fread(&acmd, sizeof (acomodacoes), 1, original) == 1) {
        if (acmd.codigo == codigo_acomodacao) {
            // O registro com o código desejado foi encontrado e o número de ocupantes foi mudado
            acmd.ocupacao++;
            acmd.lucro += valor;
            acmd.diarias += diaria;
            encontrado = 1;
        }

        // Escreva o registro (atualizado ou não) no arquivo temporário
        fwrite(&acmd, sizeof (acomodacoes), 1, temporario);
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Acomodação com código %d não encontrado.\n", codigo_acomodacao);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Acomodacoes.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Acomodacoes_temp.bin", "Acomodacoes.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos ocupantes feita com sucesso\n");
    return 0;
}

//Função que diminui uma ocupação das acomodações.
int diminui_ocupantes_valor_acm_bin(int codigo_acomodacao, float valor, int diaria) {

    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Acomodacoes.bin", "rb");
    temporario = fopen("Acomodacoes_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    acomodacoes acmd;

    while (fread(&acmd, sizeof (acomodacoes), 1, original) == 1) {
        if (acmd.codigo == codigo_acomodacao) {
            // O registro com o código desejado foi encontrado e o número de ocupantes foi mudado
            acmd.ocupacao--;
            acmd.lucro -= valor;
            acmd.diarias -= diaria;
            encontrado = 1;
        }

        // Escreva o registro (atualizado ou não) no arquivo temporário
        fwrite(&acmd, sizeof (acomodacoes), 1, temporario);
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Acomodação com código %d não encontrado.\n", codigo_acomodacao);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Acomodacoes.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Acomodacoes_temp.bin", "Acomodacoes.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos ocupantes feita com sucesso\n");
    return 0;
}

//Função que diminui uma ocupação das acomodações.
int diminui_ocupantes_acm_bin(int codigo_acomodacao) {

    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Acomodacoes.bin", "rb");
    temporario = fopen("Acomodacoes_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    acomodacoes acmd;

    while (fread(&acmd, sizeof (acomodacoes), 1, original) == 1) {
        if (acmd.codigo == codigo_acomodacao) {
            // O registro com o código desejado foi encontrado e o número de ocupantes foi mudado
            acmd.ocupacao--;
            encontrado = 1;
        }

        // Escreva o registro (atualizado ou não) no arquivo temporário
        fwrite(&acmd, sizeof (acomodacoes), 1, temporario);
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Acomodação com código %d não encontrado.\n", codigo_acomodacao);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Acomodacoes.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Acomodacoes_temp.bin", "Acomodacoes.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos ocupantes feita com sucesso\n");
    return 0;
}


//Função para deletar os dados das acomodaçôes.
int deleta_acomodacoes_bin(int codigo_acomodacao) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Acomodacoes.bin", "rb");
    temporario = fopen("Acomodacoes_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    acomodacoes acmd;

    while (fread(&acmd, sizeof(acomodacoes), 1, original) == 1) {
        if (acmd.codigo == codigo_acomodacao) {
            // O registro com o código desejado foi encontrado e apaga.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&acmd, sizeof(acomodacoes), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Acomodação com código %d não encontrado.\n", codigo_acomodacao);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Acomodacoes.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Acomodacoes_temp.bin", "Acomodacoes.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Delete dos dados das acomodações feita com sucesso\n");
    return 0;
}


// Funçao que abre um arquivo binário para escrever e gravar dados da conta dos hospedes. 
int conta_hospede_cad_bin(conta_hospede conta){
    FILE *p;
    
    //comando que abre o arquivo para escrita
    p=fopen("Contas_hospede.bin","ab");
        
    //verifica se a criação do arquivo foi bem sucedida 
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    
    //comandos para a escrita em arquivos .bin 
    
    if(!feof(p)){
        fwrite(&conta,sizeof(conta_hospede),1,p);
    }else{
        printf("O arquivo se encontra cheio.");
    }
    
    
    fclose(p);
    
    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//Função para ler o binário da conta dos hospedes  e levar para a RAM.
int conta_hospede_ram_bin(conta_hospede *conta) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Contas_hospede.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&conta[i], sizeof (conta_hospede), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados da conta dos hospedes .
void dados_conta_hospede_bin(){
    FILE *p;
    
    //comando para a leitura de um arquivo .bin
    p=fopen("Contas_hospede.bin","rb");
    
    //verifica se existe o arquivo
    if(p == NULL){
        printf("Problemas na abertura do arquivo.bin");
       exit (1);
    }
    
    conta_hospede conta;
    //comandos para leitura em .bin 
    while (fread(&conta, sizeof(conta_hospede), 1, p) == 1) {
        
        printf("\n-------CONTA DO HOSPEDE-------\n\n");
        printf("Codigo da reserva: %d\n", conta.codigo_res);
        printf("Codigo do hospede: %d\n", conta.codigo_hos);
        printf("Valor devido: %f\n", conta.valor_devido);
        
        printf("\n\n");
    }
    
    fclose(p);
}

//Função que atualiza os dados da conta dos hospedes .
int atualiza_conta_hospede_bin(conta_hospede nova_conta, int codigo_hospede) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Contas_hospede.bin", "rb");
    temporario = fopen("Contas_hospede_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    conta_hospede cont;

    while (fread(&cont, sizeof(conta_hospede), 1, original) == 1) {
        if (cont.codigo_hos == codigo_hospede) {
            // O registro com o código desejado foi encontrado e substituido
            fwrite(&nova_conta, sizeof(conta_hospede), 1, temporario);
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&cont, sizeof(conta_hospede), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Conta do hospede %d não encontrado.\n", codigo_hospede);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Contas_hospede.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Contas_hospede_temp.bin", "Contas_hospede.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Atualização dos dados da conta feita com sucesso\n");
    return 1;
}

//Função que deleta os dados da conta dos hospedes.
int deleta_conta_hospede_bin( int codigo_hospede) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Contas_hospede.bin", "rb");
    temporario = fopen("Contas_hospede_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    conta_hospede cont;

    while (fread(&cont, sizeof(conta_hospede), 1, original) == 1) {
        if (cont.codigo_hos == codigo_hospede) {
            // O registro com o código desejado foi encontrado e apagado.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&cont, sizeof(conta_hospede), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Conta do hospede %d não encontrado.\n", codigo_hospede);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Contas_hospede.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Contas_hospede_temp.bin", "Contas_hospede.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Deleção da conta feita com sucesso.\n");
    return 0;
}


//funcao para adicionar valor no caixa bin
int adiciona_caixa_bin(float valor, int cod_hos, int controle) {
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    
    conta_receber caixa;
    
    caixa.codigo_hos = cod_hos;
    caixa.date.dia = tm.tm_mday;
    caixa.date.mes = tm.tm_mon + 1;
    caixa.date.ano = tm.tm_year + 1900;
    
    if (controle == 0) {
        
        caixa.valor_devido = +valor;
        
    } else if (controle == 1) {

        caixa.valor_devido = -valor;

    }
    
    FILE *p; 

        p = fopen("Caixa.bin", "ab");

        if (p == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }

        if (!feof(p)) {
            fwrite(&caixa, sizeof (conta_receber), 1, p);
        } else {
            printf("O arquivo se encontra cheio.");
        }

        fclose(p);
        printf("Conta cadastrado com sucesso.\n");
        return 0;
}

//funcao igual a de cima porem utilizida pra cadastrar o caixa na troca de txt pra bin que ja vem com as datas
int cadastrar_caixa_bin(conta_receber caixa){
    FILE *p;

    p = fopen("Caixa.bin", "ab");

    if (p == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }

    if (!feof(p)) {
        fwrite(&caixa, sizeof (conta_receber), 1, p);
    } else {
        printf("O arquivo se encontra cheio.");
    }

    fclose(p);
    printf("Caixa cadastrado com sucesso.\n");
    return 0;
}

//trazendo dados do caixa para memoria
int caixa_ram_bin(conta_receber *caixa) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Caixa.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0;

    while (fread(&caixa[i], sizeof (conta_receber), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//funcao para printar os valores do caixa
void dados_caixa_bin() {
   FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Caixa.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    conta_receber caixa;
    
    //comandos para leitura em .bin 
    while (fread(&caixa, sizeof (conta_receber), 1, p) == 1) {
        
        printf("Código: %d\n", caixa.codigo_hos);

        // Verifica se o valor é positivo ou negativo e imprime o sinal correspondente
        if (caixa.valor_devido >= 0) {
            printf("Valor: +%.2f\n", caixa.valor_devido);
        } else {
            printf("Valor: %.2f\n", caixa.valor_devido);
        }

        printf("Data: %d/%d/%d\n", caixa.date.dia, caixa.date.mes, caixa.date.ano);
    }

    fclose(p);
}



//funcao para adicionar no arquivo contas a receber quando alguem pagar no cartao
int adicionar_contas_a_receber_bin(data datas, int cod_hos, float valor) {
    FILE *p; 

    p = fopen("Contas_receber.bin", "ab");

    if (p == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    
    conta_receber conta_h;
    
    conta_h.codigo_hos = cod_hos;
    conta_h.valor_devido= valor;
    conta_h.date.dia=datas.dia;
    conta_h.date.mes=datas.mes;
    conta_h.date.ano=datas.ano;



    if (!feof(p)) {
        fwrite(&conta_h, sizeof (conta_receber), 1, p);
    } else {
        printf("O arquivo se encontra cheio.");
    }


    fclose(p);

    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//trazendo dados do caixa para memoria
int contas_a_receber_ram_bin(conta_receber *contasRAM) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Contas_receber.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0;

    while (fread(&contasRAM[i], sizeof (conta_receber), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função que deleta os dados da conta dos hospedes.
int deleta_conta_a_receber_bin(int codigo_hospede) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Contas_receber.bin", "rb");
    temporario = fopen("Contas_receber_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    conta_receber cont;

    while (fread(&cont, sizeof (conta_receber), 1, original) == 1) {
        if (cont.codigo_hos == codigo_hospede) {
            // O registro com o código desejado foi encontrado e apagado.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&cont, sizeof (conta_receber), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Conta do hospede %d não encontrado.\n", codigo_hospede);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Contas_receber.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Contas_receber_temp.bin", "Contas_receber.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Baixa da conta feita com sucesso.\n");
    return 0;
}
        
//Função para printar os valores das contas a receber
void dados_conta_a_receber_bin() {
   FILE *p;
   int i=0;
    //comando para a leitura de um arquivo .bin
    p = fopen("Contas_receber.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    conta_receber conta;
    
    //comandos para leitura em .bin 
    while (fread(&conta, sizeof (conta_receber), 1, p) == 1) {
        
        printf("Codigo da conta:%d\n", i);
        printf("Código do hóspede: %d\n", conta.codigo_hos);
        printf("Valor: +%.2f\n", conta.valor_devido);
        printf("Data: %d/%d/%d\n\n", conta.date.dia, conta.date.mes, conta.date.ano);

        i++;
    }

    fclose(p);
}



//funcao para adicionar no arquivo contas a receber quando alguem pagar no cartao
int adicionar_contas_a_pagar_bin(float valor, int vezes,int cod_for) {

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    valor = valor / vezes;

    for (int i = 0; i < vezes; i++) {
    // Adicionar 30 dias
    tm.tm_mday += 30;
    time_t newTime = mktime(&tm);

    // Extrair dia, mês e ano da nova data
    struct tm newTm = *localtime(&newTime);
    int newDay = newTm.tm_mday;
    int newMonth = newTm.tm_mon + 1; // tm_mon é base 0 (janeiro = 0)
    int newYear = newTm.tm_year + 1900;
    
    FILE *p;

    p = fopen("Contas_pagar.bin", "ab");

    if (p == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    
    conta_receber conta;
    
    conta.codigo_hos=cod_for;
    conta.valor_devido = valor;
    conta.date.dia = newDay;
    conta.date.mes = newMonth;
    conta.date.ano = newYear;

    if (!feof(p)) {
        fwrite(&conta, sizeof (conta_receber), 1, p);
    } else {
        printf("O arquivo se encontra cheio.");
    }


    fclose(p);
    }

    printf("Conta a pagar cadastrada com sucesso.\n");
    return 0;
}

//funcao igual a de cima porem utilizida pra cadastrar as contas na troca de txt pra bin que ja vem com todos dados prontos
int cadastrar_contas_a_pagar_bin(conta_receber conta){
    FILE *p;

    p = fopen("Contas_pagar.bin", "ab");

    if (p == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }


    if (!feof(p)) {
        fwrite(&conta, sizeof (conta_receber), 1, p);
    } else {
        printf("O arquivo se encontra cheio.");
    }


    fclose(p);
    printf("Conta a pagar cadastrada com sucesso.\n");
    return 0;
}

//trazendo dados do caixa para memoria
int contas_a_pagar_ram_bin(conta_receber *contasRAM) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Contas_pagar.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0;

    while (fread(&contasRAM[i], sizeof (conta_receber), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função que deleta os dados da conta dos hospedes.
int deleta_conta_a_pagar_bin(int codigo_conta) {
    int status = 0, i = 0;
    FILE *original, *temporario;

    original = fopen("Contas_receber.bin", "rb");
    temporario = fopen("Contas_receber_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    conta_receber cont;

    while (fread(&cont, sizeof (conta_receber), 1, original) == 1) {
        if ( i = codigo_conta) {
            
            status = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&cont, sizeof (conta_receber), 1, temporario);
        }
        i++;
    }

    fclose(original);
    fclose(temporario);

     if (status != 0) {
        printf("Erro na remoção do arquivo para dar baixa na conta.\n");
        exit(1);
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Contas_receber.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Contas_receber_temp.bin", "Contas_receber.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Baixa da conta feita com sucesso.\n");
    return 0;
}
        
//Função para printar os valores das contas a receber
void dados_conta_a_pagar_bin() {
   FILE *p;
   int i=0;
    //comando para a leitura de um arquivo .bin
    p = fopen("Contas_pagar.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    conta_receber conta;
    
    //comandos para leitura em .bin 
    while (fread(&conta, sizeof (conta_receber), 1, p) == 1) {
        
        printf("Codigo da conta:%d\n", i);
        printf("Codigo do fornecedor:%d\n",conta.codigo_hos);
        printf("Valor: +%.2f\n", conta.valor_devido);
        printf("Data: %d/%d/%d\n\n", conta.date.dia, conta.date.mes, conta.date.ano);

        i++;
    }

    fclose(p);
}


//funcao para cadastrar nota fiscal
int cadastrar_notafiscal_bin(NotaFiscal nota) {
    FILE *arquivo;

    // Abrir arquivo para escrita binária no modo de acrescentar (append)
    arquivo = fopen("Notas_fiscais.bin", "ab");

    if (arquivo == NULL) {
        printf("Problemas com o arquivo.\n");
        return 1;
    }

    // Escrever dados da NotaFiscal
    fwrite(&nota, sizeof (NotaFiscal), 1, arquivo);

    // Se há produtos, escrever os detalhes dos produtos
    if (nota.num_produtos > 0) {
        fwrite(nota.entra_prod, sizeof (entrada_produto), nota.num_produtos, arquivo);
    }

    fclose(arquivo);
    printf("Nota cadastrada com sucesso.\n");

    return 0;
}

//funcao para trazer notas fiscais para a memoria ram
int notasfiscais_ram_bin(NotaFiscal **notas) {
    FILE *arquivo;

    // Abrir arquivo para leitura binária
    arquivo = fopen("Notas_fiscais.bin", "rb");

    if (arquivo == NULL) {
        printf("Problemas com o arquivo.\n");
        return -1; // Código de erro indicando falha na abertura do arquivo
    }

    // Inicializar o número de notas fiscais
    int num_notas = 0;

    // Loop para contar o número de notas fiscais no arquivo
    while (1) {
        // Tentar ler uma nova nota fiscal
        NotaFiscal tempNota;

        // Tentar ler a próxima nota fiscal
        size_t result = fread(&tempNota, sizeof (NotaFiscal), 1, arquivo);

        if (result != 1) {
            // Se não conseguiu ler uma nota fiscal, sair do loop
            break;
        }

        // Alocar memória para os produtos desta nota fiscal
        tempNota.entra_prod = malloc(tempNota.num_produtos * sizeof (entrada_produto));

        if (tempNota.entra_prod == NULL) {
            perror("Erro ao alocar memória");
            fclose(arquivo);
            return -2; // Código de erro indicando falha na alocação de memória
        }

        // Tentar ler os detalhes dos produtos desta nota fiscal
        result = fread(tempNota.entra_prod, sizeof (entrada_produto), tempNota.num_produtos, arquivo);

        if (result != tempNota.num_produtos) {
            // Se não conseguiu ler todos os produtos, sair do loop
            break;
        }

        // Incrementar o número de notas fiscais lidas
        num_notas++;

        // Alocar memória para o array de notas fiscais
        *notas = realloc(*notas, num_notas * sizeof (NotaFiscal));

        // Copiar os dados lidos para o array de notas fiscais
        (*notas)[num_notas - 1] = tempNota;
    }
    /*
    for (int i = 0; i < num_notas; i++) {
        printf("Nota Fiscal %d:\n", i + 1);
        printf("Fornecedor: %s\n", (*notas)[i].fornecedor);
        printf("CNPJ: %s\n", (*notas)[i].cnpj);
        printf("Frete: %.2f\n", (*notas)[i].frete);
        printf("Imposto: %.2f\n", (*notas)[i].imposto);
        printf("Total: %.2f\n", (*notas)[i].total);
        printf("Número de Produtos: %d\n", (*notas)[i].num_produtos);

        // Imprimir detalhes dos produtos
        for (int j = 0; j < (*notas)[i].num_produtos; j++) {
            printf("Produto %d:\n", j + 1);
            printf("Nome: %s\n", (*notas)[i].entra_prod[j].nome);
            printf("Preço: %.2f\n", (*notas)[i].entra_prod[j].preco);
            printf("Quantidade: %d\n", (*notas)[i].entra_prod[j].quantidade);
            printf("Subtotal: %.2f\n", (*notas)[i].entra_prod[j].subtotal);
        }

        printf("\n");
    }
    */
    fclose(arquivo);

    // Retornar o número de notas fiscais lidas
    return num_notas;
}

//Função para ler e printar os dados das notas fiscais.
void dados_notasficais_bin() {
    FILE *arquivo;

    // Abrir arquivo para leitura binária
    arquivo = fopen("Notas_fiscais.bin", "rb");

    if (arquivo == NULL) {
        printf("Problemas com o arquivo.\n");
        return;
    }

    NotaFiscal nota;
    entrada_produto produto;

    while (fread(&nota, sizeof (NotaFiscal), 1, arquivo) == 1) {
        printf("----------DADOS DA NOTA FISCAL----------\n");
        printf("Fornecedor: %s\n", nota.fornecedor);
        printf("CNPJ: %s\n", nota.cnpj);
        printf("Frete: %.2f\n", nota.frete);
        printf("Imposto: %.2f\n", nota.imposto);
        printf("Total da Nota: %.2f\n", nota.total);
        printf("Número de Produtos: %d\n", nota.num_produtos);

        // Imprimir dados dos produtos
        for (int i = 0; i < nota.num_produtos; i++) {
            if (fread(&produto, sizeof (entrada_produto), 1, arquivo) != 1) {
                printf("Erro ao ler dados do produto.\n");
                fclose(arquivo);
                return;
            }
            printf("Produto %d:\n", i + 1);
            printf("Nome: %s\n", produto.nome);
            printf("Preço: %.2f\n", produto.preco);
            printf("Quantidade: %d\n", produto.quantidade);
            printf("Total do Produto: %.2f\n", produto.subtotal);
        }
        printf("\n");
    }

    fclose(arquivo);
}


// Função para cadastrar venda do produto em um arquivo binário
int cadastrar_venda_bin(vendas venda) {
    FILE *p;

    p = fopen("Vendas.bin", "ab");

    if (p == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }


    if (!feof(p)) {
        fwrite(&venda, sizeof (vendas), 1, p);
    } else {
        printf("O arquivo se encontra cheio.");
    }


    fclose(p);
    printf("Notinha cadastrada com sucesso.\n");
    return 0;
}

//trazendo dados do caixa para memoria
int venda_ram_bin(vendas *vendasRAM) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Vendas.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0;

    while (fread(&vendasRAM[i], sizeof (vendas), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para printar os valores das contas a receber
void dados_venda_bin() {
    FILE *p;
    int i = 0;
    //comando para a leitura de um arquivo .bin
    p = fopen("Vendas.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    vendas vend;

    //comandos para leitura em .bin 
    while (fread(&vend, sizeof (vendas), 1, p) == 1) {

        printf("Quantidade de produtos: %d\n", vend.qtd);
        printf("Codigo do hospede:%d\n", vend.cod_hos);
        printf("Codigo do produto:%d\n", vend.cod_prod);
        printf("Valor: %.2f\n", vend.valor);
        printf("Tipo de pagamento: %d\n", vend.pagamento);
    }

    fclose(p);
}



//funcao para listar os hospedes 
int listagem_hospede_bin(int *codigo, int *listagem, char *sexo, int opcao) {
    int qtd_hos, contador = 0;

    qtd_hos = qtd_itens_bin("Hospedes.bin", sizeof (hospedes));
    hospedes *hospedesRAM = malloc(qtd_hos * sizeof (hospedes));
    hospede_ram_bin(hospedesRAM);

    hospedes *hospedesAUX;


    if (listagem[0] != 0) {
        hospedesAUX = malloc(qtd_hos * sizeof (hospedes));
        for (int i = 0; i < qtd_hos; i++) {
            if (codigo[0] <= hospedesRAM[i].codigo && hospedesRAM[i].codigo <= codigo[1]) {
                hospedesAUX[contador] = hospedesRAM[i];
                contador++;
            }
        }
        if (contador == 0) {
            printf("\nNenhum hóspede com esse intervalo de codigo.\n");
            return 0;
        }
        //realocando o hospedes ram para ficar do tamanho da quantidadede de hospedes filtrador
        hospedesRAM = realloc(hospedesRAM, contador * sizeof (hospedes));

        //copiando os dados do aux para ram para que caso utilizar ma proxima filtragem ou nao
        memcpy(hospedesRAM, hospedesAUX, contador * sizeof (hospedes));

        //igualando qtd de hospedes ao contador para ficar com a nova qtd de hospedes
        qtd_hos = contador;
        free(hospedesAUX);
    }


    if (listagem[1] != 0) {
        hospedesAUX = malloc(qtd_hos * sizeof (hospedes));
        contador = 0;
        for (int i = 0; i < qtd_hos; i++) {
            if (strcmp(sexo, hospedesRAM[i].sexo) == 0) {
                hospedesAUX[contador] = hospedesRAM[i];
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
        hospedesRAM = realloc(hospedesRAM, contador * sizeof (hospedes));

        //copiando os dados do aux para ram para que caso utilizar ma proxima filtragem ou nao
        memcpy(hospedesRAM, hospedesAUX, contador * sizeof (hospedes));

        //igualando qtd de hospedes ao contador para ficar com a nova qtd de hospedes
        qtd_hos = contador;
        free(hospedesAUX);
    }

    if (opcao == 1) {
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
    } else if (opcao == 2) {
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("listagem_hospedes.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for (int i = 0; i < qtd_hos; i++) {
            fprintf(P, "%d;%s;%s;%s;%s;%s;%s;%d;%s;%s;%s;%s;%s;%d;%d;%d;",
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

//funcao para listar a acomodacao
int listagem_acomodacoes_bin(int *codigo, int *listagem, int categoria, int opcao, data_chek_in_out datas) {
    int qtd_aco;

    qtd_aco = qtd_itens_bin("Acomodacoes.bin", sizeof (acomodacoes));
    acomodacoes *acomodacoesRAM = malloc(qtd_aco * sizeof (acomodacoes));
    acomodacoes_ram_bin(acomodacoesRAM);

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
        if (contador == 0 && listagem[0] != 0) {
            printf("\nNenhuma acomodação encontrada para essa categoria e intervalo de codigo.\n");
            return;
        } else if (contador == 0) {
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
    if (listagem[2] != 0) {
        int contador = 0, qtd_res, existe;
        existe = arquivo_existe_txt("reservas.txt");


        if (existe == 1) {
            qtd_res = contadorlinhas_txt("reservas.txt");
            qtd_res = qtd_res / 16;
            reservas reservaRAM[qtd_res];
            reservas_ram_txt(qtd_res, reservaRAM);

            int acomodacaoINDIS[qtd_res], contador_indis = 0;
            acomodacoesAUX = malloc((qtd_aco + qtd_res) * sizeof (acomodacoes));

            if (qtd_res > 0) {
                for (int i = 0; i < qtd_aco; i++) {
                    if (acomodacoesRAM[i].ocupacao == 0) {
                        acomodacoesAUX[contador] = acomodacoesRAM[i];
                        contador++;
                    } else {
                        for (int j = 0; j < qtd_res; j++) {
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
                    if (acomodacaoDisponivel == 1 && acomodacoesRAM[i].ocupacao != 0) {
                        acomodacoesAUX[contador] = acomodacoesRAM[i];
                        contador++;
                    }
                }
            }
            if (contador == 0) {
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

    if (opcao == 1) {
        for (int i = 0; i < qtd_aco; i++) {
            printf("\n------------------------------\n");
            printf("Código: %d\n", acomodacoesRAM[i].codigo);
            printf("Descrição: %s\n", acomodacoesRAM[i].descricao);
            printf("Facilidades: %s\n", acomodacoesRAM[i].facilidades);
            printf("Categoria: %d\n", acomodacoesRAM[i].categoria);
            printf("Diárias: %d\n", acomodacoesRAM[i].diarias);
            printf("Lucro: R$%.2f\n", acomodacoesRAM[i].lucro);
            printf("Ocupação: %d\n", acomodacoesRAM[i].ocupacao);
            printf("\n");
        }
    } else if (opcao == 2) {
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("listagem_acomodacoes.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for (int i = 0; i < qtd_aco; i++) {
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
        return 0;
    }

}

//funcao para filtra e printar ou salvar a listagem de reservas
int listagem_reservas_bin(int *listagem, int *codigo_hospede, int *codigo_acomodacao, data_chek_in_out datas, int opcao) {
    int qtd_res;


    qtd_res = qtd_itens_bin("Reservas.bin", sizeof (reservas));
    reservas *reservasRAM = malloc(qtd_res * sizeof (reservas));
    reservas_ram_bin(reservasRAM);

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
int listagem_movimento_acomodacoes_bin(int *listagem, int *codigo, int diarias, float lucro, int opcao) {
    int qtd_aco;

    qtd_aco = qtd_itens_bin("Acomodacoes.bin", sizeof (acomodacoes));
    acomodacoes *movimentacaoRAM = malloc(qtd_aco * sizeof (acomodacoes));
    acomodacoes_ram_bin(movimentacaoRAM);

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

//funcao para listar a acomodacao
int listagem_produtos_bin(int *codigo, int listagem, int opcao) {
    int qtd_prod;

    qtd_prod = qtd_itens_bin("Produtos.bin", sizeof (produtos));
    produtos *produtosRAM = malloc(qtd_prod * sizeof (produtos));
    produtos_ram_bin(produtosRAM);

    produtos *produtosAUX;

    if (listagem != 0) {
        produtosAUX = malloc(qtd_prod * sizeof (produtos));
        int contador = 0;
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
int listagem_estoque_minimo_bin(int *codigo, int listagem, int opcao) {
    int qtd_prod, contador = 0;

    qtd_prod = qtd_itens_bin("Produtos.bin", sizeof (produtos));
    produtos *produtosRAM = malloc(qtd_prod * sizeof (produtos));
    produtos_ram_bin(produtosRAM);

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
    contador = 0;
    if (opcao == 1) {
        for (int i = 0; i < qtd_prod; i++) {
            if (produtosRAM[i].estoque <= produtosRAM[i].estoque_min) {
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
        if (contador == 0) {
            printf("Nenhum produto em estoque minimo.\n");
            return 0;
        }
    } else if (opcao == 2) {
        contador = 0;
        for (int i = 0; i < qtd_prod; i++) {
            if (produtosRAM[i].estoque <= produtosRAM[i].estoque_min) {
                contador++;
            }
        }
        if (contador == 0) {
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
int listagem_vendas_bin(int pagamento, int opcao, int listagem) {
    int qtd_vendas;
    int contador = 0;

    qtd_vendas = qtd_itens_bin("Vendas.bin", sizeof (vendas));
    vendas *vendasRAM = malloc(qtd_vendas * sizeof (vendas));
    venda_ram_bin(vendasRAM);

    vendas *vendasAUX;

    if (listagem == 1) {
        if (pagamento == 1) {
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

//funcao para filtra e printar ou salvar a listagem de contas a receber
int listagem_contas_receber_bin(int *listagem, int *codigo, data inicio, data fim, int opcao) {
    int qtd_contas;
    int contador = 0;


    qtd_contas = qtd_itens_bin("Contas_receber.bin", sizeof (conta_receber));
    conta_receber *contasRAM = malloc(qtd_contas * sizeof (conta_receber));
    contas_a_receber_ram_bin(contasRAM);

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
int listagem_contas_pagar_bin(int *listagem, int *codigo, data inicio, data fim, int opcao) {
    int qtd_contas;
    int contador = 0;


    qtd_contas = qtd_itens_bin("Contas_pagar.bin", sizeof (conta_receber));
    conta_receber *contasRAM = malloc(qtd_contas * sizeof (conta_receber));
    contas_a_pagar_ram_bin(contasRAM);

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
void listagem_caixa_bin(data inicio, data fim, int listagem, int opcao) {
    int qtd_caixa;
    int contador = 0;

    qtd_caixa = qtd_itens_bin("Caixa.bin", sizeof (conta_receber));
    conta_receber *caixaRAM = malloc(qtd_caixa * sizeof (conta_receber));
    caixa_ram_bin(caixaRAM);

    conta_receber *caixaAUX = NULL;

    if (listagem == 1) {
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

    if (opcao == 1) {
        // Imprimindo as informações
        for (int i = 0; i < qtd_caixa; i++) {
            printf("\n------------------------------\n");
            printf("Código:%d\n", caixaRAM[i].codigo_hos);
            printf("Valor: %.2f\n", caixaRAM[i].valor_devido);
            printf("Data de Recebimento: %02d/%02d/%04d\n", caixaRAM[i].date.dia, caixaRAM[i].date.mes, caixaRAM[i].date.ano);
            printf("\n");
        }
    } else if (opcao == 2) {
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





//exportar dados
int exportar_dados_bin_xml(int *exportar) {

    FILE *arquivoXML; //Ponteiro do arquivo BIN;
    arquivoXML = fopen("exportar.xml", "w");


    fprintf(arquivoXML, "<dados>\n");


    if (exportar[0] != 0) {
        cad_hotel hotelRAM[1];
        hotel_ram_bin(hotelRAM);

        fprintf(arquivoXML, "    <tabela=hotel>\n");
        fprintf(arquivoXML, "        <registro>\n");
        fprintf(arquivoXML, "            <nome_fantasia>%s</nome_fantasia>\n", hotelRAM[0].nome_fantasia);
        fprintf(arquivoXML, "            <razao_social>%s</razao_social>\n", hotelRAM[0].razao_social);
        fprintf(arquivoXML, "            <inscricao_estadual>%s</inscricao_estadual>\n", hotelRAM[0].inscricao_estadual);
        fprintf(arquivoXML, "            <cnpj>%s</cnpj>\n", hotelRAM[0].cnpj);
        fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", hotelRAM[0].endereco.estado, hotelRAM[0].endereco.cidade, hotelRAM[0].endereco.bairro, hotelRAM[0].endereco.cep, hotelRAM[0].endereco.rua, hotelRAM[0].endereco.numero);
        fprintf(arquivoXML, "            <telefone>%s</telefone>\n", hotelRAM[0].telefone);
        fprintf(arquivoXML, "            <email>%s</email>\n", hotelRAM[0].email);
        fprintf(arquivoXML, "            <nome_responsavel>%s</nome_responsavel>\n", hotelRAM[0].nome_responsavel);
        fprintf(arquivoXML, "            <telefone_responsavel>%s</telefone_responsavel>\n", hotelRAM[0].telefone_responsavel);
        fprintf(arquivoXML, "            <checkin>%d:%d</checkin>\n", hotelRAM[0].horario_checkin.hora, hotelRAM[0].horario_checkin.minutos);
        fprintf(arquivoXML, "            <checkout>%d:%d</checkout>\n", hotelRAM[0].horario_checkout.hora, hotelRAM[0].horario_checkout.minutos);
        fprintf(arquivoXML, "            <mlpv>%f</mlpv>\n", hotelRAM[0].mlpv);
        fprintf(arquivoXML, "        </registro>\n");
        fprintf(arquivoXML, "    </tabela=hotel>\n");
    }

    if (exportar[1] != 0) {
        int qtd_hos;

        qtd_hos = qtd_itens_bin("Hospedes.bin", sizeof (hospedes));
        hospedes hospedesRAM[qtd_hos];
        hospede_ram_bin(hospedesRAM);

        fprintf(arquivoXML, "    <tabela=hospedes>\n");
        for (int i = 0; i < qtd_hos; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", hospedesRAM[i].codigo);
            fprintf(arquivoXML, "            <nome>%s</nome>\n", hospedesRAM[i].nome);
            fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", hospedesRAM[i].endereco_hospede.estado, hospedesRAM[i].endereco_hospede.cidade, hospedesRAM[i].endereco_hospede.bairro, hospedesRAM[i].endereco_hospede.cep, hospedesRAM[i].endereco_hospede.rua, hospedesRAM[i].endereco_hospede.numero);
            fprintf(arquivoXML, "            <cpf>%s</cpf>\n", hospedesRAM[i].cpf);
            fprintf(arquivoXML, "            <telefone>%s</telefone>\n", hospedesRAM[i].telefone);
            fprintf(arquivoXML, "            <email>%s</email>\n", hospedesRAM[i].email);
            fprintf(arquivoXML, "            <sexo>%s</sexo>\n", hospedesRAM[i].sexo);
            fprintf(arquivoXML, "            <est_civil>%s</est_civil>\n", hospedesRAM[i].estado_civil);
            fprintf(arquivoXML, "            <data_nascimento>%d/%d/%d</data_nascimento>\n", hospedesRAM[i].data_nacimento.dia, hospedesRAM[i].data_nacimento.mes, hospedesRAM[i].data_nacimento.ano);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=hospedes>\n");
    }
    if (exportar[2] != 0) {
        int qtd_aco;

        qtd_aco = qtd_itens_bin("Acomodacoes.bin", sizeof (acomodacoes));
        acomodacoes acomodacoesRAM[qtd_aco];
        acomodacoes_ram_bin(acomodacoesRAM);

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

    if (exportar[3] != 0) {
        int qtd_cat;

        qtd_cat = qtd_itens_bin("Categorias.bin", sizeof (categoria_acomodacao));
        categoria_acomodacao categoriasRAM[qtd_cat];
        categorias_ram_bin(categoriasRAM);

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


    if (exportar[4] != 0) {
        int qtd_prod;

        qtd_prod = qtd_itens_bin("Produtos.bin", sizeof (produtos));
        produtos produtosRAM[qtd_prod];
        produtos_ram_bin(produtosRAM);

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
    if (exportar[5] != 0) {
        int qtd_for;

        qtd_for = qtd_itens_bin("Fornecedores.bin", sizeof (fornecedores));
        fornecedores fornecedoresRAM[qtd_for];
        fornecedores_ram_bin(fornecedoresRAM);

        fprintf(arquivoXML, "    <tabela=fornecedores>\n");

        for (int i = 0; i < qtd_for; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", fornecedoresRAM[i].codigo);
            fprintf(arquivoXML, "            <nome_fantasia>%s</nome_fantasia>\n", fornecedoresRAM[i].nome_fantasia);
            fprintf(arquivoXML, "            <razao_social>%s</razao_social>\n", fornecedoresRAM[i].razao_social);
            fprintf(arquivoXML, "            <inscricao_estadual>%s</inscricao_estadual>\n", fornecedoresRAM[i].inscricao_estadual);
            fprintf(arquivoXML, "            <cnpj>%s</cnpj>\n", fornecedoresRAM[i].cnpj);
            fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", fornecedoresRAM[i].endereco.estado, fornecedoresRAM[i].endereco.cidade, fornecedoresRAM[i].endereco.bairro, fornecedoresRAM[i].endereco.cep, fornecedoresRAM[i].endereco.rua, fornecedoresRAM[i].endereco.numero);
            fprintf(arquivoXML, "            <telefone>%s</telefone>\n", fornecedoresRAM[i].telefone);
            fprintf(arquivoXML, "            <email>%s</email>\n", fornecedoresRAM[i].email);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=fornecedores>\n");
    }
    if (exportar[6] != 0) {
        int qtd_ope;

        qtd_ope = qtd_itens_bin("Operadores.bin", sizeof (OPsistema));
        OPsistema operadoresRAM[qtd_ope];
        operadores_ram_bin(operadoresRAM);

        fprintf(arquivoXML, "    <tabela=operadores>\n");

        for (int i = 0; i < qtd_ope; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", operadoresRAM[i].codigo);
            fprintf(arquivoXML, "            <nome>%s</nome>\n", operadoresRAM[i].nome);
            fprintf(arquivoXML, "            <usuario>%s</usuario>\n", operadoresRAM[i].usuario);
            fprintf(arquivoXML, "            <senha>%d</senha>\n", operadoresRAM[i].senha);
            fprintf(arquivoXML, "            <permissoes>%d;%d;%d;%d;%d</permissoes>\n", operadoresRAM[i].permissoes.cadastros, operadoresRAM[i].permissoes.reservas, operadoresRAM[i].permissoes.transacoes, operadoresRAM[i].permissoes.feedback, operadoresRAM[i].permissoes.im_exportacao);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=operadores>\n");

    }
    fprintf(arquivoXML, "</dados>\n");


    fclose(arquivoXML);
    printf("Dados exportados com sucesso.\n");
    return 0;

}

//funcao para importar dados do hotel de um xml
int importar_dados_hotel_bin_xml(char *arquivo) {
    char *buffer = trazer_xml_buffer(arquivo);

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
    dados_hotel.mlpv = atof(&auxMLPV);


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

    hotel_cad_bin(dados_hotel);


    return 0;
}

//funcao para importar dados dos hospedes
int importar_dados_hospedes_bin_xml(char *arquivo) {
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
                sscanf(auxDATA, "%d/%d/%d", &dados_hospedes[i].data_nacimento.dia, &dados_hospedes[i].data_nacimento.mes, &dados_hospedes[i].data_nacimento.ano);



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

        deleta_arquivo("Hospedes.bin");
        for (int i = 0; i < contador_registros; i++) {

            hospede_cad_bin(dados_hospedes[i]);
        }
    } else {
        printf("Tags da tabela 'hospedes' não encontradas ou conteúdo vazio.\n");
    }
}

//funcao para importar dados das acomodacoes
int importar_dados_acomodacoes_bin_xml(char *arquivo) {
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
        char auxCod[10], auxCategoria[10], auxOcupacao[10],auxLucro[10],auxDiarias[10];

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
        deleta_arquivo("Acomodacoes.bin");
        for (int i = 0; i < contador_registros; i++) {
            acomodacoes_cad_bin(dados_acomodacoes[i]);
        }

    } else {
        printf("Tags da tabela 'acomodacoes' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados das categorias de acomodacoes
int importar_dados_categoria_acomodacao_bin_xml(char *arquivo) {
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
        char auxCod[10], auxValor[10];
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

        deleta_arquivo("Categorias.bin");
        for (int i = 0; i < contador_registros; i++) {
            categoria_cad_bin(dados_categorias[i]);
        }


    } else {
        printf("Tags da tabela 'categoria_acomodacao' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados de produtos
int importar_dados_produtos_bin_xml(char *arquivo) {
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
        char auxCod[10], auxCusto[10], auxVenda[10];
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
        deleta_arquivo("Produtos.bin");
        for (int i = 0; i < contador_registros; i++) {
            produtos_cad_bin(dados_produtos[i]);
        }

    } else {
        printf("Tags da tabela 'produtos' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados dos fornecedores
int importar_dados_fornecedores_bin_xml(char *arquivo) {
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

        deleta_arquivo("Fornecedores.bin");
        for (int i = 0; i < contador_registros; i++) {
            fornecedores_cad_bin(dados_fornecedores[i]);
        }
    } else {
        printf("Tags da tabela 'fornecedores' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados dos operadores
int importar_dados_operadores_bin_xml(char *arquivo) {
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
        char auxCod[10], auxSen[20];
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

        deleta_arquivo("Operadores.bin");
        for (int i = 0; i < contador_registros; i++) {
            operadores_cad_bin(dados_operadores[i]);
        }
    } else {
        printf("Tags da tabela 'operadores' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}
