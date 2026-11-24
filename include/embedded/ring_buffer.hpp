#include <array>
#include <cstddef>

template<typename T, std::size_t Capacity>
class RingBuffer
{
    static_assert(Capacity > 0, "RingBuffer capacity must be greater than zero"); // sprawdzanie podczas kompilacji
    private:
        std::array<T, Capacity> buffer{};

        std::size_t head = 0;
        std::size_t tail = 0;
        std::size_t count = 0;

    public:
        bool push(const T& value); // dodaje element
        bool pop(T& value); // sprawdzamy czy zmienna jest i zwracamy przez value
        bool empty() const; // sprawdza, czy bufor jest pusty
        bool full() const; // sprawdza, czy bufor jest pełny
        std::size_t size() const; // zwraca aktualną liczbę elementów
};
template<typename T, std::size_t Capacity>
bool RingBuffer<T, Capacity>::push(const T& value)
{
    if (!full()){
        buffer[tail] = value;
        tail = (tail + 1) % Capacity;
        count++;
        return true;
    }
    return false;
}
template<typename T, std::size_t Capacity>
bool RingBuffer<T, Capacity>::full() const{
    return count==Capacity;
}
template<typename T, std::size_t Capacity>
bool RingBuffer<T, Capacity>::empty() const{
    return count==0;
}
template<typename T, std::size_t Capacity>
std::size_t RingBuffer<T, Capacity>::size() const{
    return count;
}
template<typename T, std::size_t Capacity>
bool RingBuffer<T, Capacity>::pop(T& value){
    if(!empty()){
        value = buffer[head];
        head = (head + 1) % Capacity;
        count--;
        return true;
    }
    return false;
}