class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        std::vector<int> curCol( obstacleGrid.size() + 1 );
        int colIdx = 0;
        curCol[ 1 ] = obstacleGrid[0][0] != 1; //Если в начале камень, то всё бессмысленно, можно тут return 0 просто сделать
        while ( colIdx < obstacleGrid[0].size() )
        {
            for ( int i = 1; i < curCol.size(); i++ )
            {
                if ( obstacleGrid[ i -1 ][ colIdx ] ) //Если здесь камень, то проставляем 0 в ячейку, ибо путей до камня нет
                  curCol[ i ] = 0;
                else
                  curCol[ i ] = curCol[ i ] + curCol[ i - 1 ]; //Всё как и в задаче без камней. См. "62. Unique Paths.cpp"
            }
            colIdx++;
        }
        return curCol.back();
    }
};
