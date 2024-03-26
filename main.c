#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivosTXT.h"
#include "structs.h"
#include "funcoes.h"
#include "reservasTXT.h"
#include "menu.h"
#include "ArquivosBin.h"
#include "ReservasBin.h"
#include "memoria.h"


//INICIO MAIN TXT

//COMEÇO HOTEL
void main_cadastro_hotel_txt() {
    //variaveis para o cadastro do hotel
    cad_hotel hotel_inf;
    int retorno = 0, opcao = 0;
    retorno = arquivo_existe_txt("hotel.txt");
    if (retorno == 1) {
        printf("Já existe um hotel cadastrado se continuar o cadastro antigo será excluído, deseja continuar?(1-Sim/0-Não):");
        scanf("%d", &opcao);
    }

    if (opcao == 1) {
        //Recebendo dados do hotel
        printf("-------CADASTRO DO HOTEL-------\n");
        printf("Digite o nome fantasia:");
        scanf(" %[^\n]s%*c", hotel_inf.nome_fantasia);
        setbuf(stdin, NULL);
        printf("Digite a razão social:");
        scanf(" %[^\n]s%*c", hotel_inf.razao_social);
        setbuf(stdin, NULL);
        printf("Digite a inscrição estadual:");
        scanf(" %[^\n]s%*c", hotel_inf.inscricao_estadual);
        setbuf(stdin, NULL);
        printf("Digite o CNPJ:");
        scanf(" %[^\n]s%*c", hotel_inf.cnpj);
        setbuf(stdin, NULL);
        printf("-------ENDEREÇO-------\n");
        printf("Digite o estado:");
        scanf(" %[^\n]s%*c", hotel_inf.endereco.estado);
        setbuf(stdin, NULL);
        printf("Digite a cidade:");
        scanf(" %[^\n]s%*c", hotel_inf.endereco.cidade);
        setbuf(stdin, NULL);
        printf("Digite o CEP:");
        scanf(" %[^\n]s%*c", &hotel_inf.endereco.cep);
        setbuf(stdin, NULL);
        printf("Digite o bairro:");
        scanf(" %[^\n]s%*c", hotel_inf.endereco.bairro);
        setbuf(stdin, NULL);
        printf("Digite a rua:");
        scanf(" %[^\n]s%*c", hotel_inf.endereco.rua);
        setbuf(stdin, NULL);
        printf("Digite o numero:");
        scanf("%d", &hotel_inf.endereco.numero);
        setbuf(stdin, NULL);
        printf("--------------------------------------------------------------------------\n");
        printf("-------DADOS PARA CONTATO-------\n");
        printf("Digite o telefone do hotel:");
        scanf(" %[^\n]s%*c", hotel_inf.telefone);
        setbuf(stdin, NULL);
        printf("Digite o e-mail do hotel:");
        scanf(" %[^\n]s%*c", hotel_inf.email);
        setbuf(stdin, NULL);
        printf("Digite o nome do responsável:");
        scanf(" %[^\n]s%*c", hotel_inf.nome_responsavel);
        setbuf(stdin, NULL);
        printf("Digite o telefone do responsável:");
        scanf(" %[^\n]s%*c", hotel_inf.telefone_responsavel);
        setbuf(stdin, NULL);
        printf("--------------------------------------------------------------------------\n");
        printf("-------HORÁRIO DE CHECK-IN-------\n");
        printf("Digite a hora do chekin(SOMENTE HORA):");
        scanf("%d", &hotel_inf.horario_checkin.hora);
        setbuf(stdin, NULL);
        printf("Digite os minutos do chekin(SOMENTE MINUTOS):");
        scanf("%d", &hotel_inf.horario_checkin.minutos);
        setbuf(stdin, NULL);
        printf("--------------------------------------------------------------------------\n");
        printf("-------HORÁRIO DE CHECK-OUT-------\n");
        printf("Digite a hora do chek-out(SOMENTE HORA):");
        scanf("%d", &hotel_inf.horario_checkout.hora);
        setbuf(stdin, NULL);
        printf("Digite os minutos do chek-out(SOMENTE MINUTOS):");
        scanf("%d", &hotel_inf.horario_checkout.minutos);
        setbuf(stdin, NULL);
        printf("--------------------------------------------------------------------------\n");
        printf("Digite a margem de lucro sobre os produtos:");
        scanf("%f", &hotel_inf.mlpv);
        setbuf(stdin, NULL);
        //chamando a função para gravar o hotel em txt
        //passando a struct como paramentro
        cadastro_hotel_txt(hotel_inf);


        //teste de hotel 

        strcpy(hotel_inf.nome_fantasia, "Hotel Teste");
        strcpy(hotel_inf.razao_social, "Razao Social Teste");
        strcpy(hotel_inf.inscricao_estadual, "123456");
        strcpy(hotel_inf.cnpj, "987654");
        strcpy(hotel_inf.endereco.estado, "Estado Teste");
        strcpy(hotel_inf.endereco.cidade, "Cidade Teste");
        strcpy(hotel_inf.endereco.cep, "12345-678");
        strcpy(hotel_inf.endereco.bairro, "Bairro Teste");
        strcpy(hotel_inf.endereco.rua, "Rua Teste");
        hotel_inf.endereco.numero = 12345;
        strcpy(hotel_inf.telefone, "123-456-7890");
        strcpy(hotel_inf.email, "hotel@teste.com");
        strcpy(hotel_inf.nome_responsavel, "Responsavel Teste");
        strcpy(hotel_inf.telefone_responsavel, "987-654-3210");
        hotel_inf.horario_checkin.hora = 10;
        hotel_inf.horario_checkin.minutos = 10;
        hotel_inf.horario_checkout.hora = 10;
        hotel_inf.horario_checkout.minutos = 10;
        hotel_inf.mlpv = 0.20;
        cadastro_hotel_txt(hotel_inf);
    }

    menu_gestao_hotel();
}

void main_atualiza_hotel_txt() {
    //variaveis para trazer dados do hotel para ram
    int opcao, retorno = 0;

    retorno = arquivo_existe_txt("hotel.txt");
    if (retorno == 0) {
        printf("Não Existe nenhum hotel cadastrado.\n\n");
        menu_gestao_hotel();
    }

    cad_hotel ramHT[1];


    printf("----------Atualizar dados do hotel----------\n");
    hotel_ram_txt(ramHT);
    printf("Dados atuais do hotel.\n");
    printf("Nome fantasia:%s\n", ramHT[0].nome_fantasia);
    printf("Razão social:%s\n", ramHT[0].razao_social);
    printf("Inscrição estadual:%s\n", ramHT[0].inscricao_estadual);
    printf("CNPJ:%s\n", ramHT[0].cnpj);
    printf("-------ENDEREÇO-------\n");
    printf("Estado:%s\n", ramHT[0].endereco.estado);
    printf("Cidade:%s\n", ramHT[0].endereco.cidade);
    printf("CEP:%s\n", ramHT[0].endereco.cep);
    printf("Bairro:%s\n", ramHT[0].endereco.bairro);
    printf("Rua:%s\n", ramHT[0].endereco.rua);
    printf("Numero de endereço:%d\n", ramHT[0].endereco.numero);
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Telefone do hotel:%s\n", ramHT[0].telefone);
    printf("E-mail do hotel:%s\n", ramHT[0].email);
    printf("Nome do responsável:%s\n", ramHT[0].nome_responsavel);
    printf("Telefone do responsável:%s\n", ramHT[0].telefone_responsavel);
    printf("-------HORÁRIO DE CHECK-IN-------\n");
    printf("%d:%d\n", ramHT[0].horario_checkin.hora, ramHT[0].horario_checkin.minutos);
    printf("-------HORÁRIO DE CHECK-OUT-------\n");
    printf("%d:%d\n", ramHT[0].horario_checkout.hora, ramHT[0].horario_checkout.minutos);
    printf("Margem de lucro sobre os produtos:%f\n", ramHT[0].mlpv);
    printf("Deseja alterar o nome fantasia?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo nome fantasia:");
        scanf(" %[^\n]s%*c", ramHT[0].nome_fantasia);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar a razão social?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova razão social:");
        scanf(" %[^\n]s%*c", ramHT[0].razao_social);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar a inscrição estadual?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova inscrição estadual:");
        scanf(" %[^\n]s%*c", ramHT[0].inscricao_estadual);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o CNPJ?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo CNPJ:");
        scanf(" %[^\n]s%*c", ramHT[0].cnpj);
        setbuf(stdin, NULL);
    }
    printf("-------ENDEREÇO-------\n");
    printf("Deseja alterar o Estado?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo estado:");
        scanf(" %[^\n]s%*c", ramHT[0].endereco.estado);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar a cidade?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova cidade:");
        scanf(" %[^\n]s%*c", ramHT[0].endereco.cidade);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o CEP?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo CEP:");
        scanf(" %[^\n]s%*c", &ramHT[0].endereco.cep);
        setbuf(stdin, NULL);
    }

    printf("Deseja alterar o bairro?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo bairro:");
        scanf(" %[^\n]s%*c", ramHT[0].endereco.bairro);
        setbuf(stdin, NULL);
    }

    printf("Deseja alterar a rua?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova rua:");
        scanf(" %[^\n]s%*c", ramHT[0].endereco.rua);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o numero de endereço?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo numero de endereço:");
        scanf("%d", &ramHT[0].endereco.numero);
        setbuf(stdin, NULL);
    }
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Deseja alterar o telefone do hotel?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo telefone do hotel:");
        scanf(" %[^\n]s%*c", ramHT[0].telefone);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o e-mail do hotel?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o e-mail do hotel:");
        scanf(" %[^\n]s%*c", ramHT[0].email);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o nome do responsável do hotel?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo nome do responsável:");
        scanf(" %[^\n]s%*c", ramHT[0].nome_responsavel);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o telefone do responsável do hotel?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Novo telefone do responsável:");
        scanf(" %[^\n]s%*c", ramHT[0].telefone_responsavel);
        setbuf(stdin, NULL);
    }
    printf("-------HORÁRIO DE CHECK-IN-------\n");
    printf("Deseja alterar a hora do chek-in?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova hora do chekin(SOMENTE HORA):");
        scanf("%d", &ramHT[0].horario_checkin.hora);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o minuto do chek-in?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite os minutos do chekin(SOMENTE MINUTOS):");
        scanf("%d", &ramHT[0].horario_checkin.minutos);
        setbuf(stdin, NULL);
    }
    printf("-------HORÁRIO DE CHECK-OUT-------\n");
    printf("Deseja alterar a hora do chek-out?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova hora do chek-out(SOMENTE HORA):");
        scanf("%d", &ramHT[0].horario_checkout.hora);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar o minuto do chek-out?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite os minutos do chek-out(SOMENTE MINUTOS):");
        scanf("%d", &ramHT[0].horario_checkout.minutos);
        setbuf(stdin, NULL);
    }
    printf("Deseja alterar a margem de lucro sobre os produtos?(1-Sim/0-Não)");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Nova margem de lucro sobre os produtos:");
        scanf("%f", &ramHT[0].mlpv);
        setbuf(stdin, NULL);
    }
    atualiza_hotel_txt(ramHT);

    menu_gestao_hotel();
}
//FIM HOTEL


