#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Structs.h"
#include "Funcoes.h"
#include "memoria.h"
#include "menu.h"
#include "arquivosTXT.h"
#include "arquivosBin.h"

cad_hotel hotel;

OPsistema *operador = NULL;
int qtd_ope = 0;

hospedes *hospede = NULL;
int qtd_hos = 0;

produtos *produto = NULL;
int qtd_pro = 0;

fornecedores *fornecedor = NULL;
int qtd_forn = 0;

categoria_acomodacao *categoria = NULL;
int qtd_cat = 0;

acomodacoes *acomodacao = NULL;
int qtd_acomd = 0;

reservas *disponiveis = NULL;
int qtd_dis=0;
reservas *reserva = NULL;
int qtd_res = 0;

conta_hospede *conta;
int qtd_con = 0;

conta_receber *conta_rec;
int qtd_con_rec=0;

conta_receber *caixa;
int qtd_cai=0;

vendas *venda;
int qtd_venda=0;

conta_receber *conta_pag;
int qtd_con_pag=0;

NotaFiscal *notas;
int qtd_notas=0;

void login_mem() {

    qtd_ope++;
    operador = (OPsistema *) realloc(operador, qtd_ope * sizeof (OPsistema));


    if (operador == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("Vejo que é a primeira vez que inicia o program, logo cadastre um operador chefe.\n");
    printf("------Dados do Operador-------\n");
    printf("Digite o código do operador:");
    scanf("%d", &operador[0].codigo);
    printf("Digite o nome do operador:");
    scanf(" %[^\n]s%*c", operador[0].nome);
    setbuf(stdin, NULL);
    printf("Digite o nome de usuário do operador:");
    scanf(" %[^\n]s%*c", operador[0].usuario);
    setbuf(stdin, NULL);
    printf("Digite a senha do operador (Somente números):");
    scanf("%d", &operador[0].senha);

    // Configuração de permissões padrão
    operador[0].permissoes.cadastros = 1;
    operador[0].permissoes.feedback = 1;
    operador[0].permissoes.im_exportacao = 1;
    operador[0].permissoes.reservas = 1;
    operador[0].permissoes.transacoes = 1;



    printf("Agora cadastre o hotel para começar desfrutar do programa.\n");
    //Recebendo dados do hotel
    printf("-------CADASTRO DO HOTEL-------\n");
    printf("Digite o nome fantasia:");
    scanf(" %[^\n]s%*c", hotel.nome_fantasia);
    setbuf(stdin, NULL);
    printf("Digite a razão social:");
    scanf(" %[^\n]s%*c", hotel.razao_social);
    setbuf(stdin, NULL);
    printf("Digite a inscrição estadual:");
    scanf(" %[^\n]s%*c", hotel.inscricao_estadual);
    setbuf(stdin, NULL);
    printf("Digite o CNPJ:");
    scanf(" %[^\n]s%*c", hotel.cnpj);
    setbuf(stdin, NULL);
    printf("-------ENDEREÇO-------\n");
    printf("Digite o estado:");
    scanf(" %[^\n]s%*c", hotel.endereco.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade:");
    scanf(" %[^\n]s%*c", hotel.endereco.cidade);
    setbuf(stdin, NULL);
    printf("Digite o CEP:");
    scanf(" %[^\n]s%*c", &hotel.endereco.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro:");
    scanf(" %[^\n]s%*c", hotel.endereco.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua:");
    scanf(" %[^\n]s%*c", hotel.endereco.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero:");
    scanf("%d", &hotel.endereco.numero);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Digite o telefone do hotel:");
    scanf(" %[^\n]s%*c", hotel.telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do hotel:");
    scanf(" %[^\n]s%*c", hotel.email);
    setbuf(stdin, NULL);
    printf("Digite o nome do responsável:");
    scanf(" %[^\n]s%*c", hotel.nome_responsavel);
    setbuf(stdin, NULL);
    printf("Digite o telefone do responsável:");
    scanf(" %[^\n]s%*c", hotel.telefone_responsavel);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------HORÁRIO DE CHECK-IN-------\n");
    printf("Digite a hora do chekin(SOMENTE HORA):");
    scanf("%d", &hotel.horario_checkin.hora);
    setbuf(stdin, NULL);
    printf("Digite os minutos do chekin(SOMENTE MINUTOS):");
    scanf("%d", &hotel.horario_checkin.minutos);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------HORÁRIO DE CHECK-OUT-------\n");
    printf("Digite a hora do chek-out(SOMENTE HORA):");
    scanf("%d", &hotel.horario_checkout.hora);
    setbuf(stdin, NULL);
    printf("Digite os minutos do chek-out(SOMENTE MINUTOS):");
    scanf("%d", &hotel.horario_checkout.minutos);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("Digite a margem de lucro sobre os produtos:");
    scanf("%f", &hotel.mlpv);
    setbuf(stdin, NULL);

    permissoes_login(operador, 0);
    menu_principal_mem();
}


//INICIO DO MODULO DE CADASTRO


//COMECO DO HOTEL
void cadastro_hotel_mem() {
    int opcao;

    printf("Se você cadastrar um hotel perderá  o antigo, realmente deseja cadastrar?(1-Sim/2-Não):");
    scanf("%d", &opcao);
    if (opcao == 2) {

    }
    printf("-------CADASTRO DO HOTEL-------\n");
    printf("Digite o nome fantasia:");
    scanf(" %[^\n]s%*c", hotel.nome_fantasia);
    setbuf(stdin, NULL);
    printf("Digite a razão social:");
    scanf(" %[^\n]s%*c", hotel.razao_social);
    setbuf(stdin, NULL);
    printf("Digite a inscrição estadual:");
    scanf(" %[^\n]s%*c", hotel.inscricao_estadual);
    setbuf(stdin, NULL);
    printf("Digite o CNPJ:");
    scanf(" %[^\n]s%*c", hotel.cnpj);
    setbuf(stdin, NULL);
    printf("-------ENDEREÇO-------\n");
    printf("Digite o estado:");
    scanf(" %[^\n]s%*c", hotel.endereco.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade:");
    scanf(" %[^\n]s%*c", hotel.endereco.cidade);
    setbuf(stdin, NULL);
    printf("Digite o CEP:");
    scanf(" %[^\n]s%*c", &hotel.endereco.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro:");
    scanf(" %[^\n]s%*c", hotel.endereco.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua:");
    scanf(" %[^\n]s%*c", hotel.endereco.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero:");
    scanf("%d", &hotel.endereco.numero);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Digite o telefone do hotel:");
    scanf(" %[^\n]s%*c", hotel.telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do hotel:");
    scanf(" %[^\n]s%*c", hotel.email);
    setbuf(stdin, NULL);
    printf("Digite o nome do responsável:");
    scanf(" %[^\n]s%*c", hotel.nome_responsavel);
    setbuf(stdin, NULL);
    printf("Digite o telefone do responsável:");
    scanf(" %[^\n]s%*c", hotel.telefone_responsavel);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------HORÁRIO DE CHECK-IN-------\n");
    printf("Digite a hora do chekin(SOMENTE HORA):");
    scanf("%d", &hotel.horario_checkin.hora);
    setbuf(stdin, NULL);
    printf("Digite os minutos do chekin(SOMENTE MINUTOS):");
    scanf("%d", &hotel.horario_checkin.minutos);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------HORÁRIO DE CHECK-OUT-------\n");
    printf("Digite a hora do chek-out(SOMENTE HORA):");
    scanf("%d", &hotel.horario_checkout.hora);
    setbuf(stdin, NULL);
    printf("Digite os minutos do chek-out(SOMENTE MINUTOS):");
    scanf("%d", &hotel.horario_checkout.minutos);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("Digite a margem de lucro sobre os produtos:");
    scanf("%f", &hotel.mlpv);
    setbuf(stdin, NULL);
    menu_gestao_hotel_mem();
}

void atualiza_hotel_mem() {
    //variaveis para trazer dados do hotel para ram
    int opcao;



    printf("----------Atualizar dados do hotel----------\n");
    printf("Dados atuais do hotel.\n");
    printf("Nome fantasia:%s\n", hotel.nome_fantasia);
    printf("Razão social:%s\n", hotel.razao_social);
    printf("Inscrição estadual:%s\n", hotel.inscricao_estadual);
    printf("CNPJ:%s\n", hotel.cnpj);
    printf("-------ENDEREÇO-------\n");
    printf("Estado:%s\n", hotel.endereco.estado);
    printf("Cidade:%s\n", hotel.endereco.cidade);
    printf("CEP:%s\n", hotel.endereco.cep);
    printf("Bairro:%s\n", hotel.endereco.bairro);
    printf("Rua:%s\n", hotel.endereco.rua);
    printf("Numero de endereço:%d\n", hotel.endereco.numero);
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Telefone do hotel:%s\n", hotel.telefone);
    printf("E-mail do hotel:%s\n", hotel.email);
    printf("Nome do responsável:%s\n", hotel.nome_responsavel);
    printf("Telefone do responsável:%s\n", hotel.telefone_responsavel);
    printf("-------HORÁRIO DE CHECK-IN-------\n");
    printf("%d:%d\n", hotel.horario_checkin.hora, hotel.horario_checkin.minutos);
    printf("-------HORÁRIO DE CHECK-OUT-------\n");
    printf("%d:%d\n", hotel.horario_checkout.hora, hotel.horario_checkout.minutos);
    printf("Margem de lucro sobre os produtos:%f\n", hotel.mlpv);
    printf("Deseja alterar o nome fantasia?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo nome fantasia:");
        scanf(" %[^\n]s%*c", hotel.nome_fantasia);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar a razão social?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova razão social:");
        scanf(" %[^\n]s%*c", hotel.razao_social);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar a inscrição estadual?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova inscrição estadual:");
        scanf(" %[^\n]s%*c", hotel.inscricao_estadual);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o CNPJ?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo CNPJ:");
        scanf(" %[^\n]s%*c", hotel.cnpj);
        setbuf(stdin, NULL);
    }
    printf("-------ENDEREÇO-------\n");
    printf("Deseja alterar o Estado?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo estado:");
        scanf(" %[^\n]s%*c", hotel.endereco.estado);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar a cidade?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova cidade:");
        scanf(" %[^\n]s%*c", hotel.endereco.cidade);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o CEP?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo CEP:");
        scanf(" %[^\n]s%*c", &hotel.endereco.cep);
        setbuf(stdin, NULL);
    }

    printf("Deseja alterar o bairro?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo bairro:");
        scanf(" %[^\n]s%*c", hotel.endereco.bairro);
        setbuf(stdin, NULL);
    }

    printf("Deseja alterar a rua?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova rua:");
        scanf(" %[^\n]s%*c", hotel.endereco.rua);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o numero de endereço?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo numero de endereço:");
        scanf("%d", &hotel.endereco.numero);
        setbuf(stdin, NULL);
    }
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Deseja alterar o telefone do hotel?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo telefone do hotel:");
        scanf(" %[^\n]s%*c", hotel.telefone);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o e-mail do hotel?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o e-mail do hotel:");
        scanf(" %[^\n]s%*c", hotel.email);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o nome do responsável do hotel?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo nome do responsável:");
        scanf(" %[^\n]s%*c", hotel.nome_responsavel);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o telefone do responsável do hotel?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo telefone do responsável:");
        scanf(" %[^\n]s%*c", hotel.telefone_responsavel);
        setbuf(stdin, NULL);
    }
    printf("-------HORÁRIO DE CHECK-IN-------\n");
    printf("Deseja alterar a hora do chek-in?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova hora do chekin(SOMENTE HORA):");
        scanf("%d", &hotel.horario_checkin.hora);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o minuto do chek-in?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite os minutos do chekin(SOMENTE MINUTOS):");
        scanf("%d", &hotel.horario_checkin.minutos);
        setbuf(stdin, NULL);
    }
    printf("-------HORÁRIO DE CHECK-OUT-------\n");
    printf("Deseja alterar a hora do chek-out?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova hora do chek-out(SOMENTE HORA):");
        scanf("%d", &hotel.horario_checkout.hora);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o minuto do chek-out?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite os minutos do chek-out(SOMENTE MINUTOS):");
        scanf("%d", &hotel.horario_checkout.minutos);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar a margem de lucro sobre os produtos?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova margem de lucro sobre os produtos:");
        scanf("%f", &hotel.mlpv);
        setbuf(stdin, NULL);
    }


    menu_gestao_hotel_mem();
}
//FIM DO HOTEL

//INICIO DO OPERADOR

int cadastro_operadores_mem() {
    //variaveis para cadastro de operadores
    qtd_ope++;
    operador = (OPsistema *) realloc(operador, qtd_ope * sizeof (OPsistema));
    int indicie = qtd_ope - 1;






    printf("------Dados do Operador-------\n");
    if (indicie == 0) {
        operador[indicie].codigo = 1;
    } else {
        operador[indicie].codigo = operador[indicie - 1].codigo + 1;
    }

    printf("Seu código do operador será: %d.\n", operador[indicie].codigo);
    printf("Digite o nome do operador:");
    scanf(" %[^\n]s%*c", operador[indicie].nome);
    setbuf(stdin, NULL);
    printf("Digite o nome de usuário do operador:");
    scanf(" %[^\n]s%*c", operador[indicie].usuario);
    setbuf(stdin, NULL);
    printf("Digite a senha do operador (Somente números):");
    scanf("%d", &operador[indicie].senha);

    printf("-------Permissões-------\n");
    printf("Cadastros:(1-Permitir/0-Negar)");
    scanf("%d", &operador[indicie].permissoes.cadastros);
    setbuf(stdin, NULL);
    printf("Reservas:(1-Permitir/0-Negar)");
    scanf("%d", &operador[indicie].permissoes.reservas);
    setbuf(stdin, NULL);
    printf("Transações:(1-Permitir/0-Negar)");
    scanf("%d", &operador[indicie].permissoes.transacoes);
    setbuf(stdin, NULL);
    printf("FeedBack:(1-Permitir/0-Negar)");
    scanf("%d", &operador[indicie].permissoes.feedback);
    setbuf(stdin, NULL);
    printf("Importações e Exportações:(1-Permitir/0-Negar)");
    scanf("%d", &operador[indicie].permissoes.im_exportacao);
    setbuf(stdin, NULL);

    menu_gestao_operadores_mem();
}

int atualiza_operadores_mem() {
    //variaveis utlizadas atualizar operadores
    int sair = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0;

    printf("-------ATUALIZAR DADOS DOS OPERADORES-------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do operador que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o operadores
        posicao = procura_operador_txt(codigo, qtd_ope, operador);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo de operador nao encontrado\n");
            contador_erro++;
        } else {
            //caso o operadore exista o laço se quebra e segue o codigo
            printf("Operador encontrado\n");
            contador_erro = 0;
            break;
        }
        if (contador_erro > 3) {
            printf("Foi detectado muitos erros do codigo do operador, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_operadores_mem();

        }

    } while (posicao == -1);

    printf("------Dados do operador------\n");
    printf("Codigo:%d\n", operador[posicao].codigo);
    printf("Nome: %s\n", operador[posicao].nome);
    printf("Nome de usuário:%s\n", operador[posicao].usuario);
    printf("Senha:%d\n", operador[posicao].senha);

    if (operador[posicao].permissoes.cadastros == 0 && operador[posicao].permissoes.reservas == 0 && operador[posicao].permissoes.transacoes == 0
            && operador[posicao].permissoes.feedback == 0 && operador[posicao].permissoes.im_exportacao == 0) {
        printf("Nenhuma permissão ativa\n");
    } else {
        printf("------Pemissões Atividas------\n");
        if (operador[posicao].permissoes.cadastros == 1) {
            printf("Cadastro\n");
        }
        if (operador[posicao].permissoes.reservas == 1) {
            printf("Reservas\n");
        }
        if (operador[posicao].permissoes.transacoes == 1) {
            printf("Transações\n");
        }
        if (operador[posicao].permissoes.feedback == 1) {
            printf("Feedback\n");
        }
        if (operador[posicao].permissoes.im_exportacao == 1) {
            printf("Importação e Exportações\n");
        }
    }

    printf("Deseja alterar qual dados do operador?(Digite a opção desejada)\n");
    printf("1-Nome\n2-Nome do usuário\n3-Senha\n4-Permissões\n5-Todos");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            printf("Digite o novo nome do operador:");
            scanf(" %[^\n]s%*c", operador[posicao].nome);
            setbuf(stdin, NULL);

            break;
        case 2:
            printf("Digite o novo nome do usuarior:");
            scanf(" %[^\n]s%*c", operador[posicao].usuario);
            setbuf(stdin, NULL);
            break;
        case 3:
            printf("Digite a nova senha:");
            scanf(" %[^\n]s%*c", operador[posicao].senha);
            setbuf(stdin, NULL);
            printf("%d", operador[posicao].senha);
            break;
        case 4:
            printf("-------Permissoões-------\n");
            printf("Cadastros:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.cadastros);
            setbuf(stdin, NULL);
            printf("Reservas:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.reservas);
            setbuf(stdin, NULL);
            printf("Transações:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.transacoes);
            setbuf(stdin, NULL);
            printf("FeedBack:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.feedback);
            setbuf(stdin, NULL);
            printf("Importações e Exportações:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.im_exportacao);
            setbuf(stdin, NULL);
            break;
        case 5:
            printf("Digite o nome do operador:");
            scanf(" %[^\n]s%*c", operador[posicao].nome);
            setbuf(stdin, NULL);
            printf("Digite o nome do usario:");
            scanf(" %[^\n]s%*c", operador[posicao].usuario);
            setbuf(stdin, NULL);
            printf("Digite a senha para o usuario:");
            scanf("%d", &operador[posicao].senha);
            setbuf(stdin, NULL);
            printf("-------PERMISSÕES-------\n");
            printf("Cadastros:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.cadastros);
            setbuf(stdin, NULL);
            printf("Reservas:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.reservas);
            setbuf(stdin, NULL);
            printf("Transações:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.transacoes);
            setbuf(stdin, NULL);
            printf("FeedBack:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.feedback);
            setbuf(stdin, NULL);
            printf("Importações e Exportações:(1-Permitir/0-Negar)");
            scanf("%d", &operador[posicao].permissoes.im_exportacao);
            setbuf(stdin, NULL);
            break;
    }
    menu_gestao_operadores_mem();
}

void deleta_operadores_mem() {
    //variaveis utlizadas deletar operadores
    int codigo = 0, contador_erro = 0, posicao = 0, opcao = 0, sair = 0, delete = 0;

    printf("------Deleção de hospede-------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do hospede que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar o operadores
        posicao = procura_hospede_txt(codigo, qtd_ope, operador);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo do hospede nao encontrado\n");
            contador_erro = 0;
        } else {
            //caso o operadore exista o laço se quebra e segue o codigo
            printf("Hospede encontrado\n");
            contador_erro = 0;
            break;
        }
        if (contador_erro > 3) {
            printf("Foi detectado muitos erros do codigo do hospede, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_hospedes_mem();
        }
    } while (posicao == -1);

    printf("------Dados do operador------\n");
    printf("Codigo:%d\n", operador[posicao].codigo);
    printf("Nome: %s\n", operador[posicao].nome);
    printf("Nome de usuário:%s\n", operador[posicao].usuario);
    printf("Senha:%d\n", operador[posicao].senha);

    if (operador[posicao].permissoes.cadastros == 0 && operador[posicao].permissoes.reservas == 0 && operador[posicao].permissoes.transacoes == 0
            && operador[posicao].permissoes.feedback == 0 && operador[posicao].permissoes.im_exportacao == 0) {
        printf("Nenhuma permissão ativa.\n");
    } else {
        printf("------Pemissões Atividas------\n");
        if (operador[posicao].permissoes.cadastros == 1) {
            printf("Cadastro.\n");
        }
        if (operador[posicao].permissoes.reservas == 1) {
            printf("Reservas.\n");
        }
        if (operador[posicao].permissoes.transacoes == 1) {
            printf("Transações.\n");
        }
        if (operador[posicao].permissoes.feedback == 1) {
            printf("Feedback.\n");
        }
        if (operador[posicao].permissoes.im_exportacao == 1) {
            printf("Importação e Exportações.\n");
        }
    }
    printf("Deseja realmente deletar esse operador?(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        for (int i = posicao; i < qtd_ope; i++) {//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente

            operador[i] = operador[i + 1];
        }
        qtd_ope--;
        operador = (OPsistema *) realloc(operador, qtd_ope * sizeof (OPsistema));

    }
    menu_gestao_operadores_mem();
}
//FIM DO OPERADOR

//COMEÇO HOSPEDE

void cadastro_hospede_mem() {
    //variaveis para cadastro de hospedes
    qtd_hos++;
    hospede = (hospedes *) realloc(hospede, qtd_hos * sizeof (hospedes));

    int indicie = qtd_hos - 1;




    printf("-------Cadastros de Hospedes--------\n");
    if (indicie == 0) {
        hospede[indicie].codigo = 1;
    } else {
        hospede[indicie].codigo = hospede[indicie - 1].codigo + 1;
    }
    printf("O código do hospede será %d.\n", hospede[indicie].codigo);
    printf("Digite o nome do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].nome);
    setbuf(stdin, NULL);
    printf("----Dados de endereço do Hospede----\n");
    printf("Digite o estado do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].endereco_hospede.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].endereco_hospede.cidade);
    setbuf(stdin, NULL);
    printf("Digite a cep do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].endereco_hospede.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].endereco_hospede.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].endereco_hospede.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero de endereço do hospede:");
    scanf("%d", &hospede[indicie].endereco_hospede.numero);
    setbuf(stdin, NULL);
    printf("----Dados pessoais do hospede-----\n");
    printf("Digite o CPF do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].cpf);
    setbuf(stdin, NULL);
    printf("Digite o telefone do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].email);
    setbuf(stdin, NULL);
    printf("Digite o sexo do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].sexo);
    setbuf(stdin, NULL);
    printf("Digite o estado civil do hospede:");
    scanf(" %[^\n]s%*c", hospede[indicie].estado_civil);
    setbuf(stdin, NULL);
    printf("Digite a data de nascimento do hospede.\n");
    printf("Dia:");
    scanf("%d", &hospede[indicie].data_nacimento.dia);
    setbuf(stdin, NULL);
    printf("Mês:");
    scanf("%d", &hospede[indicie].data_nacimento.mes);
    setbuf(stdin, NULL);
    printf("Ano:");
    scanf("%d", &hospede[indicie].data_nacimento.ano);
    setbuf(stdin, NULL);
    
    listagem_hospede_mem();
    menu_gestao_hospedes_mem();

}

void atualiza_hospede_mem() {
    int posicao, codigo, contador_erro = 0, sair = 0, opcao;

    printf("-------Atualizar Hospede-------\n");

    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do hospede que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o operadores
        posicao = procura_hospede_txt(codigo, qtd_hos, hospede);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo do hospede nao encontrado\n");
            contador_erro++;
        } else {
            //caso o operadore exista o laço se quebra e segue o codigo
            printf("Hospede encontrado\n");
            contador_erro = 0;
            break;
        }
        if (contador_erro > 3) {
            printf("Foi detectado muitos erros do codigo do hospede, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_hospedes_mem();
        }

    } while (posicao == -1);
    printf("O codigo atual do hospede é: %d.\n", hospede[posicao].codigo);
    printf("O nome atual do hospede é: %s.\n", hospede[posicao].nome);
    printf("Deseja alterar o nome do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo nome:");
        scanf(" %[^\n]s%*c", &hospede[posicao].nome);
    }
    printf("-----Dados de Endereço-------\n");
    printf("O estado atual do hospede é: %s.\n", hospede[posicao].endereco_hospede.estado);
    printf("Deseja alterar o estado do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estado:");
        scanf(" %[^\n]s%*c", &hospede[posicao].endereco_hospede.estado);
    }
    printf("A cidade atual do hospede é: %s.\n", hospede[posicao].endereco_hospede.cidade);
    printf("Deseja alterar a cidade do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova cidade:");
        scanf(" %[^\n]s%*c", &hospede[posicao].endereco_hospede.cidade);
    }
    printf("O CEP atual do hospede é: %s.\n", hospede[posicao].endereco_hospede.cep);
    printf("Deseja alterar o CEP do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo CEP:");
        scanf(" %[^\n]s%*c", &hospede[posicao].endereco_hospede.cep);
    }
    printf("O bairro atual do hospede é: %s.\n", hospede[posicao].endereco_hospede.bairro);
    printf("Deseja alterar o bairro do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo bairro:");
        scanf(" %[^\n]s%*c", &hospede[posicao].endereco_hospede.bairro);
    }
    printf("A rua atual do hospede é: %s.\n", hospede[posicao].endereco_hospede.rua);
    printf("Deseja alterar a rua do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova rua:");
        scanf(" %[^\n]s%*c", &hospede[posicao].endereco_hospede.rua);
    }
    printf("O número de endereço atual do hospede é: %d.\n", hospede[posicao].endereco_hospede.numero);
    printf("Deseja alterar o numero de endereço do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo endereço:");
        scanf("%d", &hospede[posicao].endereco_hospede.numero);
    }
    printf("-------Dado Pessoais--------\n");
    printf("O CPF atual do hospede é: %s.\n", hospede[posicao].cpf);
    printf("Deseja alterar o CEP do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo endereço:");
        scanf(" %[^\n]s%*c", &hospede[posicao].cpf);
    }
    printf("O telefone atual do hospede é: %s.\n", hospede[posicao].telefone);
    printf("Deseja alterar o telefone do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo telefone:");
        scanf(" %[^\n]s%*c", &hospede[posicao].telefone);
    }
    printf("O E-mail atual do hospede é: %s.\n", hospede[posicao].email);
    printf("Deseja alterar o E-mail do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo E-mail:");
        scanf(" %[^\n]s%*c", &hospede[posicao].email);
    }
    printf("O sexo atual do hospede é: %s.\n", hospede[posicao].sexo);
    printf("Deseja alterar o sexo do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo sexo:");
        scanf(" %[^\n]s%*c", &hospede[posicao].sexo);
    }
    printf("O estado civil atual do hospede é: %s.\n", hospede[posicao].estado_civil);
    printf("Deseja alterar o estado civil do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estado civil:");
        scanf(" %[^\n]s%*c", &hospede[posicao].estado_civil);
    }
    printf("O dia de nascimento atual do hospede é: %d.\n", hospede[posicao].data_nacimento.dia);
    printf("Deseja alterar o dia de nascimento do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo dia de nascimento:");
        scanf("%d", &hospede[posicao].data_nacimento.dia);
    }
    printf("O mes de nascimento atual do hospede é: %d.\n", hospede[posicao].data_nacimento.mes);
    printf("Deseja alterar o mes de nascimento do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo mes de nascimento:");
        scanf("%d", &hospede[posicao].data_nacimento.mes);
    }
    printf("O ano de nascimento atual do hospede é: %d.\n", hospede[posicao].data_nacimento.mes);
    printf("Deseja alterar o ano de nascimento do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo ano de nascimento:");
        scanf("%d", &hospede[posicao].data_nacimento.mes);
    }
    menu_gestao_hospedes_mem();

}

