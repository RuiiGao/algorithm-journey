#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve_of_eratosthenes(int n){
	if(n < 2) return {};
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	
	for(int i = 2; i <= sqrt(n); ++i){
		if(is_prime[i]){
			for(int j = i * i; j <= n; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	// 优化：只遍历奇数
/*	is_prime[2] = true;
	
	for(int i = 4; i <= n; i += 2){
		is_prime[i] = false;
	}
	
	for(int i = 3; i <= sqrt(n); i += 2){
		if(is_prime[i]){
			for(int j = i * i; j <= n; j += i){
				is_prime[j] = false;
			}
		}
	}
*/
	
	vector<int> primes;
	for(int i = 2; i <= n; ++i){
		if(is_prime[i]){
			primes.push_back(i);
		}
	}
	return primes;
}

int main(){
	int n = 100;
	vector<int> primes = sieve_of_eratosthenes(n);
	
	cout << "1~" << n << "的素数个数：" << primes.size() << endl; // 输出25
    cout << "所有素数：";
    for (int p : primes) cout << p << " ";
	
	return 0;
}