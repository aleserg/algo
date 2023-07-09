class Solution {
public:
    std::vector<std::vector<int>> res;
    //Генерирует последовательность по её индексу
    void generateSubset(vector<int>& nums, int comb )
    {
        std::vector<int> subset;
      //Т.к. числа не повторяются, то каждое число либо есть в комбинации, либо нет
        for ( int i = 0; i < nums.size(); i++ )
        {
            //Индекс в последовательности интерпретируется как набор бит. Пример:  3 = 011. subset = [ 2 3 ]. Числа 1 нет, т.к. на его позиции стоит 0 (элемент должен отсутствовать).
            if ( comb % 2 )  //можно заменить на ( comb >> i ) & 1. Но это общий вид, который позволяет работать с N-ричными системами счисления
              subset.push_back( nums[i] );
            comb /= 2;  // "Удаляем" младший бит, ближайший старший смещаем
        }
        res.push_back(std::move(subset));
    }
    //Генерирует все возможные комбинации чисел из nums без повторений
    //Пример: [ 1, 2, 3 ]
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int count = pow(2,nums.size()); //Всего возможных комбинаций 2^N ( Пример: 2^3 = 8 )
        for ( int i = 0; i < count; i++ )
          generateSubset(nums,i);
        return res;
    }
};
