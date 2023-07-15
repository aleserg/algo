class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        constexpr int STEPS_TO_TRACK = 2;
        std::array<int, STEPS_TO_TRACK> minCost{0,0}; //Минимальная стоимость, за которую можно добраться на 2 предыдущие ступеньки (в начале это ступеньки с индексами -1 и -2, т.е. несуществующие)
        for ( int i = 0; i < cost.size(); i++ )
        {
            auto temp = minCost[1];
            minCost[1] = std::min( minCost[0], minCost[1] ) + cost[i]; //к минимальному весу из двух предыдущих ступенек добавляем вес ступеньки, на которую сейчас наступаем
            minCost[0] = temp;
        }
        return std::min( minCost[0], minCost[1] ); //последняя ступенька она как бы без стоимости. Нам нужно просто выбрать из двух предыдущих минимальную стоимость, т.к. мы можем шагать на 1 или на 2 ступеньки за раз
    }
};
