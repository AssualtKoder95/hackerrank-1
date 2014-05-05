#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

#define MOD 1000000007


// Calculates K^N, constraining the result to mod MOD so huge numbers can
// be dealt with. Note that MOD must be prime for the output to be valid

long long expn(long long N, long long K) {
    
    
    if (K == 0){
	
	return 1;
    }
    
    if (K == 1){
	
	return N % MOD;
    }
    
    long long temp;
    
    if (K % 2 == 0){
	
	temp = expn(N, K / 2);	
	return (temp * temp) % MOD;
    } 
    else {
	
	temp = expn(N, K / 2);
	temp = (temp * temp) % MOD;	
	return (temp * N) % MOD;
    }
    
}

int main() {
    
    int T;   
    cin >> T;

    while (T--) {

	
	// 1) The problem asks us to find "(A^B) % 1000000007" where A and B can be up
	//    to 100,000 digits digits long
	//
	// 2) According to Fermat's Little Theorem, if p is a prime number and a is not divisible 
	//    by p, then a^(p-1) - 1 is an integer multiple of p. Since 1000000007 is prime, 
	//    "(A^B) % 1000000007" = "(A % 1000000007)^(B % 1000000006)"
	//
	//    @see http://en.wikipedia.org/wiki/Fermat%27s_little_theorem
	//
	// 3) Because A and B can be up to 100,000 digits long, we can't just load them 
	//    into variables and run ops on them. Instead, we run through them digit by digit, 
	//    calculating the modulus. The result is two 9-digit long numbers that will fit 
	//    in a long long.
	// 
	// 4) The final step is calculating "(X^Y) % 1000000007" where X and Y are 9 digits 
	//    long. Two important observations are
	//
	//    a) Since 1000000007 is prime, we can run a "% 1000000007" after every operation,
	//       preventing overflows
	//
	//    b) Instead multiplying X by itself up to 1000000006 times in a row, we can use
	//       recursion to multiply blocks of of previous operations by themselves, making
	//       the operations follow a 2^n series (2 -> 4 -> 8 -> 16 -> 36) and getting
	//       the job done in O(log N) time. This is called "Fast Exponentiation"
	// 
	//       @see http://en.wikipedia.org/wiki/Exponentiation_by_squaring
	//
	
	int A[100009];
	int B[100009];
 
	string str1, str2;	
	long long temp1, temp2;

	cin >> str1 >> str2;

	// Load the two strings into working arrays
	
	for (int i = 0; i < str1.length(); i++) {
	    
	    // This operation converts the character in the string, which is 
	    // stored as an ASCII value, into its int equivalent. Note the
	    // use of single quites (') instead of double quotes (").
	    
	    A[i] = str1[i] - '0';
	}
	
	for (int i = 0; i < str2.length(); i++) {
	    
	    B[i] = str2[i] - '0';
	}

	// Run a digit-by-digit modulus operation on A
	
	temp1 = A[0] % MOD;
	
	for (int i = 1; i < str1.length(); i++) {
	    
	    temp1 = ( (10 * temp1) + A[i]) % MOD;
	}

	// Run a digit-by-digit modulus operation on B
	
	temp2 = B[0] % (MOD - 1);
	
	for (int i = 1; i < str2.length(); i++) {
	    
	    temp2 = ( (10 * temp2) + B[i]) % (MOD - 1);
	}

	// Output A^B
	
	cout << expn(temp1, temp2) << endl;
	
    }
    
    return 0;
}