//COMEÇO OPERADOR
void main_cadastro_operador_txt() {
    //variaveis utilizadas para cadastro de operadores
    OPsistema op;
    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;

    //verificando se o arquvio de operadores ja existe 
    retorno = arquivo_existe_txt("operadores.txt");
    //se existir trago os dados para ram para verificar se o codigo do operador é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = contadorlinhas_txt("operadores.txt");
        quantidade = quantidade / 9;
        OPsistema ramOP[quantidade];
        operadores_ram_txt(quantidade, ramOP);

        printf("-------CADASTRO DE OPERADORES-------\n");
        printf("Digite o codigo do operador:");
        scanf("%d", &op.codigo);
        posicao = procura_operador_txt(op.codigo, quantidade, ramOP);
        while (posicao != -1) {
            printf("Esse codigo de operador ja existe digite um diferente:");
            scanf("%d", &op.codigo);
            posicao = procura_operador_txt(op.codigo, quantidade, ramOP);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_operadores();
            }
        }
    } else {
        //recebendo dados de operadores
        printf("-------CADASTRO DE OPERADORES-------\n");
        printf("Digite o codigo do usuario:");
        scanf("%d", &op.codigo);
    }

    printf("Digite o nome do operador:");
    scanf(" %[^\n]s%*c", op.nome);
    setbuf(stdin, NULL);
    printf("Digite o nome do usario:");
    scanf(" %[^\n]s%*c", op.usuario);
    setbuf(stdin, NULL);
    printf("Digite a senha para o usuario:");
    scanf("%d", &op.senha);
    setbuf(stdin, NULL);
    printf("-------PERMISSÕES-------\n");
    printf("Cadastros:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.cadastros);
    setbuf(stdin, NULL);
    printf("Reservas:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.reservas);
    setbuf(stdin, NULL);
    printf("Transações:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.transacoes);
    setbuf(stdin, NULL);
    printf("FeedBack:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.feedback);
    setbuf(stdin, NULL);
    printf("Importações e Exportações:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.im_exportacao);
    setbuf(stdin, NULL);

    //funcao responsavel por salvar os dados dos operadores em txt
    //passando o struct de operadores como parametro
    cadastro_operadores_txt(op);
    //fim do cadastro de operadores

    menu_gestao_operadores();
}

void main_atualiza_operador_txt() {
    //variaveis utilizadas para atualizar operador
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0;
    retorno = arquivo_existe_txt("operadores.txt");
    if (retorno == 0) {
        printf("Nenhum operador cadastrado.\n");
        menu_gestao_operadores();
    }


    quantidade = contadorlinhas_txt("operadores.txt");
    quantidade = quantidade / 9;
    OPsistema ramOP[quantidade];
    operadores_ram_txt(quantidade, ramOP);

    printf("-------ATUALIZAR DADOS DOS OPERADORES-------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do operador que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o operadores
        posicao = procura_operador_txt(codigo, quantidade, ramOP);
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
            menu_gestao_operadores();

        }

    } while (posicao == -1);

    printf("------Dados do operador------\n");
    printf("Codigo:%d\n", ramOP[posicao].codigo);
    printf("Nome: %s\n", ramOP[posicao].nome);
    printf("Nome de usuário:%s\n", ramOP[posicao].usuario);
    printf("Senha:%d\n", ramOP[posicao].senha);

    if (ramOP[posicao].permissoes.cadastros == 0 && ramOP[posicao].permissoes.reservas == 0 && ramOP[posicao].permissoes.transacoes == 0
            && ramOP[posicao].permissoes.feedback == 0 && ramOP[posicao].permissoes.im_exportacao == 0) {
        printf("Nenhuma permissão ativa\n");
    } else {
        printf("------Pemissões Atividas------\n");
        if (ramOP[posicao].permissoes.cadastros == 1) {
            printf("Cadastro\n");
        }
        if (ramOP[posicao].permissoes.reservas == 1) {
            printf("Reservas\n");
        }
        if (ramOP[posicao].permissoes.transacoes == 1) {
            printf("Transações\n");
        }
        if (ramOP[posicao].permissoes.feedback == 1) {
            printf("Feedback\n");
        }
        if (ramOP[posicao].permissoes.im_exportacao == 1) {
            printf("Importação e Exportações\n");
        }
    }

    printf("Deseja alterar qual dados do operador?(Digite a opção desejada)\n");
    printf("1-Nome\n2-Nome do usuário\n3-Senha\n4-Permissões\n5-Todos");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            printf("Digite o novo nome do operador:");
            scanf(" %[^\n]s%*c", ramOP[posicao].nome);
            setbuf(stdin, NULL);

            break;
        case 2:
            printf("Digite o novo nome do usuarior:");
            scanf(" %[^\n]s%*c", ramOP[posicao].usuario);
            setbuf(stdin, NULL);
            break;
        case 3:
            printf("Digite a nova senha:");
            scanf(" %[^\n]s%*c", ramOP[posicao].senha);
            setbuf(stdin, NULL);
            printf("%d", ramOP[posicao].senha);
            break;
        case 4:
            printf("-------Permissoões-------\n");
            printf("Cadastros:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.cadastros);
            setbuf(stdin, NULL);
            printf("Reservas:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.reservas);
            setbuf(stdin, NULL);
            printf("Transações:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.transacoes);
            setbuf(stdin, NULL);
            printf("FeedBack:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.feedback);
            setbuf(stdin, NULL);
            printf("Importações e Exportações:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.im_exportacao);
            setbuf(stdin, NULL);
            break;
        case 5:
            printf("Digite o codigo do usuario:");
            scanf("%d", &ramOP[posicao].codigo);
            setbuf(stdin, NULL);
            printf("Digite o nome do operador:");
            scanf(" %[^\n]s%*c", ramOP[posicao].nome);
            setbuf(stdin, NULL);
            printf("Digite o nome do usario:");
            scanf(" %[^\n]s%*c", ramOP[posicao].usuario);
            setbuf(stdin, NULL);
            printf("Digite a senha para o usuario:");
            scanf("%d", &ramOP[posicao].senha);
            setbuf(stdin, NULL);
            printf("-------PERMISSÕES-------\n");
            printf("Cadastros:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.cadastros);
            setbuf(stdin, NULL);
            printf("Reservas:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.reservas);
            setbuf(stdin, NULL);
            printf("Transações:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.transacoes);
            setbuf(stdin, NULL);
            printf("FeedBack:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.feedback);
            setbuf(stdin, NULL);
            printf("Importações e Exportações:(1-Permitir/0-Negar)");
            scanf("%d", &ramOP[posicao].permissoes.im_exportacao);
            setbuf(stdin, NULL);
            break;
    }
    atualiza_operador_txt(quantidade, ramOP);

    menu_gestao_operadores();
}

void main_deleta_operador_txt() {
    //variaveis utilizadas na deleção de operadores
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, delete = 0;

    retorno = arquivo_existe_txt("operadores.txt");
    if (retorno == 0) {
        printf("Nenhum operador cadastrado.\n");
        menu_gestao_operadores();
    }

    quantidade = contadorlinhas_txt("operadores.txt");
    quantidade = quantidade / 9;

    OPsistema ramDELOP[quantidade];
    operadores_ram_txt(quantidade, ramDELOP);



    printf("-----Deleção de Operador-----\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do operador que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar o operadores
        posicao = procura_operador_txt(codigo, quantidade, ramDELOP);
        printf("posicao=%d", posicao);
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
            menu_gestao_operadores();

        }
    } while (posicao == -1);
    printf("------Dados do operador------\n");
    printf("Codigo:%d\n", ramDELOP[posicao].codigo);
    printf("Nome: %s\n", ramDELOP[posicao].nome);
    printf("Nome de usuário:%s\n", ramDELOP[posicao].usuario);
    printf("Senha:%d\n", ramDELOP[posicao].senha);

    if (ramDELOP[posicao].permissoes.cadastros == 0 && ramDELOP[posicao].permissoes.reservas == 0 && ramDELOP[posicao].permissoes.transacoes == 0
            && ramDELOP[posicao].permissoes.feedback == 0 && ramDELOP[posicao].permissoes.im_exportacao == 0) {
        printf("Nenhuma permissão ativa.\n");
    } else {
        printf("------Pemissões Atividas------\n");
        if (ramDELOP[posicao].permissoes.cadastros == 1) {
            printf("Cadastro.\n");
        }
        if (ramDELOP[posicao].permissoes.reservas == 1) {
            printf("Reservas.\n");
        }
        if (ramDELOP[posicao].permissoes.transacoes == 1) {
            printf("Transações.\n");
        }
        if (ramDELOP[posicao].permissoes.feedback == 1) {
            printf("Feedback.\n");
        }
        if (ramDELOP[posicao].permissoes.im_exportacao == 1) {
            printf("Importação e Exportações.\n");
        }
    }
    printf("Deseja realmente deletar esse operador?(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        deleta_operador_txt(quantidade, posicao, ramDELOP);
    }
    // fim do delete de operadores
    menu_gestao_operadores();
}
//FIM OPERADOR

//COMEÇO HOSPEDE
void main_cadastro_hospede_txt() {
    //variaveis para cadastro de hospedes
    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;
    hospedes cadastro_hospedes;


    //verificando se o arquvio de hospedes ja existe 
    retorno = arquivo_existe_txt("hospedes.txt");


    //se existir trago os dados para ram para verificar se o codigo do hospede é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = contadorlinhas_txt("hospedes.txt");
        quantidade = quantidade / 16;
        hospedes ramHO[quantidade];
        hospedes_ram_txt(ramHO, quantidade);

        printf("-------Cadastros de Hospedes--------\n");
        printf("Digite o codigo do hospedes:");
        scanf("%d", &cadastro_hospedes.codigo);
        setbuf(stdin, NULL);

        posicao = procura_hospede_txt(cadastro_hospedes.codigo, quantidade, ramHO);
        while (posicao != -1) {
            printf("Esse codigo de hospedes ja existe digite um diferente:");
            scanf("%d", &cadastro_hospedes.codigo);
            posicao = procura_hospede_txt(cadastro_hospedes.codigo, quantidade, ramHO);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_hospedes();
            }
        }
    } else {
        printf("-------Cadastros de Hospedes--------\n");
        printf("Digite o codigo do hospede:");
        scanf("%d", &cadastro_hospedes.codigo);
        setbuf(stdin, NULL);

    }




    printf("Digite o nome do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.nome);
    setbuf(stdin, NULL);
    printf("----Dados de endereço do Hospede----\n");
    printf("Digite o estado do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.cidade);
    setbuf(stdin, NULL);
    printf("Digite a cep do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero de endereço do hospede:");
    scanf("%d", &cadastro_hospedes.endereco_hospede.numero);
    setbuf(stdin, NULL);
    printf("----Dados pessoais do hospede-----\n");
    printf("Digite o CPF do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.cpf);
    setbuf(stdin, NULL);
    printf("Digite o telefone do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.email);
    setbuf(stdin, NULL);
    printf("Digite o sexo do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.sexo);
    setbuf(stdin, NULL);
    printf("Digite o estado civil do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.estado_civil);
    setbuf(stdin, NULL);
    printf("Digite a data de nascimento do hospede.\n");
    printf("Dia:");
    scanf("%d", &cadastro_hospedes.data_nacimento.dia);
    setbuf(stdin, NULL);
    printf("Mês:");
    scanf("%d", &cadastro_hospedes.data_nacimento.mes);
    setbuf(stdin, NULL);
    printf("Ano:");
    scanf("%d", &cadastro_hospedes.data_nacimento.ano);
    setbuf(stdin, NULL);
    cadastro_hospedes_txt(cadastro_hospedes);
    /*
    cadastro_hospedes.codigo=1;
    strcpy(cadastro_hospedes.nome, "João da Silva");
    strcpy(cadastro_hospedes.endereco_hospede.estado, "São Paulo");
    strcpy(cadastro_hospedes.endereco_hospede.cidade, "São Paulo");
    strcpy(cadastro_hospedes.endereco_hospede.cep, "12345-678");
    strcpy(cadastro_hospedes.endereco_hospede.bairro, "Centro");
    strcpy(cadastro_hospedes.endereco_hospede.rua, "Rua Principal");
    cadastro_hospedes.endereco_hospede.numero = 123;
    strcpy(cadastro_hospedes.cpf, "123.456.789-00");
    strcpy(cadastro_hospedes.telefone, "(11) 1234-5678");
    strcpy(cadastro_hospedes.email, "joao.silva@example.com");
    strcpy(cadastro_hospedes.sexo, "Masculino");
    strcpy(cadastro_hospedes.estado_civil, "Solteiro");
    cadastro_hospedes.data_nacimento.dia = 15;
    cadastro_hospedes.data_nacimento.mes = 7;
    cadastro_hospedes.data_nacimento.ano = 1990;
    cadastro_hospedes_txt(cadastro_hospedes);
        
    cadastro_hospedes.codigo = 2;
    strcpy(cadastro_hospedes.nome, "Maria Santos");
    strcpy(cadastro_hospedes.endereco_hospede.estado, "Rio de Janeiro");
    strcpy(cadastro_hospedes.endereco_hospede.cidade, "Rio de Janeiro");
    strcpy(cadastro_hospedes.endereco_hospede.cep, "54321-987");
    strcpy(cadastro_hospedes.endereco_hospede.bairro, "Copacabana");
    strcpy(cadastro_hospedes.endereco_hospede.rua, "Avenida Beira-Mar");
    cadastro_hospedes.endereco_hospede.numero = 456;
    strcpy(cadastro_hospedes.cpf, "987.654.321-00");
    strcpy(cadastro_hospedes.telefone, "(21) 9876-5432");
    strcpy(cadastro_hospedes.email, "maria.santos@example.com");
    strcpy(cadastro_hospedes.sexo, "Feminino");
    strcpy(cadastro_hospedes.estado_civil, "Casada");
    cadastro_hospedes.data_nacimento.dia = 10;
    cadastro_hospedes.data_nacimento.mes = 3;
    cadastro_hospedes.data_nacimento.ano = 1985;
    cadastro_hospedes_txt(cadastro_hospedes);
        
    cadastro_hospedes.codigo = 3;
    strcpy(cadastro_hospedes.nome, "Carlos Ferreira");
    strcpy(cadastro_hospedes.endereco_hospede.estado, "Minas Gerais");
    strcpy(cadastro_hospedes.endereco_hospede.cidade, "Belo Horizonte");
    strcpy(cadastro_hospedes.endereco_hospede.cep, "98765-432");
    strcpy(cadastro_hospedes.endereco_hospede.bairro, "Centro");
    strcpy(cadastro_hospedes.endereco_hospede.rua, "Rua das Flores");
    cadastro_hospedes.endereco_hospede.numero = 789;
    strcpy(cadastro_hospedes.cpf, "345.678.901-23");
    strcpy(cadastro_hospedes.telefone, "(31) 1234-5678");
    strcpy(cadastro_hospedes.email, "carlos.ferreira@example.com");
    strcpy(cadastro_hospedes.sexo, "Masculino");
    strcpy(cadastro_hospedes.estado_civil, "Divorciado");
    cadastro_hospedes.data_nacimento.dia = 5;
    cadastro_hospedes.data_nacimento.mes = 9;
    cadastro_hospedes.data_nacimento.ano = 1978;
    cadastro_hospedes_txt(cadastro_hospedes);
        
    cadastro_hospedes.codigo = 4;
    strcpy(cadastro_hospedes.nome, "Ana Oliveira");
    strcpy(cadastro_hospedes.endereco_hospede.estado, "Bahia");
    strcpy(cadastro_hospedes.endereco_hospede.cidade, "Salvador");
    strcpy(cadastro_hospedes.endereco_hospede.cep, "87654-321");
    strcpy(cadastro_hospedes.endereco_hospede.bairro, "Barra");
    strcpy(cadastro_hospedes.endereco_hospede.rua, "Avenida Ondina");
    cadastro_hospedes.endereco_hospede.numero = 567;
    strcpy(cadastro_hospedes.cpf, "567.890.123-45");
    strcpy(cadastro_hospedes.telefone, "(71) 4321-8765");
    strcpy(cadastro_hospedes.email, "ana.oliveira@example.com");
    strcpy(cadastro_hospedes.sexo, "Feminino");
    strcpy(cadastro_hospedes.estado_civil, "Viúva");
    cadastro_hospedes.data_nacimento.dia = 20;
    cadastro_hospedes.data_nacimento.mes = 12;
    cadastro_hospedes.data_nacimento.ano = 1965;
    cadastro_hospedes_txt(cadastro_hospedes);
        
    cadastro_hospedes.codigo = 5;
    strcpy(cadastro_hospedes.nome, "Rafael Almeida");
    strcpy(cadastro_hospedes.endereco_hospede.estado, "Santa Catarina");
    strcpy(cadastro_hospedes.endereco_hospede.cidade, "Florianópolis");
    strcpy(cadastro_hospedes.endereco_hospede.cep, "76543-210");
    strcpy(cadastro_hospedes.endereco_hospede.bairro, "Ingleses");
    strcpy(cadastro_hospedes.endereco_hospede.rua, "Rua das Palmeiras");
    cadastro_hospedes.endereco_hospede.numero = 987;
    strcpy(cadastro_hospedes.cpf, "678.901.234-56");
    strcpy(cadastro_hospedes.telefone, "(48) 8765-4321");
    strcpy(cadastro_hospedes.email, "rafael.almeida@example.com");
    strcpy(cadastro_hospedes.sexo, "Masculino");
    strcpy(cadastro_hospedes.estado_civil, "Casado");
    cadastro_hospedes.data_nacimento.dia = 8;
    cadastro_hospedes.data_nacimento.mes = 4;
    cadastro_hospedes.data_nacimento.ano = 1980;
    cadastro_hospedes_txt(cadastro_hospedes);
     */
    menu_gestao_hospedes();
}

void main_atualiza_hospede_txt() {
    //variaveis utlizadas atualizar hospede
    int quantidade = 0, codigo = 0, contador_erro = 0, posicao = 0, opcao = 0, sair = 0, retorno = 0;

    retorno = arquivo_existe_txt("hospedes.txt");
    if (retorno == 0) {
        printf("Nenhum hospede cadastrado.\n\n");
        menu_gestao_hospedes();
    }


    quantidade = contadorlinhas_txt("hospedes.txt");
    quantidade = quantidade / 16;
    hospedes ramHO[quantidade];
    hospedes_ram_txt(ramHO, quantidade);


    printf("-------Atualizar Hospede-------\n");

    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do hospede que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o operadores
        posicao = procura_hospede_txt(codigo, quantidade, ramHO);
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
            menu_gestao_hospedes();
        }

    } while (posicao == -1);
    printf("O codigo atual do hospede é: %d.\n", ramHO[posicao].codigo);
    printf("Deseja alterar o codigo do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo codigo:");
        scanf("%d", &ramHO[posicao].codigo);
    }
    printf("O nome atual do hospede é: %s.\n", ramHO[posicao].nome);
    printf("Deseja alterar o nome do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo nome:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].nome);
    }
    printf("-----Dados de Endereço-------\n");
    printf("O estado atual do hospede é: %s.\n", ramHO[posicao].endereco_hospede.estado);
    printf("Deseja alterar o estado do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estado:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].endereco_hospede.estado);
    }
    printf("A cidade atual do hospede é: %s.\n", ramHO[posicao].endereco_hospede.cidade);
    printf("Deseja alterar a cidade do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova cidade:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].endereco_hospede.cidade);
    }
    printf("O CEP atual do hospede é: %s.\n", ramHO[posicao].endereco_hospede.cep);
    printf("Deseja alterar o CEP do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo CEP:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].endereco_hospede.cep);
    }
    printf("O bairro atual do hospede é: %s.\n", ramHO[posicao].endereco_hospede.bairro);
    printf("Deseja alterar o bairro do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo bairro:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].endereco_hospede.bairro);
    }
    printf("A rua atual do hospede é: %s.\n", ramHO[posicao].endereco_hospede.rua);
    printf("Deseja alterar a rua do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova rua:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].endereco_hospede.rua);
    }
    printf("O número de endereço atual do hospede é: %d.\n", ramHO[posicao].endereco_hospede.numero);
    printf("Deseja alterar o numero de endereço do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo endereço:");
        scanf("%d", &ramHO[posicao].endereco_hospede.numero);
    }
    printf("-------Dado Pessoais--------\n");
    printf("O CPF atual do hospede é: %s.\n", ramHO[posicao].cpf);
    printf("Deseja alterar o CEP do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo endereço:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].cpf);
    }
    printf("O telefone atual do hospede é: %s.\n", ramHO[posicao].telefone);
    printf("Deseja alterar o telefone do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo telefone:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].telefone);
    }
    printf("O E-mail atual do hospede é: %s.\n", ramHO[posicao].email);
    printf("Deseja alterar o E-mail do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo E-mail:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].email);
    }
    printf("O sexo atual do hospede é: %s.\n", ramHO[posicao].sexo);
    printf("Deseja alterar o sexo do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo sexo:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].sexo);
    }
    printf("O estado civil atual do hospede é: %s.\n", ramHO[posicao].estado_civil);
    printf("Deseja alterar o estado civil do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estado civil:");
        scanf(" %[^\n]s%*c", &ramHO[posicao].estado_civil);
    }
    printf("O dia de nascimento atual do hospede é: %d.\n", ramHO[posicao].data_nacimento.dia);
    printf("Deseja alterar o dia de nascimento do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo dia de nascimento:");
        scanf("%d", &ramHO[posicao].data_nacimento.dia);
    }
    printf("O mes de nascimento atual do hospede é: %d.\n", ramHO[posicao].data_nacimento.mes);
    printf("Deseja alterar o mes de nascimento do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo mes de nascimento:");
        scanf("%d", &ramHO[posicao].data_nacimento.mes);
    }
    printf("O ano de nascimento atual do hospede é: %d.\n", ramHO[posicao].data_nacimento.mes);
    printf("Deseja alterar o ano de nascimento do hospede(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo ano de nascimento:");
        scanf("%d", &ramHO[posicao].data_nacimento.mes);
    }
    atualiza_hospede_txt(quantidade, ramHO);

    menu_gestao_hospedes();
}

void main_deleta_hospede_txt() {
    //variaveis utlizadas deletar hospede
    int quantidade = 0, codigo = 0, contador_erro = 0, posicao = 0, opcao = 0, sair = 0, delete = 0, retorno = 0;

    retorno = arquivo_existe_txt("hospedes.txt");
    if (retorno == 0) {
        printf("Nenhum hospede cadastrado.\n\n");
        menu_gestao_hospedes();
    }

    quantidade = contadorlinhas_txt("hospedes.txt");
    quantidade = quantidade / 16;
    hospedes ramDELHO[quantidade];
    hospedes_ram_txt(ramDELHO, quantidade);

    printf("------Deleção de hospede-------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do hospede que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar o operadores
        posicao = procura_hospede_txt(codigo, quantidade, ramDELHO);
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
            menu_gestao_hospedes();
        }
    } while (posicao == -1);

    printf("------Dados do hospede------\n");
    printf("Codigo: %d.\n", ramDELHO[posicao].codigo);
    printf("Nome: %s.\n", ramDELHO[posicao].nome);
    printf("------Dados de endereço------\n");
    printf("Estado: %s.\n", ramDELHO[posicao].endereco_hospede.estado);
    printf("Cidade: %s.\n", ramDELHO[posicao].endereco_hospede.cidade);
    printf("CEP: %s.\n", ramDELHO[posicao].endereco_hospede.cep);
    printf("Bairro: %s.\n", ramDELHO[posicao].endereco_hospede.bairro);
    printf("Rua: %s.\n", ramDELHO[posicao].endereco_hospede.rua);
    printf("numero: %d.\n", ramDELHO[posicao].endereco_hospede.numero);
    printf("---------Dados pessoais--------\n");
    printf("CPF: %s.\n", ramDELHO[posicao].cpf);
    printf("Telefone: %s.\n", ramDELHO[posicao].telefone);
    printf("E-mail: %s.\n", ramDELHO[posicao].email);
    printf("Sexo: %s.\n", ramDELHO[posicao].sexo);
    printf("Estado Civil: %s.\n", ramDELHO[posicao].estado_civil);
    printf("Data de nascimento:%d/%d/%d.\n", ramDELHO[posicao].data_nacimento.dia, ramDELHO[posicao].data_nacimento.mes, ramDELHO[posicao].data_nacimento.ano);
    printf("Realmente deseja excluir esse hospode:(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        deleta_hospede_txt(quantidade, posicao, ramDELHO);
    }

    menu_gestao_hospedes();
}
//FIM HOSPEDE


//COMEÇO PRODUTO
void main_cadastro_produtos_txt() {
    //variaveis para cadastro de produto
    produtos cadastro_produtos;
    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;

    //verificando se o arquvio de produtos ja existe 
    retorno = arquivo_existe_txt("produtos.txt");


    //se existir trago os dados para ram para verificar se o codigo do hospede é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = contadorlinhas_txt("produtos.txt");
        quantidade = quantidade / 6;
        produtos produtoAT[quantidade];
        produtos_ram_txt(produtoAT, quantidade);

        printf("-------Cadastro de produto--------\n");
        printf("Digite o codigo do produto:");
        scanf("%d", &cadastro_produtos.codigo);
        setbuf(stdin, NULL);

        posicao = procura_produto_txt(cadastro_produtos.codigo, quantidade, produtoAT);
        while (posicao != -1) {
            printf("Esse codigo de produto ja existe digite um diferente:");
            scanf("%d", &cadastro_produtos.codigo);
            posicao = procura_produto_txt(cadastro_produtos.codigo, quantidade, produtoAT);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_produtos();
            }
        }
    } else {
        printf("-------Cadastro de produto--------\n");
        printf("Digite o código do produto:");
        scanf("%d", &cadastro_produtos.codigo);
        setbuf(stdin, NULL);
    }

    printf("Digite a descrição do produto:");
    setbuf(stdin, NULL);
    scanf(" %[^\n]s%*c", cadastro_produtos.descricao);
    setbuf(stdin, NULL);
    printf("Digite o estoque do produto:");
    scanf("%d", &cadastro_produtos.estoque);
    setbuf(stdin, NULL);
    printf("Digite o estoque mínimo do produto:");
    scanf("%d", &cadastro_produtos.estoque_min);
    setbuf(stdin, NULL);
    printf("Digite o preço de custo do produto:");
    scanf("%f", &cadastro_produtos.preco_custo);
    setbuf(stdin, NULL);
    printf("Digite o preço de venda do produto:");
    scanf("%f", &cadastro_produtos.preco_venda);
    setbuf(stdin, NULL);
    cadastro_produtos_txt(cadastro_produtos);
    menu_gestao_produtos();
}

void main_atualiza_produtos_txt() {
    //variaveis utilizadas para atualizar produtos
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0;

    retorno = arquivo_existe_txt("produtos.txt");
    if (retorno == 0) {
        printf("Nenhum produto cadastrado.\n\n");
        menu_gestao_produtos();
    }


    quantidade = contadorlinhas_txt("produtos.txt");
    quantidade = quantidade / 6;
    produtos produtoAT[quantidade];
    produtos_ram_txt(produtoAT, quantidade);

    printf("-------Atualizar produto-------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do produto que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_produto_txt(codigo, quantidade, produtoAT);
        //caso o operadore nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo do produto nao encontrado\n");
            contador_erro++;
        }
        if (contador_erro > 2) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair == 1) {
            menu_gestao_produtos();
            contador_erro = 0;
        }

    } while (posicao == -1);

    printf("O codigo atual do produto é: %d.\n", produtoAT[posicao].codigo);
    printf("Deseja alterar o codigo do produto?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo codigo:");
        scanf("%d", &produtoAT[posicao].codigo);
    }
    printf("A descrição atual do produto é: %s.\n", produtoAT[posicao].descricao);
    printf("Deseja alterar a descrição do produto?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova descrição:");
        scanf(" %[^\n]s%*c", &produtoAT[posicao].descricao);
    }
    printf("O estoque atual do produto é: %d.\n", produtoAT[posicao].estoque);
    printf("Deseja alterar o estoque do produto?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estoque:");
        scanf("%d", &produtoAT[posicao].estoque);
    }
    printf("O estoque minimo atual do produto é: %d.\n", produtoAT[posicao].estoque_min);
    printf("Deseja alterar o estoque minimo do produto?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estoque minimo:");
        scanf("%d", &produtoAT[posicao].estoque_min);
    }
    printf("O preço de custo atual do produto é: %f.\n", produtoAT[posicao].preco_custo);
    printf("Deseja alterar o epreço de custo do produto?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo preço de custo:");
        scanf("%f", &produtoAT[posicao].preco_custo);
    }
    printf("O preço de custo atual do produto é: %f.\n", produtoAT[posicao].preco_venda);
    printf("Deseja alterar o preço de custo do produto?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo preço de custo:");
        scanf("%f", &produtoAT[posicao].preco_venda);
    }
    //funcao para atualizar os dados no arquivo
    atualiza_produto_txt(quantidade, produtoAT);

    menu_gestao_produtos();
}

void main_deleta_produtos_txt() {
    //variaveis utilizadas para atualizar produtos
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0, delete = 0;

    retorno = arquivo_existe_txt("produtos.txt");
    if (retorno == 0) {
        printf("Nenhum produto cadastrado.\n\n");
        menu_gestao_produtos();
    }

    quantidade = contadorlinhas_txt("produtos.txt");
    quantidade = quantidade / 6;
    produtos produtoDEL[quantidade];
    produtos_ram_txt(produtoDEL, quantidade);

    printf("-------Deletar produto-------\n");
    do {
        //pedindo ao usuario o codigo do produto que deseja deletar
        printf("Digite o codigo do produto que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_produto_txt(codigo, quantidade, produtoDEL);
        //caso o produto nao existe o laço se reinicia
        if (posicao == -1) {
            printf("Codigo do produto nao encontrado.\n");
            contador_erro++;
        }
        if (contador_erro > 3) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair == 1) {
            menu_gestao_produtos();
            contador_erro = 0;
        }

    } while (posicao == -1);

    printf("------Dados do Produto------");
    printf("Código:%d\n", produtoDEL[posicao].codigo);
    printf("Descrição:%s\n", produtoDEL[posicao].descricao);
    printf("Estoque:%d\n", produtoDEL[posicao].estoque);
    printf("Estoque mínimo:%d\n", produtoDEL[posicao].estoque_min);
    printf("Preço de custo:%f\n", produtoDEL[posicao].preco_custo);
    printf("Preço de venda:%f\n", produtoDEL[posicao].preco_venda);
    printf("Realmente deseja excluir esse produto:(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        deleta_produto_txt(quantidade, posicao, produtoDEL);
    }

    menu_gestao_produtos();
}
//FIM PRODUTO


//COMEÇO FORNECEDOR
void main_cadastro_fornecedor_txt() {
    //variveis utilizadas para cadastrar fornecedor
    fornecedores cadastro_fornecedor;
    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;
    
    //verificando se o arquvio de fornecedores ja existe 
    retorno = arquivo_existe_txt("fornecedores.txt");


    //se existir trago os dados para ram para verificar se o codigo do fornecedor é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = contadorlinhas_txt("fornecedores.txt");
        quantidade = quantidade / 13;
        fornecedores fornecedorAT[quantidade];
        fornecedores_ram_txt(fornecedorAT, quantidade);

        printf("-------CADASTRO DE FORNECEDORES-------\n");
        printf("Digite o codigo do fornecedor:");
        scanf("%d", &cadastro_fornecedor.codigo);

        posicao = procura_fornecedor_txt(cadastro_fornecedor.codigo, quantidade, fornecedorAT);
        while (posicao != -1) {
            printf("Esse codigo de fornecedor ja existe digite um diferente:");
            scanf("%d", &cadastro_fornecedor.codigo);
            posicao = procura_fornecedor_txt(cadastro_fornecedor.codigo, quantidade, fornecedorAT);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_fornecedor();
            }
        }
    } else {
        printf("-------CADASTRO DE FORNECEDORES-------\n");
        printf("Digite o codigo do fornecedor:");
        scanf("%d", &cadastro_fornecedor.codigo);
    }

    printf("Digite o nome fantasia:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.nome_fantasia);
    setbuf(stdin, NULL);
    printf("Digite a razão social:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.razao_social);
    setbuf(stdin, NULL);
    printf("Digite a inscrição estadual:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.inscricao_estadual);
    setbuf(stdin, NULL);
    printf("Digite o CNPJ:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.cnpj);
    setbuf(stdin, NULL);
    printf("-------ENDEREÇO-------\n");
    printf("Digite o estado:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.endereco.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.endereco.cidade);
    setbuf(stdin, NULL);
    printf("Digite o CEP:");
    scanf(" %[^\n]s%*c", &cadastro_fornecedor.endereco.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.endereco.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.endereco.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero:");
    scanf("%d", &cadastro_fornecedor.endereco.numero);
    setbuf(stdin, NULL);
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Digite o telefone do fornecedor:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do fornecedor:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.email);
    setbuf(stdin, NULL);
    cadastro_fornecedor_txt(cadastro_fornecedor);
     /*
    cadastro_fornecedor.codigo = 1;
    strcpy(cadastro_fornecedor.nome_fantasia, "Fornecedor XYZ");
    strcpy(cadastro_fornecedor.razao_social, "Razao Social XYZ");
    strcpy(cadastro_fornecedor.inscricao_estadual, "123456");
    strcpy(cadastro_fornecedor.cnpj, "987654");
    strcpy(cadastro_fornecedor.endereco.estado, "Estado XYZ");
    strcpy(cadastro_fornecedor.endereco.cidade, "Cidade XYZ");
    strcpy(cadastro_fornecedor.endereco.cep, "12345-678");
    strcpy(cadastro_fornecedor.endereco.bairro, "Bairro XYZ");
    strcpy(cadastro_fornecedor.endereco.rua, "Rua XYZ");
    cadastro_fornecedor.endereco.numero = 123;
    strcpy(cadastro_fornecedor.telefone, "123-456-7890");
    strcpy(cadastro_fornecedor.email, "fornecedor_xyz@example.com");
    cadastro_fornecedor_txt(cadastro_fornecedor);
    
    
    cadastro_fornecedor.codigo = 2;
    strcpy(cadastro_fornecedor.nome_fantasia, "Fornecedor ABC");
    strcpy(cadastro_fornecedor.razao_social, "Razao Social ABC");
    strcpy(cadastro_fornecedor.inscricao_estadual, "654321");
    strcpy(cadastro_fornecedor.cnpj, "123789");
    strcpy(cadastro_fornecedor.endereco.estado, "Estado ABC");
    strcpy(cadastro_fornecedor.endereco.cidade, "Cidade ABC");
    strcpy(cadastro_fornecedor.endereco.cep, "54321-876");
    strcpy(cadastro_fornecedor.endereco.bairro, "Bairro ABC");
    strcpy(cadastro_fornecedor.endereco.rua, "Rua ABC");
    cadastro_fornecedor.endereco.numero = 456;
    strcpy(cadastro_fornecedor.telefone, "987-654-3210");
    strcpy(cadastro_fornecedor.email, "fornecedor_abc@example.com");
    cadastro_fornecedor_txt(cadastro_fornecedor);
    
    
    
    cadastro_fornecedor.codigo = 4;
    strcpy(cadastro_fornecedor.nome_fantasia, "JKL Distribuidora");
    strcpy(cadastro_fornecedor.razao_social, "JKL Comércio de Produtos Ltda.");
    strcpy(cadastro_fornecedor.inscricao_estadual, "789012");
    strcpy(cadastro_fornecedor.cnpj, "01234567890123");
    strcpy(cadastro_fornecedor.endereco.estado, "Estado JKL");
    strcpy(cadastro_fornecedor.endereco.cidade, "Cidade JKL");
    strcpy(cadastro_fornecedor.endereco.cep, "67890-123");
    strcpy(cadastro_fornecedor.endereco.bairro, "Bairro JKL");
    strcpy(cadastro_fornecedor.endereco.rua, "Rua JKL");
    cadastro_fornecedor.endereco.numero = 789;
    strcpy(cadastro_fornecedor.telefone, "777-456-1230");
    strcpy(cadastro_fornecedor.email, "contato@jkl.com");
    cadastro_fornecedor_txt(cadastro_fornecedor);
    */
    menu_gestao_fornecedor();
}

void main_atualiza_fornecedor_txt() {
    //variaveis utilizadas para atualizar forncedor
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0;


    retorno = arquivo_existe_txt("fornecedores.txt");
    if (retorno == 0) {
        printf("Nenhum fornecedor cadastrado.\n\n");
        menu_gestao_fornecedor();
    }



    quantidade = contadorlinhas_txt("fornecedores.txt");
    quantidade = quantidade / 13;
    fornecedores fornecedorAT[quantidade];
    fornecedores_ram_txt(fornecedorAT, quantidade);

    printf("-------Atualizar fornecedor-------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do fornecedor que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_fornecedor_txt(codigo, quantidade, fornecedorAT);
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
            menu_gestao_fornecedor();

        }

    } while (posicao == -1);

    printf("O codigo atual do fornecedor é: %d.\n", fornecedorAT[posicao].codigo);
    printf("Deseja alterar o codigo do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo codigo:");
        scanf("%d", &fornecedorAT[posicao].codigo);
    }
    printf("O nome fantasia atual do fornecedor é: %s.\n", fornecedorAT[posicao].nome_fantasia);
    printf("Deseja alterar o nome fantasia do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo nome fantasia:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].nome_fantasia);
    }
    printf("A razão social atual do fornecedor é: %s.\n", fornecedorAT[posicao].razao_social);
    printf("Deseja alterar a razão social do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova razão social:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].razao_social);
    }
    printf("A inscrição estadual atual do fornecedor é: %s.\n", fornecedorAT[posicao].inscricao_estadual);
    printf("Deseja alterar a inscrição estadual do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova inscrição estadual:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].inscricao_estadual);
    }
    printf("O CNPJ atual do fornecedor é: %s.\n", fornecedorAT[posicao].cnpj);
    printf("Deseja alterar o CNPJ do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo CNPJ:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].cnpj);
    }
    printf("--------------Dados de Endereço--------------\n");
    printf("O estado atual do fornecedor é: %s.\n", fornecedorAT[posicao].endereco.estado);
    printf("Deseja alterar o estado do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo estado:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].endereco.estado);
    }
    printf("A cidade atual do fornecedor é: %s.\n", fornecedorAT[posicao].endereco.cidade);
    printf("Deseja alterar a cidade do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova cidade:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].endereco.cidade);
    }
    printf("O CEP atual do fornecedor é: %s.\n", fornecedorAT[posicao].endereco.cep);
    printf("Deseja alterar o CEP do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo CEP:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].endereco.cep);
    }
    printf("O bairro atual do fornecedor é: %s.\n", fornecedorAT[posicao].endereco.bairro);
    printf("Deseja alterar o bairro do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo bairro:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].endereco.bairro);
    }
    printf("A rua atual do fornecedor é: %s.\n", fornecedorAT[posicao].endereco.cidade);
    printf("Deseja alterar a rua do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova rua:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].endereco.cidade);
    }
    printf("O número de endereço atual do fornecedor é: %d.\n", fornecedorAT[posicao].endereco.numero);
    printf("Deseja alterar o número de endereço do fornecedorAT?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo número de endereço:");
        scanf("%d", &fornecedorAT[posicao].endereco.numero);
    }
    printf("--------------Dados para contato--------------\n");
    printf("O telefone atual do fornecedor é: %s.\n", fornecedorAT[posicao].telefone);
    printf("Deseja alterar o telefone do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo telefone:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].telefone);
    }
    printf("O E-mail atual do fornecedor é: %s.\n", fornecedorAT[posicao].email);
    printf("Deseja alterar o E-mail do fornecedor?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo E-mail:");
        scanf(" %[^\n]s%*c", fornecedorAT[posicao].email);
    }
    atualiza_fornecedor_txt(quantidade, fornecedorAT);

    menu_gestao_fornecedor();
}

