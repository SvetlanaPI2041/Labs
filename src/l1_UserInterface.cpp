#include <iostream>
#include <string>
#include <cassert>

#include <sstream>

#include "hw/l2_ApplicationLayer.h"

using namespace std;

class TerminalOutput : public IOutput
{
public:
    virtual void Output(string s) const override final;
};


void TerminalOutput::Output(string s) const
{
    cout << s << endl;
}


int main(int , char **)
{
    TerminalOutput out;
    Application    app(out);

   cout << "Введите команду для работы с карточкой 'Курс': " << endl;
   cout << "l - Загрузить данные;" << endl;
   cout << "s - Сохранить данные;" << endl;
   cout << "c - Очистить данные;" << endl;
   cout << "a - Добавить данные (a < название курса> <продолжительность> <язык программирования> <сложность курса> <стоимость обучения>);" << endl;
   cout << "r - Удалить данные (r <id>);" << endl;
   cout << "u - Изменить данные (u <id> <Новое название курса> <Новая продолжительность> <Новый язык программирования> <Новая сложность курса> <Новая стоимость обучения>);" << endl;
   cout << "v - Просмотр текущих данных;" << endl;

    for (string line; getline(cin, line); )
    {
        if (line.empty())
            break;

        istringstream  iss(line);
        vector<string> args;
    
        for(string str; iss.good();)
        {
            iss >> str;
            args.emplace_back(str);
        }

        if (!app.performCommand(args))
            return 1;
    }

    cout << "Выполнение завершено успешно" << endl;
    return 0;
}