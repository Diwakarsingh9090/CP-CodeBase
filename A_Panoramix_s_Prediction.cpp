#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes to generate primes up to MAX
vector<bool> sieve(int MAX)
{
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int MAX = 50;
    vector<bool> isPrime = sieve(MAX);
    // Store all primes in a list
    vector<int> primes;
    for (int i = 2; i <= MAX; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
    // Find position of n in the prime list and check if next is m
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] == n)
        {
            if (i + 1 < primes.size() && primes[i + 1] == m)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            break;
        }
    }

    return 0;
}
