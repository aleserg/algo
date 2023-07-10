class Solution {
public:
    int length{0};
    int end{0};
    std::vector<std::vector<int>> res;
    std::vector<int> cur;
    void generate( int begin )
    {
        //Базовый случай - достижение текущего массива длины k
        if ( cur.size() == length )
            res.push_back(cur);
        else
        {
            for ( int i = begin; i < end; i++ )
            {
                cur.push_back( i );
                generate( i + 1 ); //Числа не могут повторяться, поэтому каждый следующий цикл начинаем с числа большего, чем текущее + нельзя делать одинаковые комбинации [ 1, 2 ] и [ 2, 1 ]
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        length = k;    
        end = n + 1;
        generate(1);
        return res;
    }
};