void main_deleta_fornecedor_txt() {
    //varivaeis utilizadas para deletar fornecedor
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0, delete = 0;

    retorno = arquivo_existe_txt("fornecedores.txt");
    if (retorno == 0) {
        printf("Nenhum fornecedor cadastrado.\n\n");
        menu_gestao_produtos();
    }


    quantidade = contadorlinhas_txt("fornecedores.txt");
    quantidade = quantidade / 13;
    fornecedores fornecedorDEL[quantidade];
    fornecedores_ram_txt(fornecedorDEL, quantidade);

    printf("-------Deletar fornecedor-------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo do fornecedor que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_fornecedor_txt(codigo, quantidade, fornecedorDEL);
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
            menu_gestao_fornecedor();
        }

    } while (posicao == -1);
    printf("--------Dados do fornecedor---------\n");
    printf("Código: %d.\n", fornecedorDEL[posicao].codigo);
    printf("Nome fantasia: %s.\n", fornecedorDEL[posicao].nome_fantasia);
    printf("Razão social: %s.\n", fornecedorDEL[posicao].razao_social);
    printf("Inscrição estadual: %s.\n", fornecedorDEL[posicao].inscricao_estadual);
    printf("CNPJ: %s.\n", fornecedorDEL[posicao].cnpj);
    printf("--------Endereço---------\n");
    printf("Estado: %s.\n", fornecedorDEL[posicao].endereco.estado);
    printf("Cidade: %s.\n", fornecedorDEL[posicao].endereco.cidade);
    printf("CEP: %s.\n", fornecedorDEL[posicao].endereco.cep);
    printf("Bairro: %s.\n", fornecedorDEL[posicao].endereco.bairro);
    printf("Rua: %s.\n", fornecedorDEL[posicao].endereco.rua);
    printf("Número: %d.\n", fornecedorDEL[posicao].endereco.numero);
    printf("--------Contato---------\n");
    printf("Número: %s.\n", fornecedorDEL[posicao].telefone);
    printf("E-mail: %s.\n", fornecedorDEL[posicao].email);
    printf("Realmente deseja excluir esse fornecedor?(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        deleta_fornecedor_txt(quantidade, posicao, fornecedorDEL);
    }

    menu_gestao_fornecedor();
}
//FIM FORNECEDOR


//COMEÇO CATEGORIA
void main_cadastro_categoria_txt() {
    //variaveis para cadastro de categorias de acomodações
    categoria_acomodacao cadastro_categoria;

    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;

    //verificando se o arquvio de fornecedores ja existe 
    retorno = arquivo_existe_txt("categorias.txt");


    //se existir trago os dados para ram para verificar se o codigo do fornecedor é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = contadorlinhas_txt("categorias.txt");
        quantidade = quantidade / 5;
        categoria_acomodacao categoriaAT[quantidade];
        categorias_ram_txt(categoriaAT, quantidade);

        printf("-----Cadastro de categorias de acomodações-------\n");
        printf("Digite o codigo da categoria:");
        scanf("%d", &cadastro_categoria.codigo);

        posicao = procura_categoria_txt(cadastro_categoria.codigo, quantidade, categoriaAT);
        while (posicao != -1) {
            printf("Esse codigo de categoria ja existe digite um diferente:");
            scanf("%d", &cadastro_categoria.codigo);
            posicao = procura_categoria_txt(cadastro_categoria.codigo, quantidade, categoriaAT);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_categoria();
            }
        }
    } else {
        printf("-----Cadastro de categorias de acomodações-------\n");
        printf("Digite o codigo da categoria:");
        scanf("%d", &cadastro_categoria.codigo);
    }



    printf("Digite a descrição da categoria(Exemplo:Standard,Luxo,Presidencial):");
    scanf(" %[^\n]s%*c", cadastro_categoria.descricao);
    printf("Digite o valor da diária:");
    scanf("%f", &cadastro_categoria.valor_diaria);
    printf("Quantidade de pessoas que comporta.\n");
    printf("Adultos:");
    scanf("%d", &cadastro_categoria.adultos);
    printf("Crianças:");
    scanf("%d", &cadastro_categoria.criancas);
    cadastro_categoria_txt(cadastro_categoria);
    menu_gestao_categoria();
}

void main_atualiza_categoria_txt() {
    //variaveis para atualizar dados de categorias de acomodações
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0;

    retorno = arquivo_existe_txt("categorias.txt");
    if (retorno == 0) {
        printf("Nenhuma categoria cadastrada.\n\n");
        menu_gestao_categoria();
    }


    quantidade = contadorlinhas_txt("categorias.txt");
    quantidade = quantidade / 5;
    categoria_acomodacao categoriaAT[quantidade];
    categorias_ram_txt(categoriaAT, quantidade);

    printf("--------Atualizar categoria de acomação----------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo da categoria que deseja alterar:");
        scanf("%d", &codigo);

        //funcao para procurar o produto
        posicao = procura_categoria_txt(codigo, quantidade, categoriaAT);
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
    printf("O codigo atual da categoria é: %d.\n", categoriaAT[posicao].codigo);
    printf("Deseja alterar o codigo da categoria?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo codigo:");
        scanf("%d", &categoriaAT[posicao].codigo);
    }
    printf("A descrição atual da categoria é: %s.\n", categoriaAT[posicao].descricao);
    printf("Deseja alterar a descrição da categoria?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova descrição:");
        scanf(" %[^\n]s%*c", categoriaAT[posicao].descricao);
    }
    printf("O valor da diária atual da categoria é: %f.\n", categoriaAT[posicao].valor_diaria);
    printf("Deseja alterar o valor da diária da categoria?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo valor da diária:");
        scanf("%f", &categoriaAT[posicao].valor_diaria);
    }
    printf("Essa categoria atualmente comporta %d adultos e %d crianças.\n", categoriaAT[posicao].adultos, categoriaAT[posicao].criancas);
    printf("Deseja alterar a quantidade de pessoas comportadas pela categoria?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova quantidade de adultos comportado:");
        scanf("%d", &categoriaAT[posicao].adultos);
        printf("Digite a nova quantidade de crianças comportado:");
        scanf("%d", &categoriaAT[posicao].criancas);
    }
    atualiza_categoria_txt(quantidade, categoriaAT);

    menu_gestao_categoria();
}

void main_deleta_categoria_txt() {
    //variaveis para deletar categorias de acomodações
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0, delete = 0;

    retorno = arquivo_existe_txt("categorias.txt");
    if (retorno == 0) {
        printf("Nenhuma categoria cadastrado.\n\n");
        menu_gestao_produtos();
    }

    quantidade = contadorlinhas_txt("categorias.txt");
    quantidade = quantidade / 5;
    categoria_acomodacao categoriaDEL[quantidade];
    categorias_ram_txt(categoriaDEL, quantidade);

    printf("--------Deletar categoria de acomação----------\n");
    do {
        //pedindo ao usuario o codigo da categoria que deseja alterar
        printf("Digite o codigo da categoria que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar a categoria
        posicao = procura_categoria_txt(codigo, quantidade, categoriaDEL);
        //caso a categoria nao existe o laço se reinicia
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

    printf("---------Dados da categoria---------\n");
    printf("Código: %d\n", categoriaDEL[posicao].codigo);
    printf("Descrição: %s\n", categoriaDEL[posicao].descricao);
    printf("Valor da diária: %.2f\n", categoriaDEL[posicao].valor_diaria);
    printf("Adultos comportados: %d\n", categoriaDEL[posicao].adultos);
    printf("Crianças comportadas: %d\n", categoriaDEL[posicao].criancas);
    printf("Realmente deseja deletar essa categoria?(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        deleta_categoria_txt(quantidade, posicao, categoriaDEL);
    }

    menu_gestao_categoria();
}
//FIM CATEGORIA


//COMEÇO ACOMODACAO
void main_cadastro_acomodacao_txt() {
    //variaveis para cadastro de acomodações
    int qtd_aco = 0, retorno = 0, quantidade = 0, existe = 0, contador_erro = 0, sair = 0, posicao = 0;
    acomodacoes cadastro_acomodacoes;

    //verificando se o arquvio de fornecedores ja existe 
    retorno = arquivo_existe_txt("acomodacoes.txt");


    //se existir trago os dados para ram para verificar se o codigo do fornecedor é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        qtd_aco = contadorlinhas_txt("acomodacoes.txt");
        qtd_aco = qtd_aco / 7;
        acomodacoes acomodacoesAT[qtd_aco];
        acomodacoes_ram_txt(acomodacoesAT, qtd_aco);

        printf("-----Cadastro de acomodações-------\n");
        printf("Digite o codigo da acomodação:");
        scanf("%d", &cadastro_acomodacoes.codigo);

        posicao = procura_acomodacao_txt(cadastro_acomodacoes.codigo, qtd_aco, acomodacoesAT);
        while (posicao != -1) {
            printf("Esse codigo de acomodação ja existe digite um diferente:");
            scanf("%d", &cadastro_acomodacoes.codigo);
            posicao = procura_acomodacao_txt(cadastro_acomodacoes.codigo, qtd_aco, acomodacoesAT);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_acomodacao();
            }
        }
    } else {
        printf("-----Cadastro de acomodações-------\n");
        printf("Digite o codigo da acomodação:");
        scanf("%d", &cadastro_acomodacoes.codigo);
    }


    printf("Digite a descrição da acomodação:");
    scanf(" %[^\n]s%*c", cadastro_acomodacoes.descricao);
    printf("Digite as facilidades da acomodação.\n"
            "Coloque uma virgula após cada facilidade\n"
            "(Ex:Ar condiciona,TV,Cama King Size):");
    scanf(" %[^\n]s%*c", cadastro_acomodacoes.facilidades);
    printf("Digite o codigo de categoria da acomodação:");
    scanf("%d", &cadastro_acomodacoes.categoria);
    quantidade = contadorlinhas_txt("categorias.txt");
    quantidade = quantidade / 5;
    categoria_acomodacao categoriaEXI[quantidade];
    categorias_ram_txt(categoriaEXI, quantidade);

    existe = procura_categoria_txt(cadastro_acomodacoes.categoria, quantidade, categoriaEXI);
    while (existe == -1) {
        printf("Essa categoria não existe digite uma existente:");
        scanf("%d", &cadastro_acomodacoes.categoria);

        existe = procura_categoria_txt(cadastro_acomodacoes.categoria, quantidade, categoriaEXI);
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
        cadastro_acomodacoes.ocupacao = 0;
        cadastro_acomodacoes.lucro = 0;
        cadastro_acomodacoes.diarias = 0;
        cadastro_acomodacoes_txt(cadastro_acomodacoes);

        contador_erro = 0;
    }
    menu_gestao_acomodacao();
}

void main_atualiza_acomodacao_txt() {
    //variaveis para atualizar acomodações
    int retorno = 0, sair = 0, qtd_aco = 0, qtd_cat = 0, codigo = 0, posicao = 0, contador_erro = 0, opcao = 0, existe = 0;

    retorno = arquivo_existe_txt("acomodacoes.txt");
    if (retorno == 0) {
        printf("Nenhuma acomodacao cadastrado.\n\n");
        menu_gestao_acomodacao();
    }

    qtd_aco = contadorlinhas_txt("acomodacoes.txt");
    qtd_aco = qtd_aco / 7;
    acomodacoes acomodacoesAT[qtd_aco];
    acomodacoes_ram_txt(acomodacoesAT, qtd_aco);

    qtd_cat = contadorlinhas_txt("categorias.txt");
    qtd_cat = qtd_cat / 5;
    categoria_acomodacao categoriaEXI[qtd_cat];
    categorias_ram_txt(categoriaEXI, qtd_cat);

    printf("--------Atualizar acomodação----------\n");
    do {
        //pedindo ao usuario o codigo do operadores que deseja alterar
        printf("Digite o codigo da acomodação que deseja alterar:");
        scanf("%d", &codigo);

        //funcao procura acomodacao
        posicao = procura_acomodacao_txt(codigo, qtd_aco, acomodacoesAT);

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
            menu_gestao_acomodacao();

        }

    } while (posicao == -1);

    printf("O codigo atual da acomodação é: %d.\n", acomodacoesAT[posicao].codigo);
    printf("Deseja alterar o codigo da acomodação?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo codigo:");
        scanf("%d", &acomodacoesAT[posicao].codigo);
    }
    printf("A descrição atual da acomodação é: %s.\n", acomodacoesAT[posicao].descricao);
    printf("Deseja alterar a descrição da acomodação?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite a nova descrição:");
        scanf(" %[^\n]s%*c", acomodacoesAT[posicao].descricao);
    }
    printf("As facilidades atuais da acomodação é: %s.\n", acomodacoesAT[posicao].facilidades);
    printf("Deseja alterar as facilidades da acomodação?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite as novas facilidades(Lembre de a cada facilidade colocar um virgula e digitar a proxima)\n"
                "(Ex:Ar-condiciona,TV,Cama King Size):");
        scanf(" %[^\n]s%*c", acomodacoesAT[posicao].facilidades);
    }
    printf("O codigo da categoria da acomodação é: %d.\n", acomodacoesAT[posicao].categoria);
    printf("Deseja alterar o codigo da categoria da acomodação?(1-Sim/0-Não):");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Digite o novo codigo da categoria:");
        scanf("%d", &acomodacoesAT[posicao].categoria);
        sair = 0;


        existe = procura_categoria_txt(acomodacoesAT[posicao].categoria, qtd_cat, categoriaEXI);
        while (existe == -1) {
            printf("Essa categoria não existe digite uma existente:");
            scanf("%d", &acomodacoesAT[posicao].categoria);
            existe = procura_categoria_txt(acomodacoesAT[posicao].categoria, qtd_cat, categoriaEXI);
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
        atualiza_acomodacoes_txt(qtd_aco, acomodacoesAT);
        contador_erro = 0;
    }


    menu_gestao_acomodacao();
}

void main_deleta_acomodacao_txt() {
    //variaveis para deletar acomodações
    int retorno = 0, sair = 0, quantidade = 0, codigo = 0, posicao = 0, contador_erro = 0, delete = 0;

    retorno = arquivo_existe_txt("acomodacoes.txt");
    if (retorno == 0) {
        printf("Nenhuma acomodacao cadastrada.\n\n");
        menu_gestao_acomodacao();
    }

    quantidade = contadorlinhas_txt("acomodacoes.txt");
    quantidade = quantidade / 7;
    acomodacoes acomodacaoDEL[quantidade];
    acomodacoes_ram_txt(acomodacaoDEL, quantidade);

    printf("--------Deletar  acomodação----------\n");
    do {
        //pedindo ao usuario o codigo da categoria que deseja alterar
        printf("Digite o codigo da acomodação que deseja deletar:");
        scanf("%d", &codigo);

        //funcao para procurar a categoria
        posicao = procura_acomodacao_txt(codigo, quantidade, acomodacaoDEL);
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
            menu_gestao_acomodacao();
        }

    } while (posicao == -1);

    printf("---------Dados da acomadação---------\n");
    printf("Código: %d\n", acomodacaoDEL[posicao].codigo);
    printf("Descrição: %s\n", acomodacaoDEL[posicao].descricao);
    printf("Facilidades: %s\n", acomodacaoDEL[posicao].facilidades);
    printf("Codigo da categoria: %d\n", acomodacaoDEL[posicao].categoria);
    printf("Realmente deseja deletar essa acomodação?(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        deleta_acomodacoes_txt(quantidade, posicao, acomodacaoDEL);
    }

    menu_gestao_acomodacao();
}
//FIM ACOMODACAO


//COMEÇO RESERVA
//FILTROS DE RESERVAS
void main_filtros_txt() {
    //variaveis utilizadas para fazer reservas
    data_chek_in_out datas;

    int qtd_cat, qtd_aco, qtd_res, qtd_dis, qtd_hos, data_filtro, pessoas_filtro;
    int categoria_filtro, facilidades_filtro, ret_data, contador_erro = 0, sair = 0;
    int cod_cat, pos_cat, retorno, criancas, adultos, cod_aco, pos_aco, ret_reserva;
    int cod_hos, pos_hos, pos_res, cod_res;

    char facilidade[20];

    //trazendo acomodacoes para ram
    qtd_aco = contadorlinhas_txt("acomodacoes.txt");
    qtd_aco = qtd_aco / 7;
    acomodacoes acomodacaoRAM[qtd_aco];
    acomodacoes_ram_txt(acomodacaoRAM, qtd_aco);


    //pegando todos dados que serao utilizados do txt para memoria ram
    qtd_res = contadorlinhas_txt("reservas.txt");
    qtd_res = qtd_res / 16;
    qtd_dis = qtd_aco + qtd_res;
    //trazendo reservas para ram
    reservas reservasRAM[qtd_res];
    reservas_ram_txt(qtd_res, reservasRAM);
    reservas disponiveis[qtd_dis];



    //trazendo hospedes para ram
    qtd_hos = contadorlinhas_txt("hospedes.txt");
    qtd_hos = qtd_hos / 16;
    hospedes hospedesRES[qtd_hos];
    hospedes_ram_txt(hospedesRES, qtd_hos);

    //trazendo categorias para ram
    qtd_cat = contadorlinhas_txt("categorias.txt");
    qtd_cat = qtd_cat / 5;
    categoria_acomodacao categoriaRAM[qtd_cat];
    categorias_ram_txt(categoriaRAM, qtd_cat);

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
                menu_modulo_reservas();
            }
        }
        printf("------Quartos Disponiveis------\n");

        qtd_dis = data_disponivel_txt(disponiveis, reservasRAM, acomodacaoRAM, qtd_res, qtd_aco, datas, categoriaRAM, qtd_cat);
        if (qtd_dis == 0) {
            menu_modulo_reservas();
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
            printa_categoria_txt(qtd_cat, categoriaRAM);
            printf("Digite o codigo de uma dessas categorias:");
            scanf("%d", &cod_cat);
            //verifica se o codigo da categoria é valido
            pos_cat = procura_categoria_txt(cod_cat, qtd_cat, categoriaRAM);

            //se nao for entra em um loop
            while (pos_cat == -1) {
                contador_erro++;
                printf("Digite uma categoria válida:");
                scanf("%d", &cod_cat);
                pos_cat = procura_categoria_txt(cod_cat, qtd_cat, categoriaRAM);
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair == 1) {
                    contador_erro = 0;
                    menu_modulo_reservas();
                }
            }

            printf("\tAcomodações disponíveis com a categoria digitada.\n\n");
            qtd_dis = categoria_disponivel_txt(cod_cat, qtd_aco, acomodacaoRAM, categoriaRAM, pos_cat, disponiveis);
            if (qtd_dis == -1) {
                menu_modulo_reservas();
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
                    menu_modulo_reservas();
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
            qtd_dis = pessoas_disponivel_txt(criancas, adultos, qtd_cat, qtd_aco, categoriaRAM, acomodacaoRAM, disponiveis);
            if (qtd_dis == -1) {
                menu_modulo_reservas();
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
                    menu_modulo_reservas();
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
            qtd_dis = facilidades_disponiveis_txt(facilidade, acomodacaoRAM, qtd_aco, disponiveis, categoriaRAM, qtd_cat);
            if (qtd_dis == -1) {
                menu_modulo_reservas();
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
                    menu_modulo_reservas();
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
        pos_aco = procura_acomodacao_disponivel(qtd_dis, cod_aco, disponiveis, acomodacaoRAM, qtd_aco);
        while (pos_aco == -1) {
            contador_erro++;
            printf("Esse codigo de acomodação não está disponível digite um válido::");
            scanf("%d", &cod_aco);
            pos_aco = procura_acomodacao_disponivel(qtd_dis, cod_aco, disponiveis, acomodacaoRAM, qtd_aco);
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas();
            }
        }
        if (data_filtro == 0) {
            if (acomodacaoRAM[pos_aco].ocupacao == 0) {
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
                        menu_modulo_reservas();
                    }
                }
            } else {
                printf("Essa acomodação não esta disponivel nessas datas,lembrando que uma dessas datas é a da própria reserva que esta sendo atualizada.\n");
                procura_data_reserva_txt(qtd_res, cod_aco, reservasRAM);
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
                        menu_modulo_reservas();
                    }
                }
                //verifico se a data que o usuario digitou nao bate com nenhuma outra
                ret_reserva = verifica_data_txt(qtd_res, reservasRAM, datas, cod_aco);
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
                            menu_modulo_reservas();
                        }
                    }
                    contador_erro++;
                    ret_reserva = verifica_data_txt(qtd_res, reservasRAM, datas, cod_aco);
                    if (contador_erro > 2) {
                        printf("Voce digitou varias datas que ja estao ocupadas deseja sair?(1-Sim/0-Não):");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }
                    if (sair != 0) {
                        contador_erro = 0;
                        menu_modulo_reservas();
                    }
                }
            }
        }


        printf("Digite um codigo para a reserva:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
        while (pos_res != -1) {
            contador_erro++;
            printf("Esse codigo de reserva ja esta em uso digite um valido:");
            scanf("%d", &cod_res);
            pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas();
            }
        }

        printf("Digite o codigo do hospede que deseja fazer a reserva:");
        scanf("%d", &cod_hos);
        pos_hos = procura_hospede_txt(cod_hos, qtd_hos, hospedesRES);
        while (pos_hos == -1) {
            contador_erro++;
            printf("Digite um codigo de hospede valido:");
            scanf("%d", &cod_hos);
            pos_hos = procura_hospede_txt(cod_hos, qtd_hos, hospedesRES);
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas();
            }
        }
        int dias;
        float valor;
        dias=contarDias(datas);
        
        pos_cat=procura_categoria_txt(acomodacaoRAM[pos_aco].categoria,qtd_cat,categoriaRAM);
        valor=categoriaRAM[pos_cat].valor_diaria*dias;
        
        
        acomodacaoRAM[pos_aco].ocupacao++;
        acomodacaoRAM[pos_aco].lucro+=valor;
        acomodacaoRAM[pos_aco].diarias+=dias;
        
        
        atualiza_acomodacoes_txt(qtd_aco, acomodacaoRAM);
        
        
        cadastro_reservas_txt(acomodacaoRAM, categoriaRAM, pos_aco, qtd_cat, datas, cod_hos, cod_res);
        
        menu_modulo_reservas();
    }
    menu_modulo_reservas();

}

