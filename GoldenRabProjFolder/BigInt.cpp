#include<iostream>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

class BigInt{
  private:
  vector<char> rabAmount;

  public:
    BigInt(){
    }

    BigInt(vector<char> rab){
      for(int i = 0; i < rab.size(); i++){
      rabAmount.push_back(rab[i]);
      }
    }

    vector<char> getRabAmount(){
      return rabAmount;
    }

    friend BigInt operator+(BigInt A, BigInt B){//A larger always
      int carry = 0;
      vector<char> sum;      

//so rn what im doing is trying to add characters...instead...change to ints add then change back to char before adding it to the "sum" and returning
      if(A.rabAmount.size()==B.rabAmount.size()){
        for(int i = A.rabAmount.size()-1; i>=0;i--){
          if (((int)A.rabAmount[i]-48) + ((int)B.rabAmount[i]-48) + carry >= 10){
            // if(i == 0){
            //   sum.insert(sum.begin(), '1');
            //   carry = 0;
            // }
            sum.insert(sum.begin(), '0' + ((((int)A.rabAmount[i]-48) + ((int)B.rabAmount[i]-48) + carry) % 10));
            carry = 1;
            if(i == 0){
              sum.insert(sum.begin(), '1');
              carry = 0;
            }
          }else{
            sum.insert(sum.begin(), '0' + (((int)A.rabAmount[i]-48) + ((int)B.rabAmount[i]-48) + carry));
            carry = 0;
          }
        }
        //now i think i need to fix the same thing below that i did above...figure out the carry when i is 0 when length is different.
      }else{
        for(int i = A.rabAmount.size()-1; i>=0;i--){
          if(i == 0){
            if (((int)A.rabAmount[i]-48) + carry >= 10){           
               sum.insert(sum.begin(), '0' + (((int)'1'-48) + (int)A.rabAmount[i]-48)%10);
               carry = 1;
            }else{
              sum.insert(sum.begin(), '0' + (((int)A.rabAmount[i]-48) + carry));
              carry = 0;
            }
          }else if (((int)A.rabAmount[i]-48) + ((int)B.rabAmount[i-1]-48) + carry >= 10){
            sum.insert(sum.begin(), '0' + ((((int)A.rabAmount[i]-48) + ((int)B.rabAmount[i-1]-48) + carry) % 10));
            carry = 1;
            
          }else{
            sum.insert(sum.begin(), '0' + (((int)A.rabAmount[i]-48) + ((int)B.rabAmount[i-1]-48) + carry));
            carry = 0;
          
          }
        }
      } 
      
      return sum;
    }
    


    friend ostream &operator<<(ostream &output, const BigInt &C){
      string out(C.rabAmount.begin(), C.rabAmount.end());
      output << out;
      return output; 
    }


    friend bool operator<(BigInt C, BigInt D){
      if(C.rabAmount.size() < D.rabAmount.size()){
        return true;
      }
      if(C.rabAmount.size() > D.rabAmount.size()){
        return false;
      }
      else{
        for(int i = 0;i< C.rabAmount.size();i++){
          if(C.rabAmount[i] < D.rabAmount[i]){
            return true;
          }
        }
        return false;
      }
    }

};
