/*
 Autores:
 * Isabela Mageste de Andrade
 * Victoria Tambasco 
 */
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

const int SIZE = 200;
using namespace std;

#define RESET   "\033[0m"

#define BOLD        "\033[1m"
#define ITALIC      "\033[3m"
#define UNDERLINE   "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m"
#define STRIKETHROUGH "\033[9m"

// Cores texto normal

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Cores texto brilhante
#define BBLACK   "\033[90m"
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"
//fundo das letras preto
#define BG_BLACK    "\033[40m"

// Função para imprimir linhas decorativas, conforme o tipo passado

void decorate(int x) {
    cout << endl;
    switch (x) {
        case 1:
            for (int i = 0; i < 20; i++) {
                cout << BLACK << "=-=" << RESET;
            }
            break;
        case 2:
            for (int i = 0; i < 20; i++) {
                cout << "===";
            }
            break;
        case 3:
            for (int i = 0; i < 20; i++) {
                cout << "---";
            }
            break;
    }
    cout << endl;
}

// Classe que representa um imóvel

struct Imovel {
    string tipo, finalidade, endereco, bairro, cidade;
    int area, valor, iptu, quartos, suites, banheiros, vagas;
    string cozinha, sala, varanda, areaServico, piso, conservacao, armarios, arCondicionado, aquecedor, ventilador;
};
// funcao para imprimir os dados do imóvel

void imprimeImovel(Imovel imovel) {
    cout << BOLD BMAGENTA "\t\t\t===DADOS DO IMOVEL==="RESET;
    decorate(2);
    cout << "\t|Tipo: " << imovel.tipo << endl;
    cout << "\t|Finalidade: " << imovel.finalidade << endl;
    cout << "\t|Endereco: " << imovel.endereco << endl;
    cout << "\t|Bairro: " << imovel.bairro << endl;
    cout << "\t|Cidade: " << imovel.cidade << endl;
    cout << "\t|Area: " << imovel.area << " m^2" << endl;
    cout << "\t|Valor: " << imovel.valor << " RS" << endl;
    cout << "\t|IPTU: " << imovel.iptu << " RS" << endl;
    cout << "\t|Quartos: " << imovel.quartos << endl;
    cout << "\t|Suites: " << imovel.suites << endl;
    cout << "\t|Banheiros: " << imovel.banheiros << endl;
    cout << "\t|Vagas: " << imovel.vagas << endl;
    cout << "\t|Cozinha: " << imovel.cozinha << endl;
    cout << "\t|Sala: " << imovel.sala << endl;
    cout << "\t|Varanda: " << imovel.varanda << endl;
    cout << "\t|Area de servico: " << imovel.areaServico << endl;
    cout << "\t|Piso: " << imovel.piso << endl;
    cout << "\t|Conservacao: " << imovel.conservacao << endl;
    cout << "\t|Armarios: " << imovel.armarios << endl;
    cout << "\t|Ar Condicionado: " << imovel.arCondicionado << endl;
    cout << "\t|Aquecedor: " << imovel.aquecedor << endl;
    cout << "\t|Ventilador: " << imovel.ventilador;
    decorate(2);
}

// Classe que representa a imobiliária (gerencia os imóveis)

struct Imobiliaria {
    int espacoUsado = SIZE; // Número de imóveis em uso
    Imovel imoveis[SIZE]; // Vetor com os imóveis
};
// Construtor chama o método para carregar os dados

// Método que carrega os dados do arquivo

void salvar(Imobiliaria &imobiliaria) {
    ofstream arquivo("database.txt");

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar" << endl;
        return;
    }

    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        arquivo << imobiliaria.imoveis[i].tipo << " "
                << imobiliaria.imoveis[i].finalidade << " "
                << imobiliaria.imoveis[i].endereco << " "
                << imobiliaria.imoveis[i].bairro << " "
                << imobiliaria.imoveis[i].cidade << " "
                << imobiliaria.imoveis[i].area << " "
                << imobiliaria.imoveis[i].valor << " "
                << imobiliaria.imoveis[i].iptu << " "
                << imobiliaria.imoveis[i].quartos << " "
                << imobiliaria.imoveis[i].suites << " "
                << imobiliaria.imoveis[i].banheiros << " "
                << imobiliaria.imoveis[i].vagas << " "
                << imobiliaria.imoveis[i].cozinha << " "
                << imobiliaria.imoveis[i].sala << " "
                << imobiliaria.imoveis[i].varanda << " "
                << imobiliaria.imoveis[i].areaServico << " "
                << imobiliaria.imoveis[i].piso << " "
                << imobiliaria.imoveis[i].conservacao << " "
                << imobiliaria.imoveis[i].armarios << " "
                << imobiliaria.imoveis[i].arCondicionado << " "
                << imobiliaria.imoveis[i].aquecedor << " "
                << imobiliaria.imoveis[i].ventilador << endl;
    }

    arquivo << "fim" << endl; // marca o fim
    arquivo.close();
}

