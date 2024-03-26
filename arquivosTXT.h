
#ifndef ARQUIVOSTXT_H
#define ARQUIVOSTXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "funcoes.h"
#include "reservasTXT.h"

// função responsavel por cadastras os dados do hotel em TXT
int cadastro_hotel_txt(cad_hotel hotel_inf);

//funçao responsavel por trazer dados do hotel para memoria ram    
int hotel_ram_txt(cad_hotel *ramHT);

//função responsavel por atualizar dados do hotel
int atualiza_hotel_txt(cad_hotel *AtualizaHT);

//função responsavel por cadastrar os dados dos operadores em TXT
int cadastro_operadores_txt(OPsistema op);

//função responsavel por trazer os dados dos operadore para memoria ram
int operadores_ram_txt(int qtd, OPsistema *ramOP);

//função para procurar operador em txt
int procura_operador_txt(int codigo,int qtd, OPsistema *ramOP);

//função para atualizar dados dos operadores
int atualiza_operador_txt(int qtd,OPsistema *ramOP);

//função para deletar operador
int deleta_operador_txt(int qtd, int posicao, OPsistema *ramDELOP);

//função para cadastrar hospedes
int cadastro_hospedes_txt(hospedes cadastro_hospede);

//funçao para trazer os dados dos hospedes para memoria ram
int hospedes_ram_txt(hospedes *ramHO, int qtd);

//funcao pra procurar hospede
int procura_hospede_txt(int codigo,int qtd, hospedes *procuraHO);

//funcao para atualizar hospede
int atualiza_hospede_txt(int qtd,hospedes *ramHO);

//funcao para deletar hospede
int deleta_hospede_txt(int qtd, int posicao, hospedes *ramDELHO);

//funcao para cadastrar produtos em txt
int cadastro_produtos_txt(produtos produtos_txt);

//funcao para passar os produtos do txt para ram
int produtos_ram_txt(produtos *ramPROD, int qtd);

//funcao para procurar produto
int procura_produto_txt(int codigo,int qtd, produtos *procuraPRO);

//procura o produto pelo nome
int procura_produto_nome_txt(char *produto, int qtd, produtos *produtosRAM) ;

//funcao para atualizar o arquivo txt de produtos
int atualiza_produto_txt(int qtd, produtos *ramPROD);

//função para deletar produtos
int deleta_produto_txt(int qtd, int posicao, produtos *ramDELPROD);

//funcao para mostrar os produtos que tem estoque
int mostra_produto_txt(int qtd,produtos *produtosRAM);

//fucao para cadastrar fornecedor
int cadastro_fornecedor_txt(fornecedores cadastro_fornecedor);

//funcao que traz fornecedor para ram
int fornecedores_ram_txt(fornecedores *ramFOR, int qtd);

//funcao para procurar fornecedor
int procura_fornecedor_txt(int codigo,int qtd, fornecedores *procuraFOR);

///procura o fornecedor pelo nome
int procura_fornecedor_nome_txt(char *fornecedor, int qtd, fornecedores *fornecedorRAM);

//funcao para atualizar fornecedor
int atualiza_fornecedor_txt(int qtd,fornecedores *fornecedorAT);

//funcao para deletar fornecedor
int deleta_fornecedor_txt(int qtd, int posicao, fornecedores *ramDELFOR);

//funcao para cadastrar categoria de acomadações em txt
int cadastro_categoria_txt(categoria_acomodacao cadatro_categoria);

//funcao para passar as categorias do txt para ram
int categorias_ram_txt(categoria_acomodacao *ramCAT, int qtd);

//funcao para procurar categoria
int procura_categoria_txt(int codigo,int qtd, categoria_acomodacao *procuraCAT);

//funcao para atualizar a categoria txt de produtos
int atualiza_categoria_txt(int qtd, categoria_acomodacao *categoriaAT);

//função para deletar categoria
int deleta_categoria_txt(int qtd, int posicao, categoria_acomodacao *categoriaDEL);

//funcao para cadastrar categoria de acomadações em txt
int cadastro_acomodacoes_txt(acomodacoes cadatro_acomodacoes);

//funcao para passar as acomodações do txt para ram
int acomodacoes_ram_txt(acomodacoes *ramCOM, int qtd);

//funcao para procurar categoria
int procura_acomodacao_txt(int codigo,int qtd, acomodacoes *procuraCOM);

//funcao para atualizar as acomodações txt 
int atualiza_acomodacoes_txt(int qtd, acomodacoes *acomodacoesAT);

//função para deletar acomodação
int deleta_acomodacoes_txt(int qtd, int posicao, acomodacoes *acomadacaoDEL);

//funcao para cadastra conta do hospede txt
int cadastro_conta_txt(conta_hospede conta);

//funcao que traz todas contas dos hospedes pra ram
int conta_ram_txt(conta_hospede *conta,int qtd);

//funcao para procurar conta do hospede
int procura_conta_txt(int cod_res, conta_hospede *conta,int qtd);

