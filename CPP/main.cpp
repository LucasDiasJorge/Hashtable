#include "hashtable.h"

int main() {

    if (find("Lucas")) {
        std::cout << "Lucas was found" << std::endl;
    }else {
        std::cout << "Lucas wasn't found" << std::endl;
    }

    if (insert("Lucas", 22)) {
        std::cout << "Lucas was insterted" << std::endl;
    } else {
        std::cout << "Lucas wasn't inserted" << std::endl;
    }

    if (find("Lucas")) {
        std::cout << "Lucas was found" << std::endl;
    }else {
        std::cout << "Lucas wasn't found" << std::endl;
    }

    if (hash_table_delete("Lucas")) {
        std::cout << "Lucas was deleted" << std::endl;
    }else {
        std::cout << "Lucas wasn't deleted" << std::endl;
    }

    if (find("Lucas")) {
        std::cout << "Lucas was found" << std::endl;
    }else {
        std::cout << "Lucas wasn't found" << std::endl;
    }

    if (insert("Lucas", 22)) {
        std::cout << "Lucas was insterted" << std::endl;
    } else {
        std::cout << "Lucas wasn't inserted" << std::endl;
    }

    if (find("Lucas")) {
        std::cout << "Lucas was found" << std::endl;
    }else {
        std::cout << "Lucas wasn't found" << std::endl;
    }

    print_table();

    reset_hashtable();

    print_table();

    return 0;
}
