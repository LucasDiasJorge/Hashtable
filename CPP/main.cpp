#include <cstring>

#include "Person.h"

#define TABLE_SIZE 10000
#define DELETED_NODE ((Person*) (0xFFFFFFFFFFFFFFFFUL))

Person* hashtable[TABLE_SIZE];

void init_hashtable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

// Função de hash (djb2)
unsigned int hash(const std::string &person_name) {
    unsigned int hash_value = 5381;

    for (const char c : person_name) {
        hash_value = ((hash_value << 5) + hash_value) + c;
    }

    return hash_value % TABLE_SIZE;
}

bool insert(const std::string& name, int age) {

    Person* new_person = new Person(name, age);

    unsigned int index = hash(new_person->name);

    if (hashtable[index] != nullptr && hashtable[index] != DELETED_NODE) {
        std::cout << hashtable[index]->name << std::endl;
        delete new_person;
        return false;
    }

    hashtable[index] = new_person;
    return true;
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashtable[i] == nullptr) {
            printf("\t%i\t---\n", i);
        } else if (hashtable[i] == DELETED_NODE) {
            printf("\t%i\t<DELETED>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hashtable[i]->name.c_str());
        }
    }
    printf("END\n");
}

bool hash_table_delete(const std::string& name) {

    unsigned int index = hash(name);

    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int attempt = (index + i) % TABLE_SIZE;

        if (hashtable[attempt] == nullptr) return true;
        if (hashtable[attempt] == DELETED_NODE) return true;
        if (strcmp(hashtable[attempt]->name.c_str(), name.c_str()) == 0) {
            hashtable[attempt] = DELETED_NODE;
            return true;
        }
    }

    return false;
}

int main() {

    init_hashtable();

    if (insert("Lucas", 22)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    print_table(); // index 7981

    if (hash_table_delete("Lucas")) {
        std::cout << "true" << std::endl;
    }else {
        std::cout << "false" << std::endl;
    }

    print_table();

    if (insert("Lucas", 22)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    print_table();

    return 0;
}
