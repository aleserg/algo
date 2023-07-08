class Solution {
public:
    /*
     * Числа фибоначчи [ 0 1 1 2 3 5.. ]. каждое следующее - сумма двух предыдущих
     * Элегантность решения в том, что здесь нет if для n <= 1. Платим за это тем, что for пройдёт один лишний раз (то есть в f2 по факту будет число фибоначчи с индексом n + 1). 
     */
    int fib(int n) 
    {
        int f1 = 0;
        int f2 = 1;
        for ( int i = 0; i < n; i++)
        {
            std::swap(f1,f2); 
            f2 += f1;             
        }
        return f1;
    }
};
