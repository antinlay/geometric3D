#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

class Curve {
 public:
  virtual std::tuple<double, double, double> getPoint(double t) = 0;
  virtual std::tuple<double, double, double> getDerivative(double t) = 0;
  virtual double getter() = 0;
};

class Circle : public Curve {
 public:
  Circle(double radius) : radius(radius) {}

  std::tuple<double, double, double> getPoint(double t) override {
    return {radius * cos(t), radius * sin(t), 0};
  }

  std::tuple<double, double, double> getDerivative(double t) override {
    return {-radius * sin(t), radius * cos(t), 0};
  }

  double getter() { return radius; }

 private:
  double radius;
};

class Ellipse : public Curve {
 public:
  Ellipse(double radiusX, double radiusY)
      : radiusX(radiusX), radiusY(radiusY) {}

  std::tuple<double, double, double> getPoint(double t) override {
    return {radiusX * cos(t), radiusY * sin(t), 0};
  }

  std::tuple<double, double, double> getDerivative(double t) override {
    return {-radiusX * sin(t), radiusY * cos(t), 0};
  }

 private:
  double radiusX;
  double radiusY;
};

class Spiral : public Curve {
 public:
  Spiral(double radius, double step) : radius(radius), step(step) {}

  std::tuple<double, double, double> getPoint(double t) override {
    return {radius * cos(t), radius * sin(t), t * step};
  }

  std::tuple<double, double, double> getDerivative(double t) override {
    return {-radius * sin(t), radius * cos(t), step};
  }

 private:
  double radius;
  double step;
};
