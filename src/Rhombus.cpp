#include "../include/Rhombus.h"

Rhombus::Rhombus(){
    points = {new Point{0,1}, new Point{1,0}, new Point{0, -1}, new Point(-1, 0)};
}

Rhombus::Rhombus(const Rhombus& other){
    for(const Point* a : other.points){
        points.push_back(new Point(*a));
    }
}
Rhombus& Rhombus::operator=(const Rhombus& other){ //Копирующее присв.
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

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept{
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

Rhombus:: ~Rhombus(){
    for(Point* a : points){
        delete a;
    }
    points.clear();
}

void Rhombus::read(std::istream& is){
    for(Point* a : points){
        delete a;
    }
    points.clear();
    Point p1, p2 , p3, p4;
    std::cout << "Enter 4 points of Rhombus:" << std::endl;
    std::cout << "Point 1: X_POS Y_POS: ";
    is >> p1.x >> p1.y;
    std::cout << "Point 2: X_POS Y_POS: ";
    is >> p2.x >> p2.y;
    std::cout << "Point 3: X_POS Y_POS: ";
    is >> p3.x >> p3.y;
    std::cout << "Point 4: X_POS Y_POS: ";
    is >> p4.x >> p4.y;
    points = {new Point{p1}, new Point{p2}, new Point{p3}, new Point{p4}};
}

bool Rhombus::equal(const Figure& other) const{
    const Rhombus* rhs = dynamic_cast<const Rhombus*>(&other);
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
    return point_cnt == 4;
}
Rhombus::operator double() const {
    double d1 = std::sqrt(std::pow(points[0]->x - points[2]->x, 2) + 
                         std::pow(points[0]->y - points[2]->y, 2));
    double d2 = std::sqrt(std::pow(points[1]->x - points[3]->x, 2) + 
                         std::pow(points[1]->y - points[3]->y, 2));
    return (d1 * d2) / 2.0;
}