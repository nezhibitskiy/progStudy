// codeWarsNarcissisticNumber.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int valueDigitNum(int value)
{
    int count = 0;
    do
    {
        count++;
        value = value / 10;
    } while (value != 0);
    return count;
}

int main()
{
    int value;
    std::cin >> value;
    int power = valueDigitNum(value);
    int tmpValue = value;
    int countedValue = 0;
    for (uint8_t i = 0; i < power; i++)
    {
        int remainder = (tmpValue % 10);
        int result = 1;
        for (uint8_t j = 0; j < power; j++)
        {
            result *= remainder;
        }
        countedValue += result;
        tmpValue /= 10;
    }

    if (countedValue == value)
        return true;
    else
        return false;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
