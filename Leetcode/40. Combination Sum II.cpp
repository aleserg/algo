class Solution
{
public:
  std::vector<std::vector<int>> res;
  std::vector<int> cur;
  void generate( std::vector<int>& candidates, int target, int sum, int pos )
  {
    if ( sum == target )
      res.push_back( cur );
    else if ( sum < target ) //Т.к. массив отсортирован по возрастанию, то дальше нет смысла пытаться искать подходящие комбинации
    {
      for ( int i = pos; i < candidates.size(); i++ )
      {
        //Защита от генерации одинаковых комбинаций
        if ( i != pos && candidates[ i ] == candidates[ i - 1 ] )
          continue;
        cur.push_back( candidates[ i ] );
        sum += candidates[ i ];
        generate( candidates, target, sum, i + 1 );
        sum -= candidates[ i ];
        cur.pop_back();
      }
    }
  }
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target )
  {
    std::sort(candidates.begin(),candidates.end());
    generate( candidates, target, 0, 0 );
    return res;
  }
};
