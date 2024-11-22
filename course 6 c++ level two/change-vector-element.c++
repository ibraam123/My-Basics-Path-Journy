#include <iostream> 
#include <vector>
using namespace std;


int main(){

vector <int> num{ 1,2,3,4,5 };
cout << "Initial Vector : ";
// & مع const
// تثبيت قيمة المتغير وعدم القدرة على تغييرها
for (const int& i : num)
{
cout << i << " ";
// Print 1 2 3 4 5
}
cout << "\n\n Updated Vector : ";
// فقط Reference & إشارة
// تستطيع تغيير قيمة المتغير
for ( int& i : num)
{
i = 20;
cout << i << " ";
// Print 20 20 20 20 20
}
// تستطيع تغيير قيمة المتغير
num[1] = 40;
num.at(2) = 80;
num.at(4) = 90;
cout << "\n\n Updated Vector : ";
// & مع const
// تثبيت قيمة المتغير وعدم القدرة على تغييرها
for (const int& i : num)
{
cout << i << " ";
// Print 20 40 80 20 90
}

return 0;

}