class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<int> cur;
    void generate(vector<int>& nums, int pos )
    {
        res.push_back(cur); //Сразу добавляем в ответ, потому что пустой массив тоже должен быть одним из ответов
        //Доп условий для базового случая не нужно. Когда дойдём до pos == nums.size() просто не сработает for
        for ( int i = pos; i < nums.size(); i++ )
        {
          if ( i != pos && nums[i] == nums[i-1] ) // 1 раз пропускаем, чтобы можно было составлять строки из повторяющихся чисел. Например, [ 2 2 ]
            continue;
          cur.push_back(nums[i]);
          generate( nums, i + 1 );
          cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
      //Нужно для того, чтобы исключать дубликаты. Например, чтобы из массива [ 1, 2, 2 ] не включились в ответ дубликаты [ 1, 2 ] и [ 1, 2 ]
       std::sort(nums.begin(), nums.end()); 
       generate( nums, 0 );
       return res;
    }
};
