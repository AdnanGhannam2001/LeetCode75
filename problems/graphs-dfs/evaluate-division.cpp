/**
 * Problem:
 *  LeetCode 75 -> Graphs - DFS
 *  399. Evaluate Division (Medium)
 *  https://leetcode.com/problems/evaluate-division/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/evaluate-division/submissions/1379750945?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      11.05MB
 *      Beats: 80.46%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
private:
    using MapKey = std::string;
    using Result = struct
    {
        std::string s;
        double value;
    };
    using MapValue = struct
    {
        bool visiting;
        std::vector<Result> results;
    };
    using Map = std::unordered_map<MapKey, MapValue>;

    void init_or_push(Map &map, MapKey key, const Result &result)
    {
        if (map.count(key) == 0)
            map[key] = {false, std::vector({result})};
        else
            map[key].results.push_back(result);
    }

    double calcEquationImpl(Map &map, const std::string& expand, const std::string& denominator)
    {
        MapValue &value = map[expand];
        double res = -1.0;

        if (value.visiting)
            return res;

        value.visiting = true;

        auto denominator_iter = std::find_if(value.results.begin(), value.results.end(), [denominator](const Result a)
        {
            return a.s == denominator;
        });

        if (denominator_iter != value.results.end())
        {
            res = denominator_iter->value;
            goto out;
        }

        for (auto &result : value.results)
        {
            if ((res = calcEquationImpl(map, result.s, denominator)) != -1.0)
            {
                res *= result.value;
                goto out;
            }
        }

out:
        value.visiting = false;
        return res;
    }

public:
    std::vector<double> calcEquation(
        const std::vector<std::vector<std::string>> &equations,
        const std::vector<double> &values,
        const std::vector<std::vector<std::string>> &queries)
    {
        Map map;
        std::vector<double> results;

        for (uint8_t i = 0; i < equations.size(); ++i)
        {
            init_or_push(map, equations[i][0], {equations[i][1], values[i]});
            init_or_push(map, equations[i][1], {equations[i][0], 1 / values[i]});
        }

        for (const auto& query : queries)
        {
            results.push_back(calcEquationImpl(map, query[0], query[1]));
        }

        return results;
    }
};

int main()
{
    Solution solution;

    solution.calcEquation(
        std::vector({std::vector({std::string("a"), std::string("b")}), std::vector({std::string("b"), std::string("c")})}),
        std::vector({2.0, 3.0}),
        std::vector<std::vector<std::string>>());

    solution.calcEquation(
        std::vector(
            {
                std::vector({std::string("a"), std::string("b")}),
                std::vector({std::string("a"), std::string("d")}),
                std::vector({std::string("d"), std::string("e")}),
                std::vector({std::string("b"), std::string("c")})
            }),
        std::vector({2.0, 4.0, 5.0, 3.0}),
        std::vector<std::vector<std::string>>());

    return 0;
}
