#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivosTXT.h"
#include "reservasTXT.h"
#include "ReservasBin.h"
#include "ArquivosBin.h"
#include "Structs.h"
#include "Funcoes.h"


// Funçao que cria um arquivo binário para as reservas.
void cria_reservas_bin(){
    FILE *p = fopen("Reservas.bin", "rb");
    
    if ( p == NULL ) {
        printf("Problemas na abertura do arquivo.\n");
        exit (1); // Indica erro na abertura dos arquivos.
    }
    
    fclose(p);
    
}

// Funçao que abre um arquivo binário para escrever e gravar dados das reservas.
int reservas_cad_bin(data_chek_in_out datas, int cod_acomodacao, int cod_hospede, int cod_reserva) {
    reservas reserva_inf;
    int teste = -1;
    
    FILE *p_hospedes = fopen("Hospedes.bin", "rb");
    FILE *p_acomodacoes = fopen("Acomodacoes.bin", "rb");
    FILE *p_categorias = fopen("Categorias.bin", "rb");
    FILE *p = fopen("Reservas.bin", "ab");

    if (p_acomodacoes == NULL || p_categorias == NULL || p == NULL || p_hospedes == NULL ) {
        printf("Problemas na abertura do arquivo.\n");
        exit (1); 
    }

    int aux = -1; // variavel aux
    hospedes hosped;
    acomodacoes acomde;
    categoria_acomodacao categ_aco;

    // Procurar acomodação por código
    while (fread(&acomde, sizeof(acomodacoes), 1, p_acomodacoes) == 1) {
        if (acomde.codigo == cod_acomodacao) {
            // O registro com o código desejado foi encontrado
            reserva_inf.codigo_aco = acomde.codigo;
            strcpy(reserva_inf.descricao, acomde.descricao);
            strcpy(reserva_inf.facilidades, acomde.facilidades);
            aux = acomde.categoria; // Salvar o código da categoria
            break;
        }
    }

    if (aux == -1) {
        printf("Acomodação não encontrada.\n");
        fclose(p_acomodacoes);
        fclose(p_categorias);
        fclose(p);
        fclose(p_hospedes);
        return -1; // Indica que a acomodação não foi encontrada.
    }

    // Procurar categoria por código
    while (fread(&categ_aco, sizeof(categoria_acomodacao), 1, p_categorias) == 1) {
        if (categ_aco.codigo == aux) {
            // O registro com o código da categoria desejada foi encontrado
            reserva_inf.categoria.codigo = categ_aco.codigo;
            strcpy(reserva_inf.categoria.descricao, categ_aco.descricao);
            reserva_inf.categoria.valor_diaria = categ_aco.valor_diaria;
            reserva_inf.categoria.adultos = categ_aco.adultos;
            reserva_inf.categoria.criancas = categ_aco.criancas;
            break;
        }
    }

    if (reserva_inf.categoria.codigo == -1) {
        printf("Categoria não encontrada.\n");
        fclose(p_acomodacoes);
        fclose(p_categorias);
        fclose(p_hospedes);
        fclose(p);
        return -1; // Indica que a categoria não foi encontrada.
    }
    
    // Procurar hospede por código
    while (fread(&hosped, sizeof(hospedes), 1, p_hospedes) == 1) {
        if (hosped.codigo == cod_hospede) {
            reserva_inf.cod_hospede = cod_hospede;
            teste=1;
            break;
        }
    }

    if (teste == -1) {
        printf("Hospede não encontrada.\n");
        fclose(p_acomodacoes);
        fclose(p_categorias);
        fclose(p_hospedes);
        fclose(p);
        return -1; // Indica que a categoria não foi encontrada.
    }

    fclose(p_acomodacoes);
    fclose(p_categorias);
    fclose(p_hospedes);

    // Preencha o restante dos campos em reserva_inf com os valores fornecidos.
    reserva_inf.codigo_res = cod_reserva;
    reserva_inf.datas.ano_in = datas.ano_in;
    reserva_inf.datas.mes_in = datas.mes_in;
    reserva_inf.datas.dia_in = datas.dia_in;
    reserva_inf.datas.ano_out = datas.ano_out;
    reserva_inf.datas.mes_out = datas.mes_out;
    reserva_inf.datas.dia_out = datas.dia_out;

    // Escreva as informações de reserva no arquivo.
    if (fwrite(&reserva_inf, sizeof(reservas), 1, p) != 1) {
        printf("Erro ao gravar dados da reserva no arquivo.\n");
        fclose(p);
        return -1; // Indica erro na gravação dos dados da reserva.
    }

    fclose(p);
    printf("Arquivo gravado com sucesso.\n");
    return 0; // Indica sucesso.
}

