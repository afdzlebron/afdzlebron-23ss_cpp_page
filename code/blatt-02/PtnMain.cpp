// Copyright 2023, AFL

#include "Ptn.hpp"
#include "PtnPrint.hpp"

int main(int argc, char **argv) {
  int n = 1303601;
  bool result = is_pythagorean_triple(n, true);
  return result;
}
