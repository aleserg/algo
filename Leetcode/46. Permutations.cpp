class Solution {
public:
    /*
      Для понимания перестановок проще представлять массив как число [ 1, 2, 3 ] -> 123
      Следующая перестановка это минимальное число, которое можно составить из предложенных цифр (но больше текущего):
      123 -> 132 -> 213 -> 231 -> 312 -> 321
      Если такого числа найти невозможно, то снова возвращаемся в начало (минимальное число из предложенных цифр)
    */
    std::array<bool, 21> used;           //Использованные числа. По-хорошему, здесь надо хранить индексы чисел, чтобы не зависеть от диапазона значений, либо использовать <set>
    std::vector<std::vector<int>> res; 
    std::vector<int> path;               //Комбинация из чисел, собранная на момент вызова метода
    bool isUsed( int num )
    {
        return used[ num + 10 ]; //Выравнивание, т.к. по констрейтам  -10 <= nums[i] <= 10. Лучше здесь использовать индексы или <set>
    }
    void setUsed( int num, bool isUsed )
    {
        used[ num + 10 ] = isUsed;
    }

    void permute(vector<int>& nums, int step )
    {
        //Глубина рекурсии - размер массива, т.к. числа не могут повторяться
        if ( step == nums.size() )
            res.push_back(path);
        else
        {
            step++;
            for ( auto v : nums )  //Такой перебор позволит получить перестановки в правильном порядке (не смотря на то, что в задаче это не важно). Достаточно лишь отсортировать nums перед началом
            {
                if ( isUsed( v ) )
                 continue;
                setUsed( v, true );
                path.push_back( v );
                permute( nums, step );
                setUsed( v, false );
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        permute( nums, 0 );
        return res;
    }
};