//fucao para cadastrar as reservas quando for mudar de arquvio txt para bin
int muda_reserva_arquivo_txt_p_bin(reservas reservasRAM){
    FILE *p;

    //comando que abre o arquivo para escrita
    p = fopen("Reservas.bin", "ab");

    //verifica se a criação do arquivo foi bem sucedida 
    if (p == NULL) {
        printf("Problemas na abertura do Reservas.bin");
        exit(1);
    }


    //comandos para a escrita em arquivos .bin 
    if (!feof(p)) {
        fwrite(&reservasRAM, sizeof (reservas), 1, p);
    }else {
        printf("O arquivo se encontra cheio.");
    }

    fclose(p);

    printf("Arquivo gravado com sucesso\n");
    return 0;
}

//Função para descobrir as acomodações livres
int quartos_desocupados_bin(int qtd_aco) {
    int contador_quartos = 0;
    
    // Abra o arquivo de acomodações para leitura
    FILE *p_acomodacoes = fopen("Acomodacoes.bin", "rb");
    FILE *p_categorias = fopen("Categorias.bin", "rb");

    if (p_acomodacoes == NULL || p_categorias == NULL) {
         printf("Problemas na abertura do arquivo.bin");
         exit (1);
    }

    acomodacoes acmd;
    categoria_acomodacao cat_acmd;

    while (fread(&acmd, sizeof(acomodacoes), 1, p_acomodacoes) == 1) {
        if (acmd.ocupacao == 0) {
            contador_quartos++;
            printf("Codigo do quarto:%d\n", acmd.codigo);
            printf("Descrição do quarto:%s\n", acmd.descricao);
            printf("Facilidades do quarto:%s\n", acmd.facilidades);

            // Volte ao início do arquivo de categorias para encontrar a correspondente
            fseek(p_categorias, 0, SEEK_SET);

            while (fread(&cat_acmd, sizeof(categoria_acomodacao), 1, p_categorias) == 1) {
                if (acmd.categoria == cat_acmd.codigo) {
                    printf("Codigo da categoria:%d\n", cat_acmd.codigo);
                    printf("Descrição da categoria:%s\n", cat_acmd.descricao);
                    printf("Valor da diária da categoria:%f\n", cat_acmd.valor_diaria);
                    printf("Crianças comportadas:%d\n", cat_acmd.criancas);
                    printf("Adultos comportados:%d\n\n\n\n\n", cat_acmd.adultos);
                    break;
                }
            }
        }
    }

    fclose(p_acomodacoes);
    fclose(p_categorias);

    if (contador_quartos == qtd_aco) {
        return 1;
    }

    return 0;
}

//Função para ler o binário das reservas e levar para a RAM.
int reservas_ram_bin(reservas *reservas_inf) {
    FILE *p;

    //comando para a leitura de um arquivo .bin
    p = fopen("Reservas.bin", "rb");

    //verifica se existe o arquivo
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin");
        exit(1);
    }

    int i = 0; 

    while (fread(&reservas_inf[i], sizeof (reservas), 1, p) == 1) {
        i++;
    }

    if (ferror(p)) {
        // Verifica se houve erro durante a leitura do arquivo
        printf("Erro na leitura do arquivo .bin");
        fclose(p);
        exit(1);
    }

    fclose(p);
    return 0;
}