void deleta_hospede_mem() {
    //variaveis utlizadas deletar hospede
    int codigo = 0, contador_erro = 0, posicao = 0, opcao = 0, sair = 0, delete = 0;



    printf("------Deleção de hospede-------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do hospede que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar o operadores
        posicao = procura_hospede_txt(codigo, qtd_hos, hospede);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo do hospede nao encontrado\n");
            contador_erro = 0;
        } else {
            //caso o operadore exista o laço se quebra e segue o codigo
            printf("Hospede encontrado\n");
            contador_erro = 0;
            break;
        }
        if (contador_erro > 3) {
            printf("Foi detectado muitos erros do codigo do hospede, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            menu_gestao_hospedes_mem();
        }
    } while (posicao == -1);

    printf("------Dados do hospede------\n");
    printf("Codigo: %d.\n", hospede[posicao].codigo);
    printf("Nome: %s.\n", hospede[posicao].nome);
    printf("------Dados de endereço------\n");
    printf("Estado: %s.\n", hospede[posicao].endereco_hospede.estado);
    printf("Cidade: %s.\n", hospede[posicao].endereco_hospede.cidade);
    printf("CEP: %s.\n", hospede[posicao].endereco_hospede.cep);
    printf("Bairro: %s.\n", hospede[posicao].endereco_hospede.bairro);
    printf("Rua: %s.\n", hospede[posicao].endereco_hospede.rua);
    printf("numero: %d.\n", hospede[posicao].endereco_hospede.numero);
    printf("---------Dados pessoais--------\n");
    printf("CPF: %s.\n", hospede[posicao].cpf);
    printf("Telefone: %s.\n", hospede[posicao].telefone);
    printf("E-mail: %s.\n", hospede[posicao].email);
    printf("Sexo: %s.\n", hospede[posicao].sexo);
    printf("Estado Civil: %s.\n", hospede[posicao].estado_civil);
    printf("Data de nascimento:%d/%d/%d.\n", hospede[posicao].data_nacimento.dia, hospede[posicao].data_nacimento.mes, hospede[posicao].data_nacimento.ano);
    printf("Realmente deseja excluir esse hospode:(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        for (int i = posicao; i < qtd_hos; i++) {//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente          
            hospede[i] = hospede[i + 1];
        }
        qtd_hos--;
        hospede = (hospedes *) realloc(hospede, qtd_hos * sizeof (hospedes));
    }
    menu_gestao_hospedes_mem();
}
//FIM HOSPEDE

//COMEÇO PRODUTO

void cadastro_produtos_mem() {
    //variaveis para cadastro de produto
    qtd_pro++;
    produto = (produtos *) realloc(produto, qtd_pro * sizeof (produtos));
    int indicie = qtd_pro - 1;

    printf("-------Cadastro de produto--------\n");
    if (indicie == 0) {
        produto[indicie].codigo = 1;
    } else {
        produto[indicie].codigo = produto[indicie - 1].codigo + 1;
    }
    printf("O código do produto será %d.\n", produto[indicie].codigo);
    printf("Digite a descrição do produto:");
    setbuf(stdin, NULL);
    scanf(" %[^\n]s%*c", produto[indicie].descricao);
    setbuf(stdin, NULL);
    printf("Digite o estoque do produto:");
    scanf("%d", &produto[indicie].estoque);
    setbuf(stdin, NULL);
    printf("Digite o estoque mínimo do produto:");
    scanf("%d", &produto[indicie].estoque_min);
    setbuf(stdin, NULL);
    printf("Digite o preço de custo do produto:");
    scanf("%f", &produto[indicie].preco_custo);
    setbuf(stdin, NULL);
    printf("Digite o preço de venda do produto:");
    scanf("%f", &produto[indicie].preco_venda);
    setbuf(stdin, NULL);

    menu_gestao_produtos_mem();
}

void atualiza_produto_mem() {
    int posicao, codigo, contador_erro = 0, sair = 0, opcao;

    printf("-------Atualizar Produto-------\n");

    do {
        // Pedindo ao usuário o código do produto que deseja alterar
        printf("Digite o código do produto que deseja alterar:");
        scanf("%d", &codigo);

        // Função para procurar o produto
        posicao = procura_produto_txt(codigo, qtd_pro, produto);
        // Caso o produto não exista, o laço se reinicia
        if (posicao == -1) {
            printf("Código do produto não encontrado\n");
            contador_erro++;
        } else {
            // Caso o produto exista, o laço se quebra e segue o código
            printf("Produto encontrado\n");
            contador_erro = 0;
            break;
        }
        if (contador_erro > 3) {
            printf("Foram detectados muitos erros de código do produto. Deseja sair dessa função? (1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_produtos_mem();
        }

    } while (posicao == -1);


    printf("O código atual do produto é: %d.\n", produto[posicao].codigo);
    printf("A descrição atual do produto é: %s.\n", produto[posicao].descricao);
    printf("Deseja alterar a descrição do produto (1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova descrição do produto:");
        scanf(" %[^\n]s%*c", produto[posicao].descricao);
    }

    printf("O estoque atual do produto é: %d.\n", produto[posicao].estoque);
    printf("Deseja alterar o estoque do produto (1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estoque do produto:");
        scanf("%d", &produto[posicao].estoque);
    }

    printf("O estoque mínimo atual do produto é: %d.\n", produto[posicao].estoque_min);
    printf("Deseja alterar o estoque mínimo do produto (1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estoque mínimo do produto:");
        scanf("%d", &produto[posicao].estoque_min);
    }

    printf("O preço de custo atual do produto é: %.2f.\n", produto[posicao].preco_custo);
    printf("Deseja alterar o preço de custo do produto (1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo preço de custo do produto:");
        scanf("%f", &produto[posicao].preco_custo);
    }

    printf("O preço de venda atual do produto é: %.2f.\n", produto[posicao].preco_venda);
    printf("Deseja alterar o preço de venda do produto (1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo preço de venda do produto:");
        scanf("%f", &produto[posicao].preco_venda);
    }


    menu_gestao_produtos_mem();
}

void deleta_produtos_mem() {
    // Variáveis utilizadas para deletar produtos
    int codigo = 0, contador_erro = 0, posicao = 0, opcao = 0, sair = 0, delete = 0;

    printf("------Deleção de Produto-------\n");

    do {
        // Pedindo ao usuário o código do produto que deseja deletar
        printf("Digite o código do produto que deseja deletar:");
        scanf("%d", &codigo);

        // Função para procurar o produto
        posicao = procura_produto_txt(codigo, qtd_pro, produto);
        // Caso o produto não exista, o laço se reinicia
        if (posicao == -1) {
            printf("Código do produto não encontrado\n");
            contador_erro = 0;
        } else {
            // Caso o produto exista, o laço se quebra e segue o código
            printf("Produto encontrado\n");
            contador_erro = 0;
            break;
        }
        if (contador_erro > 3) {
            printf("Foram detectados muitos erros no código do produto. Deseja sair dessa função? (1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            menu_gestao_produtos_mem();
        }
    } while (posicao == -1);

    printf("------Dados do Produto------\n");
    printf("Código: %d.\n", produto[posicao].codigo);
    printf("Descrição: %s.\n", produto[posicao].descricao);
    printf("Estoque: %d.\n", produto[posicao].estoque);
    printf("Estoque Mínimo: %d.\n", produto[posicao].estoque_min);
    printf("Preço de Custo: %.2f.\n", produto[posicao].preco_custo);
    printf("Preço de Venda: %.2f.\n", produto[posicao].preco_venda);

    printf("Realmente deseja excluir esse produto? (1-Sim/0-Não):");
    scanf("%d", &delete);

    if (delete == 1) {
        for (int i = posicao; i < qtd_pro; i++) {
            // Sobrescreve os dados do produto seguinte ao que será deletado, e assim sucessivamente
            produto[i] = produto[i + 1];
        }

        qtd_pro--;
        produto = (produtos *) realloc(produto, qtd_pro * sizeof (produtos));
    }

    menu_gestao_produtos_mem();
}
//FIM PRODUTO



//COMEÇO FORNECEDOR

void cadastro_fornecedores_mem() {
    //variaveis para cadastro de fornecedores
    qtd_forn++;
    fornecedor = (fornecedores *) realloc(fornecedor, qtd_forn * sizeof (fornecedores));

    int indicie = qtd_forn - 1;




    printf("-------Cadastros de Fornecedores--------\n");

    if (indicie == 0) {
        fornecedor[indicie].codigo = 1;
    } else {
        fornecedor[indicie].codigo = fornecedor[indicie - 1].codigo + 1;
    }

    printf("O código do fornecedor será %d.\n", fornecedor[indicie].codigo);

    printf("Digite o nome fantasia:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].nome_fantasia);
    setbuf(stdin, NULL);
    printf("Digite a razão social:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].razao_social);
    setbuf(stdin, NULL);
    printf("Digite a inscrição estadual:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].inscricao_estadual);
    setbuf(stdin, NULL);
    printf("Digite o CNPJ:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].cnpj);
    setbuf(stdin, NULL);
    printf("-------ENDEREÇO-------\n");
    printf("Digite o estado:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].endereco.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].endereco.cidade);
    setbuf(stdin, NULL);
    printf("Digite o CEP:");
    scanf(" %[^\n]s%*c", &fornecedor[indicie].endereco.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].endereco.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].endereco.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero:");
    scanf("%d", &fornecedor[indicie].endereco.numero);

    setbuf(stdin, NULL);
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Digite o telefone do fornecedor:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do fornecedor:");
    scanf(" %[^\n]s%*c", fornecedor[indicie].email);
    setbuf(stdin, NULL);


    menu_gestao_fornecedor_mem();
}

void atualiza_fornecedores_mem() {
    //variaveis utlizadas atualizar forenecedores
    int posicao, codigo, contador_erro = 0, sair = 0, opcao;

    printf("-------Atualizar Fornecedor-------\n");

    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do fornecedor que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_fornecedor_txt(codigo, qtd_forn, fornecedor);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo do fornecedor nao encontrado\n");
            contador_erro++;
        }
        if (contador_erro > 2) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_fornecedor_mem();

        }

    } while (posicao == -1);
    printf("O nome fantasia atual do fornecedor é: %s.\n", fornecedor[posicao].nome_fantasia);
    printf("Deseja alterar o nome fantasia do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo nome fantasia:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].nome_fantasia);
    }
    printf("A razão social atual do fornecedor é: %s.\n", fornecedor[posicao].razao_social);
    printf("Deseja alterar a razão social do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova razão social:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].razao_social);
    }
    printf("A inscrição estadual atual do fornecedor é: %s.\n", fornecedor[posicao].inscricao_estadual);
    printf("Deseja alterar a inscrição estadual do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova inscrição estadual:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].inscricao_estadual);
    }
    printf("O CNPJ atual do fornecedor é: %s.\n", fornecedor[posicao].cnpj);
    printf("Deseja alterar o CNPJ do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo CNPJ:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].cnpj);
    }
    printf("--------------Dados de Endereço--------------\n");
    printf("O estado atual do fornecedor é: %s.\n", fornecedor[posicao].endereco.estado);
    printf("Deseja alterar o estado do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estado:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].endereco.estado);
    }
    printf("A cidade atual do fornecedor é: %s.\n", fornecedor[posicao].endereco.cidade);
    printf("Deseja alterar a cidade do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova cidade:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].endereco.cidade);
    }
    printf("O CEP atual do fornecedor é: %s.\n", fornecedor[posicao].endereco.cep);
    printf("Deseja alterar o CEP do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo CEP:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].endereco.cep);
    }
    printf("O bairro atual do fornecedor é: %s.\n", fornecedor[posicao].endereco.bairro);
    printf("Deseja alterar o bairro do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo bairro:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].endereco.bairro);
    }
    printf("A rua atual do fornecedor é: %s.\n", fornecedor[posicao].endereco.cidade);
    printf("Deseja alterar a rua do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova rua:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].endereco.cidade);
    }
    printf("O número de endereço atual do fornecedor é: %d.\n", fornecedor[posicao].endereco.numero);
    printf("Deseja alterar o número de endereço do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo número de endereço:");
        scanf("%d", &fornecedor[posicao].endereco.numero);
    }
    printf("--------------Dados para contato--------------\n");
    printf("O telefone atual do fornecedor é: %s.\n", fornecedor[posicao].telefone);
    printf("Deseja alterar o telefone do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo telefone:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].telefone);
    }
    printf("O E-mail atual do fornecedor é: %s.\n", fornecedor[posicao].email);
    printf("Deseja alterar o E-mail do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo E-mail:");
        scanf(" %[^\n]s%*c", fornecedor[posicao].email);
    }
    menu_gestao_fornecedor_mem();
}

void deleta_fornecedores_mem() {
    //variaveis utlizadas deletar fornecedores
    int codigo = 0, contador_erro = 0, posicao = 0, opcao = 0, sair = 0, delete = 0;

    printf("--------Deletar  fornecedor----------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do fornecedor que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_fornecedor_txt(codigo, qtd_forn, fornecedor);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo do fornecedor nao encontrado\n");
            contador_erro++;
        }
        if (contador_erro > 2) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_fornecedor_mem();
        }

    } while (posicao == -1);

    printf("--------Dados do fornecedor---------\n");
    printf("Código: %d.\n", fornecedor[posicao].codigo);
    printf("Nome fantasia: %s.\n", fornecedor[posicao].nome_fantasia);
    printf("Razão social: %s.\n", fornecedor[posicao].razao_social);
    printf("Inscrição estadual: %s.\n", fornecedor[posicao].inscricao_estadual);
    printf("CNPJ: %s.\n", fornecedor[posicao].cnpj);
    printf("--------Endereço---------\n");
    printf("Estado: %s.\n", fornecedor[posicao].endereco.estado);
    printf("Cidade: %s.\n", fornecedor[posicao].endereco.cidade);
    printf("CEP: %s.\n", fornecedor[posicao].endereco.cep);
    printf("Bairro: %s.\n", fornecedor[posicao].endereco.bairro);
    printf("Rua: %s.\n", fornecedor[posicao].endereco.rua);
    printf("Número: %d.\n", fornecedor[posicao].endereco.numero);
    printf("--------Contato---------\n");
    printf("Número: %s.\n", fornecedor[posicao].telefone);
    printf("E-mail: %s.\n", fornecedor[posicao].email);
    printf("Realmente deseja excluir esse fornecedor?(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        for (int i = posicao; i < qtd_forn; i++) {//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente

            fornecedor[i] = fornecedor[i + 1];
        }
        qtd_forn--;
        fornecedor = (fornecedores *) realloc(fornecedor, qtd_forn * sizeof (fornecedores));

    }
    menu_gestao_fornecedor_mem();
}
//FIM FORNECEDOR


//COMECO DA CATEGORIA

void cadastra_categoria_mem() {
    qtd_cat++;
    categoria = (categoria_acomodacao *) realloc(categoria, qtd_cat * sizeof (categoria_acomodacao));

    int indice = qtd_cat - 1;

    printf("-------Cadastro de Categoria de Acomodação--------\n");
    if (indice == 0) {
        categoria[indice].codigo = 1;
    } else {
        categoria[indice].codigo = categoria[indice - 1].codigo + 1;
    }
    printf("O código da categoria será %d.\n", categoria[indice].codigo);
    printf("Digite a descrição da categoria:");
    scanf(" %[^\n]s%*c", categoria[indice].descricao);
    printf("Digite o valor da diária:");
    scanf("%f", &categoria[indice].valor_diaria);
    printf("Digite a quantidade máxima de adultos:");
    scanf("%d", &categoria[indice].adultos);
    printf("Digite a quantidade máxima de crianças:");
    scanf("%d", &categoria[indice].criancas);

    menu_gestao_categoria_mem();

}

void atualiza_categoria_mem() {
    int codigo, posicao, opcao, contador_erro = 0, sair = 0;

    printf("-------Atualizar Categoria de Acomodação-------\n");

    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo da categoria que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_categoria_txt(codigo, qtd_cat, categoria);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo da categoria não encontrado\n");
            contador_erro++;
        }
        if (contador_erro > 2) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_categoria();

        }

    } while (posicao == -1);

    // Exibe os dados atuais da categoria
    printf("Código: %d\n", categoria[posicao].codigo);
    printf("Descrição atual: %s\n", categoria[posicao].descricao);
    printf("Valor da diária atual: %.2f\n", categoria[posicao].valor_diaria);
    printf("Quantidade máxima de adultos atual: %d\n", categoria[posicao].adultos);
    printf("Quantidade máxima de crianças atual: %d\n", categoria[posicao].criancas);

    // Pergunta ao usuário qual campo deseja alterar
    printf("Deseja alterar a descrição? (1-Sim/0-Não): ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova descrição: ");
        scanf(" %[^\n]s%*c", categoria[posicao].descricao);
    }

    printf("Deseja alterar o valor da diária? (1-Sim/0-Não): ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo valor da diária: ");
        scanf("%f", &categoria[posicao].valor_diaria);
    }

    printf("Deseja alterar a quantidade máxima de adultos? (1-Sim/0-Não): ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova quantidade máxima de adultos: ");
        scanf("%d", &categoria[posicao].adultos);
    }

    printf("Deseja alterar a quantidade máxima de crianças? (1-Sim/0-Não): ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova quantidade máxima de crianças: ");
        scanf("%d", &categoria[posicao].criancas);
    }

    menu_gestao_categoria();

}

