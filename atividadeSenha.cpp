#include <iostream>
using namespace std;
#define MAX 5
struct Fila {
    int inicio;
    int fim;
    float nos[MAX];
};
Fila* init() {
    Fila* f = new Fila;
    f->inicio = 0;
    f->fim = 0;
    return f;
}
int isEmpty(Fila* f) {
    return (f->inicio == f->fim);
}
int incrementa(int i) {
    return (i == MAX ? 0 : ++i);
}
int count(Fila* f) {
    int qtde = 0;
    int i = f->inicio;
    while (i != f->fim) {
        qtde++;
        i = incrementa(i);
    }
    return qtde;
}
void print(Fila* f) {
    int i = f->inicio;
    cout << "------------" << endl;
    while (i != f->fim) {
        cout << f->nos[i] << endl;
        i = incrementa(i);
    }
    cout << "------------" << endl;
}
void freeFila(Fila* f) {
    free(f);
}
int enqueue(Fila* f, float v) {
    int podeEnfileirar = (incrementa(f->fim) != f->inicio);
    if (podeEnfileirar) {
        f->nos[f->fim] = v;
        f->fim = incrementa(f->fim);
    }
    return podeEnfileirar;
}
float dequeue(Fila* f) {
    float ret;
    if (isEmpty(f)) {
        ret = -1;
    }
    else {
        ret = f->nos[f->inicio];
        f->inicio = incrementa(f->inicio);
    }
    return ret;
}

int main() {
    Fila* senhas = init();
    Fila* senhasAtendidas = init();

    int primeiraExecucao = 1;
    int opcao = -1;
    while (opcao != 0) {

        cout << "Qual a opção desejada?" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Gerar senha" << endl;
        cout << "2 - Realizar atendimento" << endl;
        cout << "Quantidade de senhas: " << count(senhas) << endl;
        cin >> opcao;

        if (opcao == 1) {
            float novaSenha = count(senhas) + 1;
            if (enqueue(senhas, novaSenha)) {
                cout << "Senha: " << novaSenha << endl;
            }
            else {
                cout << "Limite de senhas atingido." << endl;
            }
        }
        else if (opcao == 2) {
            if (!isEmpty(senhas)) {
                float senhaAtual = dequeue(senhas);
                cout << "Atendimento concluído. Senha: " << senhaAtual << endl;
                enqueue(senhasAtendidas, senhaAtual);
            }
            else {
                cout << "Ainda não há senhas." << endl;
            }
        } else if (opcao == 0) {
        if (isEmpty(senhas)) {
            cout << "Não há senhas aguardando atendimento." << endl;
            opcao = 0;
        } else {
            cout << "Ainda há senhas aguardando atendimento." << endl;
            opcao = -1;
        }
        }
        primeiraExecucao = 0;
    }
    cout << "Quantidade de senhas atendidas: " << count(senhasAtendidas) << endl;

    freeFila(senhas);
    freeFila(senhasAtendidas);

    return 0;
}
