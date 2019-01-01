# ProjectEuler

This repository contains solutions to the problems of [Project Euler](https://en.wikipedia.org/wiki/Project_Euler). Check out the [official website](https://projecteuler.net/) and the programming versions over at [hackerrank](https://www.hackerrank.com/) [here](https://www.hackerrank.com/contests/projecteuler/challenges) with higher input sizes thus asking for a faster solution.

1. Multiples of 3 and 5:

    - Use the formula \sum i = 1 + 2 + \dots + n = n(n+1)/2 to sum multiples of 3 and 5 seperately.  
    - Make sure to not count any number twice (multiples of both 3 and 5 like 15)
    - Note the upperlimit.  
    Ans: 233168

2. Even Fibonacci numbers:

    - Fibonacci numbers grow fast (factor of \phi ~ 1.6, golden ratio).
    - The upper limit (4 million) and the one from the ProjectEuler+ is crossed by just the 34th number and the 82nd number.  
    - The parity of the number sequence: oeooeooeooeooe. We need to calculate only every 3rd number.  
    - a, b = 2, 3 and a, b = a+2b, 2a+3b where a is the even fibonacchi's  
    - Bonus: Check out finding nth fibonacci in O(lgn) instead of O(n)  
    Ans: 4613732

3. Largest Prime factor:

    - The only prime factor greater than \sqrt{n} would be n itself (if it were prime)  
    - Thus, finding the largest prime factor would be O(\sqrt{n})  
    - Bonus: All primes are of the form 6n+1 or 6n+5  
    Ans: 6857

4. Largest palindrome product:

    - There are only 1000 3- digit number and all combinations can be enumerated with ease.  
    - Iterate over multiples of 11.  
    - Binary search for the largest number less than n. Or simple linear search will work too because the number of palindromes is just 2470.  
    Ans: 906609  

5. Smallest multiple:

    - Find LCM of all numbers from 1 to N, or  
    - Get prime factorization and find LCM using this.  
    - LCM = ab/GCD(a, b)  
    Ans: 232792560

6. Sum square difference:

    - \sum i^2 = n(n+1)(2n+1)/6  
    - (\sum i)^2 = n^2(n+1)^2/4  
    Ans: 25164150  

7. 10001st prime:

    - Use sieve method to list all primes  
    Ans: 104743  

8. Largest product in a series:

    - Rolling window  
    Ans: 23514624000  

9. Special Pythogorean triplets:

    - Solve the given 2 equations for b interms of a.  
    - Run a loop from 1 to n/3 for a with wlog a < b < c  

10. Summation of primes:

    - List all the primes below 2 million and sum them up  
    Ans: 142913828922

12. Highy divisible triangular number:

    - Number of divisors of 2^a3^b5^c... = (a + 1)(b + 1)(c + 1)...  
    - We could find number of divisors of every number using a sieve.  
    - nD(n(n+1)/2) = nD(n)nD((n+1)/2) or nD(n/2)nD(n+1) based on parity of n.  
    Ans: 76576500

13. Large sum:

    - Use library big integers  
    Ans: 5537376230

14. Longest Collatz sequence:

    - Memoize upto 10**6 numbers
    - Compute prefix max argument  
    Ans: 837799

15. Lattice paths:

    - Ans is ^2nCn  
    Ans: 137846528820

16. Power Digit sum:

    - Store huge numbers as char array and simulate multiplying by hand.  
    Ans: 1366

18. Maximum path sum I:

    - DP  
    Ans: 1074

20. Factorial digit sum

    - Library big integers  
    Ans: 648

21. Amicable numbers:

    - Sum of divisors = pi(pi^mi+1 - 1)/(pi - 1) where n = pi^mi  

24. Lexicographi permutations:

    - Read about factorial number systems  
    Ans: 2783915460

25. 1000-digit Fibonacci number:

    - F(n) = floor((phi^2)/(5^1/2) + 1/2)  
    - Number of digits in n = ceil(log10(n))  
    Ans: 4782

26. Reciprocal cycles:

    - 1/y = 0.000...0.cycle.cycle.cycle...
    - 10^i/y = 0.cycle.cycle.cycle...
    - 10^i+c/y = cycle.cycle.cycle....
    - (10^i)(10^c - 1)/y = cycle
    - y must divide 10^i or 10^c - 1  
    Ans: 983

27. Quadratic primes:

    - f(0) = b which needs to be prime.
    - Try all possible values of n and test f(n) for prime.  
    Ans: -59231 (-61, 971)

28. Number spiral diagnols:

    - Smallest corner in kth square = 1 + 4k(k+1) - 6k, solved recursively
    - Sum till kth square = 1 + 4k + 2k(k+1)(8k+7)/3, solved recursively  
    Ans: 669171001

29. Distinct powers:

    - a1^b1 = a2^b2 iff a1 = c^i1 and a2 = c^i2 given all are integers
    - Every exponent of a = c^k is repeated iff jk <= in, 0 < i < k
    - O(nlgn^2), although can do better, O(nlgn)
    Ans: 9183

30. Digit fifth powers:

    - Iterate over all integers with an upper limit of n9^n where n is the number of digits
    Ans: 443839

