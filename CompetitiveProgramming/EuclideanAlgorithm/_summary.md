# Number Theory Notes

## 1. GCD of a and b

### a) Brute Force:
---------------
- It uses the fact that the gcd must be less than or equal to min(a, b)

**ALGORITHM:**

Take gcd = 0
for i in [1, min(a, b)]:
    if (a % i == b % i == 0):
        gcd = i
print(gcd)

- Time Complexity: O(min(a, b))

### b) Euclidean Algorithm:
-----------------------
- Euclid's Algorithm states that gcd(a, b) = gcd(b, a % b)
- Using this fact we can recursively compute gcd.
- Since 0 <= (a % b) <= (b - 1), the second parameter b must become 0 at some point, where the recursion bottoms out.

**ALGORITHM:**

function gcd(a, b):
    if (b == 0):
        return a
    return gcd(b, a % b)

- Expected Time Complexity: O(log(a))


## 2. Extended Euclidean Algorithm
------------------------------------------------
- Used to solve equations of the form:
    
    ax + by = gcd(a, b)

- Recursive approach to solve the equation:

    ax + by = gcd(a, b)   ---- (1)

Substituting, a = b, b = (a % b), is valid because of Euclid's Algorithm

    bx1 + (a % b)y1 = gcd(a, b)
=>  bx1 + [a - floor(a/ b) * b]y1 = gcd(a, b) (Using a % b = a - floor(a / b))
=>  bx1 + ay1 - by1 * floor(a / b) = gcd(a, b)
=>  a * y1 + b * [x1 - y1 * floor(a / b)] = gcd(a, b)   --- (2)

Comparing (1) & (2):
    x = y1, y = x1 - y1 * floor(a / b)   --- (RESULT)

**ALGORITHM:**

function extendedEuclid(a, b):
    if (b == 0):       // The base case
        return {1, 0}  // When b == 0, a == gcd(a, b), thus solution is (1, 0)

    subRes = extendedEuclid(a, b)
    return { subRes[1], subRes[0] - (a / b) * subRes[1] }

- This algorithm can also be used to calculate gcd(a, b)

## 3) Multiplicative Modulo Inverse
------------------------------------------------
- Find x such that ax = 1 (mod m), and 1 <= x <= (m - 1)
- Since, ax should leave a remainder of 1, when divided by m, we can write it as:
    my + 1 = ax, where y is some integer
=>  ax + my = 1

- Thus, MMI exists iff gcd(a, m) = 1
- The problem of finding MMI is now reduced to finding the solution to the above equation, which can be easily done using Extended Euclidean Algorithm

**ALGORITHM:**

function MMI(a, m):
    if gcd(a, m) != 1:
        print "MMI does not exist"
        return
    
    mmi = extendedEuclid(a, m)
    return (mmi % m + m) % m  // Add m to make mmi in the range [1, m - 1]


## Linear Diophantine Equations
------------------------------------------------
- An equation of the form ax + by = c
- Solution to this equation for integer values of x & y exist iff c % gcd(a, b) == 0
- Let, gcd(a, b) = g. Then,
    c = k * g
=>  ax + by = k * g

From Extended Euclid's Algorithm we can find solutions of, ax + by = g. Hence, the above equation is nothing but,
    k * (ax + by) = k * g
=>  ax + by = c

Hence, to find the solution this equation, we can solve for ax + by = g, and then multiply the results by k (= c / g).

- There are infinitely many solutions to linear diophantine equations. Suppose (x1, y1) are solutions to an equation ax + by = c. Then,

    (x, y) = [x1 + t * (b / g), y1 - t * (a / g)] (t is a parameter that can be varied to get infinitely many solutions)

is also a solution.

