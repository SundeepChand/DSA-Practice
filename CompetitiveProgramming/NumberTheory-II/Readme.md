# Notes

## Modular Arithmetic
---

### 1) Addition
```
    (a + b) % m = (a % m + b % m) % m
```

### 2) Subtraction
```
    (a - b) % m = (a % m + b % m) % m  (This will give incorrect results with negative values)
```
- **NOTE:** In C/C++, modulus is calculated as,
```
    a % m = a - (n * trunc(a / n))

Ex:
    In C++, (-7) % 5 = -2, whereas it should be 3
```
- So to correct the mod value, add m to the result and take its mod. Thus, the final code for subtraction is as follows:
```
    (a - b) % m = ((a % m + b % m) % m + m) % m
```

### 3) Multiplication
```
    (a * b) % m = (a % m * b % m) % m
```

### 4) Division
```
    (a / b) % m = (a % m * modInverse(a) % m) % m
```
- `modInverse` can be calculated as mentioned in the next section.

## Fermat's Little Theorem
---
- `(a ^ m) = a (mod m)`, where `m` is some prime.
- This can be used in finding the multiplicative modulo inverse.
- Dividing both sides by `a ^ 2`, we get
```
    (a ^ (m - 2)) = a ^ (-1) (mod m), which is the MMI
```
- Thus the MMI mod m (where, m is a prime) can be found as above.

**CODE:**
```
    ll fastExponentiation(ll a, ll e, ll m)
    {
        ll ans = 1, cur = a;
        while (e)
        {
            if (e & 1)
                ans = (ans * cur) % m;
            e >>= 1, cur = (cur * cur) % m;
        }
        return ans;
    }

    ll modInverse(ll a, ll m)
    {
        return fastExponentiation(a, m - 2, m);
    }
```

## Calculating nCr and nPr mod m
---
- We can use the modular operations to find nCr and nPr mod m
- nCr (mod m)
```
    int nCr(int n, int r)
    {
        ll a = (fact[n] * modInverse(fact[n - r], MOD)) % MOD;
        return (a * modInverse(fact[r], MOD)) % MOD;
    }
```
- nPr (mod m)
```
    int nPr(int n, int r)
    {
        return (fact[n] * modInverse(fact[n - r], MOD)) % MOD;
    }
```

## Chinese Remainder Theorem
---
- Ex:
```
    x % 3 = 2
    x % 5 = 3
    x % 7 = 4

    x =   A   +   B   +   C
=>  x = a*3*5 + b*3*7 + c*5*7

Taking x % 3,
    x % 3 = (c * 35) % 3 = 2 * c
=>      2 = 2 * c
=>      c = 1

Taking x % 5,
    x % 5 = (b * 21) % 5 = 1 * b
=>      3 = 1 * b
=>      b = 3

Similarly, taking x % 7, we get a = 4

Therefore,
    x = 4*3*5 + 3*3*7 + 1*5*7 = 158

Now, there are infinitely many solutions for x, and they can be given by
    x = 158 + t * LCM(3, 5, 7) = 158 + t * 105
```
- **NOTE:** For the solution to exist, the divisors must be pairwise co-prime.

## Totient Function
---
- It gives the number of integers less than n which are co-prime to n.
```
    phi(n) = n * prod(1 - 1 / p), where p are all the primes that divide n.

Ex:
    phi(10) = 10 * (1 - 1/2) * (1 - 1/5) = 10 * (1 / 2) * (4 / 5)
            = 4
```