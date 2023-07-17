class Solution {
public:
    /*
         Исходный массив:
          1 4    
          2 5 
          3 6
          Начальное значение curCol:
          INT_MAX  первый элемент фейковый - защита от выхода за границы массива
           0
          INT_MAX
          INT_MAX
          Почему именно так? Потому что кратчайший путь определяется возможными ходами (сверху и слева). Соответственно, мы берем минимум из этих значений и прибавляем текущее значение ячейки.
          Точка старта - элемент с индексом 1. Поэтому туда поставили 0. В остальные ячейки INT_MAX, потому что если 0, 
          то первый проход будет думать, что кратчайший путь к элементу [0][1] ( 2 ) это 0 (т.к. слева 0), а на самом деле это 1 (т.к. у нас есть единственный путь - сверху.
          INT_MAX                     INT_MAX                        INT_MAX      
          0        min(0,INT_MAX) + 1    1     min(1,INT_MAX) + 4       5
          INT_MAX  min(INT_MAX,1) + 2    3     min(3,5)       + 5       8
          INT_MAX  min(INT_MAX,3) + 3    6     min(6,8)       + 6       12
     */
    int minPathSum(vector<vector<int>>& grid) 
    {
        std::vector<int> curCol( grid.size() + 1, INT_MAX );
        curCol[1] = 0;
        for ( int j = 0; j < grid[0].size(); j++ )
        {
            for ( int i = 1; i < curCol.size(); i++ )
                curCol[i] = std::min(curCol[i-1], curCol[i]) + grid[i-1][j];
        }
        return curCol.back();
    }
};
