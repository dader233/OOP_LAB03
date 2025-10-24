// Pentagon.cpp
#include "../include/Pentagon.h"
#include <cmath>

Pentagon::Pentagon() {
    points = {
        new Point{0.0, 2.0},
        new Point{1.5, 1.0}, 
        new Point{1.0, -1.0},
        new Point{-1.0, -1.0},
        new Point{-1.5, 1.0}
    };
}   

Pentagon::Pentagon(const Pentagon& other) {
    for(const Point* a : other.points){
        points.push_back(new Point(*a));
    }
}

Pentagon::Pentagon(Pentagon&& other) noexcept {
    points = std::move(other.points);
    other.points.clear();
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other){
        for(Point* a : points){
            delete a;
        }
        points.clear();
        for(const Point* a : other.points){
            points.push_back(new Point{*a});
        }
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other){
        for (Point *a : points){
            delete a;
        }
        points.clear();
        points = std::move(other.points);
        other.points.clear();
    }
    return *this;
}

Pentagon::~Pentagon() {
    for(Point* a : points){
        delete a;
    }
    points.clear();
}

void Pentagon::read(std::istream& is) {
    for(Point* a : points){
        delete a;
    }
    points.clear();
    
    Point p1, p2, p3, p4, p5;
    std::cout << "Enter 5 points of Pentagon:" << std::endl;
    std::cout << "Point 1: X_POS Y_POS: ";
    is >> p1.x >> p1.y;
    std::cout << "Point 2: X_POS Y_POS: ";
    is >> p2.x >> p2.y;
    std::cout << "Point 3: X_POS Y_POS: ";
    is >> p3.x >> p3.y;
    std::cout << "Point 4: X_POS Y_POS: ";
    is >> p4.x >> p4.y;
    std::cout << "Point 5: X_POS Y_POS: ";
    is >> p5.x >> p5.y;
    
    points = {new Point{p1}, new Point{p2}, new Point{p3}, new Point{p4}, new Point{p5}};
}

bool Pentagon::equal(const Figure& other) const {
    const Pentagon* rhs = dynamic_cast<const Pentagon*>(&other);
    if (!rhs || points.size() != rhs->points.size()){
        return false;
    }
    size_t point_cnt = 0;
    for (size_t i = 0; i < points.size(); i++) {
        for(size_t j = 0; j < rhs->points.size(); j++){
            if(*points[i] == *rhs->points[j]){
                ++point_cnt;
                break;
            }
        }
    }
    return point_cnt == 5;
}

Pentagon::operator double() const {
    double area = 0.0;
    for (size_t i = 0; i < points.size(); i++) {
        size_t next_i = (i + 1) % points.size();
        area += points[i]->x * points[next_i]->y - points[next_i]->x * points[i]->y;
    }
    return std::abs(area) / 2.0;
}