#include "functies.hpp"
#include <pybind11/pybind11.h>
#include <iostream>
#include <string>
#include <cmath>
#include <numbers>

namespace py = pybind11;

// Title: square_root
void square_root(double root){
    double real_root;
    real_root = std::sqrt(root);
    std::cout << "Square root: " << real_root << "\n";
}

// Title: is_prime
void is_prime(int prime){
    if (prime <= 1){
        std::cout << "No prime number\n";
        return;
    }
    for (int i = 2; i <= std::sqrt(prime); i++){
        if (prime % i == 0) {
            std::cout << "It is not a prime number\n";
            return;
        }
    }
    std::cout << "It is a prime number\n";
}

// Title: factorial
void factorial(int factorial){
    std::cout << std::tgamma(factorial + 1) << "\n";
}

// Title: circle_area
void circle_area(double radius){
    double ca;
    ca = 3.14159 * radius * radius;
    std::cout << "Circle area: " << ca << "\n";
}

// Title: quadratic_formula
void quadratic_formula(double ax, double bx, double c){
    double d, x1, x2;
    if (ax == 0){
        std::cout << "No possible out come\n";
        return;
    }
    d = bx * bx - 4 * ax * c;
    if (d == 0){
        x1 = ( -bx + std::sqrt(d) ) / (2 * ax);
        x2 = ( -bx - std::sqrt(d) ) / (2 * ax);
        std::cout << "X1: " << x1 << "\n" << "X2: " << x2 << "\n";
    }

    else if (d > 0){
        x1 = ( -bx + std::sqrt(d) ) / (2 * ax);
        x2 = ( -bx - std::sqrt(d) ) / (2 * ax);
        std::cout << "X1: " << x1 << "\n" << "X2: " << x2 << "\n";
    }
    else if (d < 0){
        std::cout << "No possible out come\n";
    }
}

void circle_circumference(double radius){
    // Calculates circumference from radius and prints it.
    double pi1 = 3.14159265359;
    double cece = 2 * pi1 * radius;
    std::cout << cece << "\n";
}

void triangle_area(double a, double b, double c){
    // Heron's formula for triangle area (prints result).
    double s = (a + b + c) / 2;
    double area = std::sqrt((s * (s - a) * (s - b) * (s - c)));
    std::cout << area << "\n";
}

void point_distance(double x1, double x2, double y1, double y2){
    // Euclidean distance between two points (x1,y1) and (x2,y2).
    double d = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    std::cout << d << "\n";
}

void standart_diviation(double p, int n){
    // Standard deviation calculation; prints result.
    double sigma  = std::sqrt((p *(1-p))/ 2);
    std::cout << sigma << "\n";
}


//aanmaak python functies en modules.
// Title: PYBIND11_MODULE
PYBIND11_MODULE(FopMath, m, py::mod_gil_not_used()) {
    m.doc() = "FopMath pybind11 module"; // optional module docstring

    m.def("quadratic_formula", &quadratic_formula, py::arg("ax"), py::arg("bx"), py::arg("c"));
    m.def("Square_root", &square_root, py::arg("root"));
    m.def("is_prime", &is_prime, py::arg("prime"));
    m.def("factorial", &factorial, py::arg("factorial"));
    m.def("circle_area", &circle_area, py::arg("radius"));
    m.def("circle_circumference", &circle_circumference, py::arg("radius"));
    m.def("triangle_area", &triangle_area, py::arg("a"), py::arg("b"), py::arg("c"));
    m.def("point_distance", &point_distance, py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"));
    m.def("standart_diviation", &standart_diviation, py::arg("p"), py::arg("n"));
}
