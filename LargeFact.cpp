#include <iostream>
#include<vector>
using namespace std;
void multiply(int x, vector<int>* f)
{
    int carry = 0;
    for (int i = 0; i < f->size(); i++)
    {
        int num = (*f)[i] * x + carry;
        (*f)[i] = num % 10;
        carry = num / 10;
    }
    while (carry > 0)
    {
        f->push_back(carry % 10);
        carry /= 10;
    }
}
void fact(int n)
{
    vector<int>* f = new vector<int>;
    f->push_back(1);
    for (int i = 2; i <= n; i++)
    {
        multiply(i, f);
    }
    for (int i = f->size() - 1; i >= 0; i--)
        cout << (*f)[i];
}

int main()
{
    int n;
    cin>>n;
    fact(n);
    return 0;
}
