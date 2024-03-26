#ifndef STRUCTS_H
#define STRUCTS_H


//struct feito para detalhes do endereço do hotel
typedef struct{
         char estado[30];
         char cidade[30];
         char cep[12];
         char bairro[30];
         char rua[50];
         int numero;
}dados_edrc;

//struct que guarda o horario de checkin
typedef struct{
        int hora;
        int minutos;
}checkin;

//struct que guarda o horario de checkout
typedef struct{
        int hora;
        int minutos;
}checkout;

//struct que contem os dados do hotel
typedef struct{
    
    char nome_fantasia[50];
    char razao_social[50];
    char inscricao_estadual[40];
    char cnpj[18];
    dados_edrc endereco;
    char telefone[20];
    char email[50];
    char nome_responsavel[50];//Nome do responsável (dono ou gerente)
    char telefone_responsavel[15];//Telefone do responsável (dono ou gerente)
    checkin horario_checkin;
    checkout horario_checkout;
    float mlpv;//Margem de lucro de produtos vendidos
    
}cad_hotel;

//struct que guarda as permissoes de cada modulo
typedef struct{
        int cadastros;
        int reservas;
        int transacoes;
        int feedback;
        int im_exportacao;
}permissao;

//struct que guarda os dados referentes aos operadores do sistema 
typedef struct{
        int codigo;
        char nome[50],usuario[30];
        int senha;
        permissao permissoes;
}OPsistema;

//struct que guarda os dados referentes ao usuario do sistema
typedef struct{
        int codigo;
        char nome[50];
        int senha;
}dados_usuario;


//struct para a data de nascimento
typedef struct{
    int dia;
    int mes;
    int ano;
}data;

//struct que contem os dados dos hospedes
typedef struct{
    int codigo;
    char nome[50];
    dados_edrc endereco_hospede;
    char cpf[15];
    char telefone[15];
    char email[50];
    char sexo[40];
    char estado_civil[40];
    data data_nacimento;
}hospedes;

typedef struct{
    int codigo;
    char descricao[50];
    int estoque;
    int estoque_min;
    float preco_custo;
    float preco_venda;
}produtos;

typedef struct{
    int codigo;
    char nome_fantasia[50];
    char razao_social[50];
    char inscricao_estadual[40];
    char cnpj[18];
    dados_edrc endereco;
    char telefone[20];
    char email[50];
}fornecedores;

typedef struct{
    int codigo;
    char descricao[50];
    float valor_diaria;
    int adultos;
    int criancas;
}categoria_acomodacao;

typedef struct{
    int codigo;
    char descricao[50];
    char facilidades[50];
    int categoria;
    float lucro;
    int diarias;
    int ocupacao;
}acomodacoes;

typedef struct{
    int dia_in;
    int mes_in;
    int ano_in;  
    int dia_out;
    int mes_out;
    int ano_out; 
}data_chek_in_out;



typedef struct{
    int codigo_res;
    int codigo_aco;
    char descricao[50];
    char facilidades[50];
    categoria_acomodacao categoria;
    data_chek_in_out  datas;
    int cod_hospede;
}reservas;

typedef struct{
    int codigo_res;
    int codigo_hos;
    float valor_devido;
}conta_hospede;

typedef struct{
    int codigo_hos;
    float valor_devido;
    data date;
}conta_receber;


typedef struct {
    char nome[100];
    float preco;
    int quantidade;
    float subtotal;
} entrada_produto;

typedef struct {
    char fornecedor[100];
    char cnpj[15];
    float frete;
    float imposto;
    float total;
    int num_produtos;
    entrada_produto *entra_prod;
} NotaFiscal;

typedef struct{
    int qtd;
    int cod_hos;
    int cod_prod;
    float valor;
    int pagamento;
    //1=A vista 2=Anotar//
}vendas;


#endif // STRUCTS_H