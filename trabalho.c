#include <stdio.h>

// Caso esteja utilizando o Windows, usará a biblioteca windows.h, caso contrário, usará a biblioteca unistd.h
#ifdef _WIN32 || _WIN64
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Códigos cadastrado no clube(considere como um CPF)
const int CLUBE[] = {1, 2, 3, 4, 5, 6};

typedef struct {
    char nome[255];
    int idade;
    int clubeVantagens;
} cliente;

typedef struct {
    double subTotal;
    int itens;
    double valorDesconto;
    double total;
} carrinho;

cliente cadastrarUser();
carrinho registrarCarrinho(nome, idade, clubeVantagens);
carrinho atualizarCarrinho(option, CARRINHO);
int verificarClube();
void sair();

int main() {
    // Limpa a tela
    system("cls");
   // Cadastra o usuário e verifica se ele possui cadastro no clube de vantagens
    cliente USER = cadastrarUser();
    // Função que registra o carrinho do cliente
    carrinho CARRINHO = registrarCarrinho(USER.nome, USER.idade, USER.clubeVantagens);

    // Função que realiza a saída do aplicativo
    sair();
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
    printf("Cadastrando...");
    sleep(1); // Função que faz o programa esperar por um tempo
    system("cls");

    printf("Digite sua idade: ");
    scanf("%d", &USER.idade);
    printf("Cadastrando...");
    sleep(1);
    system("cls");

    USER.clubeVantagens = verificarClube();
    if (USER.clubeVantagens == 0) {
        printf("Clube de vantagens não encontrado!\n\n");
        sleep(1);
        system("cls");
    } else {
        printf("Bem vindo %s! seu clube de vantagens foi encontrado e você possui 5%% de desconto em suas compras!\n\n", USER.nome);
        sleep(2);
        system("cls");
    }

    return USER;
}

/**
 * Realiza o registro do carrinho do cliente
 * @return {struct}
 */
carrinho registrarCarrinho(char nome[], int idade, int clubeVantagens) {
    carrinho CARRINHO;
    CARRINHO.subTotal = 0.00;
    CARRINHO.itens = 0;
    CARRINHO.valorDesconto = 0.00;
    CARRINHO.total = 0.00;
    
    int option;

    while(option != 0) {
        system("cls");
        mostrarProdutos(CARRINHO, nome, idade, clubeVantagens);
        scanf("%d", &option);
        if (option == 0) {
            break;
        }
        CARRINHO = atualizarCarrinho(option, CARRINHO, clubeVantagens, idade);
        sleep(2);
    }


    return CARRINHO;
}

/**
 * Realiza a exibição dos produtos
 * @return {struct}
 */
void mostrarProdutos(carrinho CARRINHO, char nome[], int idade, int clubeVantagens) {

        printf("-------------------------------------------------------\n");
        printf("Cliente: %s\n", nome);
        printf("Idade: %d\n", idade);
        if (clubeVantagens != 0) {
            printf("Desconto: 5%%\n");
            printf("Identificação do clube de vantagens: %d\n", clubeVantagens);
        }
        printf("-------------------------------------------------------\n");
        printf("Selecione uma opção:\n");
        printf("1. Arroz: R$15,00\n");
        printf("2. Feijão: R$10,00\n");
        printf("3. Macarrão: R$5,00\n");
        printf("4. Carne: R$30,00\n");
        printf("5. Frango: R$20,00\n");
        printf("6. Peixe: R$25,00\n");
        printf("7. Leite: R$5,00\n");
        printf("8. Ovos: R$10,00\n");
        printf("9. Açucar: R$5,00\n");
        printf("10. Café: R$10,00\n");
        printf("11. Óleo: R$5,00\n");
        printf("12. Sal: R$5,00\n");
        printf("13. Farinha: R$5,00\n");
        printf("14. Fubá: R$5,00\n");
        printf("15. Cerveja: R$5,00\n");
        printf("16. Vodka: R$50,00\n");
        printf("17. Whisky: R$75,00\n");
        printf("18. Energético: R$10,00\n");
        printf("\n0. Finalizar a compra\n");
        printf("-------------------------------------------------------\n");
        printf("Sub-total: R$ %.2lf\n", CARRINHO.subTotal);
        printf("Qtd. de itens: %d\n", CARRINHO.itens);
        if (clubeVantagens != 0) {
            printf("Desconto: 5%%\n");
        } else {
            printf("Desconto: 0%%\n");
        }
        printf("Valor do desconto: R$ %.2lf\n", CARRINHO.valorDesconto);
        printf("Total: R$ %.2lf\n", CARRINHO.total);
        printf("-------------------------------------------------------\n");
        printf("Digite sua opção: ");
}

