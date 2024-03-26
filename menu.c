#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "funcoes.h"
#include "arquivosTXT.h"
#include "reservasTXT.h"
#include "menu.h"
#include "ArquivosBin.h"
#include "ReservasBin.h"
#include "memoria.h" 

//variavel global utilizada para armazenar as permissoes do usuario que fez login
int permissoes[5];



int permissoes_login(OPsistema *ramOP, int pos_op){
    //atribuindo valor para a variavel global para que tenha acesso somente as permissoes ativas
    permissoes[0] = ramOP[pos_op].permissoes.cadastros;
    permissoes[1] = ramOP[pos_op].permissoes.reservas;
    permissoes[2] = ramOP[pos_op].permissoes.transacoes;
    permissoes[3] = ramOP[pos_op].permissoes.feedback;
    permissoes[4] = ramOP[pos_op].permissoes.im_exportacao;  
   
}



//Inicio do menu de TXT
void menu_principal_txt(){
    int menu=0,opcao=0;
    printf("------------------------Bem vindo-------------------------\n");
    printf("1-Módulo de Cadastros e Gestão de dados.\n");
    printf("2-Módulo de Reservas.\n");
    printf("3-Módulo de Transações.\n");
    printf("4-Módulo de Feedback.\n");
    printf("5-Módulo de importação/exportação de dados.\n");
    printf("6-Alterar modo de salvamento.\n");
    printf("7-Encerrar programa\n");
    printf("Digite a opção que deseja:");
    scanf("%d",&menu);
    
    switch(menu){
        case 1:
            if (permissoes[0] == 1) {
                menu_modulo_cadastro();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_txt();
            }
            break;
        case 2:
            if (permissoes[1] == 1) {
                menu_modulo_reservas();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_txt();
            }
            break;
        case 3:
            if (permissoes[2] == 1) {
                menu_modulo_transacoes();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_txt();
            }
            break; 
        case 4:
           if (permissoes[3] == 1) {
                menu_modulo_feedback();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_txt();
            }
            break; 
        case 5:
            if (permissoes[4] == 1) {
                menu_modulo_im_exportacao();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_txt();
            }
            break; 
        case 6:
            menu_alterar_salvemento_txt();
            break; 
        case 7:
           printf("Saindo...");
            break; 
        default:
            printf("\nDigite uma opção válida.\n");
            menu_principal_txt();
            break;
    }
}