//funcao para canelar reserva
void main_deleta_reserva_txt() {
    //variaveis para deletar reserva
    int retorno = 0, sair = 0, qtd_aco = 0, qtd_res = 0, codigo = 0, pos_res = 0, contador_erro = 0, delete = 0, pos_aco = 0;
    int qtd_cat,pos_cat;
    retorno = arquivo_existe_txt("reservas.txt");
    if (retorno == 0) {
        printf("Nenhuma reserva cadastrada.\n\n");
        menu_modulo_reservas();
    }

    qtd_aco = contadorlinhas_txt("acomodacoes.txt");
    qtd_aco = qtd_aco / 7;
    acomodacoes acomodacaoDEL[qtd_aco];
    acomodacoes_ram_txt(acomodacaoDEL, qtd_aco);

    qtd_res = contadorlinhas_txt("reservas.txt");
    qtd_res = qtd_res / 16;
    reservas reservasRAM[qtd_res];
    reservas_ram_txt(qtd_res, reservasRAM);

    qtd_cat = contadorlinhas_txt("categorias.txt");
    qtd_cat = qtd_cat / 5;
    categoria_acomodacao categoriaRAM[qtd_cat];
    categorias_ram_txt(categoriaRAM, qtd_cat);
    
    printf("--------Cancelar reservas----------\n");
    printf("Digite o codigo da reserva que deseja cancelar:");
    scanf("%d", &codigo);
    pos_res = procura_reserva_txt(codigo, qtd_res, reservasRAM);
    while (pos_res == -1) {
        //pedindo ao usuario o codigo da reserva que deseja alterar
        printf("Digite um codigo de reserva válido:");
        scanf("%d", &codigo);

        //funcao para procurar a reserva
        pos_res = procura_reserva_txt(codigo, qtd_res, reservasRAM);

        if (contador_erro > 3) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_modulo_reservas();
        }

    }

    printf("---------Dados da reserva---------\n");
    printf("Código da reserva:%d\n", reservasRAM[pos_res].codigo_res);
    printf("Codigo do quarto:%d\n", reservasRAM[pos_res].codigo_aco);
    printf("Descrição do quarto:%s\n", reservasRAM[pos_res].descricao);
    printf("Facilidades do quarto:%s\n", reservasRAM[pos_res].facilidades);
    printf("Codigo da categoria:%d\n", reservasRAM[pos_res].categoria.codigo);
    printf("Descrição da categoria:%s\n", reservasRAM[pos_res].descricao);
    printf("Valor da diária da categoria:%f\n", reservasRAM[pos_res].categoria.valor_diaria);
    printf("Crianças comportadas:%d\n", reservasRAM[pos_res].categoria.criancas);
    printf("Adultos comportadas:%d\n", reservasRAM[pos_res].categoria.adultos);
    printf("Data do check-in:%d/%d/%d\n", reservasRAM[pos_res].datas.dia_in, reservasRAM[pos_res].datas.mes_in, reservasRAM[pos_res].datas.ano_in);
    printf("Data do check-out:%d/%d/%d\n", reservasRAM[pos_res].datas.dia_out, reservasRAM[pos_res].datas.mes_out, reservasRAM[pos_res].datas.ano_out);
    printf("Código do hóspede:%d\n\n", reservasRAM[pos_res].cod_hospede);
    pos_aco = procura_acomodacao_txt(reservasRAM[pos_res].codigo_aco, qtd_aco, acomodacaoDEL);
    printf("Realmente deseja cancelar essa reserva?(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
        int dias;
        float valor;
        pos_cat=procura_categoria_txt(reservasRAM[pos_res].categoria.codigo,qtd_cat,categoriaRAM);
        dias=contarDias(reservasRAM[pos_res].datas);
        valor=dias*categoriaRAM[pos_cat].valor_diaria;
        
        
        acomodacaoDEL[pos_aco].ocupacao--;
        acomodacaoDEL[pos_aco].diarias-=dias;
        acomodacaoDEL[pos_aco].lucro-=valor;
        atualiza_acomodacoes_txt(qtd_aco, acomodacaoDEL);
        
        deleta_reserva_txt(qtd_res, pos_res, reservasRAM);
    }

    menu_modulo_reservas();
}

void main_chekin_txt() {
    int cod_res, qtd_res, pos_res, sair=0, contador_erro = 0, opcao, pagamento, dias;
    float valor;

    data date;
    data_chek_in_out datas;

    conta_hospede conta;
    qtd_res = contadorlinhas_txt("reservas.txt");
    qtd_res = qtd_res / 16;
    reservas reservasRAM[qtd_res];
    reservas_ram_txt(qtd_res, reservasRAM);

    printf("------CHECK-IN--------\n");
    printf("Digite o código da reserva para fazer o check-in:");
    scanf("%d", &cod_res);
    pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes();
        }
    }
    //aqui eu trago a data de reserva para calcular quantos dias o hospede vai ficar no hotel
    datas.ano_in = reservasRAM[pos_res].datas.ano_in;
    datas.mes_in = reservasRAM[pos_res].datas.mes_in;
    datas.dia_in = reservasRAM[pos_res].datas.dia_in;
    datas.ano_out = reservasRAM[pos_res].datas.ano_out;
    datas.mes_out = reservasRAM[pos_res].datas.mes_out;
    datas.dia_out = reservasRAM[pos_res].datas.dia_out;

    //contando a diferenca de dias entre as datas
    dias = contarDias(datas);
    //calculando o valor da diaria
    valor = dias * reservasRAM[pos_res].categoria.valor_diaria;

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

            //salvando no caixa  o valor pago pelo hospede
            adicionar_caixa_txt(valor, reservasRAM[pos_res].cod_hospede, 0);

            conta.codigo_hos = reservasRAM[pos_res].cod_hospede;
            conta.codigo_res = reservasRAM[pos_res].codigo_res;
            conta.valor_devido = 0;
            //criando a conta do hospede para se ele for comprar algo
            cadastro_conta_txt(conta);
        } else if (pagamento == 2 || pagamento == 3) {
            printf("Digite a data do vencimento do cartão do hóspede.\n");
            printf("Dia:");
            scanf("%d", &date.dia);
            printf("Mês:");
            scanf("%d", &date.mes);
            printf("Ano:");
            scanf("%d", &date.ano);
            adicionar_contas_a_receber_txt(date, reservasRAM[pos_res].cod_hospede, valor);
            conta.codigo_hos = reservasRAM[pos_res].cod_hospede;
            conta.codigo_res = reservasRAM[pos_res].codigo_res;
            conta.valor_devido = 0;
            //criando a conta do hospede para se ele for comprar algo
            cadastro_conta_txt(conta);
        }
    } else if (opcao == 2) {
        conta.codigo_hos = reservasRAM[pos_res].cod_hospede;
        conta.codigo_res = reservasRAM[pos_res].codigo_res;
        conta.valor_devido = valor;
        //criando a conta do hospede para se ele for comprar algo
        cadastro_conta_txt(conta);
    }
    menu_modulo_transacoes();
}

//fazendo o chekout do hospede
void main_chekout_txt() {
    
    int cod_res, qtd_res, pos_res, sair=0, contador_erro = 0;
    int opcao, pagamento, qtd_con, pos_con,qtd_aco,pos_aco;
   
    data date;
    
    qtd_res = contadorlinhas_txt("reservas.txt");
    qtd_res = qtd_res / 16;
    reservas reservasRAM[qtd_res];
    reservas_ram_txt(qtd_res, reservasRAM);

    qtd_con = contadorlinhas_txt("conta_hospedes.txt");
    qtd_con = qtd_con / 3;
    conta_hospede contasRAM[qtd_con];
    conta_ram_txt(contasRAM, qtd_con);
   
    
    qtd_aco = contadorlinhas_txt("acomodacoes.txt");
    qtd_aco = qtd_aco / 7;
    acomodacoes acomodacoesRAM[qtd_aco];
    acomodacoes_ram_txt(acomodacoesRAM, qtd_aco);
    


    printf("------CHECK-OUT--------\n");
    
    printf("Digite o código da reserva para fazer o check-out:");
    scanf("%d", &cod_res);
    pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes();
        }
    }
    
    pos_con=procura_conta_txt(cod_res,contasRAM,qtd_con);
    if(contasRAM[pos_con].valor_devido==0){
        printf("Você não possui nenhum saldo devedor.\n");
        //deletando a reserva apos o chekout
        deleta_reserva_txt(qtd_res,pos_res,reservasRAM);
        
        //procurando acomodacao para tirar 1 da ocupacao 
        pos_aco=procura_acomodacao_txt(reservasRAM[pos_res].codigo_aco,qtd_aco,acomodacoesRAM);
        acomodacoesRAM[pos_aco].ocupacao--;
        atualiza_acomodacoes_txt(qtd_aco, acomodacoesRAM);
        //deletando a conta do hospede
        deleta_conta_txt(qtd_con,pos_con,contasRAM);
    }else{
        printf("O saldo devedor do hóspede é de:%.2f reais.\n",contasRAM[pos_con].valor_devido);
        printf("Como deseja pagar?\n");
        printf("1-Dinheiro.\n");
        printf("2-Cartão de crédito.\n");
        printf("3-Cartão de débito.\n");
        printf("Digite a opção desejada:");
        scanf("%d", &pagamento);
        if (pagamento == 1) {
            //salvando no caixa  o valor pago pelo hospede
            adicionar_caixa_txt(contasRAM[pos_con].valor_devido, reservasRAM[pos_res].cod_hospede, 0);
            //deletando a reserva ja que o hospede ja saiu do quarto
            deleta_reserva_txt(qtd_res, pos_res, reservasRAM);

            //procurando acomodacao para tirar 1 da ocupacao 
            pos_aco = procura_acomodacao_txt(reservasRAM[pos_res].codigo_aco, qtd_aco, acomodacoesRAM);
            acomodacoesRAM[pos_aco].ocupacao--;
            atualiza_acomodacoes_txt(qtd_aco, acomodacoesRAM);
            //deletando a conta do hospede
            deleta_conta_txt(qtd_con, pos_con, contasRAM);
  
        } else if (pagamento == 2 || pagamento == 3) {
            printf("Digite a data do vencimento do cartão do hóspede.\n");
            printf("Dia:");
            scanf("%d", &date.dia);
            printf("Mês:");
            scanf("%d", &date.mes);
            printf("Ano:");
            scanf("%d", &date.ano);
            adicionar_contas_a_receber_txt(date, reservasRAM[pos_res].cod_hospede, contasRAM[pos_con].valor_devido);
            //deletando a reserva ja que o hospede ja saiu do quarto
            deleta_reserva_txt(qtd_res, pos_res, reservasRAM);

            //procurando acomodacao para tirar 1 da ocupacao 
            pos_aco = procura_acomodacao_txt(reservasRAM[pos_res].codigo_aco, qtd_aco, acomodacoesRAM);
            acomodacoesRAM[pos_aco].ocupacao--;
            atualiza_acomodacoes_txt(qtd_aco, acomodacoesRAM);
            //deletando a conta do hospede
            deleta_conta_txt(qtd_con, pos_con, contasRAM);
        }
    }
    menu_modulo_transacoes();
}

//fazendo as vendas de produtos do hotel
void main_venda_txt(){
    int pos_con,qtd_con,qtd_prod,pos_prod,contador_erro=0,sair=0,pagamento,cod_res,pos_res,qtd_res;
    vendas venda;
    
    qtd_con = contadorlinhas_txt("conta_hospedes.txt");
    qtd_con = qtd_con / 3;
    conta_hospede contasRAM[qtd_con];
    conta_ram_txt(contasRAM, qtd_con);
    
    qtd_res = contadorlinhas_txt("reservas.txt");
    qtd_res = qtd_res / 16;
    reservas reservasRAM[qtd_res];
    reservas_ram_txt(qtd_res, reservasRAM);
    
    qtd_prod = contadorlinhas_txt("produtos.txt");
    qtd_prod = qtd_prod / 6;
    produtos produtosRAM[qtd_prod];
    produtos_ram_txt(produtosRAM, qtd_prod);
    
    printf("-----VENDAS-------\n");
    printf("Digite o código da reserva do hóspede que está comprando:");
    scanf("%d",&cod_res);
    pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes();
        }
    }
    printf("PRODUTOS DISPONÍVEIS:\n");
    mostra_produto_txt(qtd_prod,produtosRAM);
    printf("Digite o código do produto que deseja:");
    scanf("%d",&venda.cod_prod);
    pos_prod = procura_produto_txt(venda.cod_prod, qtd_prod, produtosRAM);
    while (pos_prod == -1) {
        contador_erro++;
        printf("Esse codigo de produto não existe, digite um válido:");
        scanf("%d", &venda.cod_prod);
        pos_prod = procura_produto_txt(venda.cod_prod, qtd_prod, produtosRAM);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes();
        }
    }
    printf("Quantos desse produto deseja comprar?:");
    scanf("%d", &venda.qtd);
    while(venda.qtd>produtosRAM[pos_prod].estoque){
        contador_erro++;
        printf("Não tem estoque disponível para essa quantidade,digite uma quantidade que tenha no estoque:");
        scanf("%d", &venda.qtd);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes();
        }
    }
    venda.valor=venda.qtd*produtosRAM[pos_prod].preco_venda;
    printf("Qual a forma de pagamento?\n");
    printf("1-A vista.\n");
    printf("2-Anotar.\n");
    printf("Digite a opção desejada:");
    scanf("%d",&pagamento);
    if(pagamento==1){
        venda.pagamento=pagamento;
        venda.cod_hos=reservasRAM[pos_res].cod_hospede;
        cadastrar_venda_txt(venda);
        //salvando no caixa  o valor pago pelo hospede
        adicionar_caixa_txt(venda.valor, reservasRAM[pos_res].cod_hospede, 0);
        
        //atualizando o estoque
        produtosRAM[pos_prod].estoque-=venda.qtd;
        atualiza_produto_txt(qtd_prod,produtosRAM);
        
    }else if(pagamento==2){
        venda.pagamento=pagamento;
        venda.cod_hos=reservasRAM[pos_res].cod_hospede;
        //fazendo a notinha
        printf("\n-------NOTINHA---------\n");
        printf("Código do hóspede:%d\n",venda.cod_hos);
        printf("Codigo do produto:%d\n",venda.cod_prod);
        printf("Nome do produto:%s\n",produtosRAM[pos_prod].descricao);
        printf("Quantidade:%d\n",venda.qtd);
        printf("Valor unitário:%.2f\n",produtosRAM[pos_prod].preco_venda);
        printf("Valor total da notinha:%.2f\n\n",venda.valor);
        
        cadastrar_venda_txt(venda);
        //adicionando o valor comprando na conta do hospede
        pos_con=procura_conta_txt(cod_res,contasRAM,qtd_con);
        contasRAM[pos_con].valor_devido=contasRAM[pos_con].valor_devido+venda.valor;
        atualiza_conta_txt(qtd_con,contasRAM);
        
        //atualizando o estoque
        produtosRAM[pos_prod].estoque-=venda.qtd;
        atualiza_produto_txt(qtd_prod,produtosRAM);
    }
    menu_modulo_transacoes();
}

//listando os movimentos de caixa
void main_caixa_txt(){
    int qtd_caixa,existe;
    
    existe=arquivo_existe_txt("caixa.txt");
    if(existe==0){
        printf("Não tem nenhum movimento no caixa.\n");
        menu_modulo_transacoes();
    }
    printf("-----CONTROLE DE CAIXA------\n");
    mostra_caixa_txt();
    menu_modulo_transacoes();
}

//dando baixa nas contas a receber
void main_receber_txt(){
    int cod_conta,qtd_conta,sair=0,contador_erro=0,existe;
    
    existe = arquivo_existe_txt("contas_receber.txt");
    if (existe == 0) {
        printf("Não tem nenhuma conta a receber.\n");
        menu_conta_receber();
    }
    qtd_conta = contadorlinhas_txt("contas_receber.txt");
    qtd_conta = qtd_conta / 5;
    conta_receber contasRAM[qtd_conta];
    contas_receber_ram_txt(contasRAM, qtd_conta);

    
    
    
    printf("\n-----CONTAS A RECEBER------\n");
    mostra_contas_a_receber_txt(qtd_conta,contasRAM);
    printf("Digite a conta que deseja dar baixa:");
    scanf("%d",&cod_conta);
    while(cod_conta+1>qtd_conta){
        printf("Digite uma conta válida que deseja dar baixa:");
        scanf("%d",&cod_conta);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_conta_receber();
        }
    }
    adicionar_caixa_txt(contasRAM[cod_conta].valor_devido,contasRAM[cod_conta].codigo_hos,0);
    deleta_conta_receber_txt(qtd_conta,cod_conta,contasRAM);
    menu_conta_receber();
}

//listando todas contas a receber
void main_listar_conta_receber_txt(){
    int existe,qtd_conta;
    existe = arquivo_existe_txt("contas_receber.txt");
    if (existe == 0) {
        printf("Não tem nenhuma conta a receber.\n");
        menu_conta_receber();
    }
    qtd_conta = contadorlinhas_txt("contas_receber.txt");
    qtd_conta = qtd_conta / 5;
    conta_receber contasRAM[qtd_conta];
    contas_receber_ram_txt(contasRAM, qtd_conta);
    
    printf("\n--------LISTA DE CONTAS A RECEBER--------\n");
    mostra_contas_a_receber_txt(qtd_conta,contasRAM);
    menu_conta_receber();
}


//dando entrada em notas de fornecedores
void main_entrada_produtos_txt() {
    float frete_prod, imposto_prod, entrada;
    float total = 0, prazo = 0, saldo = 0;
    int vezes, qtd_for, pos_for, contador_erro = 0, retorno, sair = 0, pagamento, qtd_caixa;
    int qtd_total=0, qtd_prod, pos_prod, estoque_min, cod_prod;

    NotaFiscal notas;
    notas.num_produtos = 0;
    notas.total = 0;
    notas.entra_prod = NULL;

    produtos cadastroPROD;

    cad_hotel ramHT[1];
    hotel_ram_txt(ramHT);

    qtd_for = contadorlinhas_txt("fornecedores.txt");
    qtd_for = qtd_for / 13;
    fornecedores fornecedorRAM[qtd_for];
    fornecedores_ram_txt(fornecedorRAM, qtd_for);




    printf("\n-------ENTRADA DE NOTAS--------\n");
    printf("Digite a razão social do fornecedor:");
    scanf(" %[^\n]s%*c", notas.fornecedor);
    setbuf(stdin, NULL);
    pos_for = procura_fornecedor_nome_txt(notas.fornecedor, qtd_for, fornecedorRAM);
    if (pos_for == -1) {
        printf("Vejo que esse fornecedor não está cadastrado, cadastre ele primerio.\n");
        main_cadastro_fornecedor_txt();
    }
    strcpy(notas.cnpj,fornecedorRAM[pos_for].cnpj);
    
    
    printf("Digite o valor do frete:");
    scanf("%f", &notas.frete);
    printf("Digite o valor do imposto:");
    scanf("%f", &notas.imposto);

    while (sair == 0) {
        notas.entra_prod = realloc(notas.entra_prod, (notas.num_produtos + 1) * sizeof (entrada_produto));

        if (notas.entra_prod == NULL) {
            perror("Erro ao alocar memória");
            exit(EXIT_FAILURE);
        }

        // Ler informações do usuário
        printf("Digite a descrição do produto: ");
        scanf(" %[^\n]s%*c", notas.entra_prod[notas.num_produtos].nome);
        setbuf(stdin, NULL);
        printf("Digite o preço do produto: ");
        scanf("%f", &notas.entra_prod[notas.num_produtos].preco);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &notas.entra_prod[notas.num_produtos].quantidade);

        // Calcular subtotal
        notas.entra_prod[notas.num_produtos].subtotal =
                notas.entra_prod[notas.num_produtos].preco * notas.entra_prod[notas.num_produtos].quantidade;

        // Atualizar total da nota e quantidade total
        notas.total += notas.entra_prod[notas.num_produtos].subtotal;
        qtd_total += notas.entra_prod[notas.num_produtos].quantidade;

        // Verificar se há mais produtos
        printf("A nota possui mais produtos? (0-Sim/1-Não): ");
        scanf("%d", &sair);

        notas.num_produtos++;
    }

    imposto_prod = notas.imposto / qtd_total;
    frete_prod = notas.frete / qtd_total;

    for (int i = 0; i < notas.num_produtos; i++) {
        qtd_prod = contadorlinhas_txt("produtos.txt");
        qtd_prod = qtd_prod / 6;
        produtos produtosRAM[qtd_prod];
        produtos_ram_txt(produtosRAM, qtd_prod);

        retorno = procura_produto_nome_txt(notas.entra_prod[i].nome, qtd_prod, produtosRAM);
        if (retorno == -1) {
            printf("O produto %s ainda não foi cadastrado.\n",notas.entra_prod[i].nome);
            printf("Digite o estoque minímo para o cadastrá-lo:");
            scanf("%d", &estoque_min);
            printf("Digite um código para esse produto:");
            scanf("%d", &cod_prod);
            pos_prod = procura_produto_txt(cod_prod, qtd_prod, produtosRAM);
            sair = 0;
            while (pos_prod != -1) {
                printf("Esse codigo de produto ja existe digite um diferente:");
                scanf("%d", &cod_prod);
                pos_prod = procura_produto_txt(cod_prod, qtd_prod, produtosRAM);
                contador_erro++;
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair != 0) {
                    menu_modulo_transacoes();
                }
            }
            cadastroPROD.codigo = cod_prod;
            strcpy(cadastroPROD.descricao, notas.entra_prod[i].nome);
            cadastroPROD.estoque = notas.entra_prod[i].quantidade;
            cadastroPROD.estoque_min = estoque_min;
            cadastroPROD.preco_custo = notas.entra_prod[i].preco;
            cadastroPROD.preco_venda = (frete_prod + imposto_prod + notas.entra_prod[i].preco) * ((ramHT[0].mlpv + 100) / 100);
            cadastro_produtos_txt(cadastroPROD);
        } else {
            produtosRAM[retorno].estoque += notas.entra_prod[i].quantidade;
            produtosRAM[retorno].preco_custo = notas.entra_prod[i].preco;
            produtosRAM[retorno].preco_venda = (frete_prod + imposto_prod + notas.entra_prod[i].preco) * ((ramHT[0].mlpv + 100) / 100);
            atualiza_produto_txt(qtd_prod, produtosRAM);
        }
    }

    qtd_caixa = contadorlinhas_txt("caixa.txt");
    qtd_caixa = qtd_caixa / 5;
    conta_receber caixaRAM[qtd_caixa];
    caixa_ram_txt(caixaRAM, qtd_caixa);
    notas.total += notas.frete + notas.imposto;
    saldo = calcula_saldo_caixa(qtd_caixa, caixaRAM);

    printf("Valor total da nota:%.2f\n", notas.total);
    printf("Valor total em caixa:%.2f\n", saldo);
    printf("Qual será a forma de pagamento do nota fiscal?\n");
    printf("1-A vista.\n");
    printf("2-A prazo.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &pagamento);
    if (pagamento == 1) {
        if (saldo < notas.total) {
            printf("O caixa não possui saldo suficiente para o pagamento,logo pagará a prazo.\n");
            pagamento = 2;
        } else {
            adicionar_caixa_txt(notas.total, fornecedorRAM[pos_for].codigo, 1);
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
            prazo = notas.total - entrada;
            adicionar_caixa_txt(entrada, fornecedorRAM[pos_for].codigo, 1);
            adicionar_contas_pagar_txt(prazo, vezes,fornecedorRAM[pos_for].codigo);
        } else {
            printf("Deseja parcelar em quantas vezes?:");
            scanf("%d", &vezes);
            adicionar_contas_pagar_txt(notas.total, vezes,fornecedorRAM[pos_for].codigo);
        }
    }

    cadastrar_notafiscal_txt(notas);

    menu_modulo_transacoes();
}


