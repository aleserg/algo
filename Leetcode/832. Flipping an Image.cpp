class Solution
{
public:
  vector<vector<int>> flipAndInvertImage( vector<vector<int>>& image )
  {
    for ( int i = 0; i < image.size(); i++ )
    {
      int l = 0;
      int r = image[ 0 ].size() - 1;
      while ( l < r )
      {
        std::swap( image[ i ][ l ], image[ i ][ r ] );
        image[ i ][ l ] = image[ i ][ l ] ? 0 : 1;
        image[ i ][ r ] = image[ i ][ r ] ? 0 : 1;
        l++;
        r--;
      }
      if ( l == r )
        image[ i ][ l ] = image[ i ][ l ] ? 0 : 1; //Дополнительное условие. Чтобы без этого, нужно отдельно реверсить каждую строку, а потом в двойном цикле флипать значения
    }
    return image;
  }
};
