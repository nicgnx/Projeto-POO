#ifndef CARGO_H
#define CARGO_H
#include <string>

class Cargo {
private:
    std::string cargo;

public:
    Cargo(std::string cargo);
    Cargo();
    ~Cargo();
    std::string getCargo();
    void setCargo(std::string cargo);
};

#endif // CARGO_H