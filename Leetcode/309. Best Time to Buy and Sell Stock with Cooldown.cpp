class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int hasStock = -prices[0];   //Состояние, при котором мы держим акцию на руках (т.е. купили её сегодня, либо в один из предыдущих дней)
        int hasNoStock = 0;          //Состояние, при котром мы продали акцию сегодня, либо в один из предыдущих дней
        int cooldown = 0;            //Состояние, на 1 день отстающее от hasNoStock, т.к. мы не можем покупать ничего в течение дня после продажи
        //В целом задача в каждый момент времени рассматривает параллельно несколько сценариев и выбирает из них лучший ( а что будет если: .. )
        for ( int i = 1; i < prices.size(); i++ )
        {
            int oldHasNoStock = hasNoStock;
            hasNoStock = std::max( hasNoStock, hasStock + prices[i] );  //Выбираем между продажей акции, которая есть на руках, или её отсутствием в предыдущий день (т.е. ничего не деланием)
            hasStock = std::max( cooldown - prices[i], hasStock );      //Выбираем между покупкой акции после кулдауна или держанием на руках существующей акции (т.е. ничего не деланием)
            cooldown = oldHasNoStock;
        }
        return hasNoStock;
    }
};
