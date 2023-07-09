class Solution {
public:
    vector<vector<string>> res;
    std::vector<std::string> curVar;
    /*
      Королева может "бить" по вертикали, по горизонтали и по диагонали
      Сложность задачи состоит в том, что непонятно как проверять доступность клетки по диагонали (не бьёт ли её какая-либо из других королев)

         0  1  2  3 индексация столбцов
     Индексация диагоналей LeftToRight. Формула ( i - j ). Либо <set>, либо центрировать самостоятельно
     0   0  1  2  3
     1  -1  0  1  2
     2  -2 -1  0  1
     3  -3 -2 -1  0

         0  1  2  3 индексация столбцов
     Индексация диагоналей RightToLeft. Формула ( i + j )
     0   0  1  2  3
     1   1  2  3  4
     2   2  3  4  5
     3   3  4  5  6
    */
    std::vector<bool> rows; //занятые строки. можно не создавать, т.к. алгоритм проходится построчно. Проверка этого массива всегда будет проходить
    std::vector<bool> cols; //занятые столбцы
    std::vector<bool> LRdiag; //занятые диагонали слева-направо (середина проходит с левого верхнего угла в правый нижний)
    std::vector<bool> RLdiag; //занятые диагонали справа-налево (середина проходит с правого верхнего угла в левый нижний)
    void resize( int n )
    {
        rows.resize(n);
        cols.resize(n);
        LRdiag.resize( 2 * n - 1 ); //для поля 4х4 это 7 диагоналей, т.е. максимальный индекс диагонали 6. См. рис. выше
        RLdiag.resize( 2 * n - 1 );
    }
    // + rows.size() - 1 ( 4 - 1 = 3 ) - линейное смещение всех индексов из отрицательного диапазона ( -3 превращает в 0, 0 в 3 и тд )
    bool canPlace( int i, int j )
    {
        return !rows[i] && !cols[j] && !RLdiag[ i + j ] && !LRdiag[ i - j + rows.size() - 1 ];
    }
    void setIsBusy( int i, int j, bool isBusy )
    {
        rows[i] = cols[j] = RLdiag[ i + j ] = LRdiag[ i - j + rows.size() - 1 ] = isBusy;
    }

    //создаёт строку из точек и ставит в нужный индекс королеву
    std::string placeQueen( int idx )
    {
        std::string s( rows.size(), '.' );
        s[idx] = 'Q';
        return s;
    }

    // в качестве row передаётся индекс предыдущего уровня (заполненного)
    void solve( int row )
    {
        row++;
        if ( row == rows.size() )
        {
          res.push_back( curVar );
          return;
        }
        for ( int col = 0; col < cols.size(); col++ )
        {
            if ( !canPlace(row, col) )
              continue;
            setIsBusy(row, col, true);
            curVar.push_back( placeQueen(col) );
            solve(row);
            curVar.pop_back();
            setIsBusy(row, col, false);
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        resize(n);
        solve( -1 );
        return res;
    }
};
