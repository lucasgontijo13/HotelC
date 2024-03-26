#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "funcoes.h"
#include "reservasTXT.h"
#include "arquivosTXT.h"
#include "menu.h"
#include "ArquivosBin.h"
#include "ReservasBin.h"



//funcao pra criar o arquivo de reservas para começar a cadastrar reservas
void criar_reservas_txt() {
    FILE *P; //Ponteiro do arquivo TXT;

    P = fopen("reservas.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }

}

//funcao que pegas os dados da acomodacao com os dados da categoria da propria acomodacao e o codigo do hospede para criar o arquvio de reservas em txt
int cadastro_reservas_txt(acomodacoes *acomodacoes, categoria_acomodacao *categorias, int posicao_acomodacao, int qtd_cat, data_chek_in_out datas, int cod_hos, int cod_res) {
    reservas reservasCAD;
    
    reservasCAD.codigo_res = cod_res;
    reservasCAD.codigo_aco = acomodacoes[posicao_acomodacao].codigo;
    strcpy(reservasCAD.descricao, acomodacoes[posicao_acomodacao].descricao);
    strcpy(reservasCAD.facilidades, acomodacoes[posicao_acomodacao].facilidades);
    for (int i = 0; i < qtd_cat; i++) {
        if (categorias[i].codigo == acomodacoes[posicao_acomodacao].categoria) {
            reservasCAD.categoria.codigo = categorias[i].codigo;
            strcpy(reservasCAD.categoria.descricao, categorias[i].descricao);
            reservasCAD.categoria.valor_diaria = categorias[i].valor_diaria;
            reservasCAD.categoria.adultos = categorias[i].adultos;
            reservasCAD.categoria.criancas = categorias[i].criancas;
            break;
        }
    }
    reservasCAD.datas.ano_in = datas.ano_in;
    reservasCAD.datas.mes_in = datas.mes_in;
    reservasCAD.datas.dia_in = datas.dia_in;
    reservasCAD.datas.ano_out = datas.ano_out;
    reservasCAD.datas.mes_out = datas.mes_out;
    reservasCAD.datas.dia_out = datas.dia_out;
    reservasCAD.cod_hospede = cod_hos;

    FILE *P; //Ponteiro do arquivo TXT;

    P = fopen("reservas.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    fprintf(P, "%d\n%d\n%s\n%s\n%d\n%s\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
            reservasCAD.codigo_res,
            reservasCAD.codigo_aco,
            reservasCAD.descricao,
            reservasCAD.facilidades,
            reservasCAD.categoria.codigo,
            reservasCAD.categoria.descricao,
            reservasCAD.categoria.valor_diaria,
            reservasCAD.categoria.adultos,
            reservasCAD.categoria.criancas,
            reservasCAD.datas.dia_in,
            reservasCAD.datas.mes_in,
            reservasCAD.datas.ano_in,
            reservasCAD.datas.dia_out,
            reservasCAD.datas.mes_out,
            reservasCAD.datas.ano_out,
            reservasCAD.cod_hospede);
    fclose(P);
    printf("Reserva cadastrada com sucesso.\n");

    return 0;
    // fim da função de cadastro de categorias
}

int muda_reserva_arquivo_bin_p_txt(reservas reservasRAM){
    FILE *P; //Ponteiro do arquivo TXT;

    P = fopen("reservas.txt", "a");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.");
        exit(1);
    }
    fprintf(P, "%d\n%d\n%s\n%s\n%d\n%s\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
        reservasRAM.codigo_res,
        reservasRAM.codigo_aco,
        reservasRAM.descricao,
        reservasRAM.facilidades,
        reservasRAM.categoria.codigo,
        reservasRAM.categoria.descricao,
        reservasRAM.categoria.valor_diaria,
        reservasRAM.categoria.adultos,
        reservasRAM.categoria.criancas,
        reservasRAM.datas.dia_in,
        reservasRAM.datas.mes_in,
        reservasRAM.datas.ano_in,
        reservasRAM.datas.dia_out,
        reservasRAM.datas.mes_out,
        reservasRAM.datas.ano_out,
        reservasRAM.cod_hospede);
    
    
    fclose(P);
    printf("Reserva cadastrada com sucesso.\n");

    return 0;
}

