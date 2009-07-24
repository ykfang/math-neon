/*
Math-NEON:  Neon Optimised Math Library based on cmath
Contact:    lachlan.ts@gmail.com
Copyright (C) 2009  Lachlan Tychsen - Smith aka Adventus

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "math.h"
#include <stdio.h>

const float __log2f_A = 1.0f / 8388608.0f;
const float __log2f_B = 127.0f;

float log2f_fast(const float x){
	
	union {
		float f;
		int i;
	} sx;
	
	sx.f = fabsf(x);	
	sx.f = ((float) sx.i) * __log2f_A - __log2f_B;
	
	return sx.f;
}

const float __logf_A = 0.69314718055f;

float logf_fast(const float x){
	return log2f_fast(x) * __logf_A;
}

const float __expf_A = 8388608 / M_LN2;
const float __expf_B = 1065353216 - 366393;

float expf_fast(const float x){

	union {
		float f;
		int i;
	} sx;

	sx.f = x;
	sx.i = (__expf_A * x + __expf_B);
	return sx.f;
}

float powf_fast(const float x, const float y){
	return expf_fast(y * logf_fast(x));
}