// Problem   Fractran
// Algorithm Simulation
// Runtime   O(n)

#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int max_nprimes = 172;
const int max_prime = 1024;

int prime[max_nprimes];

// Generate the prime numbers up to max_prime using the Sieve of Eratosthenes.
// The result is stored in prime[0], ..., prime[max_nprimes-1].
void init()
{
  bool sieve[max_prime];
  for (int i=0 ; i<max_prime ; i++)
    sieve[i] = true;
  int nprimes = 0;
  prime[nprimes++] = 2;
  for (int i=3 ; i<max_prime ; i+=2)
    if (sieve[i])
    {
      prime[nprimes++] = i;
      for (int j=i*i ; j<max_prime ; j+=i+i)
        sieve[j] = false;
    }
  assert(nprimes == max_nprimes);
}

typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vpi::iterator vpit;

// Compute the prime factorization of x.
// The result is a vector of (index,exponent) pairs indicating the (positive)
// exponent of prime[index] in the factorization of x.
vpi prime_factors(int x)
{
  vpi result;
  for (int i=0 ; i<max_nprimes && x>1 ; i++)
  {
    int cnt = 0;
    while (x % prime[i] == 0)
    {
      x /= prime[i];
      ++cnt;
    }
    if (cnt > 0)
      result.push_back(pi(i, cnt));
  }
  assert(x == 1);
  return result;
}

// Compute the number of prime factors of v.
int number_of_factors(vpi &v)
{
  int cnt = 0;
  for (vpit it = v.begin() ; it != v.end() ; ++it)
    cnt += it->second;
  return cnt;
}

int main()
{
  init();
  while (1)
  {
    int m, n, k;
    cin >> m;
    if (m == 0) break;
    assert(1 <= m && m <= 50);
    cin >> n >> k;
    assert(1 <= n && n <= 1000000000);
    assert(1 <= k && k <= 100);

    // The current state N is stored as a vector indicating the exponents of
    // all primes up to max_prime in the prime factorization of N.
    // The total number of prime factors of N is additionally cached in N_sum.
    int N[max_nprimes];
    for (int i=0 ; i<max_nprimes ; i++)
      N[i] = 0;
    vpi N_p = prime_factors(n);
    for (vpit it = N_p.begin() ; it != N_p.end() ; ++it)
      N[it->first] = it->second;
    int N_sum = number_of_factors(N_p);

    // We store the numerators and denominators using their prime factorization.
    // The difference of the number of prime factors is cached in delta.
    int numerator[128], denominator[128], delta[128];
    vpi numerator_p[128], denominator_p[128];
    for (int i=0 ; i<k ; i++)
    {
      cin >> numerator[i] >> denominator[i];
      numerator_p[i] = prime_factors(numerator[i]);
      denominator_p[i] = prime_factors(denominator[i]);
      delta[i] = number_of_factors(numerator_p[i]) - number_of_factors(denominator_p[i]);
    }

    while (m > 0)
    {
      // Is N a power of 2?
      if (N_sum == N[0])
      {
        --m;
        cout << N[0] << (m == 0 ? '\n' : ' ');
      }
      for (int i=0 ; i<k ; i++)
      {
        // Does denominator[i] divide N?
        for (vpit it = denominator_p[i].begin() ; it != denominator_p[i].end() ; ++it)
          if (N[it->first] < it->second)
            goto try_next_fraction;
        // N = (N / denominator[i]) * numerator[i];
        for (vpit it = denominator_p[i].begin() ; it != denominator_p[i].end() ; ++it)
          N[it->first] -= it->second;
        for (vpit it = numerator_p[i].begin() ; it != numerator_p[i].end() ; ++it)
          N[it->first] += it->second;
        N_sum += delta[i];
        break;
try_next_fraction:;
      }
    }
  }
  return 0;
}