//traz as reservas para memoria ram
int reservas_ram_txt(int qtd, reservas *ramRES) {

    FILE *P;
    int i = 0;
    P = fopen("reservas.txt", "r");

    for (i = 0; i < qtd; i++) {
        fscanf(P, "%d", &ramRES[i].codigo_res);
        fscanf(P, "\n%d", &ramRES[i].codigo_aco);
        fscanf(P, "\n%[^\n]s", ramRES[i].descricao);
        fscanf(P, "\n%[^\n]s", ramRES[i].facilidades);
        fscanf(P, "\n%d", &ramRES[i].categoria.codigo);
        fscanf(P, "\n%[^\n]s", &ramRES[i].categoria.descricao);
        fscanf(P, "\n%f", &ramRES[i].categoria.valor_diaria);
        fscanf(P, "\n%d", &ramRES[i].categoria.adultos);
        fscanf(P, "\n%d", &ramRES[i].categoria.criancas);
        fscanf(P, "\n%d", &ramRES[i].datas.dia_in);
        fscanf(P, "\n%d", &ramRES[i].datas.mes_in);
        fscanf(P, "\n%d", &ramRES[i].datas.ano_in);
        fscanf(P, "\n%d", &ramRES[i].datas.dia_out);
        fscanf(P, "\n%d", &ramRES[i].datas.mes_out);
        fscanf(P, "\n%d", &ramRES[i].datas.ano_out);
        fscanf(P, "\n%d", &ramRES[i].cod_hospede);
    }




    fclose(P);

    return 0;
}


//utilizado no filtro de categoria para printar o codigo e a descricao da categoria para o usuario escolher
int printa_categoria_txt(int qtd, categoria_acomodacao *printCAT) {
    for (int i = 0; i < qtd; i++) {
        printf("Codigo:%d\n", printCAT[i].codigo);
        printf("Descrição:%s\n", printCAT[i].descricao);
    }
}



//printa as datas em que aquela quarto esta reservado
int procura_data_reserva_txt(int qtd, int codigo_aco, reservas *reservaRAM) {

    for (int i = 0; i < qtd; i++) {
        if (reservaRAM[i].codigo_aco == codigo_aco) {
            printf("Chek-in:%d/%d/%d\t", reservaRAM[i].datas.dia_in, reservaRAM[i].datas.mes_in, reservaRAM[i].datas.ano_in);
            printf("Chek-out:%d/%d/%d\n\n", reservaRAM[i].datas.dia_out, reservaRAM[i].datas.mes_out, reservaRAM[i].datas.ano_out);
        }
    }
    return 1;
}

//verifica se a data nao esta infligindo nenhuma reserva
int verifica_data_txt(int qtd, reservas *ramRES, data_chek_in_out datas, int cod_aco) {
    int i = 0;
    for (i = 0; i < qtd; i++) {
        if (datas.ano_in > ramRES[i].datas.ano_out || datas.ano_out < ramRES[i].datas.ano_in) {

        } else if (datas.mes_in > ramRES[i].datas.mes_out || datas.mes_out < ramRES[i].datas.mes_in) {

        } else if (datas.dia_in > ramRES[i].datas.dia_out || datas.dia_out < ramRES[i].datas.dia_in) {

        } else if (cod_aco == ramRES[i].codigo_aco) {
            return -1;
        }
    }
    return 1;
}


//verifica se o quarto escolhido esta com a ocupacao igual a 0 ou seja senao existe nenhuma reserva
int verifica_ocupacao_txt(int qtd_aco, int cod_aco, acomodacoes *acomodacaoRES) {

    for (int i = 0; i < qtd_aco; i++) {
        if (acomodacaoRES[i].codigo == cod_aco) {
            if (acomodacaoRES[i].ocupacao == 0) {
                return 0;
            } else {
                return 1;
            }
        }
    }
    return -1;
}

//função para procurar reserva em txt
int procura_reserva_txt(int codigo, int qtd, reservas *procuraRES) {
    for (int i = 0; i < qtd; i++) {
        if (procuraRES[i].codigo_res == codigo) {
            return i;
        }
    }
    return -1;
}

