#ifndef RESERVASBIN_H
#define RESERVASBIN_H

// Funçao que cria um arquivo binário para as reservas.
void cria_reservas_bin();

// Funçao que abre um arquivo binário para escrever e gravar dados das reservas.
int reservas_cad_bin(data_chek_in_out datas, int cod_acomodacao, int cod_hospede, int cod_reserva);

//
int muda_reserva_arquivo_txt_p_bin(reservas reservasRAM);
//Função para descobrir as acomodações livres
int quartos_desocupados_bin(int qtd_aco);

//Função para ler o binário das reservas e levar para a RAM.
int reservas_ram_bin(reservas *reservas_inf);

//Função para ler e printar os dados das reservas.
void dados_reservas_bin();

//Função para ler e printar uma reserva especifica.
int print_reserva_bin( int codigo_res);

//verifica se o codigo do usuario digitou existe e se encaixa dentro da categoria filtrada escolhida
int disponibilidade_acomodacao_bin(int cod_cat, int cod_aco);

//printa as datas em que aquela quarto esta reservado
int procura_data_reserva_bin(int codigo_acomodacao);

//verifica se o quarto escolhido esta com a ocupacao igual a 0 ou seja se nao existe nenhuma reserva
int verifica_ocupacao_bin(int codigo_acomodacao);

// Função para verificar e coletar códigos das acomodações disponíveis que possuem todas as facilidades
int verificar_acomodacoes_disponiveis_bin(const char *facilidades_usuario, int *codigos_disponiveis);

//Função que atualiza os dados das reservas.
int atualiza_reservas_bin(reservas *nova_reservas, int codigo_reserva);

//Função que deleta os dados das reservas.
int deleta_reservas_bin( int codigo_reserva);

#endif /* RESERVASBIN_H */