//Inicio Módulo de Cadastros e Gestão de dados
void menu_modulo_cadastro(){
    int menu;
    printf("\n-----------MODULO DE CADASTRO-----------\n");
    printf("1-Gestao de dados do hotel.\n");
    printf("2-Gestao de dados dos operadores.\n");
    printf("3-Gestao de dados dos hospedes.\n");
    printf("4-Gestao de dados dos produtos.\n");
    printf("5-Gestao de dados dos fornecedores.\n");
    printf("6-Gestao de dados das categorias de acomodações.\n");
    printf("7-Gestao de dados das acomodações.\n");
    printf("8-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);
    
        switch(menu){
        case 1:
            menu_gestao_hotel();
            break;
        case 2:
            menu_gestao_operadores();
            break;
        case 3:
            menu_gestao_hospedes();
            break; 
        case 4:
           menu_gestao_produtos();
            break; 
        case 5:
            menu_gestao_fornecedor();
            break; 
        case 6:
           menu_gestao_categoria();
            break; 
        case 7:
           menu_gestao_acomodacao();
            break; 
        case 8:
           menu_principal_txt();
            break; 
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_cadastro();
            break;
        
    }
}

void menu_gestao_hotel(){
    int menu;
    printf("\n-----------GESTÃO DO HOTEL-----------\n");
    printf("1-Cadastro do Hotel.\n");
    printf("2-Atualizar cadastro do hotel.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);
    
    switch (menu) {
        case 1:
            main_cadastro_hotel_txt();
            break;
        case 2:
            main_atualiza_hotel_txt();
            break;
        case 3:
            menu_modulo_cadastro();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_hotel();
            break;

    }
}

void menu_gestao_operadores(){
    int menu;
    printf("\n-----------GESTÃO DOS OPERADORES-----------\n");
    printf("1-Cadastro de operadores.\n");
    printf("2-Atualizar operadores.\n");
    printf("3-Deletar operador.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);
    
        switch (menu) {
        case 1:
            main_cadastro_operador_txt();
            break;
        case 2:
            main_atualiza_operador_txt();
            break;
        case 3:
            main_deleta_operador_txt();
            break;
        case 4:
            menu_modulo_cadastro();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_operadores();
            break;

    }
}

void menu_gestao_hospedes(){
    int menu;
    printf("\n-----------GESTÃO DOS HOSPEDES-----------\n");
    printf("1-Cadastro de hospede.\n");
    printf("2-Atualizadar hospede.\n");
    printf("3-Deletar hospede.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);
    
         switch (menu) {
        case 1:
            main_cadastro_hospede_txt();
            break;
        case 2:
            main_atualiza_hospede_txt();
            break;
        case 3:
            main_deleta_hospede_txt();
            break;
        case 4:
            menu_modulo_cadastro();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_hospedes();
            break;

    }
}

void menu_gestao_produtos(){
    int menu;
    printf("\n-----------GESTÃO DE PRODUTOS-----------\n");
    printf("1-Cadastrar produto.\n");
    printf("2-Atualizar produto.\n");
    printf("3-Deletar produto.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);
    
    switch (menu) {
        case 1:
            main_cadastro_produtos_txt();
            break;
        case 2:
            main_atualiza_produtos_txt();
            break;
        case 3:
            main_deleta_produtos_txt();
            break;
        case 4:
            menu_modulo_cadastro();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_produtos();
            break;

    }
}

void menu_gestao_fornecedor(){
    int menu;
    printf("\n-----------GESTÃO DE FORNECEDORES-----------\n");
    printf("1-Cadastrar fornecedor.\n");
    printf("2-Atualizar fornecedor.\n");
    printf("3-Deletar fornecedor.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);

    switch (menu) {
        case 1:
            main_cadastro_fornecedor_txt();
            break;
        case 2:
            main_atualiza_fornecedor_txt();
            break;
        case 3:
            main_deleta_fornecedor_txt();
            break;
        case 4:
            menu_modulo_cadastro();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_fornecedor();
            break;

    }
}

void menu_gestao_categoria(){
    int menu;
    printf("\n-----------GESTÃO DE CATEGORIAS-----------\n");
    printf("1-Cadastrar categoria de acomadação.\n");
    printf("2-Atualizar categoria de acomadação.\n");
    printf("3-Deletar categoria de acomadação.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);

    switch (menu) {
        case 1:
            main_cadastro_categoria_txt();
            break;
        case 2:
            main_atualiza_categoria_txt();
            break;
        case 3:
            main_deleta_categoria_txt();
            break;
        case 4:
            menu_modulo_cadastro();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_categoria();
            break;

    }
}

void menu_gestao_acomodacao(){
    int menu;
    printf("\n-----------GESTÃO DAS ACOMODAÇÕES-----------\n");
    printf("1-Cadastrar acomodação.\n");
    printf("2-Atualizar acomodação.\n");
    printf("3-Deletar acomodação.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);

    switch (menu) {
        case 1:
            main_cadastro_acomodacao_txt();
            break;
        case 2:
            main_atualiza_acomodacao_txt();
            break;
        case 3:
            main_deleta_acomodacao_txt();
            break;
        case 4:
            menu_modulo_cadastro();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_acomodacao();
            break;

    }
}
//Fim Módulo de Cadastros e Gestão de dados


//Inicio do modulo de reservas
void menu_modulo_reservas(){
    criar_reservas_txt();
    
    int menu;
    printf("\n-----------MODULO DE RESERVAS-----------\n");
    printf("1-Fazer uma reserva.\n");
    printf("2-Cancelar uma reserva.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d",&menu);

    switch (menu) {
        case 1:
            printf("Escolha os filtros que deseja para fazer uma reserva.\n");
            main_filtros_txt();
            break;
        case 2:
            main_deleta_reserva_txt();
            break;
        case 3:
            menu_principal_txt();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_reservas();
            break;

    }
}
//Fim do modulo de reservas

//Inicio do modulo de transações
void menu_modulo_transacoes(){
    int menu;
    printf("\n-----------MODULO DE TRANSAÇÕES-----------\n");
    printf("1-Fazer Check-in do hóspede.\n");
    printf("2-Fazer Check-out do hóspede.\n");
    printf("3-Venda de produtos.\n");
    printf("4-Controle de caixa.\n");
    printf("5-Contas a receber.\n");
    printf("6-Entrada de produtos.\n");
    printf("7-Contas a pagar.\n");
    printf("8-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            main_chekin_txt();
            break;
        case 2:
            main_chekout_txt();
            break;
        case 3:
            main_venda_txt();
            break;
        case 4:
            main_caixa_txt();
            break;
        case 5:
            menu_conta_receber();
            break;
        case 6:
            main_entrada_produtos_txt();
            break;
        case 7:
            menu_conta_pagar();
            break;
        case 8:
            menu_principal_txt();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_transacoes();
            break;

    }
}

void menu_conta_receber(){
    int menu;
    printf("\n-----------CONTAS A RECEBER-----------\n");
    printf("1-Dar baixa em nota.\n");
    printf("2-Listar contas a receber.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            main_receber_txt();
            break;
        case 2:
            main_listar_conta_receber_txt();
            break;
        case 3:
            menu_modulo_transacoes();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_conta_receber();
            break;

    }
}

void menu_conta_pagar() {
    int menu;
    printf("\n-----------CONTAS A PAGAR-----------\n");
    printf("1-Dar baixa em nota.\n");
    printf("2-Listar contas a pagar.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
        switch (menu) {
        case 1:
            main_conta_pagar_txt();
            break;
        case 2:
            main_listar_conta_pagar_txt();
            break;
        case 3:
            menu_modulo_transacoes();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_conta_pagar();
            break;

    }
}
//Fim do modulo de transações

//Inicio modulo de feedback
void menu_modulo_feedback() {
    int menu;
    printf("\n-----------MODULO DE FEEDBACK-----------\n");
    printf("1-Listagem de hóspedes.\n");
    printf("2-Listagem de acomodações.\n");
    printf("3-Listagem de reservas.\n");
    printf("4-Listagem de movimentação de acomodações.\n");
    printf("5-Listagem de produtos de consumo.\n");
    printf("6-Listagem de produtos em estoque mínimo.\n");
    printf("7-Listagem de vendas.\n");
    printf("8-Listagem de contas a receber.\n");
    printf("9-Listagem de contas a pagar.\n");
    printf("10-Listagem de movimentação de Caixa.\n");
    printf("11-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            main_listagem_hospede_txt();
            break;
        case 2:
            main_listagem_acomodacoes_txt();
            break;
        case 3:
            main_listagem_reservas_txt();
            break;
        case 4:
            main_listagem_movimento_acomodacoes_txt();
            break;
        case 5:
            main_listagem_produtos_txt();
            break;
        case 6:
            main_listagem_estoque_minimo_txt();
            break;
        case 7:
            main_listagem_vendas_txt();
            break;
        case 8:
            main_listagem_contas_receber_txt();
            break;
        case 9:
            main_listagem_contas_pagar_txt();
            break;
        case 10:
            main_listagem_caixa_txt();
            break;
        case 11:
            menu_principal_txt();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_feedback();
            break;

    }
}
//Fim modulo de feedback


//INICIO DO MODULO DE IMPORTAÇÃO E EXPORTAÇÂO
void menu_modulo_im_exportacao(){
    int menu;
    printf("\n--------MODULO DE IMPORTAÇÃO E EXPORTAÇÃO--------\n");
    printf("1-Deseja importar dados.\n");
    printf("2-Deseja exportar dados.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            main_importar_dados_txt();
            break;
        case 2:
            main_exportar_dados_txt();
            break;
        case 3:
            menu_principal_txt();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_im_exportacao();
            break;

    }
}
//FIM DO MODULO DE IMPORTAÇÃO E EXPORTAÇÂO


//MENU PARA ALTERAR MODULO DE SALVAMENTO
void menu_alterar_salvemento_txt() {
    int menu;
    printf("\n-----------ALTERAR MODO DE SALVAMENTO-----------\n");
    printf("1-Salvamento em binário.\n");
    printf("2-Salvamento em memória.\n");
    printf("3-Voltar.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &menu);
    
        switch (menu) {
        case 1:
            muda_arquivo_txt_p_bin();
            menu_principal_bin();
            break;
        case 2:
            printf("Tudo que for feito a partir daqui sera perdido após encerrar o programa.\n");
            muda_arquivo_txt_p_mem();
            menu_principal_mem();
            break;
        case 3:
            menu_principal_txt();
         break;    
        default:
            printf("\nDigite uma opção válida.\n");
            menu_alterar_salvemento_txt();
            break;

    }
}
//FIM do menu de TXT





//Inicio do menu de BINARIO
void menu_principal_bin() {
    int menu = 0,opcao=0;

    printf("------------------------Bem vindo-------------------------\n ");
    printf("1-Módulo de Cadastros e Gestão de dados.\n");
    printf("2-Módulo de Reservas.\n");
    printf("3-Módulo de Transações.\n");
    printf("4-Módulo de Feedback.\n");
    printf("5-Módulo de importação/exportação de dados.\n");
    printf("6-Alterar modo de salvamento.\n");
    printf("7-Encerrar programa\n");
    printf("Digite a opção que deseja:");
    scanf("%d", &menu);
    
    switch(menu){
        case 1:
            if (permissoes[0] == 1) {
                menu_modulo_cadastro_bin();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_bin();
            }
            break;
        case 2:
            if (permissoes[1] == 1) {
                menu_modulo_reservas_bin();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_bin();
            }
            break;
        case 3:
            if (permissoes[2] == 1) {
                menu_modulo_transacoes_bin();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_bin();
            }
            break; 
        case 4:
           if (permissoes[3] == 1) {
                menu_modulo_feedback_bin();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_bin();
            }
            break; 
        case 5:
            if (permissoes[4] == 1) {
                menu_modulo_im_exportacao_bin();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_bin();
            }
            break; 
        case 6:
           menu_alterar_salvemento_bin();
            break; 
        case 7:
           printf("Saindo...");
            break; 
        default:
            printf("\nDigite uma opção válida.\n");
            menu_principal_bin();
            break;
    }
}

//Inicio Módulo de Cadastros e Gestão de dados
void menu_modulo_cadastro_bin() {
    int menu;
    printf("\n-----------MODULO DE CADASTRO-----------\n");
    printf("1-Gestao de dados do hotel.\n");
    printf("2-Gestao de dados dos operadores.\n");
    printf("3-Gestao de dados dos hospedes.\n");
    printf("4-Gestao de dados dos produtos.\n");
    printf("5-Gestao de dados dos fornecedores.\n");
    printf("6-Gestao de dados das categorias de acomodações.\n");
    printf("7-Gestao de dados das acomodações.\n");
    printf("8-Lista de dados.\n");
    printf("9-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch(menu){
        case 1:
            menu_gestao_hotel_bin();
            break;
        case 2:
            menu_gestao_operadores_bin();
            break;
        case 3:
            menu_gestao_hospedes_bin();
            break; 
        case 4:
           menu_gestao_produtos_bin();
            break; 
        case 5:
            menu_gestao_fornecedor_bin();
            break; 
        case 6:
           menu_gestao_categoria_bin();
            break; 
        case 7:
           menu_gestao_acomodacao_bin();
            break; 
        case 8:
           menu_listas_bin();
            break; 
        case 9:
           menu_principal_bin();
            break; 
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_cadastro_bin();
            break;
        
    }
}

void menu_gestao_hotel_bin() {
    int menu;
    printf("\n-----------GESTÃO DO HOTEL-----------\n");
    printf("1-Cadastro do Hotel.\n");
    printf("2-Atualizar cadastro do hotel.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            main_cadastro_hotel_bin();
            break;
        case 2:
            main_atualiza_hotel_bin();
            break;
        case 3:
            menu_modulo_cadastro_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_hotel_bin();
            break;

    }
}

void menu_gestao_operadores_bin() {
    int menu;
    printf("\n-----------GESTÃO DOS OPERADORES-----------\n");
    printf("1-Cadastro de operadores.\n");
    printf("2-Atualizar operadores.\n");
    printf("3-Deletar operador.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
            switch (menu) {
        case 1:
            main_cadastro_operador_bin();
            break;
        case 2:
            main_atualiza_operador_bin();
            break;
        case 3:
            main_deleta_operador_bin();
            break;
        case 4:
            menu_modulo_cadastro_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_operadores_bin();
            break;

    }
}

void menu_gestao_hospedes_bin() {
    int menu;
    printf("\n-----------GESTÃO DOS HOSPEDES-----------\n");
    printf("1-Cadastro de hospede.\n");
    printf("2-Atualizadar hospede.\n");
    printf("3-Deletar hospede.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            main_cadastro_hospede_bin();
            break;
        case 2:
            main_atualiza_hospede_bin();
            break;
        case 3:
            main_deleta_hospede_bin();
            break;
        case 4:
            menu_modulo_cadastro_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_hospedes_bin();
            break;

    }
}

void menu_gestao_produtos_bin() {
    int menu;
    printf("\n-----------GESTÃO DE PRODUTOS-----------\n");
    printf("1-Cadastrar produto.\n");
    printf("2-Atualizar produto.\n");
    printf("3-Deletar produto.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
     switch (menu) {
        case 1:
            main_cadastro_produtos_bin();
            break;
        case 2:
            main_atualiza_produtos_bin();
            break;
        case 3:
            main_deleta_produtos_bin();
            break;
        case 4:
            menu_modulo_cadastro_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_produtos_bin();
            break;

    }
}

void menu_gestao_fornecedor_bin() {
    int menu;
    printf("\n-----------GESTÃO DE FORNECEDORES-----------\n");
    printf("1-Cadastrar fornecedor.\n");
    printf("2-Atualizar fornecedor.\n");
    printf("3-Deletar fornecedor.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            main_cadastro_fornecedor_bin();
            break;
        case 2:
            main_atualiza_fornecedor_bin();
            break;
        case 3:
            main_deleta_fornecedor_bin();
            break;
        case 4:
            menu_modulo_cadastro_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_fornecedor_bin();
            break;

    }
}

void menu_gestao_categoria_bin() {
    int menu;
    printf("\n-----------GESTÃO DE CATEGORIAS-----------\n");
    printf("1-Cadastrar categoria de acomadação.\n");
    printf("2-Atualizar categoria de acomadação.\n");
    printf("3-Deletar categoria de acomadação.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            main_cadastro_categoria_bin();
            break;
        case 2:
            main_atualiza_categoria_bin();
            break;
        case 3:
            main_deleta_categoria_bin();
            break;
        case 4:
            menu_modulo_cadastro_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_categoria_bin();
            break;

    }
}

void menu_gestao_acomodacao_bin() {
    int menu;
    printf("\n-----------GESTÃO DAS ACOMODAÇÕES-----------\n");
    printf("1-Cadastrar acomodação.\n");
    printf("2-Atualizar acomodação.\n");
    printf("3-Deletar acomodação.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            main_cadastro_acomodacao_bin();
            break;
        case 2:
            main_atualiza_acomodacao_bin();
            break;
        case 3:
            main_deleta_acomodacao_bin();
            break;
        case 4:
            menu_modulo_cadastro_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_acomodacao_bin();
            break;

    }
}

void menu_listas_bin() {
    int menu;
    printf("\n-----------LISTAR DADOS-----------\n");
    printf("1-Dados hotel.\n");
    printf("2-Dados Operadores.\n");
    printf("3-Dados Hospedes.\n");
    printf("4-Dados Produtos.\n");
    printf("5-Dados Fornecedores.\n");
    printf("6-Dados categorias.\n");
    printf("7-Dados acomodações.\n");
    printf("8-Dados Reservas.\n");
    printf("9-Dados conta do hospede.\n");
    printf("10-Dados do caixa.\n");
    printf("11-Dados das contas a receber.\n");
    printf("12-Dados das contas a pagar.\n");
    printf("13-Dados das notas fiscais.\n");
    printf("14-Dados das vendas.\n");
    printf("15-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            dados_hotel_bin();
            menu_listas_bin();
            break;
        case 2:
            dados_operadores_bin();
            menu_listas_bin();
            break;
        case 3:
            dados_hospede_bin();
            menu_listas_bin();
            break;
        case 4:
            dados_produtos_bin();
            menu_listas_bin();
            break;
        case 5:
            dados_fornecedores_bin();
            menu_listas_bin();
            break;
        case 6:
            dados_categorias_bin();
            menu_listas_bin();
            break;
        case 7:
            dados_acomodacoes_bin();
            menu_listas_bin();
            break;
        case 8:
            dados_reservas_bin();
            menu_listas_bin();
            break;
        case 9:
            dados_conta_hospede_bin();
            menu_listas_bin();
            break;
        case 10:
            dados_caixa_bin();
            menu_listas_bin();
            break;
        case 11:
            dados_conta_a_receber_bin();
            menu_listas_bin();
            break;
        case 12:
            dados_conta_a_pagar_bin();
            menu_listas_bin();
            break;
        case 13:
            dados_notasficais_bin();
            menu_listas_bin();
            break;
        case 14:
            dados_venda_bin();
            menu_listas_bin();
            break;
        case 15:
            menu_modulo_cadastro_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_listas_bin();
            break;

    }
}
//Fim Módulo de Cadastros e Gestão de dados


//Inicio do modulo de reservas
void menu_modulo_reservas_bin(){
    cria_reservas_bin();
    
    int menu;
    printf("\n-----------MODULO DE RESERVAS-----------\n");
    printf("1-Fazer uma reserva.\n");
    printf("2-Cancelar uma reserva.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            printf("Escolha os filtros que deseja para fazer uma reserva.\n");
            main_filtros_bin();
            break;
        case 2:
            main_deleta_reserva_bin();
            break;
        case 3:
            menu_principal_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_reservas_bin();
            break;

    }
}

//Inicio do modulo de transações
void menu_modulo_transacoes_bin() {
    int menu;
    printf("\n-----------MODULO DE TRANSAÇÕES-----------\n");
    printf("1-Fazer Check-in do hóspede.\n");
    printf("2-Fazer Check-out do hóspede.\n");
    printf("3-Venda de produtos.\n");
    printf("4-Controle de caixa.\n");
    printf("5-Contas a receber.\n");
    printf("6-Entrada de produtos.\n");
    printf("7-Contas a pagar.\n");
    printf("8-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            main_chekin_bin();
            break;
        case 2:
            main_chekout_bin();
            break;
        case 3:
            main_venda_bin();
            break;
        case 4:
            main_caixa_bin();
            break;
        case 5:
            menu_conta_receber_bin();
            break;
        case 6:
            main_entrada_produtos_bin();
            break;
        case 7:
            menu_conta_pagar_bin();
            break;
        case 8:
            menu_principal_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_transacoes_bin();
            break;

    }
}

void menu_conta_receber_bin() {
    int menu;
    printf("\n-----------CONTAS A RECEBER-----------\n");
    printf("1-Dar baixa em nota.\n");
    printf("2-Listar contas a receber.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            main_receber_bin();
            break;
        case 2:
            main_listar_conta_receber_bin();
            break;
        case 3:
            menu_modulo_transacoes_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_conta_receber_bin();
            break;

    }
}

void menu_conta_pagar_bin() {
    int menu;
    printf("\n-----------CONTAS A PAGAR-----------\n");
    printf("1-Dar baixa em nota.\n");
    printf("2-Listar contas a pagar.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            main_conta_pagar_bin();
            break;
        case 2:
            main_listar_conta_pagar_bin();
            break;
        case 3:
            menu_modulo_transacoes_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_conta_pagar_bin();
            break;

    }
}
//Fim do modulo de transações


//Inicio modulo de feedback
void menu_modulo_feedback_bin() {
    int menu;
    printf("\n-----------MODULO DE FEEDBACK-----------\n");
    printf("1-Listagem de hóspedes.\n");
    printf("2-Listagem de acomodações.\n");
    printf("3-Listagem de reservas.\n");
    printf("4-Listagem de movimentação de acomodações.\n");
    printf("5-Listagem de produtos de consumo.\n");
    printf("6-Listagem de produtos em estoque mínimo.\n");
    printf("7-Listagem de vendas.\n");
    printf("8-Listagem de contas a receber.\n");
    printf("9-Listagem de contas a pagar.\n");
    printf("10-Listagem de movimentação de Caixa.\n");
    printf("11-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            main_listagem_hospede_bin();
            break;
        case 2:
            main_listagem_acomodacoes_bin();
            break;
        case 3:
            main_listagem_reservas_bin();
            break;
        case 4:
            main_listagem_movimento_acomodacoes_bin();
            break;
        case 5:
            main_listagem_produtos_bin();
            break;
        case 6:
            main_listagem_estoque_minimo_bin();
            break;
        case 7:
            main_listagem_vendas_bin();
            break;
        case 8:
            main_listagem_contas_receber_bin();
            break;
        case 9:
            main_listagem_contas_pagar_bin();
            break;
        case 10:
            main_listagem_caixa_bin();
            break;
        case 11:
            menu_principal_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_feedback_bin();
            break;

    }
}
//Fim modulo de feedback

//Inicio do modulo de importação e exportação
void menu_modulo_im_exportacao_bin() {
    int menu;
    printf("\n--------MODULO DE IMPORTAÇÃO E EXPORTAÇÃO--------\n");
    printf("1-Deseja importar dados.\n");
    printf("2-Deseja exportar dados.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            main_importar_dados_bin();
            break;
        case 2:
            main_exportar_dados_bin();
            break;
        case 3:
            menu_principal_bin();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_im_exportacao_bin();
            break;

    }
}

//MENU PARA ALTERAR MODULO DE SALVAMENTO
void menu_alterar_salvemento_bin(){
    int menu;
    printf("\n-----------ALTERAR MODO DE SALVAMENTO-----------\n");
    printf("1-Salvamento em texto.\n");
    printf("2-Salvamento em memória.\n");
    printf("3-Voltar.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            muda_arquivo_bin_p_txt();
            menu_principal_txt();
            break;
        case 2:
            printf("Tudo que for feito a partir daqui sera perdido após encerrar o programa.\n");
            muda_arquivo_bin_p_mem();
            menu_principal_mem();
            break;
        case 3:
            menu_principal_txt();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_alterar_salvemento_txt();
            break;


    }
}
//FIM do menu de BINARIO


///Inicio do menu de MEMORIA
void menu_principal_mem() {
    int menu = 0;

    printf("------------------------Bem vindo-------------------------\n");
    printf("1-Módulo de Cadastros e Gestão de dados.\n");
    printf("2-Módulo de Reservas.\n");
    printf("3-Módulo de Transações.\n");
    printf("4-Módulo de Feedback.\n");
    printf("5-Módulo de importação/exportação de dados.\n");
    printf("6-Alterar modo de salvamento.\n");
    printf("7-Encerrar programa\n");
    printf("Digite a opção que deseja:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            if (permissoes[0] == 1) {
                menu_modulo_cadastro_mem();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_mem();
            }
            break;
        case 2:
            if (permissoes[1] == 1) {
                menu_modulo_reservas_mem();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_mem();
            }
            break;
        case 3:
            if (permissoes[2] == 1) {
                menu_modulo_transacoes_mem();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_mem();
            }
            break;
        case 4:
            if (permissoes[3] == 1) {
                menu_modulo_feedback_mem();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_mem();
            }
            break;
        case 5:
            if (permissoes[4] == 1) {
                menu_modulo_im_exportacao_mem();
            } else {
                printf("Você não tem permissão para esse módulo.\n");
                menu_principal_mem();
            }
            break;
        case 6:
            menu_alterar_salvemento_mem();
            break;
        case 7:
            printf("Saindo...");
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_principal_mem();
            break;
    }
}


//Inicio Módulo de Cadastros e Gestão de dados
void menu_modulo_cadastro_mem() {
    int menu;
    printf("\n-----------MODULO DE CADASTRO-----------\n");
    printf("1-Gestao de dados do hotel.\n");
    printf("2-Gestao de dados dos operadores.\n");
    printf("3-Gestao de dados dos hospedes.\n");
    printf("4-Gestao de dados dos produtos.\n");
    printf("5-Gestao de dados dos fornecedores.\n");
    printf("6-Gestao de dados das categorias de acomodações.\n");
    printf("7-Gestao de dados das acomodações.\n");
    printf("8-Lista de dados.\n");
    printf("9-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            menu_gestao_hotel_mem();
            break;
        case 2:
            menu_gestao_operadores_mem();
            break;
        case 3:
            menu_gestao_hospedes_mem();
            break;
        case 4:
            menu_gestao_produtos_mem();
            break;
        case 5:
            menu_gestao_fornecedor_mem();
            break;
        case 6:
            menu_gestao_categoria_mem();
            break;
        case 7:
            menu_gestao_acomodacao_mem();
            break;
        case 8:
            menu_listas_mem();
            break;
        case 9:
            menu_principal_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_cadastro_mem();
            break;

    }
}

void menu_gestao_hotel_mem() {
    int menu;
    printf("\n-----------GESTÃO DO HOTEL-----------\n");
    printf("1-Cadastro do Hotel.\n");
    printf("2-Atualizar cadastro do hotel.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            cadastro_hotel_mem();
            break;
        case 2:
            atualiza_hotel_mem();
            break;
        case 3:
            menu_modulo_cadastro_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_hotel_mem();
            break;

    }
}

void menu_gestao_operadores_mem() {
    int menu;
    printf("\n-----------GESTÃO DOS OPERADORES-----------\n");
    printf("1-Cadastro de operadores.\n");
    printf("2-Atualizar operadores.\n");
    printf("3-Deletar operador.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            cadastro_operadores_mem();
            break;
        case 2:
            atualiza_operadores_mem();
            break;
        case 3:
            deleta_operadores_mem();
            break;
        case 4:
            menu_modulo_cadastro_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_operadores_mem();
            break;

    }
}

void menu_gestao_hospedes_mem() {
    int menu;
    printf("\n-----------GESTÃO DOS HOSPEDES-----------\n");
    printf("1-Cadastro de hospede.\n");
    printf("2-Atualizadar hospede.\n");
    printf("3-Deletar hospede.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            cadastro_hospede_mem();
            break;
        case 2:
            atualiza_hospede_mem();
            break;
        case 3:
            deleta_hospede_mem();
            break;
        case 4:
            menu_modulo_cadastro_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_hospedes_mem();
            break;

    }
}

void menu_gestao_produtos_mem() {
    int menu;
    printf("\n-----------GESTÃO DE PRODUTOS-----------\n");
    printf("1-Cadastrar produto.\n");
    printf("2-Atualizar produto.\n");
    printf("3-Deletar produto.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            cadastro_produtos_mem();
            break;
        case 2:
            atualiza_produto_mem();
            break;
        case 3:
            deleta_produtos_mem();
            break;
        case 4:
            menu_modulo_cadastro_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_produtos_mem();
            break;

    }
}

void menu_gestao_fornecedor_mem() {
    int menu;
    printf("\n-----------GESTÃO DE FORNECEDORES-----------\n");
    printf("1-Cadastrar fornecedor.\n");
    printf("2-Atualizar fornecedor.\n");
    printf("3-Deletar fornecedor.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            cadastro_fornecedores_mem();
            break;
        case 2:
            atualiza_fornecedores_mem();
            break;
        case 3:
            deleta_fornecedores_mem();
            break;
        case 4:
            menu_modulo_cadastro_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_fornecedor_mem();
            break;

    }
}

void menu_gestao_categoria_mem() {
    int menu;
    printf("\n-----------GESTÃO DE CATEGORIAS-----------\n");
    printf("1-Cadastrar categoria de acomadação.\n");
    printf("2-Atualizar categoria de acomadação.\n");
    printf("3-Deletar categoria de acomadação.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            cadastra_categoria_mem();
            break;
        case 2:
            atualiza_categoria_mem();
            break;
        case 3:
            deleta_categoria_mem();
            break;
        case 4:
            menu_modulo_cadastro_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_categoria_mem();
            break;

    }
}

void menu_gestao_acomodacao_mem() {
    int menu;
    printf("\n-----------GESTÃO DAS ACOMODAÇÕES-----------\n");
    printf("1-Cadastrar acomodação.\n");
    printf("2-Atualizar acomodação.\n");
    printf("3-Deletar acomodação.\n");
    printf("4-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            cadastro_acomodacao_mem();
            break;
        case 2:
            atualiza_acomodacoes_mem();
            break;
        case 3:
            deleta_acomodacoes_mem();
            break;
        case 4:
            menu_modulo_cadastro_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_gestao_acomodacao_mem();
            break;

    }
}

void menu_listas_mem() {
    cad_hotel hotel;
    OPsistema op;
    hospedes hospede;
    produtos produto;
    fornecedores fornecedor;
    categoria_acomodacao categoria;
    acomodacoes acomodacao;
    reservas reserva;

    int menu;
    printf("\n-----------LISTAR DADOS-----------\n");
    printf("1-Dados hotel.\n");
    printf("2-Dados Operadores.\n");
    printf("3-Dados Hospedes.\n");
    printf("4-Dados Produtos.\n");
    printf("5-Dados Fornecedores.\n");
    printf("6-Dados categorias.\n");
    printf("7-Dados acomodações.\n");
    printf("8-Dados Reservas.\n");
    printf("9-Dados conta do hospede.\n");
    printf("10-Dados do caixa.\n");
    printf("11-Dados das contas a receber.\n");
    printf("12-Dados das contas a pagar.\n");
    printf("13-Dados das notas fiscais.\n");
    printf("14-Dados das vendas.\n");
    printf("15-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            dadosHotel();
            menu_listas_mem();
            break;
        case 2:
            dadosOperador();
            menu_listas_mem();
            break;
        case 3:
            dadosHospede();
            menu_listas_mem();
            break;
        case 4:
            dadosProdutos();
            menu_listas_mem();
            break;
        case 5:
            dadosFornecedor();
            menu_listas_mem();
            break;
        case 6:
            dadosCategoria();
            menu_listas_mem();
            break;
        case 7:
            dadosAcomodacao();
            menu_listas_mem();
            break;
        case 8:
            dadosReserva();
            menu_listas_mem();
            break;
        case 9:
            dadosContaHospede();
            menu_listas_mem();
            break;
        case 10:
            dadosCaixa();
            menu_listas_mem();
            break;
        case 11:
            dadosContaReceber();
            menu_listas_mem();
            break;
        case 12:
            dadosContaPagar();
            menu_listas_mem();
            break;
        case 13:
            dadosNotaFiscal();
            menu_listas_mem();
            break;
        case 14:
            dadosVenda();
            menu_listas_mem();
            break;
        case 15:
            menu_modulo_cadastro_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_listas_mem();
            break;

    }
}
//Fim Módulo de Cadastros e Gestão de dados


//Inicio do modulo de reservas
void menu_modulo_reservas_mem() {


    int menu;
    printf("\n-----------MODULO DE RESERVAS-----------\n");
    printf("1-Fazer uma reserva.\n");
    printf("2-Cancelar uma reserva.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            printf("Escolha os filtros que deseja para fazer uma reserva.\n");
            filtros_mem();
            break;
        case 2:
            deleta_reservas_mem();
            break;
        case 3:
            menu_principal_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_reservas_mem();
            break;

    }
}

//Inicio do modulo de transações
void menu_modulo_transacoes_mem() {
    int menu;
    printf("\n-----------MODULO DE TRANSAÇÕES-----------\n");
    printf("1-Fazer Check-in do hóspede.\n");
    printf("2-Fazer Check-out do hóspede.\n");
    printf("3-Venda de produtos.\n");
    printf("4-Controle de caixa.\n");
    printf("5-Contas a receber.\n");
    printf("6-Entrada de produtos.\n");
    printf("7-Contas a pagar.\n");
    printf("8-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            chekin_mem();
            break;
        case 2:
            chekout_mem();
            break;
        case 3:
            venda_mem();
            break;
        case 4:
            caixa_mem();
            break;
        case 5:
            menu_conta_receber_mem();
            break;
        case 6:
            entrada_produtos_mem();
            break;
        case 7:
            menu_conta_pagar_mem();
            break;
        case 8:
            menu_principal_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_transacoes_mem();
            break;

    }
}

void menu_conta_receber_mem() {
    int menu;
    printf("\n-----------CONTAS A RECEBER-----------\n");
    printf("1-Dar baixa em nota.\n");
    printf("2-Listar contas a receber.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            receber_mem();
            break;
        case 2:
            listar_conta_receber_mem();
            break;
        case 3:
            menu_modulo_transacoes_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_conta_receber_mem();
            break;

    }
}

void menu_conta_pagar_mem() {
    int menu;
    printf("\n-----------CONTAS A PAGAR-----------\n");
    printf("1-Dar baixa em nota.\n");
    printf("2-Listar contas a pagar.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            //conta_pagar_mem();
            break;
        case 2:
            //listar_conta_pagar_mem();
            break;
        case 3:
            menu_modulo_transacoes_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_conta_pagar_mem();
            break;

    }
}
//Fim do modulo de transações


//Inicio modulo de feedback
void menu_modulo_feedback_mem() {
    int menu;
    printf("\n-----------MODULO DE FEEDBACK-----------\n");
    printf("1-Listagem de hóspedes.\n");
    printf("2-Listagem de acomodações.\n");
    printf("3-Listagem de reservas.\n");
    printf("4-Listagem de movimentação de acomodações.\n");
    printf("5-Listagem de produtos de consumo.\n");
    printf("6-Listagem de produtos em estoque mínimo.\n");
    printf("7-Listagem de vendas.\n");
    printf("8-Listagem de contas a receber.\n");
    printf("9-Listagem de contas a pagar.\n");
    printf("10-Listagem de movimentação de Caixa.\n");
    printf("11-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            listagem_hospede_mem();
            break;
        case 2:
            listagem_acomodacoes_mem();
            break;
        case 3:
            listagem_reservas_mem();
            break;
        case 4:
            listagem_movimento_acomodacoes_mem();
            break;
        case 5:
            listagem_produtos_mem();
            break;
        case 6:
            listagem_estoque_minimo_mem();
            break;
        case 7:
            listagem_vendas_mem();
            break;
        case 8:
            listagem_contas_receber_mem();
            break;
        case 9:
            listagem_contas_pagar_mem();
            break;
        case 10:
            listagem_caixa_mem();
            break;
        case 11:
            menu_principal_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_feedback_mem();
            break;

    }
}
//Fim modulo de feedback


//INICIO DO MODULO DE IMPORTAÇÃO E EXPORTAÇÂO
void menu_modulo_im_exportacao_mem() {
    int menu;
    printf("\n--------MODULO DE IMPORTAÇÃO E EXPORTAÇÃO--------\n");
    printf("1-Deseja importar dados.\n");
    printf("2-Deseja exportar dados.\n");
    printf("3-Voltar.\n");
    printf("Opção:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            importar_dados_mem();
            break;
        case 2:
            exportar_dados_mem();
            break;
        case 3:
            menu_principal_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_modulo_im_exportacao();
            break;

    }
}
//FIM DO MODULO DE IMPORTAÇÃO E EXPORTAÇÂO

//menu para alterar modo de salvamento
void menu_alterar_salvemento_mem() {
    int menu;
    printf("\n-----------ALTERAR MODO DE SALVAMENTO-----------\n");
    printf("Lembrando todos dados salvos em memória serão perdidos.\n");
    printf("1-Salvamento em texto.\n");
    printf("2-Salvamento em binário.\n");
    printf("3-Voltar.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            login_txt();
            break;
        case 2:
            login_bin();
            break;
        case 3:
            menu_principal_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            menu_alterar_salvemento_mem();
            break;


    }
}

//FIM do menu de MEMORIA