/**
 * Realiza a validação do número do clube de vantagens
 * @return {int}
 */
int verificarClube() {
    int clubeVantagens;
    printf("Você possui cadastro no clube de vantagens?\n");
    printf("Se sim, digite o número do clube de vantagens, se não, digite 0: ");
    scanf("%d", &clubeVantagens);
    printf("Validando clube de vantagens...");
    sleep(1);
    system("cls");

    for (int i = 0; i < sizeof(CLUBE); i++) { // Laço de repetição
        if (clubeVantagens == CLUBE[i]) {
            return clubeVantagens;
        }
    }


    return 0;
}

/**
 * Realiza a atualização do carrinho
 * @return {struct}
 */
carrinho atualizarCarrinho(int option, carrinho CARRINHO, int clubeVantagens, int idade) {
    double valor, desconto;
    switch (option) {
        case 1:
            valor = 15;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Arroz\n");
            break;
        case 2:
            valor = 10;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Feijão\n");
            break;
        case 3:
            valor = 5;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Macarrão\n");
            break;
        case 4:
            valor = 30;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Carne\n");
            break;
        case 5:
            valor = 20;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Frango\n");
            break;
        case 6:
            valor = 25;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Peixe\n");
            break;
        case 7:
            valor = 5;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Leite\n");
            break;
        case 8:
            valor = 10;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Ovos\n");
            break;
        case 9:
            valor = 5;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Açucar\n");
            break;
        case 10:
            valor = 10;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Café\n");
            break;
        case 11:
            valor = 5;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Óleo\n");
            break;
        case 12:
            valor = 5;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Sal\n");
            break;
        case 13:
            valor = 5;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Farinha\n");
            break;
        case 14:
            valor = 5;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Fubá\n");
            break;
        case 15:
            if (idade >= 18) {
                valor = 5;
                CARRINHO.subTotal += valor;
                CARRINHO.itens += 1;
                system("cls");
                printf("Selecionado: Cerveja\n");
            } else {
                printf("Você não tem idade suficiente para comprar bebidas alcoólicas!\n");
                sleep(2);
            }
            break;
        case 16:
            if (idade >= 18) {
                valor = 50;
                CARRINHO.subTotal += valor;
                CARRINHO.itens += 1;
                system("cls");
                printf("Selecionado: Vodka\n");
            } else {
                printf("Você não tem idade suficiente para comprar bebidas alcoólicas!\n");
                sleep(1);
            }
            break;
        case 17:
            if (idade >= 18) {
                valor = 75;
                CARRINHO.subTotal += valor;
                CARRINHO.itens += 1;
                system("cls");
                printf("Selecionado: Whisky\n");
            } else {
                printf("Você não tem idade suficiente para comprar bebidas alcoólicas!\n");
                sleep(1);
            }
            break;
        case 18:
            valor = 10;
            CARRINHO.subTotal += valor;
            CARRINHO.itens += 1;
            system("cls");
            printf("Selecionado: Energético\n");
            break;
        default:
            system("cls");
            printf("Opção inválida!\n");
            sleep(1);
            break;
    }

    if (clubeVantagens != 0) {
        desconto = CARRINHO.subTotal * 0.05;
        CARRINHO.valorDesconto = desconto;
        CARRINHO.total = CARRINHO.subTotal - desconto;
    } else {
        CARRINHO.valorDesconto = 0;
        CARRINHO.total = CARRINHO.subTotal;
    }

    return CARRINHO;
}

/**
 * Realiza a saída do programa
 * @return {void}
 */
void sair() {
    system("cls");
    printf("Saindo do aplicativo.");
    sleep(1);
    system("cls");
    printf("Saindo do aplicativo..");
    sleep(1);
    system("cls");
    printf("Saindo do aplicativo...");
    sleep(1);
    system("cls");
    printf("Saindo do aplicativo.");
    sleep(1);
    system("cls");
    printf("Saindo do aplicativo..");
    sleep(1);
    system("cls");
    printf("Saindo do aplicativo...");
    sleep(1);
}