//funcao para atualizar reserva em txt
int atualiza_reserva_txt(int qtd, reservas *reservasAT) {
    int status = 0;
    FILE *P;

    P = fopen("reservas_temp.txt", "w");

    if (P == NULL) {
        printf("Problemas na abertura do arquivo.\n");
        exit(1);
    }
    for (int i = 0; i < qtd; i++) {
        fprintf(P, "%d\n%d\n%s\n%s\n%d\n%s\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                reservasAT[i].codigo_res,
                reservasAT[i].codigo_aco,
                reservasAT[i].descricao,
                reservasAT[i].facilidades,
                reservasAT[i].categoria.codigo,
                reservasAT[i].categoria.descricao,
                reservasAT[i].categoria.valor_diaria,
                reservasAT[i].categoria.adultos,
                reservasAT[i].categoria.criancas,
                reservasAT[i].datas.dia_in,
                reservasAT[i].datas.mes_in,
                reservasAT[i].datas.ano_in,
                reservasAT[i].datas.dia_out,
                reservasAT[i].datas.mes_out,
                reservasAT[i].datas.ano_out,
                reservasAT[i].cod_hospede);
    }
    fclose(P);

    status = remove("reservas.txt");

    if (status != 0) {
        printf("Erro na remoção do arquivo para atualizar a reserva.\n");
        exit(1);
    }
    status = rename("reservas_temp.txt", "reservas.txt");

    if (status != 0) {
        printf("Erro na renomeção do arquivo para atualizar a reserva.\n");
        exit(1);
    }
    printf("Atualização da reserva feita com sucesso.\n");
    return 0;
}

//funcao para deletar reserva em txt
int deleta_reserva_txt(int qtd, int posicao, reservas *ramDELRES) {
    int status = 0;
    //laço para pegar todos operadores apos o que vai ser excluido e trazer para tras
    for (int i = posicao; i < qtd; i++) {//sobrescreve os dados do operador seguinte ao que será deletado, e assim sucessivamente

        ramDELRES[i].codigo_res = ramDELRES[i + 1].codigo_res;
        ramDELRES[i].codigo_aco = ramDELRES[i + 1].codigo_aco;
        strcpy(ramDELRES[i].descricao, ramDELRES[i + 1].descricao);
        strcpy(ramDELRES[i].facilidades, ramDELRES[i + 1].facilidades);
        ramDELRES[i].categoria.codigo = ramDELRES[i + 1].categoria.codigo;
        strcpy(ramDELRES[i].categoria.descricao, ramDELRES[i + 1].categoria.descricao);
        ramDELRES[i].categoria.valor_diaria = ramDELRES[i + 1].categoria.valor_diaria;
        ramDELRES[i].categoria.adultos = ramDELRES[i + 1].categoria.adultos;
        ramDELRES[i].categoria.criancas = ramDELRES[i + 1].categoria.criancas;
        ramDELRES[i].datas.dia_in = ramDELRES[i + 1].datas.dia_in;
        ramDELRES[i].datas.mes_in = ramDELRES[i + 1].datas.mes_in;
        ramDELRES[i].datas.ano_in = ramDELRES[i + 1].datas.ano_in;
        ramDELRES[i].datas.dia_out = ramDELRES[i + 1].datas.dia_out;
        ramDELRES[i].datas.mes_out = ramDELRES[i + 1].datas.mes_out;
        ramDELRES[i].datas.ano_out = ramDELRES[i + 1].datas.ano_out;
        ramDELRES[i].cod_hospede = ramDELRES[i + 1].cod_hospede;
    }

    reservas *p;
    //diminuindo em um o tamanho do ponteiro
    p = malloc((qtd - 1) * sizeof (reservas)); //realoca memoria com uma posicao a menos

    //pegando os dados dos operadores e passando para o ponteiro
    for (int i = 0; i < qtd - 1; i++) {//preenche o ponteiro alocado com os dados dos operadores
        p[i].codigo_res = ramDELRES[i].codigo_res;
        p[i].codigo_aco = ramDELRES[i].codigo_aco;
        strcpy(p[i].descricao, ramDELRES[i].descricao);
        strcpy(p[i].facilidades, ramDELRES[i].facilidades);
        p[i].categoria.codigo = ramDELRES[i].categoria.codigo;
        strcpy(p[i].categoria.descricao, ramDELRES[i].categoria.descricao);
        p[i].categoria.valor_diaria = ramDELRES[i].categoria.valor_diaria;
        p[i].categoria.adultos = ramDELRES[i].categoria.adultos;
        p[i].categoria.criancas = ramDELRES[i].categoria.criancas;
        p[i].datas.dia_in = ramDELRES[i].datas.dia_in;
        p[i].datas.mes_in = ramDELRES[i].datas.mes_in;
        p[i].datas.ano_in = ramDELRES[i].datas.ano_in;
        p[i].datas.dia_out = ramDELRES[i].datas.dia_out;
        p[i].datas.mes_out = ramDELRES[i].datas.mes_out;
        p[i].datas.ano_out = ramDELRES[i].datas.ano_out;
        p[i].cod_hospede = ramDELRES[i].cod_hospede;
    }

    FILE *temp;

    temp = fopen("reservas_temp.txt", "w");
    if (temp == NULL) {
        return 1;
    }
    //retirando da quantidade o OP deletado
    qtd = qtd - 1;
    //gravando o arquivo
    for (int i = 0; i < qtd; i++) {
        fprintf(temp, "%d\n%d\n%s\n%s\n%d\n%s\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                p[i].codigo_res,
                p[i].codigo_aco,
                p[i].descricao,
                p[i].facilidades,
                p[i].categoria.codigo,
                p[i].categoria.descricao,
                p[i].categoria.valor_diaria,
                p[i].categoria.adultos,
                p[i].categoria.criancas,
                p[i].datas.dia_in,
                p[i].datas.mes_in,
                p[i].datas.ano_in,
                p[i].datas.dia_out,
                p[i].datas.mes_out,
                p[i].datas.ano_out,
                p[i].cod_hospede);
    }
    fclose(temp);
    status = remove("reservas.txt");

    if (status != 0) {
        printf("Erro na remoção do arquivo para deletar a reserva.\n");
        exit(1);
    }
    status = rename("reservas_temp.txt", "reservas.txt");

    if (status != 0) {
        printf("Erro na renomeção do arquivo para deletar a reserva.\n");
        exit(1);
    }
    printf("Cancelamento da reserva feita com sucesso.\n");
    return 0;
}