//Função para ler e printar os dados das reservas.
void dados_reservas_bin() {
    FILE *p;
    
    // Abrir o arquivo binário para leitura
    p = fopen("Reservas.bin", "rb");
    
    // Verificar se o arquivo foi aberto com sucesso
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin\n");
        exit (1);
    }
    
    reservas reservas_inf;
    
    // Ler e imprimir os dados das reservas
    while (fread(&reservas_inf, sizeof(reservas), 1, p) == 1) {
        
        printf("\n-------DADOS DAS RESERVAS-------\n\n");
        
        printf("Codigo: %d\n", reservas_inf.codigo_res);
        printf("Codigo da acomodação: %d\n", reservas_inf.codigo_aco);
        printf("Descrição: %s\n", reservas_inf.descricao); 
        printf("Facilidades: %s\n", reservas_inf.facilidades); 
        printf("Codigo da categoria: %d\n", reservas_inf.categoria.codigo);
        printf("Descrição da categoria: %s\n", reservas_inf.categoria.descricao);
        printf("Diaria da categoria: R$%.2f\n", reservas_inf.categoria.valor_diaria);
        printf("Número de adultos da categoria: %d\n", reservas_inf.categoria.adultos);
        printf("Número de crianças da categoria: %d\n", reservas_inf.categoria.criancas);
        printf("Data de check-in: %d/%d/%d\n", reservas_inf.datas.dia_in, reservas_inf.datas.mes_in, reservas_inf.datas.ano_in);
        printf("Data de check-out: %d/%d/%d\n", reservas_inf.datas.dia_out, reservas_inf.datas.mes_out, reservas_inf.datas.ano_out);
        printf("Codigo do hospede: %d\n\n", reservas_inf.cod_hospede);
    }
    
    fclose(p);
}

//Função para ler e printar uma reserva especifica.
int print_reserva_bin(int codigo_res) {
    int cod_aco;
    FILE *p;
    
    // Abrir o arquivo binário para leitura
    p = fopen("Reservas.bin", "rb");
    
    // Verificar se o arquivo foi aberto com sucesso
    if (p == NULL) {
        printf("Problemas na abertura do arquivo.bin\n");
        exit (1);
    }
    
    reservas reservas_inf;
    
    // Ler e imprimir os dados das reservas
    while (fread(&reservas_inf, sizeof(reservas), 1, p) == 1) {
        
        if(reservas_inf.codigo_res==codigo_res){
        printf("\n-------DADOS DAS RESERVAS-------\n\n");
        
        printf("Codigo: %d\n", reservas_inf.codigo_res);
        printf("Codigo da acomodação: %d\n", reservas_inf.codigo_aco);
        printf("Descrição: %s\n", reservas_inf.descricao); 
        printf("Facilidades: %s\n", reservas_inf.facilidades); 
        printf("Codigo da categoria: %d\n", reservas_inf.categoria.codigo);
        printf("Descrição da categoria: %s\n", reservas_inf.categoria.descricao);
        printf("Diaria da categoria: R$%.2f\n", reservas_inf.categoria.valor_diaria);
        printf("Número de adultos da categoria: %d\n", reservas_inf.categoria.adultos);
        printf("Número de crianças da categoria: %d\n", reservas_inf.categoria.criancas);
        printf("Data de check-in: %d/%d/%d\n", reservas_inf.datas.dia_in, reservas_inf.datas.mes_in, reservas_inf.datas.ano_in);
        printf("Data de check-out: %d/%d/%d\n", reservas_inf.datas.dia_out, reservas_inf.datas.mes_out, reservas_inf.datas.ano_out);
        printf("Codigo do hospede: %d\n\n", reservas_inf.cod_hospede);
        
        cod_aco = reservas_inf.codigo_aco;
        
        }    
    }
    
    fclose(p);
    
    return cod_aco;
}

//printa as datas em que aquela quarto esta reservado
int procura_data_reserva_bin(int codigo_acomodacao){
    
     FILE *p_reserva = fopen("Reservas.bin", "rb");

    if (p_reserva == NULL) {
        printf("Problemas na abertura do arquivo de reservas.\n");
        exit(1);
    }

    reservas reserva;

    while (fread(&reserva, sizeof (reservas), 1, p_reserva) == 1) {
        
        if(reserva.codigo_aco == codigo_acomodacao){
           printf("Chek-in:%d/%d/%d\t",reserva.datas.dia_in,reserva.datas.mes_in,reserva.datas.ano_in);
           printf("Chek-out:%d/%d/%d\n\n",reserva.datas.dia_out,reserva.datas.mes_out,reserva.datas.ano_out);        
        
        }
    }


    fclose(p_reserva);

    return 1;
}

//verifica se o quarto escolhido esta com a ocupacao igual a 0 ou seja se nao existe nenhuma reserva
int verifica_ocupacao_bin(int codigo_acomodacao){
   
    FILE *p_acomod = fopen("Acomodacoes.bin", "rb");

    if (p_acomod == NULL) {
        printf("Problemas na abertura do arquivo de reservas.\n");
        exit(1);
    }

    acomodacoes acmd;

    while (fread(&acmd, sizeof (acomodacoes), 1, p_acomod) == 1) {

       if(acmd.codigo == codigo_acomodacao){
           
               fclose(p_acomod);
               
           if(acmd.ocupacao==0){
               return 0;
           }else{
               return 1;
           }    
       }
    }

    return -1;
}

