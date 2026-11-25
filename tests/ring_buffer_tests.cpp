#include <cassert>
#include "embedded/ring_buffer.hpp"

int main()
{
    RingBuffer<int, 3> buffer;

    // Test 1: pusty bufor
    assert(buffer.empty());
    assert(!buffer.full());
    assert(buffer.size() == 0);

    // Test 2: dodawanie
    assert(buffer.push(10));
    assert(buffer.push(20));
    assert(buffer.push(30));

    assert(buffer.full());
    assert(buffer.size() == 3);

    // Test 3: brak miejsca
    assert(!buffer.push(40));

    // Test 4: pobieranie
    int value = 0;

    assert(buffer.pop(value));
    assert(value == 10);

    assert(buffer.pop(value));
    assert(value == 20);

    // Test 5: zawijanie indeksu tail
    assert(buffer.push(40));
    assert(buffer.push(50));

    assert(buffer.full());
    assert(buffer.size() == 3);

    // Kolejność FIFO musi być zachowana po zawinięciu.
    assert(buffer.pop(value));
    assert(value == 30);

    assert(buffer.pop(value));
    assert(value == 40);

    assert(buffer.pop(value));
    assert(value == 50);

    // Test 6: bufor znów jest pusty
    assert(buffer.empty());
    assert(buffer.size() == 0);

    return 0;
}