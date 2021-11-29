#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N, Q, K = list(map(int, input().strip().split()))
V = list(map(int, input().strip().split()))
for _ in range(Q):
    row = list(map(int, input().strip().split()))
    type = row[0]
    if type == 1:
        # building update
        a, b = row[1:]

        # insert your code here
        
    if type == 2:
        # redevelopment planning
        l, r, s = row[1:]

        # insert your code here

        print(42)  # print the result of the query
