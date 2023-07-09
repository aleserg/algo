class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    bool combinationSum( vector<int>& candidates, int target, int curSum, int beginPos )
    {     
        //на моменте 2 2 2 2 сработает условие, что дальше углубляться нет смысла, соответственно комбинации 2 2 2 3 и далее уже не будут перебираться
        if ( target <= curSum )
        {
            if ( target == curSum )
              res.push_back(path);
            return false; //Дальше нет смысла продолжать, т.к. массив кандидатов отсортирован, а мы уже дошли до target
        }
        bool needContinue = true;
        for ( int i = beginPos; i < candidates.size() && needContinue; i++ )
        {
            //beginPos - индекс, с которого вложенный метод начнёт свой перебор. 
            //То есть если сейчас path = [ 2 3 ], то следующий вызов начнёт перебирать с 3, число 2 перебирать не будет (иначе мы будем возвращать дубликаты, такие как [ 2 2 3 ], [ 2 3 2 ] и [ 3 2 2 ] )
            path.push_back(candidates[i]);
            curSum += candidates[i]; 
            needContinue = combinationSum(candidates, target, curSum, i);
            curSum -= candidates[i];
            path.pop_back();
        }
        return true; //продолжаем перебор
    }
    // target = 7. candidates = [2,3,6,7]
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        std::sort(candidates.begin(), candidates.end()); //Обязательно нужен возрастающий порядок для оптимизации
        combinationSum(candidates, target, 0, 0 );
        return res;
    }
};
