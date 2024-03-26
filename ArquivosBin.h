#ifndef ARQUIVOSBIN_H
#define ARQUIVOSBIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


//cabeçalho da função utilizada para criar arquivos em binario para o cad do hotel 
int hotel_cad_bin(cad_hotel hotel_inf);

//cabeçalho da função utilizada para ler arquivos em binario para o cad do hotel 
int hotel_ram_bin(cad_hotel *hotel_inf);

//Função para ler e printar os dados do hotel.
void dados_hotel_bin();

//Função que atualiza os dados do hotel.
int atualiza_hotel_bin(cad_hotel *novo_hotel_inf);



// Funçao que abre um arquivo Binário para escrever e gravar dados dos operadores 
int operadores_cad_bin(OPsistema op);

//Função para ler o binario do cadastro de operadores e levar para a RAM.
int operadores_ram_bin(OPsistema *op);

//Função para ler e printar os dados dos operadores.
void dados_operadores_bin();

//Função que atualiza os dados dos operadores.
int atualiza_operadores_bin(OPsistema novo_op, int codigo_operador);

//Função que deleta os dados de um operador.
int deleta_operadores_bin(int codigo_operador);



// Funçao que abre um arquivo binário para escrever e gravar dados dos hospedes.
int hospede_cad_bin(hospedes hospede_inf);

//Função para ler o binário do cadastro dos hospedes e levar para a RAM.
int hospede_ram_bin(hospedes *hospede_inf);

//Função para ler e printar os dados dos hospedes.
void dados_hospede_bin();

//Função que atualiza os dados dos hospedes.
int atualiza_hospede_bin(hospedes novo_hospede, int codigo_hospede);

//Função que deleta os dados de um hospede.
int deleta_hospede_bin(int codigo_hospede);



// Funçao que abre um arquivo binário para escrever e gravar dados dos produtos.
int produtos_cad_bin(produtos produtos_inf);

//Função para ler o binário dos produtos e levar para a RAM.
int produtos_ram_bin(produtos *produtos_inf);

//Função para ler e printar os dados dos produtos.
void dados_produtos_bin();

//Função que atualiza os dados dos produtos.
int atualiza_produtos_bin(produtos *novo_produto, int codigo_produto);

//atualiza somento o estoque do produto
int atualiza_estoque_bin(int qtd_compra , int codigo_produto);

//Função que deleta um dado de produto.
int deleta_produtos_bin(int codigo_produto);



// Funçao que abre um arquivo binário para escrever e gravar dados dos fornecedores.
int fornecedores_cad_bin(fornecedores fornecedores_inf);

//Função para ler o binário dos fornecedores e levar para a RAM.
int fornecedores_ram_bin(fornecedores *fornecedores_inf);

//Função para ler e printar os dados dos fornecedores.
void dados_fornecedores_bin();

//Função que atualiza os dados dos fornecedores.
int atualiza_fornecedores_bin(fornecedores novo_fornecedor, int codigo_fornecedor);

//Função que deleta um dado de fornecedor.
int deleta_fornecedor_bin(int codigo_fornecedor);



// Funçao que abre um arquivo binário para escrever e gravar dados das categorias de acomodações.
int categoria_cad_bin(categoria_acomodacao categorias_inf);

//Função para ler o binário das categorias de acomodação e levar para a RAM.
int categorias_ram_bin(categoria_acomodacao *categorias_inf);

//Função para ler e printar os dados das categorias de acomodação.
void dados_categorias_bin();

//Função que atualiza os dados das categorias de acomodação.
int atualiza_categorias_bin(categoria_acomodacao nova_categorias, int codigo_categorias);

//Função que atualiza os dados das categorias de acomodação.
int deleta_categorias_bin(int codigo_categorias);



// Funçao que abre um arquivo binário para escrever e gravar dados das acomodações.
int acomodacoes_cad_bin(acomodacoes acomodacoes_inf);

//Função para ler o binário das acomodações e levar para a RAM.
int acomodacoes_ram_bin(acomodacoes *acomodacoes_inf);

//Função para ler e printar os dados das acomodações.
void dados_acomodacoes_bin();

//Função para ler e printar os dados das acomodações.
void dados_acm_especificas_bin(reservas *vetor_cod);

//Função que atualiza os dados das acomodações.
int atualiza_acomodacoes_bin(acomodacoes nova_acomodacao, int codigo_acomodacao);

//Função que atualiza somente a ocupação das acomodações.
int atualiza_cupantes_acm_bin(int ocupantes, int codigo_acomodacao);

//Função que adiciona uma ocupação das acomodações.
int soma_ocupantes_acm_bin(int codigo_acomodacao, float valor, int diaria);

//Função que diminui uma ocupação das acomodações.
int diminui_ocupantes_acm_bin(int codigo_acomodacao);

//Função que diminui uma ocupação das acomodações.
int diminui_ocupantes_valor_acm_bin(int codigo_acomodacao, float valor, int diaria) ;

//Função para deletar os dados das acomodaçôes.
int deleta_acomodacoes_bin(int codigo_acomodacao);



// Funçao que abre um arquivo binário para escrever e gravar dados da conta dos hospedes. 
int conta_hospede_cad_bin(conta_hospede conta);

