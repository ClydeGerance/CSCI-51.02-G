#include <iostream>

int multiply(int x, int y) {
    int result = 0;
    
    while (y) {
        if (y & 1)  // If y is odd, add x to result
            result += x;
        
        x <<= 1;  // Double x (shift left)
        y >>= 1;  // Halve y (shift right)
    }
    
    return result;
}

int main() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::cout << a << " * " << b << " = " << multiply(a, b) << std::endl;
    return 0;
}
