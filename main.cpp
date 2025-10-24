#include <iostream>
#include "include/Figure.h"
#include "include/Rhombus.h"
#include "include/Pentagon.h"
#include "include/Hexagon.h"

double calculate_total_area(Figure* figures[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += (double)*figures[i];
    }
    return total;
}

void remove_figure(Figure* figures[], int* count, int index) {
    if (index < 0 || index >= *count) return;
    
    for (int i = index; i < *count - 1; i++) {
        figures[i] = figures[i + 1];
    }
    (*count)--;
}

int main() {
    Rhombus rhomb1, rhomb2;
    Pentagon pent1, pent2; 
    Hexagon hex1, hex2;

    std::cout << "=== Enter first set of figures ===\n";
    
    std::cout << "Rhombus 1 - enter 4 points (x y x y x y x y): ";
    std::cin >> rhomb1;
    
    std::cout << "Pentagon 1 - enter 5 points: ";
    std::cin >> pent1;
    
    std::cout << "Hexagon 1 - enter 6 points: ";
    std::cin >> hex1;

    Figure* shapes[3] = {&rhomb1, &pent1, &hex1};
    int shape_count = 3;

    std::cout << "\n=== First set results ===\n";
    for (int i = 0; i < shape_count; i++) {
        Point c = shapes[i]->center();
        std::cout << "Shape " << i << ":\n";
        std::cout << *shapes[i];
        std::cout << "Center: " << c.x << " " << c.y << "\n";
        std::cout << "Area: " << (double)*shapes[i] << "\n\n";
    }

    std::cout << "Total area: " << calculate_total_area(shapes, shape_count) << "\n";

    remove_figure(shapes, &shape_count, 1);
    std::cout << "\nAfter removing shape 1, count: " << shape_count << "\n";

    std::cout << "\n=== Remaining shapes ===\n";
    for (int i = 0; i < shape_count; i++) {
        Point c = shapes[i]->center();
        std::cout << "Shape " << i << ":\n";
        std::cout << *shapes[i];
        std::cout << "Center: " << c.x << " " << c.y << "\n";
        std::cout << "Area: " << (double)*shapes[i] << "\n\n";
    }

    std::cout << "Total area now: " << calculate_total_area(shapes, shape_count) << "\n";

    std::cout << "\n=== Enter second set for comparison ===\n";
    std::cout << "Rhombus 2: ";
    std::cin >> rhomb2;
    std::cout << "Pentagon 2: ";
    std::cin >> pent2;
    std::cout << "Hexagon 2: ";
    std::cin >> hex2;

    std::cout << "\n=== Comparison results ===\n";
    std::cout << "Rhombus 1 == Rhombus 2: " << (rhomb1 == rhomb2) << "\n";
    std::cout << "Pentagon 1 == Pentagon 2: " << (pent1 == pent2) << "\n"; 
    std::cout << "Hexagon 1 == Hexagon 2: " << (hex1 == hex2) << "\n";

    std::cout << "\n=== Testing copy operations ===\n";
    Rhombus rhomb_copy(rhomb1);
    std::cout << "Copied rhombus area: " << (double)rhomb_copy << "\n";
    
    Pentagon pent_move(std::move(pent1));
    std::cout << "Moved pentagon area: " << (double)pent_move << "\n";

    return 0;
}