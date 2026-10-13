// Bibliotécas Nativas
#include <fstream>

// Bibliotécas Proprietárias
#include "interface.hpp"
#include "storage.hpp"
#include "jsonl.hpp"

using namespace std;
static uint64_t id = 1;

// Programa Principal
void main(int argc, char** argv){
    if (argc < 2){
        std::cerr << "Comando inexistente.\n";
    }

    string cmd = argv[1];

    if (cmd == "init")
        INIT::execute(argc, argv);

    if (cmd == "run")
        RUN::execute(argc, argv);

    if (cmd == "verify")
        VERIFY::execute(argc, argv);

    if (cmd == "describe")
        DESCRIBE::execute(argc, argv);

    std::cerr << "Comando desconhecido: " << cmd << '\n';
}

// TODO: Implementar leitura do workload JSONL,
// execução de PUT/GET/DELETE e escrita das respostas.
void run(const string& directory,
        const string& workload,
        const string& results){

    ifstream input(workload);
    ofstream output(results);
    jsonl::Json operation;

    //status: Precisa de um controle
    string status = NULL;

    while (jsonl::read(input, operation)){
        string op = operation.at("op").get<string>();

        //REG data = create_reg(); Registra Dados
        //IDX ref = create_idx();  Registra Indexação

        if(op == "put"){
            
        }
            
        if(op == "get"){

        }

        if(op == "del"){

        }
        
        if(op == "scan"){

        }

        jsonl::write(output,{{"id:",id},{"op:",op},{"status:", status}});
        id++;
    }
    std::cerr << "Comando run ainda não implementado." << endl;
}

// Verifica a integridade do armazenamento
void verify(const string& directory){
    // TODO: implementar verificação da estrutura persistente.
    std::cerr << "Comando verify ainda não implementado." << endl;
}

// Exibe informações sobre o merroranismo
void describe(){
    cout << "Storage Engine" << endl;
    cout << "Operacoes: PUT, GET, DELETE e SCAN" << endl;
}