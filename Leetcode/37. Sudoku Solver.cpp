class Solution
{
public:
  enum
  {
    ROW = 0,  //Занятые числа в строке
    COL,      //Занятые числа в столбце
    SQUARE,   //Занятые числа в квадрате
    COUNT
  };
  static const auto MAX_DIGIT = 9;
  static const auto MIN_DIGIT = 1;
  static const auto SQUARE_SIZE = 9;
  using UsedDigitsList = std::array<std::array<bool, MAX_DIGIT + 1>, SQUARE_SIZE>;
  std::array<UsedDigitsList, COUNT> checkLists{};

  int getSquareIdx( int row, int col )
  {
    return row / 3 * 3 + col / 3;
  }

  void fillCheckLists( std::vector<std::vector<char>>& board )
  {
    for( int i = 0; i < board.size(); i++ )
    {
      for ( int j = 0; j < board[0].size(); j++ )
      {
        auto symb = board[ i ][ j ];
        if ( symb == '.' )
          continue;        
        placeDigit( symb - '0', i, j, true );
      }
    }
  }

  bool canPlaceDigit( int digit, int row, int col )
  {
    return !checkLists[ ROW ][ row ][ digit ] && !checkLists[ COL ][ col ][ digit ] && !checkLists[ SQUARE ][ getSquareIdx( row, col ) ][ digit ];
  }

  void placeDigit( int digit, int row, int col, bool val )
  {
    checkLists[ COL ][ col ][ digit ] = val;
    checkLists[ ROW ][ row ][ digit ] = val;
    checkLists[ SQUARE ][ getSquareIdx( row, col ) ][ digit ] = val;
  }

  std::pair<int,int> getRowCol( int pos )
  {
    return { pos / SQUARE_SIZE, pos % SQUARE_SIZE };
  }

  bool solve( int pos, std::vector<std::vector<char>>& board )
  {
    pos++;
    if ( pos == SQUARE_SIZE * SQUARE_SIZE )
      return true;
    const auto [ row, col ] = getRowCol( pos );
    //Если уже стоит какое-то число, то идём дальше, нам его менять нельзя, это условие задачи
    if ( board[ row ][ col ] != '.' )
      return solve( pos, board );
      
    for ( int i = MIN_DIGIT; i <= MAX_DIGIT; i++ )
    {
      //Если число уже есть в строке/столбце/квадрате, то пропускаем, ищем другое
      if ( !canPlaceDigit( i, row, col ) )
        continue;
      placeDigit( i, row, col, true );
      board[ row ][ col ] = i + '0';
      if ( solve( pos, board ) )
        return true;    //Решение найдено, выходим из всех рекурсий, не заменяя цифры обратно на '.'
      board[ row ][ col ] = '.'; // Возвращаем точку, чтобы последующие вызовы не игнорировали данную ячейку
      placeDigit( i, row, col, false );    
    }
    return false;
  }

  void solveSudoku(std::vector<std::vector<char>>& board )
  {
    fillCheckLists( board );
    solve( -1, board );
  }
};
