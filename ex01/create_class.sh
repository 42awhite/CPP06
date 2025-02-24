#!/bin/bash

# Verifica que se pase un nombre de clase
if [ -z "$1" ]; then
    echo "Usage: $0 ClassName"
    exit 1
fi

CLASS_NAME=$1
HEADER_FILE="${CLASS_NAME}.hpp"
CPP_FILE="${CLASS_NAME}.cpp"

# Crear el archivo de encabezado (.hpp)
cat <<EOL > $HEADER_FILE
#ifndef ${CLASS_NAME^^}_HPP
#define ${CLASS_NAME^^}_HPP

class $CLASS_NAME {
public:
    $CLASS_NAME();
    ~$CLASS_NAME();
    $CLASS_NAME(const $CLASS_NAME &other);
    $CLASS_NAME &operator=(const $CLASS_NAME &other);
};

#endif // ${CLASS_NAME^^}_HPP
EOL

# Crear el archivo fuente (.cpp)
cat <<EOL > $CPP_FILE
#include "$HEADER_FILE"

$CLASS_NAME::$CLASS_NAME() {
    // Constructor
}

$CLASS_NAME::~$CLASS_NAME() {
    // Destructor
}

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &other) {
    // Copy constructor
}

$CLASS_NAME & $CLASS_NAME::operator=(const $CLASS_NAME &other) {
    // Copy assignment operator
    return *this;
}
EOL

echo "Class $CLASS_NAME created with $HEADER_FILE and $CPP_FILE"
