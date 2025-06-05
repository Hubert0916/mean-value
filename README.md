## Problem
Write a new C++ function or class that can calculate the correct mean value for any integral type without using floating point or big number libraries. 

The function should avoid producing incorrect results for any input, even with large amounts of data.

## Project Structure
```
mean-value
├── benchmark
│   └── mean_benchmark.cpp
├── include
│   ├── my_mean.h (Good version.)
│   └── origin_mean.h (Bad version. It could lead to overflow easily)
├── src
│   └── main.cpp
└── test
    └── mean_test.cpp
```


## Strategy
   
Initially, I used Welford’s Online Algorithm to compute the mean value.

While it’s known for its numerical stability and ability to handle streaming data efficiently, I encountered some drawbacks in my use case:
  •	Rounding issues: Since the algorithm incrementally updates the mean using a delta value, it requires rounding at every step. This introduces small but compounding errors, especially with negative numbers.
  •	Complexity with negative values: Handling negative inputs and ensuring correct rounding behavior added unnecessary complexity to my implementation.

To address these issues, I switched to a more intuitive approach: dividing each variable by the dataset size and storing the quotient and remainders. 

This avoids overflow and gives the same result as the standard mean formula, without the rounding overhead of Welford’s method.


## Test & Benchmark

I use Google Test for unit testing and Google Benchmark to measure program execution time.
