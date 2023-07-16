class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        std::vector<int> res{0,0}; //Важно сразу создать ответ, чтобы если ни в одной строке не было ни одной единицы, вернуть [0,0], 
                                   //т.к. хотя бы 1 строка всегда есть и по условию задачи нужно вернуть строку с минимальным индексом и масимальным числом единиц
        for ( int i = 0; i < mat.size(); i++ )
        {
            int ones = 0;
            for ( auto val : mat[i] )
              ones += val;
            if ( ones > res[1] )
            {
              res[0] = i;
              res[1] = ones;
            }
        }
        return res;
    }
};