// Função para verificar e coletar códigos das acomodações disponíveis que possuem todas as facilidades
int verificar_acomodacoes_disponiveis_bin(const char *facilidades_usuario, int *codigos_disponiveis) {
    FILE *p_acomd = fopen("Acomodacoes.bin", "rb");
    
    if (p_acomd == NULL) {
        printf("Problemas na abertura do arquivo de acomodações.\n");
        return 0;   
    }

    acomodacoes acomodacao;
    int qtd_codigos = 0;

    while (fread(&acomodacao, sizeof(acomodacoes), 1, p_acomd) == 1) {
        // Inicialize a flag como verdadeira para cada acomodação
        int atende_todas_facilidades = 1;
        
        // Verifique se a acomodação possui todas as facilidades especificadas
        for (int i = 0; facilidades_usuario[i] != NULL; i++) {
            const char *facilidade_usuario = facilidades_usuario[i]; // Não é necessário fazer uma cópia

            // Use uma função de comparação de strings que seja sensível a maiúsculas e minúsculas
            if (strstr(acomodacao.facilidades, facilidade_usuario) == NULL) {
                // Se alguma facilidade não for encontrada, a acomodação não atende aos critérios
                atende_todas_facilidades = 0;
                break; // Não é necessário verificar mais, então saia do loop
            }
        }
        
        // Se a acomodação atender a todas as facilidades, armazene seu código
        if (atende_todas_facilidades == 1) {
            codigos_disponiveis[qtd_codigos] = acomodacao.codigo;
            qtd_codigos++;
        }
    }
    fclose(p_acomd);
    if (qtd_codigos == 0){
        printf("Nenhuma acomodação encontrada.\n");
    }
    
    return qtd_codigos;
}

//Função que atualiza os dados das reservas.
int atualiza_reservas_bin(reservas *nova_reservas, int codigo_reserva) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Reservas.bin", "rb");
    temporario = fopen("Reservas_temp.bin", "wb");

    if (original == NULL) {
        perror("Erro na abertura do arquivo original");
        exit(1);
    }

    if (temporario == NULL) {
        perror("Erro na abertura do arquivo temporário");
        exit(1);
    }

    reservas resrv;

    while (fread(&resrv, sizeof (reservas), 1, original) == 1) {
        if (resrv.codigo_res == codigo_reserva) {
            // O registro com o código desejado foi encontrado e substituído
            fwrite(nova_reservas, sizeof (reservas), 1, temporario);
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&resrv, sizeof (reservas), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Reserva com código %d não encontrado.\n", codigo_reserva);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Reservas.bin") != 0) {
        perror("Erro na remoção do arquivo original");
        exit(1);
    }

    if (rename("Reservas_temp.bin", "Reservas.bin") != 0) {
        perror("Erro na renomeação do arquivo temporário");
        exit(1);
    }

    printf("Atualização dos dados das reservas feita com sucesso\n");
    return 0;
}

//Função que deleta os dados das reservas.
int deleta_reservas_bin( int codigo_reserva) {
    int encontrado = 0;
    FILE *original, *temporario;

    original = fopen("Reservas.bin", "rb");
    temporario = fopen("Reservas_temp.bin", "wb");

    if (original == NULL || temporario == NULL) {
        printf("Erro na abertura de arquivos.");
        exit(1);
    }

    reservas resrv;

    while (fread(&resrv, sizeof(reservas), 1, original) == 1) {
        if (resrv.codigo_res == codigo_reserva) {
            // O registro com o código desejado foi encontrado e o apaga.
            encontrado = 1;
        } else {
            // Escreva os outros registros no arquivo temporário
            fwrite(&resrv, sizeof(reservas), 1, temporario);
        }
    }

    fclose(original);
    fclose(temporario);

    if (encontrado == 0) {
        printf("Reserva com código %d não encontrado.\n", codigo_reserva);
        return 0;
    }

    // Substitui o arquivo original pelo temporário
    if (remove("Reservas.bin") != 0) {
        printf("Erro na remoção do arquivo original.");
        exit(1);
    }

    if (rename("Reservas_temp.bin", "Reservas.bin") != 0) {
        printf("Erro na renomeação do arquivo temporário.");
        exit(1);
    }

    printf("Delete dos dados das reservas feita com sucesso\n");
    return 0;
}
