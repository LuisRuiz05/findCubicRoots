#include <iostream>

void calculateRoots(double a, double b, double c, double d);

int main()
{
    double a, b, c, d;
    
    // Enter the problem data
    std::cout << "Enter 'a' value: "; std::cin >> a;
    std::cout << "Enter 'b' value: "; std::cin >> b;
    std::cout << "Enter 'c' value: "; std::cin >> c;
    std::cout << "Enter 'd' value: "; std::cin >> d;

    // Call function
    calculateRoots(a, b, c, d);
}

void calculateRoots(double a, double b, double c, double d) {
    double discriminant, q, r, theta, s, t;

    // In case we've got 0 roots.
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        std::cout << "{}";
        return;
    }

    // Calculating the discriminant term
    q = (3 * a * c - b * b) / (9 * a * a);
    r = (9 * a * b * c - 27 * a * a * d - 2 * b * b * b) / (54 * a * a * a);
    discriminant = q * q * q + r * r;

    if (discriminant > 0) {
        // Case 1: Three different real roots
        s = cbrt(r + sqrt(discriminant));
        t = cbrt(r - sqrt(discriminant));

        double x1 = s + t - b / (3 * a);
        std::cout << "Found roots: {" << x1 << "}" << std::endl;
    }
    else if (discriminant == 0) {
        // Caso 2: Two equal real root and a different real root
        double x1 = 2 * cbrt(r) - b / (3 * a);
        double x2 = - cbrt(r) - b / (3 * a);

        std::cout << "Found roots: {" << x1 << ", " << x2 << "}" << std::endl;
    }
    else {
        // Case 3: One real root and two complex conjugate roots
        double pi = 3.14159265358979323846; // Pi's approximation
        theta = acos(r / sqrt(-q * q * q));
        double x1 = 2 * sqrt(-q) * cos(theta / 3) - b / (3 * a);
        double x2 = 2 * sqrt(-q) * cos((theta + 2 * pi) / 3) - b / (3 * a);
        double x3 = 2 * sqrt(-q) * cos((theta + 4 * pi) / 3) - b / (3 * a);

        std::cout << "Found roots: {" << x1 << ", " << x2 << ", " << x3 << "}" << std::endl;
    }
}