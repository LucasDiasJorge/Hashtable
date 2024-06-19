#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

// Estrutura para o nó da Hashtable
typedef struct {
    int key;
    int value;
} HashNode;

// Hashtable
extern HashNode hashtable[TABLE_SIZE];

// Função para salvar a Hashtable em um arquivo
void saveHashtableToFile(const char* filename);

// Função para carregar a Hashtable de um arquivo
void loadHashtableFromFile(const char* filename);

#endif /* HASHTABLE_H */
