



#ifndef FUNCOES_H
#define FUNCOES_H

//procura codigo operador no binario
int procura_operador_bin( int codigo_operador);

//procura codigo hospede no binario
int procura_hospede_bin( int codigo_hospede);

//procura codigo produto no binario
int procura_produto_bin( int codigo_produto);

//procura codigo fornecedor no binario
int procura_fornecedor_bin( int codigo_fornecedor);

//procura codigo categoria no binario
int procura_categoria_bin( int codigo_categorias);

//procura codigo acomodacao no binario
int procura_acomodacao_bin( int codigo_acomodacao);

//procura codigo reserva no binario
int procura_reserva_bin( int codigo_reserva);

//retorna a quantidade de acomodações com 
int qtd_itens_bin(const char *nome_arquivo, size_t tamanho_registro);

//função para ferificar se existe arquivo
int arquivo_existe_bin(char *NomeArquivo);

//verifica quais meses tem 31 dias e se o fevereiro tem 29
int diasNoMes(int mes, int ano) ;

//verifica se o ano é bissexto
int ehBissexto(int ano);

//funcao para verificar se a data é valida
int data_atual(data_chek_in_out datas);

//funcao para verificar se o login foi feito certo
int verifica_login(int cod_op,int senha, OPsistema *ramOP,int quantidade);

//verifica se o arquivo txt  ja existe 
int arquivo_existe_txt(char *filename);

//funçao para contar linhas de um arquivo txt
int contadorlinhas_txt(char *arquivo) ;

//funcao para deletar qualquer arquivo
int deleta_arquivo(char *arquivo);

//funcao para calcular o saldo disponivel do caixa
float calcula_saldo_caixa(int qtd_caixa, conta_receber *caixaRAM);

//funcao que pega dados dos arquivos binarios e passa para o arquivo txt
int muda_arquivo_bin_p_txt();

//funcao que pega dados dos arquivos txt e passa para o arquivo binario
int muda_arquivo_txt_p_bin();



#endif /* FUNCOES_H */