//funcao para filtrar por data em txt
int data_disponivel_txt(reservas *disponiveis, reservas *reservaRAM, acomodacoes *acomodacoesRAM, int qtd_res, int qtd_aco, data_chek_in_out datas, categoria_acomodacao *categoriaRAM, int qtd_cat) {
    int contador = 0, i = 0, j = 0, h = 0, k = 0, inidice[qtd_res], codigo[qtd_res], flag = 0, contador_indisponiveis = 0;

    //verifica as acomodacoes disponiveis para todas as datas
    for (h = 0; h < qtd_aco; h++) {
        if (acomodacoesRAM[h].ocupacao == 0) {
            disponiveis[contador].codigo_aco = acomodacoesRAM[h].codigo;
            strcpy(disponiveis[contador].descricao, acomodacoesRAM[h].descricao);
            strcpy(disponiveis[contador].facilidades, acomodacoesRAM[h].facilidades);
            for (k = 0; k < qtd_cat; k++) {
                if (acomodacoesRAM[h].categoria == categoriaRAM[k].codigo) {
                    disponiveis[contador].categoria.codigo = categoriaRAM[k].codigo;
                    strcpy(disponiveis[contador].categoria.descricao, categoriaRAM[k].descricao);
                    disponiveis[contador].categoria.valor_diaria = categoriaRAM[k].valor_diaria;
                    disponiveis[contador].categoria.criancas = categoriaRAM[k].criancas;
                    disponiveis[contador].categoria.adultos = categoriaRAM[k].adultos;
                    contador++;
                }
            }
        }
    }
    
    
    for (i = 0; i < qtd_res; i++) {
        if ((datas.ano_in <= reservaRAM[i].datas.ano_out || datas.ano_out >= reservaRAM[i].datas.ano_in) &&
                (datas.mes_in <= reservaRAM[i].datas.mes_out || datas.mes_out >= reservaRAM[i].datas.mes_in) &&
                (datas.dia_in <= reservaRAM[i].datas.dia_out || datas.dia_out >= reservaRAM[i].datas.dia_in)) {
            inidice[contador_indisponiveis] = i;
            codigo[contador_indisponiveis] = reservaRAM[i].codigo_aco;
            contador_indisponiveis++;
        }
    }
    
    if (contador_indisponiveis == 0) {
        for (i = 0; i < qtd_res; i++) {
            flag = 0;
            for (j = 0; j < i; j++) {
                if (reservaRAM[i].codigo_aco == reservaRAM[j].codigo_aco) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                disponiveis[contador].codigo_aco = reservaRAM[i].codigo_aco;
                strcpy(disponiveis[contador].descricao, reservaRAM[i].descricao);
                strcpy(disponiveis[contador].facilidades, reservaRAM[i].facilidades);
                disponiveis[contador].categoria.codigo = reservaRAM[i].categoria.codigo;
                strcpy(disponiveis[contador].categoria.descricao, reservaRAM[i].categoria.descricao);
                disponiveis[contador].categoria.valor_diaria = reservaRAM[i].categoria.valor_diaria;
                disponiveis[contador].categoria.criancas = reservaRAM[i].categoria.criancas;
                disponiveis[contador].categoria.adultos = reservaRAM[i].categoria.adultos;
                contador++;
            }
        }
    }
    
    else if (contador_indisponiveis > 0) {
        for (i = 0; i < qtd_res; i++) {
            for (j = 0; j < contador_indisponiveis; j++) {
                if (codigo[j] != reservaRAM[i].codigo_aco) {
                    if (contador > 0) {
                        for (k = 0; k < contador; k++) {
                            if (reservaRAM[i].codigo_aco == disponiveis[k].codigo_aco) {
                                flag = 1;
                                break;
                            } else {
                                flag = 0;
                            }
                        }
                    } else {
                        flag = 0;
                    }
                } else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                disponiveis[contador].codigo_aco = reservaRAM[i].codigo_aco;
                strcpy(disponiveis[contador].descricao, reservaRAM[i].descricao);
                strcpy(disponiveis[contador].facilidades, reservaRAM[i].facilidades);
                disponiveis[contador].categoria.codigo = reservaRAM[i].categoria.codigo;
                strcpy(disponiveis[contador].categoria.descricao, reservaRAM[i].categoria.descricao);
                disponiveis[contador].categoria.valor_diaria = reservaRAM[i].categoria.valor_diaria;
                disponiveis[contador].categoria.criancas = reservaRAM[i].categoria.criancas;
                disponiveis[contador].categoria.adultos = reservaRAM[i].categoria.adultos;
                contador++;
            }

        }
    } 





    if (contador > 0) {
        return contador;
    } else {
        printf("Nenhum quarto disponível nessa data.\n");
        return -1;
    }




    return 0;
}

