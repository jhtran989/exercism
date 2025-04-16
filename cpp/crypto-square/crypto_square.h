#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <locale>
#include <iostream>
#include <stdexcept>

namespace crypto_square {

// TODO: add your solution here
class cipher {
private:
    std::string input{};
public:
    cipher(std::string input) : input(input) {}

    std::string normalized_cipher_text() {
        std::string normalizedInput{input};

        // FIXME
        std::cout << normalizedInput << std::endl;

        normalizedInput.erase(std::remove_if(normalizedInput.begin(), normalizedInput.end(), 
        [](const char c){
            return !std::isalnum(c);
        }), normalizedInput.end());

        // FIXME
        std::cout << normalizedInput << std::endl;

        std::transform(normalizedInput.begin(), normalizedInput.end(), normalizedInput.begin(),
        [](char c)
        {
            return std::tolower(c);
        });

        // FIXME
        std::cout << normalizedInput << std::endl;

        // TODO: keep only characters
        // normalizedInput.erase(std::remove(normalizedInput.begin(), normalizedInput.end(), ' '), normalizedInput.end());
        // normalizedInput.erase(std::remove(normalizedInput.begin(), normalizedInput.end(), '.'), normalizedInput.end());
        // normalizedInput.erase(std::remove(normalizedInput.begin(), normalizedInput.end(), '-'), normalizedInput.end());

        int normalizedSize = normalizedInput.length();
        int normalizedSqrt = std::ceil(std::sqrt(normalizedSize));

        // FIXME:
        std::cout << "initial sqrt: " << normalizedSqrt << std::endl;
        std::cout << "size: " << normalizedSize << std::endl;

        int r;
        int c;

        std::string result{};
        if (normalizedSqrt * normalizedSqrt >= normalizedSize) {
            if (normalizedSqrt * (normalizedSqrt - 1) >= normalizedSize) {
                r = normalizedSqrt - 1;
                c = normalizedSqrt;
            } else {
                r = normalizedSqrt;
                c = normalizedSqrt;
            }
        } else {
            throw std::domain_error("r and c values...");
        }

        // FIXME:
        std::cout << "r: " << r << std::endl;
        std::cout << "c: " << c << std::endl;

        int delta = r * c - normalizedSize;

        // FIXME:
        std::cout << "delta: " << delta << std::endl;

        normalizedInput += std::string(delta, ' ');
        normalizedSize += delta;

        // FIXME
        std::cout << normalizedInput << std::endl;

        for (int i = 0; i < c; i++) {
            // result += normalizedInput[i];
            for (int j = 0; j < normalizedSize - i; j += c) {
                result += normalizedInput[i + j];
                
                // FIXME:
                std::cout << i + j * c << std::endl;
            }

            if (i < c - 1) {
                result += " ";
            }
        }

        // FIXME:
        std::cout << "|" << result << "|" << std::endl;
        // |imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau |
        // |imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau |
        // |imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau |
        // |imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau |

        return result;
    }
};

}  // namespace crypto_square

#endif  // CRYPTO_SQUARE_H