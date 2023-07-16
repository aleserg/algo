class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        auto size = mat.size();
        auto sum = 0;
        for ( int i = 0, j = size - 1; i < size; i++, j-- )
            sum += mat[i][i] + ( i != j? mat[j][i] : 0 );  //Проверяем, что i != j, чтобы лишний раз не сложить центральный элемент массива 
        return sum;
      //Можно в конце вычесть центральный элемент (если сторона массива нечетная), но интервьюер может сказать, что складывать и вычитать очень дорого, давай без лишних действий
    }
};
