

#include <iostream>
#include <vector>


using namespace std;

int maxN(vector<int> arr)
{
    int i = 0, n = 0;
    int im = 0;
    for (int j : arr)
    {
        if (n < j)
        {
            n = j;
            im = i;
        }
        i++;

    }
    return im;
}
int minN(vector<int> arr)
{
    int i = 0, n = 10000000;
    int im = 0;
    for (int j : arr)
    {
        if (n > j)
        {
            n = j;
            im = i;
        }
        i++;

    }
    return im;
}
int countN(vector<int> arr)
{
    int n;
    cout << "Задайте число: ";
    cin >> n;
    int i = 0;
    for (int j : arr)
    {
        if (j > n)
            i++;
    }
    return i;
}
int sumN(vector<int> arr)
{
    int i = 0;
    for (int j : arr)
    {
        i += j;
    }
    return i;
}

int main()
{
    setlocale(0, "");

    vector<int> Okak = { 1, 161, 8767, -98, 57, 876, 524 };
    for (int j : Okak)
    {
        cout << j << endl;
    }

    cout << "Мин. номер: " << minN(Okak) << endl;
    cout << "Макс. номер: " << maxN(Okak) << ", Максимальный элемент: " << Okak[maxN(Okak)] << endl;
    cout << "Количество элементов больше заданого числа: " << countN(Okak) << endl;
    cout << "Сумма элементов: " << sumN(Okak) << endl;


}

