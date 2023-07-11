 class Solution
 {
   //Комбинации букв на каждой клавише
   std::array<std::vector<char>, 8> letters{ std::vector<char>{ 'a', 'b', 'c' }, { 'd', 'e', 'f'}, {'g','h','i'}, { 'j', 'k', 'l' }, { 'm','n','o'}, {'p','q', 'r','s'}, { 't','u','v' }, {'w','x','y','z'} };
 public:
   std::vector<std::string> res;
   std::string cur;
   void combine( const std::string & digits, int pos )
   {
     pos++;
     if ( pos == digits.size() )
     {
       res.push_back( cur ); //Если цифры закончились, добавляем в ответ
       return;
     }
     // '2' - первая кнопка, на которой есть буквы. Массив на 8 кнопок, соответственно, нужно сместить '2' на индекс 0.
     for ( auto symb : letters[ digits[ pos ] - '2' ] )
     {
       cur.push_back( symb );
       combine( digits, pos );
       cur.pop_back();
     }
   }
   std::vector<std::string> letterCombinations(std::string digits )
   {
     //Если не проверить, то алгоритм вернет массив с одной пустой строкой, что не верно
     if ( digits.empty() )
       return res;
     combine( digits, -1 );
     return res;
   }
 };
