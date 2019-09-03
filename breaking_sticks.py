#!/bin/python3

import math
import os
import random
import re
import sys
long NoOfMoves(long n){
    if(n == 1)
        return 1;
    long m = n;
    int p = 0;
    while(m%2 == 0){
        p++;
        m /= 2;
    }
    if(m == 1)
        return n*2 - 1;
    bool b = true;
    long ans = 0;
    for (int i = 2; i <= sqrt(n); ++i){
        if(n%i == 0){
            b = false;
            ans = max(ans, 1 + (n/i) * NoOfMoves(i));
            ans = max(ans, 1 + i * NoOfMoves(n/i));
        }
    }
    if(b)
        return n+1;
    return ans;
}
d = {}
def NoOfMoves(n):
	if n == 1:
		d[1] = 1
		return d[1]
	m = n;
    p = 0;
    while m%2 == 0:
        p++
        m /= 2

    if m == 1:
        return n*2 - 1;

# Complete the longestSequence function below.
def longestSequence(a):
    # Return the length of the longest possible sequence of moves.

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    a = list(map(int, input().rstrip().split()))

    result = longestSequence(a)

    fptr.write(str(result) + '\n')

    fptr.close()