//dando baixa nas contas a pagar
void main_conta_pagar_txt(){
    int cod_conta, qtd_conta, sair = 0, contador_erro = 0, existe,qtd_caixa;
    float saldo=0;
    
    existe = arquivo_existe_txt("contas_pagar.txt");
    if (existe == 0) {
        printf("Não tem nenhuma conta a pagar.\n");
        menu_conta_receber();
    }
    
    qtd_caixa = contadorlinhas_txt("caixa.txt");
    qtd_caixa = qtd_caixa / 5;
    conta_receber caixaRAM[qtd_caixa];
    caixa_ram_txt(caixaRAM, qtd_caixa);
    saldo = calcula_saldo_caixa(qtd_caixa, caixaRAM);
    
    qtd_conta = contadorlinhas_txt("contas_pagar.txt");
    qtd_conta = qtd_conta / 4;
    conta_receber contasRAM[qtd_conta];
    contas_pagar_ram_txt(contasRAM, qtd_conta);




    printf("\n-----CONTAS A PAGAR------\n");
    mostra_contas_a_pagar_txt(qtd_conta, contasRAM);
    printf("Digite a conta que deseja dar baixa:");
    scanf("%d", &cod_conta);
    while (cod_conta + 1 > qtd_conta) {
        printf("Digite uma conta válida que deseja dar baixa:");
        scanf("%d", &cod_conta);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_conta_pagar();
        }
    }
    if(contasRAM[cod_conta].valor_devido>saldo){
        printf("O caixa não possui saldo o suficiente para pagar.\n");
        printf("Saldo do caixa:%.2f\n",saldo);
        menu_conta_pagar();
    }else{
        adicionar_caixa_txt(contasRAM[cod_conta].valor_devido, contasRAM[cod_conta].codigo_hos, 1);
        deleta_conta_pagar_txt(qtd_conta, cod_conta, contasRAM);
        menu_conta_pagar();
    }
    
}

//listando todas contas a receber
void main_listar_conta_pagar_txt() {
    int existe, qtd_conta;
    existe = arquivo_existe_txt("contas_pagar.txt");
    if (existe == 0) {
        printf("Não tem nenhuma conta a pagar.\n");
        menu_conta_pagar();
    }
    qtd_conta = contadorlinhas_txt("contas_pagar.txt");
    qtd_conta = qtd_conta / 4;
    conta_receber contasRAM[qtd_conta];
    contas_pagar_ram_txt(contasRAM, qtd_conta);

    printf("\n--------LISTA DE CONTAS A RECEBER--------\n");
    mostra_contas_a_pagar_txt(qtd_conta, contasRAM);
    menu_conta_pagar();
}
//FIM TRANSAÇÕES


//INICIO FEEEDBACK
//funcao para listar hospedes
void main_listagem_hospede_txt(){
    int listagem[2];
    int codigo[2];
    int sexo[20];
    int opcao;
    
    printf("\n-----------LISTAGEM DE HÓSPEDES-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Faixa de código.(1-Sim/0-Não):");
    scanf("%d", &listagem[0]);
    if(listagem[0]==1){
        printf("Digite dois codigos.(do 1 ao 10, por exemplo).\n");
        printf("Código 1:");
        scanf("%d",&codigo[0]);
        printf("Código 2:");
        scanf("%d",&codigo[1]);
        while(codigo[0]>codigo[1]){
            printf("O código 1 tem que ser menor que o código 2.\n");
            printf("Código 1:");
            scanf("%d",&codigo[0]);
            printf("Código 2:");
            scanf("%d",&codigo[1]);
        }
    }
    printf("Deseja filtrar por sexo.(1-Sim/0-Não):");
    scanf("%d",&listagem[1]);
    if(listagem[1]==1){
        printf("Digite o sexo que deseja filtrar:");
        scanf(" %[^\n]s%*c", sexo);
        setbuf(stdin, NULL);
    }
                          
    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada:");
    scanf("%d",&opcao);
    if(opcao !=1 && opcao !=2){
        printf("Essa opção não existe.\n");
        menu_modulo_feedback();
    }
    listagem_hospede_txt(codigo,listagem,sexo,opcao);
    menu_modulo_feedback();
}

//funcao para listar acomodacoes
void main_listagem_acomodacoes_txt(){
    int listagem[3];
    int codigo[2];
    int categoria;
    int opcao,ret_data;
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
        menu_modulo_feedback();
    }
    listagem_acomodacoes_txt(codigo, listagem, categoria, opcao,dates);
    menu_modulo_feedback();
}

//funcao para listar reservas
void main_listagem_reservas_txt() {
    int listagem[3];
    int codigo_hospede[2],codigo_acomodacao[2];
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
        menu_modulo_feedback();
    }
    listagem_reservas_txt(listagem, codigo_hospede,codigo_acomodacao ,datas, opcao);
    menu_modulo_feedback();
}

//funcao para listar acomodacoes 
void main_listagem_movimento_acomodacoes_txt() {
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
        scanf("%d",&lucro);
    }
    


    printf("1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2) {
        printf("Essa opção não existe.\n");
        menu_modulo_feedback();
    }
    listagem_movimento_acomodacoes_txt(listagem, codigo, diarias, lucro, opcao);
    menu_modulo_feedback();
}

//funcao para listar produtos
void main_listagem_produtos_txt() {
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
        menu_modulo_feedback();
    }
    listagem_produtos_txt(codigo, listagem, opcao);
    menu_modulo_feedback();
}

//funcao para listar estoque minimo
void main_listagem_estoque_minimo_txt(){
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
        menu_modulo_feedback();
    }

    listagem_estoque_minimo_txt(codigo, listagem, opcao);
    menu_modulo_feedback();
}

//funcao para listar vendas
void main_listagem_vendas_txt() {
    int listagem;
    int pagamento;
    int opcao;

    printf("\n-----------LISTAGEM DE VENDAS-----------\n");
    printf("Escolha os filtros que deseja fazer a listagem.\n");
    printf("Deseja filtrar por metodo de pagamento?(1-Sim/0-Não): ");
    scanf("%d", &listagem);
    if(listagem==1){
        printf("\n1-Deseja filtrar por pagamentos a vista.\n");
        printf("2-Deseja filtrar por pagamentos a prazo.\n");
        printf("Digite a opção desejada:");
        scanf("%d",&pagamento);
        if(pagamento != 1 && pagamento != 2){
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
        menu_modulo_feedback();
    }
    
    listagem_vendas_txt(pagamento, opcao,listagem); 
    menu_modulo_feedback();
}

//funcao para listar contas a receber
void main_listagem_contas_receber_txt(){
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
    if(listagem[1] == 1){
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
        menu_modulo_feedback();
    } 

    listagem_contas_receber_txt(listagem,codigo,inicio,fim,opcao);
    menu_modulo_feedback();
    
}

//funcao para listar contas a pagar
void main_listagem_contas_pagar_txt(){
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
        menu_modulo_feedback();
    }

    listagem_contas_pagar_txt(listagem, codigo, inicio, fim, opcao);
    menu_modulo_feedback();
}

//funcao para listar caixa
void main_listagem_caixa_txt() {
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
        menu_modulo_feedback();
    }

    // Chamada da função para listagem de caixa
    listagem_caixa_txt(inicio, fim,listagem ,opcao);
    
    menu_modulo_feedback();
}
//FIM FEEDBACK



//COMEÇO IMPORTAÇÃO E EXPORTAÇÃO
void main_importar_dados_txt(){
    int importar;
    char arquivo[30];
    printf("\n------IMPORTAR DADOS-------\n");
    printf("Primeiramente digite o nome do arquivo que deseja importar(EX:arquivo.xml):");
    scanf(" %[^\n]s%*c", arquivo);    
    printf("Quais dados deseja importar?\n");
    printf("Dados do Hotel.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if(importar==1){
        importar_dados_hotel_xml(arquivo);
    }
    printf("Dados dos Hospedes.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if(importar==1){
        importar_dados_hospedes_xml(arquivo);
    }
    printf("Dados das acomodações.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if(importar==1){
        importar_dados_acomodacoes_xml(arquivo);
    }
    printf("Dados das categorias de acomodação.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if(importar==1){
        importar_dados_categoria_acomodacao_xml(arquivo);
    }
    printf("Dados dos produtos.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if(importar==1){
        importar_dados_produtos_xml(arquivo);
    }
    printf("Dados dos fornecedores.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if(importar==1){
        importar_dados_fornecedores_xml(arquivo);
    }
    printf("Dados dos operadores.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if(importar==1){
        importar_dados_operadores_xml(arquivo);
    }

    menu_modulo_im_exportacao();
}

//funcao para exportar dados
void main_exportar_dados_txt(){
    int exportar[7];
    
    printf("\n------EXPORTAR DADOS-------\n");
    printf("Quais dados deseja exportar?\n");
    printf("Dados do Hotel.(1-Sim/0-Não):");
    scanf("%d",&exportar[0]);
    printf("Dados dos Hospedes.(1-Sim/0-Não):");
    scanf("%d",&exportar[1]);
    printf("Dados das acomodações.(1-Sim/0-Não):");
    scanf("%d",&exportar[2]);
    printf("Dados das categorias de acomodação.(1-Sim/0-Não):");
    scanf("%d",&exportar[3]);
    printf("Dados dos produtos.(1-Sim/0-Não):");
    scanf("%d",&exportar[4]);
    printf("Dados dos fornecedores.(1-Sim/0-Não):");
    scanf("%d",&exportar[5]);
    printf("Dados dos operadores.(1-Sim/0-Não):");
    scanf("%d",&exportar[6]);
    
    exportar_dados_xml(exportar);
   
    menu_modulo_im_exportacao();
}
//FIM IMPORTAÇÃO E EXPORTAÇÃO




//funçao utilizada para o login
void login_txt() {
    permissao login;
    OPsistema operador;
    cad_hotel hotel;
    int pos_op, cod_op, senha, cont_erro = 0, sair=0, retorno_txt, quantidade, retorno_bin;


    retorno_txt = arquivo_existe_txt("operadores.txt");
    retorno_bin = arquivo_existe_bin("Operadores.bin");

    if (retorno_txt == 0 && retorno_bin == 0) {
        printf("Vejo que é a primeira vez que inicie o programa\n");
        printf("Começe cadastrando um operador,lembrando esse operador terá todas permissões ativas.\n");
        printf("------Dados do Operador-------\n");
        printf("Digite o código do operador:");
        scanf("%d", &operador.codigo);
        printf("Digite o nome do operador:");
        scanf(" %[^\n]s%*c", operador.nome);
        setbuf(stdin, NULL);
        printf("Digite o nome de usuário do operador:");
        scanf(" %[^\n]s%*c", operador.usuario);
        setbuf(stdin, NULL);
        printf("Digite a senha do operador(Somente números):");
        scanf("%d", &operador.senha);
        operador.permissoes.cadastros = 1;
        operador.permissoes.feedback = 1;
        operador.permissoes.im_exportacao = 1;
        operador.permissoes.reservas = 1;
        operador.permissoes.transacoes = 1;

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
        //chamando a função para gravar o hotel em txt
        //passando a struct como paramentro
        cadastro_hotel_txt(hotel);
        cadastro_operadores_txt(operador);
        menu_principal_txt();


    } else {
        if (retorno_bin != 0) {
            //se for diferente de 0 é pq existe informações salvas em binarios logo vamos trazelas para txt
            muda_arquivo_bin_p_txt();
        }

        quantidade = contadorlinhas_txt("operadores.txt");
        quantidade = quantidade / 9;
        OPsistema ramOP[quantidade];
        operadores_ram_txt(quantidade, ramOP);

        printf("\tLOGIN\n");
        printf("Código do operador:");
        scanf("%d", &cod_op);
        printf("Senha do usuário:");
        scanf("%d", &senha);
        pos_op = verifica_login(cod_op, senha, ramOP, quantidade);
        while (pos_op == -1) {
            printf("Operador não encontrado.\n");
            printf("Digite um operador válido.\n");
            printf("Código do operador:");
            scanf("%d", &cod_op);
            printf("Senha do usuário:");
            scanf("%d", &senha);
            pos_op = verifica_login(cod_op, senha, ramOP, quantidade);
            cont_erro++;
            if (cont_erro > 2) {
                printf("Ocorreu muitos erros de login deseja sair?(1-Sim/0-Não):");
                scanf("%d", &sair);
            }
            if (sair == 1) {
                exit(1);
            }
        }
        if (pos_op != -1) {
            printf("Login feito com sucesso.\n");
            permissoes_login(ramOP, pos_op);
            menu_principal_txt();
        }
    }
}
//FIM MAIN TXT




//INICIO MAIN BIN
//INICIO HOTEL
void main_cadastro_hotel_bin() {
    //Variaveis para o crud do hotel.
    cad_hotel hotel_inf;
    int hotel;

    hotel = arquivo_existe_bin("Hotel.bin");

    if (hotel == 1) {
        printf("Hotel já existente se fizer outro cadastro perdera o anterior.");
    }


    //Recebendo dados do hotel
    printf("-------CADASTRO DO HOTEL-------\n");
    printf("Digite o nome fantasia:");
    scanf(" %[^\n]s%*c", hotel_inf.nome_fantasia);
    setbuf(stdin, NULL);
    printf("Digite a razão social:");
    scanf(" %[^\n]s%*c", hotel_inf.razao_social);
    setbuf(stdin, NULL);
    printf("Digite a inscrição estadual:");
    scanf(" %[^\n]s%*c", hotel_inf.inscricao_estadual);
    setbuf(stdin, NULL);
    printf("Digite o CNPJ:");
    scanf(" %[^\n]s%*c", hotel_inf.cnpj);
    setbuf(stdin, NULL);
    printf("-------ENDEREÇO-------\n");
    printf("Digite o estado:");
    scanf(" %[^\n]s%*c", hotel_inf.endereco.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade:");
    scanf(" %[^\n]s%*c", hotel_inf.endereco.cidade);
    setbuf(stdin, NULL);
    printf("Digite o CEP:");
    scanf(" %[^\n]s%*c", &hotel_inf.endereco.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro:");
    scanf(" %[^\n]s%*c", hotel_inf.endereco.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua:");
    scanf(" %[^\n]s%*c", hotel_inf.endereco.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero:");
    scanf("%d", &hotel_inf.endereco.numero);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Digite o telefone do hotel:");
    scanf(" %[^\n]s%*c", hotel_inf.telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do hotel:");
    scanf(" %[^\n]s%*c", hotel_inf.email);
    setbuf(stdin, NULL);
    printf("Digite o nome do responsável:");
    scanf(" %[^\n]s%*c", hotel_inf.nome_responsavel);
    setbuf(stdin, NULL);
    printf("Digite o telefone do responsável:");
    scanf(" %[^\n]s%*c", hotel_inf.telefone_responsavel);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------HORÁRIO DE CHECK-IN-------\n");
    printf("Digite a hora do chekin(SOMENTE HORA):");
    scanf("%d", &hotel_inf.horario_checkin.hora);
    setbuf(stdin, NULL);
    printf("Digite os minutos do chekin(SOMENTE MINUTOS):");
    scanf("%d", &hotel_inf.horario_checkin.minutos);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("-------HORÁRIO DE CHECK-OUT-------\n");
    printf("Digite a hora do chek-out(SOMENTE HORA):");
    scanf("%d", &hotel_inf.horario_checkout.hora);
    setbuf(stdin, NULL);
    printf("Digite os minutos do chek-out(SOMENTE MINUTOS):");
    scanf("%d", &hotel_inf.horario_checkout.minutos);
    setbuf(stdin, NULL);
    printf("--------------------------------------------------------------------------\n");
    printf("Digite a margem de lucro sobre os produtos:");
    scanf("%f", &hotel_inf.mlpv);
    setbuf(stdin, NULL);

    //passando a struct como paramentro
    hotel_cad_bin(hotel_inf);
    menu_gestao_hotel_bin();
}

void main_atualiza_hotel_bin() {

    cad_hotel novo_hotel_inf [1];
    int opcao;
    int hotel;

    hotel = arquivo_existe_bin("Hotel.bin");

    if (hotel == 1) {

        printf("----------Atualizar dados do hotel----------\n");
        dados_hotel_bin();

        printf("Deseja alterar o nome fantasia?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo nome fantasia:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].nome_fantasia);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar a razão social?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nova razão social:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].razao_social);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar a inscrição estadual?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nova inscrição estadual:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].inscricao_estadual);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar o CNPJ?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo CNPJ:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].cnpj);
            setbuf(stdin, NULL);
        }
        printf("-------ENDEREÇO-------\n");
        printf("Deseja alterar o Estado?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo estado:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].endereco.estado);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar a cidade?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nova cidade:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].endereco.cidade);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar o CEP?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo CEP:");
            scanf(" %[^\n]s%*c", &novo_hotel_inf [0].endereco.cep);
            setbuf(stdin, NULL);
        }

        printf("Deseja alterar o bairro?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo bairro:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].endereco.bairro);
            setbuf(stdin, NULL);
        }

        printf("Deseja alterar a rua?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nova rua:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].endereco.rua);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar o numero de endereço?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo numero de endereço:");
            scanf("%d", &novo_hotel_inf [0].endereco.numero);
            setbuf(stdin, NULL);
        }
        printf("-------DADOS PARA CONTATO-------\n");
        printf("Deseja alterar o telefone do hotel?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo telefone do hotel:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].telefone);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar o e-mail do hotel?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Digite o e-mail do hotel:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].email);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar o nome do responsável do hotel?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo nome do responsável:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].nome_responsavel);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar o telefone do responsável do hotel?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Novo telefone do responsável:");
            scanf(" %[^\n]s%*c", novo_hotel_inf [0].telefone_responsavel);
            setbuf(stdin, NULL);
        }
        printf("-------HORÁRIO DE CHECK-IN-------\n");
        printf("Deseja alterar a hora do chek-in?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nova hora do chekin(SOMENTE HORA):");
            scanf("%d", &novo_hotel_inf [0].horario_checkin.hora);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar o minuto do chek-in?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Digite os minutos do chekin(SOMENTE MINUTOS):");
            scanf("%d", &novo_hotel_inf [0].horario_checkin.minutos);
            setbuf(stdin, NULL);
        }
        printf("-------HORÁRIO DE CHECK-OUT-------\n");
        printf("Deseja alterar a hora do chek-out?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nova hora do chek-out(SOMENTE HORA):");
            scanf("%d", &novo_hotel_inf [0].horario_checkout.hora);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar o minuto do chek-out?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Digite os minutos do chek-out(SOMENTE MINUTOS):");
            scanf("%d", &novo_hotel_inf [0].horario_checkout.minutos);
            setbuf(stdin, NULL);
        }
        printf("Deseja alterar a margem de lucro sobre os produtos?(1-Sim/0-Não)");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nova margem de lucro sobre os produtos:");
            scanf("%f", &novo_hotel_inf [0].mlpv);
            setbuf(stdin, NULL);
        }
        atualiza_hotel_bin(novo_hotel_inf);
        menu_gestao_hotel_bin();
    } else {
        printf("Hotel não cadastrada.");
        menu_gestao_hotel_bin();
    }
}
//FIM HOTEL


