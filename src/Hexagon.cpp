#include "../include/Hexagon.h"
#include <cmath>

Hexagon::Hexagon() {
    points = {
        new Point{1.0, 0.0},
        new Point{0.5, 0.866},
        new Point{-0.5, 0.866},
        new Point{-1.0, 0.0},
        new Point{-0.5, -0.866},
        new Point{0.5, -0.866}
    };
}

Hexagon::Hexagon(const Hexagon& other) {
    for(const Point* a : other.points){
        points.push_back(new Point(*a));
    }
}

Hexagon::Hexagon(Hexagon&& other) noexcept {
    points = std::move(other.points);
    other.points.clear();
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
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

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
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

Hexagon::~Hexagon() {
    for(Point* a : points){
        delete a;
    }
    points.clear();
}

void Hexagon::read(std::istream& is) {
    for(Point* a : points){
        delete a;
    }
    points.clear();
    
    Point p1, p2, p3, p4, p5, p6;
    std::cout << "Enter 6 points of Hexagon:" << std::endl;
    std::cout << "Point 1: ";
    is >> p1.x >> p1.y;
    std::cout << "Point 2: ";
    is >> p2.x >> p2.y;
    std::cout << "Point 3: ";
    is >> p3.x >> p3.y;
    std::cout << "Point 4: ";
    is >> p4.x >> p4.y;
    std::cout << "Point 5: ";
    is >> p5.x >> p5.y;
    std::cout << "Point 6: ";
    is >> p6.x >> p6.y;
    
    points = {new Point{p1}, new Point{p2}, new Point{p3}, new Point{p4}, new Point{p5}, new Point{p6}};
}

bool Hexagon::equal(const Figure& other) const {
    const Hexagon* rhs = dynamic_cast<const Hexagon*>(&other);
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
    return point_cnt == 6;
}

Hexagon::operator double() const {
    double area = 0.0;
    for (size_t i = 0; i < points.size(); i++) {
        size_t next_i = (i + 1) % points.size();
        area += points[i]->x * points[next_i]->y - points[next_i]->x * points[i]->y;
    }
    return std::abs(area) / 2.0;
}