void deleta_categoria_mem() {
    int codigo, posicao, delete, contador_erro = 0, sair = 0;

    printf("\n------Deleção de Categoria de Acomodação-------\n");
    do {

        printf("Digite o codigo da categoria que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_categoria_txt(codigo, qtd_cat, categoria);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo da categoria não encontrado\n");
            contador_erro++;
        }
        if (contador_erro > 2) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_categoria();

        }

    } while (posicao == -1);

    // Exibe os dados da categoria antes da exclusão
    printf("------Dados da Categoria------\n");
    printf("Código: %d\n", categoria[posicao].codigo);
    printf("Descrição: %s\n", categoria[posicao].descricao);
    printf("Valor da diária: %.2f\n", categoria[posicao].valor_diaria);
    printf("Quantidade máxima de adultos: %d\n", categoria[posicao].adultos);
    printf("Quantidade máxima de crianças: %d\n", categoria[posicao].criancas);

    printf("Realmente deseja excluir essa categoria? (1-Sim/0-Não): ");
    scanf("%d", &delete);

    if (delete == 1) {
        // Move os elementos para preencher a lacuna
        for (int i = posicao; i < qtd_cat; i++) {
            categoria[i] = categoria[i + 1];
        }

        // Reduz o tamanho do array
        qtd_cat--;
        categoria = (categoria_acomodacao *) realloc(categoria, qtd_cat * sizeof (categoria_acomodacao));

        printf("Categoria excluída com sucesso!\n");
    }

    menu_gestao_categoria();
}
//FIM DA CATEGORIA



//COMECO ACOMODACAO

void cadastro_acomodacao_mem() {
    //variaveis para cadastro de acomodações
    int existe = 0, contador_erro = 0, sair = 0, posicao = 0;
    qtd_acomd++;
    acomodacao = (acomodacoes *) realloc(acomodacao, qtd_acomd * sizeof (acomodacoes));

    int indicie = qtd_acomd - 1;



    printf("-------Cadastros de acomodações--------\n");

    if (indicie == 0) {
        acomodacao[indicie].codigo = 1;
    } else {
        acomodacao[indicie].codigo = acomodacao[indicie - 1].codigo + 1;
    }

    printf("O código da acomodação será %d.\n", acomodacao[indicie].codigo);

    printf("Digite a descrição da acomodação:");
    scanf(" %[^\n]s%*c", acomodacao[indicie].descricao);
    printf("Digite as facilidades da acomodação.\n"
            "Coloque uma virgula após cada facilidade\n"
            "(Ex:Ar condiciona,TV,Cama King Size):");
    scanf(" %[^\n]s%*c", acomodacao[indicie].facilidades);
    printf("Digite o codigo de categoria da acomodação:");
    scanf("%d", &acomodacao[indicie].categoria);

    existe = procura_categoria_txt(acomodacao[indicie].categoria, qtd_cat, categoria);

    while (existe == -1) {
        printf("Essa categoria não existe digite uma existente:");
        scanf("%d", &acomodacao[indicie].categoria);

        existe = procura_categoria_txt(acomodacao[indicie].categoria, qtd_cat, categoria);
        contador_erro++;
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair == 1) {
            break;
        }
    }//fim do while
    if (sair == 0) {
        acomodacao[indicie].ocupacao = 0;
        acomodacao[indicie].lucro = 0;
        acomodacao[indicie].diarias = 0;
        contador_erro = 0;
    }
    menu_gestao_acomodacao_mem();
}

void atualiza_acomodacoes_mem() {
    //variaveis utlizadas atualizar acomodações
    int posicao, codigo, contador_erro = 0, sair = 0, opcao = 0, existe = 0;

    printf("-------Atualizar Fornecedor-------\n");

    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo da acomodação que deseja alterar:");
        scanf("%d", &codigo);

        //funcao procura acomodacao
        posicao = procura_acomodacao_txt(codigo, qtd_acomd, acomodacao);

        if (posicao == -1) {
            printf("Codigo da acomodação não encontrado\n");
            contador_erro++;
        }
        if (contador_erro > 2) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_acomodacao_mem();

        }

    } while (posicao == -1);

    printf("A descrição atual da acomodação é: %s.\n", acomodacao[posicao].descricao);
    printf("Deseja alterar a descrição da acomodação?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova descrição:");
        scanf(" %[^\n]s%*c", acomodacao[posicao].descricao);
    }
    printf("As facilidades atuais da acomodação é: %s.\n", acomodacao[posicao].facilidades);
    printf("Deseja alterar as facilidades da acomodação?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite as novas facilidades(Lembre de a cada facilidade colocar um virgula e digitar a proxima)\n"
                "(Ex:Ar-condiciona,TV,Cama King Size):");
        scanf(" %[^\n]s%*c", acomodacao[posicao].facilidades);
    }
    printf("O codigo da categoria da acomodação é: %d.\n", acomodacao[posicao].categoria);
    printf("Deseja alterar o codigo da categoria da acomodação?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo codigo da categoria:");
        scanf("%d", &acomodacao[posicao].categoria);
        sair = 0;

        existe = procura_categoria_txt(acomodacao[posicao].categoria, qtd_cat, categoria);

        while (existe == -1) {
            printf("Essa categoria não existe digite uma existente:");
            scanf("%d", &acomodacao[posicao].categoria);
            existe = procura_categoria_txt(acomodacao[posicao].categoria, qtd_cat, categoria);
            contador_erro++;

            if (contador_erro > 2) {
                printf("Ocorreu muitos erros, deseja sair da função de atualizar acomodação?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair == 1) {
                break;
            }
        }//fim do while
    }
    if (sair == 0) {
        contador_erro = 0;
    }


    menu_gestao_fornecedor_mem();
}

void deleta_acomodacoes_mem() {
    //variaveis para deletar acomodações
    int sair = 0, codigo = 0, posicao = 0, contador_erro = 0, delete = 0;


    printf("--------Deletar  acomodação----------\n");
    do {
        //pedindo ao usuario o codigo da categoria que deseja alterar
        printf("Digite o codigo da acomodação que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar a categoria
        posicao = procura_acomodacao_txt(codigo, qtd_acomd, acomodacao);
        //caso a categoria nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo da acomodação não encontrado\n");
            contador_erro++;
        }
        if (contador_erro > 3) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_gestao_acomodacao_mem();
        }

    } while (posicao == -1);

    printf("---------Dados da acomadação---------\n");
    printf("Código: %d\n", acomodacao[posicao].codigo);
    printf("Descrição: %s\n", acomodacao[posicao].descricao);
    printf("Facilidades: %s\n", acomodacao[posicao].facilidades);
    printf("Codigo da categoria: %d\n", acomodacao[posicao].categoria);
    printf("Realmente deseja deletar essa acomodação?(1-Sim/0-Não):");
    scanf("%d", &delete);

    if (delete == 1) {
        for (int i = posicao; i < qtd_acomd; i++) {//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente

            acomodacao[i] = acomodacao[i + 1];
        }
        qtd_acomd--;
        acomodacao = (acomodacoes *) realloc(acomodacao, qtd_acomd * sizeof (acomodacoes));

    }
    menu_gestao_acomodacao_mem();
}
//FIM DA ACOMODACAO

//FIM DO MODULO DE CADASTRO


//INICIO DOS PRINTS DE DADOS
// dados hotel 
void dadosHotel() {


    printf("-------INFORMAÇÕES DO HOTEL-------\n");
    printf("Nome: %s\n", hotel.nome_fantasia);
    printf("Razão Social: %s\n", hotel.razao_social);
    printf("Inscrição Estadual: %s\n", hotel.inscricao_estadual);
    printf("CNPJ: %s\n", hotel.cnpj);
    printf("Endereço: %s, %s, %s, %s, %s, %d\n", hotel.endereco.estado, hotel.endereco.cidade, hotel.endereco.cep, hotel.endereco.bairro, hotel.endereco.rua, hotel.endereco.numero);
    printf("Telefone: %s\n", hotel.telefone);
    printf("E-mail: %s\n", hotel.email);
    printf("Responsável: %s, %s\n", hotel.nome_responsavel, hotel.telefone_responsavel);
    printf("Horário de Check-in: %d:%d\n", hotel.horario_checkin.hora, hotel.horario_checkin.minutos);
    printf("Horário de Check-out: %d:%d\n", hotel.horario_checkout.hora, hotel.horario_checkout.minutos);
    printf("Margem de Lucro sobre os Produtos: %.2f\n\n\n", hotel.mlpv);
}

// dados hospedes
void dadosHospede() {
    printf("-------INFORMAÇÕES DO HÓSPEDE-------\n");

    for (int i = 0; i < qtd_hos; i++) {
        printf("Código: %d\n", hospede[i].codigo);
        printf("Nome: %s\n", hospede[i].nome);
        printf("Endereço: %s, %s, %s, %s, %s, %d\n", hospede[i].endereco_hospede.estado, hospede[i].endereco_hospede.cidade, hospede[i].endereco_hospede.cep, hospede[i].endereco_hospede.bairro, hospede[i].endereco_hospede.rua, hospede[i].endereco_hospede.numero);
        printf("CPF: %s\n", hospede[i].cpf);
        printf("Telefone: %s\n", hospede[i].telefone);
        printf("E-mail: %s\n", hospede[i].email);
        printf("Sexo: %s\n", hospede[i].sexo);
        printf("Estado Civil: %s\n\n\n", hospede[i].estado_civil);
    }

}

// dados operadores
void dadosOperador() {

    printf("-------INFORMAÇÕES DO OPERADOR-------\n");

    for (int i = 0; i < qtd_ope; i++) {
        printf("Código: %d\n", operador[i].codigo);
        printf("Nome: %s\n", operador[i].nome);
        printf("Usuário: %s\n", operador[i].usuario);
        printf("Senha: %d\n", operador[i].senha);
        printf("Permissões:\n");
        printf("Cadastros: %d\n", operador[i].permissoes.cadastros);
        printf("Reservas: %d\n", operador[i].permissoes.reservas);
        printf("Transações: %d\n", operador[i].permissoes.transacoes);
        printf("Feedback: %d\n", operador[i].permissoes.feedback);
        printf("Im-Exportação: %d\n\n\n", operador[i].permissoes.im_exportacao);

    }
}

// dados produtos 
void dadosProdutos() {

    printf("-------INFORMAÇÕES DO PRODUTO-------\n");

    for (int i = 0; i < qtd_pro; i++) {

        printf("Código: %d\n", produto[i].codigo);
        printf("Descrição: %s\n", produto[i].descricao);
        printf("Estoque: %d\n", produto[i].estoque);
        printf("Estoque Mínimo: %d\n", produto[i].estoque_min);
        printf("Preço de Custo: %.2f\n", produto[i].preco_custo);
        printf("Preço de Venda: %.2f\n\n\n", produto[i].preco_venda);

    }
}

// dados fornecedores 
void dadosFornecedor() {

    printf("-------INFORMAÇÕES DO FORNECEDOR-------\n");

    for (int i = 0; i < qtd_forn; i++) {
        printf("Nome: %s\n", fornecedor[i].nome_fantasia);
        printf("Razão Social: %s\n", fornecedor[i].razao_social);
        printf("Inscrição Estadual: %s\n", fornecedor[i].inscricao_estadual);
        printf("CNPJ: %s\n", fornecedor[i].cnpj);
        printf("Endereço - Estado: %s\n", fornecedor[i].endereco.estado);
        printf("Endereço - Cidade: %s\n", fornecedor[i].endereco.cidade);
        printf("Endereço - CEP: %s\n", fornecedor[i].endereco.cep);
        printf("Endereço - Bairro: %s\n", fornecedor[i].endereco.bairro);
        printf("Endereço - Rua: %s\n", fornecedor[i].endereco.rua);
        printf("Endereço - Número: %d\n", fornecedor[i].endereco.numero);
        printf("Telefone: %s\n", fornecedor[i].telefone);
        printf("Email: %s\n\n\n", fornecedor[i].email);

    }
}

// dados categoria 
void dadosCategoria() {
    printf("-------INFORMAÇÕES DA CATEGORIA-------\n");

    for (int i = 0; i < qtd_cat; i++) {
        printf("Código: %d\n", categoria[i].codigo);
        printf("Descrição: %s\n", categoria[i].descricao);
        printf("Valor da diária: %.2f\n", categoria[i].valor_diaria);
        printf("Quantidade de adultos: %d\n", categoria[i].adultos);
        printf("Quantidade de crianças: %d\n\n\n", categoria[i].criancas);
    }
}

// dados acomodacao 
void dadosAcomodacao() {
    printf("-------INFORMAÇÕES DA ACOMODAÇÃO-------\n");

    for (int i = 0; i < qtd_acomd; i++) {

        printf("Código: %d\n", acomodacao[i].codigo);
        printf("Descrição: %s\n", acomodacao[i].descricao);
        printf("Facilidades: %s\n", acomodacao[i].facilidades);
        printf("Codigo da categoria: %d\n", acomodacao[i].categoria);
        printf("Diarias: %d\n", acomodacao[i].diarias);
        printf("Lucro: %.2f\n", acomodacao[i].lucro);
        printf("Ocupação: %d\n\n\n", acomodacao[i].ocupacao);

    }
}

// dados reservas 
void dadosReserva() {
    printf("-------INFORMAÇÕES DA RESERVA-------\n");

    for (int i = 0; i < qtd_res; i++) {

        printf("Codigo: %d\n", reserva[i].codigo_res);
        printf("Codigo da acomodação: %d\n", reserva[i].codigo_aco);
        printf("Descrição: %s\n", reserva[i].descricao);
        printf("Facilidades: %s\n", reserva[i].facilidades);
        printf("Codigo da categoria: %d\n", reserva[i].categoria.codigo);
        printf("Descrição da categoria: %s\n", reserva[i].categoria.descricao);
        printf("Diaria da categoria: R$%.2f\n", reserva[i].categoria.valor_diaria);
        printf("Número de adultos da categoria: %d\n", reserva[i].categoria.adultos);
        printf("Número de crianças da categoria: %d\n", reserva[i].categoria.criancas);
        printf("Data de check-in: %d/%d/%d\n", reserva[i].datas.dia_in, reserva[i].datas.mes_in, reserva[i].datas.ano_in);
        printf("Data de check-out: %d/%d/%d\n", reserva[i].datas.dia_out, reserva[i].datas.mes_out, reserva[i].datas.ano_out);
        printf("Codigo do hospede: %d\n\n\n", reserva[i].cod_hospede);

    }
}

// dados da conta dos hospedes
void dadosContaHospede() {
    printf("-------INFORMAÇÕES DA CONTA DO HOSPEDE-------\n");

    for (int i = 0; i < qtd_con; i++) {

        printf("\n-------CONTA DO HOSPEDE-------\n\n");
        printf("Codigo da reserva: %d\n", conta[i].codigo_res);
        printf("Codigo do hospede: %d\n", conta[i].codigo_hos);
        printf("Valor devido: %f\n\n\n", conta[i].valor_devido);

    }
}

// dados do caixa
void dadosCaixa() {
    printf("-------INFORMAÇÕES DO CAIXA-------\n");

    for (int i = 0; i < qtd_cai; i++) {

        printf("Código: %d\n", caixa[i].codigo_hos);

        // Verifica se o valor é positivo ou negativo e imprime o sinal correspondente
        if (caixa[i].valor_devido >= 0) {
            printf("Valor: +%.2f\n", caixa[i].valor_devido);
        } else {
            printf("Valor: %.2f\n", caixa[i].valor_devido);
        }

        printf("Data: %d/%d/%d\n\n\n", caixa[i].date.dia, caixa[i].date.mes, caixa[i].date.ano);

    }
}

// dados das contas a receber
void dadosContaReceber() {
    printf("-------INFORMAÇÕES DAS CONTAS A RECEBER-------\n");

    for (int i = 0; i < qtd_con_rec; i++) {

        printf("Codigo da conta:%d\n", i);
        printf("Código do hóspede: %d\n", conta_rec[i].codigo_hos);
        printf("Valor: +%.2f\n", conta_rec[i].valor_devido);
        printf("Data: %d/%d/%d\n\n\n", conta_rec[i].date.dia, conta_rec[i].date.mes, conta_rec[i].date.ano);

    }
}

// dados das contas a pagar
void dadosContaPagar() {
    printf("-------INFORMAÇÕES DAS CONTAS A PAGAR-------\n");

    for (int i = 0; i < qtd_con_pag; i++) {

        printf("Codigo da conta:%d\n", i);
        printf("Codigo do fornecedor:%d\n", conta_pag[i].codigo_hos);
        printf("Valor: +%.2f\n", conta_pag[i].valor_devido);
        printf("Data: %d/%d/%d\n\n\n", conta_pag[i].date.dia, conta_pag[i].date.mes, conta_pag[i].date.ano);
    }
}

// dados das notas fiscais
void dadosNotaFiscal() {
    printf("-------INFORMAÇÕES DAS NOTAS FISCAIS-------\n");

    for (int i = 0; i < qtd_notas; i++) {

   printf("----------DADOS DA NOTA FISCAL----------\n");
        printf("Fornecedor: %s\n", notas[i].fornecedor);
        printf("CNPJ: %s\n", notas[i].cnpj);
        printf("Frete: %.2f\n", notas[i].frete);
        printf("Imposto: %.2f\n", notas[i].imposto);
        printf("Total da Nota: %.2f\n", notas[i].total);
        printf("Número de Produtos: %d\n", notas[i].num_produtos);

        // Imprimir dados dos produtos
        for (int j = 0; j < notas[i].num_produtos; j++) {
            
            printf("Produto %d:\n", j + 1);
            printf("Nome: %s\n", notas[i].entra_prod[j].nome);
            printf("Preço: %.2f\n", notas[i].entra_prod[j].preco);
            printf("Quantidade: %d\n", notas[i].entra_prod[j].quantidade);
            printf("Total do Produto: %.2f\n", notas[i].entra_prod[j].subtotal);
        }
        printf("\n\n");
    }
}

// dados das vendas
void dadosVenda() {
    printf("-------INFORMAÇÕES DAS VENDAS-------\n");

    for (int i = 0; i < qtd_venda; i++) {
        
        printf("Quantidade de produtos: %d\n", venda[i].qtd);
        printf("Codigo do hospede:%d\n", venda[i].cod_hos);
        printf("Codigo do produto:%d\n", venda[i].cod_prod);
        printf("Valor: %.2f\n", venda[i].valor);
        printf("Tipo de pagamento: %d\n\n\n", venda[i].pagamento);
    }
}
//FIM DOS PRINTS DE DADOS



