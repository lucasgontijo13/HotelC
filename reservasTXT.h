

#ifndef RESERVASTXT_H
#define RESERVASTXT_H

//funcao pra criar o arquivo de reservas para começar a cadastrar reservas
void criar_reservas_txt();
    
//funcao que pegas os dados da acomodacao com os dados da categoria da propria acomodacao e o codigo do hospede para criar o arquvio de reservas em txt
int cadastro_reservas_txt(acomodacoes *acomodacoes, categoria_acomodacao *categorias, int posicao_acomodacao, int qtd_cat, data_chek_in_out datas, int cod_hos, int cod_res); 

//fucao para cadastrar as reservas quando for mudar de arquvio bin para txt
int muda_reserva_arquivo_bin_p_txt(reservas reservasRAM);

//traz as reservas para memoria ram
int reservas_ram_txt(int qtd, reservas *ramRES);

//utilizado no filtro de categoria para printar o codigo e a descricao da categoria para o usuario escolher
int printa_categoria_txt(int qtd, categoria_acomodacao *printCAT);

//printa as datas em que aquela quarto esta reservado
int procura_data_reserva_txt(int qtd, int codigo_aco, reservas *reservaRAM) ;

//verifica se a data nao esta infligindo nenhuma reserva
int verifica_data_txt(int qtd, reservas *ramRES, data_chek_in_out datas, int cod_aco);

//verifica se o quarto escolhido esta com a ocupacao igual a 0 ou seja senao existe nenhuma reserva
int verifica_ocupacao_txt(int qtd_aco, int cod_aco, acomodacoes *acomodacaoRES);

//função para procurar reserva em txt
int procura_reserva_txt(int codigo, int qtd, reservas *procuraRES);

//funcao para atualizar reserva em txt
int atualiza_reserva_txt(int qtd, reservas *reservasAT);

//funcao para deletar reserva em txt
int deleta_reserva_txt(int qtd, int posicao, reservas *ramDELRES);

//funcao para filtrar por data em txt
int data_disponivel_txt(reservas *disponiveis, reservas *reservaRAM, acomodacoes *acomodacoesRAM, int qtd_res, int qtd_aco, data_chek_in_out datas, categoria_acomodacao *categoriaRAM, int qtd_cat);

//funcao para filtrar por categoria em txt
int categoria_disponivel_txt(int codigo_cat, int qtd_aco, acomodacoes *acomodacoesRAM, categoria_acomodacao *categoriaRAM, int pos_cat, reservas *disponiveis);

//funcao para filtrar por quantidade de pessoas em txt
int pessoas_disponivel_txt(int criancas, int adultos, int qtd_cat, int qtd_aco, categoria_acomodacao *categoriaRAM, acomodacoes *acomodacoesRAM, reservas *disponiveis);

//funçao para filtrar po facilidades em txt
int facilidades_disponiveis_txt(char *facilidades, acomodacoes *acomodacoesRAM, int qtd_aco, reservas *disponiveis, categoria_acomodacao *categoriaRAM, int qtd_cat);

//funcao que filtra por facilidades mesmo depois de um filtro ja ter sido utilizado
int filtro_facilidades_filtrada_txt(char *facilidades, reservas *disponiveis_novo, reservas *disponiveis_antigo, int qtd_dis);

//funcao para procurar facilidades no vetor que ja foi filtrado uma vez
int procura_facilidades_filtrada_txt(char *facilidades, reservas *disponiveis, int qtd_dis);

//funcao que filtra por categoria mesmo depois de um filtro ja ter sido utilizado
int filtro_categoria_filtrada_txt(reservas *disponivel_novo, reservas *disponiveis_antigo, int qtd_dis, int cod_cat);

//funcao para procurar categora no vetor que ja foi filtrado uma vez
int procura_categoria_filtrada_txt(int cod_cat, reservas *disponiveis, int qtd_dis);

//funcao que filtra por quantidade de pessoas mesmo depois de um filtro ja ter sido utilizado
int filtro_pessoas_filtrada(int criancas, int adultos ,reservas *disponivel_novo, reservas *disponiveis_antigo, int qtd_dis);

//funcao para procurar categora no vetor que ja foi filtrado uma vez
int procura_pessoas_filtrada_txt(int criancas,int adultos, reservas *disponiveis, int qtd_dis);

//funcao para pegar a posicao da acomodaçao que esta em um vetor disponivel
int procura_acomodacao_disponivel(int qtd_dis,int cod_aco,reservas *disponiveis,acomodacoes *acomodacaoRAM,int qtd_aco);


#endif /* RESERVAS_H */

