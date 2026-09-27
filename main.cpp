#include <iostream>
#include <string>

using namespace std;

int main() {

    // ============================================================
    // BANCO INF101 - Sistema de Registro e Gestão de Contas
    // ============================================================

    // Quantidade máxima de contas
    const int MAX_CONTAS = 5;

    // Arrays para armazenar os dados das contas
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    // Quantidade de contas cadastradas
    int quantidadeContas = 0;

    int opcao;

    // Inicializa todas as contas como inativas
    for (int i = 0; i < MAX_CONTAS; i++) {
        contaAtiva[i] = false;
    }

    // ============================================================
    // MENU PRINCIPAL
    // ============================================================

    do {

        cout << endl;
        cout << "********************************" << endl;
        cout << "**         BANCO INF101        **" << endl;
        cout << "********************************" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            // ====================================================
            // 1 - CADASTRAR CONTA
            // ====================================================

            case 1: {

                if (quantidadeContas >= MAX_CONTAS) {

                    cout << endl;
                    cout << "Limite de 5 contas atingido!" << endl;

                } else {

                    int numero;
                    bool numeroValido;

                    cout << endl;
                    cout << "===== CADASTRO DE CONTA =====" << endl;

                    // Validação do número da conta
                    do {

                        cout << "Numero da conta: ";
                        cin >> numero;

                        if (numero <= 0) {
                            cout << "Erro: o numero da conta deve ser maior que zero." << endl;
                            numeroValido = false;
                        } else {
                            numeroValido = true;
                        }

                    } while (!numeroValido);

                    // Verifica se o número já está cadastrado
                    bool numeroExiste = false;

                    for (int i = 0; i < quantidadeContas; i++) {

                        if (numeroConta[i] == numero) {
                            numeroExiste = true;
                        }
                    }

                    if (numeroExiste) {

                        cout << "Erro: esse numero de conta ja esta cadastrado." << endl;

                    } else {

                        numeroConta[quantidadeContas] = numero;

                        cin.ignore();

                        cout << "Nome do titular: ";
                        getline(cin, nomeCliente[quantidadeContas]);

                        cout << "CPF do titular: ";
                        getline(cin, cpf[quantidadeContas]);

                        // Validação do tipo da conta
                        do {

                            cout << "Tipo da conta:" << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Escolha: ";
                            cin >> tipoConta[quantidadeContas];

                            if (tipoConta[quantidadeContas] != 1 &&
                                tipoConta[quantidadeContas] != 2) {

                                cout << "Erro: escolha 1 ou 2." << endl;
                            }

                        } while (tipoConta[quantidadeContas] != 1 &&
                                 tipoConta[quantidadeContas] != 2);

                        // Validação do saldo
                        do {

                            cout << "Saldo inicial: ";
                            cin >> saldo[quantidadeContas];

                            if (saldo[quantidadeContas] < 0) {
                                cout << "Erro: o saldo nao pode ser negativo." << endl;
                            }

                        } while (saldo[quantidadeContas] < 0);

                        // Conta começa ativa
                        contaAtiva[quantidadeContas] = true;

                        quantidadeContas++;

                        cout << endl;
                        cout << "Conta cadastrada com sucesso!" << endl;
                    }
                }

                break;
            }

            // ====================================================
            // 2 - CONSULTAR CONTA
            // ====================================================

            case 2: {

                if (quantidadeContas == 0) {

                    cout << endl;
                    cout << "Nenhuma conta cadastrada." << endl;

                } else {

                    int numero;
                    bool encontrada = false;

                    cout << endl;
                    cout << "===== CONSULTAR CONTA =====" << endl;
                    cout << "Digite o numero da conta: ";
                    cin >> numero;

                    for (int i = 0; i < quantidadeContas; i++) {

                        if (numeroConta[i] == numero) {

                            encontrada = true;

                            cout << endl;
                            cout << "Numero da conta: " << numeroConta[i] << endl;
                            cout << "Nome do titular: " << nomeCliente[i] << endl;
                            cout << "CPF: " << cpf[i] << endl;

                            cout << "Tipo da conta: ";

                            if (tipoConta[i] == 1) {
                                cout << "Corrente" << endl;
                            } else {
                                cout << "Poupanca" << endl;
                            }

                            cout << "Saldo: R$ " << saldo[i] << endl;

                            cout << "Status: ";

                            if (contaAtiva[i]) {
                                cout << "Ativa" << endl;
                            } else {
                                cout << "Inativa" << endl;
                            }
                        }
                    }

                    if (!encontrada) {
                        cout << "Conta nao encontrada." << endl;
                    }
                }

                break;
            }

            // ====================================================
            // 3 - VERIFICAR SALDO
            // ====================================================

            case 3: {

                if (quantidadeContas == 0) {

                    cout << endl;
                    cout << "Nenhuma conta cadastrada." << endl;

                } else {

                    int numero;
                    bool encontrada = false;

                    cout << endl;
                    cout << "===== VERIFICAR SALDO =====" << endl;
                    cout << "Numero da conta: ";
                    cin >> numero;

                    for (int i = 0; i < quantidadeContas; i++) {

                        if (numeroConta[i] == numero) {

                            encontrada = true;

                            // Verifica se a conta está ativa
                            if (contaAtiva[i]) {

                                cout << "Saldo atual: R$ "
                                     << saldo[i] << endl;

                            } else {

                                cout << "A conta esta inativa." << endl;
                                cout << "Nao e possivel consultar o saldo." << endl;
                            }
                        }
                    }

                    if (!encontrada) {
                        cout << "Conta nao encontrada." << endl;
                    }
                }

                break;
            }

            // ====================================================
            // 4 - ALTERAR TIPO DA CONTA
            // ====================================================

            case 4: {

                if (quantidadeContas == 0) {

                    cout << endl;
                    cout << "Nenhuma conta cadastrada." << endl;

                } else {

                    int numero;
                    bool encontrada = false;

                    cout << endl;
                    cout << "===== ALTERAR TIPO DA CONTA =====" << endl;
                    cout << "Numero da conta: ";
                    cin >> numero;

                    for (int i = 0; i < quantidadeContas; i++) {

                        if (numeroConta[i] == numero) {

                            encontrada = true;

                            // Operação depende da conta estar ativa
                            if (!contaAtiva[i]) {

                                cout << "A conta esta inativa." << endl;
                                cout << "Nao e possivel alterar o tipo." << endl;

                            } else {

                                do {

                                    cout << endl;
                                    cout << "Novo tipo da conta:" << endl;
                                    cout << "1 - Corrente" << endl;
                                    cout << "2 - Poupanca" << endl;
                                    cout << "Escolha: ";
                                    cin >> tipoConta[i];

                                    if (tipoConta[i] != 1 &&
                                        tipoConta[i] != 2) {

                                        cout << "Erro: escolha 1 ou 2." << endl;
                                    }

                                } while (tipoConta[i] != 1 &&
                                         tipoConta[i] != 2);

                                cout << "Tipo da conta alterado com sucesso!" << endl;
                            }
                        }
                    }

                    if (!encontrada) {
                        cout << "Conta nao encontrada." << endl;
                    }
                }

                break;
            }

            // ====================================================
            // 5 - ATIVAR / DESATIVAR CONTA
            // ====================================================

            case 5: {

                if (quantidadeContas == 0) {

                    cout << endl;
                    cout << "Nenhuma conta cadastrada." << endl;

                } else {

                    int numero;
                    bool encontrada = false;

                    cout << endl;
                    cout << "===== ATIVAR/DESATIVAR CONTA =====" << endl;
                    cout << "Numero da conta: ";
                    cin >> numero;

                    for (int i = 0; i < quantidadeContas; i++) {

                        if (numeroConta[i] == numero) {

                            encontrada = true;

                            if (contaAtiva[i]) {

                                contaAtiva[i] = false;

                                cout << "Conta desativada com sucesso!" << endl;

                            } else {

                                contaAtiva[i] = true;

                                cout << "Conta ativada com sucesso!" << endl;
                            }
                        }
                    }

                    if (!encontrada) {
                        cout << "Conta nao encontrada." << endl;
                    }
                }

                break;
            }

            // ====================================================
            // 6 - SAIR
            // ====================================================

            case 6:

                cout << endl;
                cout << "Obrigado por utilizar o Banco INF101!" << endl;
                cout << "Programa encerrado." << endl;

                break;

            // ====================================================
            // OPÇÃO INVÁLIDA
            // ====================================================

            default:

                cout << endl;
                cout << "Opcao invalida! Escolha uma opcao de 1 a 6." << endl;

                break;
        }

    } while (opcao != 6);

    return 0;
}