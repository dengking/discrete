#ifndef _FFT_H
#define	_FFT_H
#include "complex.h"
Complex* fft(Complex *a, int n, int inv);/*����a��fft�任*/
Complex* fftInverse(Complex *a, int n);/*����a��fft��任*/
#endif	/* _FFT_H */
