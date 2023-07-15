class Solution {
public:
    int climbStairs(int n) 
    {
      constexpr int STEPS_TO_TRACK = 2;
      std::array<int, STEPS_TO_TRACK> arr{ 1, 2 }; // на первую ступеньку можно забраться 1 способом, на вторую - двумя
      //На третью и далее - сумма комбинаций двух предыдущих ступенек
      for ( int i = 2; i < n; i++ )
      {
        int temp = arr[0] + arr[1];
        arr[0] = arr[1];
        arr[1] = temp;
      }
      return n == 1? 1 : arr[1];
    }
};
