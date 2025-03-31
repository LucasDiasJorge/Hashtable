#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstring>

#include "Person.h"

#define TABLE_SIZE 10000
#define DELETED_NODE ((Person*) (0xFFFFFFFFFFFFFFFFUL))

void reset_hashtable();

// Função de hash (djb2)
unsigned int hash(const std::string &person_name);

bool insert(const std::string& name, int age);

bool find(const std::string& name);

void print_table();

bool hash_table_delete(const std::string& name);

#endif //HASHTABLE_H