//funcao para filtrar por categoria em txt
int categoria_disponivel_txt(int codigo_cat, int qtd_aco, acomodacoes *acomodacoesRAM, categoria_acomodacao *categoriaRAM, int pos_cat, reservas *disponiveis) {
    int contador = 0;
    for (int i = 0; i < qtd_aco; i++) {
        if (codigo_cat == acomodacoesRAM[i].categoria) {
            disponiveis[contador].codigo_aco = acomodacoesRAM[i].codigo;
            strcpy(disponiveis[contador].descricao, acomodacoesRAM[i].descricao);
            strcpy(disponiveis[contador].facilidades, acomodacoesRAM[i].facilidades);
            disponiveis[contador].categoria.codigo = categoriaRAM[pos_cat].codigo;
            strcpy(disponiveis[contador].categoria.descricao, categoriaRAM[pos_cat].descricao);
            disponiveis[contador].categoria.valor_diaria = categoriaRAM[pos_cat].valor_diaria;
            disponiveis[contador].categoria.criancas = categoriaRAM[pos_cat].criancas;
            disponiveis[contador].categoria.adultos = categoriaRAM[pos_cat].adultos;
            contador++;
        }
    }
    if(contador==0){
        printf("Não existe quartos com essa categoria.\n");
        return -1;
    }
    return contador;
}

