#ifndef MEMORIA_H
#define MEMORIA_H

void login_mem();

void cadastro_hotel_mem();

void atualiza_hotel_mem();


int cadastro_operadores_mem();

int atualiza_operadores_mem();

void deleta_operadores_mem();


void cadastro_hospede_mem();

void atualiza_hospede_mem();

void deleta_hospede_mem();


void cadastro_produtos_mem();

void atualiza_produto_mem();

void deleta_produtos_mem();


void cadastro_fornecedores_mem();

void atualiza_fornecedores_mem();

void deleta_fornecedores_mem();


void cadastra_categoria_mem();

void atualiza_categoria_mem();

void deleta_categoria_mem();


void cadastro_acomodacao_mem();

void atualiza_acomodacoes_mem();

void deleta_acomodacoes_mem();


void dadosHotel();

void dadosHospede();

void dadosOperador();

void dadosProdutos();

void dadosFornecedor();

void dadosCategoria();

void dadosAcomodacao();

void dadosReserva();

void dadosContaHospede();

void dadosCaixa();

void dadosContaReceber();

void dadosContaPagar();

void dadosNotaFiscal();

void dadosVenda();


void filtros_mem();

void deleta_reservas_mem();

void chekin_mem();

void chekout_mem();

void venda_mem();

void caixa_mem();

void receber_mem();

void listar_conta_receber_mem();

void entrada_produtos_mem();

void conta_pagar_mem();

void listar_conta_pagar_mem();



int funcao_listagem_hospede_mem(int *codigo, int *listagem,char *sexo,int opcao);

void listagem_hospede_mem();


int funcao_listagem_acomodacoes_mem(int *codigo, int *listagem,int categoria,int opcao,data_chek_in_out datas);

void listagem_acomodacoes_mem();


int funcao_listagem_reservas_mem(int *listagem, int *codigo_hospede, int *codigo_acomodacao, data_chek_in_out datas, int opcao) ;

void listagem_reservas_mem();


int funcao_listagem_movimento_acomodacoes_mem(int *listagem, int *codigo, int diarias, float lucro, int opcao) ;

void listagem_movimento_acomodacoes_mem();


int funcao_listagem_produtos_mem(int *codigo, int listagem, int opcao);

void listagem_produtos_mem();


int funcao_listagem_estoque_minimo_mem(int *codigo, int listagem, int opcao);

void listagem_estoque_minimo_mem();


int funca_listagem_vendas_mem(int pagamento, int opcao, int listagem);

void listagem_vendas_mem();


int funcao_listagem_contas_receber_mem(int *listagem, int *codigo, data inicio, data fim, int opcao) ;

void listagem_contas_receber_mem();


int funcao_listagem_contas_pagar_mem(int *listagem, int *codigo, data inicio, data fim, int opcao) ;

void listagem_contas_pagar_mem();


void funcao_listagem_caixa_mem(data inicio, data fim, int listagem, int opcao);

void listagem_caixa_mem();


int importar_hotel_mem_xml(char *arquivo);

int importar_dados_hospedes_mem_xml(char *arquivo);

int importar_dados_acomodacoes_mem_xml(char *arquivo);

int importar_dados_categoria_acomodacao_mem_xml(char *arquivo);

int importar_dados_produtos_mem_xml(char *arquivo);

int importar_dados_fornecedores_mem_xml(char *arquivo);

int importar_dados_operadores_mem_xml(char *arquivo);

void importar_dados_mem();

int exportar_dados_xml_mem(int *exportar);

void exportar_dados_mem();

int muda_arquivo_bin_p_mem();

int muda_arquivo_txt_p_mem();


#endif /* MEMORIA_H */