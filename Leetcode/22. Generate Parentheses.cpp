class Solution {
public:
    int balance{0};   //Баланс. Если < 0, то где-то была закрытая скобка до открытой.  "(()" - баланс 1.
    std::string cur;  //Текущий редактируемый набор скобок
    std::vector<std::string> res;
    std::array<std::pair<char,int>, 2> charToWeightMap{ std::pair{ '(', 1 }, { ')', -1 }  }; //Скобка и её вес
    int max;          // Количество скобок в последовательности
    void generate( int lvl )
    {   
        //Если сгенерировали нужное количество скобок, убеждаемся, что количество закрытых == количеству открытых
        if ( lvl == max && balance == 0 )
        {
            res.push_back(cur);
            return;
        }
        //Если баланс < 0, то где-то была закрытая скобка до открытой. Генерировать дальше нет смысла. Последовательность не валидна
        //max - lvl - количество скобок, которых осталось догенерировать. Если осталось меньше скобок, чем открыто, то генерировать дальше бессмысленно. 
        //Пример max = 6. cur == "((((". lvl == 4. max - lvl == 2. balance = 4. Мы не можем догенерировать 4 скобки, когда осталось всего 2.
        if ( balance < 0 || max - lvl < balance )
          return;
        lvl++;
        for ( auto & p : charToWeightMap )
        {
            cur.push_back(p.first);
            balance += p.second;
            generate(lvl);  
            balance -= p.second;
            cur.pop_back();
        }        
    }
    vector<string> generateParenthesis(int n) 
    {
        max = n * 2; //Важно! n - количество пар скобок. 3 открытых 3 закрытых. Итого 6.
        generate(0);
        return res;
    }
};
