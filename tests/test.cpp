#include <gtest/gtest.h>
#include <sstream>
#include "../include/Figure.h"
#include "../include/Rhombus.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"

// Тесты для Rhombus
TEST(RhombusTest, AreaCalculation) {
    Rhombus rhombus;
    EXPECT_NEAR(2.0, static_cast<double>(rhombus), 1e-6);
}

TEST(RhombusTest, CentreCalculation) {
    Rhombus rhombus;
    Point centre = rhombus.center();
    EXPECT_NEAR(0.0, centre.x, 1e-6);
    EXPECT_NEAR(0.0, centre.y, 1e-6);
}

TEST(RhombusTest, EqualityOperator) {
    Rhombus rhombus1;
    Rhombus rhombus2;
    EXPECT_TRUE(rhombus1 == rhombus2);
}

TEST(RhombusTest, CopyAssignment) {
    Rhombus rhombus1;
    Rhombus rhombus2;
    rhombus2 = rhombus1;
    EXPECT_TRUE(rhombus1 == rhombus2);
}

// Тесты для Pentagon
TEST(PentagonTest, AreaCalculation) {
    Pentagon pentagon;
    double area = static_cast<double>(pentagon);
    EXPECT_GT(area, 0.0);
}

TEST(PentagonTest, CentreCalculation) {
    Pentagon pentagon;
    Point centre = pentagon.center();
    EXPECT_NEAR(0.0, centre.x, 1e-3);
    EXPECT_NEAR(0.4, centre.y, 1e-3);
}

// Тесты для Hexagon
TEST(HexagonTest, AreaCalculation) {
    Hexagon hexagon;
    double area = static_cast<double>(hexagon);
    EXPECT_GT(area, 0.0);
}

TEST(HexagonTest, CentreCalculation) {
    Hexagon hexagon;
    Point centre = hexagon.center();
    EXPECT_NEAR(0.0, centre.x, 1e-6);
    EXPECT_NEAR(0.0, centre.y, 1e-6);
}

// Тест полиморфизма
TEST(PolymorphismTest, FigurePointer) {
    Rhombus* rhombus = new Rhombus();
    Pentagon* pentagon = new Pentagon();
    Hexagon* hexagon = new Hexagon();
    
    Figure* figures[] = {rhombus, pentagon, hexagon};
    
    for (int i = 0; i < 3; ++i) {
        Point centre = figures[i]->center();
        double area = static_cast<double>(*figures[i]);
        EXPECT_GT(area, 0.0);
    }
    
    delete rhombus;
    delete pentagon;
    delete hexagon;
}

// Простой тест вывода
TEST(StreamTest, OutputOperator) {
    Rhombus rhombus;
    std::ostringstream oss;
    oss << rhombus;
    EXPECT_FALSE(oss.str().empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}