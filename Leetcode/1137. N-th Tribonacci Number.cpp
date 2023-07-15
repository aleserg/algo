class Solution {
public:
    int tribonacci(int n) 
    {
        const auto TRANSFERS = 3;
        std::array<int, TRANSFERS> prev{ 0, 1, 1 };
        //В задачах на динамику надо искать как переиспользовать результаты предыдущих вычислений
        for ( int i = 2; i < n; i++ )
        {
            int temp = prev[0] + prev[1] + prev[2];
            prev[0] = prev[1];
            prev[1] = prev[2];
            prev[2] = temp;
        }
        return n < 3? prev[n] : prev[2];
    }
};
