class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int hasStock = -prices[0];  //Состояние, когда мы купили и держим акцию. Начальное состояние - обязательно купили первую акцию, иначе формула будет всегда оставлять 0 в качестве своего значения
        int hasNoStock = 0;         //Состояние, когда на руках акции нет
        for ( int i = 1; i < prices.size(); i++ )
        {
            int oldHasNoStock = hasNoStock;
            hasNoStock = std::max( hasNoStock, prices[i] + hasStock - fee ); //Сравниваем состояние без акции и состояние с продажей акции
            hasStock = std::max( oldHasNoStock - prices[i], hasStock ); //Сравниваем состояние без акции + покупка сегодняшней акции и состояние, когда мы купили акцию ранее
        }
        return hasNoStock;        
    }
};
