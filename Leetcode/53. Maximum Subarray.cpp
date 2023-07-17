class Solution {
public:
    /*
     Исходный массив: [-2,1,-3,4,-1,2,1,-5,4]
     Сумма          : [-2,1,-2,4, 3,5,6,-1,3]
     Ответ          : [-2,1,-2,4, 3,5,6, 6,6]
    */
    int maxSubArray(vector<int>& nums) 
    {
        int sum = nums[0];
        int maxSum = sum; //Ответ - максимальная сумма во всем массиве
        for ( int i = 1; i < nums.size(); i++ )
        {
          auto val = nums[i];
          sum = std::max( val, sum + val ); //Выбираем, стоит ли начать отсчитывать подмассив массив сначала или же продолжить старый рассчет
          maxSum = std::max( sum, maxSum ); //Запоминаем максимальную сумму
        }
        return maxSum;
    }
};