//funcao para atualizar conta do hospede
int atualiza_conta_txt(int qtd, conta_hospede *conta);

//funcao para deletar conta do hospede
int deleta_conta_txt(int qtd, int posicao, conta_hospede *conta);



//funcao para cadastra venda de produtos
int cadastrar_venda_txt(vendas venda);

//traz as vendas pra ram
int ram_venda_txt(vendas *venda,int qtd);


//funcao para adicionar valor no caixa txt
int adicionar_caixa_txt(float valor, int cod_hos, int controle);

//funcao para cadastrar caixa com todos os dados, sem pegar a data atual
int cadastrar_caixa_txt(conta_receber caixa);

//trazendo dados do caixa para memoria
int caixa_ram_txt(conta_receber *caixaRAM, int qtd);

//funcao para printar os valores do caixa
void mostra_caixa_txt();



//funcao para adicionar no arquivo contas a receber quando alguem pagar no cartao
int adicionar_contas_a_receber_txt(data datas, int cod_hos, float valor);

//traznedo contas a receber para memoria ram
int contas_receber_ram_txt(conta_receber *contasRAM,int qtd_conta);

//deletando conta receber 
int deleta_conta_receber_txt(int qtd, int posicao, conta_receber *conta);

//funcao para printar os valores das contas a receber
int mostra_contas_a_receber_txt(int qtd_conta, conta_receber *conta);



//cadastrando conta a pagar
int adicionar_contas_pagar_txt(float valor,int vezes,int cod_for);

//funcao para cadastrar conta a pagar com todos valores cheios
int cadastrar_contas_pagar_txt(conta_receber conta);

// trazendo contas a pagar para memoria ram
int contas_pagar_ram_txt(conta_receber *contasRAM, int qtd_conta);

//funcao para printar os valores das contas a pagar
int mostra_contas_a_pagar_txt(int qtd_conta, conta_receber *conta);

//deletando conta receber 
int deleta_conta_pagar_txt(int qtd, int posicao, conta_receber *conta);


//funcao para cadastrar nota fiscal
int cadastrar_notafiscal_txt(NotaFiscal notas);

//funcao para trazer dados das notas fiscais para memoria
int ram_notafiscal_txt(int qtd_notas, NotaFiscal *notas);

//funcao para filtra e printar ou salvar a listagem de hospedes
int listagem_hospede_txt(int *codigo, int *listagem, char *sexo, int opcao);

//funcao para filtra e printar ou salvar a listagem de acomodacoes
int listagem_acomodacoes_txt(int *codigo, int *listagem, int categoria, int opcao, data_chek_in_out datas);

//funcao para filtra e printar ou salvar a listagem de reservas
int listagem_reservas_txt(int *listagem, int *codigo_hospede, int *codigo_acomodacao, data_chek_in_out datas, int opcao);

//funcao para filtra e printar ou salvar a listagem de acomodacoes
int listagem_movimento_acomodacoes_txt(int *listagem, int *codigo, int diarias, float lucro, int opcao);

//funcao para filtra e printar ou salvar a listagem de produtos
int listagem_produtos_txt(int *codigo, int listagem,int opcao);

//funcao para filtra e printar ou salvar a listagem de produtos em estoque minimo
int listagem_estoque_minimo_txt(int *codigo, int listagem, int opcao);

//funcao para filtra e printar ou salvar a listagem de vendas
int listagem_vendas_txt(int pagamento, int opcao, int listagem);

// funcao para ajudar na filtragem verificando se a data esta entre o intervalo
int data_entre(data d1, data d2);

//funcao para filtra e printar ou salvar a listagem de contas a receber
int listagem_contas_receber_txt(int *listagem, int *codigo, data inicio, data fim, int opcao);

//funcao para filtra e printar ou salvar a listagem de contas a pagar
int listagem_contas_pagar_txt(int *listagem, int *codigo, data inicio, data fim, int opcao);

//funcao para filtra e printar ou salvar a listagem de caixa
void listagem_caixa_txt(data inicio, data fim, int listagem, int opcao);




//funcao para exportar dados para um arquivo XML
int exportar_dados_xml(int *exportar);

//funcao para trazer o arquivo xml para memoria
char* trazer_xml_buffer(char *importar);

//funcao para importar dados do hotel de um xml
int importar_dados_hotel_xml(char *arquivo);

//funcao para importar dados do hospede
int importar_dados_hospedes_xml(char *arquivo);

//funcao para importar dados das acomodacoes
int importar_dados_acomodacoes_xml(char *arquivo);

//funcao para importar dados das categorias de acomodacoes
int importar_dados_categoria_acomodacao_xml(char *arquivo);

//funcao para importar dados de produtos
int importar_dados_produtos_xml(char *arquivo);

//funcao para importar dados dos fornecedores
int importar_dados_fornecedores_xml(char *arquivo);

//funcao para importar dados dos operadores
int importar_dados_operadores_xml(char *arquivo);

#endif /* ARQUIVOS_H */

