#include <math.h>
#include "pav_analysis.h"

float ventana_Hamming(unsigned int n, unsigned int N){
    float valor = 0.54 - 0.46*cos(2*M_PI*n/N-1); 
    return valor;
}
float power_Hamming(const float *x, unsigned int N){
    float num = 0;
    float den;
        for(unsigned int n=0; n<N; n++){
            float  w = ventana_Hamming(n, N);
            num += pow(x[n] * w, 2);
            den = w * w;
        }
    return (10*log10(num/den));
}

float compute_power(const float *x, unsigned int N) {
    float num = 0;
        for(unsigned int n=0; n<N; n++){
            num += x[n]*x[n];
        }
    return (10*log10(num/N));
}

float compute_am(const float *x, unsigned int N) {
    float num = 0;
    for(unsigned int n=0; n<N; n++){
        num += fabs(x[n]);
    }
    return (num/N);
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    int count = 0;
    for(unsigned int n=1; n<N; n++){
        if(x[n]*x[n-1] < 0){
            count++;
        }
    }
    return (fm/2.0)*(1.0/(N-1.0))*count;
}
int sgn(float x){
    if(x<0){
        return -1;
    }
    if(x==0){
        return 0;
    }
    if(x>0){
        return 1;
    }
    return 0;
}