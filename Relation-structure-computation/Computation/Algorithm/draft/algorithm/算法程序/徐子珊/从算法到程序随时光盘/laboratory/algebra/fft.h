#ifndef _FFT_H
#define	_FFT_H
#include "complex.h"
Complex* fft(Complex *a, int n, int inv);/*向量a的fft变换*/
Complex* fftInverse(Complex *a, int n);/*向量a的fft逆变换*/
#endif	/* _FFT_H */