//INICIO DO MODULO DE RESERVAS
//funcao para filtrar por data em txt
void filtros_mem() {
    //variaveis utilizadas para fazer reservas
    data_chek_in_out datas;

    int data_filtro, pessoas_filtro;
    int categoria_filtro, facilidades_filtro, ret_data, contador_erro = 0, sair = 0;
    int cod_cat, pos_cat, retorno, criancas, adultos, cod_aco, pos_aco, ret_reserva;
    int cod_hos, pos_hos, pos_res, cod_res;

    char facilidade[20];
    qtd_res++;
    qtd_dis=qtd_res+qtd_acomd;
    
    int indicie = qtd_res -1;
    
    reserva = (reservas *) realloc(reserva, qtd_res * sizeof (reservas));
    disponiveis = (reservas *) realloc(disponiveis, qtd_dis * sizeof (reservas));
    
    
    
    printf("Deseja filtrar por data?(1-Sim/0-Não):");
    scanf("%d", &data_filtro);
    if (data_filtro == 1) {
        printf("----------Filtro por Data----------\n");
        printf("Digite a data que deseja fazer o chek-in.\n");
        printf("Dia:");
        scanf("%d", &datas.dia_in);
        printf("Mes:");
        scanf("%d", &datas.mes_in);
        printf("Ano:");
        scanf("%d", &datas.ano_in);
        printf("Digite a data que deseja fazer o chek-out.\n");
        printf("Dia:");
        scanf("%d", &datas.dia_out);
        printf("Mes:");
        scanf("%d", &datas.mes_out);
        printf("Ano:");
        scanf("%d", &datas.ano_out);
        ret_data = data_atual(datas);
        while (ret_data == 1) {
            printf("Essa data não é válida, digite um data valida.\n");
            printf("Digite a data que deseja fazer o chek-in.\n");
            printf("Dia:");
            scanf("%d", &datas.dia_in);
            printf("Mes:");
            scanf("%d", &datas.mes_in);
            printf("Ano:");
            scanf("%d", &datas.ano_in);
            printf("Digite a data que deseja fazer o chek-out.\n");
            printf("Dia:");
            scanf("%d", &datas.dia_out);
            printf("Mes:");
            scanf("%d", &datas.mes_out);
            printf("Ano:");
            scanf("%d", &datas.ano_out);
            ret_data = data_atual(datas);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas_mem();
            }
        }
        printf("------Quartos Disponiveis------\n");

        qtd_dis = data_disponivel_txt(disponiveis, reserva, acomodacao, qtd_res, qtd_acomd, datas, categoria, qtd_cat);
        if (qtd_dis == 0) {
            menu_modulo_reservas_mem();
        }
        for (int i = 0; i < qtd_dis; i++) {
            printf("Código da Acomodação: %d\n", disponiveis[i].codigo_aco);
            printf("Descrição da Acomodação: %s\n", disponiveis[i].descricao);
            printf("Facilidades da Acomodação: %s\n", disponiveis[i].facilidades);
            printf("Código da Categoria: %d\n", disponiveis[i].categoria.codigo);
            printf("Descrição da Categoria: %s\n", disponiveis[i].categoria.descricao);
            printf("Valor da Diária da Categoria: %.2f\n", disponiveis[i].categoria.valor_diaria);
            printf("Quantidade de Crianças suportadas pela acomodação: %d\n", disponiveis[i].categoria.criancas);
            printf("Quantidade de Adultos suportadas pela acomodação: %d\n\n", disponiveis[i].categoria.adultos);
        }
    }
    printf("Deseja filtrar por categoria?(1-Sim/0-Não):");
    scanf("%d", &categoria_filtro);
    if (categoria_filtro == 1) {
        if (data_filtro == 0) {
            printf("---------Filtro por Categoria---------\n");
            printf("\tCategorias disponíveis\n");
            printa_categoria_txt(qtd_cat, categoria);
            printf("Digite o codigo de uma dessas categorias:");
            scanf("%d", &cod_cat);
            //verifica se o codigo da categoria é valido
            pos_cat = procura_categoria_txt(cod_cat, qtd_cat, categoria);

            //se nao for entra em um loop
            while (pos_cat == -1) {
                contador_erro++;
                printf("Digite uma categoria válida:");
                scanf("%d", &cod_cat);
                pos_cat = procura_categoria_txt(cod_cat, qtd_cat, categoria);
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair == 1) {
                    contador_erro = 0;
                    menu_modulo_reservas_mem();
                }
            }

            printf("\tAcomodações disponíveis com a categoria digitada.\n\n");
            qtd_dis = categoria_disponivel_txt(cod_cat, qtd_acomd, acomodacao, categoria, pos_cat, disponiveis);
            if (qtd_dis == -1) {
                menu_modulo_reservas_mem();
            }
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código do Aço: %d\n", disponiveis[i].codigo_aco);
                printf("Descrição: %s\n", disponiveis[i].descricao);
                printf("Facilidades: %s\n", disponiveis[i].facilidades);
                printf("Código da Categoria: %d\n", disponiveis[i].categoria.codigo);
                printf("Descrição da Categoria: %s\n", disponiveis[i].categoria.descricao);
                printf("Valor Diário da Categoria: %.2f\n", disponiveis[i].categoria.valor_diaria);
                printf("Quantidade de Crianças da Categoria: %d\n", disponiveis[i].categoria.criancas);
                printf("Quantidade de Adultos da Categoria: %d\n\n", disponiveis[i].categoria.adultos);
            }
        } else if (data_filtro == 1) {
            printf("---------Filtro por Categoria---------\n");
            printf("Digite o codigo de uma das categorias dos quartos acima:");
            scanf("%d", &cod_cat);
            //verifica se o codigo da categoria é valido
            pos_cat = procura_categoria_filtrada_txt(cod_cat, disponiveis, qtd_dis);

            //se nao for entra em um loop
            while (pos_cat == -1) {
                contador_erro++;
                printf("Digite uma categoria válida:");
                scanf("%d", &cod_cat);
                pos_cat = procura_categoria_filtrada_txt(cod_cat, disponiveis, qtd_dis);
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair == 1) {
                    contador_erro = 0;
                    menu_modulo_reservas_mem();
                }
            }

            printf("\tAcomodações disponíveis com a categoria digitada.\n\n");
            qtd_dis = filtro_categoria_filtrada_txt(disponiveis, disponiveis, qtd_dis, cod_cat);
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código do Aço: %d\n", disponiveis[i].codigo_aco);
                printf("Descrição: %s\n", disponiveis[i].descricao);
                printf("Facilidades: %s\n", disponiveis[i].facilidades);
                printf("Código da Categoria: %d\n", disponiveis[i].categoria.codigo);
                printf("Descrição da Categoria: %s\n", disponiveis[i].categoria.descricao);
                printf("Valor Diário da Categoria: %.2f\n", disponiveis[i].categoria.valor_diaria);
                printf("Quantidade de Crianças da Categoria: %d\n", disponiveis[i].categoria.criancas);
                printf("Quantidade de Adultos da Categoria: %d\n\n", disponiveis[i].categoria.adultos);
            }
        }
    }
    printf("Deseja filtrar por quantidade de pessoa?(1-Sim/0-Não):");
    scanf("%d", &pessoas_filtro);
    if (pessoas_filtro == 1) {

        if (categoria_filtro == 0 && data_filtro == 0) {
            printf("------Filtro por Quantidade de Pessoas------\n");
            printf("Digite a quantidade exata de pessoas que deseja.\n");
            printf("Adultos:");
            scanf("%d", &adultos);
            printf("Crianças:");
            scanf("%d", &criancas);
            qtd_dis = pessoas_disponivel_txt(criancas, adultos, qtd_cat, qtd_acomd, categoria, acomodacao, disponiveis);
            if (qtd_dis == -1) {
                menu_modulo_reservas_mem();
            }


            for (int i = 0; i < qtd_dis; i++) {
                printf("Código do Aço: %d\n", disponiveis[i].codigo_aco);
                printf("Descrição: %s\n", disponiveis[i].descricao);
                printf("Facilidades: %s\n", disponiveis[i].facilidades);
                printf("Código da Categoria: %d\n", disponiveis[i].categoria.codigo);
                printf("Descrição da Categoria: %s\n", disponiveis[i].categoria.descricao);
                printf("Valor Diário da Categoria: %.2f\n", disponiveis[i].categoria.valor_diaria);
                printf("Quantidade de Crianças da Categoria: %d\n", disponiveis[i].categoria.criancas);
                printf("Quantidade de Adultos da Categoria: %d\n\n", disponiveis[i].categoria.adultos);
            }
        } else if (categoria_filtro == 1 || data_filtro == 1) {
            printf("------Filtro por Quantidade de Pessoas------\n");
            printf("Digite a quantidade exata de pessoas que deseja de acordo com os quartos acima.\n");
            printf("Adultos:");
            scanf("%d", &adultos);
            printf("Crianças:");
            scanf("%d", &criancas);
            retorno = procura_pessoas_filtrada_txt(criancas, adultos, disponiveis, qtd_dis);

            //se nao for entra em um loop
            while (retorno == -1) {
                contador_erro++;
                printf("Digite uma quantidade de pessoas que esteja nos quartos previamente filtrados:");
                printf("Adultos:");
                scanf("%d", &adultos);
                printf("Crianças:");
                scanf("%d", &criancas);
                retorno = procura_pessoas_filtrada_txt(criancas, adultos, disponiveis, qtd_dis);
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair == 1) {
                    contador_erro = 0;
                    menu_modulo_reservas_mem();
                }
            }
            printf("\tAcomodações disponíveis com a quantidade de pessoas digitada.\n\n");
            qtd_dis = filtro_pessoas_filtrada(criancas, adultos, disponiveis, disponiveis, qtd_dis);
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código do Aço: %d\n", disponiveis[i].codigo_aco);
                printf("Descrição: %s\n", disponiveis[i].descricao);
                printf("Facilidades: %s\n", disponiveis[i].facilidades);
                printf("Código da Categoria: %d\n", disponiveis[i].categoria.codigo);
                printf("Descrição da Categoria: %s\n", disponiveis[i].categoria.descricao);
                printf("Valor Diário da Categoria: %.2f\n", disponiveis[i].categoria.valor_diaria);
                printf("Quantidade de Crianças da Categoria: %d\n", disponiveis[i].categoria.criancas);
                printf("Quantidade de Adultos da Categoria: %d\n\n", disponiveis[i].categoria.adultos);
            }
        }
    }
    printf("Deseja filtrar por facilidades?(1-Sim/0-Não):");
    scanf("%d", &facilidades_filtro);
    if (facilidades_filtro == 1) {
        if (pessoas_filtro == 0 && categoria_filtro == 0 && pessoas_filtro == 0) {
            printf("------Filtro por Facildades------\n");
            printf("Digite a facilidade que deseja:");
            scanf(" %[^\n]s%*c", facilidade);
            qtd_dis = facilidades_disponiveis_txt(facilidade, acomodacao, qtd_acomd, disponiveis, categoria, qtd_cat);
            if (qtd_dis == -1) {
                menu_modulo_reservas_mem();
            }
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código do Aço: %d\n", disponiveis[i].codigo_aco);
                printf("Descrição: %s\n", disponiveis[i].descricao);
                printf("Facilidades: %s\n", disponiveis[i].facilidades);
                printf("Código da Categoria: %d\n", disponiveis[i].categoria.codigo);
                printf("Descrição da Categoria: %s\n", disponiveis[i].categoria.descricao);
                printf("Valor Diário da Categoria: %.2f\n", disponiveis[i].categoria.valor_diaria);
                printf("Quantidade de Crianças da Categoria: %d\n", disponiveis[i].categoria.criancas);
                printf("Quantidade de Adultos da Categoria: %d\n\n", disponiveis[i].categoria.adultos);
            }
        } else if (pessoas_filtro == 1 || categoria_filtro == 1 || pessoas_filtro == 1) {
            printf("------Filtro por Facildades------\n");
            printf("Digite a facilidade que deseja de acordo com os quartos previamente filtrados:");
            scanf(" %[^\n]s%*c", facilidade);
            retorno = procura_facilidades_filtrada_txt(facilidade, disponiveis, qtd_dis);
            while (retorno == -1) {
                contador_erro++;
                printf("Digite uma facilidades que esteja nos quartos previamente filtrados:");
                scanf(" %[^\n]s%*c", facilidade);
                retorno = procura_facilidades_filtrada_txt(facilidade, disponiveis, qtd_dis);
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair == 1) {
                    contador_erro = 0;
                    menu_modulo_reservas_mem();
                }
            }
            printf("\tAcomodações disponíveis com a facilidade digitada.\n\n");
            qtd_dis = filtro_facilidades_filtrada_txt(facilidade, disponiveis, disponiveis, qtd_dis);
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código do Aço: %d\n", disponiveis[i].codigo_aco);
                printf("Descrição: %s\n", disponiveis[i].descricao);
                printf("Facilidades: %s\n", disponiveis[i].facilidades);
                printf("Código da Categoria: %d\n", disponiveis[i].categoria.codigo);
                printf("Descrição da Categoria: %s\n", disponiveis[i].categoria.descricao);
                printf("Valor Diário da Categoria: %.2f\n", disponiveis[i].categoria.valor_diaria);
                printf("Quantidade de Crianças da Categoria: %d\n", disponiveis[i].categoria.criancas);
                printf("Quantidade de Adultos da Categoria: %d\n\n", disponiveis[i].categoria.adultos);
            }
        }
    }
    if (pessoas_filtro == 1 || categoria_filtro == 1 || facilidades_filtro == 1 || data_filtro == 1) {
        printf("Digite o código da acomodação que deseja reservar:");
        scanf("%d", &cod_aco);
        pos_aco = procura_acomodacao_disponivel(qtd_dis, cod_aco, disponiveis, acomodacao, qtd_acomd);
        while (pos_aco == -1) {
            contador_erro++;
            printf("Esse codigo de acomodação não está disponível digite um válido::");
            scanf("%d", &cod_aco);
            pos_aco = procura_acomodacao_disponivel(qtd_dis, cod_aco, disponiveis, acomodacao, qtd_acomd);
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas_mem();
            }
        }
        if (data_filtro == 0) {
            if (acomodacao[pos_aco].ocupacao == 0) {
                printf("Essa acomodação está disponivel para qualquer data.\n");
                printf("Digite uma data para fazer a reserva.\n");
                printf("Dia do Chekin:");
                scanf("%d", &datas.dia_in);
                printf("Mês do Chekin:");
                scanf("%d", &datas.mes_in);
                printf("Ano do Chekin:");
                scanf("%d", &datas.ano_in);
                printf("Dia do Chekout:");
                scanf("%d", &datas.dia_out);
                printf("Mês do Chekout:");
                scanf("%d", &datas.mes_out);
                printf("Ano do Chekout:");
                scanf("%d", &datas.ano_out);
                ret_data = data_atual(datas);
                while (ret_data == 1) {
                    printf("Essa data não é válida, digite um data valida.\n");
                    printf("Digite a data que deseja fazer o chek-in.\n");
                    printf("Dia:");
                    scanf("%d", &datas.dia_in);
                    printf("Mes:");
                    scanf("%d", &datas.mes_in);
                    printf("Ano:");
                    scanf("%d", &datas.ano_in);
                    printf("Digite a data que deseja fazer o chek-out.\n");
                    printf("Dia:");
                    scanf("%d", &datas.dia_out);
                    printf("Mes:");
                    scanf("%d", &datas.mes_out);
                    printf("Ano:");
                    scanf("%d", &datas.ano_out);
                    ret_data = data_atual(datas);
                    contador_erro++;
                    if (contador_erro > 2) {
                        printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não):");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }
                    if (sair != 0) {
                        contador_erro = 0;
                        menu_modulo_reservas_mem();
                    }
                }
            } else {
                printf("Essa acomodação não esta disponivel nessas datas,lembrando que uma dessas datas é a da própria reserva que esta sendo atualizada.\n");
                procura_data_reserva_txt(qtd_res, cod_aco, reserva);
                printf("Digite uma data para fazer a reserva que não seja esssas datas mostradas.\n");
                printf("Dia do Chekin:");
                scanf("%d", &datas.dia_in);
                printf("Mês do Chekin:");
                scanf("%d", &datas.mes_in);
                printf("Ano do Chekin:");
                scanf("%d", &datas.ano_in);
                printf("Dia do Chekout:");
                scanf("%d", &datas.dia_out);
                printf("Mês do Chekout:");
                scanf("%d", &datas.mes_out);
                printf("Ano do Chekout:");
                scanf("%d", &datas.ano_out);
                ret_data = data_atual(datas);
                while (ret_data == 1) {
                    printf("Essa data não é válida, digite um data valida.\n");
                    printf("Digite a data que deseja fazer o chek-in.\n");
                    printf("Dia:");
                    scanf("%d", &datas.dia_in);
                    printf("Mes:");
                    scanf("%d", &datas.mes_in);
                    printf("Ano:");
                    scanf("%d", &datas.ano_in);
                    printf("Digite a data que deseja fazer o chek-out.\n");
                    printf("Dia:");
                    scanf("%d", &datas.dia_out);
                    printf("Mes:");
                    scanf("%d", &datas.mes_out);
                    printf("Ano:");
                    scanf("%d", &datas.ano_out);
                    ret_data = data_atual(datas);
                    contador_erro++;
                    if (contador_erro > 2) {
                        printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não):");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }
                    if (sair != 0) {
                        contador_erro = 0;
                        menu_modulo_reservas_mem();
                    }
                }
                //verifico se a data que o usuario digitou nao bate com nenhuma outra
                ret_reserva = verifica_data_txt(qtd_res, reserva, datas, cod_aco);
                while (ret_reserva == -1) {
                    printf("Voce digitou uma data que ja esta reservada.\nDigite outra data\n");
                    printf("Dia do Chekin:");
                    scanf("%d", &datas.dia_in);
                    printf("Mês do Chekin:");
                    scanf("%d", &datas.mes_in);
                    printf("Ano do Chekin:");
                    scanf("%d", &datas.ano_in);
                    printf("Dia do Chekout:");
                    scanf("%d", &datas.dia_out);
                    printf("Mês do Chekout:");
                    scanf("%d", &datas.mes_out);
                    printf("Ano do Chekout:");
                    scanf("%d", &datas.ano_out);

                    ret_data = data_atual(datas);
                    while (ret_data == 1) {
                        printf("Essa data não é válida, digite um data valida.\n");
                        printf("Digite a data que deseja fazer o chek-in.\n");
                        printf("Dia:");
                        scanf("%d", &datas.dia_in);
                        printf("Mes:");
                        scanf("%d", &datas.mes_in);
                        printf("Ano:");
                        scanf("%d", &datas.ano_in);
                        printf("Digite a data que deseja fazer o chek-out.\n");
                        printf("Dia:");
                        scanf("%d", &datas.dia_out);
                        printf("Mes:");
                        scanf("%d", &datas.mes_out);
                        printf("Ano:");
                        scanf("%d", &datas.ano_out);
                        ret_data = data_atual(datas);
                        contador_erro++;
                        if (contador_erro > 2) {
                            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não):");
                            scanf("%d", &sair);
                            contador_erro = 0;
                        }
                        if (sair != 0) {
                            contador_erro = 0;
                            menu_modulo_reservas_mem();
                        }
                    }
                    contador_erro++;
                    ret_reserva = verifica_data_txt(qtd_res, reserva, datas, cod_aco);
                    if (contador_erro > 2) {
                        printf("Voce digitou varias datas que ja estao ocupadas deseja sair?(1-Sim/0-Não):");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }
                    if (sair != 0) {
                        contador_erro = 0;
                        menu_modulo_reservas_mem();
                    }
                }
            }
        }

        if (indicie == 0) {
            reserva[indicie].codigo_res = 1;
        } else {
            reserva[indicie].codigo_res = reserva[indicie - 1].codigo_res + 1;
        }
        printf("O codigo da reserva sera: %d.\n",reserva[indicie].codigo_res);
        
        

        printf("Digite o codigo do hospede que deseja fazer a reserva:");
        scanf("%d", &cod_hos);
        pos_hos = procura_hospede_txt(cod_hos, qtd_hos, hospede);
        while (pos_hos == -1) {
            contador_erro++;
            printf("Digite um codigo de hospede valido:");
            scanf("%d", &cod_hos);
            pos_hos = procura_hospede_txt(cod_hos, qtd_hos, hospede);
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas_mem();
            }
        }
        int dias;
        float valor;
        dias = contarDias(datas);

        pos_cat = procura_categoria_txt(acomodacao[pos_aco].categoria, qtd_cat, categoria);
        valor = categoria[pos_cat].valor_diaria*dias;


        acomodacao[pos_aco].ocupacao++;
        acomodacao[pos_aco].lucro += valor;
        acomodacao[pos_aco].diarias += dias;
        
        reserva[indicie].codigo_aco = acomodacao[pos_aco].codigo;
        strcpy(reserva[indicie].descricao, acomodacao[pos_aco].descricao);
        strcpy(reserva[indicie].facilidades, acomodacao[pos_aco].facilidades);
        for (int i = 0; i < qtd_cat; i++) {
            if (categoria[i].codigo == acomodacao[pos_aco].categoria) {
                reserva[indicie].categoria.codigo = categoria[i].codigo;
                strcpy(reserva[indicie].categoria.descricao, categoria[i].descricao);
                reserva[indicie].categoria.valor_diaria = categoria[i].valor_diaria;
                reserva[indicie].categoria.adultos = categoria[i].adultos;
                reserva[indicie].categoria.criancas = categoria[i].criancas;
                break;
            }
        }
        reserva[indicie].datas.ano_in = datas.ano_in;
        reserva[indicie].datas.mes_in = datas.mes_in;
        reserva[indicie].datas.dia_in = datas.dia_in;
        reserva[indicie].datas.ano_out = datas.ano_out;
        reserva[indicie].datas.mes_out = datas.mes_out;
        reserva[indicie].datas.dia_out = datas.dia_out;
        reserva[indicie].cod_hospede = cod_hos;



        free(disponiveis);
        menu_modulo_reservas_mem();
    }
    
    free(disponiveis);
    menu_modulo_reservas_mem();

}

//funcao para cancelar reserva
void deleta_reservas_mem() {
    //variaveis para deletar acomodações
    int sair = 0, pos_aco=0,codigo = 0, posicao = 0, contador_erro = 0, delete = 0, pos_res = 0, pos_cat=0;


    printf("--------Cancelar reservas----------\n");
    printf("Digite o codigo da reserva que deseja cancelar:");
    scanf("%d", &codigo);
    pos_res = procura_reserva_txt(codigo, qtd_res, reserva);
    
    while (pos_res == -1) {
        //pedindo ao usuario o codigo da reserva que deseja alterar
        printf("Digite um codigo de reserva válido:");
        scanf("%d", &codigo);

        //funcao para procurar a reserva
        pos_res = procura_reserva_txt(codigo, qtd_res, reserva);

        if (contador_erro > 3) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_modulo_reservas_mem();
        }

    }

    printf("---------Dados da reserva---------\n");
    printf("Código da reserva:%d\n", reserva[pos_res].codigo_res);
    printf("Codigo do quarto:%d\n", reserva[pos_res].codigo_aco);
    printf("Descrição do quarto:%s\n", reserva[pos_res].descricao);
    printf("Facilidades do quarto:%s\n", reserva[pos_res].facilidades);
    printf("Codigo da categoria:%d\n", reserva[pos_res].categoria.codigo);
    printf("Descrição da categoria:%s\n", reserva[pos_res].descricao);
    printf("Valor da diária da categoria:%f\n", reserva[pos_res].categoria.valor_diaria);
    printf("Crianças comportadas:%d\n", reserva[pos_res].categoria.criancas);
    printf("Adultos comportadas:%d\n", reserva[pos_res].categoria.adultos);
    printf("Data do check-in:%d/%d/%d\n", reserva[pos_res].datas.dia_in, reserva[pos_res].datas.mes_in, reserva[pos_res].datas.ano_in);
    printf("Data do check-out:%d/%d/%d\n", reserva[pos_res].datas.dia_out, reserva[pos_res].datas.mes_out, reserva[pos_res].datas.ano_out);
    printf("Código do hóspede:%d\n\n", reserva[pos_res].cod_hospede);
    pos_aco = procura_acomodacao_txt(reserva[pos_res].codigo_aco, qtd_acomd, acomodacao);
    
    printf("Realmente deseja cancelar essa reserva?(1-Sim/0-Não):");
    scanf("%d", &delete);

    if (delete == 1) {
        
        int dias;
        float valor;
        pos_cat = procura_categoria_txt(reserva[pos_res].categoria.codigo, qtd_cat, categoria);
        dias = contarDias(reserva[pos_res].datas);
        valor = dias * categoria[pos_cat].valor_diaria;


        acomodacao[pos_aco].ocupacao--;
        acomodacao[pos_aco].diarias -= dias;
        acomodacao[pos_aco].lucro -= valor;

        for (int i = posicao; i < qtd_res; i++) {
            reserva[i] = reserva[i + 1];
        }
        qtd_res--;
        reserva = (reservas *) realloc(reserva, qtd_res * sizeof (reservas));     
    }
    
        

    menu_modulo_reservas_mem();
}
//FIM DO MODULO DE RESERVAS




