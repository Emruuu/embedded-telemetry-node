#include <iostream>
#include "embedded/ring_buffer.hpp"

int main()
{
    RingBuffer<int, 3> buffer;

    // Test 1: nowy bufor powinien być pusty
    std::cout << "Empty: " << buffer.empty() << '\n';

    // Test 2: dodawanie elementow
    buffer.push(10);
    buffer.push(20);
    buffer.push(30);

    std::cout << "Full: " << buffer.full() << '\n';
    std::cout << "Size: " << buffer.size() << '\n';

    // Test 3: pobieranie elementu
    int value = 0;

    if (buffer.pop(value))
        std::cout << "Popped: " << value << '\n';

    std::cout << "Size after pop: " << buffer.size() << '\n';

    return 0;
}
