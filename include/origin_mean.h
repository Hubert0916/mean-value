#include <ranges>
#include <numeric>

constexpr auto originMean(std::ranges::range auto &&d)
{
    using item_t = std::ranges::range_value_t<decltype(d)>;
    return std::reduce(std::begin(d), std::end(d), item_t{}) /
           static_cast<item_t>(std::ranges::distance(d));
}