//INICIO DO MODULO DE TRANSACOES
//fazendo chekin do hospede
void chekin_mem() {
    int cod_res, pos_res, sair = 0, contador_erro = 0, opcao, pagamento, dias;
    float valor;

    data date;
    data_chek_in_out datas;
    
    qtd_con++;
    int indicie_con = qtd_con - 1;
    conta = (conta_hospede *) realloc(conta, qtd_con * sizeof (conta_hospede));
    
    qtd_cai++;
    int indicie_cai = qtd_cai -1;
    caixa = (conta_receber *) realloc(caixa, qtd_cai * sizeof (conta_receber));
    
    qtd_con_rec++;
    int indicie_rec = qtd_con_rec -1;
    conta_rec = (conta_receber *) realloc(conta_rec, qtd_con_rec * sizeof (conta_receber));
    
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    
    
    

    printf("------CHECK-IN--------\n");
    printf("Digite o código da reserva para fazer o check-in:");
    scanf("%d", &cod_res);
    pos_res = procura_reserva_txt(cod_res, qtd_res, reserva);
    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reserva);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_mem();
        }
    }
    //aqui eu trago a data de reserva para calcular quantos dias o hospede vai ficar no hotel
    datas.ano_in = reserva[pos_res].datas.ano_in;
    datas.mes_in = reserva[pos_res].datas.mes_in;
    datas.dia_in = reserva[pos_res].datas.dia_in;
    datas.ano_out = reserva[pos_res].datas.ano_out;
    datas.mes_out = reserva[pos_res].datas.mes_out;
    datas.dia_out = reserva[pos_res].datas.dia_out;

    //contando a diferenca de dias entre as datas
    dias = contarDias(datas);
    //calculando o valor da diaria
    valor = dias * reserva[pos_res].categoria.valor_diaria;

    printf("Deseja pagar a hospedagem em qual momento?\n");
    printf("1-Check-in.\n");
    printf("2-Check-out.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Escolha a forma de pagamento.\n");
        printf("1-Dinheiro.\n");
        printf("2-Cartão de crédito.\n");
        printf("3-Cartão de débito.\n");
        printf("Digite a opção desejada:");
        scanf("%d", &pagamento);
        if (pagamento == 1) {

            caixa[indicie_cai].codigo_hos=reserva[pos_res].cod_hospede;
            caixa[indicie_cai].valor_devido=valor;
            caixa[indicie_cai].date.ano=tm.tm_year + 1900;
            caixa[indicie_cai].date.mes=tm.tm_mon + 1;
            caixa[indicie_cai].date.dia=tm.tm_mday;
            
            

            conta[indicie_con].codigo_hos = reserva[pos_res].cod_hospede;
            conta[indicie_con].codigo_res = reserva[pos_res].codigo_res;
            conta[indicie_con].valor_devido = 0;
            
            
        } else if (pagamento == 2 || pagamento == 3) {
            printf("Digite a data do vencimento do cartão do hóspede.\n");
            printf("Dia:");
            scanf("%d", &date.dia);
            printf("Mês:");
            scanf("%d", &date.mes);
            printf("Ano:");
            scanf("%d", &date.ano);
            
            conta_rec[indicie_rec].codigo_hos=reserva[pos_res].cod_hospede;
            conta_rec[indicie_rec].valor_devido=valor;
            conta_rec[indicie_rec].date.ano=date.ano;
            conta_rec[indicie_rec].date.mes=date.mes;
            conta_rec[indicie_rec].date.dia=date.dia;
            
            
            conta[indicie_con].codigo_hos = reserva[pos_res].cod_hospede;
            conta[indicie_con].codigo_res = reserva[pos_res].codigo_res;
            conta[indicie_con].valor_devido = 0;
           
            
        }
    } else if (opcao == 2) {
        conta[indicie_con].codigo_hos = reserva[pos_res].cod_hospede;
        conta[indicie_con].codigo_res = reserva[pos_res].codigo_res;
        conta[indicie_con].valor_devido = valor;
        
        
    }
    menu_modulo_transacoes_mem();
}

//fazendo o chekout do hospede
void chekout_mem() {
    int cod_res, sair = 0, contador_erro = 0;
    int opcao, pagamento, pos_con, pos_res, pos_aco;

    qtd_cai++;
    int indicie_cai = qtd_cai - 1;
    caixa = (conta_receber *) realloc(caixa, qtd_cai * sizeof (conta_receber));

    qtd_con_rec++;
    int indicie_rec = qtd_con_rec - 1;
    conta_rec = (conta_receber *) realloc(conta_rec, qtd_con_rec * sizeof (conta_receber));

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    data date;

    printf("------CHECK-OUT--------\n");

    printf("Digite o código da reserva para fazer o check-out:");
    scanf("%d", &cod_res);

    pos_res = procura_reserva_txt(cod_res, qtd_res, reserva);
    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reserva);

        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_mem();
        }
    }

    pos_con = procura_conta_txt(cod_res, conta, qtd_con);

    if (conta[pos_con].valor_devido == 0) {
        printf("Você não possui nenhum saldo devedor.\n");

        for (int i = pos_res; i < qtd_res; i++) {

            reserva[i] = reserva[i + 1];
        }
        qtd_res--;
        reserva = (reservas *) realloc(reserva, qtd_res * sizeof (reservas));

        //procurando acomodacao para tirar 1 da ocupacao 
        pos_aco = procura_acomodacao_txt(reserva[pos_res].codigo_aco, qtd_acomd, acomodacao);
        acomodacao[pos_aco].ocupacao--;


        //deletando a conta do hospede
        for (int i = pos_con; i < qtd_con; i++) {

            conta[i] = conta[i + 1];
        }

        qtd_con--;
        conta = (conta_hospede *) realloc(conta, qtd_con * sizeof (conta_hospede));

    } else {
        printf("O saldo devedor do hóspede é de:%.2f reais.\n", conta[pos_con].valor_devido);
        printf("Como deseja pagar?\n");
        printf("1-Dinheiro.\n");
        printf("2-Cartão de crédito.\n");
        printf("3-Cartão de débito.\n");
        printf("Digite a opção desejada:");
        scanf("%d", &pagamento);
        if (pagamento == 1) {


            //salvando no caixa  o valor pago pelo hospede       
            caixa[indicie_cai].codigo_hos = reserva[pos_res].cod_hospede;
            caixa[indicie_cai].valor_devido = conta[pos_con].valor_devido;
            caixa[indicie_cai].date.dia = tm.tm_mday;
            caixa[indicie_cai].date.mes = tm.tm_mon + 1;
            caixa[indicie_cai].date.ano = tm.tm_year + 1900;

            //deletando a reserva ja que o hospede ja saiu do quarto
            for (int i = pos_res; i < qtd_res; i++) {

                reserva[i] = reserva[i + 1];
            }
            qtd_res--;
            reserva = (reservas *) realloc(reserva, qtd_res * sizeof (reservas));

            //procurando acomodacao para tirar 1 da ocupacao 
            pos_aco = procura_acomodacao_txt(reserva[pos_res].codigo_aco, qtd_acomd, acomodacao);
            acomodacao[pos_aco].ocupacao--;

            //deletando a conta do hospede
            for (int i = pos_con; i < qtd_con; i++) {

                conta[i] = conta[i + 1];
            }

            qtd_con--;
            conta = (conta_hospede *) realloc(conta, qtd_con * sizeof (conta_hospede));

        } else if (pagamento == 2 || pagamento == 3) {
            printf("Digite a data do vencimento do cartão do hóspede.\n");
            printf("Dia:");
            scanf("%d", &date.dia);
            printf("Mês:");
            scanf("%d", &date.mes);
            printf("Ano:");
            scanf("%d", &date.ano);

            conta_rec[indicie_rec].date.dia = date.dia;
            conta_rec[indicie_rec].date.mes = date.mes;
            conta_rec[indicie_rec].date.ano = date.ano;
            conta_rec[indicie_rec].codigo_hos = reserva[pos_res].cod_hospede;
            conta_rec[indicie_rec].valor_devido = conta[pos_con].valor_devido;


            //deletando a reserva ja que o hospede ja saiu do quarto
            for (int i = pos_res; i < qtd_res; i++) {

                reserva[i] = reserva[i + 1];
            }
            qtd_res--;
            reserva = (reservas *) realloc(reserva, qtd_res * sizeof (reservas));

            //procurando acomodacao para tirar 1 da ocupacao 
            pos_aco = procura_acomodacao_txt(reserva[pos_res].codigo_aco, qtd_acomd, acomodacao);
            acomodacao[pos_aco].ocupacao--;

            //deletando a conta do hospede
            for (int i = pos_con; i < qtd_con; i++) {

                conta[i] = conta[i + 1];
            }

            qtd_con--;
            conta = (conta_hospede *) realloc(conta, qtd_con * sizeof (conta_hospede));
        }
    }
    menu_modulo_transacoes_mem();
}

//fazendo as vendas de produtos do hotel
void venda_mem() {
    int pos_con, pos_prod, contador_erro = 0, sair = 0, pagamento, cod_res, pos_res;
    
    qtd_venda++;
    int indicie = qtd_venda - 1;
    venda = (vendas *) realloc(conta, qtd_venda * sizeof (vendas));
    
    qtd_cai++;
    int indicie_cai = qtd_cai - 1;
    caixa = (conta_receber *) realloc(caixa, qtd_cai * sizeof (conta_receber));
    
    
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    

    printf("-----VENDAS-------\n");
    printf("Digite o código da reserva do hóspede que está comprando:");
    scanf("%d", &cod_res);
    pos_res = procura_reserva_txt(cod_res, qtd_res, reserva);
    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reserva);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_mem();
        }
    }
    printf("PRODUTOS DISPONÍVEIS:\n");
    mostra_produto_txt(qtd_pro, produto);
    printf("Digite o código do produto que deseja:");
    scanf("%d", &venda[indicie].cod_prod);
    pos_prod = procura_produto_txt(venda[indicie].cod_prod, qtd_pro, produto);
    while (pos_prod == -1) {
        contador_erro++;
        printf("Esse codigo de produto não existe, digite um válido:");
        scanf("%d", &venda[indicie].cod_prod);
        pos_prod = procura_produto_txt(venda[indicie].cod_prod, qtd_pro, produto);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_mem();
        }
    }
    printf("Quantos desse produto deseja comprar?:");
    scanf("%d", &venda[indicie].qtd);
    while (venda[indicie].qtd > produto[pos_prod].estoque) {
        contador_erro++;
        printf("Não tem estoque disponível para essa quantidade,digite uma quantidade que tenha no estoque:");
        scanf("%d", &venda[indicie].qtd);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_mem();
        }
    }
    venda[indicie].valor = venda[indicie].qtd * produto[pos_prod].preco_venda;
    printf("Qual a forma de pagamento?\n");
    printf("1-A vista.\n");
    printf("2-Anotar.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &pagamento);
    if (pagamento == 1) {
        venda[indicie].pagamento = pagamento;
        venda[indicie].cod_hos = reserva[pos_res].cod_hospede;
        
        
        caixa[indicie_cai].codigo_hos=reserva[pos_res].cod_hospede;
        caixa[indicie_cai].valor_devido=venda[indicie].valor;
        caixa[indicie_cai].date.ano = tm.tm_year + 1900;
        caixa[indicie_cai].date.mes = tm.tm_mon + 1;
        caixa[indicie_cai].date.dia = tm.tm_mday;
        
        

        produto[pos_prod].estoque -= venda[indicie].qtd;
        

    } else if (pagamento == 2) {
        venda[indicie].pagamento = pagamento;
        venda[indicie].cod_hos = reserva[pos_res].cod_hospede;
        //fazendo a notinha
        printf("\n-------NOTINHA---------\n");
        printf("Código do hóspede:%d\n", venda[indicie].cod_hos);
        printf("Codigo do produto:%d\n", venda[indicie].cod_prod);
        printf("Nome do produto:%s\n", produto[pos_prod].descricao);
        printf("Quantidade:%d\n", venda[indicie].qtd);
        printf("Valor unitário:%.2f\n", produto[pos_prod].preco_venda);
        printf("Valor total da notinha:%.2f\n\n", venda[indicie].valor);

        
        //adicionando o valor comprando na conta do hospede
        pos_con = procura_conta_txt(cod_res, conta, qtd_con);
        
        conta[pos_con].valor_devido = conta[pos_con].valor_devido + venda[indicie].valor;

        //atualizando o estoque
        produto[pos_prod].estoque -= venda[indicie].qtd;
    }
    menu_modulo_transacoes_mem();
}

//listando os movimentos de caixa
void caixa_mem() {

    if (qtd_cai == 0) {
        printf("Não tem nenhum movimento no caixa.\n");
        menu_modulo_transacoes_mem();
    }
    printf("-----CONTROLE DE CAIXA------\n");

    for (int i = 0; i < qtd_cai; i++) {
        printf("Código: %d\n", caixa[i].codigo_hos);

        // Verifica se o valor é positivo ou negativo e imprime o sinal correspondente
        if (caixa[i].valor_devido >= 0) {
            printf("Valor: +%.2f\n", caixa[i].valor_devido);
        } else {
            printf("Valor: %.2f\n", caixa[i].valor_devido);
        }

        printf("Data: %d/%d/%d\n", caixa[i].date.dia, caixa[i].date.mes, caixa[i].date.ano);
    }

    menu_modulo_transacoes_mem();
}

//dando baixa nas contas a receber
void receber_mem() {
    int cod_conta, sair = 0, contador_erro = 0;
    
    if(qtd_con_rec==0){
        printf("Não tem conta a receber.\n");
    }
    
    
    qtd_con_rec++;
    int indicie_rec = qtd_con_rec -1;
    conta_rec = (conta_receber *) realloc(conta_rec, qtd_con_rec * sizeof (conta_receber));
    
    
    qtd_cai++;
    int indicie_cai = qtd_cai - 1;
    caixa = (conta_receber *) realloc(caixa, qtd_cai * sizeof (conta_receber));

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    
    
    
    
    
    printf("\n-----CONTAS A RECEBER------\n");
    mostra_contas_a_receber_txt(qtd_con_rec, conta_rec);
    printf("Digite a conta que deseja dar baixa:");
    scanf("%d", &cod_conta);
    while (cod_conta + 1 > qtd_con_rec) {
        printf("Digite uma conta válida que deseja dar baixa:");
        scanf("%d", &cod_conta);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_conta_receber_mem();
        }
    }
    caixa[indicie_cai].codigo_hos=conta[cod_conta].codigo_hos;
    caixa[indicie_cai].valor_devido=conta[cod_conta].valor_devido;
    caixa[indicie_cai].date.ano = tm.tm_year + 1900;
    caixa[indicie_cai].date.mes = tm.tm_mon + 1;
    caixa[indicie_cai].date.dia = tm.tm_mday;
    
    for(int i=cod_conta;i<qtd_con_rec;i++){
        conta[i]=conta[i+1];
    }
    
    menu_conta_receber_mem();
}

//listando todas contas a receber
void listar_conta_receber_mem() {

    if (qtd_con_rec == 0) {
        printf("Não tem nenhuma conta a receber.\n");
        menu_conta_receber_mem();
    }

    printf("\n--------LISTA DE CONTAS A RECEBER--------\n");

    for (int i = 0; i < qtd_con; i++) {
        printf("Codigo da conta:%d\n", i);
        printf("Código do hóspede: %d\n", conta_rec[i].codigo_hos);
        printf("Valor: +%.2f\n", conta_rec[i].valor_devido);
        printf("Data: %d/%d/%d\n\n", conta_rec[i].date.dia, conta_rec[i].date.mes, conta_rec[i].date.ano);
    }

    menu_conta_receber_mem();
}

// dando entrada em notas de fornecedores
void entrada_produtos_mem() {
    float frete_prod, imposto_prod, entrada;
    float total = 0, prazo = 0, saldo = 0;
    int vezes, pos_for, contador_erro = 0, retorno, sair = 0, pagamento;
    int qtd_total = 0, pos_prod, estoque_min, cod_prod;

    
    qtd_notas++;
    int indicie = qtd_notas - 1;
    notas = (vendas *) realloc(notas, qtd_notas * sizeof (vendas));
    

    notas[indicie].num_produtos = 0;
    notas[indicie].total = 0;
    notas[indicie].entra_prod = NULL;
    
    
    qtd_cai++;
    int indicie_cai = qtd_cai - 1;
    caixa = (conta_receber *) realloc(caixa, qtd_cai * sizeof (conta_receber));

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    
    

    printf("\n-------ENTRADA DE NOTAS--------\n");
    printf("Digite a razão social do fornecedor:");
    scanf(" %[^\n]s%*c", notas[indicie].fornecedor);
    setbuf(stdin, NULL);
    pos_for = procura_fornecedor_nome_txt(notas[indicie].fornecedor, qtd_forn, fornecedor);
    if (pos_for == -1) {
        printf("Vejo que esse fornecedor não está cadastrado, cadastre ele primerio.\n");
        cadastro_fornecedores_mem();
    }
    strcpy(notas[indicie].cnpj, fornecedor[pos_for].cnpj);


    printf("Digite o valor do frete:");
    scanf("%f", &notas[indicie].frete);
    printf("Digite o valor do imposto:");
    scanf("%f", &notas[indicie].imposto);

    while (sair == 0) {
        notas[indicie].entra_prod = realloc(notas[indicie].entra_prod, (notas[indicie].num_produtos + 1) * sizeof (entrada_produto));

        if (notas[indicie].entra_prod == NULL) {
            perror("Erro ao alocar memória");
            exit(EXIT_FAILURE);
        }

        // Ler informações do usuário
        printf("Digite a descrição do produto: ");
        scanf(" %[^\n]s%*c", notas[indicie].entra_prod[notas[indicie].num_produtos].nome);
        setbuf(stdin, NULL);
        printf("Digite o preço do produto: ");
        scanf("%f", &notas[indicie].entra_prod[notas[indicie].num_produtos].preco);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &notas[indicie].entra_prod[notas[indicie].num_produtos].quantidade);

        // Calcular subtotal
        notas[indicie].entra_prod[notas[indicie].num_produtos].subtotal =
                notas[indicie].entra_prod[notas[indicie].num_produtos].preco * notas[indicie].entra_prod[notas[indicie].num_produtos].quantidade;

        // Atualizar total da nota e quantidade total
        notas[indicie].total += notas[indicie].entra_prod[notas[indicie].num_produtos].subtotal;
        qtd_total += notas[indicie].entra_prod[notas[indicie].num_produtos].quantidade;

        // Verificar se há mais produtos
        printf("A nota possui mais produtos? (0-Sim/1-Não): ");
        scanf("%d", &sair);

        notas[indicie].num_produtos++;
    }

    imposto_prod = notas[indicie].imposto / qtd_total;
    frete_prod = notas[indicie].frete / qtd_total;

    for (int i = 0; i < notas[indicie].num_produtos; i++) {
        retorno = procura_produto_nome_txt(notas[indicie].entra_prod[i].nome, qtd_pro, produto);
        if (retorno == -1) {
            printf("O produto %s ainda não foi cadastrado.\n", notas[indicie].entra_prod[i].nome);
            printf("Digite o estoque minímo para o cadastrá-lo:");
            scanf("%d", &estoque_min);
            printf("Digite um código para esse produto:");
            scanf("%d", &cod_prod);
            pos_prod = procura_produto_txt(cod_prod, qtd_pro, produto);
            sair = 0;
            while (pos_prod != -1) {
                printf("Esse codigo de produto ja existe digite um diferente:");
                scanf("%d", &cod_prod);
                pos_prod = procura_produto_txt(cod_prod, qtd_pro, produto);
                contador_erro++;
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair != 0) {
                    menu_modulo_transacoes_mem();
                }
            }
            
            qtd_pro++;
            produto = (produtos *) realloc(produto, qtd_pro * sizeof (produtos));
            int indicie_prod = qtd_pro - 1;
            
            produto[indicie_prod].codigo = cod_prod;
            strcpy(produto[indicie_prod].descricao, notas[indicie].entra_prod[i].nome);
            produto[indicie_prod].estoque = notas[indicie].entra_prod[i].quantidade;
            produto[indicie_prod].estoque_min = estoque_min;
            produto[indicie_prod].preco_custo = notas[indicie].entra_prod[i].preco;
            produto[indicie_prod].preco_venda = (frete_prod + imposto_prod + notas[indicie].entra_prod[i].preco) * ((hotel.mlpv + 100) / 100);
            
            
        } else {
            produto[retorno].estoque += notas[indicie].entra_prod[i].quantidade;
            produto[retorno].preco_custo = notas[indicie].entra_prod[i].preco;
            produto[retorno].preco_venda = (frete_prod + imposto_prod + notas[indicie].entra_prod[i].preco) * ((hotel.mlpv + 100) / 100);
            
        }
    }

    
    notas[indicie].total += notas[indicie].frete + notas[indicie].imposto;
    saldo = calcula_saldo_caixa(qtd_cai, caixa);

    printf("Valor total da nota:%.2f\n", notas[indicie].total);
    printf("Valor total em caixa:%.2f\n", saldo);
    printf("Qual será a forma de pagamento do nota fiscal?\n");
    printf("1-A vista.\n");
    printf("2-A prazo.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &pagamento);
    if (pagamento == 1) {
        if (saldo < notas[indicie].total) {
            printf("O caixa não possui saldo suficiente para o pagamento,logo pagará a prazo.\n");
            pagamento = 2;
        } else {
            
            caixa[indicie_cai].codigo_hos = fornecedor[pos_for].codigo;
            caixa[indicie_cai].valor_devido = -notas[indicie].total;
            caixa[indicie_cai].date.ano = tm.tm_year + 1900;
            caixa[indicie_cai].date.mes = tm.tm_mon + 1;
            caixa[indicie_cai].date.dia = tm.tm_mday;
            
        }
    }
    if (pagamento == 2) {
        printf("1-Deseja pagar uma entrada e o restante a prazo.\n");
        printf("2-Deseja pagar tudo a prazo.\n");
        printf("Digite a opção desejada:");
        scanf("%d", &pagamento);
        if (pagamento == 1) {
            printf("Digite a quantia que será dada de entrada:");
            scanf("%f", &entrada);
            while (entrada > saldo) {
                printf("Saldo:%.2f\n", saldo);
                printf("O caixa não possui esse saldo,digite um valor válido:");
                scanf("%f", &entrada);
            }
            printf("Deseja parcelar em quantas vezes o restante?:");
            scanf("%d", &vezes);
            prazo = notas[indicie].total - entrada;
            
            caixa[indicie_cai].codigo_hos = fornecedor[pos_for].codigo;
            caixa[indicie_cai].valor_devido = -entrada;
            caixa[indicie_cai].date.ano = tm.tm_year + 1900;
            caixa[indicie_cai].date.mes = tm.tm_mon + 1;
            caixa[indicie_cai].date.dia = tm.tm_mday;
            
            
            
            for(int i=0;i<vezes;i++){
                
                qtd_con_pag++;
                int indicie_pag = qtd_con_pag - 1;
                conta_pag = (conta_receber *) realloc(conta_pag, indicie_pag * sizeof (conta_receber));
                
                conta_pag[indicie_pag].valor_devido = prazo/vezes;
                conta_pag[indicie_pag].codigo_hos = fornecedor[pos_for].codigo;
                
                // Adicionar 30 dias
                tm.tm_mday += 30;
                time_t newTime = mktime(&tm);

                // Extrair dia, mês e ano da nova data
                struct tm newTm = *localtime(&newTime);
                int newDay = newTm.tm_mday;
                int newMonth = newTm.tm_mon + 1; // tm_mon é base 0 (janeiro = 0)
                int newYear = newTm.tm_year + 1900;
                
                conta_pag[indicie_pag].date.dia = newDay;
                conta_pag[indicie_pag].date.mes = newMonth;
                conta_pag[indicie_pag].date.ano = newYear;
                
                
            }
            
            
            
            
   
        } else {
            printf("Deseja parcelar em quantas vezes?:");
            scanf("%d", &vezes);
            for (int i = 0; i < vezes; i++) {
                
                qtd_con_pag++;
                int indicie_pag = qtd_con_pag - 1;
                conta_pag = (conta_receber *) realloc(conta_pag, indicie_pag * sizeof (conta_receber));
                
                
                conta_pag[indicie_pag].valor_devido = notas[indicie].total/vezes;
                conta_pag[indicie_pag].codigo_hos = fornecedor[pos_for].codigo;

                // Adicionar 30 dias
                tm.tm_mday += 30;
                time_t newTime = mktime(&tm);

                // Extrair dia, mês e ano da nova data
                struct tm newTm = *localtime(&newTime);
                int newDay = newTm.tm_mday;
                int newMonth = newTm.tm_mon + 1; // tm_mon é base 0 (janeiro = 0)
                int newYear = newTm.tm_year + 1900;

                conta_pag[indicie_pag].date.dia = newDay;
                conta_pag[indicie_pag].date.mes = newMonth;
                conta_pag[indicie_pag].date.ano = newYear;

                


            }
            
            
        }
    }

    

    menu_modulo_transacoes();
}

