#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>

void init(const std::string& directory);
void run(const std::string& directory,
        const std::string& workload,
        const std::string& results);

void verify(const std::string& directory);
void describe();

struct INIT{
    static void execute(int argc, char** argv) {
        if (argc != 4 || std::string(argv[2]) != "--data-dir"){
            std::cerr << "Uso: engine init --data-dir <diretorio>\n";
        }

        init(argv[3]);
    }
};

struct RUN{
    static void execute(int argc, char** argv) {
        if (argc != 8 ||
            std::string(argv[2]) != "--data-dir" ||
            std::string(argv[4]) != "--input" ||
            std::string(argv[6]) != "--output"){
            std::cerr << "Uso: engine run --data-dir <diretorio>"
                 << " --input <entrada> --output <saida>\n";
        }

        run(argv[3], argv[5], argv[7]);
    }
};

struct VERIFY{
    static void execute(int argc, char** argv) {
        if (argc != 4 || std::string(argv[2]) != "--data-dir"){
            std::cerr << "Uso: engine verify --data-dir <diretorio>\n";
        }
        verify(argv[3]);
    }
};

struct DESCRIBE{
    static void execute(int argc, char** argv) {
        if (argc != 2){
            std::cerr << "Uso: engine describe\n";
        }
        describe();
    }
};

#endif