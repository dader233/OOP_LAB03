#include "../include/Figure.h"

Point Figure::center() const{
    if (points.empty()){
        return Point{0, 0};
    }
    double res_x = 0.0;
    double res_y = 0.0;
    for(Point* A : points){
        res_x += A->x;
        res_y += A->y;
    }
    double quantity = points.size()
    Point res = {res_x/quantity, res_y/quantity};
    return res;
}

std::operator<<(std::ostream&, const Figure& figure){
    if (figure.points.empty()){
        os << "Figure is empty." << "\n";
    }
    else{
        for(size_t i = 0; i < figure.points.size(); i++){
            os  << "Point" << i+1 << "coords: {" << figure.points[i] -> x << ', ' << figure.points[i] -> y 
                << "}" << "\n";
        }
    }
    return os;
}

std::operator>>(std::istream& is, Figure& figure) {
    figure.read(is); 
    return is;
}

bool operator==(const Point& a, const Point& b) {
    return std::abs(a.x - b.x) < 1e-7 && std::abs(a.y - b.y) < 1e-7;
}

bool operator==(const Figure& fig1, const Figure& fig2){
    return fig1.equal(fig2);
}