//dando baixa nas contas a pagar
void conta_pagar_mem() {

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    int cod_conta, sair = 0, contador_erro = 0;
    float saldo = 0;

    if (qtd_con_pag == 0) {
        printf("Não tem nenhuma conta a pagar.\n");
        menu_conta_receber_mem();
    }

    qtd_cai++;
    int indicie_cai = qtd_cai - 1;
    caixa = (conta_receber *) realloc(caixa, qtd_cai * sizeof (conta_receber));

    printf("\n-----CONTAS A PAGAR------\n");

    for (int i = 0; i < qtd_con_pag; i++) {
        printf("Codigo da conta:%d\n", i);
        printf("Codigo do fornecedor:%d", conta_pag[i].codigo_hos);
        printf("Valor: +%.2f\n", conta_pag[i].valor_devido);
        printf("Data: %d/%d/%d\n\n", conta_pag[i].date.dia, conta_pag[i].date.mes, conta_pag[i].date.ano);
    }

    printf("Digite a conta que deseja dar baixa:");
    scanf("%d", &cod_conta);
    while (cod_conta + 1 > qtd_con_pag) {
        printf("Digite uma conta válida que deseja dar baixa:");
        scanf("%d", &cod_conta);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_conta_pagar_mem();
        }
    }
    if (conta_pag[cod_conta].valor_devido > saldo) {
        printf("O caixa não possui saldo o suficiente para pagar.\n");
        printf("Saldo do caixa:%.2f\n", saldo);
        menu_conta_pagar_mem();
    } else {

        caixa[indicie_cai].codigo_hos = conta[cod_conta].codigo_hos;
        caixa[indicie_cai].valor_devido = -conta[cod_conta].valor_devido;
        caixa[indicie_cai].date.dia = tm.tm_mday;
        caixa[indicie_cai].date.mes = tm.tm_mon + 1;
        caixa[indicie_cai].date.ano = tm.tm_year + 1900;


        //deletando a conta pendente
        for (int i = cod_conta; i < qtd_con_pag; i++) {
            conta_pag[i] = conta_pag[i + 1];
        }

        menu_conta_pagar_mem();
    }

}

//listando todas contas a receber
void listar_conta_pagar_mem() {
    if (qtd_con_pag == 0) {
        printf("Não tem nenhuma conta a pagar.\n");
        menu_conta_pagar_mem();
    }
    printf("\n--------LISTA DE CONTAS A RECEBER--------\n");
    mostra_contas_a_pagar_txt(qtd_con_pag, conta);
    menu_conta_pagar();
}
//FIM DO MODULO DE TRANSACOES



//INICIO FEEEDBACK
//funcao para listar hospedes

