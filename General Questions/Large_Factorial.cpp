#include <bits/stdc++.h>

using namespace std;

std::string factorial(int n)
{
    if (n < 0)
        return "0";
    if (n == 0)
        return "1";

    const int BASE = 1000000000;
    vector<int> result;
    result.push_back(1);

    for (int x = 2; x <= n; x++)
    {
        long long carry = 0;

        for (int i = 0; i < result.size(); i++)
        {
            long long prod = (long long)result[i] * x + carry;
            result[i] = prod % BASE;
            carry = prod / BASE;
        }
        while (carry)
        {
            result.push_back(carry % BASE);
            carry /= BASE;
        }
    }

    string output = to_string(result.back());
    for (int i = result.size() - 2; i >= 0; i--)
    {
        string chunk = to_string(result[i]);
        output += string(9 - chunk.length(), '0') + chunk;
    }

    return output;
}

int main() {
    // Test with different numbers
    cout << "5! = " << factorial(5) << endl;      // 120
    cout << "10! = " << factorial(10) << endl;    // 3628800
    cout << "20! = " << factorial(20) << endl;    // 2432902008176640000
    
    // Large factorial
    string fact100 = factorial(100);
    cout << "\n100! has " << fact100.length() << " digits" << endl;
    cout << "First 50 digits: " << fact100.substr(0, 50) << "..." << endl;
    
    return 0;
}