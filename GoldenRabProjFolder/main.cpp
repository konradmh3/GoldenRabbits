#include<iostream>
#include<time.h>
#include<iomanip>
#include<math.h>
#include<unordered_map>
#include<stdlib.h>
#include "BigInt.cpp"
using namespace std;

BigInt goldRabbits(int);
static unordered_map<int, BigInt> rabbidMap;

int main(){
  int const months = 12 * 10;
  int start = time(0);
  for(int i = 0; i < months; i++){
    int current = time(0);
    rabbidMap[i] = goldRabbits(i);
    cout << setw(5)<<current-start<<":";
    cout << " GoldRabbits("<<setw(2)<<i<<") = ";
    cout << setw(11) << rabbidMap[i] << endl;
  }
}

BigInt goldRabbits(int n){
  vector<char> rabbitsAtMonth;
  if(n==0 || n==1){
    rabbitsAtMonth.push_back('1');
    return rabbitsAtMonth;
  }
  else {
    return rabbidMap[n-1] + rabbidMap[n-2];
  }
}


