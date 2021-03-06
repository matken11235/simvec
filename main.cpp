// clang++ -std=c++17 -Wall -O0 -g -fsanitize=address -mavx512f main.cpp
// sde -skx -- ./a.out
#include "include/simvec.hpp"

int main() {
    static constexpr std::size_t VECSIZE = 256;
    simvec::Simvec<float, VECSIZE> a{};
    simvec::Simvec<float, VECSIZE> b{};
    simvec::Simvec<float, VECSIZE> c{};
    a[0] = b[0] = c[0] = 1.23f;
    for (std::size_t i = 1; i < VECSIZE; ++i) {
        a[i] = b[i] = c[i] = 0.0f;
    }

    simvec::Simvec<float, VECSIZE> sum{};
    sum = a + b + c;
    for (const auto& s : sum) {
        std::cout << s << ", ";
    }
    std::cout << std::endl << std::endl;

    simvec::Simvec<float, VECSIZE> diff{};
    diff = a - sum - sum;
    for (const auto& d : diff) {
        std::cout << d << ", ";
    }
    std::cout << std::endl << std::endl;

    simvec::Simvec<float, VECSIZE> res{};
    res = a * b - c;
    for (const auto& r : res) {
        std::cout << r << ", ";
    }
    std::cout << std::endl << std::endl;

    simvec::Simvec<float, VECSIZE> prod{};
    prod[0] = 2.0f;
    for (std::size_t i = 1; i < VECSIZE; ++i) {
        prod[i] = 1.0f;
    }
    std::cout << inner_product(prod, diff) << std::endl;

    return 0;
}
