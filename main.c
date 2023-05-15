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

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name,MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    // Table is empty
}

void print_table(){
    printf("START\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        }else if(hash_table[i] == DELETED_NODE){
            printf("\t%i\t---<DELETED>\n",i);
        }else{ 
            printf("\t%i\t%s\n",i,hash_table[i]->name);
        }
    }
    printf("END\n");
}

bool hash_table_insert(person *p){
    if (p ==NULL) return false;
    int index = hash(p->name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL || hash_table[try] == DELETED_NODE){
            hash_table[try] = p;
            return true;
        }
    }
    return false;

}

person *hash_table_delete(char *name){
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL) return NULL;
        if(hash_table[try] == DELETED_NODE) continue;;
        if(hash_table[try] != NULL && strncmp(hash_table[try]->name, name,TABLE_SIZE) == 0){
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }else{
            return NULL;
        }    
    }
    
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return false;
        }
        if(hash_table[try] == DELETED_NODE){
            continue;
        }
        if(hash_table[try] != NULL && strncmp(hash_table[try]->name, name,TABLE_SIZE) == 0){
            return hash_table[try];
        }else{
            return NULL;
        }
    }
    
}

int main(){
 
    init_hash_table();
    print_table();

    person lucas = {.name="Lucas",.age=256};
    person luisa = {.name="Luisa",.age=18};
    person nazira = {.name="Nazira",.age=32};
    person ron = {.name="ron",.age=4};

    hash_table_insert(&lucas);
    hash_table_insert(&luisa);
    hash_table_insert(&nazira);
    hash_table_insert(&ron);

    print_table();

    person *tmp = hash_table_lookup("Lucas");

    if (tmp == NULL){
         printf("NOT FOUND\n");
    }else{
        printf("FOUND %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("Nadir");

    if (tmp == NULL){
         printf("NOT FOUND\n");
    }else{
        printf("FOUND %s.\n", tmp->name);
    }

    hash_table_delete("Luisa");

    print_table();

    return 0;
}