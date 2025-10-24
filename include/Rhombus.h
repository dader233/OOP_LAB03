#pragma once
#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    ~Rhombus();
    
    void read(std::istream& is) override;
    bool equal(const Figure& other) const override;
    operator double() const override;
};