//Função para ler o binário da conta dos hospedes  e levar para a RAM.
int conta_hospede_ram_bin(conta_hospede *conta);

//Função para ler e printar os dados da conta dos hospedes .
void dados_conta_hospede_bin();

//Função que atualiza os dados da conta dos hospedes .
int atualiza_conta_hospede_bin(conta_hospede nova_conta, int codigo_hospede);

//Função que deleta os dados da conta dos hospedes.
int deleta_conta_hospede_bin( int codigo_hospede);



//funcao para adicionar valor no caixa bin
int adiciona_caixa_bin(float valor, int cod_hos, int controle);

//funcao igual a de cima porem utilizida pra cadastrar o caixa na troca de txt pra bin que ja vem com as datas
int cadastrar_caixa_bin(conta_receber caixa);

//trazendo dados do caixa para memoria
int caixa_ram_bin(conta_receber *caixa);

//funcao para printar os valores do caixa
void dados_caixa_bin() ;



//funcao para adicionar no arquivo contas a receber quando alguem pagar no cartao
int adicionar_contas_a_receber_bin(data datas, int cod_hos, float valor) ;

//trazendo dados do caixa para memoria
int contas_a_receber_ram_bin(conta_receber *contasRAM) ;

//Função que deleta os dados da conta dos hospedes.
int deleta_conta_a_receber_bin(int codigo_hospede);

//Função para printar os valores das contas a receber
void dados_conta_a_receber_bin();



//funcao para adicionar no arquivo contas a receber quando alguem pagar no cartao
int adicionar_contas_a_pagar_bin(float valor, int vezes,int cod_for);

//funcao igual a de cima porem utilizida pra cadastrar as contas na troca de txt pra bin que ja vem com todos dados prontos
int cadastrar_contas_a_pagar_bin(conta_receber conta);

//trazendo dados do caixa para memoria
int contas_a_pagar_ram_bin(conta_receber *contasRAM);

//Função que deleta os dados da conta dos hospedes.
int deleta_conta_a_pagar_bin(int codigo_conta) ;
        
//Função para printar os valores das contas a receber
void dados_conta_a_pagar_bin() ;


// Função para cadastrar nota fiscal em um arquivo binário
int cadastrar_notafiscal_bin(NotaFiscal nota);

//printa os dados das notas fiscais
void dados_notasficais_bin();

//funcao que traz as notas fiscais para a memoria
int notasfiscais_ram_bin(NotaFiscal **notas);


// Função para cadastrar venda do produto em um arquivo binário
int cadastrar_venda_bin(vendas venda);

//trazendo dados do caixa para memoria
int venda_ram_bin(vendas *vendasRAM);

//Função para printar os valores das contas a receber
void dados_venda_bin();


//funcao para listar os hospedes 
int listagem_hospede_bin(int *codigo, int *listagem, char *sexo, int opcao);

//funcao para listar a acomodacao
int listagem_acomodacoes_bin(int *codigo, int *listagem, int categoria, int opcao, data_chek_in_out datas);

//funcao para filtra e printar ou salvar a listagem de reservas
int listagem_reservas_bin(int *listagem, int *codigo_hospede, int *codigo_acomodacao, data_chek_in_out datas, int opcao);

//funcao para filtra e printar ou salvar a listagem de acomodacoes
int listagem_movimento_acomodacoes_bin(int *listagem, int *codigo, int diarias, float lucro, int opcao);

//funcao para listar a acomodacao
int listagem_produtos_bin(int *codigo, int listagem, int opcao);

//funcao para filtra e printar ou salvar a listagem de produtos em estoque minimo
int listagem_estoque_minimo_bin(int *codigo, int listagem, int opcao) ;

//funcao para filtra e printar ou salvar a listagem de vendas
int listagem_vendas_bin(int pagamento, int opcao, int listagem);

//funcao para filtra e printar ou salvar a listagem de contas a receber
int listagem_contas_receber_bin(int *listagem, int *codigo, data inicio, data fim, int opcao);

//funcao para filtra e printar ou salvar a listagem de contas a pagar
int listagem_contas_pagar_bin(int *listagem, int *codigo, data inicio, data fim, int opcao);

//funcao para filtra e printar ou salvar a listagem de caixa
void listagem_caixa_bin(data inicio, data fim, int listagem, int opcao);



//exportar dados
int exportar_dados_bin_xml(int *exportar);

//funcao para importar dados do hotel de um xml
int importar_dados_hotel_bin_xml(char *arquivo);

//funcao para importar dados dos hospedes
int importar_dados_hospedes_bin_xml(char *arquivo);

//funcao para importar dados das acomodacoes
int importar_dados_acomodacoes_bin_xml(char *arquivo);

//funcao para importar dados das categorias de acomodacoes
int importar_dados_categoria_acomodacao_bin_xml(char *arquivo);

//funcao para importar dados de produtos
int importar_dados_produtos_bin_xml(char *arquivo);

//funcao para importar dados dos fornecedores
int importar_dados_fornecedores_bin_xml(char *arquivo);

//funcao para importar dados dos operadores
int importar_dados_operadores_bin_xml(char *arquivo);

#endif /* ARQUIVOSBIN_H */

