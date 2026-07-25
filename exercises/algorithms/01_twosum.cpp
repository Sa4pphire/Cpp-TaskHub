#include <cassert>
#include <cstddef>
#include <optional>
#include <utility>
#include <vector>
#include <unordered_map>

using IndexPair = std::pair<std::size_t, std::size_t>;

std::optional<IndexPair> two_sum(
    const std::vector<int>& numbers,
    int target) {
    std::unordered_map<int, std::size_t> seen;

    for (std::size_t i = 0; i < numbers.size(); ++i) {
        const int needed = target - numbers[i];
        auto it = seen.find(needed);
        if (it != seen.end()){
            return IndexPair{it->second,i};
        }
        seen[numbers[i]] = i;
        // TODO：
        // 1. 在 seen 中查找 needed。
        // 2. 找到时返回两个下标。
        // 3. 没找到时记录当前数字和下标。
    }

    return std::nullopt;
}

int main() {
    const auto normal = two_sum({2, 7, 11, 15}, 9);
    assert(normal.has_value());
    assert(normal->first == 0);
    assert(normal->second == 1);

    const auto duplicate = two_sum({3, 3}, 6);
    assert(duplicate.has_value());
    assert(duplicate->first == 0);
    assert(duplicate->second == 1);

    assert(!two_sum({}, 9).has_value());
    assert(!two_sum({3}, 6).has_value());
    assert(!two_sum({1, 2, 3}, 10).has_value());

    return 0;
}