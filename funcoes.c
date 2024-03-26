#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivosTXT.h"
#include "reservasTXT.h"
#include "Structs.h"
#include "ArquivosBin.h"
#include "ReservasBin.h"
#include "menu.h"

//procura codigo operador no binario
int procura_operador_bin( int codigo_operador){
    int encontrado = 0;
    FILE *p;

    p = fopen("Operadores.bin", "rb");

    if (p == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    OPsistema operd;

    while (fread(&operd, sizeof(OPsistema), 1, p) == 1) {
        if (operd.codigo == codigo_operador) {
            // O registro com o código desejado foi encontrado 
            encontrado = 1;
        } 
    }
    
    fclose(p);

    if (encontrado == 0) {
        printf("Código %d disponíveis.\n", codigo_operador);
        return 0;
    }else{
         printf("Operador encontrado.\n\n");
    }
    return 1;
}

//procura codigo hospede no binario
int procura_hospede_bin( int codigo_hospede){
    int encontrado = 0;
    FILE *p;

    p = fopen("Hospedes.bin", "rb");

    if (p == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    hospedes hspd;

    while (fread(&hspd, sizeof(hospedes), 1, p) == 1) {
        if (hspd.codigo == codigo_hospede) {
            // O registro com o código desejado foi encontrado 
            encontrado = 1;
        } 
    }
    
    fclose(p);

    if (encontrado == 0) {
        printf("Código %d disponíveis.\n", codigo_hospede);
        return 0;
    }else{
         printf("Hospede encontrado.\n\n");
    }
    return 1;
}

//procura codigo produto no binario
int procura_produto_bin( int codigo_produto){
    int encontrado = 0;
    FILE *p;

    p = fopen("Produtos.bin", "rb");

    if (p == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    produtos prdt;

    while (fread(&prdt, sizeof(produtos), 1, p) == 1) {
        if (prdt.codigo == codigo_produto) {
            // O registro com o código desejado foi encontrado 
            encontrado = 1;
        } 
    }
    
    fclose(p);

    if (encontrado == 0) {
        printf("Código %d disponíveis.\n", codigo_produto);
        return 0;
    }else{
         printf("Produto encontrado.\n\n");
    }
    return 1;
}

//procura codigo fornecedor no binario
int procura_fornecedor_bin( int codigo_fornecedor){
    int encontrado = 0;
    FILE *p;

    p = fopen("Fornecedores.bin", "rb");

    if (p == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    fornecedores frnc;

    while (fread(&frnc, sizeof(fornecedores), 1, p) == 1) {
        if (frnc.codigo == codigo_fornecedor) {
            // O registro com o código desejado foi encontrado 
            encontrado = 1;
        } 
    }
    
    fclose(p);

    if (encontrado == 0) {
        printf("Código %d disponíveis.\n", codigo_fornecedor);
        return 0;
    }else{
         printf("Fornecedor encontrado.\n\n");
    }
    return 1;
}

//procura codigo categoria no binario
int procura_categoria_bin( int codigo_categorias){
    int encontrado = 0;
    FILE *p;

    p = fopen("Categorias.bin", "rb");

    if (p == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    categoria_acomodacao categ;

    while (fread(&categ, sizeof(categoria_acomodacao), 1, p) == 1) {
        if (categ.codigo == codigo_categorias) {
            // O registro com o código desejado foi encontrado 
            encontrado = 1;
        } 
    }
    
    fclose(p);

    if (encontrado == 0) {
        printf("Código %d disponíveis.\n", codigo_categorias);
        return 0;
    }else{
         printf("Categoria encontrado.\n\n");
    }
    return 1;
}

//procura codigo acomodacao no binario
int procura_acomodacao_bin( int codigo_acomodacao){
    int encontrado = 0;
    FILE *p;

    p = fopen("Acomodacoes.bin", "rb");

    if (p == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    acomodacoes acmd;

    while (fread(&acmd, sizeof(acomodacoes), 1, p) == 1) {
        if (acmd.codigo == codigo_acomodacao) {
            // O registro com o código desejado foi encontrado 
            encontrado = 1;
        } 
    }
    
    fclose(p);

    if (encontrado == 0) {
        printf("Código %d disponíveis.\n", codigo_acomodacao);
        return 0;
    }else{
         printf("Acomodação encontrado.\n\n");
    }
    return 1;
}

//procura codigo reserva no binario
int procura_reserva_bin( int codigo_reserva){
    int encontrado = 0;
    FILE *p;

    p = fopen("Reservas.bin", "rb");

    if (p == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    reservas reserv;

    while (fread(&reserv, sizeof(reservas), 1, p) == 1) {
        if (reserv.codigo_res == codigo_reserva ) {
            // O registro com o código desejado foi encontrado 
            encontrado = 1;
        } 
    }
    
    fclose(p);

    if (encontrado == 0) {
        printf("Código %d disponíveis.\n", codigo_reserva);
        return 0;
    }else{
         printf("Reserva encontrado.\n\n");
    }
    return 1;
}

//retorna a quantidade de acomodações com 
int qtd_itens_bin(const char *nome_arquivo, size_t tamanho_registro) {
    FILE *p = fopen(nome_arquivo, "rb");
    long tamanho_arquivo;
    int qtd_itens;

    if (p == NULL) {
        printf("Erro na abertura de arquivo: %s\n", nome_arquivo);
        exit (1); 
    }

    // comando usado para posicionar o ponteiro no final do arquivo, para que possa obter o tamanho total do arquivo usando ftell.
    fseek(p, 0, SEEK_END);
    
    // Recebe o tamanho do arquivo
    tamanho_arquivo = ftell(p);

    fclose(p);

    if (tamanho_arquivo == -1) {
        printf("Erro ao obter o tamanho do arquivo: %s\n", nome_arquivo);
        return 0; 
    }
    
    qtd_itens = tamanho_arquivo / tamanho_registro;
    
    return qtd_itens;
}

//função para ferificar se existe arquivo
int arquivo_existe_bin(char *NomeArquivo){
    
    FILE *arquivo;
    
    if(arquivo = fopen(NomeArquivo, "rb")){
        fclose(arquivo);
        return 1;
    }
    
    return 0;
}

//verifica quais meses tem 31 dias e se o fevereiro tem 29
int diasNoMes(int mes, int ano) {
    if (mes < 1 || mes > 12) {
        return -1; // Mês inválido
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica se o mês é fevereiro e se o ano é bissexto
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) {
        return 29;
    }

    return diasNoMes[mes];
}

//verifica se o ano é bissexto
int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

//funcao para verificar se a data é valida
int data_atual(data_chek_in_out datas) {
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    if (datas.dia_in <= diasNoMes(datas.mes_in, datas.ano_in) &&
            datas.mes_in <= 12 &&
            datas.dia_out <= diasNoMes(datas.mes_out, datas.ano_out) &&
            datas.mes_out <= 12) {

        if (datas.ano_in < datas.ano_out ||
                (datas.ano_in == datas.ano_out && datas.mes_in < datas.mes_out) ||
                (datas.ano_in == datas.ano_out && datas.mes_in == datas.mes_out && datas.dia_in <= datas.dia_out)) {

            if (tm.tm_year + 1900 <= datas.ano_in) {
                return 0;
            } else if (tm.tm_mon + 1 <= datas.mes_in) {
                return 0;
            } else if (tm.tm_mday <= datas.dia_in) {
                return 0;
            }
        }
    }

    return 1;
}

//funcao para verificar se o login foi feito certo
int verifica_login(int cod_op,int senha, OPsistema *ramOP,int quantidade){

    for(int i=0;i<quantidade;i++){
        if(cod_op==ramOP[i].codigo && senha==ramOP[i].senha){
            return i;
        }
    }
    return -1;
}

//verifica se o arquivo txt  ja existe 
int arquivo_existe_txt(char *filename) {

    FILE *file;
    if (file = fopen(filename, "r")) {
        fclose(file);
        return 1;

    }
    return 0;
}

//funçao para contar linhas de um arquivo txt
int contadorlinhas_txt(char *arquivo) {
    int linhas = 0;
    char aux;
    FILE *P = fopen(arquivo, "r");
    if (P == NULL) {
        printf("Falha na abertura do arquivo");
        return -1;

    }
    do {
        aux = fgetc(P);
        if (aux == '\n') {
            linhas++;
        }

    } while (aux != EOF);
    fclose(P);
    return linhas;
}

//funcao para deletar qualquer arquivo
int deleta_arquivo(char *arquivo){
    int status;
    status = remove(arquivo);

    if (status != 0) {
        printf("O arquivo não existe.\n");
    }
}

// Função para calcular a diferença em dias entre duas datas, considerando anos bissextos
int contarDias(data_chek_in_out datas) {
    // Definir as estruturas tm para as datas de entrada e saída
    struct tm entrada = {.tm_year = datas.ano_in - 1900, .tm_mon = datas.mes_in - 1, .tm_mday = datas.dia_in};
    struct tm saida = {.tm_year = datas.ano_out - 1900, .tm_mon = datas.mes_out - 1, .tm_mday = datas.dia_out};

    // Converter as estruturas tm para o formato de tempo
    time_t entradaTime = mktime(&entrada);
    time_t saidaTime = mktime(&saida);

    // Calcular a diferença em segundos entre as duas datas
    time_t diferenca = difftime(saidaTime, entradaTime);

    // Converter a diferença de segundos para dias
    int dias = diferenca / (60 * 60 * 24);

    // Corrigir a contagem de dias para levar em conta anos bissextos
    for (int ano = datas.ano_in; ano <= datas.ano_out; ano++) {
        if (ehBissexto(ano)) {
            struct tm bissexto = {.tm_year = ano - 1900, .tm_mon = 1, .tm_mday = 29};
            time_t bissextoTime = mktime(&bissexto);
            if (entradaTime <= bissextoTime && bissextoTime < saidaTime) {
                dias--;
            }
        }
    }
    
  
    return dias;
}

//funcao para calcular o saldo disponivel do caixa
float calcula_saldo_caixa(int qtd_caixa,conta_receber *caixaRAM){
    float saldo=0;
    for(int i=0;i<qtd_caixa;i++){
        saldo+=caixaRAM[i].valor_devido;
    }
    return saldo;
}


//funcao que pega dados dos arquivos binarios e passa para o arquivo txt
int muda_arquivo_bin_p_txt(){
    int existe,quantidade;
    
    //traz operadores para ram e salva em txt e apaga o arquivo bin
    quantidade=qtd_itens_bin("Operadores.bin",sizeof (OPsistema));
    OPsistema operadoresRAM[quantidade];
    operadores_ram_bin(operadoresRAM);
    for(int i=0;i<quantidade;i++){
        cadastro_operadores_txt(operadoresRAM[i]);
    }
    deleta_arquivo("Operadores.bin");
    
    //traz Hotel para ram e salva em txt e apaga o arquivo bin
    existe=arquivo_existe_bin("Hotel.bin");
    if(existe==1){
        cad_hotel hotelRAM[1];
        //trazendo hotel pra memoria
        hotel_ram_bin(hotelRAM);
        //passando o hotel para o arquivo binario
        cadastro_hotel_txt(hotelRAM[0]);
        //deletando o arquivo TXT para ficar somente o binario
        deleta_arquivo("Hotel.bin");
    }
    
    //traz Hospedes para ram e salva em txt e apaga o arquivo bin
    existe=arquivo_existe_bin("Hospedes.bin");
    if(existe==1){
        quantidade=qtd_itens_bin("Hospedes.bin",sizeof (hospedes));
        hospedes hospedesRAM[quantidade];
        hospede_ram_bin(hospedesRAM);
        for(int i=0;i<quantidade;i++){
            cadastro_hospedes_txt(hospedesRAM[i]);
        }
        deleta_arquivo("Hospedes.bin");
    }
    
    //traz Produtos para ram e salva em txt e apaga o arquivo bin
    existe=arquivo_existe_bin("Produtos.bin");
    if(existe==1){
        quantidade=qtd_itens_bin("Produtos.bin",sizeof (produtos));
        produtos produtosRAM[quantidade];
        produtos_ram_bin(produtosRAM);
        for(int i=0;i<quantidade;i++){
            cadastro_produtos_txt(produtosRAM[i]);
        }
        deleta_arquivo("Produtos.bin");
    }
    
    //traz Fornecedores para ram e salva em txt e apaga o arquivo bin
    existe=arquivo_existe_bin("Fornecedores.bin");
    if(existe==1){
        quantidade=qtd_itens_bin("Fornecedores.bin",sizeof (fornecedores));
        fornecedores fornecedoresRAM[quantidade];
        fornecedores_ram_bin(fornecedoresRAM);
        for(int i=0;i<quantidade;i++){
            cadastro_fornecedor_txt(fornecedoresRAM[i]);
        }
        deleta_arquivo("Fornecedores.bin");
    }
    
    //traz Categorias para ram e salva em txt e apaga o arquivo bin
    existe = arquivo_existe_bin("Categorias.bin");
    if (existe == 1) {
        quantidade = qtd_itens_bin("Categorias.bin", sizeof (categoria_acomodacao));
        categoria_acomodacao categoriasRAM[quantidade];
        categorias_ram_bin(categoriasRAM);
        for (int i = 0; i < quantidade; i++) {
            cadastro_categoria_txt(categoriasRAM[i]);
        }
        deleta_arquivo("Categorias.bin");
    }
    
    //traz Acomodacoes para ram e salva em txt e apaga o arquivo bin
    existe = arquivo_existe_bin("Acomodacoes.bin");
    if (existe == 1) {
        quantidade = qtd_itens_bin("Acomodacoes.bin", sizeof (acomodacoes));
        acomodacoes acomodacoesRAM[quantidade];
        acomodacoes_ram_bin(acomodacoesRAM);
        for (int i = 0; i < quantidade; i++) {
            cadastro_acomodacoes_txt(acomodacoesRAM[i]);
        }
        deleta_arquivo("Acomodacoes.bin");
    }
    
    //traz Reservas para ram e salva em txt e apaga o arquivo bin
    existe = arquivo_existe_bin("Reservas.bin");
    if (existe == 1) {
        quantidade = qtd_itens_bin("Reservas.bin", sizeof (reservas));
        reservas reservasRAM[quantidade];
        reservas_ram_bin(reservasRAM);
        for(int i=0;i<quantidade;i++){
            muda_reserva_arquivo_bin_p_txt(reservasRAM[i]);
        }
        deleta_arquivo("Reservas.bin");
    }
    
    existe = arquivo_existe_txt("Contas_hospede.bin");
    if (existe == 1) {
        quantidade = qtd_itens_bin("Contas_hospede.bin", sizeof (conta_hospede));
        conta_hospede contasRAM[quantidade];
        conta_hospede_ram_bin(contasRAM);
        for (int i = 0; i < quantidade; i++) {
            cadastro_conta_txt(contasRAM[i]);
        }
        deleta_arquivo("Contas_hospede.bin");
    }
    
    existe = arquivo_existe_txt("Vendas.bin");
    if (existe == 1) {
        quantidade = qtd_itens_bin("Vendas.bin", sizeof (vendas));
        vendas vendasRAM[quantidade];
        venda_ram_bin(vendasRAM);
        for (int i = 0; i < quantidade; i++) {
            cadastrar_venda_txt(vendasRAM[i]);
        }
        deleta_arquivo("Vendas.bin");
    }


    existe = arquivo_existe_txt("Caixa.bin");
    if (existe == 1) {
        quantidade = qtd_itens_bin("Caixa.bin", sizeof (conta_receber));
        conta_receber caixaRAM[quantidade];
        caixa_ram_bin(caixaRAM);
        for (int i = 0; i < quantidade; i++) {
            cadastrar_caixa_txt(caixaRAM[i]);
        }
        deleta_arquivo("Caixa.bin");
    }

    existe = arquivo_existe_txt("Contas_receber.bin");
    if (existe == 1) {
        quantidade = qtd_itens_bin("Contas_receber.bin", sizeof (conta_receber));
        conta_receber contasRAM[quantidade];
        contas_a_receber_ram_bin(contasRAM);
        data date;
        for (int i = 0; i < quantidade; i++) {
            date.ano = contasRAM[i].date.ano;
            date.mes = contasRAM[i].date.mes;
            date.dia = contasRAM[i].date.dia;
            adicionar_contas_a_receber_txt(date, contasRAM[i].codigo_hos, contasRAM[i].valor_devido);
        }
        deleta_arquivo("Contas_receber.bin");
    }

    existe = arquivo_existe_txt("Contas_pagar.bin");
    if (existe == 1) {
        quantidade = qtd_itens_bin("Contas_pagar.bin", sizeof (conta_receber));
        conta_receber contasRAM[quantidade];
        contas_a_pagar_ram_bin(contasRAM);
        for (int i = 0; i < quantidade; i++) {
            cadastrar_contas_pagar_txt(contasRAM[i]);
        }
        deleta_arquivo("Contas_pagar.bin");
    }

    existe = arquivo_existe_txt("Notas_fiscais.bin");
    if (existe == 1) {
        NotaFiscal *notasRAM=NULL;
        quantidade=notasfiscais_ram_bin(&notasRAM);
        for (int i = 0; i < quantidade; i++) {
            cadastrar_notafiscal_txt(notasRAM[i]);
        }
        deleta_arquivo("Notas_fiscais.bin");
    }
}

//funcao que pega dados dos arquivos txt e passa para o arquivo binario
int muda_arquivo_txt_p_bin(){
    int existe,quantidade;
    
    //traz operadores para ram e salva em binario e apaga o arquivo txt
    quantidade=contadorlinhas_txt("operadores.txt");
    quantidade=quantidade/9;
    OPsistema operadoresRAM[quantidade];
    operadores_ram_txt(quantidade,operadoresRAM);
    for(int i=0;i<quantidade;i++){
        operadores_cad_bin(operadoresRAM[i]);
    }
    deleta_arquivo("operadores.txt");
    
    //traz hotel para ram e salva em binario e apaga o arquivo txt
    existe=arquivo_existe_txt("hotel.txt");
    if(existe==1){
        cad_hotel hotelRAM[1];
        //trazendo hotel pra memoria
        hotel_ram_txt(hotelRAM);
        //passando o hotel para o arquivo binario
        hotel_cad_bin(hotelRAM[0]);
        //deletando o arquivo TXT para ficar somente o binario
        deleta_arquivo("hotel.txt");
    }
    
    //traz hospedes para ram e salva em binario e apaga o arquivo txt
    existe=arquivo_existe_txt("hospedes.txt");
    if(existe==1){
        quantidade=contadorlinhas_txt("hospedes.txt");
        quantidade=quantidade/16;
        hospedes hospedesRAM[quantidade];
        hospedes_ram_txt(hospedesRAM,quantidade);
        for(int i=0;i<quantidade;i++){
            hospede_cad_bin(hospedesRAM[i]);
        }
        deleta_arquivo("hospedes.txt");
    }
    
    //traz produtos para ram e salva em binario e apaga o arquivo txt
    existe=arquivo_existe_txt("produtos.txt");
    if(existe==1){
        quantidade = contadorlinhas_txt("produtos.txt");
        quantidade = quantidade / 6;
        produtos produtoRAM[quantidade];
        produtos_ram_txt(produtoRAM, quantidade);
        for(int i=0;i<quantidade;i++){
            produtos_cad_bin(produtoRAM[i]);
        }
        deleta_arquivo("produtos.txt");
    }
    
    //traz fornecedores para ram e salva em binario e apaga o arquivo txt
    existe=arquivo_existe_txt("fornecedores.txt");
    if(existe==1){
        quantidade = contadorlinhas_txt("fornecedores.txt");
        quantidade = quantidade / 13;
        fornecedores fornecedorRAM[quantidade];
        fornecedores_ram_txt(fornecedorRAM, quantidade);
        for(int i=0;i<quantidade;i++){
            fornecedores_cad_bin(fornecedorRAM[i]);
        }
        deleta_arquivo("fornecedores.txt");
    }
    
    //traz categorias para ram e salva em binario e apaga o arquivo txt
    existe=arquivo_existe_txt("categorias.txt");
    if(existe==1){
        quantidade = contadorlinhas_txt("categorias.txt");
        quantidade = quantidade / 5;
        categoria_acomodacao categoriaRAM[quantidade];
        categorias_ram_txt(categoriaRAM, quantidade);
        for(int i=0;i<quantidade;i++){
            categoria_cad_bin(categoriaRAM[i]);
        }
        deleta_arquivo("categorias.txt");
    }
    
    //traz acomodacoes para ram e salva em binario e apaga o arquivo txt
    existe=arquivo_existe_txt("acomodacoes.txt");
    if(existe==1){
        quantidade = contadorlinhas_txt("acomodacoes.txt");
        quantidade = quantidade / 7;
        acomodacoes acomodacoesRAM[quantidade];
        acomodacoes_ram_txt(acomodacoesRAM, quantidade);
        for(int i=0;i<quantidade;i++){
            acomodacoes_cad_bin(acomodacoesRAM[i]);
        }
        deleta_arquivo("acomodacoes.txt");
    }
    
    //traz reservas para ram e salva em binario e apaga o arquivo txt
    existe=arquivo_existe_txt("reservas.txt");
    if (existe == 1) {
        quantidade = contadorlinhas_txt("reservas.txt");
        quantidade = quantidade / 16;
        reservas reservasRAM[quantidade];
        reservas_ram_txt(quantidade,reservasRAM);
        for(int i=0;i<quantidade;i++){
            muda_reserva_arquivo_txt_p_bin(reservasRAM[i]);
        }
        deleta_arquivo("reservas.txt");
    }
    
    
    existe=arquivo_existe_txt("conta_hospedes.txt");
    if (existe == 1) {
        quantidade = contadorlinhas_txt("conta_hospedes.txt");
        quantidade = quantidade / 3;
        conta_hospede contasRAM[quantidade];
        conta_ram_txt(contasRAM, quantidade);
        for(int i=0;i<quantidade;i++){
            conta_hospede_cad_bin(contasRAM[i]);
        }
        deleta_arquivo("conta_hospedes.txt");
    }
    existe=arquivo_existe_txt("vendas.txt");
    if (existe == 1) {
        quantidade = contadorlinhas_txt("vendas.txt");
        vendas vendasRAM[quantidade];
        ram_venda_txt(vendasRAM,quantidade);
        for(int i=0;i<quantidade;i++){
            cadastrar_venda_bin(vendasRAM[i]);
        }
        deleta_arquivo("vendas.txt");
    }
    
    
    existe = arquivo_existe_txt("caixa.txt");
    if (existe == 1) {
        quantidade = contadorlinhas_txt("caixa.txt");
        quantidade = quantidade / 5;
        conta_receber caixaRAM[quantidade];
        caixa_ram_txt(caixaRAM, quantidade);
        for (int i = 0; i < quantidade; i++) {
            cadastrar_caixa_bin(caixaRAM[i]);
        }
        deleta_arquivo("caixa.txt");
    }
    
    existe = arquivo_existe_txt("contas_receber.txt");
    if (existe == 1) {
        quantidade = contadorlinhas_txt("contas_receber.txt");
        quantidade = quantidade / 5;
        conta_receber contasRAM[quantidade];
        contas_receber_ram_txt(contasRAM, quantidade);
        
        data date;
        for (int i = 0; i < quantidade; i++) {
            date.ano=contasRAM[i].date.ano;
            date.mes=contasRAM[i].date.mes;
            date.dia=contasRAM[i].date.dia;
            
            adicionar_contas_a_receber_bin(date,contasRAM[i].codigo_hos,contasRAM[i].valor_devido);
        }
        deleta_arquivo("contas_receber.txt");
    }
    
    existe = arquivo_existe_txt("contas_pagar.txt");
    if (existe == 1) {
        quantidade = contadorlinhas_txt("contas_pagar.txt");
        quantidade = quantidade / 5;
        conta_receber contasRAM[quantidade];
        contas_pagar_ram_txt(contasRAM, quantidade);
        for (int i = 0; i < quantidade; i++) {
            cadastrar_contas_a_pagar_bin(contasRAM[i]);
        }
        deleta_arquivo("contas_pagar.txt");
    }
    
    existe = arquivo_existe_txt("notas_fiscais.txt");
    if (existe == 1) {
        quantidade = contadorlinhas_txt("notas_fiscais.txt");
        quantidade = quantidade / 7;
        NotaFiscal notasRAM[quantidade];
        ram_notafiscal_txt(quantidade, notasRAM);
        for (int i = 0; i < quantidade; i++) {
            cadastrar_notafiscal_bin(notasRAM[i]);
        }
        deleta_arquivo("notas_fiscais.txt");
    }    
}

