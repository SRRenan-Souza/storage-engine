#ifndef JSONL_HPP
#define JSONL_HPP
#pragma once

#include <istream>
#include <ostream>
#include <string>
#include <nlohmann/json.hpp>

namespace jsonl{
    using Json = nlohmann::json;

    inline bool read(std::istream& input, Json& result){
        std::string line;

        while (std::getline(input, line)){
            if (line.find_first_not_of(" \t\r") == std::string::npos){
                continue;
            }

            result = Json::parse(line);
            return true;
        }

        if (input.bad()){
            throw std::ios_base::failure("Falha de leitura do JSONL");
        }
        
        return false;
    }

    inline void write(std::ostream& output, const Json& value) {
        output << value.dump() << '\n';

        if (!output) {
            throw std::ios_base::failure("Falha de escrita do JSONL");
        }
    }
}

#endif jSONL_HPP