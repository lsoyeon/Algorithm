#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
/*
소수 몇개 만들 수 있을까
*/

bool isPrime(int n){
    if(n<2) return false;
    int sqrt_n = sqrt(n);
    for(int i = 2; i <= sqrt_n ; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    int len = numbers.size();
    unordered_set<int> us;
    sort(numbers.begin(), numbers.end()); //next_permutation 사용하려면 정렬 필요
    
    do{
        if(isPrime(stoi(numbers))){
            us.insert(stoi(numbers));
        }
        cout << stoi(numbers) << endl;
        for(int i = 1; i <len ; ++i){
            int front= stoi(numbers.substr(0,i)); //시작 인덱스, 길이
            int end = stoi(numbers.substr(i, len-i));
            cout << "front: " << front << " end: " << end << endl;
            if(isPrime(front)){
                us.insert(front);
            }
            if(isPrime(end)){
                us.insert(end);
            }
        }
        
    }
    while(next_permutation(numbers.begin(), numbers.end()));
    
    answer = us.size();
    return answer;
}