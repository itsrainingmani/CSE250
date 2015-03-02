/***
 *  $Id$
 **
 *  File: a2.cpp
 *  Created: Feb 11, 2015
 *
 *  Author: Jaroslaw Zola <jzola@buffalo.edu>
 */

#include <iostream>
#include "a2.hpp"

const int N = 1024;
const int M = 128;

A2 create_array() {
    A2 A;
    A = A2(N, M);
    return A;
} // create_array

void write_array(A2& A) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) A(i, j) = 0.0;
    }
    A(N - 1, M - 1) = 1;
} // write_array

double read_array(const A2& A) { return A(N - 1, M - 1); }


// if you see 3 ok there is a good chance your code works ;-)

int main(int argc, char* argv[]) {
    /*
    A2 A = create_array();
    write_array(A);

    std::cout << ((read_array(A) == 1) ? "ok" : "error") << std::endl;
    std::cout << ((A.rsum(N - 1) == 1) ? "ok" : "error") << std::endl;
    std::cout << ((A.csum(M - 1) == 1) ? "ok" : "error") << std::endl;
    */

    A2 A(N,M);
    write_array(A);

    A(3,3) = 9.4;
    A(4,3) = 12.0;
    A(3,4) = 10.0;
    std::cout<<A(3,3)<<std::endl;
    std::cout<<A.csum(4);

    return 0;
} // main