//COMEÇO OPERADOR
void main_cadastro_operador_bin() {
    //variaveis utilizadas para cadastro de operadores
    OPsistema op;
    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;

    //verificando se o arquvio de operadores ja existe 
    retorno = arquivo_existe_bin("Operadores.bin");
    //se existir trago os dados para ram para verificar se o codigo do operador é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = qtd_itens_bin("Operadores.bin", sizeof (OPsistema));
        OPsistema ramOP[quantidade];
        operadores_ram_bin(ramOP);

        printf("-------CADASTRO DE OPERADORES-------\n");
        printf("Digite o codigo do operador:");
        scanf("%d", &op.codigo);
        posicao = procura_operador_txt(op.codigo, quantidade, ramOP);

        while (posicao != -1) {
            printf("Esse codigo de operador ja existe digite um diferente:");
            scanf("%d", &op.codigo);
            posicao = procura_operador_txt(op.codigo, quantidade, ramOP);

            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_operadores_bin();
            }
        }
    } else {
        //recebendo dados de operadores
        printf("-------CADASTRO DE OPERADORES-------\n");
        printf("Digite o codigo do usuario:");
        scanf("%d", &op.codigo);
    }

    printf("Digite o nome do operador:");
    scanf(" %[^\n]s%*c", op.nome);
    setbuf(stdin, NULL);
    printf("Digite o nome do usario:");
    scanf(" %[^\n]s%*c", op.usuario);
    setbuf(stdin, NULL);
    printf("Digite a senha para o usuario:");
    scanf("%d", &op.senha);
    setbuf(stdin, NULL);
    printf("-------PERMISSÕES-------\n");
    printf("Cadastros:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.cadastros);
    setbuf(stdin, NULL);
    printf("Reservas:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.reservas);
    setbuf(stdin, NULL);
    printf("Transações:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.transacoes);
    setbuf(stdin, NULL);
    printf("FeedBack:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.feedback);
    setbuf(stdin, NULL);
    printf("Importações e Exportações:(1-Permitir/0-Negar)");
    scanf("%d", &op.permissoes.im_exportacao);
    setbuf(stdin, NULL);

    //passando o struct de operadores como parametro
    operadores_cad_bin(op);
    //fim do cadastro de operadores

    menu_gestao_operadores_bin();
}

void main_atualiza_operador_bin() {
    //variaveis utilizadas para atualizar operador
    OPsistema op_inf;
    int existe_op = 0, posicao = 0;
    int codigo_op;
    int retorno;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Operadores.bin");

    if (retorno == 1) {

        printf("\n-------ATUALIZAR DADOS DOS OPERADORES-------\n\n");

        do {
            //pedindo ao usuario o codigo do operadores que deseja alterar
            printf("Digite o codigo do operador que deseja alterar:");
            scanf("%d", &codigo_op);

            existe_op = procura_operador_bin(codigo_op);
            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_operadores_bin();
                break;
            }

            if (existe_op == 1) {
                printf("Digite os novos dados para o operador: \n\n");

                printf("Digite o codigo de usuario:");
                scanf("%d", &op_inf.codigo);

                posicao = procura_operador_bin(op_inf.codigo);

                while (posicao == 1) {
                    printf("Esse codigo já está em uso, tente um diferente: ");
                    scanf("%d", &op_inf.codigo);

                    posicao = procura_operador_bin(op_inf.codigo);
                    contador_erro++;

                    if (contador_erro > 2) {
                        printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }

                    if (sair != 0) {
                        menu_gestao_operadores_bin();
                    }
                }

                printf("Digite o nome do operador:");
                scanf(" %[^\n]s%*c", op_inf.nome);
                setbuf(stdin, NULL);
                printf("Digite o nome do usario:");
                scanf(" %[^\n]s%*c", op_inf.usuario);
                setbuf(stdin, NULL);
                printf("Digite a senha para o usuario:");
                scanf("%d", &op_inf.senha);
                setbuf(stdin, NULL);

                printf("-------PERMISSÕES-------\n");
                printf("Cadastros:(1-Permitir/0-Negar)");
                scanf("%d", &op_inf.permissoes.cadastros);
                setbuf(stdin, NULL);
                printf("Reservas:(1-Permitir/0-Negar)");
                scanf("%d", &op_inf.permissoes.reservas);
                setbuf(stdin, NULL);
                printf("Transações:(1-Permitir/0-Negar)");
                scanf("%d", &op_inf.permissoes.transacoes);
                setbuf(stdin, NULL);
                printf("FeedBack:(1-Permitir/0-Negar)");
                scanf("%d", &op_inf.permissoes.feedback);
                setbuf(stdin, NULL);
                printf("Importações e Exportações:(1-Permitir/0-Negar)");
                scanf("%d", &op_inf.permissoes.im_exportacao);
                setbuf(stdin, NULL);

                atualiza_operadores_bin(op_inf, codigo_op);
                menu_gestao_operadores_bin();
                break;
            }

        } while (sair == 0 || existe_op == 0);

    } else {
        printf("Não existe cadastro de operadores.");
        menu_gestao_operadores_bin();
    }
}

void main_deleta_operador_bin() {
    //variaveis utilizadas na deleção de operadores
    int existe_op = 0;
    int codigo_op;
    int retorno;
    int delete = 0;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Operadores.bin");

    if (retorno == 1) {

        printf("-----DELEÇÃO DE OPERADOR-----\n");

        do {
            //pedindo ao usuario o codigo do operadores que deseja deletar
            printf("Digite o codigo do operador que deseja deletar:");
            scanf("%d", &codigo_op);

            //funcao para procurar o operadores
            existe_op = procura_operador_bin(codigo_op);

            if (existe_op == 1) {
                break;
            }

            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_operadores_bin();
                break;
            }

        } while (sair == 0 || existe_op == 0);

        printf("Deseja realmente deletar esse operador?(1-Sim/0-Não): ");
        scanf("%d", &delete);

        if (delete == 1) {
            deleta_operadores_bin(codigo_op);
        }

    } else {
        printf("Não existe cadastro de operadores.");
    }

    menu_gestao_operadores_bin();
}
//FIM OPERADOR

//COMEÇO HOSPEDE
void main_cadastro_hospede_bin() {
    //variaveis para cadastro de hospedes
    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;
    hospedes cadastro_hospedes;


    //verificando se o arquvio de hospedes ja existe 
    retorno = arquivo_existe_bin("Hospedes.bin");


    //se existir trago os dados para ram para verificar se o codigo do hospede é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = qtd_itens_bin("Hospedes.bin", sizeof (hospedes));
        hospedes ramHO[quantidade];
        hospede_ram_bin(ramHO);

        printf("-------Cadastros de Hospedes--------\n");
        printf("Digite o codigo do hospedes:");
        scanf("%d", &cadastro_hospedes.codigo);
        setbuf(stdin, NULL);

        posicao = procura_hospede_txt(cadastro_hospedes.codigo, quantidade, ramHO);
        while (posicao != -1) {
            printf("Esse codigo de hospedes ja existe digite um diferente:");
            scanf("%d", &cadastro_hospedes.codigo);
            posicao = procura_hospede_txt(cadastro_hospedes.codigo, quantidade, ramHO);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_hospedes_bin();
            }
        }
    } else {
        printf("-------Cadastros de Hospedes--------\n");
        printf("Digite o codigo do hospede:");
        scanf("%d", &cadastro_hospedes.codigo);
        setbuf(stdin, NULL);

    }




    printf("Digite o nome do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.nome);
    setbuf(stdin, NULL);
    printf("----Dados de endereço do Hospede----\n");
    printf("Digite o estado do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.cidade);
    setbuf(stdin, NULL);
    printf("Digite a cep do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.endereco_hospede.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero de endereço do hospede:");
    scanf("%d", &cadastro_hospedes.endereco_hospede.numero);
    setbuf(stdin, NULL);
    printf("----Dados pessoais do hospede-----\n");
    printf("Digite o CPF do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.cpf);
    setbuf(stdin, NULL);
    printf("Digite o telefone do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.email);
    setbuf(stdin, NULL);
    printf("Digite o sexo do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.sexo);
    setbuf(stdin, NULL);
    printf("Digite o estado civil do hospede:");
    scanf(" %[^\n]s%*c", cadastro_hospedes.estado_civil);
    setbuf(stdin, NULL);
    printf("Digite a data de nascimento do hospede.\n");
    printf("Dia:");
    scanf("%d", &cadastro_hospedes.data_nacimento.dia);
    setbuf(stdin, NULL);
    printf("Mês:");
    scanf("%d", &cadastro_hospedes.data_nacimento.mes);
    setbuf(stdin, NULL);
    printf("Ano:");
    scanf("%d", &cadastro_hospedes.data_nacimento.ano);
    setbuf(stdin, NULL);
    hospede_cad_bin(cadastro_hospedes);

    menu_gestao_hospedes_bin();
}

void main_atualiza_hospede_bin() {
    //variaveis utlizadas atualizar hospede
    hospedes hospede_inf;
    int existe_hos = 0, posicao = 0;
    int codigo_hospede;
    int retorno;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Hospedes.bin");
    if (retorno == 1) {

        printf("-------ATUALIZA HOSPEDE -------\n");

        do {
            //pedindo ao usuario o codigo do hospede que deseja alterar
            printf("Digite o codigo do hospede que deseja alterar:");
            scanf("%d", &codigo_hospede);

            existe_hos = procura_hospede_bin(codigo_hospede);
            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_hospedes_bin();
                break;
            }

            if (existe_hos == 1) {
                printf("Digite os novos dados para o hospede: \n\n");

                printf("Digite o codigo do hospede:");
                scanf("%d", &hospede_inf.codigo);
                setbuf(stdin, NULL);

                posicao = procura_hospede_bin(hospede_inf.codigo);

                while (posicao == 1) {
                    printf("Esse codigo já está em uso, tente um diferente: ");
                    scanf("%d", &hospede_inf.codigo);

                    posicao = procura_hospede_bin(hospede_inf.codigo);
                    contador_erro++;

                    if (contador_erro > 2) {
                        printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }

                    if (sair != 0) {
                        menu_gestao_hospedes_bin();
                        break;
                    }
                }

                printf("Digite o nome do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.nome);
                setbuf(stdin, NULL);
                printf("----Dados de endereço do Hospede----\n");
                printf("Digite o estado do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.endereco_hospede.estado);
                setbuf(stdin, NULL);
                printf("Digite a cidade do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.endereco_hospede.cidade);
                setbuf(stdin, NULL);
                printf("Digite a cep do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.endereco_hospede.cep);
                setbuf(stdin, NULL);
                printf("Digite o bairro do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.endereco_hospede.bairro);
                setbuf(stdin, NULL);
                printf("Digite a rua do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.endereco_hospede.rua);
                setbuf(stdin, NULL);
                printf("Digite o numero de endereço do hospede:");
                scanf("%d", &hospede_inf.endereco_hospede.numero);
                setbuf(stdin, NULL);


                printf("----Dados pessoais do hospede-----\n");
                printf("Digite o CPF do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.cpf);
                setbuf(stdin, NULL);
                printf("Digite o telefone do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.telefone);
                setbuf(stdin, NULL);
                printf("Digite o e-mail do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.email);
                setbuf(stdin, NULL);
                printf("Digite o sexo do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.sexo);
                setbuf(stdin, NULL);
                printf("Digite o estado civil do hospede:");
                scanf(" %[^\n]s%*c", hospede_inf.estado_civil);
                setbuf(stdin, NULL);
                printf("Digite a data de nascimento do hospede.\n");
                printf("Dia:");
                scanf("%d", &hospede_inf.data_nacimento.dia);
                setbuf(stdin, NULL);
                printf("Mês:");
                scanf("%d", &hospede_inf.data_nacimento.mes);
                setbuf(stdin, NULL);
                printf("Ano:");
                scanf("%d", &hospede_inf.data_nacimento.ano);
                setbuf(stdin, NULL);

                atualiza_hospede_bin(hospede_inf, codigo_hospede);
                menu_gestao_hospedes_bin();
                break;
            }

        } while (sair == 0 || existe_hos == 0);

    } else {
        printf("Não existe cadastro de hospedes.");
        menu_gestao_hospedes_bin();
    }
}

void main_deleta_hospede_bin() {
    //variaveis utilizadas na deleção de hospedes
    int existe_hos = 0;
    int codigo_hospede;
    int delete = 0;
    int retorno;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Hospedes.bin");

    if (retorno == 1) {

        printf("-----DELEÇÃO DE HOSPEDE-----\n");

        do {
            //pedindo ao usuario o codigo do hospede que deseja deletar
            printf("Digite o codigo do hospede que deseja deletar:");
            scanf("%d", &codigo_hospede);

            //funcao para procurar o hospede
            existe_hos = procura_hospede_bin(codigo_hospede);

            if (existe_hos == 1) {
                break;
            }

            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_hospedes_bin();
                break;
            }

        } while (sair == 0 || existe_hos == 0);

        printf("Deseja realmente deletar esse hospede?(1-Sim/0-Não): ");
        scanf("%d", &delete);

        if (delete == 1) {
            deleta_hospede_bin(codigo_hospede);
        }

    } else {
        printf("Não existe cadastro de hospedes.");
    }
    menu_gestao_hospedes_bin();
}
//FIM HOSPEDE


//COMEÇO PRODUTO
void main_cadastro_produtos_bin() {
    //variaveis para cadastro de produto
    produtos cadastro_produtos;
    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;

    //verificando se o arquvio de produtos ja existe 
    retorno = arquivo_existe_bin("Produtos.bin");


    //se existir trago os dados para ram para verificar se o codigo do hospede é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = qtd_itens_bin("Produtos.bin", sizeof (produtos));
        produtos produtoAT[quantidade];
        produtos_ram_bin(produtoAT);

        printf("-------Cadastro de produto--------\n");
        printf("Digite o codigo do produto:");
        scanf("%d", &cadastro_produtos.codigo);
        setbuf(stdin, NULL);

        posicao = procura_produto_txt(cadastro_produtos.codigo, quantidade, produtoAT);
        while (posicao != -1) {
            printf("Esse codigo de produto ja existe digite um diferente:");
            scanf("%d", &cadastro_produtos.codigo);
            posicao = procura_produto_txt(cadastro_produtos.codigo, quantidade, produtoAT);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_produtos_bin();
            }
        }
    } else {
        printf("-------Cadastro de produto--------\n");
        printf("Digite o código do produto:");
        scanf("%d", &cadastro_produtos.codigo);
        setbuf(stdin, NULL);
    }

    printf("Digite a descrição do produto:");
    setbuf(stdin, NULL);
    scanf(" %[^\n]s%*c", cadastro_produtos.descricao);
    setbuf(stdin, NULL);
    printf("Digite o estoque do produto:");
    scanf("%d", &cadastro_produtos.estoque);
    setbuf(stdin, NULL);
    printf("Digite o estoque mínimo do produto:");
    scanf("%d", &cadastro_produtos.estoque_min);
    setbuf(stdin, NULL);
    printf("Digite o preço de custo do produto:");
    scanf("%f", &cadastro_produtos.preco_custo);
    setbuf(stdin, NULL);
    printf("Digite o preço de venda do produto:");
    scanf("%f", &cadastro_produtos.preco_venda);
    setbuf(stdin, NULL);

    produtos_cad_bin(cadastro_produtos);
    menu_gestao_produtos_bin();
}

void main_atualiza_produtos_bin() {
    //variaveis utlizadas atualizar produtos
    produtos produtos_inf;
    int existe_prod = 0, posicao = 0;
    int codigo_produto;
    int retorno;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Produtos.bin");
    if (retorno == 1) {

        printf("-------ATUALIZA PRODUTO -------\n");

        do {
            //pedindo ao usuario o codigo do produto que deseja alterar
            printf("Digite o codigo do produto que deseja alterar:");
            scanf("%d", &codigo_produto);

            existe_prod = procura_produto_bin(codigo_produto);
            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_produtos_bin();
                break;
            }

            if (existe_prod == 1) {
                printf("Digite os novos dados para o produto: \n\n");

                printf("Digite o código do produto:");
                scanf("%d", &produtos_inf.codigo);
                setbuf(stdin, NULL);

                posicao = procura_produto_bin(produtos_inf.codigo);

                while (posicao == 1) {
                    printf("Esse codigo já está em uso, tente um diferente: ");
                    scanf("%d", &produtos_inf.codigo);

                    posicao = procura_produto_bin(produtos_inf.codigo);
                    contador_erro++;

                    if (contador_erro > 2) {
                        printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }

                    if (sair != 0) {
                        menu_gestao_produtos_bin();
                        break;
                    }
                }

                printf("Digite a descrição do produto:");
                setbuf(stdin, NULL);
                scanf(" %[^\n]s%*c", produtos_inf.descricao);
                setbuf(stdin, NULL);
                printf("Digite o estoque do produto:");
                scanf("%d", &produtos_inf.estoque);
                setbuf(stdin, NULL);
                printf("Digite o estoque mínimo do produto:");
                scanf("%d", &produtos_inf.estoque_min);
                setbuf(stdin, NULL);
                printf("Digite o preço de custo do produto:");
                scanf("%f", &produtos_inf.preco_custo);
                setbuf(stdin, NULL);
                printf("Digite o preço de venda do produto:");
                scanf("%f", &produtos_inf.preco_venda);
                setbuf(stdin, NULL);

                atualiza_produtos_bin(&produtos_inf, codigo_produto);
                menu_gestao_produtos_bin();
                break;
            }

        } while (sair == 0 || existe_prod == 0);

    } else {
        printf("Não existe cadastro de produtos.");
        menu_gestao_produtos_bin();
    }
}

void main_deleta_produtos_bin() {
    //variaveis utilizadas na deleção de produtos
    int existe_prod = 0;
    int codigo_produto;
    int retorno;
    int delete = 0;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Produtos.bin");

    if (retorno == 1) {

        printf("-----DELEÇÃO DE PRODUTO-----\n");

        do {
            //pedindo ao usuario o codigo do produto que deseja deletar
            printf("Digite o codigo do produto que deseja deletar:");
            scanf("%d", &codigo_produto);

            //funcao para procurar o produto
            existe_prod = procura_produto_bin(codigo_produto);

            if (existe_prod == 1) {
                break;
            }

            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_produtos_bin();
                break;
            }

        } while (sair == 0 || existe_prod == 0);

        printf("Deseja realmente deletar esse produto?(1-Sim/0-Não): ");
        scanf("%d", &delete);

        if (delete == 1) {
            deleta_produtos_bin(codigo_produto);
        }

    } else {
        printf("Não existe cadastro de produtos.");
    }
    menu_gestao_produtos_bin();
}
//FIM PRODUTO


//COMEÇO FORNECEDOR
void main_cadastro_fornecedor_bin() {
    //variveis utilizadas para cadastrar fornecedor
    fornecedores cadastro_fornecedor;
    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;

    //verificando se o arquvio de fornecedores ja existe 
    retorno = arquivo_existe_bin("Fornecedores.bin");


    //se existir trago os dados para ram para verificar se o codigo do fornecedor é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = qtd_itens_bin("Fornecedores.bin", sizeof (fornecedores));
        fornecedores fornecedorAT[quantidade];
        fornecedores_ram_bin(fornecedorAT);

        printf("-------CADASTRO DE FORNECEDORES-------\n");
        printf("Digite o codigo do fornecedor:");
        scanf("%d", &cadastro_fornecedor.codigo);

        posicao = procura_fornecedor_txt(cadastro_fornecedor.codigo, quantidade, fornecedorAT);
        while (posicao != -1) {
            printf("Esse codigo de fornecedor ja existe digite um diferente:");
            scanf("%d", &cadastro_fornecedor.codigo);
            posicao = procura_fornecedor_txt(cadastro_fornecedor.codigo, quantidade, fornecedorAT);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_fornecedor_bin();
            }
        }
    } else {
        printf("-------CADASTRO DE FORNECEDORES-------\n");
        printf("Digite o codigo do fornecedor:");
        scanf("%d", &cadastro_fornecedor.codigo);
    }

    printf("Digite o nome fantasia:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.nome_fantasia);
    setbuf(stdin, NULL);
    printf("Digite a razão social:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.razao_social);
    setbuf(stdin, NULL);
    printf("Digite a inscrição estadual:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.inscricao_estadual);
    setbuf(stdin, NULL);
    printf("Digite o CNPJ:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.cnpj);
    setbuf(stdin, NULL);
    printf("-------ENDEREÇO-------\n");
    printf("Digite o estado:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.endereco.estado);
    setbuf(stdin, NULL);
    printf("Digite a cidade:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.endereco.cidade);
    setbuf(stdin, NULL);
    printf("Digite o CEP:");
    scanf(" %[^\n]s%*c", &cadastro_fornecedor.endereco.cep);
    setbuf(stdin, NULL);
    printf("Digite o bairro:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.endereco.bairro);
    setbuf(stdin, NULL);
    printf("Digite a rua:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.endereco.rua);
    setbuf(stdin, NULL);
    printf("Digite o numero:");
    scanf("%d", &cadastro_fornecedor.endereco.numero);
    setbuf(stdin, NULL);
    printf("-------DADOS PARA CONTATO-------\n");
    printf("Digite o telefone do fornecedor:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.telefone);
    setbuf(stdin, NULL);
    printf("Digite o e-mail do fornecedor:");
    scanf(" %[^\n]s%*c", cadastro_fornecedor.email);
    setbuf(stdin, NULL);
    fornecedores_cad_bin(cadastro_fornecedor);
    menu_gestao_fornecedor_bin();
}

void main_atualiza_fornecedor_bin() {
    //variaveis utlizadas atualizar fornecedores
    fornecedores fornecedores_inf;
    int existe_forn = 0, posicao = 0;
    int codigo_fornecedores;
    int retorno;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Fornecedores.bin");
    if (retorno == 1) {

        printf("-------ATUALIZA FORNECEDORES -------\n");

        do {
            //pedindo ao usuario o codigo do fornecedor que deseja alterar
            printf("Digite o codigo do fornecedor que deseja alterar:");
            scanf("%d", &codigo_fornecedores);

            existe_forn = procura_fornecedor_bin(codigo_fornecedores);
            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_fornecedor_bin();
                break;
            }

            if (existe_forn == 1) {
                printf("Digite os novos dados para o fornecedor: \n\n");

                printf("Digite o codigo do fornecedor:");
                scanf("%d", &fornecedores_inf.codigo);

                posicao = procura_fornecedor_bin(fornecedores_inf.codigo);

                while (posicao == 1) {
                    printf("Esse codigo já está em uso, tente um diferente: ");
                    scanf("%d", &fornecedores_inf.codigo);

                    posicao = procura_fornecedor_bin(fornecedores_inf.codigo);
                    contador_erro++;

                    if (contador_erro > 2) {
                        printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }

                    if (sair != 0) {
                        menu_gestao_fornecedor_bin();
                        break;
                    }
                }

                printf("Digite o nome fantasia:");
                scanf(" %[^\n]s%*c", fornecedores_inf.nome_fantasia);
                setbuf(stdin, NULL);
                printf("Digite a razão social:");
                scanf(" %[^\n]s%*c", fornecedores_inf.razao_social);
                setbuf(stdin, NULL);
                printf("Digite a inscrição estadual:");
                scanf(" %[^\n]s%*c", fornecedores_inf.inscricao_estadual);
                setbuf(stdin, NULL);
                printf("Digite o CNPJ:");
                scanf(" %[^\n]s%*c", fornecedores_inf.cnpj);
                setbuf(stdin, NULL);
                printf("-------ENDEREÇO-------\n");
                printf("Digite o estado:");
                scanf(" %[^\n]s%*c", fornecedores_inf.endereco.estado);
                setbuf(stdin, NULL);
                printf("Digite a cidade:");
                scanf(" %[^\n]s%*c", fornecedores_inf.endereco.cidade);
                setbuf(stdin, NULL);
                printf("Digite o CEP:");
                scanf(" %[^\n]s%*c", &fornecedores_inf.endereco.cep);
                setbuf(stdin, NULL);
                printf("Digite o bairro:");
                scanf(" %[^\n]s%*c", fornecedores_inf.endereco.bairro);
                setbuf(stdin, NULL);
                printf("Digite a rua:");
                scanf(" %[^\n]s%*c", fornecedores_inf.endereco.rua);
                setbuf(stdin, NULL);
                printf("Digite o numero:");
                scanf("%d", &fornecedores_inf.endereco.numero);
                setbuf(stdin, NULL);
                printf("-------DADOS PARA CONTATO-------\n");
                printf("Digite o telefone do fornecedor:");
                scanf(" %[^\n]s%*c", fornecedores_inf.telefone);
                setbuf(stdin, NULL);
                printf("Digite o e-mail do fornecedor:");
                scanf(" %[^\n]s%*c", fornecedores_inf.email);
                setbuf(stdin, NULL);

                atualiza_fornecedores_bin(fornecedores_inf, codigo_fornecedores);
                menu_gestao_fornecedor_bin();
                break;
            }

        } while (sair == 0 || existe_forn == 0);

    } else {
        printf("Não existe cadastro de fornecedores.");
        menu_gestao_fornecedor_bin();
    }
}

void main_deleta_fornecedor_bin() {
    //variaveis utilizadas na deleção de fornecedor
    int existe_forn = 0;
    int codigo_fornecedores;
    int retorno;
    int delete = 0;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Fornecedores.bin");

    if (retorno == 1) {

        printf("-----DELEÇÃO DE FORNECEDOR-----\n");

        do {
            //pedindo ao usuario o codigo do fornecedor que deseja deletar
            printf("Digite o codigo do fornecedor que deseja deletar:");
            scanf("%d", &codigo_fornecedores);

            //funcao para procurar o fornecedor
            existe_forn = procura_fornecedor_bin(codigo_fornecedores);

            if (existe_forn == 1) {
                break;
            }

            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_fornecedor_bin();
                break;
            }

        } while (sair == 0 || existe_forn == 0);

        printf("Deseja realmente deletar esse fornecedor?(1-Sim/0-Não): ");
        scanf("%d", &delete);

        if (delete == 1) {
            deleta_fornecedor_bin(codigo_fornecedores);
        }

    } else {
        printf("Não existe cadastro de fornecedor.");
    }
    menu_gestao_fornecedor_bin();
}
//FIM FORNECEDOR


//COMEÇO CATEGORIA
void main_cadastro_categoria_bin() {
    //variaveis para cadastro de categorias de acomodações
    categoria_acomodacao cadastro_categoria;

    int retorno = 0, quantidade = 0, posicao = 0, contador_erro = 0, sair = 0;

    //verificando se o arquvio de fornecedores ja existe 
    retorno = arquivo_existe_bin("Categorias.bin");


    //se existir trago os dados para ram para verificar se o codigo do fornecedor é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        quantidade = qtd_itens_bin("Categorias.bin", sizeof (categoria_acomodacao));
        categoria_acomodacao categoriaAT[quantidade];
        categorias_ram_bin(categoriaAT);

        printf("-----Cadastro de categorias de acomodações-------\n");
        printf("Digite o codigo da categoria:");
        scanf("%d", &cadastro_categoria.codigo);

        posicao = procura_categoria_txt(cadastro_categoria.codigo, quantidade, categoriaAT);
        while (posicao != -1) {
            printf("Esse codigo de categoria ja existe digite um diferente:");
            scanf("%d", &cadastro_categoria.codigo);
            posicao = procura_categoria_txt(cadastro_categoria.codigo, quantidade, categoriaAT);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_categoria_bin();
            }
        }
    } else {
        printf("-----Cadastro de categorias de acomodações-------\n");
        printf("Digite o codigo da categoria:");
        scanf("%d", &cadastro_categoria.codigo);
    }



    printf("Digite a descrição da categoria(Exemplo:Standard,Luxo,Presidencial):");
    scanf(" %[^\n]s%*c", cadastro_categoria.descricao);
    printf("Digite o valor da diária:");
    scanf("%f", &cadastro_categoria.valor_diaria);
    printf("Quantidade de pessoas que comporta.\n");
    printf("Adultos:");
    scanf("%d", &cadastro_categoria.adultos);
    printf("Crianças:");
    scanf("%d", &cadastro_categoria.criancas);

    categoria_cad_bin(cadastro_categoria);
    menu_gestao_categoria_bin();
}

void main_atualiza_categoria_bin() {
    //variaveis utlizadas atualizar fornecedores
    categoria_acomodacao categorias_inf;
    int existe_cat = 0, posicao = 0;
    int codigo_categorias;
    int retorno;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Categorias.bin");
    if (retorno == 1) {

        printf("-------ATUALIZA CATEGORIA -------\n");

        do {
            //pedindo ao usuario o codigo da categoria que deseja alterar
            printf("Digite o codigo da categoria que deseja alterar:");
            scanf("%d", &codigo_categorias);

            existe_cat = procura_categoria_bin(codigo_categorias);
            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_categoria_bin();
                break;
            }

            if (existe_cat == 1) {
                printf("Digite os novos dados para a categoria: \n\n");

                printf("Digite o codigo da categoria:");
                scanf("%d", &categorias_inf.codigo);

                posicao = procura_categoria_bin(categorias_inf.codigo);

                while (posicao == 1) {
                    printf("Esse codigo já está em uso, tente um diferente: ");
                    scanf("%d", &categorias_inf.codigo);

                    posicao = procura_categoria_bin(categorias_inf.codigo);
                    contador_erro++;

                    if (contador_erro > 2) {
                        printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }

                    if (sair != 0) {
                        menu_gestao_categoria_bin();
                        break;
                    }
                }

                printf("Digite a descrição da categoria(Exemplo:Standard,Luxo,Presidencial):");
                scanf(" %[^\n]s%*c", categorias_inf.descricao);
                printf("Digite o valor da diária:");
                scanf("%f", &categorias_inf.valor_diaria);
                printf("Quantidade de pessoas que comporta.\n");
                printf("Adultos:");
                scanf("%d", &categorias_inf.adultos);
                printf("Crianças:");
                scanf("%d", &categorias_inf.criancas);

                atualiza_categorias_bin(categorias_inf, codigo_categorias);
                menu_gestao_categoria_bin();
                break;
            }

        } while (sair == 0 || existe_cat == 0);

    } else {
        printf("Não existe cadastro de categoria.");
        menu_gestao_categoria_bin();
    }
}

void main_deleta_categoria_bin() {
    //variaveis utilizadas na deleção de fornecedor
    int existe_cat = 0;
    int codigo_categorias;
    int retorno;
    int delete = 0;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Categorias.bin");

    if (retorno == 1) {

        printf("-----DELEÇÃO DE CATEGORIA-----\n");

        do {
            //pedindo ao usuario o codigo da categoria que deseja deletar
            printf("Digite o codigo da categoria que deseja deletar:");
            scanf("%d", &codigo_categorias);

            //funcao para procurar a categoria
            existe_cat = procura_categoria_bin(codigo_categorias);

            if (existe_cat == 1) {
                break;
            }

            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_categoria_bin();
                break;
            }

        } while (sair == 0 || existe_cat == 0);

        printf("Deseja realmente deletar essa categoria?(1-Sim/0-Não): ");
        scanf("%d", &delete);

        if (delete == 1) {
            deleta_categorias_bin(codigo_categorias);
        }

    } else {
        printf("Não existe cadastro de categoria.");
    }
    menu_gestao_categoria_bin();
}
//FIM CATEGORIA


//COMEÇO ACOMODACAO
void main_cadastro_acomodacao_bin() {
    //variaveis para cadastro de acomodações
    int qtd_aco = 0, retorno = 0, quantidade = 0, existe = 0, contador_erro = 0, sair = 0, posicao = 0;
    acomodacoes cadastro_acomodacoes;

    //verificando se o arquvio de fornecedores ja existe 
    retorno = arquivo_existe_bin("Acomodacoes.bin");


    //se existir trago os dados para ram para verificar se o codigo do fornecedor é igual a outro ja cadastrado 
    if (retorno == 1) {
        //trazendo operadores para ram
        qtd_aco = qtd_itens_bin("Acomodacoes.bin", sizeof (acomodacoes));
        acomodacoes acomodacoesAT[qtd_aco];
        acomodacoes_ram_bin(acomodacoesAT);

        printf("-----Cadastro de acomodações-------\n");
        printf("Digite o codigo da acomodação:");
        scanf("%d", &cadastro_acomodacoes.codigo);

        posicao = procura_acomodacao_txt(cadastro_acomodacoes.codigo, qtd_aco, acomodacoesAT);
        while (posicao != -1) {
            printf("Esse codigo de acomodação ja existe digite um diferente:");
            scanf("%d", &cadastro_acomodacoes.codigo);
            posicao = procura_acomodacao_txt(cadastro_acomodacoes.codigo, qtd_aco, acomodacoesAT);
            contador_erro++;
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros de codigo deseja sair dessa função?(1-Sim/0-Não):");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                menu_gestao_acomodacao_bin();
            }
        }
    } else {
        printf("-----Cadastro de acomodações-------\n");
        printf("Digite o codigo da acomodação:");
        scanf("%d", &cadastro_acomodacoes.codigo);
    }


    printf("Digite a descrição da acomodação:");
    scanf(" %[^\n]s%*c", cadastro_acomodacoes.descricao);
    printf("Digite as facilidades da acomodação.\n"
            "Coloque uma virgula após cada facilidade\n"
            "(Ex:Ar condiciona,TV,Cama King Size):");
    scanf(" %[^\n]s%*c", cadastro_acomodacoes.facilidades);
    printf("Digite o codigo de categoria da acomodação:");
    scanf("%d", &cadastro_acomodacoes.categoria);


    quantidade = qtd_itens_bin("Categorias.bin", sizeof (categoria_acomodacao));
    categoria_acomodacao categoriaEXI[quantidade];
    categorias_ram_bin(categoriaEXI);

    existe = procura_categoria_txt(cadastro_acomodacoes.categoria, quantidade, categoriaEXI);

    while (existe == -1) {
        printf("Essa categoria não existe digite uma existente:");
        scanf("%d", &cadastro_acomodacoes.categoria);

        existe = procura_categoria_txt(cadastro_acomodacoes.categoria, quantidade, categoriaEXI);
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
        cadastro_acomodacoes.ocupacao = 0;
        cadastro_acomodacoes.diarias = 0;
        cadastro_acomodacoes.lucro = 0;
        acomodacoes_cad_bin(cadastro_acomodacoes);

        contador_erro = 0;
    }
    menu_gestao_acomodacao_bin();
}

void main_atualiza_acomodacao_bin() {
    //variaveis utlizadas atualizar fornecedores
    acomodacoes acomodacoes_inf;
    int existe_aco = 0, posicao = 0;
    int existe_cat = 0;
    int codigo_acomodacoes;
    int retorno;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Acomodacoes.bin");
    if (retorno == 1) {

        printf("-------ATUALIZA ACOMODAÇÃO -------\n");

        do {
            //pedindo ao usuario o codigo da acomodação que deseja alterar
            printf("Digite o codigo da acomodação que deseja alterar:");
            scanf("%d", &codigo_acomodacoes);

            existe_aco = procura_acomodacao_bin(codigo_acomodacoes);
            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_acomodacao_bin();
                break;
            }

            if (existe_aco == 1) {
                printf("Digite os novos dados para a acomodação: \n\n");

                printf("Digite o codigo da acomodação:");
                scanf("%d", &acomodacoes_inf.codigo);

                posicao = procura_acomodacao_bin(acomodacoes_inf.codigo);

                while (posicao == 0) {
                    printf("Esse codigo já está em uso, tente um diferente: ");
                    scanf("%d", &acomodacoes_inf.codigo);

                    posicao = procura_acomodacao_bin(acomodacoes_inf.codigo);
                    contador_erro++;

                    if (contador_erro > 2) {
                        printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }

                    if (sair != 0) {
                        menu_gestao_acomodacao_bin();
                        break;
                    }
                }

                printf("Digite a descrição da acomodação:");
                scanf(" %[^\n]s%*c", acomodacoes_inf.descricao);
                printf("Digite as facilidades da acomodação.\n"
                        "Coloque uma virgula após cada facilidade\n"
                        "(Ex:Ar condiciona,TV,Cama King Size):");
                scanf(" %[^\n]s%*c", acomodacoes_inf.facilidades);
                printf("Digite o codigo de categoria da acomodação:");
                scanf("%d", &acomodacoes_inf.categoria);

                existe_cat = procura_categoria_bin(acomodacoes_inf.categoria);

                while (existe_cat == 0) {
                    printf("Tente novamente com um código válido: ");
                    scanf("%d", &acomodacoes_inf.categoria);

                    existe_cat = procura_categoria_bin(acomodacoes_inf.categoria);
                    contador_erro++;

                    if (contador_erro > 2) {
                        printf("Ocorreu muitos erros, deseja sair dessa função?(1-Sim/0-Não): ");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }
                    if (sair == 1) {
                        menu_gestao_acomodacao_bin();
                        break;
                    }
                }

                if (sair == 0) {
                    atualiza_acomodacoes_bin(acomodacoes_inf, codigo_acomodacoes);
                    menu_gestao_acomodacao_bin();
                    break;
                }
            }
        } while (sair == 0 || existe_aco == 0);

    } else {
        printf("Não existe cadastro de acomodações.");
        menu_gestao_acomodacao_bin();
    }
}

void main_deleta_acomodacao_bin() {
    //variaveis utilizadas na deleção de fornecedor
    int existe_aco = 0;
    int codigo_acomodacoes;
    int retorno;
    int delete = 0;
    int sair = 0, contador_erro = 0;

    retorno = arquivo_existe_bin("Acomodacoes.bin");

    if (retorno == 1) {

        printf("-----DELEÇÃO DE ACOMODAÇÃO-----\n");

        do {
            //pedindo ao usuario o codigo da acomodação que deseja deletar
            printf("Digite o codigo da acomodação que deseja deletar:");
            scanf("%d", &codigo_acomodacoes);

            //funcao para procurar a acomodação
            existe_aco = procura_acomodacao_bin(codigo_acomodacoes);

            if (existe_aco == 1) {
                break;
            }

            contador_erro++;

            if (contador_erro > 2) {
                printf("Foi detectado muitos erros de codigo, deseja sair dessa função?(1-Sim/0-Não): ");
                scanf("%d", &sair);
                contador_erro = 0;
            }

            if (sair != 0) {
                menu_gestao_acomodacao_bin();
                break;
            }

        } while (sair == 0 || existe_aco == 0);

        printf("Deseja realmente deletar essa acomodação?(1-Sim/0-Não): ");
        scanf("%d", &delete);

        if (delete == 1) {
            deleta_acomodacoes_bin(codigo_acomodacoes);
        }

    } else {
        printf("Não existe cadastro de acomodações.");
    }
    menu_gestao_acomodacao_bin();
}
//FIM ACOMODACAO

//INICIO MODOULO DE RESERVAS
//filtros para cadastro de reservas
void main_filtros_bin() {
    //variaveis utilizadas para fazer reservas
    reservas reserva;
    data_chek_in_out datas;
    int retorno, criancas, adultos, qtd_aco = 0, qtd_hos = 0, qtd_cat = 0, qtd_res = 0, sair = 0, ret_reserva = 0, ret_data = 0, pos_res = 0, pos_cat, categoria_filtro, pessoas_filtro, facilidades_filtro;
    int pos_aco = 0, pos_hos = 0, cod_aco = 0, cod_hos, contador_erro = 0, opcao = 0, cod_res = 0, qtd_dis, cod_cat, data_filtro = 0;
    char facilidade[20];
    float valor;
    int diaria;
    
    
    //trazendo acomodacoes para ram
    qtd_aco = qtd_itens_bin("Acomodacoes.bin", sizeof (acomodacoes));
    acomodacoes acomodacaoRAM [qtd_aco];
    acomodacoes_ram_bin(acomodacaoRAM);


    //pegando todos dados que serao utilizados para memoria ram
    qtd_res = qtd_itens_bin("Reservas.bin", sizeof (reservas));
    qtd_dis = qtd_aco + qtd_res;

    //trazendo reservas para ram
    reservas reservasRAM[qtd_res];
    reservas_ram_bin(reservasRAM);
    reservas disponiveis[qtd_dis];



    //trazendo hospedes para ram
    qtd_hos = qtd_itens_bin("Hospedes.bin", sizeof (hospedes));
    hospedes hospedesRES[qtd_hos];
    hospede_ram_bin(hospedesRES);

    //trazendo categorias para ram
    qtd_cat = qtd_itens_bin("Categorias.bin", sizeof (categoria_acomodacao));
    categoria_acomodacao categoriaRAM[qtd_cat];
    categorias_ram_bin(categoriaRAM);

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
                menu_modulo_reservas_bin();
            }
        }
        printf("------Quartos Disponiveis------\n");

        qtd_dis = data_disponivel_txt(disponiveis, reservasRAM, acomodacaoRAM, qtd_res, qtd_aco, datas, categoriaRAM, qtd_cat);
        if (qtd_dis == 0) {
            menu_modulo_reservas_bin();
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
            printa_categoria_txt(qtd_cat, categoriaRAM);
            printf("Digite o codigo de uma dessas categorias:");
            scanf("%d", &cod_cat);

            //verifica se o codigo da categoria é valido
            pos_cat = procura_categoria_txt(cod_cat, qtd_cat, categoriaRAM);

            //se nao for entra em um loop
            while (pos_cat == -1) {
                contador_erro++;
                printf("Digite uma categoria válida:");
                scanf("%d", &cod_cat);
                pos_cat = procura_categoria_txt(cod_cat, qtd_cat, categoriaRAM);
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair == 1) {
                    contador_erro = 0;
                    menu_modulo_reservas_bin();
                }
            }

            printf("\tAcomodações disponíveis com a categoria digitada.\n\n");
            qtd_dis = categoria_disponivel_txt(cod_cat, qtd_aco, acomodacaoRAM, categoriaRAM, pos_cat, disponiveis);
            if (qtd_dis == -1) {
                menu_modulo_reservas_bin();
            }
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código da Acomodação: %d\n", disponiveis[i].codigo_aco);
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
                    menu_modulo_reservas_bin();
                }
            }

            printf("\tAcomodações disponíveis com a categoria digitada.\n\n");
            qtd_dis = filtro_categoria_filtrada_txt(disponiveis, disponiveis, qtd_dis, cod_cat);
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código da Acomodação: %d\n", disponiveis[i].codigo_aco);
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
            qtd_dis = pessoas_disponivel_txt(criancas, adultos, qtd_cat, qtd_aco, categoriaRAM, acomodacaoRAM, disponiveis);
            if (qtd_dis == -1) {
                menu_modulo_reservas_bin();
            }


            for (int i = 0; i < qtd_dis; i++) {
                printf("Código da Acomodação: %d\n", disponiveis[i].codigo_aco);
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
                    menu_modulo_reservas_bin();
                }
            }
            printf("\tAcomodações disponíveis com a quantidade de pessoas digitada.\n\n");
            qtd_dis = filtro_pessoas_filtrada(criancas, adultos, disponiveis, disponiveis, qtd_dis);
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código da Acomodação: %d\n", disponiveis[i].codigo_aco);
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
            qtd_dis = facilidades_disponiveis_txt(facilidade, acomodacaoRAM, qtd_aco, disponiveis, categoriaRAM, qtd_cat);
            if (qtd_dis == -1) {
                menu_modulo_reservas_bin();
            }
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código da Acomodação: %d\n", disponiveis[i].codigo_aco);
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
                    menu_modulo_reservas_bin();
                }
            }
            printf("\tAcomodações disponíveis com a facilidade digitada.\n\n");
            qtd_dis = filtro_facilidades_filtrada_txt(facilidade, disponiveis, disponiveis, qtd_dis);
            for (int i = 0; i < qtd_dis; i++) {
                printf("Código da Acomodação: %d\n", disponiveis[i].codigo_aco);
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
    if (facilidades_filtro == 1 || categoria_filtro == 1 || pessoas_filtro == 1 || data_filtro == 1) {
        printf("Digite o código da acomodação que deseja reservar:");
        scanf("%d", &cod_aco);
        pos_aco = procura_acomodacao_disponivel(qtd_dis, cod_aco, disponiveis, acomodacaoRAM, qtd_aco);
        while (pos_aco == -1) {
            contador_erro++;
            printf("Esse codigo de acomodação não está disponível digite um válido::");
            scanf("%d", &cod_res);
            pos_aco = procura_acomodacao_disponivel(qtd_dis, cod_aco, disponiveis, acomodacaoRAM, qtd_aco);
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas_bin();
            }
        }
        if (data_filtro == 0) {
            if (acomodacaoRAM[pos_aco].ocupacao == 0) {
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
                        menu_modulo_reservas_bin();
                    }
                }
            } else {
                printf("Essa acomodação não esta disponivel nessas datas,lembrando que uma dessas datas é a da própria reserva que esta sendo atualizada.\n");
                procura_data_reserva_bin(cod_aco);
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
                        menu_modulo_reservas_bin();
                    }
                }
                //verifico se a data que o usuario digitou nao bate com nenhuma outra
                ret_reserva = verifica_data_txt(qtd_res, reservasRAM, datas, cod_aco);
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
                            menu_modulo_reservas_bin();
                        }
                    }
                    contador_erro++;
                    ret_reserva = verifica_data_txt(qtd_res, reservasRAM, datas, cod_aco);
                    if (contador_erro > 2) {
                        printf("Voce digitou varias datas que ja estao ocupadas deseja sair?(1-Sim/0-Não):");
                        scanf("%d", &sair);
                        contador_erro = 0;
                    }
                    if (sair != 0) {
                        contador_erro = 0;
                        menu_modulo_reservas_bin();
                    }
                }
            }
        }

        printf("Digite um codigo para a reserva:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res,qtd_res,reservasRAM);
        while (pos_res != -1) {
            contador_erro++;
            printf("Esse codigo de reserva ja esta em uso digite um valido:");
            scanf("%d", &cod_res);
            pos_res = procura_reserva_txt(cod_res,qtd_res,reservasRAM);
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas_bin();
            }
        }

        printf("Digite o codigo do hospede que deseja fazer a reserva:");
        scanf("%d", &cod_hos);
        pos_hos = procura_hospede_bin(cod_hos);
        while (pos_hos == 0) {
            contador_erro++;
            printf("Digite um codigo de hospede valido:");
            scanf("%d", &cod_hos);
            pos_hos = procura_hospede_bin(cod_hos);
            if (contador_erro > 2) {
                printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
                scanf("%d", &sair);
                contador_erro = 0;
            }
            if (sair != 0) {
                contador_erro = 0;
                menu_modulo_reservas_bin();
            }
        }
        
        
        diaria=contarDias(datas);
        
        pos_cat=procura_categoria_txt(acomodacaoRAM[pos_aco].categoria,qtd_cat,categoriaRAM);
        
        valor=categoriaRAM[pos_cat].valor_diaria*diaria;
        
        reservas_cad_bin(datas, cod_aco, cod_hos, cod_res);
        
        soma_ocupantes_acm_bin(cod_aco,valor,diaria);
        menu_modulo_reservas_bin();
    }
    menu_modulo_reservas_bin();

}

