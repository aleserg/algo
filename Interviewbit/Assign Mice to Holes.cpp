//Идея решения в том, чтобы распределить мышей и норы в порядке возрастания на оси координат. И тогда каждая мышь должна будет побежать в "свою" (по индексу) нору. 
//Данный вариант будет оптимальным во всех возможных случаях.
int Solution::mice(vector<int> &A, vector<int> &B) 
{
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    int maxPath = 0;
    for ( int i = 0; i < A.size(); i++ )
        maxPath = std::max( maxPath, std::abs( A[i] - B[i] ) );
    return maxPath;
}
