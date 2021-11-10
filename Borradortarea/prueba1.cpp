//Makefiles y sumas

#include <iostream>
#include <cmath>

typedef float REAL;
REAL sum1(int N);
REAL sum2(int N);
REAL sum3(int N);


int main(void)
{
   

  for(int N = 1; N <= 10; N++) {

    //REAL diff1 = std::fabs(sum1(N) - sum3(N))/sum3(N);
    REAL diff2 = std::fabs(sum2(N) - sum3(N))/sum3(N);

    std::cout << N  << "\t"<<sum1(N)<<"\t" <<sum2(N)<<"\t"<<sum3(N)<<"\t"<< diff2 <<"\n";
  }
    return 0;
}




//sum1: suma alternando el signo 

REAL sum1(int N)
{
    REAL suma = 0;
    for(int ii = 1; ii <=2*N; ++ii) {
      suma += (pow(-1.0, ii)*ii)/(ii+1.0);
    }
    return suma;
}



//sum2: suma solamente con una resta 

REAL sum2(int N)
{
    REAL suma = 0;
    REAL termino1=0;
    REAL termino2=0;
    
    for(int ii = 1; ii<= N; ++ii) {
      termino1 -= (2.0*ii-1.0)/(2.0*ii);
      termino2 += (2.0*ii)/(2.0*ii+1.0);
    }

    suma= termino2 + termino1;
    
    return suma;
}



//sum3: suma sin restas

REAL sum3(int N)
{
  REAL suma=0;
  
  for (int ii=1; ii<=N; ++ii){
    suma += 1.0/(2.0*ii*(2.0*ii+1.0));
  }
  return suma;
}
