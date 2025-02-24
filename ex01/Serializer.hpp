#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data {
    int value;
    std::string text;
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serializer(); // Constructor privado para evitar instanciación
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
};

#endif
