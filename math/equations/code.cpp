
#include<iostream>
#include<vector>

using namespace std;

// This is a hardcore math challenge that requires specialized knowledge to 
// solve. All example testcases provided are completely useless. 1 collapses the
// equation and reveals nothing of the pattern, whereas 32327!^2 and 40921!^2 are so
// large that they're impractical to calculate. For example, 32327!^2 has 3468 distinct 
// prime factors. Have fun multiplying those together by hand to check your algorithm.
// https://www.wolframalpha.com/input/?i=prime+factorization+32327!^2.
//
// @see http://se7so.blogspot.ca/2012/10/number-of-positive-integral-solutions.html
//
// 1) The number of solutions is equal to the exponents of the prime factorization of N!^2,
//    incremented by 1, all multiplied together. For example, say N = 3, so N! = 2*3 = 6, 
//    and 6^2 = 36. The prime factorization of 36 is 2^2 * 3^2, giving the exponents "2" and 
//    "2" Thus, the solution is (2 + 1) * (2 + 1) = 9.
//
// 2) The next thing we need to observe is that we don't have to calculate N!^2 (which could be
//    milllions of digits long). We only need to calculate the prime factorization of each number 
//    from 1 to N, then add 1 to it to satisfy solution 1) then add an additional 1 to each 
//    exponent to handle the ^2 (squared). Say N = 3. The prime factorization of 3 is 3*1, of 2 
//    is 2*1, and of 1 is irrelevant. (1 + 1 + 1) * (1 + 1 + 1) = 9.
//
// The above solution can be calculated in O(N^2) time. Unfortunately, the problem author
// has set the testcases so large that only a O(N) solution will pass.
//
// 3) The final thing we need to observe is that instead of calculating the prime factorization
//    for every number between 2 and N, we can just calculate the prime factorization of N,
//    and for each exponent simply go 2(E + F) + 1. Say N is 3. The prime decomposition of 
//    3 is 3^1. Therefore E = 3 and F = 1. This gives 2(3 + 1) + 1 = 9. It runs in linear time.
//


int main(){
    
    // NOTE: its important to dynamically allocate the arrays. By default under Windows 7, the
    // Microsoft C++ compiler allocates ~500K of stack to a command line program and its awkward
    // to change. If we statically allocate an array, the size of the array comes out of our stack
    // budget. If we exceed our stack budget the program will segfault. A 100K element array
    // of <long long> is 800K.
    
    unsigned long long* primes = new unsigned long long[100000];
    unsigned long long* prime_factors = new unsigned long long [100000];

    primes[0] = 1;
    primes[1] = 2;
    prime_factors[1] = 0;
    
    unsigned long long count;
    unsigned long long check = 2;
    
    unsigned long long n, iter_n, divisor;
    int count_primes = 2;
 
    cin >> n;
    
    // First, pre-process all the factors of 2 in the array. This
    // cuts our processing time in half.
    
    while (divisor = n / check){

        prime_factors[1] += divisor;
        check = check * 2;
    }

    // Iterate through all the numbers from 3 to N
    
    for (iter_n = 3; iter_n <= n; iter_n++){

        bool is_prime = true;
        check = iter_n;
	
	// Test for divisibility against every prime number up to the square 
	// root of the number we're currently testing. If no primes divide
	// it, the number itself is prime. This works because every non-prime
	// number can be expressed powers of prime numbers.
	
        for (int i = 1; i < count_primes; i++){

            if ( check % primes[i] == 0){

                is_prime = false;
                break;
            }
	    
            if ( (primes[i] * primes[i]) > check){
		
                break;
	    }
        }
	
	// If we've found a prime number, calculate ("number" + "exponent"),
	// then increment the working number
	
        if(is_prime){

            primes[count_primes] = iter_n;
	    
            while (divisor = n / check){

                prime_factors[count_primes] += divisor;
                check = check * iter_n;
            }
	    
	    count_primes++;
        }
	
    }

    count = 1;
    
    // And as a final challenge, the solution count on some testcases
    // overflows a 256 bit number. So we have to maintain a running 
    // moduslus as we add the numbers up.
    
    for (int i = 1; i < count_primes; i++){

        count *= ((prime_factors[i] * 2) + 1) % 1000007;
        count = count % 1000007;
    }

    
    cout << count << endl;

    delete[] primes;
    delete[] prime_factors;
    
    return 0;
    
}