void deletar(int pos, Imobiliaria &imobiliaria) {
    if (pos < 0 || pos >= imobiliaria.espacoUsado) {
        cout << "Posição inválida!" << endl;
        return;
    }

    for (int i = pos; i < imobiliaria.espacoUsado - 1; i++) {
        imobiliaria.imoveis[i] = imobiliaria.imoveis[i + 1]; // "puxa" o próximo para cima
    }

    imobiliaria.espacoUsado--; // reduz o total de imóveis
    salvar(imobiliaria); // atualiza o arquivo
    cout << "Imóvel na posição " << pos << " removido com sucesso." << endl;

}

void abreArquivo(Imobiliaria &imobiliaria) {
    ifstream arquivo("database.txt");
    string linha;

    if (!arquivo.is_open()) {
        cerr << "erro ao abrir o arquivo para leitura" << endl;
    } else {
        int i = 0;
        while (i < SIZE && arquivo >> imobiliaria.imoveis[i].tipo && imobiliaria.imoveis[i].tipo != "fim") {
            arquivo >> imobiliaria.imoveis[i].finalidade
                    >> imobiliaria.imoveis[i].endereco
                    >> imobiliaria.imoveis[i].bairro
                    >> imobiliaria.imoveis[i].cidade
                    >> imobiliaria.imoveis[i].area
                    >> imobiliaria.imoveis[i].valor
                    >> imobiliaria.imoveis[i].iptu
                    >> imobiliaria.imoveis[i].quartos
                    >> imobiliaria.imoveis[i].suites
                    >> imobiliaria.imoveis[i].banheiros
                    >> imobiliaria.imoveis[i].vagas
                    >> imobiliaria.imoveis[i].cozinha
                    >> imobiliaria.imoveis[i].sala
                    >> imobiliaria.imoveis[i].varanda
                    >> imobiliaria.imoveis[i].areaServico
                    >> imobiliaria.imoveis[i].piso
                    >> imobiliaria.imoveis[i].conservacao
                    >> imobiliaria.imoveis[i].armarios
                    >> imobiliaria.imoveis[i].arCondicionado
                    >> imobiliaria.imoveis[i].aquecedor
                    >> imobiliaria.imoveis[i].ventilador;
            i++;
        }

        imobiliaria.espacoUsado = i; // Ajusta tamanho
        //deletar(imobiliaria.espacoUsado, imobiliaria); // Remove último imóvel 
        //imobiliaria.espacoUsado--;
    }
    arquivo.close();
}



// Imprime todos os imóveis cadastrados

void imprimeImobiliaria(Imobiliaria &imobiliaria) {
    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        imprimeImovel(imobiliaria.imoveis[i]);
    }
}

// Salva os imóveis no arquivo


// Adiciona um novo imóvel manualmente

void adicionar(Imobiliaria &imobiliaria) {
    if (imobiliaria.espacoUsado >= SIZE) {
        cout << "Erro: Limite de imóveis atingido." << endl;
        return;
    }

    Imovel novo;

    // Entrada de dados do usuário
    cout << "Digite os dados do novo imóvel:" << endl;
    cout << "Tipo: ";
    cin >> novo.tipo;
    cout << "Finalidade: ";
    cin >> novo.finalidade;
    cout << "Endereço: ";
    cin >> novo.endereco;
    cout << "Bairro: ";
    cin >> novo.bairro;
    cout << "Cidade: ";
    cin >> novo.cidade;
    cout << "Área (em m^2): ";
    cin >> novo.area;
    cout << "Valor (RS): ";
    cin >> novo.valor;
    cout << "IPTU (RS): ";
    cin >> novo.iptu;
    cout << "Quartos: ";
    cin >> novo.quartos;
    cout << "Suítes: ";
    cin >> novo.suites;
    cout << "Banheiros: ";
    cin >> novo.banheiros;
    cout << "Vagas: ";
    cin >> novo.vagas;
    cout << "Cozinha (sim/nao): ";
    cin >> novo.cozinha;
    cout << "Sala (sim/nao): ";
    cin >> novo.sala;
    cout << "Varanda (sim/nao): ";
    cin >> novo.varanda;
    cout << "Área de serviço (sim/nao): ";
    cin >> novo.areaServico;
    cout << "Piso: ";
    cin >> novo.piso;
    cout << "Conservação: ";
    cin >> novo.conservacao;
    cout << "Armários (sim/nao): ";
    cin >> novo.armarios;
    cout << "Ar condicionado (sim/nao): ";
    cin >> novo.arCondicionado;
    cout << "Aquecedor (sim/nao): ";
    cin >> novo.aquecedor;
    cout << "Ventilador (sim/nao): ";
    cin >> novo.ventilador;

    // Adiciona ao vetor
    imobiliaria.imoveis[imobiliaria.espacoUsado] = novo;
    imobiliaria.espacoUsado++;

    salvar(imobiliaria); // salva no arquivo
    cout << BOLD RED"\nImóvel adicionado com sucesso!" RESET << endl;
}

