#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

# Complete the anagram function below.
def anagram(s):
    n = len(s) 
    # if length of str is odd
    if n % 2: return -1

    s1, s2 = s[:n//2], s[n//2:]
    c1 = Counter(s1)
    c2 = Counter(s2)
    
    diff = 0
    for c in set(s):
        diff += abs(c1.get(c, 0) - c2.get(c, 0))
    
    return diff//2

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = anagram(s)

        fptr.write(str(result) + '\n')

    fptr.close()
