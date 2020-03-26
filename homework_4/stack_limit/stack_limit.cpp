#include <iostream>
#include <algorithm>

int main() {
    size_t memory_on_stack = 0;
    std::size_t size = 100 * 1024;
    while(true) {
        char data[size];
        char elt = '1';
        //std::fill(std::begin(data), std::begin(data) + size, elt);
        for (int i = 0; i != size; i++) data[i] = elt;
        char new_elt = data[0] + data[1];
        std::cerr << "New element! " << new_elt << std::endl;
        memory_on_stack += 100;
        std::cerr << "memory added to stack: " << memory_on_stack << " kb" << std::endl;
        size += 100*1024;
    }
}
