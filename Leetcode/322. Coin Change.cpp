class Solution
{
public:
  int coinChange( vector<int> & coins, int amount )  //Оптимально по памяти, не оптимально по времени
  {
    std::sort( coins.begin(), coins.end() );
    //Оптимальный по памяти вариант O(  min( amount, coin.max ) + 1 )
    // Т.е худший случай это 12. Т.к монет максимум 12
    //По времени O( n * ( min( amount, coin.max ) + 1 ) )
    std::vector<int> res( std::min( coins.back(), amount ) + 1, -1 );
    res[ 0 ] = 0;
    for ( int i = 0; i <= amount; i++ )
    {
      int curAmount = i;
      if ( i >= res.size() )
      {
        for ( int k = 0 ; k < res.size() - 1; k++ )
          res[ k ] = res[ k + 1 ];
        res.back() = -1;
        curAmount = res.size() - 1;
      }
      int combinations = INT_MAX;
      for ( auto coin : coins )
      {
        if ( coin > curAmount )
          break;
        if ( res[ curAmount - coin ] != -1 )
          combinations = std::min( combinations, res[ curAmount - coin ] + 1 );
      }
      if ( combinations != INT_MAX )
        res[ curAmount ] = combinations;
    }
    return res.back();
  }
};

class Solution
{
public:
  std::vector<int> res;
  int circularBufferPos = 0;
  int getValueFromBuf( int pos )
  {
    return pos < 0? res[ pos + res.size() ] : res[ pos ];
  }
  int coinChange( vector<int> & coins, int amount )  //Быстро и оптимально по памяти за счёт циклического буфера. Вариант ещё быстрее - выделить памяти размером с amount + 1. Но асимптотика будет такой же
  {
    std::sort( coins.begin(), coins.end() );
    //Оптимальный по памяти вариант O(  min( amount, coin.max ) + 1 )
    // Т.е худший случай это 12. Т.к монет максимум 12
    //По времени O( n )
    res.assign( std::min( coins.back(), amount ) + 1, -1 );
    res[ 0 ] = 0; //это нужно для начала (чтобы пытаясь набрать amount монетой того же номинала, мы получили в ответе 1, а не 0 ) comb = res[ 5 (amount) - 5 (coin) ] + 1 (мы же использовали монету, добавляем)
    for ( int curAmount = 1; curAmount <= amount; curAmount++ )
    {
      circularBufferPos = curAmount % res.size();
      int combinations = INT_MAX;
      for ( auto coin : coins )
      {
        if ( coin > curAmount )
          break;
        int combWithCoin = getValueFromBuf( circularBufferPos - coin );
        if ( combWithCoin != -1 )
          combinations = std::min( combinations, combWithCoin + 1 );
      }
      res[ circularBufferPos ] = combinations == INT_MAX? -1 : combinations;
    }
    return res[ circularBufferPos ];
  }
};
