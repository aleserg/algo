class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        if ( m * n != original.size() ) //Даже если весь original влезает в m * n, нас это не устраивает, надо чтобы прям одинаковое число элементов было
          return {};
        std::vector<std::vector<int>> res( m, std::vector<int>( n ) );
        for ( int i = 0; i < original.size(); i++ )
          res[ i / n ][ i % n ] = original[i];
        return res;        
    }
};
