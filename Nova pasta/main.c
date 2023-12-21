#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_STR_LEN 50

float m(float x1, float x2) {
    return (x1 * x2);
}

struct venda_de_passagens {
    int origem;
    int destino;
    char saida[MAX_STR_LEN];
    char chegada[MAX_STR_LEN];
    float preco;
    float q;
};

void exibir_cidades() {
    printf("Cidades disponíveis:\n");
    printf("1. Volta Redonda\n2. Resende\n3. Barra Mansa\n4. Barra do Piraí\n5. São José dos Campos\n6. Taubaté\n7. Caçapava\n8. Jacareí\n9. Pindamonhangaba\n10. Guaratinguetá\n11. Lorena\n12. Caraguatatuba\n13. Cruzeiro\n14. Aparecida\n15. Cachoeira Paulista\n");
}

const char* obter_nome_cidade(int codigo) {
    switch (codigo) {
        case 1: return "Volta Redonda";
        case 2: return "Resende";
        case 3: return "Barra Mansa";
        case 4: return "Barra do Piraí";
        case 5: return "São José dos Campos";
        case 6: return "Taubaté";
        case 7: return "Caçapava";
        case 8: return "Jacareí";
        case 9: return "Pindamonhangaba";
        case 10: return "Guaratinguetá";
        case 11: return "Lorena";
        case 12: return "Caraguatatuba";
        case 13: return "Cruzeiro";
        case 14: return "Aparecida";
        case 15: return "Cachoeira Paulista";
        default: return "Desconhecida";
    }
}

void exibir_vendas() {
    FILE* arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo\n");
        return;
    }

    struct venda_de_passagens venda;
    while (fscanf(arquivo, "Origem: %d\nDestino: %d\nSaída: %s\nChegada: %s\nPreço: %f\nPassagens: %f\n", &venda.origem, &venda.destino, venda.saida, venda.chegada, &venda.preco, &venda.q) == 6) {
        printf("\nOrigem: %s\nDestino: %s\nSaída: %s\nChegada: %s\nPreço: %.2f\nPassagens: %.f\n",
               obter_nome_cidade(venda.origem),
               obter_nome_cidade(venda.destino),
               venda.saida,
               venda.chegada,
               venda.preco,
               venda.q);
    }

    fclose(arquivo);
}
void salvar_venda(struct venda_de_passagens venda) {
    FILE* arquivo = fopen("arquivo.txt", "a");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo\n");
        return;
    }

    fprintf(arquivo, "Origem: %s\nDestino: %s\nSaída: %s\nChegada: %s\nPreço: %.2f\nPassagens: %.f\n",
            obter_nome_cidade(venda.origem),
            obter_nome_cidade(venda.destino),
            venda.saida,
            venda.chegada,
            venda.preco,
            venda.q);

    fclose(arquivo);
}


int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int op = 0, a2 = 0;
    struct venda_de_passagens p;

    do {
        printf("\t\t------  BEM VINDO   ------\n");
        printf("Escolha uma opção:\n");
        printf("\t(1) - Cadastrar passagem\n");
        printf("\t(2) - Exibir lista de vendas\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                exibir_cidades();

                printf("Escolha a cidade de origem (pelo número):\n");
                scanf("%d", &p.origem);

                printf("Escolha a cidade de destino (pelo número):\n");
                scanf("%d", &p.destino);

                printf("Horário de saída (hh:mm):\n");
                scanf("%s", p.saida);

                printf("Horário de chegada (hh:mm):\n");
                scanf("%s", p.chegada);

                printf("Preço da passagem:\n");
                scanf("%f", &p.preco);

                printf("\nQuantas passagens você gostaria de comprar?\n");
                scanf("%f", &p.q);

                salvar_venda(p);
                break;

            case 2:
                exibir_vendas();
                break;

            default:
                printf("OPÇÃO INVÁLIDA\n");
        }

        printf("\nContinuar usando o sistema?\n");
        printf(" 1- Sim\n");
        printf(" 2- Não\n");
        scanf("%d", &a2);
    } while (a2 == 1);

    return 0;
}
