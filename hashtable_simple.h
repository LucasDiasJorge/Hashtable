#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*) (0xFFFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

extern person* hash_table[TABLE_SIZE];

unsigned int hash(char *name);
void init_hash_table();
void print_table();
bool hash_table_insert(person *p);
person* hash_table_delete(char *name);
person* hash_table_lookup(char *name);

#endif