void buscaCaracteristica(Imobiliaria &imobiliaria) {
    string armarios, ar, aquecedor, ventilador;
    bool isValida = false;

    while (!isValida) {
        isValida = true;
        cout << "buscar um imovel por caracteristicas" << endl;
        //pergunta ao usuario as caracteristicas que ele quer no seu imovel e caso algo, se nao, sim ou nao for digitado, informa ao usuario
        cout << "digite se voce quer que tenha armarios (sim/nao):" << endl;
        cin >> armarios;

        if (armarios != "sim" && armarios != "nao") {
            cout << "valor digitado invalido" << endl;
            isValida = false;
        }
        cout << "digite se voce quer que tenha ar condicionado (sim/nao):" << endl;
        cin >> ar;
        if (ar != "sim" && ar != "nao") {
            cout << "valor digitado invalido" << endl;
            isValida = false;
        }
        cout << "digite se voce quer que tenha aquecedor (sim/nao):" << endl;
        cin >> aquecedor;
        if (aquecedor != "sim" && aquecedor != "nao") {
            cout << "valor digitado invalido" << endl;
            isValida = false;
        }

        cout << "digite se voce quer que tenha ventilador (sim/nao):" << endl;
        cin >> ventilador;
        if (ventilador != "sim" && ventilador != "nao") {
            cout << "valor digitado invalido" << endl;
            isValida = false;
        }

    }
    //percorre o vetor pelas especificacoes dadas anteriormente e mostra as opcoes de imoveis que ele pode escolher
    cout << "imoveis encontrados com as caracteristicas desejadas:" << endl;
    decorate(2);
    bool achou = false;
    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        if ((imobiliaria.imoveis[i].armarios == armarios)&&
                (imobiliaria.imoveis[i].arCondicionado == ar)&&
                (imobiliaria.imoveis[i].aquecedor == aquecedor)&&
                (imobiliaria.imoveis[i].ventilador == ventilador)) {
            imprimeImovel(imobiliaria.imoveis[i]);
            achou = true;
        }
    }
    if (!achou) {
        cout << "Nenhuma Correspondencia" << endl;
    }
}

void buscaRua(Imobiliaria &imobiliaria) {//passagem por referencia caso o endereco for deletado
    string rua;
    int indices[SIZE];
    int opcoes = 0;
    cout << "digite o nome da rua: " << endl;
    cin >> rua;
    bool achou = false;

    // Mostra todos os imóveis encontrados na rua escolhida e guarda os índices
    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        if (imobiliaria.imoveis[i].endereco == rua) {
            cout << "Opção [" << (opcoes + 1) << "]:" << endl;
            imprimeImovel(imobiliaria.imoveis[i]);
            indices[opcoes] = i;
            opcoes++;
            achou = true;
        }
    }
    if (!achou) {
        cout << "nenhum imovel encontrado na rua " << rua << endl;
    }
    // se encontrar imoveis na rua, pergunta se o usuario quer excluir algum dos imoveis, ou o imovel especifico
    cout << "deseja excluir algum imovel? (1 - sim, 0 - nao): ";
    int excluir;
    cin >> excluir;//verifica se o valor digitado e valido
        if (excluir != 1 && excluir != 0) {
            cout << "valor digitado invalido, tente novamente" << endl;

        }
        if (excluir != 1) {
            cout << "nenhum imovel foi excluido" << endl;

        }
    if (excluir == 1) {
 
        cout<<"OPCOES: ";
        for(int i = 0; i<opcoes; i++){
            cout<<"["<< i+1 <<"]";
        }
        
        cout << "\nDigite o número da opção que deseja excluir (-1 para cancelar): ";
        int escolha;
        cin >> escolha;
        // verifica se a escolha é valida

        bool excluiu = false;
        if (escolha >= 0 && escolha <= opcoes) {
            deletar(indices[escolha - 1], imobiliaria);
            excluiu = true;
        }

        if (!excluiu) {
            cout << "Nenhum imovel foi excluido." << endl;
        }
    }else {
          cout << "nenhum imovel foi excluido" << endl;
    }

}

