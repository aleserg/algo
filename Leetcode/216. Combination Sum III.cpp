class Solution {
public:
  constexpr static auto MIN_DIGIT = 1;
  constexpr static auto MAX_DIGIT = 9;
  std::vector<std::vector<int>> res;
  std::vector<int> cur;
  //Отличия от других задач на бэктрекинг: 
  //1) набор цифр всегда один и тот же
  //2) длина комбинации всегда одинаковая
  void generate(  int count, int target, int digit, int sum )
  {
    if ( !count ) //Если бы не нужно было искать комбинации определенной длины, то условия бы не было, проверялось бы только target == sum
    {
      if ( target == sum ) res.push_back( cur );
      return;
    }
    count--;
    if ( sum < target  )
    {
      for ( int i = digit; i <= MAX_DIGIT; ++i)
      {
        cur.push_back( i );
        sum += i;
        generate( count, target, i + 1, sum );
        sum -= i;
        cur.pop_back();
      }
    }
  }
  std::vector<std::vector<int>> combinationSum3( int k, int n )
  {
    generate( k, n, MIN_DIGIT, 0 );
    return res;
  }
};
