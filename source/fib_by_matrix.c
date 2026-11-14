#include <bits/types/stack_t.h>
#include <stdio.h>
#include <inttypes.h> //for printing uint ' s'
#include <stdlib.h> // for exit 
#include <stdint.h> //for uints_t  ; s = size in bits 
#include <strings.h> //for atoll


uint64_t calculate( long long int nthFib );

int main( int  argc , char* argv[]  ){
  unsigned long int NthFib ;
  if (argc != 2){ printf("incorrect usage \n Usage : fib [number]\n"); exit(-1);  }
  printf("%lld" , atoll(argv[1]));
  NthFib = atoll(argv[1]);
  printf("calculating your fibonachi %" PRIu64 "\n" , calculate(NthFib));
  
  return 0;
}


char matrixX1[2][2] = {1, 1, 1 ,0}; // meaning calute next fib 
/*
  matrix * [x] = [ x + y]
           [y] = [   y  ]
*/

uint64_t matrixX64[2][2]= { //meaning calulate 64th fib . matrixX1 ^ 64
     17167680177565 ,  10610209857723 ,
     10610209857723 ,   6557470319842
};




//as of now currently no work of E , Einv and lambdas
//at first i considered to use these 3
//depedning upon the acuuracy and nth fib dynamically calculate the matrixX__ for the numerb of jumps


/*
float_t E[2][2] = { 0.8507 , 0.5257 , -0.5257 , -0.8505 };
float_t Einv[2][2] = { -.8507 , -0.5257 , 0.5257 , -0.8507 };
float_t lambdas[2] = { 1.6180 ,  -0.6180 };
*/


uint64_t calculate(long long int  n){
  n--;  //because first fibonachi is taken is zero

  uint64_t px , py , x ,y ;
  x = 0 , y = 0 ,px = 1 ; py = 0 ;
  
  uint8_t bigSteps= n / (64);
  uint8_t smallSteps = n % (64);  
  while ( bigSteps != 0  )
  {
      x = matrixX64[0][0] * px + matrixX64 [0][1] * py;
      y = matrixX64[1][0] * px + matrixX64 [1][1] * py;

      px = x;py = y;
      bigSteps--;
  }
  while(smallSteps !=0 )
  {
      x = matrixX1[0][0] * px + matrixX1 [0][1] *py;
      y = matrixX1[1][0] * px + matrixX1 [1][1] *py;
      px = x ; py =y ;
      smallSteps--;
  }
  
  return x;
}
