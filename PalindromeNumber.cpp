// C++ Implementation of Palindrome Number

#include <iostream>

using namespace std;

bool isPalindrome(int n)
{
    if(n < 0 || n != 0 && n % 10 == 0) return false; // base case

    int x = 0;

    while(n > x) {
        x = x * 10 + n % 10;
        n = n / 10;
    }
    return (n == x  || n == x / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << isPalindrome(n) << endl;
    return 0;
}
