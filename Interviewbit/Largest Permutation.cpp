vector<int> Solution::solve(vector<int> &A, int B) 
{
    std::vector<int> numToPosMap( A.size() + 1 ); //Дополнительный элемент, т.к. числа начинаются с 1
    for ( int i = 0; i < A.size(); i++ )
        numToPosMap[ A[i] ] = i; //Число A[i] находится на позиции i
    
    for ( int i = 0, curNum = A.size(); i < A.size() - 1 && B > 0; i++, curNum-- )
    {
        if ( A[i] == curNum ) //Если число и так находится на своём месте, то нет смысла его перемещать. Количество перестановок не уменьшаем
          continue;
        B--; //Уменьшаем количество оставшихся перестановок
        int temp =  A[i];
        std::swap( A[i], A[ numToPosMap[ curNum ] ]  ); // numToPosMap[ curNum ] - где находится требуемое число
        std::swap( numToPosMap[ curNum ], numToPosMap[ temp ] ); // A[i] на данный момент == curNum, поэтому нужна переменная temp, чтобы не потерять значение A[i] до свапа
    }
    return A;    
}