//funcao para cancelar reserva
void main_deleta_reserva_bin() {
    //variaveis para deletar reserva

    int retorno = 0, sair = 0, codigo = 0, contador_erro = 0, delete = 0, pos_res;
    int codigo_aco,pos_cat;
    int dias, qtd_res, qtd_cat;
    float valor;
    
    
    retorno = arquivo_existe_bin("Reservas.bin");
    if (retorno == 0) {
        printf("Nenhuma reserva cadastrada.\n\n");
        menu_modulo_reservas_bin();
    }
    
    qtd_cat = qtd_itens_bin("Categorias.bin", sizeof (categoria_acomodacao));
    categoria_acomodacao categoriaRAM[qtd_cat];
    categorias_ram_bin(categoriaRAM);

    qtd_res = qtd_itens_bin("Reservas.bin", sizeof (reservas));
    reservas reservasRAM[qtd_res];
    reservas_ram_bin(reservasRAM);
    

    printf("--------Cancelar reservas----------\n");
    printf("Digite o codigo da reserva que deseja cancelar:");
    scanf("%d", &codigo);
    pos_res = procura_reserva_bin(codigo);
    while (pos_res == 0) {
        //pedindo ao usuario o codigo da reserva que deseja alterar
        printf("Digite um codigo de reserva válido:");
        scanf("%d", &codigo);

        //funcao para procurar a reserva
        pos_res = procura_reserva_txt(codigo,qtd_res,reservasRAM);

        if (contador_erro > 3) {
            printf("Foi detectado muitos erros, deseja sair dessa função?(1-Sim/0-Não):");
            scanf("%d", &sair);
        }
        if (sair == 1) {
            contador_erro = 0;
            menu_modulo_reservas_bin();
        }

    }

    codigo_aco = print_reserva_bin(codigo);

    printf("Realmente deseja cancelar essa reserva?(1-Sim/0-Não):");
    scanf("%d", &delete);
    if (delete == 1) {
             
        pos_cat = procura_categoria_txt(reservasRAM[pos_res].categoria.codigo, qtd_cat, categoriaRAM);
        
        dias = contarDias(reservasRAM[pos_res].datas);
        valor = dias * categoriaRAM[pos_cat].valor_diaria;
        
        diminui_ocupantes_valor_acm_bin(codigo_aco,valor,dias);
        deleta_reservas_bin(codigo);
    }

    menu_modulo_reservas_bin();
}
//FIM MODOULO DE RESERVAS



//COMECO TRANSAÇÕES BIN
//fazendo o chekin do hospede
void main_chekin_bin() {
    int cod_res, qtd_res, pos_res, sair = 0, contador_erro = 0, opcao, pagamento, dias;
    float valor;

    data date;
    data_chek_in_out datas;
    conta_hospede conta;

    qtd_res = qtd_itens_bin("Reservas.bin", sizeof (reservas));
    reservas reservasRAM[qtd_res];
    reservas_ram_bin(reservasRAM);

    printf("------CHECK-IN--------\n");
    printf("Digite o código da reserva para fazer o check-in:");
    scanf("%d", &cod_res);
    pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);
    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);

        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }

        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_bin();
        }
    }
    //aqui eu trago a data de reserva para calcular quantos dias o hospede vai ficar no hotel
    datas.ano_in = reservasRAM[pos_res].datas.ano_in;
    datas.mes_in = reservasRAM[pos_res].datas.mes_in;
    datas.dia_in = reservasRAM[pos_res].datas.dia_in;
    datas.ano_out = reservasRAM[pos_res].datas.ano_out;
    datas.mes_out = reservasRAM[pos_res].datas.mes_out;
    datas.dia_out = reservasRAM[pos_res].datas.dia_out;

    //contando a diferenca de dias entre as datas
    dias = contarDias(datas);
    //calculando o valor da diaria
    valor = dias * reservasRAM[pos_res].categoria.valor_diaria;

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

            //salvando no caixa  o valor pago pelo hospede
            adiciona_caixa_bin(valor, reservasRAM[pos_res].cod_hospede, 0);

            conta.codigo_hos = reservasRAM[pos_res].cod_hospede;
            conta.codigo_res = reservasRAM[pos_res].codigo_res;
            conta.valor_devido = 0;
            //criando a conta do hospede para se ele for comprar algo
            conta_hospede_cad_bin(conta);

        } else if (pagamento == 2 || pagamento == 3) {

            printf("Digite a data do vencimento do cartão do hóspede.\n");
            printf("Dia:");
            scanf("%d", &date.dia);
            printf("Mês:");
            scanf("%d", &date.mes);
            printf("Ano:");
            scanf("%d", &date.ano);

            adicionar_contas_a_receber_bin(date, reservasRAM[pos_res].cod_hospede, valor);

            conta.codigo_hos = reservasRAM[pos_res].cod_hospede;
            conta.codigo_res = reservasRAM[pos_res].codigo_res;
            conta.valor_devido = 0;
            //criando a conta do hospede para se ele for comprar algo
            conta_hospede_cad_bin(conta);
        }
    } else if (opcao == 2) {
        conta.codigo_hos = reservasRAM[pos_res].cod_hospede;
        conta.codigo_res = reservasRAM[pos_res].codigo_res;
        conta.valor_devido = valor;
        //criando a conta do hospede para se ele for comprar algo
        conta_hospede_cad_bin(conta);
    }

    menu_modulo_transacoes_bin();
}

//fazendo o chekout do hospede
void main_chekout_bin() {

    int cod_res, qtd_res, pos_res, sair = 0, contador_erro = 0;
    int opcao, pagamento, qtd_con, pos_con, qtd_aco, pos_aco;

    data date;

    qtd_res = qtd_itens_bin("Reservas.bin", sizeof (reservas));
    reservas reservasRAM[qtd_res];
    reservas_ram_bin(reservasRAM);

    qtd_con = qtd_itens_bin("Contas_hospede.bin", sizeof (conta_hospede));
    conta_hospede contasRAM[qtd_con];
    conta_hospede_ram_bin(contasRAM);

    qtd_aco = qtd_itens_bin("Acomodacoes.bin", sizeof (acomodacoes));
    acomodacoes acomodacaoRAM [qtd_aco];
    acomodacoes_ram_bin(acomodacaoRAM);

    printf("------CHECK-OUT--------\n");

    printf("Digite o código da reserva para fazer o check-out:");
    scanf("%d", &cod_res);
    pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);

    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);

        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_bin();
        }
    }

    pos_con = procura_conta_txt(cod_res, contasRAM, qtd_con);
    if (contasRAM[pos_con].valor_devido == 0) {

        printf("Você não possui nenhum saldo devedor.\n");
        //deletando a reserva apos o chekout
        deleta_reservas_bin(cod_res);

        //diminuindo a ocupação da acomodação
        diminui_ocupantes_acm_bin(reservasRAM[pos_res].codigo_aco);

        //deletando a conta do hospede
        deleta_conta_hospede_bin(reservasRAM[pos_res].cod_hospede);

    } else {
        printf("O saldo devedor do hóspede é de:%.2f reais.\n", contasRAM[pos_con].valor_devido);
        printf("Como deseja pagar?\n");
        printf("1-Dinheiro.\n");
        printf("2-Cartão de crédito.\n");
        printf("3-Cartão de débito.\n");
        printf("Digite a opção desejada:");
        scanf("%d", &pagamento);
        if (pagamento == 1) {

            //salvando no caixa  o valor pago pelo hospede
            adiciona_caixa_bin(contasRAM[pos_con].valor_devido, reservasRAM[pos_res].cod_hospede, 0);

            //deletando a reserva ja que o hospede ja saiu do quarto
            deleta_reservas_bin(reservasRAM[pos_con].codigo_res);

            //diminuindo a ocupação da acomodação
            diminui_ocupantes_acm_bin(reservasRAM[pos_res].codigo_aco);

            //deletando a conta do hospede
            deleta_conta_hospede_bin(reservasRAM[pos_res].cod_hospede);

        } else if (pagamento == 2 || pagamento == 3) {
            printf("Digite a data do vencimento do cartão do hóspede.\n");
            printf("Dia:");
            scanf("%d", &date.dia);
            printf("Mês:");
            scanf("%d", &date.mes);
            printf("Ano:");
            scanf("%d", &date.ano);

            adicionar_contas_a_receber_bin(date, reservasRAM[pos_res].cod_hospede, contasRAM[pos_con].valor_devido);

            //deletando a reserva ja que o hospede ja saiu do quarto
            deleta_reservas_bin(reservasRAM[pos_res].codigo_res);

            //diminuindo a ocupação da acomodação
            diminui_ocupantes_acm_bin(reservasRAM[pos_res].codigo_aco);

            //deletando a conta do hospede
            deleta_conta_hospede_bin(reservasRAM[pos_res].cod_hospede);
        }
    }
    menu_modulo_transacoes_bin();
}

