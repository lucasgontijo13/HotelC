#ifndef MENU_H
#define MENU_H

//funcao para trazer permissoes para o menu em uma variavel global
int permissoes_login(OPsistema *ramOP, int pos_op);

//COMEÇO MENU TXT
void menu_principal_txt();

void menu_modulo_cadastro();

void menu_gestao_hotel();

void menu_gestao_operadores();

void menu_gestao_hospedes();

void menu_gestao_produtos();

void menu_gestao_fornecedor();

void menu_gestao_categoria();

void menu_gestao_acomodacao();

void menu_modulo_reservas();

void menu_modulo_transacoes();

void menu_conta_receber();

void menu_conta_pagar();

void menu_modulo_feedback();

void menu_modulo_im_exportacao();

void menu_alterar_salvemento_txt();
// FIM MENU TXT

//INICIO DO MENU BINARIO
void menu_principal_bin();

void menu_modulo_cadastro_bin();

void menu_gestao_hotel_bin();

void menu_gestao_operadores_bin();

void menu_gestao_hospedes_bin();

void menu_gestao_produtos_bin();

void menu_gestao_fornecedor_bin();

void menu_gestao_categoria_bin();

void menu_gestao_acomodacao_bin();

void menu_listas_bin();

void menu_modulo_reservas_bin();

void menu_modulo_transacoes_bin();

void menu_conta_receber_bin();

void menu_conta_pagar_bin();

void menu_modulo_feedback_bin();

void menu_modulo_im_exportacao_bin();

void menu_alterar_salvemento_bin();

//FIM DO MENU BINARIO

//INICIO DO MENU MEMORIA
void menu_principal_mem();

void menu_modulo_cadastro_mem();

void menu_gestao_hotel_mem();

void menu_gestao_operadores_mem();

void menu_gestao_hospedes_mem();

void menu_gestao_produtos_mem();

void menu_gestao_fornecedor_mem();

void menu_gestao_categoria_mem();

void menu_gestao_acomodacao_mem();

void menu_modulo_reservas_mem();

void menu_listas_mem();

void menu_modulo_reservas_mem();

void menu_modulo_transacoes_mem();

void menu_conta_receber_mem();

void menu_conta_pagar_mem();

void menu_modulo_feedback_mem();

void menu_modulo_im_exportacao_mem();
//FIM DO MENU MEMORIA

#endif /* MENU_H */