void buscaTipo(Imobiliaria &imobiliaria) {
    int max, min;
    bool isValido = false;

    while (!isValido) {

        cout << "digite o valor maximo " << endl;
        cin >> max;

        cout << "digite o valor minimo" << endl;
        cin >> min;

        if (max <= 0 || min <= 0) {
            cout << "valor digitado invalido, tente novamente" << endl;
            isValido = false;
        } else {
            isValido = true;
        }
    }
    if (min > max) {
        int aux = min;
        min = max;
        max = aux;
    }

    //mostra todos os imoveis dentro da faixa de preco definida menos os que sao para venda
    cout << "imoveis encontrados na faixa: " << min << "-" << max << endl;
    decorate(2);
    bool achou = false;
    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        if (imobiliaria.imoveis[i].valor >= min && imobiliaria.imoveis[i].valor <= max && imobiliaria.imoveis[i].finalidade != "venda") {
            imprimeImovel(imobiliaria.imoveis[i]);
            achou = true;
        }

    }
    if (!achou) {
        cout << "Nenhuma ocorrencia" << endl;

    }
}

void buscaQuarto(Imobiliaria &imobiliaria) {
    int quartos, suites;
    bool isValido = false;
    while (!isValido) {
        cout << "Digite o numero minimo de quartos: ";
        cin >> quartos;

        cout << "Digite o numero minimo de suites: ";
        cin >> suites;

        if (quartos <= 0 || suites < 0) {
            cout << "valor digitado invalido" << endl;
            isValido = false;
        } else {
            isValido = true;
        }

    }

    //percorre o vetor e mostra os imoveis que possuem o numero definido como minimo de quartos e suites
    cout << "imoveis encontrados com o numero de quartos e suites desejado:" << endl;
    decorate(2);
    bool achou = false;

    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        if (imobiliaria.imoveis[i].quartos == quartos && imobiliaria.imoveis[i].suites == suites) {
            imprimeImovel(imobiliaria.imoveis[i]);
            achou = true;
        }
    }
    if (!achou) {
        cout << "Nenhum imovel encontrado com o numero de quartos e suites desejado." << endl;
    }

}

void mostraBarra(int porcentagem) {
    char barra[50];
    for (int i = 0; i < 50; i++) {
        barra[i] = ' ';
    }
    barra[0] = '|';
    barra[49] = '|';

    porcentagem = porcentagem / 2;
    for (int i = 1; i < porcentagem; i++) {
        barra[i] = ':';
        barra[i + 1] = '.';
    }
    for (int i = 0; i < 50; i++) {
        cout << BOLD BG_BLACK CYAN << barra[i];
    }
    cout << RESET << endl;

}

void relatorio(Imobiliaria &imobiliaria) {
    float total = imobiliaria.espacoUsado;
    float porcentagem;
    int vendaConta = 0, aluguelConta = 0, temporadaConta = 0;
    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        if (imobiliaria.imoveis[i].finalidade == "venda") {
            vendaConta++;
        } else if (imobiliaria.imoveis[i].finalidade == "aluguel") {
            aluguelConta++;
        } else if (imobiliaria.imoveis[i].finalidade == "temporada") {
            temporadaConta++;
        }
    }
    if (total > 0) {

        porcentagem = (float) ((vendaConta / total)*100);
        cout << "porcentagem de imoveis para venda: " << porcentagem << "%" << endl;
        mostraBarra((int) porcentagem);
        decorate(3);
        porcentagem = (float) ((aluguelConta / total)*100);
        cout << "porcentagem de imoveis para aluguel: " << porcentagem << "%" << endl;
        mostraBarra((int) porcentagem);
        decorate(3);
        porcentagem = (float) ((temporadaConta / total)*100);
        cout << "porcentagem de imoveis para temporada: " << porcentagem << "%" << endl;
        mostraBarra((int) porcentagem);
        decorate(3);
    }

    int casasSuites = 0;
    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        if (imobiliaria.imoveis[i].suites > 0) {
            casasSuites++;
        }
    }
    porcentagem = (float) ((casasSuites / total)*100);
    cout << "porcentagem de casas com suites: " << porcentagem << "%" << endl;
    mostraBarra((int) porcentagem);
    decorate(3);

    int pisosCeramica = 0;
    for (int i = 0; i < imobiliaria.espacoUsado; i++) {
        if (imobiliaria.imoveis[i].piso == "cerâmica" || imobiliaria.imoveis[i].piso == "ceramica" && imobiliaria.imoveis[i].finalidade == "comercial") {
            pisosCeramica++;
        }
    }
    porcentagem = (float) ((pisosCeramica / total) * 100);
    cout << "porcentagem de pisos com ceramica nas salas comerciais: " << porcentagem << "%" << endl;
    mostraBarra(porcentagem);
    decorate(1);
}

