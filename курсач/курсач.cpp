#include <iostream>
#include <string>
using namespace std;
/*
int searchIdSymbol(string str, char symbol)
{
    int idSymbol = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == symbol)
        //{
            idSymbol = i;
            //break;    возможно пригодиться
        //}
    }
    return idSymbol;
}

string cutBkt(string str)
{
    int idBktOne = searchIdSymbol(str,'(');//поиск айди открывающей скобки
    int idBktTwo = searchIdSymbol(str, ')');// поиск айди закрывающей скобки
    string expr = "";//переменная для выражения из скобок

        //cout << idBktOne << "  " << idBktTwo<<"\n";
    expr.append(str, idBktOne + 1, idBktTwo - idBktOne-1);
        //cout << expr <<"   expr\n";
    //добавляет в конец строки expr символы строки str начиная с символа с индексом pos количеством count.
    str.erase(idBktOne, idBktTwo - idBktOne+1);
    //удаляет из строки str  с символа с индексом pos количеством count
        //cout << str << "  str\n";
    str += expr;
        //cout << str << "  str\n";
    return str;
}
/*
    Памятка
или             "+"
и               "*"
не              "!"
импликация      ">"
тождество       "~"
искл. или       "-~"
штрих Шафера    "|" "-*"
стрелка Пирса   "-+"
//

int main()
{
    string test = "x+(x+y)";
    cout << test<<endl;
    cout << cutBkt(test);
}
*/

string simpl(string text, string zkn,string pin)
{
    int id = text.find(zkn);
    text.replace(id, zkn.length(), pin);// заменяем N символов начиная с id на pin
    //cout << "id = " << id << "  len= " << zkn.length() << "\n";
    return text;
}
int main()
{
    string text = "A*0";

    cout <<"Start text\t" << text << "\n";

    while (true)
    {
        //двойное отрицание
        if (text.find("!!A") != string::npos)//проверка на вхождение
            text = simpl(text, "!!", "");       //!!A=A

        //исключение третьего
        else if (text.find("A+!A") != string::npos)
            text = simpl(text, "A+!A", "1");    //A+!A=1

        else if (text.find("A*!A") != string::npos)
            text = simpl(text, "A*!A", "0");    //A+!A=0

        //операции с константами
        else if (text.find("A*0") != string::npos)
            text = simpl(text, "A*0", "0");      //A*0=0

        else if (text.find("A*1") != string::npos)
            text = simpl(text, "A*1", "A");      //A*1=A

        else if (text.find("A+0") != string::npos)
            text = simpl(text, "A+0", "A");      //A+0=A

        else if (text.find("A+1") != string::npos)
            text = simpl(text, "A+1", "1");      //A+1=1

        //повторения
        else if (text.find("A+A") != string::npos)
            text = simpl(text, "A+A", "A");      //A+A=A

        else if (text.find("A*A") != string::npos)
            text = simpl(text, "A*A", "A");      //A*A=A

        //поглощения
        else if (text.find("A*(A+B)") != string::npos)
            text = simpl(text, "A*(A+B)", "A");     //A*(A+B)=A

        else if (text.find("A+A*B") != string::npos)
            text = simpl(text, "A+A*B", "A");       //A+A*B=A

        //переместительный
        else
            break;
    }
    cout << "Final text\t" << text << "\n";

}