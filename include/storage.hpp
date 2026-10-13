#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <filesystem>

typedef struct IDX{
    uint64_t key = 0;
    uint32_t offset = 0;
} IDX;

typedef struct REG{
    uint64_t key = 0;
    uint64_t size = 0;
    std::string& value;
} REG;

void put(uint64_t key, const std::string& value);
void get(uint64_t key);
void del(uint64_t key);
void scan(uint64_t start, uint64_t end);

REG create_reg();
IDX create_idx();

#endif