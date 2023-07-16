class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool needFillFirstRow = false;
        bool neefFillFirstCol = false;
        //Если в изначальной матрице в первом столбце был хотя бы один 0, то потом мы должны будем его полностью заполнить нулями
        for ( int i = 0; i < matrix.size(); i++ )
           neefFillFirstCol = neefFillFirstCol || matrix[i][0] == 0;
        //Если в изначальной матрице в первой строке был хотя бы один 0, то потом мы должны будем её полностью заполнить нулями
        for ( int j = 0; j < matrix[0].size(); j++ )
           needFillFirstRow = needFillFirstRow || matrix[0][j] == 0;
        //В первую строку и первый столбец заносим данные о том, какие строки/столбцы должны быть заполнены нулями
        for ( int i = 0; i < matrix.size(); i++ )
        {                           
            for ( int j = 0; j < matrix[0].size(); j++ )
            {
                if ( matrix[i][j] != 0 )
                  continue;
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
        //Заполняем нулями все необходимые строки, кроме первой
        for ( int i = 1; i < matrix.size(); i++ )
        {
            if ( matrix[i][0] != 0 )
              continue;
            for ( int j = 1; j < matrix[0].size(); j++ )
              matrix[i][j] = 0;
        }
        //Заполняем нулями все необходимые столбцы, кроме первого
        for ( int j = 1; j < matrix[0].size(); j++ )
        {
            if ( matrix[0][j] != 0 )
              continue;
            for ( int i = 1; i < matrix.size(); i++ )
              matrix[i][j] = 0;
        }
        //Заполним нулями первую строку, если нужно
        if ( needFillFirstRow )
        {
            for ( int j = 0; j < matrix[0].size(); j++ )
              matrix[0][j] = 0;
        }
        //Заполним нулями первый столбец, если нужно
        if ( neefFillFirstCol )
        {
            for ( int i = 0; i < matrix.size(); i++ )
              matrix[i][0] = 0;
        }
    }
};
