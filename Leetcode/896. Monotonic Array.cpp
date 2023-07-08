class Solution {
public:
    //Проверяет, является ли массив монотонным. Только убывающим или только возрастающим (если все элементы равны, то тоже ОК)
    bool isMonotonic(vector<int>& nums) 
    {
      bool isIncr = true; //Массив монотонно возрастает
      bool isDecr = true; //Массив монотонно убывает
      for ( int i = 0; i < nums.size() - 1 ; i++ )
      {
        isIncr = isIncr && nums[i] <= nums[i+1];
        isDecr = isDecr && nums[i] >= nums[i+1];
      }
      return isIncr || isDecr;
    }
};
