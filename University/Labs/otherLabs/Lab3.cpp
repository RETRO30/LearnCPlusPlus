 #include <iostream>

 int main(){

    // Пункт 1
    int A, B, C;
    std::cin >> A >> B >> C;
    if (A > 0 && B > 0 && C > 0){
        if (A < B && B < C){
            std::cout << "A < B < C -> " << C << B << A << std::endl; 
        }
        else if (A % C == 0){
            std::cout << "A%C==0 -> " << A/C + B << std::endl;
        }
        else {
            std::cout << "Doesn't fit any of the conditions -> " << A + B + C << std::endl;
        }
    }
    else {
        std::cout << "Error with input";
    }

    // Пункт 2
    int N;
    std::cin >> N;
    N = N < 50 && N > 0 ? N:-1;
    switch (N)
    {
    case (1):
        std::cout << "Is the square" << std::endl;
        break;
    case (4):
        std::cout << "Is the square" << std::endl;
        break;
    case (9):
        std::cout << "Is the square" << std::endl;
        break;
    case (16):
        std::cout << "Is the square" << std::endl;
        break;
    case (25):
        std::cout << "Is the square" << std::endl;
        break;
    case (36):
        std::cout << "Is the square" << std::endl;
        break;
    case (49):
        std::cout << "Is the square" << std::endl;
        break;
    default:
        std::cout << "Is not a square" << std::endl;
        break;
    }
 }