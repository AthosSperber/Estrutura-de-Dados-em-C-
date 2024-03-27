#include <iostream>

#define TAMANHO_PILHA 10

using namespace std;

struct Carro {
    string  placa;
    int     ano;
};

struct Pilha {
    Carro   data[TAMANHO_PILHA];
    int     contador;
};

/* Protótipos das funções */
void inicializar(Pilha *);
void estacionar(Pilha *, string, int);
void estacionar(Pilha *, Carro);
Carro sair(Pilha *);
void imprime_pilha(Pilha *);
void imprime_tudo(Pilha *);
int quantidade_vagas(Pilha);

int main() {
    Pilha estacionamento;
    inicializar(&estacionamento);
    int escolha;
    string placa;
    int ano;
    Carro carro_comum;

    while (true) {
        cout << "\n----- Menu -----\n";
        cout << "1. Adicionar carro\n";
        cout << "2. Remover carro\n";
        cout << "3. Mostrar carros estacionados\n";
        cout << "4. Mostrar todos os carros na pilha\n";
        cout << "5. Mostrar quantidade de vagas disponíveis\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                cout << "Digite a placa do carro: ";
                cin >> placa;
                cout << "Digite o ano do carro: ";
                cin >> ano;
                estacionar(&estacionamento, placa, ano);
                break;
            case 2:
                carro_comum = sair(&estacionamento);
                break;
            case 3:
                imprime_pilha(&estacionamento);
                break;
            case 4:
                imprime_tudo(&estacionamento);
                break;
            case 5:
                cout << "Quantidade de vagas disponíveis: " << quantidade_vagas(estacionamento) << endl;
                break;
            case 6:
                cout << "Encerrando o programa.\n";
                return 0;
            default:
                cout << "Opção inválida. Por favor, escolha novamente.\n";
        }
    }

    return 0;
}

/* Implementação das funções */

void inicializar(Pilha *estacionamento) {
    estacionamento->contador = 0;
    for (int i = 0; i < TAMANHO_PILHA; i++) {
        estacionamento->data[i].placa = "AAA0000";
        estacionamento->data[i].ano = 0;
    }
}

void estacionar(Pilha *estacionamento, string placa, int ano) {
    if (estacionamento->contador < TAMANHO_PILHA) {
        estacionamento->data[estacionamento->contador].placa = placa;
        estacionamento->data[estacionamento->contador].ano = ano;
        estacionamento->contador++;
        cout << "Carro de placa " << placa << " e ano " << ano << " estacionado com sucesso." << endl;
    } else {
        cout << "Estacionamento lotado. Não é possível estacionar mais carros." << endl;
    }
}

void estacionar(Pilha *estacionamento, Carro carro) {
    if (estacionamento->contador < TAMANHO_PILHA) {
        estacionamento->data[estacionamento->contador] = carro;
        estacionamento->contador++;
        cout << "Carro de placa " << carro.placa << " e ano " << carro.ano << " estacionado com sucesso." << endl;
    } else {
        cout << "Estacionamento lotado. Não é possível estacionar mais carros." << endl;
    }
}

Carro sair(Pilha *estacionamento) {
    Carro carroSaindo;
    if (estacionamento->contador > 0) {
        estacionamento->contador--;
        carroSaindo = estacionamento->data[estacionamento->contador];
        estacionamento->data[estacionamento->contador].placa = "XXX0000";
        estacionamento->data[estacionamento->contador].ano = 0;
        cout << "Carro de placa " << carroSaindo.placa << " e ano " << carroSaindo.ano << " saiu do estacionamento." << endl;
    } else {
        cout << "Estacionamento vazio. Não há carros para sair." << endl;
    }
    return carroSaindo;
}

void imprime_pilha(Pilha *estacionamento) {
    cout << "Carros estacionados:" << endl;
    for (int i = 0; i < estacionamento->contador; i++) {
        cout << "Placa: " << estacionamento->data[i].placa << ", Ano: " << estacionamento->data[i].ano << endl;
    }
}

void imprime_tudo(Pilha *estacionamento) {
    cout << "Todos os carros na pilha:" << endl;
    for (int i = 0; i < TAMANHO_PILHA; i++) {
        cout << "Placa: " << estacionamento->data[i].placa << ", Ano: " << estacionamento->data[i].ano << endl;
    }
}

int quantidade_vagas(Pilha estacionamento) {
    return TAMANHO_PILHA - estacionamento.contador;
}
