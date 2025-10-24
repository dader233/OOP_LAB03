#pragma once
#include "Figure.h"

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    ~Pentagon();
    
    void read(std::istream& is) override;
    bool equal(const Figure& other) const override;
    operator double() const override;
};