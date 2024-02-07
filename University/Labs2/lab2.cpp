#include <math.h>
#include <string>
#include <iostream>

namespace sh {

        class Triangle {
                private:
                        int a, b, c;
                public:
                        Triangle() {
                                this->a = 1;
                                this->b = 1;
                                this->c = 1;
                        }

                        Triangle(int a, int b, int c): Triangle() {
                                if ((a + b < c || a + c < b || b + c < a) || (a <= 0 || b <= 0 || c <= 0)) {
                                        std::cout <<"Invalid triangle sides: " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) << std::endl;
                                }
                                else {
                                        this->a = a;
                                        this->b = b;
                                        this->c = c;
                                }
                                
                        }
                        
                        Triangle(const Triangle &t) {
                                this->a = t.a;
                                this->b = t.b;
                                this->c = t.c;
                        }

                        int getMinSide() {
                                return a < b ? (a < c ? a : c) : (b < c ? b : c);
                        }

                        double calcArea() {
                                double p = (a + b + c) / 2.0;
                                return sqrt(p * (p - a) * (p - b) * (p - c));
                        }

                        std::string getInfo() {
                                return "Triangle: a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c)+ ", area = " + std::to_string(calcArea());
                        }

                        ~Triangle() {
                                std::cout << "Class deleted" << std::endl;
                        }
        };
}

int main() {
        sh::Triangle t(3, 4, 5);
        sh::Triangle t2(t);
        sh::Triangle t3(-1, 2, 3);
        std::cout << t.getInfo() << std::endl;
        std::cout << t2.getInfo() << std::endl;
        std::cout << t3.getInfo() << std::endl;
        return 0;
}