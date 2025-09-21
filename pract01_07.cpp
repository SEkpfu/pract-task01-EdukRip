

#include <iostream>


using namespace std;

void result(double hour, double rubH, double prem, double &res, double &pNa, double &pSu)
{
    res = hour * rubH * (1 + prem / 100);
    pNa = res * 0.13;
    pSu = res - pNa;
}

void Worker(double &hour, double &rubH, double &prem, string &fam)
{
    cout << "Для работника с почасовой оплатой труда известны:" << endl;

    cout << "Количество отработанных им часов = ";
    cin >> hour;
    cout << "Ставка почасовой оплаты(руб.в час) = ";
    cin >> rubH;
    cout << "% премии = ";
    cin >> prem;
    cout << "Введите фамилию работника: ";
    cin >> fam;
}

int main()
{
    setlocale(0, "");
    int k = 1, mk = 0;
    double mSu = 0; // Для макс
    double sSu = 0;

    while (k < 6)
    {
        double hour, rubH, prem, res, pNa, pSu;
        string fam;


        cout << "Работник #" << k << endl;
        Worker(hour, rubH, prem, fam);

        result(hour, rubH, prem, res, pNa, pSu);

        cout << "Заработано всего: " << res << endl;

        cout << "Вычтено подоходным налогом: " << pNa << endl;

        cout << "Сумма с учётом вычета подоходного налога: " << pSu << endl;

        sSu += pSu;

        if (pSu > mSu)
        {
            mSu = pSu;
            mk = k;
        }
        if (pSu < 1000)
        {
            cout << fam << endl;
        }
        if (pSu > 50000)
        {
            cout << fam[0] << "-" << fam[fam.length() - 1] << endl;
        }

        k++;
    }
    
    cout << "Больше заработал работник под номером " << mk << endl; //При одинаковых не говорит нормально
    cout << "Вместе работники заработали (с вычетом налога): " << sSu << endl;
    cout << "Средняя зарплата в бригаде: " << sSu / (k - 1);

    return 0;
}

