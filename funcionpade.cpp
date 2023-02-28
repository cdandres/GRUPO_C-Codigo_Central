#include <iostream>
#include <string>
#include <cmath>

double sin_pade(double x){

    double a = ((12671/4363920)*(std::pow(x, 5)) - ((2363/18183)*(std::pow(x, 3))) + x);
    double b = (1 + ((445/12122)*std::pow(x, 2))  + ((601/872784)*std::pow(x, 4)) + ((121/16662240)*std::pow(x, 6)));

    return a/b;
}

int main(void){

    double x = 0.1;
    std::cout << x <<"\t"<< sin_pade(x) << std::sin(x) << std::endl;
    
    return 0;
}
\\Si deja editar
