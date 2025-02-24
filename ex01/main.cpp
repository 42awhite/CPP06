#include "Serializer.hpp"

int main() {
    Data data = {42, "Hello, Serialization!"};

    // Serialización
    uintptr_t raw = Serializer::serialize(&data);

    // Deserialización
    Data* newPtr = Serializer::deserialize(raw);

    // Verificación
    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Deserialized pointer: " << newPtr << std::endl;
    std::cout << "Value: " << newPtr->value << ", Text: " << newPtr->text << std::endl;

    return 0;
}