//fazendo as vendas de produtos do hotel
void main_venda_bin() {
    int pos_con, qtd_con, qtd_prod, pos_prod, contador_erro = 0, sair = 0, pagamento, cod_res, pos_res, qtd_res;
    vendas venda;
    
    qtd_con = qtd_itens_bin("Contas_hospede.bin", sizeof (conta_hospede));
    conta_hospede contasRAM[qtd_con];
    conta_hospede_ram_bin(contasRAM);

    qtd_res = qtd_itens_bin("Reservas.bin", sizeof (reservas));
    reservas reservasRAM[qtd_res];
    reservas_ram_bin(reservasRAM);

    qtd_prod = qtd_itens_bin("Produtos.bin", sizeof (produtos));
    produtos produtosRAM[qtd_prod];
    produtos_ram_bin(produtosRAM);

    printf("-----VENDAS-------\n");
    printf("Digite o código da reserva do hóspede que está comprando:");
    scanf("%d", &cod_res);
    pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);

    while (pos_res == -1) {
        contador_erro++;
        printf("Esse codigo de reserva não existe, digite um válido:");
        scanf("%d", &cod_res);
        pos_res = procura_reserva_txt(cod_res, qtd_res, reservasRAM);

        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_bin();
        }
    }

    printf("PRODUTOS DISPONÍVEIS:\n");
    mostra_produto_txt(qtd_prod, produtosRAM);

    printf("Digite o código do produto que deseja:");
    scanf("%d", &venda.cod_prod);
    pos_prod = procura_produto_txt(venda.cod_prod, qtd_prod, produtosRAM);

    while (pos_prod == -1) {
        contador_erro++;
        printf("Esse codigo de produto não existe, digite um válido:");
        scanf("%d", &venda.cod_prod);
        pos_prod = procura_produto_txt(venda.cod_prod, qtd_prod, produtosRAM);

        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_bin();
        }
    }
    printf("Quantos desse produto deseja comprar?:");
    scanf("%d", &venda.qtd);
    while (venda.qtd > produtosRAM[pos_prod].estoque) {
        contador_erro++;
        printf("Não tem estoque disponível para essa quantidade,digite uma quantidade que tenha no estoque:");
        scanf("%d", &venda.qtd);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_modulo_transacoes_bin();
        }
    }
    venda.valor = venda.qtd * produtosRAM[pos_prod].preco_venda;
    printf("Qual a forma de pagamento?\n");
    printf("1-A vista.\n");
    printf("2-Anotar.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &pagamento);
    if (pagamento == 1) {
        venda.pagamento=pagamento;
        venda.cod_hos=reservasRAM[pos_res].cod_hospede;
        
        cadastrar_venda_bin(venda);
        //salvando no caixa  o valor pago pelo hospede
        adiciona_caixa_bin(venda.valor, reservasRAM[pos_res].cod_hospede, 0);

        //atualizando o estoque
        atualiza_estoque_bin(venda.qtd, venda.cod_prod);


    } else if (pagamento == 2) {
        venda.pagamento=pagamento;
        venda.cod_hos=reservasRAM[pos_res].cod_hospede;
        //fazendo a notinha
        printf("\n-------NOTINHA---------\n");
        printf("Codigo do hóspede:%d\n", venda.cod_hos);
        printf("Codigo do produto:%d\n", venda.cod_prod);
        printf("Nome do produto:%s\n", produtosRAM[pos_prod].descricao);
        printf("Quantidade:%d\n", venda.qtd);
        printf("Valor unitário:%.2f\n", produtosRAM[pos_prod].preco_venda);
        printf("Valor total da notinha:%.2f\n\n", venda.valor);

        cadastrar_venda_bin(venda);
        //adicionando o valor comprando na conta do hospede
        pos_con = procura_conta_txt(cod_res, contasRAM, qtd_con);

        contasRAM[pos_con].valor_devido = contasRAM[pos_con].valor_devido + venda.valor;
        atualiza_conta_hospede_bin(contasRAM[pos_con], contasRAM[pos_con].codigo_hos);

        //atualizando o estoque
        atualiza_estoque_bin(venda.qtd, venda.cod_prod);
    }
    menu_modulo_transacoes_bin();
}

//listando os movimentos de caixa
void main_caixa_bin() {
    int qtd_caixa, existe;

    existe = arquivo_existe_bin("Caixa.bin");
    if (existe == 0) {
        printf("Não tem nenhum movimento no caixa.\n");
        menu_modulo_transacoes_bin();
    }
    printf("-----CONTROLE DE CAIXA------\n");
    dados_caixa_bin();
    menu_modulo_transacoes_bin();
}

//dando baixa nas contas a receber
void main_receber_bin() {
    int cod_conta, qtd_conta, sair = 0, contador_erro = 0, existe;

    existe = arquivo_existe_bin("Contas_receber.bin");
    if (existe == 0) {
        printf("Não tem nenhuma conta a receber.\n");
        menu_conta_receber_bin();
    }

    qtd_conta = qtd_itens_bin("Contas_hospede.bin", sizeof (conta_hospede));
    conta_hospede contasRAM[qtd_conta];
    conta_hospede_ram_bin(contasRAM);




    printf("\n-----CONTAS A RECEBER------\n");
    dados_conta_a_receber_bin();
    printf("Digite a conta que deseja dar baixa:");
    scanf("%d", &cod_conta);
    while (cod_conta + 1 > qtd_conta) {
        printf("Digite uma conta válida que deseja dar baixa:");
        scanf("%d", &cod_conta);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_conta_receber_bin();
        }
    }
    adiciona_caixa_bin(contasRAM[cod_conta].valor_devido, contasRAM[cod_conta].codigo_hos, 0);
    deleta_conta_a_receber_bin(contasRAM[cod_conta].codigo_hos);
    menu_conta_receber_bin();
}

//listando todas contas a receber
void main_listar_conta_receber_bin() {
    int existe;
    existe = arquivo_existe_bin("Contas_receber.bin");
    if (existe == 0) {
        printf("Não tem nenhuma conta a receber.\n");
        menu_conta_receber_bin();
    }

    printf("\n--------LISTA DE CONTAS A RECEBER--------\n");
    dados_conta_a_receber_bin();
    menu_conta_receber_bin();
}

//dando entrada de produtos por notas fiscais
void main_entrada_produtos_bin() {
    float frete_prod, imposto_prod, entrada;
    float total = 0, prazo = 0, saldo = 0;
    int vezes, qtd_for, pos_for, contador_erro = 0, retorno, sair = 0, pagamento, qtd_caixa;
    int qtd_total = 0, qtd_prod, pos_prod, estoque_min, cod_prod;
    
    produtos ATprodutos;
    NotaFiscal notas;
    notas.num_produtos = 0;
    notas.total = 0;
    notas.entra_prod = NULL;

    produtos cadastroPROD;

    cad_hotel ramHT[1];
    hotel_ram_bin(ramHT);

    qtd_for = qtd_itens_bin("Fornecedores.bin", sizeof (fornecedores));
    fornecedores fornecedorRAM[qtd_for];
    fornecedores_ram_bin(fornecedorRAM);

    printf("\n-------ENTRADA DE NOTAS--------\n");
    printf("Digite o nome do fornecedor:");
    scanf(" %[^\n]s%*c", notas.fornecedor);

    pos_for = procura_fornecedor_nome_txt(notas.fornecedor, qtd_for, fornecedorRAM);
    if (pos_for == -1) {
        printf("Vejo que esse fornecedor não está cadastrado, cadastre ele primeiro.\n");
        main_cadastro_fornecedor_bin();
    }

    setbuf(stdin, NULL);
    printf("Digite o valor do frete:");
    scanf("%f", &notas.frete);
    printf("Digite o valor do imposto:");
    scanf("%f", &notas.imposto);

    while (sair == 0) {
        notas.entra_prod = realloc(notas.entra_prod, (notas.num_produtos + 1) * sizeof (entrada_produto));

        if (notas.entra_prod == NULL) {
            perror("Erro ao alocar memória");
            exit(EXIT_FAILURE);
        }

        // Ler informações do usuário
        printf("Digite a descrição do produto: ");
        scanf(" %[^\n]s%*c", notas.entra_prod[notas.num_produtos].nome);
        setbuf(stdin, NULL);
        printf("Digite o preço do produto: ");
        scanf("%f", &notas.entra_prod[notas.num_produtos].preco);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &notas.entra_prod[notas.num_produtos].quantidade);

        // Calcular subtotal
        notas.entra_prod[notas.num_produtos].subtotal =
                notas.entra_prod[notas.num_produtos].preco * notas.entra_prod[notas.num_produtos].quantidade;

        // Atualizar total da nota e quantidade total
        notas.total += notas.entra_prod[notas.num_produtos].subtotal;
        qtd_total += notas.entra_prod[notas.num_produtos].quantidade;

        // Verificar se há mais produtos
        printf("A nota possui mais produtos? (0-Sim/1-Não): ");
        scanf("%d", &sair);

        notas.num_produtos++;
    }

    imposto_prod = notas.imposto / qtd_total;
    frete_prod = notas.frete / qtd_total;

    for (int i = 0; i < notas.num_produtos; i++) {
        // Trazendo produtos para a memória RAM
        qtd_prod = qtd_itens_bin("Produtos.bin", sizeof (produtos));
        produtos produtosRAM[qtd_prod];
        produtos_ram_bin(produtosRAM);

        retorno = procura_produto_nome_txt(notas.entra_prod[i].nome, qtd_prod, produtosRAM);
        if (retorno == -1) {
            printf("O produto %s ainda não foi cadastrado.\n",notas.entra_prod[i].nome);
            printf("Digite o estoque mínimo para o cadastro:");
            scanf("%d", &estoque_min);
            printf("Digite um código para o produto:");
            scanf("%d", &cod_prod);
            pos_prod = procura_produto_txt(cod_prod, qtd_prod, produtosRAM);
            sair = 0;
            while (pos_prod != -1) {
                printf("Esse código de produto já existe, digite um diferente:");
                scanf("%d", &cod_prod);
                pos_prod = procura_produto_txt(cod_prod, qtd_prod, produtosRAM);
                contador_erro++;
                if (contador_erro > 2) {
                    printf("Ocorreu muitos erros de código, deseja sair dessa função? (1-Sim/0-Não):");
                    scanf("%d", &sair);
                    contador_erro = 0;
                }
                if (sair != 0) {
                    menu_modulo_transacoes_bin();
                }
            }

            cadastroPROD.codigo = cod_prod;
            strcpy(cadastroPROD.descricao, notas.entra_prod[i].nome);
            cadastroPROD.estoque = notas.entra_prod[i].quantidade;
            cadastroPROD.estoque_min = estoque_min;
            cadastroPROD.preco_custo = notas.entra_prod[i].preco;
            cadastroPROD.preco_venda = (frete_prod + imposto_prod + notas.entra_prod[i].preco) * ((ramHT[0].mlpv + 100) / 100);
            produtos_cad_bin(cadastroPROD);
        } else {
            produtosRAM[retorno].estoque += notas.entra_prod[i].quantidade;
            produtosRAM[retorno].preco_custo = notas.entra_prod[i].preco;
            produtosRAM[retorno].preco_venda = (frete_prod + imposto_prod + notas.entra_prod[i].preco) * ((ramHT[0].mlpv + 100) / 100);
            
            ATprodutos.codigo=produtosRAM[retorno].codigo;
            strcpy(ATprodutos.descricao,produtosRAM[retorno].descricao);
            ATprodutos.estoque=produtosRAM[retorno].estoque;
            ATprodutos.estoque_min=produtosRAM[retorno].estoque_min;
            ATprodutos.preco_custo=produtosRAM[retorno].preco_custo;
            ATprodutos.preco_venda=produtosRAM[retorno].preco_venda;
            
            
            atualiza_produtos_bin(&ATprodutos, produtosRAM[retorno].codigo);
        }
    }

    qtd_caixa = qtd_itens_bin("Caixa.bin", sizeof (conta_receber));
    conta_receber caixaRAM[qtd_caixa];
    caixa_ram_bin(caixaRAM);

    notas.total += notas.frete + notas.imposto;
    saldo = calcula_saldo_caixa(qtd_caixa, caixaRAM);

    printf("Valor total da nota: %.2f\n", notas.total);
    printf("Valor total em caixa: %.2f\n", saldo);
    printf("Qual será a forma de pagamento da nota fiscal?\n");
    printf("1-A vista.\n");
    printf("2-A prazo.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &pagamento);

    if (pagamento == 1) {
        if (saldo < notas.total) {
            printf("O caixa não possui saldo suficiente para o pagamento, logo pagará a prazo.\n");
            pagamento = 2;
        } else {
            adiciona_caixa_bin(notas.total, fornecedorRAM[pos_for].codigo, 1);
        }
    }

    if (pagamento == 2) {
        // Parcelamento: como funciona? Tem limite de vezes?
        printf("1-Deseja pagar uma entrada e o restante a prazo.\n");
        printf("2-Deseja pagar tudo a prazo.\n");
        printf("Digite a opção desejada:");
        scanf("%d", &pagamento);

        if (pagamento == 1) {
            printf("Digite a quantia que será dada de entrada:");
            scanf("%f", &entrada);

            while (entrada > saldo) {
                printf("Saldo: %.2f\n", saldo);
                printf("O caixa não possui esse saldo, digite um valor válido:");
                scanf("%f", &entrada);
            }

            printf("Deseja parcelar em quantas vezes o restante?:");
            scanf("%d", &vezes);
            prazo = total - entrada;
            adiciona_caixa_bin(entrada, fornecedorRAM[pos_for].codigo, 1);
            adicionar_contas_a_pagar_bin(prazo, vezes, fornecedorRAM[pos_for].codigo);
        } else {
            printf("Deseja parcelar em quantas vezes?:");
            scanf("%d", &vezes);
            adicionar_contas_a_pagar_bin(notas.total, vezes, fornecedorRAM[pos_for].codigo);
        }
    }
    strcpy(notas.cnpj,fornecedorRAM[pos_for].cnpj);
    cadastrar_notafiscal_bin(notas);

    menu_modulo_transacoes_bin();
}

//dando baixa nas contas a pagar
void main_conta_pagar_bin() {
    int cod_conta, qtd_conta, sair = 0, contador_erro = 0, existe, qtd_caixa;
    float saldo = 0;

    existe = arquivo_existe_bin("Contas_pagar.bin");
    if (existe == 0) {
        printf("Não tem nenhuma conta a pagar.\n");
        menu_conta_receber_bin();
    }

    qtd_caixa = qtd_itens_bin("Caixa.bin", sizeof (conta_receber));
    conta_receber caixaRAM[qtd_caixa];
    caixa_ram_bin(caixaRAM);
    saldo = calcula_saldo_caixa(qtd_caixa, caixaRAM);

    qtd_conta = qtd_itens_bin("Contas_pagar.bin", sizeof (conta_receber));
    conta_receber contasRAM[qtd_conta];
    contas_a_pagar_ram_bin(contasRAM);


    printf("\n-----CONTAS A PAGAR------\n");
    dados_conta_a_pagar_bin();

    printf("Digite a conta que deseja dar baixa:");
    scanf("%d", &cod_conta);
    while (cod_conta + 1 > qtd_conta) {
        printf("Digite uma conta válida que deseja dar baixa:");
        scanf("%d", &cod_conta);
        if (contador_erro > 2) {
            printf("Ocorreu muitos erros deseja sair dessa função?(1-Sim/0-Não)");
            scanf("%d", &sair);
            contador_erro = 0;
        }
        if (sair != 0) {
            contador_erro = 0;
            menu_conta_pagar_bin();
        }
    }
    if (contasRAM[cod_conta].valor_devido > saldo) {
        printf("O caixa não possui saldo o suficiente para pagar.\n");
        printf("Saldo do caixa:%.2f\n", saldo);
        menu_conta_pagar_bin();
    } else {
        adiciona_caixa_bin(contasRAM[cod_conta].valor_devido, -1, 1);
        deleta_conta_a_pagar_bin(cod_conta);
        menu_conta_pagar_bin();
    }

}

//listando todas contas a receber
void main_listar_conta_pagar_bin() {

    int existe;
    existe = arquivo_existe_bin("Contas_pagar.bin");
    if (existe == 0) {
        printf("Não tem nenhuma conta a pagar.\n");
        menu_conta_pagar_bin();
    }

    printf("\n--------LISTA DE CONTAS A RECEBER--------\n");
    dados_conta_a_pagar_bin();
    menu_conta_pagar_bin();
}
//FIM TRANSAÇÕES BIN


//INICIO FEEEDBACK
//funcao para listar hospedes
void main_listagem_hospede_bin() {
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
        menu_modulo_feedback_bin();
    }
    listagem_hospede_bin(codigo, listagem, sexo, opcao);
    menu_modulo_feedback_bin();
}

//funcao para listar acomodacoes
void main_listagem_acomodacoes_bin() {
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
        menu_modulo_feedback_bin();
    }
    listagem_acomodacoes_bin(codigo, listagem, categoria, opcao, dates);
    menu_modulo_feedback_bin();
}

//funcao para listar reservas
void main_listagem_reservas_bin() {
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
        menu_modulo_feedback_bin();
    }
    listagem_reservas_bin(listagem, codigo_hospede, codigo_acomodacao, datas, opcao);
    menu_modulo_feedback_bin();
}

//funcao para listar acomodacoes 
void main_listagem_movimento_acomodacoes_bin() {
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
        menu_modulo_feedback_bin();
    }
    listagem_movimento_acomodacoes_bin(listagem, codigo, diarias, lucro, opcao);
    menu_modulo_feedback_bin();
}

//funcao para listar produtos
void main_listagem_produtos_bin() {
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
        menu_modulo_feedback_bin();
    }
    listagem_produtos_bin(codigo, listagem, opcao);
    menu_modulo_feedback_bin();
}

//funcao para listar estoque minimo
void main_listagem_estoque_minimo_bin() {
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
        menu_modulo_feedback_bin();
    }

    listagem_estoque_minimo_bin(codigo, listagem, opcao);
    menu_modulo_feedback_bin();
}

//funcao para listar venda
void main_listagem_vendas_bin() {
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
            menu_modulo_feedback_bin();
        }
    }

    printf("\n1-Deseja imprimir o relatório em tela.\n");
    printf("2-Deseja gerar um arquivo do relatório.\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    listagem_vendas_bin(pagamento, opcao, listagem);
    menu_modulo_feedback_bin();
}

//funcao para listar contas a receber
void main_listagem_contas_receber_bin() {
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
        menu_modulo_feedback_bin();
    }

    listagem_contas_receber_bin(listagem, codigo, inicio, fim, opcao);
    menu_modulo_feedback_bin();

}

//funcao para listar contas a pagar
void main_listagem_contas_pagar_bin() {
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
        menu_modulo_feedback_bin();
    }

    listagem_contas_pagar_bin(listagem, codigo, inicio, fim, opcao);
    menu_modulo_feedback_bin();
}

//funcao para listar caixa
void main_listagem_caixa_bin() {
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
        menu_modulo_feedback_bin();
    }

    // Chamada da função para listagem de caixa
    listagem_caixa_bin(inicio, fim, listagem, opcao);

    menu_modulo_feedback_bin();
}
//FIM FEEDBACK


//COMEÇO IMPORTAÇÃO E EXPORTAÇÃO
//funcao para importar dados
void main_importar_dados_bin() {
    int importar;
    char arquivo[30];
    printf("\n------IMPORTAR DADOS-------\n");
    printf("Primeiramente digite o nome do arquivo que deseja importar(EX:arquivo.xml):");
    scanf(" %[^\n]s%*c", arquivo);
    printf("Quais dados deseja importar?\n");
    printf("Dados do Hotel.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_hotel_bin_xml(arquivo);
    }
    printf("Dados dos Hospedes.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_hospedes_bin_xml(arquivo);
    }
    printf("Dados das acomodações.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_acomodacoes_bin_xml(arquivo);
    }
    printf("Dados das categorias de acomodação.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_categoria_acomodacao_bin_xml(arquivo);
    }
    printf("Dados dos produtos.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_produtos_bin_xml(arquivo);
    }
    printf("Dados dos fornecedores.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_fornecedores_bin_xml(arquivo);
    }
    printf("Dados dos operadores.(1-Sim/0-Não):");
    scanf("%d", &importar);
    if (importar == 1) {
        importar_dados_operadores_bin_xml(arquivo);
    }

    menu_modulo_im_exportacao_bin();
}

//funcao para exportar dados
void main_exportar_dados_bin() {
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

    exportar_dados_bin_xml(exportar);

    menu_modulo_im_exportacao_bin();
}
//FIM IMPORTAÇÃO E EXPORTAÇÃO

void login_bin() {
    permissao login;
    OPsistema operador;
    cad_hotel hotel;
    int pos_op, cod_op, senha, cont_erro = 0, sair = 0, retorno_bin, retorno_txt, quantidade;


    retorno_txt = arquivo_existe_txt("operadores.txt");
    retorno_bin = arquivo_existe_bin("Operadores.bin");

    if (retorno_txt == 0 && retorno_bin == 0) {
        printf("Vejo que é a primeira vez que inicie o programa\n");
        printf("Começe cadastrando um operador,lembrando esse operador terá todas permissões ativas.\n");
        printf("------Dados do Operador-------\n");
        printf("Digite o código do operador:");
        scanf("%d", &operador.codigo);
        printf("Digite o nome do operador:");
        scanf(" %[^\n]s%*c", operador.nome);
        setbuf(stdin, NULL);
        printf("Digite o nome de usuário do operador:");
        scanf(" %[^\n]s%*c", operador.usuario);
        setbuf(stdin, NULL);
        printf("Digite a senha do operador(Somente números):");
        scanf("%d", &operador.senha);
        operador.permissoes.cadastros = 1;
        operador.permissoes.feedback = 1;
        operador.permissoes.im_exportacao = 1;
        operador.permissoes.reservas = 1;
        operador.permissoes.transacoes = 1;

        operadores_cad_bin(operador);

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
        //chamando a função para gravar o hotel em txt
        //passando a struct como paramentro
        hotel_cad_bin(hotel);
        menu_principal_bin();

    } else {
        if (retorno_txt != 0) {
            //se for diferente de 0 é pq existe informações salvas em txt logo vamos trazelas para binario
            muda_arquivo_txt_p_bin();
        }
        quantidade = qtd_itens_bin("Operadores.bin", sizeof (OPsistema));
        OPsistema ramOP[quantidade];
        operadores_ram_bin(ramOP);

        printf("\tLOGIN\n");
        printf("Código do operador:");
        scanf("%d", &cod_op);
        printf("Senha do usuário:");
        scanf("%d", &senha);
        pos_op = verifica_login(cod_op, senha, ramOP, quantidade);
        while (pos_op == -1) {
            printf("Operador não encontrado.\n");
            printf("Digite um operador válido.\n");
            printf("Código do operador:");
            scanf("%d", &cod_op);
            printf("Senha do usuário:");
            scanf("%d", &senha);
            pos_op = verifica_login(cod_op, senha, ramOP, quantidade);
            cont_erro++;
            if (cont_erro > 2) {
                printf("Ocorreu muitos erros de login deseja sair?(1-Sim/0-Não):");
                scanf("%d", &sair);
            }
            if (sair == 1) {
                exit(1);
            }
        }
        if (pos_op != -1) {
            printf("Login feito com sucesso.\n");
            permissoes_login(ramOP, pos_op);
            menu_principal_bin();
        }
    }
}
//FIM MAIN BIN


int main() {
    int opcao;
    printf("=========BEM VINDO=========\n");
    printf("Qual forma de salvamento sera usada?\n");
    printf("1-Salvamento em arquivo texto.\n");
    printf("2-Salvamento em arquivo binário.\n");
    printf("3-Salvamento em memória.\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            login_txt();
            break;
        case 2:
            login_bin();
            break;
        case 3:
            login_mem();
            break;
        default:
            printf("\nDigite uma opção válida.\n");
            main();
            break;
    }


    return (EXIT_SUCCESS);
}
