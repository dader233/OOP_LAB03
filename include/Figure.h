#pragma once

#include <iostream>
#include <vector>
#include <cmath>

struct Point{
    double x;
    double y;
};

bool operator==(const Point& a, const Point& b);

class Figure{
    protected:
        std::vector<Point*> points;
        virtual void read(std::istream& is) = 0; // пункт 2 добавка
        virtual bool equal(const Figure& other) const = 0;
    public:
        Point center() const; // центр (пункт 1)
        virtual operator double() const = 0; // площадь (пункт 4)
        friend std::istream& operator>> (std::istream& is, Figure& figure); // пункт 3
        friend std::ostream& operator<< (std::ostream& os, const Figure& figure); // пункт 2
        friend bool operator==(const Figure& fig1, const Figure& fig2);
        virtual ~Figure() = default;
   
        
}; 
