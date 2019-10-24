//
// Created by nik on 10/24/19.
//
#ifndef CS103_DZ04_NIKOLA_TASIC_3698_QUICKSORT_H
#define CS103_DZ04_NIKOLA_TASIC_3698_QUICKSORT_H

#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>


extern void memswp(void* a, void* b, uint size) {
	void* t = malloc(size);
	memcpy(t, a, size);
	memcpy(a, b, size);
	memcpy(b, t, size);
	free(t);
}

extern int64_t badd(void* num, uint size) {
	int64_t sum = 0;
	int64_t n = *(int64_t*) num;
	uint bmask = (uint) (1 << (size * CHAR_BIT - 1));
	uint msb = n & bmask;
	if (msb) {
		n = ~n + 1;
		for (uint i = bmask; i > 0; i = i / 2) { // (n & i) ? printf("1") : printf("0");
			sum -= i * !!(n & i);
		}
	} else {
		for (uint i = bmask; i > 0; i = i / 2) { // (n & i) ? printf("1") : printf("0");
			sum += i * !!(n & i);
		}
	}
	return sum;
}

static int __cmpfunc(void* a, void* b, uint size) {
	return badd(a, size) < badd(b, size);
}

static int (* _cmpfunc)(void*, void*, uint);

static int _partition(void* arr, uint size, int low, int high, int (* cmpfunc)(void*, void*, uint)) {
	void* pivot;
	int i = low - 1;

	pivot = malloc(size);
	memcpy(pivot, arr + high * size, size);

	for (int j = low; j <= high - 1; j++) {
		if (cmpfunc(arr + j * size, pivot, size)) {
			i++;
			memswp(arr + i * size, arr + j * size, size);
		}
	}
	memswp(arr + (i + 1) * size, arr + high * size, size);
	free(pivot);
	return (i + 1);
}

static void _quicksort(void* arr, uint size, int32_t low, int32_t high, int (* cmpfunc)(void*, void*, uint)) {
	if (low < high) {
		int pi = _partition(arr, size, low, high, cmpfunc);
		_quicksort(arr, size, low, pi - 1, cmpfunc);
		_quicksort(arr, size, pi + 1, high, cmpfunc);
	}
}

extern void quicksort(void* arr, uint32_t nmemb, uint size, int (* cmpfunc)(void*, void*, uint)) {
	_cmpfunc = cmpfunc != NULL ? cmpfunc : &__cmpfunc;
	_quicksort(arr, size, 0, nmemb, _cmpfunc);
}

#endif
