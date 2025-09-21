

#include <iostream>
#include <vector>


using namespace std;

void result(double hour, double rubH, double &res, double &pNa, double &pSu)
{
    res = hour * rubH;
    pNa = res * 0.13;
    pSu = res - pNa;
}

void Worker(double &hour, double &rubH)
{
    cout << "\nДля работника с почасовой оплатой труда известны:" << endl;

    cout << "Количество отработанных им часов = ";
    cin >> hour;
    cout << "Ставка почасовой оплаты(руб.в час) = ";
    cin >> rubH;
}

int main()
{
    //8 Задание. Т.к. массивов 2 я предполагаю мы премию больше не выдаём
    setlocale(0, "");
    int k;
    int i = 0;
    cout << "Введите количество рабочих: ";
    cin >> k;

    int minN = 0, maxN = 0, N5k = 0, SumN = 0;
    vector<double> N5t = {};
    double maxSu = 0, minSu = 10000000000000000;

    double* hour = new double[k];
    double* rubH = new double[k];
    double* pNa = new double[k];
    double* pSu = new double[k];
    double res;
    
    while (i < k)
    {
        Worker(hour[i], rubH[i]);
        result(hour[i], rubH[i], res, pNa[i], pSu[i]);

        if (pSu[i] > 50000)
        {
            N5k += 1;
            N5t.push_back(i+1);
        }
            
        if (maxSu < pSu[i])
        {
            maxSu = pSu[i];
            maxN = i + 1;
        }
        else if (minSu > pSu[i])
        {
            minSu = pSu[i];
            minN = i + 1;
        }
        SumN += pNa[i];
        i++;
    }
    cout << "\nНомер работника, получившего меньше всех " << minN << endl;
    cout << "Макс зарплата: " << maxSu << ", Заработал работник " << maxN << endl;
    cout << "Заработало больше 50 тысяч. " << N5k << ", номера рабочих: " << endl;
    for (int j : N5t)
    {
        cout << j << " ";
    }
    cout << "\nСумма налогов: " << SumN;
}

