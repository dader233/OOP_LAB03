#pragma once
#include "Figure.h"

class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    ~Hexagon();
    
    void read(std::istream& is) override;
    bool equal(const Figure& other) const override;
    operator double() const override;
};