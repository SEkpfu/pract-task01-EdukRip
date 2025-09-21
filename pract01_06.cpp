

#include <iostream>

using namespace std;

double result(double hour, double rubH, double prem)
{
    return rubH * hour * (1 + prem / 100);
}
double pNalog(double res)
{
    // Будем считать % подоходного налога за 13. Можно также было написать программу для этого, но я не думаю, что это имелось в виду в задачке.
    return res * 0.13;
}
double pSumma(double res)
{
    return res - pNalog(res);
}

double Worker()
{
    cout << "Для работника с почасовой оплатой труда известны:" << endl;

    double hour, rubH, prem, resl;
    cout << "Количество отработанных им часов = ";
    cin >> hour;
    cout << "Ставка почасовой оплаты(руб.в час) = ";
    cin >> rubH;
    cout << "% премии = ";
    cin >> prem;

    resl = result(hour, rubH, prem);

    cout << "Заработано всего: " << resl << endl;

    cout << "Вычтено подоходным налогом: " << pNalog(resl) << endl;

    cout << "Сумма с учётом вычета подоходного налога: " << pSumma(resl) << endl;
    
    return 0;
}


int main()
{
    setlocale(0, "");

    
    Worker();
    

    return 0;
}

