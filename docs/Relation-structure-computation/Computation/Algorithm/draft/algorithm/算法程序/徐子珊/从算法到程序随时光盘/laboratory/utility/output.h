/* 
 * File:   output.h
 * Author: ����ɺ
 *
 * Created on 2009��7��1��, ����10:31
 */

#ifndef _OUTPUT_H
#define	_OUTPUT_H
#ifdef	__cplusplus
extern "C" {
#endif
#include <stdio.h>
void intOutput(void *x);
void charOutput(void *x);
void doubleOutput(void *x);
void floatOutput(void *x);
void stringOutput(void *x);
#ifdef	__cplusplus
}
#endif

#endif	/* _OUTPUT_H */