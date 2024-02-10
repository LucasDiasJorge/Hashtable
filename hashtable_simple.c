#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE ((person*) (0xFFFFFFFFFFFFFFFFUL))

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person* hash_table[TABLE_SIZE];

unsigned int hash(const char* name) {
    unsigned int hash_value = 5381; // Initial value for DJB2
    int c;

    while ((c = *name++)) {
        hash_value = ((hash_value << 5) + hash_value) + c; // DJB2 Hash Function
    }

    return hash_value % TABLE_SIZE;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {
    printf("START\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<DELETED>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("END\n");
}

bool hash_table_insert(person* p) {
    if (p == NULL) return false;

    unsigned int index = hash(p->name);

    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int try = (index + i) % TABLE_SIZE;

        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
            hash_table[try] = p;
            return true;
        }
    }

    return false;
}

person* hash_table_delete(const char* name) {
    unsigned int index = hash(name);

    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int try = (index + i) % TABLE_SIZE;

        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strcmp(hash_table[try]->name, name) == 0) {
            person* tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }

    return NULL;
}

person* hash_table_lookup(const char* name) {
    unsigned int index = hash(name);

    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int try = (index + i) % TABLE_SIZE;

        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strcmp(hash_table[try]->name, name) == 0) return hash_table[try];
    }

    return NULL;
}

int main() {
    init_hash_table();
    print_table();

    person lucas = {.name = "Lucas", .age = 256};
    person luisa = {.name = "Luisa", .age = 18};
    person nazira = {.name = "Nazira", .age = 32};
    person ron = {.name = "Ron", .age = 4};

    hash_table_insert(&lucas);
    hash_table_insert(&luisa);
    hash_table_insert(&nazira);
    hash_table_insert(&ron);

    print_table();

    person* tmp = hash_table_lookup("Lucas");
    if (tmp == NULL) {
        printf("NOT FOUND\n");
    } else {
        printf("FOUND %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("Nadir");
    if (tmp == NULL) {
        printf("NOT FOUND\n");
    } else {
        printf("FOUND %s.\n", tmp->name);
    }

    hash_table_delete("Luisa");

    print_table();

    return 0;
}
