#pragma once
#include <ranges>
#include <cstdint>

// Computes the mean of a range of integers using integer arithmetic.
// Handles negative values and avoids overflow using a quotient/remainder approach.
// Result is rounded toward zero with fair remainder handling.
constexpr auto myMean(std::ranges::range auto &&d)
{
    using item_t = std::ranges::range_value_t<decltype(d)>;
    item_t sum_of_q = 0;                                          // Accumulated quotients
    intmax_t sum_of_r = 0;                                        // Accumulated remainders
    intmax_t N = static_cast<intmax_t>(std::ranges::distance(d)); // Total number of elements

    if (N == 0) // Handle empty range: return zero as the mean
    {
        return item_t{0};
    }

    for (item_t x : d)
    {
        // Integer division and modulo
        auto q = x / N;
        auto r = x % N;

        // Ensure remainder r is always non-negative
        if (r < 0)
        {
            q--;
            r += N;
        }

        // calculate sum of quotient
        sum_of_q += static_cast<item_t>(q);

        // If the accumulated remainder is enough to carry over, increment the quotient and update the remaining remainder.
        if (sum_of_r + r >= N)
        {
            sum_of_q++;
            sum_of_r += r - N;
        }
        else
        {
            sum_of_r += r;
        }
    }

    // Rounding process
    if( sum_of_q >= 0)
    {
        // e.g., 3 + 0.5 = 3.5 is rounded up to 4
        return static_cast<item_t>(sum_of_q + (2 * sum_of_r >= N));
    }
    else
    {
        // e.g., -4 + 0.5 = -3.5 is rounded up to -4
        return static_cast<item_t>(sum_of_q + (2 * sum_of_r > N));
    }
}