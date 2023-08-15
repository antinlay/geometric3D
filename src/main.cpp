#include "model.h"

int main() {
  std::vector<Curve*> curves;
  curves.push_back(new Circle(5));
  curves.push_back(new Ellipse(10, 15));
  curves.push_back(new Spiral(20, 0.1));

  // Fill container with random curves

  std::list<Circle*> circles;
  for (auto curve : curves) {
    Circle* circle = dynamic_cast<Circle*>(curve);
    if (circle) circles.push_back(circle);
  }

  // Sort circles by radius
  circles.sort([](Circle* a, Circle* b) { return a->getter() < b->getter(); });

  // Compute total radius
  double totalRadius = 0;
  for (auto circle : circles) {
    totalRadius += circle->getter();
  }

  std::cout << "Total radius: " << totalRadius << std::endl;
}