void imprimeMenu() {
    decorate(1);
    cout << BOLD << "\t\t\t===MENU===" << RESET;
    decorate(2);
    cout << "|0- sair\t\t\t\t\t\t|" << endl;
    cout << RED << "|1- adicionar um novo imovel na base de dados\t\t|" << RESET << endl;
    cout << BRED << "|2- buscar um imovel por rua \t\t\t\t|" << RESET << endl;
    cout << YELLOW << "|3- buscar um imovel pelo valor \t\t\t|" << RESET << endl;
    cout << GREEN << "|4- buscar um imovel pelas suas caracteristicas\t\t|" << RESET << endl;
    cout << BLUE << "|5- buscar um imovel pelo numero de quartos e suites\t|" << RESET << endl;
    cout << CYAN << "|6- relatorio de estatisticas \t\t\t\t|" << RESET << endl;
    cout << BBLUE << "|7- listagem de todos os imoveis \t\t\t|" << RESET << endl;
    cout << MAGENTA << "|8- deletar imovel(posicao) \t\t\t\t|";
    decorate(1);
}

int main() {
    Imovel imovel;

    int choice;
    bool isRunning = true;
    Imobiliaria imobiliaria;
    for (int i = 0; i < SIZE; i++) {
        imobiliaria.imoveis[i].finalidade = " ";
        imobiliaria.imoveis[i].endereco = " ";
        imobiliaria.imoveis[i].bairro = " ";
        imobiliaria.imoveis[i].cidade = " ";
        imobiliaria.imoveis[i].area = 0;
        imobiliaria.imoveis[i].valor = 0;
        imobiliaria.imoveis[i].iptu = 0;
        imobiliaria.imoveis[i].quartos = 0;
        imobiliaria.imoveis[i].suites = 0;
        imobiliaria.imoveis[i].banheiros = 0;
        imobiliaria.imoveis[i].vagas = 0;
        imobiliaria.imoveis[i].cozinha = " ";
        imobiliaria.imoveis[i].sala = " ";
        imobiliaria.imoveis[i].varanda = " ";
        imobiliaria.imoveis[i].areaServico = " ";
        imobiliaria.imoveis[i].piso = " ";
        imobiliaria.imoveis[i].conservacao = " ";
        imobiliaria.imoveis[i].armarios = " ";
        imobiliaria.imoveis[i].arCondicionado = " ";
        imobiliaria.imoveis[i].aquecedor = " ";
        imobiliaria.imoveis[i].ventilador = " ";
    }
    abreArquivo(imobiliaria);


    while (isRunning) {
        imprimeMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << BOLD RED "\t\t==ADICIONAR NOVO IMOVEL==" RESET;
                decorate(2);
                adicionar(imobiliaria);

                break;
            case 2:
                cout << BOLD BRED "\t\t ==BUSCA POR RUA==" RESET;
                decorate(2);

                buscaRua(imobiliaria);

                break;

            case 3:
                cout << BOLD YELLOW "\t\t==BUSCAR POR VALOR==" RESET;
                decorate(2);

                buscaTipo(imobiliaria);

                break;

            case 4:
                cout << BOLD GREEN "\t\t==BUSCAR POR CARACTERISTICA==" RESET;
                decorate(2);

                buscaCaracteristica(imobiliaria);
                break;

            case 5:
                cout << BOLD BLUE "\t\t==BUSCAR POR QUARTOS==" RESET;
                decorate(2);

                buscaQuarto(imobiliaria);

                break;

            case 6:
                decorate(1);
                cout << BOLD CYAN "\t\t==RELATORIO==" RESET;
                decorate(2);
                relatorio(imobiliaria);
                break;
            case 7:
                cout << BOLD BBLUE "\t\t==LISTAGEM==" RESET;
                decorate(2);
                imprimeImobiliaria(imobiliaria);
                break;
            case 8:
                cout << BOLD MAGENTA "\t\t==DELETAR IMOVEL==" RESET;
                decorate(2);
                int pos;
                cout << "Informe a posicao do imovel a ser deletado" << endl;
                cin>>pos;
                deletar(pos, imobiliaria);
                break;
            default:
                cout << "encerrando programa ..." << endl;
                isRunning = false;
                break;
        }
    }

    return 0;
}