//funcao para filtra e printar ou salvar a listagem de hospedes
int funcao_listagem_hospede_mem(int *codigo, int *listagem,char *sexo,int opcao) {
    int contador=0;
    
    
    
    hospedes *hospedesAUX;
    hospedes *hospedesRAM = malloc(qtd_hos * sizeof(hospedes));
    for(int i=0;i<qtd_hos;i++){
        hospedesRAM[i]=hospede[i];
    }
    
    
    if(listagem[0]!=0){
        hospedesAUX = malloc(qtd_hos * sizeof(hospedes));
        for(int i=0;i<qtd_hos;i++){
            if(codigo[0] <= hospedesRAM[i].codigo && hospedesRAM[i].codigo <= codigo[1]){
                hospedesAUX[contador]=hospedesRAM[i];           
                contador++;
            }
        }
        if(contador==0){
            printf("\nNenhum hóspede com esse intervalo de codigo.\n");
            return 0;
        }
        //realocando o hospedes ram para ficar do tamanho da quantidadede de hospedes filtrador
        hospedesRAM = realloc(hospedesRAM, contador * sizeof (hospedes));
        
        //copiando os dados do aux para ram para que caso utilizar ma proxima filtragem ou nao
        memcpy(hospedesRAM,hospedesAUX , contador * sizeof (hospedes));

        //igualando qtd de hospedes ao contador para ficar com a nova qtd de hospedes
        qtd_hos=contador;
        free(hospedesAUX);
    }
    
    
    if(listagem[1]!=0){
        hospedesAUX= malloc(qtd_hos * sizeof(hospedes));
        contador=0;
        for(int i=0;i<qtd_hos;i++){
            if (strcmp(sexo, hospedesRAM[i].sexo) == 0) {
                hospedesAUX[contador]=hospedesRAM[i];
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
        hospedesRAM = realloc(hospedesRAM, contador * sizeof(hospedes));
        
        //copiando os dados do aux para ram para que caso utilizar ma proxima filtragem ou nao
        memcpy(hospedesRAM, hospedesAUX, contador * sizeof(hospedes));
        
        //igualando qtd de hospedes ao contador para ficar com a nova qtd de hospedes
        qtd_hos=contador;
        free(hospedesAUX);
    }
    
    if(opcao==1){
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
    }else if(opcao==2){
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("listagem_hospedes.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for(int i=0;i<qtd_hos;i++){
            fprintf(P, "%d;%s;%s;%s;%s;%s;%s;%d;%s;%s;%s;%s;%s;%d;%d;%d;\n",
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
    
    free(hospedesRAM);
    return 0;
}

//parte visual da listagm 
void listagem_hospede_mem() {
    int listagem[2];
    int codigo[2];
    int sexo[20];
    int opcao;

    printf("\n-----------LISTAGEM DE HÓSPEDES-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Faixa de código.(1-Sim/0-Não):");
    scanf("%d", &listagem[0]);
    if (listagem[0] == 1) {
        printf("Digite dois codigos.(do 1 ao 10, por exemplo).\n");
        printf("Código 1:");
        scanf("%d", &codigo[0]);
        printf("Código 2:");
        scanf("%d", &codigo[1]);
        while (codigo[0] > codigo[1]) {
            printf("O código 1 tem que ser menor que o código 2.\n");
            printf("Código 1:");
            scanf("%d", &codigo[0]);
            printf("Código 2:");
            scanf("%d", &codigo[1]);
        }
    }
    printf("Deseja filtrar por sexo.(1-Sim/0-Não):");
    scanf("%d", &listagem[1]);
    if (listagem[1] == 1) {
        printf("Digite o sexo que deseja filtrar:");
        scanf(" %[^\n]s%*c", sexo);
        setbuf(stdin, NULL);
    }

    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }
    funcao_listagem_hospede_mem(codigo, listagem, sexo, opcao);
    menu_modulo_feedback_mem();
}


//funcao para filtra e printar ou salvar a listagem de acomodacoes
int funcao_listagem_acomodacoes_mem(int *codigo, int *listagem,int categoria,int opcao,data_chek_in_out datas){
    
    acomodacoes *acomodacoesAUX;
    acomodacoes *acomodacoesRAM = malloc(qtd_acomd * sizeof(acomodacoes));
    
    for(int i=0;i<qtd_acomd;i++){
        acomodacoesRAM[i]=acomodacao[i];
    }
    
    if (listagem[0] != 0) {
        acomodacoesAUX = malloc(qtd_acomd * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_acomd; i++) {
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
        qtd_acomd = contador;
        free(acomodacoesAUX);
    }

    if (listagem[1] != 0) {
        acomodacoesAUX = malloc(qtd_acomd * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_acomd; i++) {
            if (acomodacoesRAM[i].categoria == categoria) {
                acomodacoesAUX[contador] = acomodacoesRAM[i];
                contador++;
            }
        }
        if (contador == 0 && listagem[0]!=0) {
            printf("\nNenhuma acomodação encontrada para essa categoria e intervalo de codigo.\n");
            return;
        }else if(contador==0){
            printf("\nNenhuma acomodação encontrada para essa categoria.\n");
        }
        
        // Realocando o acomodacoesRAM para ficar do tamanho da quantidade de acomodações filtradas
        acomodacoesRAM = realloc(acomodacoesRAM, contador * sizeof (acomodacoes));
        
        // Copiando os dados do AUX para RAM
        memcpy(acomodacoesRAM, acomodacoesAUX, contador * sizeof (acomodacoes));
        
        // Igualando a quantidade de acomodações ao contador
        qtd_acomd = contador;
        free(acomodacoesAUX);
    }
    if(listagem[2]!=0){
        int contador=0,qtd_res,existe;
        existe = arquivo_existe_txt("reservas.txt");
        
        
        if(existe==1){
            qtd_res = contadorlinhas_txt("reservas.txt");
            qtd_res = qtd_res / 16;
            reservas reservaRAM[qtd_res];
            reservas_ram_txt(qtd_res, reservaRAM);
            
            int acomodacaoINDIS[qtd_res],contador_indis=0;
            acomodacoesAUX = malloc((qtd_acomd+qtd_res) * sizeof (acomodacoes));
       
            if(qtd_res>0){
                for (int i = 0; i < qtd_acomd; i++) {
                    if (acomodacoesRAM[i].ocupacao == 0) {
                        acomodacoesAUX[contador]=acomodacoesRAM[i];
                        contador++;
                    }else{
                        for(int j=0;j<qtd_res;j++){
                            if ((datas.ano_in <= reservaRAM[i].datas.ano_out || datas.ano_out >= reservaRAM[i].datas.ano_in) &&
                                    (datas.mes_in <= reservaRAM[i].datas.mes_out || datas.mes_out >= reservaRAM[i].datas.mes_in) &&
                                    (datas.dia_in <= reservaRAM[i].datas.dia_out || datas.dia_out >= reservaRAM[i].datas.dia_in)) {
                                acomodacaoINDIS[contador_indis] = reservaRAM[i].codigo_aco;
                                contador_indis++;
                            }
                        }                            
                    }
                }
                for (int i = 0; i < qtd_acomd; i++) {
                    int acomodacaoDisponivel = 1; // Assume que a acomodação está disponível

                    // Verifica se a acomodação está na lista de indisponíveis
                    for (int j = 0; j < contador_indis; j++) {
                        if (acomodacoesRAM[i].codigo == acomodacaoINDIS[j]) {
                            acomodacaoDisponivel = 0; // A acomodação está indisponível
                            break;
                        }
                    }

                    // Adiciona a acomodação à lista de disponíveis
                    if (acomodacaoDisponivel==1 && acomodacoesRAM[i].ocupacao != 0) {
                        acomodacoesAUX[contador] = acomodacoesRAM[i];
                        contador++;
                    }
                }
            }
            if(contador==0){
                printf("\nNenhuma acomodação encontrada com esses filtros.\n");
                return 0;
            }
            // Realocando o acomodacoesRAM para ficar do tamanho da quantidade de acomodações filtradas
            acomodacoesRAM = realloc(acomodacoesRAM, contador * sizeof (acomodacoes));

            // Copiando os dados do AUX para RAM
            memcpy(acomodacoesRAM, acomodacoesAUX, contador * sizeof (acomodacoes));

            // Igualando a quantidade de acomodações ao contador
            qtd_acomd = contador;
            free(acomodacoesAUX);
        }
        
    }
    
    if(opcao==1){
        for (int i = 0; i < qtd_acomd; i++) {
            printf("\n------------------------------\n");
            printf("Código: %d\n", acomodacoesRAM[i].codigo);
            printf("Descrição: %s\n", acomodacoesRAM[i].descricao);
            printf("Facilidades: %s\n", acomodacoesRAM[i].facilidades);
            printf("Categoria: %d\n", acomodacoesRAM[i].categoria);
            printf("Diárias: %d\n", acomodacoesRAM[i].diarias);
            printf("Lucro: %.2f\n", acomodacoesRAM[i].lucro);
            printf("Ocupação: %d\n", acomodacoesRAM[i].ocupacao);
            printf("\n");
        }
    }else if(opcao==2) {
        FILE *P; //Ponteiro do arquivo TXT;

        P = fopen("listagem_acomodacoes.txt", "w");

        if (P == NULL) {
            printf("Problemas na abertura do arquivo.");
            exit(1);
        }
        for(int i=0;i<qtd_acomd;i++){
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
        
    }
    free(acomodacoesRAM);
    return 0;
}

//funcao para listar acomodacoes
void listagem_acomodacoes_mem() {
    int listagem[3];
    int codigo[2];
    int categoria;
    int opcao, ret_data;
    data_chek_in_out dates;

    printf("\n-----------LISTAGEM DE ACOMODACOES-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Faixa de código.(1-Sim/0-Não):");
    scanf("%d", &listagem[0]);
    if (listagem[0] == 1) {
        printf("Digite dois codigos.(do 1 ao 10, por exemplo).\n");
        printf("Código 1:");
        scanf("%d", &codigo[0]);
        printf("Código 2:");
        scanf("%d", &codigo[1]);
        while (codigo[0] > codigo[1]) {
            printf("O código 1 tem que ser menor que o código 2.\n");
            printf("Código 1:");
            scanf("%d", &codigo[0]);
            printf("Código 2:");
            scanf("%d", &codigo[1]);
        }
    }
    printf("Deseja filtrar por categoria.(1-Sim/0-Não):");
    scanf("%d", &listagem[1]);
    if (listagem[1] == 1) {
        printf("Digite a categoria filtrar:");
        scanf("%d", &categoria);
    }

    printf("Deseja filtrar por data dísponivel.(1-Sim/0-Não):");
    scanf("%d", &listagem[2]);
    if (listagem[2] == 1) {
        printf("Digite o intervalo de data que deseja, data 1 tem que ser menor que a data 2.\n");
        printf("Data 1:\n");
        printf("Dia:");
        scanf("%d", &dates.dia_in);
        printf("Mes:");
        scanf("%d", &dates.mes_in);
        printf("Ano:");
        scanf("%d", &dates.ano_in);
        printf("Data 2:\n");
        printf("Dia:");
        scanf("%d", &dates.dia_out);
        printf("Mes:");
        scanf("%d", &dates.mes_out);
        printf("Ano:");
        scanf("%d", &dates.ano_out);
        ret_data = data_atual(dates);
        while (ret_data == 1) {
            printf("Essa data não é válida,a data 1 tem que ser menor que a data 2, digite um data valida.\n");
            printf("Data 1:\n");
            printf("Dia:");
            scanf("%d", &dates.dia_in);
            printf("Mes:");
            scanf("%d", &dates.mes_in);
            printf("Ano:");
            scanf("%d", &dates.ano_in);
            printf("Data 2:\n");
            printf("Dia:");
            scanf("%d", &dates.dia_out);
            printf("Mes:");
            scanf("%d", &dates.mes_out);
            printf("Ano:");
            scanf("%d", &dates.ano_out);
            ret_data = data_atual(dates);
        }
    }


    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }
    funcao_listagem_acomodacoes_mem(codigo, listagem, categoria, opcao, dates);
    menu_modulo_feedback_mem();
}


//funcao para filtra e printar ou salvar a listagem de reservas
int funcao_listagem_reservas_mem(int *listagem, int *codigo_hospede, int *codigo_acomodacao, data_chek_in_out datas, int opcao) {
    
    reservas *reservasRAM = malloc(qtd_res * sizeof (reservas));

    for (int i = 0; i < qtd_res; i++) {
        reservasRAM[i] = reserva[i];
    }
    
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
            return 1;
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
            return 1;
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
    free(reservasRAM);
    return 0;
}

//funcao para listar reservas
void listagem_reservas_mem() {
    int listagem[3];
    int codigo_hospede[2], codigo_acomodacao[2];
    int diarias;
    int opcao;
    int ret_data;
    float lucro;
    data_chek_in_out datas;

    printf("\n-----------LISTAGEM DE RESERVAS-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Faixa de código de hóspede.(1-Sim/0-Não):");
    scanf("%d", &listagem[0]);
    if (listagem[0] == 1) {
        printf("Digite dois codigos.(do 1 ao 10, por exemplo).\n");
        printf("Código 1:");
        scanf("%d", &codigo_hospede[0]);
        printf("Código 2:");
        scanf("%d", &codigo_hospede[1]);
        while (codigo_hospede[0] > codigo_hospede[1]) {
            printf("O código 1 tem que ser menor que o código 2.\n");
            printf("Código 1:");
            scanf("%d", &codigo_hospede[0]);
            printf("Código 2:");
            scanf("%d", &codigo_hospede[1]);
        }
    }
    printf("Faixa de código de acomodacao.(1-Sim/0-Não):");
    scanf("%d", &listagem[1]);
    if (listagem[1] == 1) {
        printf("Digite dois codigos.(do 1 ao 10, por exemplo).\n");
        printf("Código 1:");
        scanf("%d", &codigo_acomodacao[0]);
        printf("Código 2:");
        scanf("%d", &codigo_acomodacao[1]);
        while (codigo_acomodacao[0] > codigo_acomodacao[1]) {
            printf("O código 1 tem que ser menor que o código 2.\n");
            printf("Código 1:");
            scanf("%d", &codigo_acomodacao[0]);
            printf("Código 2:");
            scanf("%d", &codigo_acomodacao[1]);
        }
    }


    printf("Deseja filtrar por data reservadas.(1-Sim/0-Não):");
    scanf("%d", &listagem[2]);
    if (listagem[2] == 1) {
        printf("Digite o intervalo de data que deseja, data 1 tem que ser menor que a data 2.\n");
        printf("Data 1:\n");
        printf("Dia:");
        scanf("%d", &datas.dia_in);
        printf("Mes:");
        scanf("%d", &datas.mes_in);
        printf("Ano:");
        scanf("%d", &datas.ano_in);
        printf("Data 2:\n");
        printf("Dia:");
        scanf("%d", &datas.dia_out);
        printf("Mes:");
        scanf("%d", &datas.mes_out);
        printf("Ano:");
        scanf("%d", &datas.ano_out);
        ret_data = data_atual(datas);
        while (ret_data == 1) {
            printf("Essa data não é válida,a data 1 tem que ser menor que a data 2, digite um data valida.\n");
            printf("Data 1:\n");
            printf("Dia:");
            scanf("%d", &datas.dia_in);
            printf("Mes:");
            scanf("%d", &datas.mes_in);
            printf("Ano:");
            scanf("%d", &datas.ano_in);
            printf("Data 2:\n");
            printf("Dia:");
            scanf("%d", &datas.dia_out);
            printf("Mes:");
            scanf("%d", &datas.mes_out);
            printf("Ano:");
            scanf("%d", &datas.ano_out);
            ret_data = data_atual(datas);
        }
    }



    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }
    funcao_listagem_reservas_mem(listagem, codigo_hospede, codigo_acomodacao, datas, opcao);
    menu_modulo_feedback_mem();
}



//funcao para filtra e printar ou salvar a listagem de acomodacoes
int funcao_listagem_movimento_acomodacoes_mem(int *listagem, int *codigo, int diarias, float lucro, int opcao) {
    
    acomodacoes *movimentacaoRAM = malloc(qtd_acomd * sizeof (acomodacoes));

    for (int i = 0; i < qtd_acomd; i++) {
        movimentacaoRAM[i] = acomodacao[i];
    }

    acomodacoes *movimentacaoAUX;

    if (listagem[0] != 0) {
        movimentacaoAUX = malloc(qtd_acomd * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_acomd; i++) {
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
        qtd_acomd = contador;
        free(movimentacaoAUX);
    }

    if (listagem[1] != 0) {
        movimentacaoAUX = malloc(qtd_acomd * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_acomd; i++) {
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
        qtd_acomd = contador;
        free(movimentacaoAUX);
    }
    if (listagem[2] != 0) {
        movimentacaoAUX = malloc(qtd_acomd * sizeof (acomodacoes));
        int contador = 0;
        for (int i = 0; i < qtd_acomd; i++) {
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
        qtd_acomd = contador;
        free(movimentacaoAUX);
    }

    if (opcao == 1) {
        for (int i = 0; i < qtd_acomd; i++) {
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
        for (int i = 0; i < qtd_acomd; i++) {
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
    free(movimentacaoRAM);
    return 0;
}

//funcao para listar acomodacoes 
void listagem_movimento_acomodacoes_mem() {
    int listagem[3];
    int codigo[2];
    int diarias;
    int opcao;
    float lucro;

    printf("\n-----------LISTAGEM DE MOVIMENTAÇÃO DE ACOMODACÕES-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Faixa de código.(1-Sim/0-Não):");
    scanf("%d", &listagem[0]);
    if (listagem[0] == 1) {
        printf("Digite dois codigos.(do 1 ao 10, por exemplo).\n");
        printf("Código 1:");
        scanf("%d", &codigo[0]);
        printf("Código 2:");
        scanf("%d", &codigo[1]);
        while (codigo[0] > codigo[1]) {
            printf("O código 1 tem que ser menor que o código 2.\n");
            printf("Código 1:");
            scanf("%d", &codigo[0]);
            printf("Código 2:");
            scanf("%d", &codigo[1]);
        }
    }
    printf("Deseja filtrar por quantidade de diárias ocupadas.(1-Sim/0-Não):");
    scanf("%d", &listagem[1]);
    if (listagem[1] == 1) {
        printf("Digite a partir de quantas diárias deseja listar:");
        scanf("%d", &diarias);
    }


    printf("Deseja filtrar pelo rendimento da acomodacão.(1-Sim/0-Não):");
    scanf("%d", &listagem[2]);
    if (listagem[2] == 1) {
        printf("Digite a partir de quantos reais de rendimento deseja listar:");
        scanf("%d", &lucro);
    }



    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }
    funcao_listagem_movimento_acomodacoes_mem(listagem, codigo, diarias, lucro, opcao);
    menu_modulo_feedback_mem();
}



//funcao para filtra e printar ou salvar a listagem de produtos
int funcao_listagem_produtos_mem(int *codigo, int listagem, int opcao) {
    int contador = 0;
    
    produtos *produtosRAM = malloc(qtd_pro * sizeof (produtos));

    for (int i = 0; i < qtd_pro; i++) {
        produtosRAM[i] = produto[i];
    }

    produtos *produtosAUX;

    if (listagem != 0) {
        produtosAUX = malloc(qtd_pro * sizeof (produtos));
        for (int i = 0; i < qtd_pro; i++) {
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
        qtd_pro = contador;
        free(produtosAUX);
    }

    if (opcao == 1) {
        for (int i = 0; i < qtd_pro; i++) {
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

        for (int i = 0; i < qtd_pro; i++) {
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

//funcao para listar produtos
void listagem_produtos_mem() {
    int listagem;
    int codigo[2];
    int opcao;

    printf("\n-----------LISTAGEM DE PRODUTOS-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Faixa de código.(1-Sim/0-Não):");
    scanf("%d", &listagem);
    if (listagem == 1) {
        printf("Digite dois códigos. (por exemplo, do 1 ao 10).\n");
        printf("Código 1:");
        scanf("%d", &codigo[0]);
        printf("Código 2:");
        scanf("%d", &codigo[1]);
        while (codigo[0] > codigo[1]) {
            printf("O código 1 deve ser menor que o código 2.\n");
            printf("Código 1:");
            scanf("%d", &codigo[0]);
            printf("Código 2:");
            scanf("%d", &codigo[1]);
        }
    }

    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }
    funcao_listagem_produtos_mem(codigo, listagem, opcao);
    menu_modulo_feedback_mem();
}



//funcao para filtra e printar ou salvar a listagem de produtos em estoque minimo
int funcao_listagem_estoque_minimo_mem(int *codigo, int listagem, int opcao) {
    int contador = 0;
    
    produtos *produtosRAM = malloc(qtd_pro * sizeof (produtos));

    for (int i = 0; i < qtd_pro; i++) {
        produtosRAM[i] = produto[i];
    }

    produtos *produtosAUX;

    if (listagem != 0) {
        produtosAUX = malloc(qtd_pro * sizeof (produtos));

        for (int i = 0; i < qtd_pro; i++) {
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
        qtd_pro = contador;
        free(produtosAUX);
    }
    contador = 0;
    if (opcao == 1) {
        for (int i = 0; i < qtd_pro; i++) {
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
        for (int i = 0; i < qtd_pro; i++) {
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
        for (int i = 0; i < qtd_pro; i++) {
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
    }
    free(produtosRAM);
    return 0;
}


//funcao para listar estoque minimo
void listagem_estoque_minimo_mem() {
    int listagem;
    int codigo[2];
    int opcao;

    printf("\n-----------LISTAGEM DE PRODUTOS EM ESTOQUE MÍNIMO-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Faixa de código. (1-Sim/0-Não): ");
    scanf("%d", &listagem);

    if (listagem == 1) {
        printf("Digite dois códigos. (por exemplo, do 1 ao 10).\n");
        printf("Código 1: ");
        scanf("%d", &codigo[0]);
        printf("Código 2: ");
        scanf("%d", &codigo[1]);

        while (codigo[0] > codigo[1]) {
            printf("O código 1 deve ser menor que o código 2.\n");
            printf("Código 1: ");
            scanf("%d", &codigo[0]);
            printf("Código 2: ");
            scanf("%d", &codigo[1]);
        }
    }

    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }

    funcao_listagem_estoque_minimo_mem(codigo, listagem, opcao);
    menu_modulo_feedback_mem();
}



//funcao para filtra e printar ou salvar a listagem de vendas
int funca_listagem_vendas_mem(int pagamento, int opcao, int listagem) {
    int contador = 0;
  
    vendas *vendasRAM = malloc(qtd_venda * sizeof (vendas));

    for (int i = 0; i < qtd_venda; i++) {
        vendasRAM[i] = venda[i];
    }

    vendas *vendasAUX;

    if (listagem == 1) {
        if (pagamento == 1) {
            vendasAUX = malloc(qtd_venda * sizeof (vendas));
            for (int i = 0; i < qtd_venda; i++) {
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
            qtd_venda = contador;
            free(vendasAUX);
        } else if (pagamento == 2) {

            vendasAUX = malloc(qtd_venda * sizeof (vendas));
            for (int i = 0; i < qtd_venda; i++) {
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
            qtd_venda = contador;
            free(vendasAUX);
        }
    }

    if (opcao == 1) {
        for (int i = 0; i < qtd_venda; i++) {
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

        for (int i = 0; i < qtd_venda; i++) {
            fprintf(P, "%d;%d;%d;%d;%f;\n",
                    vendasRAM[i].pagamento,
                    vendasRAM[i].cod_hos,
                    vendasRAM[i].cod_prod,
                    vendasRAM[i].qtd,
                    vendasRAM[i].valor);
        }

        fclose(P);
        printf("Listagem de vendas gerada com sucesso.\n");
        
    }
    free(vendasRAM);
    return 0;
}

//funcao para listar vendas
void listagem_vendas_mem() {
    int listagem;
    int pagamento;
    int opcao;

    printf("\n-----------LISTAGEM DE VENDAS-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Deseja filtrar por metodo de pagamento?(1-Sim/0-Não): ");
    scanf("%d", &listagem);
    if (listagem == 1) {
        printf("\n1-Deseja filtrar por pagamentos a vista.\n");
        printf("2-Deseja filtrar por pagamentos a prazo.\n");
        printf("Digite a opção desejada:");
        scanf("%d", &pagamento);
        if (pagamento != 1 && pagamento != 2) {
            printf("Digite um opção válida.\n");
            menu_modulo_feedback();
        }
    }

    printf("\n1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }
    
    funca_listagem_vendas_mem(pagamento, opcao, listagem);
    menu_modulo_feedback_mem();
}



//funcao para filtra e printar ou salvar a listagem de contas a receber
int funcao_listagem_contas_receber_mem(int *listagem, int *codigo, data inicio, data fim, int opcao) {
    int contador = 0;
    
    conta_receber *contasRAM = malloc(qtd_con_rec * sizeof (conta_receber));

    for (int i = 0; i < qtd_con_rec; i++) {
        contasRAM[i] = conta_rec[i];
    }

    conta_receber *contasAUX = NULL;

    // Aplicando o filtro por código
    if (listagem[0] == 1) {
        contasAUX = malloc(qtd_con_rec * sizeof (conta_receber));
        for (int i = 0; i < qtd_con_rec; i++) {
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
        qtd_con_rec = contador;
        free(contasAUX);
    }

    // Aplicando o filtro por data de recebimento
    if (listagem[1] == 1) {
        contasAUX = malloc(qtd_con_rec * sizeof (conta_receber));
        for (int i = 0; i < qtd_con_rec; i++) {
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
        qtd_con_rec = contador;
        free(contasAUX);
    }

    // Imprimindo ou salvando conforme a opção
    if (opcao == 1) {
        for (int i = 0; i < qtd_con_rec; i++) {
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

        for (int i = 0; i < qtd_con_rec; i++) {
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
    free(contasRAM);
    return 0;
}

//funcao para listar contas a receber
void listagem_contas_receber_mem() {
    int listagem[2];
    int codigo[2];
    int opcao;
    data inicio, fim;


    printf("\n-----------LISTAGEM DE CONTAS A RECEBER-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");

    printf("Faixa de código. (1-Sim/0-Não): ");
    scanf("%d", &listagem[0]);
    if (listagem[0] == 1) {
        printf("Digite dois códigos. (por exemplo, do 1 ao 10).\n");
        printf("Código 1: ");
        scanf("%d", &codigo[0]);
        printf("Código 2: ");
        scanf("%d", &codigo[1]);

        while (codigo[0] > codigo[1]) {
            printf("O código 1 deve ser menor que o código 2.\n");
            printf("Código 1: ");
            scanf("%d", &codigo[0]);
            printf("Código 2: ");
            scanf("%d", &codigo[1]);
        }
    }
    printf("Data de recebimento. (1-Sim/0-Não): ");
    scanf("%d", &listagem[1]);
    if (listagem[1] == 1) {
        // Adicionando os filtros de data
        printf("Digite a data de início:\n");
        printf("Dia:");
        scanf("%d", &inicio.dia);
        printf("Mês:");
        scanf("%d", &inicio.mes);
        printf("Ano:");
        scanf("%d", &inicio.ano);

        printf("Digite a data de fim:\n");
        printf("Dia:");
        scanf("%d", &fim.dia);
        printf("Mês:");
        scanf("%d", &fim.mes);
        printf("Ano:");
        scanf("%d", &fim.ano);
    }


    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }

    funcao_listagem_contas_receber_mem(listagem, codigo, inicio, fim, opcao);
    menu_modulo_feedback_mem();
}



//funcao para filtra e printar ou salvar a listagem de contas a pagar
int funcao_listagem_contas_pagar_mem(int *listagem, int *codigo, data inicio, data fim, int opcao) {
    int contador = 0;


    
    conta_receber *contasRAM = malloc(qtd_con_pag * sizeof (conta_receber));

    for (int i = 0; i < qtd_con_pag; i++) {
        contasRAM[i] = conta_pag[i];
    }

    conta_receber *contasAUX = NULL;

    // Aplicando o filtro por código
    if (listagem[0] == 1) {
        contasAUX = malloc(qtd_con_pag * sizeof (conta_receber));
        for (int i = 0; i < qtd_con_pag; i++) {
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
        qtd_con_pag = contador;
        free(contasAUX);
    }

    // Aplicando o filtro por data de recebimento
    if (listagem[1] == 1) {
        contasAUX = malloc(qtd_con_pag * sizeof (conta_receber));
        for (int i = 0; i < qtd_con_pag; i++) {
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
        qtd_con_pag = contador;
        free(contasAUX);
    }

    // Imprimindo ou salvando conforme a opção
    if (opcao == 1) {
        for (int i = 0; i < qtd_con_pag; i++) {
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

        for (int i = 0; i < qtd_con_pag; i++) {
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
    free(contasRAM);
    return 0;
}

//funcao para listar contas a pagar
void listagem_contas_pagar_mem() {
    int listagem[2];
    int codigo[2];
    int opcao;
    data inicio, fim;


    printf("\n-----------LISTAGEM DE CONTAS A PAGAR-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");

    printf("Faixa de código. (1-Sim/0-Não): ");
    scanf("%d", &listagem[0]);
    if (listagem[0] == 1) {
        printf("Digite dois códigos. (por exemplo, do 1 ao 10).\n");
        printf("Código 1: ");
        scanf("%d", &codigo[0]);
        printf("Código 2: ");
        scanf("%d", &codigo[1]);

        while (codigo[0] > codigo[1]) {
            printf("O código 1 deve ser menor que o código 2.\n");
            printf("Código 1: ");
            scanf("%d", &codigo[0]);
            printf("Código 2: ");
            scanf("%d", &codigo[1]);
        }
    }
    printf("Data de recebimento. (1-Sim/0-Não): ");
    scanf("%d", &listagem[1]);
    if (listagem[1] == 1) {
        // Adicionando os filtros de data
        printf("Digite a data de início:\n");
        printf("Dia:");
        scanf("%d", &inicio.dia);
        printf("Mês:");
        scanf("%d", &inicio.mes);
        printf("Ano:");
        scanf("%d", &inicio.ano);

        printf("Digite a data de fim:\n");
        printf("Dia:");
        scanf("%d", &fim.dia);
        printf("Mês:");
        scanf("%d", &fim.mes);
        printf("Ano:");
        scanf("%d", &fim.ano);
    }


    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }

    funcao_listagem_contas_pagar_mem(listagem, codigo, inicio, fim, opcao);
    menu_modulo_feedback_mem();
}



//funcao para filtra e printar ou salvar a listagem de caixa
void funcao_listagem_caixa_mem(data inicio, data fim, int listagem, int opcao) {
    int contador = 0;

    conta_receber *caixaRAM = malloc(qtd_cai * sizeof (conta_receber));

    for (int i = 0; i < qtd_cai; i++) {
        caixaRAM[i] = caixa[i];
    }

    conta_receber *caixaAUX = NULL;

    if (listagem == 1) {
        caixaAUX = malloc(qtd_cai * sizeof (conta_receber));
        for (int i = 0; i < qtd_cai; i++) {
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
        qtd_cai = contador;
        free(caixaAUX);
    }

    if (opcao == 1) {
        // Imprimindo as informações
        for (int i = 0; i < qtd_cai; i++) {
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

        for (int i = 0; i < qtd_cai; i++) {
            fprintf(P, "%f;%02d;%02d;%04d;\n",
                    caixaRAM[i].valor_devido,
                    caixaRAM[i].date.dia,
                    caixaRAM[i].date.mes,
                    caixaRAM[i].date.ano);
        }

        fclose(P);
        printf("Listagem de caixa gerada com sucesso.\n");
    }
    free(caixaRAM);
    return 0;
}

//funcao para listar caixa
void listagem_caixa_mem() {
    int listagem;
    data inicio, fim;
    int opcao;

    printf("\n-----------LISTAGEM DE CAIXA-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");

    // Filtro por intervalo de datas
    printf("Data de recebimento. (1-Sim/0-Não): ");
    scanf("%d", &listagem);
    if (listagem == 1) {
        printf("Digite a data de início:\n");
        printf("Dia:");
        scanf("%d", &inicio.dia);
        printf("Mês:");
        scanf("%d", &inicio.mes);
        printf("Ano:");
        scanf("%d", &inicio.ano);

        printf("Digite a data de fim:\n");
        printf("Dia:");
        scanf("%d", &fim.dia);
        printf("Mês:");
        scanf("%d", &fim.mes);
        printf("Ano:");
        scanf("%d", &fim.ano);
    }

    // Escolha da opção de listagem
    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback_mem();
    }

    // Chamada da função para listagem de caixa
    funcao_listagem_caixa_mem(inicio, fim, listagem, opcao);
    menu_modulo_feedback_mem();
}
//FIM FEEDBACK


//COMEÇO IMPORTAÇÃO E EXPORTAÇÃO


//funcao para importar dados do hotel de um xml
int importar_hotel_mem_xml(char *arquivo) {
    char *buffer = trazer_xml_buffer(arquivo);

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
    extrairValor(buffer, "<nome_fantasia>", "</nome_fantasia>", hotel.nome_fantasia);
    extrairValor(buffer, "<razao_social>", "</razao_social>", hotel.razao_social);
    extrairValor(buffer, "<inscricao_estadual>", "</inscricao_estadual>", hotel.inscricao_estadual);
    extrairValor(buffer, "<cnpj>", "</cnpj>", hotel.cnpj);


    extrairValor(buffer, "<endereco>", "</endereco>", auxEndereco);
    sscanf(auxEndereco, "%[^;];%[^;];%[^;];%[^;];%[^;];%d", hotel.endereco.estado,
            hotel.endereco.cidade, hotel.endereco.bairro,
            hotel.endereco.cep, hotel.endereco.rua,
            &hotel.endereco.numero);

    extrairValor(buffer, "<telefone>", "</telefone>", hotel.telefone);
    extrairValor(buffer, "<email>", "</email>", hotel.email);
    extrairValor(buffer, "<nome_responsavel>", "</nome_responsavel>", hotel.nome_responsavel);
    extrairValor(buffer, "<telefone_responsavel>", "</telefone_responsavel>", hotel.telefone_responsavel);


    // Extrai os valores de checkin e checkout
    extrairValor(buffer, "<checkin>", "</checkin>", auxCheckin);
    sscanf(auxCheckin, "%d:%d", &hotel.horario_checkin.hora, &hotel.horario_checkin.minutos);
    extrairValor(buffer, "<checkout>", "</checkout>", auxCheckout);
    sscanf(auxCheckin, "%d:%d", &hotel.horario_checkout.hora, &hotel.horario_checkout.minutos);


    extrairValor(buffer, "<mlpv>", "</mlpv>", auxMLPV);
    hotel.mlpv = atof(&auxMLPV);


    /*
        // Imprime os dados do hotel
        printf("Nome Fantasia: %s\n", hotel.nome_fantasia);
        printf("Razão Social: %s\n", hotel.razao_social);
        printf("Inscrição Estadual: %s\n", hotel.inscricao_estadual);
        printf("CNPJ: %s\n", hotel.cnpj);
        printf("Endereço: %s, %s, %s, %s, %s, %d\n", hotel.endereco.estado,hotel.endereco.cidade, hotel.endereco.bairro,
               hotel.endereco.cep, hotel.endereco.rua, hotel.endereco.numero);
        printf("Telefone: %s\n", hotel.telefone);
        printf("Email: %s\n", hotel.email);
        printf("Nome Responsável: %s\n", hotel.nome_responsavel);
        printf("Telefone Responsável: %s\n", hotel.telefone_responsavel);
        printf("Checkin: %d:%d\n", hotel.horario_checkin.hora,hotel.horario_checkin.minutos);
        printf("Checkout: %d:%d\n", hotel.horario_checkout.hora,hotel.horario_checkout.minutos);
        printf("MLPV: %f\n", hotel.mlpv);
     */
    // Libera a memória alocada
    free(conteudo_hotel);



    return 0;
}

//funcao para importar dados dos hospedes
int importar_dados_hospedes_mem_xml(char *arquivo) {
    char *buffer = trazer_xml_buffer(arquivo);


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
        free(hospede);
        
        qtd_hos=0;
        
        for (int i = 0; i < contador_registros; i++) {
            qtd_hos++;
            hospede = (hospedes *) realloc(hospede, qtd_hos * sizeof (hospedes));
            hospede[i]=dados_hospedes[i];
        }
    } else {
        printf("Tags da tabela 'hospedes' não encontradas ou conteúdo vazio.\n");
    }
}

//funcao para importar dados das acomodacoes
int importar_dados_acomodacoes_mem_xml(char *arquivo) {
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
        char auxCod[10], auxCategoria[10], auxOcupacao[10], auxLucro[10],auxDiarias[10];

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
        free(acomodacao);
        qtd_acomd=0;
        for (int i = 0; i < contador_registros; i++) {
            qtd_acomd++;
            acomodacao = (acomodacoes *) realloc(acomodacao, qtd_acomd * sizeof (acomodacoes));
            acomodacao[i]=dados_acomodacoes[i];
        }

    } else {
        printf("Tags da tabela 'acomodacoes' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}


//funcao para importar dados das categorias de acomodacoes
int importar_dados_categoria_acomodacao_mem_xml(char *arquivo) {
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

        free(categoria);
        qtd_cat = 0;
        for (int i = 0; i < contador_registros; i++) {
            qtd_cat++;
            categoria = (categoria_acomodacao *) realloc(categoria, qtd_cat * sizeof (categoria_acomodacao));
            categoria[i] = dados_categorias[i];
        }


    } else {
        printf("Tags da tabela 'categoria_acomodacao' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados de produtos
int importar_dados_produtos_mem_xml(char *arquivo) {
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
        free(produto);
        qtd_pro = 0;
        for (int i = 0; i < contador_registros; i++) {
            qtd_pro++;
            produto = (produtos *) realloc(produto, qtd_pro * sizeof (produtos));   
            produto[i] = dados_produtos[i];
        }

    } else {
        printf("Tags da tabela 'produtos' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados dos fornecedores
int importar_dados_fornecedores_mem_xml(char *arquivo) {
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

        free(fornecedor);
        qtd_forn = 0;
        for (int i = 0; i < contador_registros; i++) {
            qtd_forn++;
            fornecedor = (fornecedores *) realloc(fornecedor, qtd_forn * sizeof (fornecedores));
            fornecedor[i] = dados_fornecedores[i];
        }
    } else {
        printf("Tags da tabela 'fornecedores' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}

//funcao para importar dados dos operadores
int importar_dados_operadores_mem_xml(char *arquivo) {
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
        
        free(operador);
        qtd_ope = 0;
        for (int i = 0; i < contador_registros; i++) {
            qtd_ope++;
            operador = (OPsistema *) realloc(operador, qtd_ope * sizeof (OPsistema));
            operador[i] = dados_operadores[i];
        }
    } else {
        printf("Tags da tabela 'operadores' não encontradas ou conteúdo vazio.\n");
    }

    return 0;
}


//funcao para importar dados
void importar_dados_mem() {
    int importar;
    char arquivo[30];
    printf("\n------IMPORTAR DADOS-------\n");
    printf("Primeiramente digite o nome do arquivo que deseja importar(EX:arquivo.xml):");
    scanf(" %[^\n]s%*c", arquivo);
    printf("Quais dados deseja importar?\n");
    printf("Dados do Hotel.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_hotel_mem_xml(arquivo);
    }
    printf("Dados dos Hospedes.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_hospedes_mem_xml(arquivo);
    }
    printf("Dados das acomodações.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_acomodacoes_mem_xml(arquivo);
    }
    printf("Dados das categorias de acomodação.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_categoria_acomodacao_mem_xml(arquivo);
    }
    printf("Dados dos produtos.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_produtos_mem_xml(arquivo);
    }
    printf("Dados dos fornecedores.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_fornecedores_mem_xml(arquivo);
    }
    printf("Dados dos operadores.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_operadores_mem_xml(arquivo);
    }

    menu_modulo_im_exportacao_mem();
}



//exportar dados em xml
int exportar_dados_xml_mem(int *exportar) {

    FILE *arquivoXML; //Ponteiro do arquivo TXT;
    arquivoXML = fopen("exportar.xml", "w");


    fprintf(arquivoXML, "<dados>\n");


    if (exportar[0] != 0) {
        fprintf(arquivoXML, "    <tabela=hotel>\n");
        fprintf(arquivoXML, "        <registro>\n");
        fprintf(arquivoXML, "            <nome_fantasia>%s</nome_fantasia>\n", hotel.nome_fantasia);
        fprintf(arquivoXML, "            <razao_social>%s</razao_social>\n", hotel.razao_social);
        fprintf(arquivoXML, "            <inscricao_estadual>%s</inscricao_estadual>\n", hotel.inscricao_estadual);
        fprintf(arquivoXML, "            <cnpj>%s</cnpj>\n", hotel.cnpj);
        fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", hotel.endereco.estado, hotel.endereco.cidade, hotel.endereco.bairro, hotel.endereco.cep, hotel.endereco.rua, hotel.endereco.numero);
        fprintf(arquivoXML, "            <telefone>%s</telefone>\n", hotel.telefone);
        fprintf(arquivoXML, "            <email>%s</email>\n", hotel.email);
        fprintf(arquivoXML, "            <nome_responsavel>%s</nome_responsavel>\n", hotel.nome_responsavel);
        fprintf(arquivoXML, "            <telefone_responsavel>%s</telefone_responsavel>\n", hotel.telefone_responsavel);
        fprintf(arquivoXML, "            <checkin>%d:%d</checkin>\n", hotel.horario_checkin.hora, hotel.horario_checkin.minutos);
        fprintf(arquivoXML, "            <checkout>%d:%d</checkout>\n", hotel.horario_checkout.hora, hotel.horario_checkout.minutos);
        fprintf(arquivoXML, "            <mlpv>%f</mlpv>\n", hotel.mlpv);
        fprintf(arquivoXML, "        </registro>\n");
        fprintf(arquivoXML, "    </tabela=hotel>\n");
    }

    if (exportar[1] != 0) {

        fprintf(arquivoXML, "    <tabela=hospedes>\n");
        for (int i = 0; i < qtd_hos; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", hospede[i].codigo);
            fprintf(arquivoXML, "            <nome>%s</nome>\n", hospede[i].nome);
            fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", hospede[i].endereco_hospede.estado, hospede[i].endereco_hospede.cidade, hospede[i].endereco_hospede.bairro, hospede[i].endereco_hospede.cep, hospede[i].endereco_hospede.rua, hospede[i].endereco_hospede.numero);
            fprintf(arquivoXML, "            <cpf>%s</cpf>\n", hospede[i].cpf);
            fprintf(arquivoXML, "            <telefone>%s</telefone>\n", hospede[i].telefone);
            fprintf(arquivoXML, "            <email>%s</email>\n", hospede[i].email);
            fprintf(arquivoXML, "            <sexo>%s</sexo>\n", hospede[i].sexo);
            fprintf(arquivoXML, "            <est_civil>%s</est_civil>\n", hospede[i].estado_civil);
            fprintf(arquivoXML, "            <data_nascimento>%d/%d/%d</data_nascimento>\n", hospede[i].data_nacimento.dia, hospede[i].data_nacimento.mes, hospede[i].data_nacimento.ano);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=hospedes>\n");
    }
    if (exportar[2] != 0) {
        
        fprintf(arquivoXML, "    <tabela=acomodacoes>\n");
        for (int i = 0; i < qtd_acomd; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", acomodacao[i].codigo);
            fprintf(arquivoXML, "            <descricao>%s</descricao>\n", acomodacao[i].descricao);
            fprintf(arquivoXML, "            <facilidades>%s</facilidades>\n", acomodacao[i].facilidades);
            fprintf(arquivoXML, "            <categoria>%d</categoria>\n", acomodacao[i].categoria);
            fprintf(arquivoXML, "            <diarias>%d</diarias>\n", acomodacao[i].diarias);
            fprintf(arquivoXML, "            <lucro>%f</lucro>\n", acomodacao[i].lucro);
            fprintf(arquivoXML, "            <ocupacao>%d</ocupacao>\n", acomodacao[i].ocupacao);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=acomodacoes>\n");
    }

    if (exportar[3] != 0) {
        
        fprintf(arquivoXML, "    <tabela=categoria_acomodacao>\n");
        for (int i = 0; i < qtd_cat; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", categoria[i].codigo);
            fprintf(arquivoXML, "            <descricao>%s</descricao>\n", categoria[i].descricao);
            fprintf(arquivoXML, "            <valor_diaria>%f</valor_diaria>\n", categoria[i].valor_diaria);
            fprintf(arquivoXML, "            <adultos>%d</adultos>\n", categoria[i].adultos);
            fprintf(arquivoXML, "            <criancas>%d</criancas>\n", categoria[i].criancas);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=categoria_acomodacao>\n");
    }


    if (exportar[4] != 0) {
        fprintf(arquivoXML, "    <tabela=produtos>\n");

        for (int i = 0; i < qtd_pro; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", produto[i].codigo);
            fprintf(arquivoXML, "            <descricao>%s</descricao>\n", produto[i].descricao);
            fprintf(arquivoXML, "            <estoque>%d</estoque>\n", produto[i].estoque);
            fprintf(arquivoXML, "            <estoque_min>%d</estoque_min>\n", produto[i].estoque_min);
            fprintf(arquivoXML, "            <preco_custo>%f</preco_custo>\n", produto[i].preco_custo);
            fprintf(arquivoXML, "            <preco_venda>%f</preco_venda>\n", produto[i].preco_venda);
            fprintf(arquivoXML, "        </registro>\n");
        }

        fprintf(arquivoXML, "    </tabela=produtos>\n");
    }
    if (exportar[5] != 0) {

        fprintf(arquivoXML, "    <tabela=fornecedores>\n");

        for (int i = 0; i < qtd_forn; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", fornecedor[i].codigo);
            fprintf(arquivoXML, "            <nome_fantasia>%s</nome_fantasia>\n", fornecedor[i].nome_fantasia);
            fprintf(arquivoXML, "            <razao_social>%s</razao_social>\n", fornecedor[i].razao_social);
            fprintf(arquivoXML, "            <inscricao_estadual>%s</inscricao_estadual>\n", fornecedor[i].inscricao_estadual);
            fprintf(arquivoXML, "            <cnpj>%s</cnpj>\n", fornecedor[i].cnpj);
            fprintf(arquivoXML, "            <endereco>%s;%s;%s;%s;%s;%d</endereco>\n", fornecedor[i].endereco.estado, fornecedor[i].endereco.cidade, fornecedor[i].endereco.bairro, fornecedor[i].endereco.cep, fornecedor[i].endereco.rua, fornecedor[i].endereco.numero);
            fprintf(arquivoXML, "            <telefone>%s</telefone>\n", fornecedor[i].telefone);
            fprintf(arquivoXML, "            <email>%s</email>\n", fornecedor[i].email);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=fornecedores>\n");
    }
    if (exportar[6] != 0) {

        fprintf(arquivoXML, "    <tabela=operadores>\n");
        for (int i = 0; i < qtd_ope; i++) {
            fprintf(arquivoXML, "        <registro>\n");
            fprintf(arquivoXML, "            <codigo>%d</codigo>\n", operador[i].codigo);
            fprintf(arquivoXML, "            <nome>%s</nome>\n", operador[i].nome);
            fprintf(arquivoXML, "            <usuario>%s</usuario>\n", operador[i].usuario);
            fprintf(arquivoXML, "            <senha>%d</senha>\n", operador[i].senha);
            fprintf(arquivoXML, "            <permissoes>%d;%d;%d;%d;%d</permissoes>\n", operador[i].permissoes.cadastros, operador[i].permissoes.reservas, operador[i].permissoes.transacoes, operador[i].permissoes.feedback, operador[i].permissoes.im_exportacao);
            fprintf(arquivoXML, "        </registro>\n");
        }
        fprintf(arquivoXML, "    </tabela=operadores>\n");
    }
    fprintf(arquivoXML, "</dados>\n");


    fclose(arquivoXML);
    printf("Dados exportados com sucesso.\n");
    return 0;
}

//para visual da funcao para exportar dados
void exportar_dados_mem() {
    int exportar[7];

    printf("\n------EXPORTAR DADOS-------\n");
    printf("Quais dados deseja exportar?\n");
    printf("Dados do Hotel.(1-Sim/0-Não):");
    scanf("%d", &exportar[0]);
    printf("Dados dos Hospedes.(1-Sim/0-Não):");
    scanf("%d", &exportar[1]);
    printf("Dados das acomodações.(1-Sim/0-Não):");
    scanf("%d", &exportar[2]);
    printf("Dados das categorias de acomodação.(1-Sim/0-Não):");
    scanf("%d", &exportar[3]);
    printf("Dados dos produtos.(1-Sim/0-Não):");
    scanf("%d", &exportar[4]);
    printf("Dados dos fornecedores.(1-Sim/0-Não):");
    scanf("%d", &exportar[5]);
    printf("Dados dos operadores.(1-Sim/0-Não):");
    scanf("%d", &exportar[6]);

    exportar_dados_xml_mem(exportar);

    menu_modulo_im_exportacao_mem();
}
//FIM IMPORTAÇÃO E EXPORTAÇÃO


//funcao que pega dados dos arquivos binarios e passa para a memoria
int muda_arquivo_bin_p_mem() {
    int existe;
    //traz operadores para ram
    qtd_ope = qtd_itens_bin("Operadores.bin", sizeof (OPsistema));
    operador = (OPsistema *) realloc(operador, qtd_ope * sizeof (OPsistema));
    operadores_ram_bin(operador);
    
    
    //traz Hotel para ram e salva em txt e apaga o arquivo bin
    existe = arquivo_existe_bin("Hotel.bin");
    if (existe == 1) {
        cad_hotel hotelRAM[1];
        //trazendo hotel pra memoria
        hotel_ram_bin(hotelRAM);        
        hotel=hotelRAM[0];
    }

    //traz Hospedes para ram e salva em txt e apaga o arquivo bin
    existe = arquivo_existe_bin("Hospedes.bin");
    if (existe == 1) {
        qtd_hos = qtd_itens_bin("Hospedes.bin", sizeof (hospedes));
        hospede = (hospedes *) realloc(hospede, qtd_hos * sizeof (hospedes));
        hospede_ram_bin(hospede);
    }

    //traz Produtos para ram e salva em txt e apaga o arquivo bin
    existe = arquivo_existe_bin("Produtos.bin");
    if (existe == 1) {
        qtd_pro = qtd_itens_bin("Produtos.bin", sizeof (produtos));
        
        produto = (produtos *) realloc(produto, qtd_pro * sizeof (produtos));
        produtos_ram_bin(produto);
        
    }

    //traz Fornecedores para ram 
    existe = arquivo_existe_bin("Fornecedores.bin");
    if (existe == 1) {
        qtd_forn = qtd_itens_bin("Fornecedores.bin", sizeof (fornecedores));
        
        fornecedor = (fornecedores *) realloc(fornecedor, qtd_forn * sizeof (fornecedores));
        fornecedores_ram_bin(fornecedor);
        
    }

    //traz Categorias para ram 
    existe = arquivo_existe_bin("Categorias.bin");
    if (existe == 1) {
        qtd_cat = qtd_itens_bin("Categorias.bin", sizeof (categoria_acomodacao));
        categoria = (categoria_acomodacao *) realloc(categoria, qtd_cat * sizeof (categoria_acomodacao));
        categorias_ram_bin(categoria);
        
    }

    //traz Acomodacoes para ram 
    existe = arquivo_existe_bin("Acomodacoes.bin");
    if (existe == 1) {
        qtd_acomd = qtd_itens_bin("Acomodacoes.bin", sizeof (acomodacoes));
        acomodacao = (acomodacoes *) realloc(acomodacao, qtd_acomd * sizeof (acomodacoes));
        acomodacoes_ram_bin(acomodacao);
    }

    //traz Reservas para ram 
    existe = arquivo_existe_bin("Reservas.bin");
    if (existe == 1) {
        qtd_res = qtd_itens_bin("Reservas.bin", sizeof (reservas));
        reserva = (reservas *) realloc(reserva, qtd_res * sizeof (reservas));
        reservas_ram_bin(reserva);
        
    }

    existe = arquivo_existe_txt("Contas_hospede.bin");
    if (existe == 1) {
        qtd_con = qtd_itens_bin("Contas_hospede.bin", sizeof (conta_hospede));
        conta = (conta_hospede *) realloc(conta, qtd_con * sizeof (conta_hospede));
        conta_hospede_ram_bin(conta);
        
    }

    existe = arquivo_existe_txt("Vendas.bin");
    if (existe == 1) {
        qtd_venda = qtd_itens_bin("Vendas.bin", sizeof (vendas));
        venda = (vendas *) realloc(venda, qtd_venda * sizeof (vendas));
        venda_ram_bin(venda);
    }


    existe = arquivo_existe_txt("Caixa.bin");
    if (existe == 1) {
        qtd_cai = qtd_itens_bin("Caixa.bin", sizeof (conta_receber));
        caixa = (conta_receber *) realloc(caixa, qtd_cai * sizeof (conta_receber));
        caixa_ram_bin(caixa);
    }

    existe = arquivo_existe_txt("Contas_receber.bin");
    if (existe == 1) {
        qtd_con_rec = qtd_itens_bin("Contas_receber.bin", sizeof (conta_receber));
        conta_rec = (conta_receber *) realloc(conta_rec, qtd_con_rec * sizeof (conta_receber));
        contas_a_receber_ram_bin(conta_rec);
        
    }

    existe = arquivo_existe_txt("Contas_pagar.bin");
    if (existe == 1) {
        qtd_con_pag = qtd_itens_bin("Contas_pagar.bin", sizeof (conta_receber));
        conta_pag = (conta_receber *) realloc(conta_pag, qtd_con_pag * sizeof (conta_receber));
        contas_a_pagar_ram_bin(conta_pag);
        
    }

    existe = arquivo_existe_txt("Notas_fiscais.bin");
    if (existe == 1) {
        qtd_notas = notasfiscais_ram_bin(&notas);
    }
}

//funcao que pega dados dos arquivos txt e passa para a memoria
int muda_arquivo_txt_p_mem() {
    int existe, quantidade;

    //traz operadores para ram e salva em binario e apaga o arquivo txt
    qtd_ope = contadorlinhas_txt("operadores.txt");
    qtd_ope = qtd_ope / 9;
    operador = (OPsistema *) realloc(operador, qtd_ope * sizeof (OPsistema));
    operadores_ram_txt(qtd_ope, operador);

    //traz hotel para ram e salva em binario e apaga o arquivo txt
    existe = arquivo_existe_txt("hotel.txt");
    if (existe == 1) {
        cad_hotel hotelRAM[1];
        //trazendo hotel pra memoria
        hotel_ram_txt(hotelRAM);
        hotel = hotelRAM[0];
    }

    //traz hospedes para ram e salva em binario e apaga o arquivo txt
    existe = arquivo_existe_txt("hospedes.txt");
    if (existe == 1) {
        qtd_hos = contadorlinhas_txt("hospedes.txt");
        qtd_hos = qtd_hos / 16;
        hospede = (hospedes *) realloc(hospede, qtd_hos * sizeof (hospedes));
        hospedes_ram_txt(hospede, qtd_hos);
    }

    //traz produtos para ram e salva em binario e apaga o arquivo txt
    existe = arquivo_existe_txt("produtos.txt");
    if (existe == 1) {
        qtd_pro = contadorlinhas_txt("produtos.txt");
        qtd_pro = qtd_pro / 6;
        produto = (produtos *) realloc(produto, qtd_pro * sizeof (produtos));
        produtos_ram_txt(produto, qtd_pro);
        
    }

    //traz fornecedores para ram e salva em binario e apaga o arquivo txt
    existe = arquivo_existe_txt("fornecedores.txt");
    if (existe == 1) {
        qtd_forn = contadorlinhas_txt("fornecedores.txt");
        qtd_forn = qtd_forn / 13;
        fornecedor = (fornecedores *) realloc(fornecedor, qtd_forn * sizeof (fornecedores));
        fornecedores_ram_txt(fornecedor, qtd_forn);
    }

    //traz categorias para ram e salva em binario e apaga o arquivo txt
    existe = arquivo_existe_txt("categorias.txt");
    if (existe == 1) {
        qtd_cat = contadorlinhas_txt("categorias.txt");
        qtd_cat = qtd_cat / 5;
        categoria = (categoria_acomodacao *) realloc(categoria, qtd_cat * sizeof (categoria_acomodacao));
        categorias_ram_txt(categoria, qtd_cat);
        
    }

    //traz acomodacoes para ram e salva em binario e apaga o arquivo txt
    existe = arquivo_existe_txt("acomodacoes.txt");
    if (existe == 1) {
        qtd_acomd = contadorlinhas_txt("acomodacoes.txt");
        qtd_acomd = qtd_acomd / 7;
        acomodacao = (acomodacoes *) realloc(acomodacao, qtd_acomd * sizeof (acomodacoes));
        acomodacoes_ram_txt(acomodacao, qtd_acomd);
    }

    //traz reservas para ram e salva em binario e apaga o arquivo txt
    existe = arquivo_existe_txt("reservas.txt");
    if (existe == 1) {
        qtd_res = contadorlinhas_txt("reservas.txt");
        qtd_res = qtd_res / 16;
        reserva = (reservas *) realloc(reserva, qtd_res * sizeof (reservas));
        reservas_ram_txt(qtd_res, reserva);
    }


    existe = arquivo_existe_txt("conta_hospedes.txt");
    if (existe == 1) {
        qtd_con = contadorlinhas_txt("conta_hospedes.txt");
        qtd_con = qtd_con / 3;
        conta = (conta_hospede *) realloc(conta, qtd_con * sizeof (conta_hospede));
        conta_ram_txt(conta, qtd_con);
    }
    
    existe = arquivo_existe_txt("vendas.txt");
    if (existe == 1) {
        qtd_venda = contadorlinhas_txt("vendas.txt");
        venda = (vendas *) realloc(venda, qtd_venda * sizeof (vendas));
        ram_venda_txt(venda, qtd_venda);
        
    }


    existe = arquivo_existe_txt("caixa.txt");
    if (existe == 1) {
        qtd_cai = contadorlinhas_txt("caixa.txt");
        qtd_cai = qtd_cai / 5;
        caixa = (conta_receber *) realloc(caixa, qtd_cai * sizeof (conta_receber));
        caixa_ram_txt(caixa, qtd_cai);
        
    }

    existe = arquivo_existe_txt("contas_receber.txt");
    if (existe == 1) {
        qtd_con_rec = contadorlinhas_txt("contas_receber.txt");
        qtd_con_rec = qtd_con_rec / 5;
        conta_rec = (conta_receber *) realloc(conta_rec, qtd_con_rec * sizeof (conta_receber));
        contas_receber_ram_txt(conta_rec, qtd_con_rec);
    }

    existe = arquivo_existe_txt("contas_pagar.txt");
    if (existe == 1) {
        qtd_con_pag = contadorlinhas_txt("contas_pagar.txt");
        qtd_con_pag = qtd_con_pag / 5;
        conta_pag = (conta_receber *) realloc(conta_pag, qtd_con_pag * sizeof (conta_receber));
        contas_pagar_ram_txt(conta_pag, qtd_con_pag);
    }

    existe = arquivo_existe_txt("notas_fiscais.txt");
    if (existe == 1) {
        qtd_notas = contadorlinhas_txt("notas_fiscais.txt");
        qtd_notas = qtd_notas / 7;
        notas = (NotaFiscal *) realloc(notas, qtd_notas * sizeof (NotaFiscal));
        ram_notafiscal_txt(qtd_notas, notas);
    }
}