//funcao para filtrar por quantidade de pessoas em txt
int pessoas_disponivel_txt(int criancas, int adultos, int qtd_cat, int qtd_aco, categoria_acomodacao *categoriaRAM, acomodacoes *acomodacoesRAM, reservas *disponiveis) {
    int contador = 0;
    int j = 0, i = 0;
    for (i = 0; i < qtd_cat; i++) {
        if (adultos == categoriaRAM[i].adultos && criancas == categoriaRAM[i].criancas) {
            for (j = 0; j < qtd_aco; j++) {
                if (categoriaRAM[i].codigo == acomodacoesRAM[j].categoria) {
                    disponiveis[contador].codigo_aco = acomodacoesRAM[j].codigo;
                    strcpy(disponiveis[contador].descricao, acomodacoesRAM[j].descricao);
                    strcpy(disponiveis[contador].facilidades, acomodacoesRAM[j].facilidades);
                    disponiveis[contador].categoria.codigo = categoriaRAM[i].codigo;
                    strcpy(disponiveis[contador].categoria.descricao, categoriaRAM[i].descricao);
                    disponiveis[contador].categoria.valor_diaria = categoriaRAM[i].valor_diaria;
                    disponiveis[contador].categoria.criancas = categoriaRAM[i].criancas;
                    disponiveis[contador].categoria.adultos = categoriaRAM[i].adultos;
                    contador++;
                }
            }
        }
    }
    if(contador==0){
        printf("Nenhuma acomodação disponivel com essa quantidade de pessoas.");
        return -1; 
    }
    return contador;
}

//funçao para filtrar po facilidades em txt
int facilidades_disponiveis_txt(char *facilidades, acomodacoes *acomodacoesRAM, int qtd_aco, reservas *disponiveis, categoria_acomodacao *categoriaRAM, int qtd_cat) {
    char *resultado;
    int contador = 0;
    for (int i = 0; i < qtd_aco; i++) {
        resultado = strstr(acomodacoesRAM[i].facilidades, facilidades);
        if (resultado != NULL) {
            disponiveis[contador].codigo_aco = acomodacoesRAM[i].codigo;
            strcpy(disponiveis[contador].descricao, acomodacoesRAM[i].descricao);
            strcpy(disponiveis[contador].facilidades, acomodacoesRAM[i].facilidades);
            for (int j = 0; j < qtd_cat; j++) {
                if (acomodacoesRAM[i].categoria == categoriaRAM[j].codigo) {
                    disponiveis[contador].categoria.codigo = categoriaRAM[j].codigo;
                    strcpy(disponiveis[contador].categoria.descricao, categoriaRAM[j].descricao);
                    disponiveis[contador].categoria.valor_diaria = categoriaRAM[j].valor_diaria;
                    disponiveis[contador].categoria.criancas = categoriaRAM[j].criancas;
                    disponiveis[contador].categoria.adultos = categoriaRAM[j].adultos;
                    contador++;
                }
            }
        }
    }

    if (contador == 0) {
        printf("Nenhuma acomodação disponível com essa facilidade.\n");
        return -1;
    } else {
        return contador;
    }
}




//funcao que filtra por facilidades mesmo depois de um filtro ja ter sido utilizado
int filtro_facilidades_filtrada_txt(char *facilidades, reservas *disponiveis_novo, reservas *disponiveis_antigo, int qtd_dis){
    char *resultado;
    int contador = 0;
    for (int i = 0; i < qtd_dis; i++) {
        resultado = strstr(disponiveis_antigo[i].facilidades, facilidades);
        if (resultado != NULL) {
            disponiveis_novo[contador].codigo_aco = disponiveis_antigo[i].codigo_aco;
            strcpy(disponiveis_novo[contador].descricao, disponiveis_antigo[i].descricao);
            strcpy(disponiveis_novo[contador].facilidades, disponiveis_antigo[i].facilidades);
            disponiveis_novo[contador].categoria.codigo = disponiveis_antigo[i].categoria.codigo;
            strcpy(disponiveis_novo[contador].categoria.descricao, disponiveis_antigo[i].categoria.descricao);
            disponiveis_novo[contador].categoria.valor_diaria = disponiveis_antigo[i].categoria.valor_diaria;
            disponiveis_novo[contador].categoria.criancas = disponiveis_antigo[i].categoria.criancas;
            disponiveis_novo[contador].categoria.adultos = disponiveis_antigo[i].categoria.adultos;
            contador++;
        }
    }
    if (contador == 0) {
        printf("Nenhuma acomodação disponível com essa facilidade.\n");
        return -1;
    } else {
        return contador;
    }
}
    
