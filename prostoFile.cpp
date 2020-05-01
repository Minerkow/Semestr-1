#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>

/*Если диапазон содержит меньше 2 элементов, выйти из функции.
Создать вектор, содержащий все элементы текущего диапазона.
Разбить вектор на две равные части. (В этой задаче гарантируется, что длина передаваемого диапазона является степенью двойки, так что вектор всегда можно разбить на две равные части.)
Вызвать функцию MergeSort от каждой половины вектора.
С помощью алгоритма merge слить отсортированные половины, записав полученный отсортированный диапазон вместо исходного.*/
using namespace std;

ostream& operator<<(ostream &out, vector<int> v);

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if (range_end - range_begin < 2)
        return;
    vector<typename RandomIt::value_type> v(range_begin, range_end);
    auto midle = v.begin() + (v.begin() - v.end()) / 2;
    MergeSort(v.begin(), midle);
    MergeSort(midle, v.end());
    merge(v.begin(), midle, midle, v.end(), range_begin);
}

ostream& operator<<(ostream &out, vector<int> v)
{
     for (int i = 0; i < v.size();  ++i)
     {
         out << v[i] << " ";
     }
     return out;
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
   for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
