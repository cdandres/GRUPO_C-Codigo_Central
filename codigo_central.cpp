#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

unsigned long long factorial(int i);
long double sinTaylor (double x, int max);
long double sinK (double x, int max);
long double sinPade(double x);

int main(int argc, char **argv)
{
  double x {0.0};

  if(argc != 1) { //no hay argumentos de entrada, el valor de x es fijo entre 0 y 2pi y los terminos de las series son 5 y 10
    std::cerr << "ERROR.\nUsage:\n" << argv[0] << "\n";
    return 1;
  }

  std::ofstream fout("datos.txt");
  
  fout << "x" << "\t" << "exact" << "\t" << "sinTaylor" << "\t" << "errorTaylor" << "\t" << "sinPade" << "\t" << "errorPade" << "\t" << "sinK" << "\t" << "errorK" << "\n"

  double pi = std::acos(-1); //Este seria el valor de pi.

  for (x = 0; x <= 2*pi; x+=0.1) { 

    double exact = std::sin(x);
    double sin_Taylor = sinTaylor(x, 5);
    double sin_Pade = sinPade(x);
    double sin_K = sinK(x, 10);

    fout << x << "\t" << exact << "\t"
         << sin_Taylor << "\t" << std::fabs(1.0 - sin_Taylor/exact) << "\t"
         << sin_Pade << "\t" << std::fabs(1.0 - sin_Pade/exact) << "\t" 
         << sin_K << "\t" << std::fabs(1.0 - sin_K/exact) << "\n";
  }
  fout.close();

  return 0;
}

// Factorial
unsigned long long factorial(int n){
  unsigned long long result = 1;

  for (int i = 2; i <= n; i++){
    result *= i;
  }
  return result;
}

// Aproximación del seno en series de Taylor
long double sinTaylor (double x, int maxN){
  double sinValue = 0;

  for (int k = 0; k<=maxN; k++){
    sinValue += std::pow(-1.0, k) * std::pow(x, 2*k+1) / factorial(2*k+1);
  }
  return sinValue;
}

// Nuestra aproximación recursiva del seno.
long double sinK (double x, int max){
  double sinValue = sinTaylor(x, 2);

  for (int k = 2; k<=max; k++){
    sinValue += -1* sinValue * std::pow(x,2)/(2*k*((2*k)+1));
  }
  
  return sinValue;
}

//Aproximación del seno de Padé
long double sinPade(double x){

    double a = ((12671/4363920)*(std::pow(x, 5)) - ((2363/18183)*(std::pow(x, 3))) + x);
    double b = (1.0 + ((445/12122)*std::pow(x, 2))  + ((601/872784)*std::pow(x, 4)) + ((121/16662240)*std::pow(x, 6)));

    return a/b;

}

