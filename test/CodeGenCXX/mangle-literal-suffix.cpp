// RUN: %clang_cc1 -triple mips-none-none -emit-llvm -o - %s | FileCheck %s

template <class T> void g3(char (&buffer)[sizeof(T() + 5.0)]) {}
template void g3(char (&)[sizeof(double)]);
// CHECK: _Z2g3IdEvRAszplcvT__ELd4014000000000000E_c

template <class T> void g4(char (&buffer)[sizeof(T() + 5.0L)]) {}
template void g4(char (&)[sizeof(long double)]);
// CHECK: _Z2g4IeEvRAszplcvT__ELe4014000000000000E_c

template <class T> void g5(char (&buffer)[sizeof(T() + 5)]) {}
template void g5(char (&)[sizeof(int)]);
// CHECK: _Z2g5IiEvRAszplcvT__ELi5E_c

template <class T> void g6(char (&buffer)[sizeof(T() + 5L)]) {}
template void g6(char (&)[sizeof(long int)]);
// CHECK: _Z2g6IlEvRAszplcvT__ELl5E_c