//funcao para procurar facilidades no vetor que ja foi filtrado uma vez
int procura_facilidades_filtrada_txt(char *facilidades, reservas *disponiveis, int qtd_dis) {
    
    char *resultado;
    for (int i = 0; i < qtd_dis; i++) {
        resultado = strstr(disponiveis[i].facilidades, facilidades);
        if (resultado != NULL) {
           return i; 
        }        
    }
    return -1;
}


//funcao que filtra por categoria mesmo depois de um filtro ja ter sido utilizado
int filtro_categoria_filtrada_txt(reservas *disponivel_novo, reservas *disponiveis_antigo, int qtd_dis, int cod_cat) {
    int contador = 0;
    for (int i = 0; i < qtd_dis; i++) {
        if (disponiveis_antigo[i].categoria.codigo == cod_cat) {
            disponivel_novo[contador].codigo_aco = disponiveis_antigo[i].codigo_aco;
            strcpy(disponivel_novo[contador].descricao, disponiveis_antigo[i].descricao);
            strcpy(disponivel_novo[contador].facilidades, disponiveis_antigo[i].facilidades);
            disponivel_novo[contador].categoria.codigo = disponiveis_antigo[i].categoria.codigo;
            strcpy(disponivel_novo[contador].categoria.descricao, disponiveis_antigo[i].descricao);
            disponivel_novo[contador].categoria.valor_diaria = disponiveis_antigo[i].categoria.valor_diaria;
            disponivel_novo[contador].categoria.criancas = disponiveis_antigo[i].categoria.criancas;
            disponivel_novo[contador].categoria.adultos = disponiveis_antigo[i].categoria.adultos;
            contador++;
        }
    }
    return contador;

}

//funcao para procurar categora no vetor que ja foi filtrado uma vez
int procura_categoria_filtrada_txt(int cod_cat, reservas *disponiveis, int qtd_dis) {

    for (int i = 0; i < qtd_dis; i++) {
        if (disponiveis[i].categoria.codigo == cod_cat) {
            return i;
        }
    }
    return -1;
}


//funcao que filtra por quantidade de pessoas mesmo depois de um filtro ja ter sido utilizado
int filtro_pessoas_filtrada(int criancas, int adultos ,reservas *disponivel_novo, reservas *disponiveis_antigo, int qtd_dis) {
    int contador=0;
    for (int i = 0; i < qtd_dis; i++) {
        if (disponiveis_antigo[i].categoria.criancas == criancas && disponiveis_antigo[i].categoria.adultos == adultos) {
            disponivel_novo[contador].codigo_aco = disponiveis_antigo[i].codigo_aco;
            strcpy(disponivel_novo[contador].descricao, disponiveis_antigo[i].descricao);
            strcpy(disponivel_novo[contador].facilidades, disponiveis_antigo[i].facilidades);
            disponivel_novo[contador].categoria.codigo = disponiveis_antigo[i].categoria.codigo;
            strcpy(disponivel_novo[contador].categoria.descricao, disponiveis_antigo[i].descricao);
            disponivel_novo[contador].categoria.valor_diaria = disponiveis_antigo[i].categoria.valor_diaria;
            disponivel_novo[contador].categoria.criancas = disponiveis_antigo[i].categoria.criancas;
            disponivel_novo[contador].categoria.adultos = disponiveis_antigo[i].categoria.adultos;
            contador++;    
            }
        }
    if(contador>0){
        return contador;
    }else {
        return -1;
    }
}

//funcao para procurar categora no vetor que ja foi filtrado uma vez
int procura_pessoas_filtrada_txt(int criancas,int adultos, reservas *disponiveis, int qtd_dis) {

    for (int i = 0; i < qtd_dis; i++) {
        if (disponiveis[i].categoria.criancas == criancas && disponiveis[i].categoria.adultos == adultos) {
            return i;
        }
    }
    return -1;
}

//funcao para pegar a posicao da acomodaçao que esta em um vetor disponivel
int procura_acomodacao_disponivel(int qtd_dis,int cod_aco,reservas *disponiveis,acomodacoes *acomodacaoRAM,int qtd_aco){
    
    for (int i = 0; i < qtd_dis; i++) {
        if (disponiveis[i].codigo_aco == cod_aco) {
            for (int j = 0; j < qtd_aco; j++) {
                if (acomodacaoRAM[j].codigo == cod_aco) {
                    return j;
                }
            }
        }
    }    
    return -1;
}

