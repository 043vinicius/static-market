#include <stdio.h>
#include <math.h>
#include <string.h>

const int CLUBE[] = {1, 2, 3, 4, 5, 6};

typedef struct {
    char nome[255];
    int idade;
    int clubeVantagens;
} cliente;

typedef struct {
    int valorTotal;
    int itens;
    int desconto;
    int valorDesconto;
    int valorFinal;
} carrinho;

cliente cadastrarUser();
carrinho registrarCarrinho();
int verificarClube();

int main() {
   // Cadastra o usuário e verifica se ele possui cadastro no clube de vantagens
    cliente USER = cadastrarUser();
    // Função que registra o carrinho do cliente
    carrinho CARRINHO = registrarCarrinho(USER);
    // Função que calcula o valor total da compra e da os descontos se aplicável
 
    return 0;
}

/**
 * Realiza o cadastro do usuario 
 * @return {struct}
 */
cliente cadastrarUser() {
    cliente USER;

    printf("Digite seu nome: ");
    scanf("%[^\n]s", &USER.nome);
    printf("Digite sua idade: ");
    scanf("%d", &USER.idade);
    int validarClube = verificarClube();
    if (validarClube == 0) {
        printf("Clube de vantagens não encontrado!\n\n");
        USER.clubeVantagens = validarClube;
        printf("Nome: %s\nIdade: %d\nIdentificação do clube de vantagens: Não possui!\n", USER.nome, USER.idade);
    } else {
        USER.clubeVantagens = validarClube;
        printf("Bem vindo %s! seu clube de vantagens foi encontrado e você possui 5% de desconto em suas compras!\n\n", USER.nome);
        printf("\nNome: %s\nIdade: %d\nIdentificação do clube de vantagens: %d\n", USER.nome, USER.idade, USER.clubeVantagens);
    }

    return USER;
}

/**
 * Realiza o registro do carrinho do cliente
 * @return {struct}
 */
carrinho registrarCarrinho(USER) {
    carrinho CARRINHO;
    int option, valor, desconto;


    return CARRINHO;
}

/**
 * Realiza a validação do número do clube de vantagens
 * @return {int}
 */
int verificarClube() {
    int clubeVantagens;
    printf("Digite o número do clube de vantagens: ");
    scanf("%d", &clubeVantagens);

    for (int i = 0; i < sizeof(CLUBE); i++) { // Laço de repetição
        if (clubeVantagens == CLUBE[i]) {
            return clubeVantagens;
        }
    }


    return 0;
}