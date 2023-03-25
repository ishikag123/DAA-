#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
   double hi;
   double lo;
} two_val;

// double fibo(int num)
// {
//     if (num == 0)
//     {
//         return 0; 
//     }
//     else if (num == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         double n1=0,n2=1,n3;
//         for(int i=1;i<num;i++){
//             n3=n1+n2;
//             n1=n2;
//             n2=n3;
//         }
//         return n3;
//     }
// }
double hirec(int);
double lorec(int);

double hirec ( int n )
{
    if(n==0){
        return 1;
    }
    return 2*hirec(n-1)+lorec(n-1);
}

double lorec ( int n )
{
    if(n==0){
        return 0;
    }
    return hirec(n-1)+lorec(n-1);
}

two_val hilorec ( int n )
{
   two_val N2,N;
   if (n==0){
    N.hi=1;
    N.lo=0;

    return N;
   }
   N2=hilorec(n-1);
   N.hi=2*N2.hi+N2.lo;
   N.lo=N2.hi+N2.lo;
   
   return N;   
}

two_val hiloformula ( int n )
{
   two_val N;

   N.hi = ((5+sqrt(5))/10)*pow(((3-sqrt(5))/2),n+1)+((5-sqrt(5))/10)*pow(((3+sqrt(5))/2),n+1);
   N.lo = ((-5-(sqrt(5))*3)/10)*pow(((3-sqrt(5))/2),n+1)+((-5+(sqrt(5))*3)/10)*pow(((3+sqrt(5))/2),n+1);
   return N;
}

// double hirec2(int n){
//     return fibo(2*n+1);
// }

// double lorec2(int n){
//     return fibo(2*n);
// }

int main ()
{
   two_val N1, N2, N3;
   int n;

   clock_t start, end;
   double cpu_time_used;

   printf("n=");
   scanf("%d", &n);
   printf("\nn = %d\n", n);

   printf("\n+++ Method 0\n");
   start = clock();
   N1.hi = hirec(n); N1.lo = lorec(n);
   end = clock();
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N1.hi, n, N1.lo);
   cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   printf("Method 0 took %f seconds to execute \n", cpu_time_used);

   printf("\n+++ Method 1\n");
   start = clock();
   N2 = hilorec(n);
   end = clock();
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N2.hi, n, N2.lo);
   cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   printf("Method 1 took %.20f seconds to execute \n", cpu_time_used);

   printf("\n+++ Method 2\n");
   start = clock();
   N3 = hiloformula(n);
   end = clock();
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N3.hi, n, N3.lo);
   cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   printf("Method 2 took %.20f seconds to execute \n", cpu_time_used);

   // printf("\n+++ Method 3\n");
   // start = clock();
   // N4.hi = hirec2(n); N4.lo = lorec2(n);
   // end = clock();
   // printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N4.hi, n, N4.lo);
   // cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   // printf("Method 0 took %f seconds to execute \n", cpu_time_used);

   exit(0);
}
