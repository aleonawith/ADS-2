// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  for (int i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0)
    return 1;
  else
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double res = 0;
  for (int i = 0; i <= count; i++) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  int k = 1;
  double res = 0;
  for (int i = 1; i <= count; i++) {
    if (i % 2 != 0)
      res += calcItem(x, k);
    else
      res -= calcItem(x, k);
    k += 2;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  int k = 0;
  double res = 0;
  for (int i = 1; i <= count; i++) {
    if (i % 2 != 0)
      res += calcItem(x, k);
    else
      res -= calcItem(x, k);
    k += 2;
  }
  return res;
}
