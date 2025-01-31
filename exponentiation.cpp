#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Normal Exponentiation (O(n))
long long normalExponentiation(long long base, long long exponent, long long &multiplications) {
    long long result = 1;
    multiplications = 0;
    for (long long i = 0; i < exponent; i++) {
        result *= base;
        multiplications++; // Counting multiplications
    }
    return result;
}

// Binary Exponentiation (O(log n))
long long binaryExponentiation(long long base, long long exponent, long long &multiplications) {
    long long result = 1;
    multiplications = 0;
    while (exponent > 0) {
        if (exponent % 2 == 1) { 
            result *= base;
            multiplications++; 
        }
        base *= base;
        multiplications++; 
        exponent /= 2;
    }
    return result;
}

// Modular Binary Exponentiation (O(log n))
long long modularExponentiation(long long base, long long exponent, long long mod, long long &multiplications) {
    long long result = 1;
    base = base % mod;
    multiplications = 0;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
            multiplications++; 
        }
        base = (base * base) % mod;
        multiplications++; 
        exponent /= 2;
    }
    return result;
}

int main() {
    long long base, exponent, mod, multiplications;
    
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    cout << "Enter modulus (for modular exponentiation, enter a large prime like 1e9+7): ";
    cin >> mod;

    // Normal Exponentiation
    auto start1 = high_resolution_clock::now();
    long long normalResult = normalExponentiation(base, exponent, multiplications);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    cout << "\n🔹 Normal Exponentiation (O(n)) Result: " << normalResult << endl;
    cout << "⏳ Time: " << duration1.count() << " microseconds" << endl;
    cout << "🔢 Multiplications: " << multiplications << endl;

    // Binary Exponentiation
    auto start2 = high_resolution_clock::now();
    long long binaryResult = binaryExponentiation(base, exponent, multiplications);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "\n🔹 Binary Exponentiation (O(log n)) Result: " << binaryResult << endl;
    cout << "⏳ Time: " << duration2.count() << " microseconds" << endl;
    cout << "🔢 Multiplications: " << multiplications << endl;

    // Modular Exponentiation
    auto start3 = high_resolution_clock::now();
    long long modularResult = modularExponentiation(base, exponent, mod, multiplications);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);

    cout << "\n🔹 Modular Exponentiation (O(log n) with mod) Result: " << modularResult << endl;
    cout << "⏳ Time: " << duration3.count() << " microseconds" << endl;
    cout << "🔢 Multiplications: " << multiplications << endl;

    return 0;
}
