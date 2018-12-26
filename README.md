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
