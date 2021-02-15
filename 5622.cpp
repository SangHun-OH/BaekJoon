include <iostream>
#include <vector>
using namespace std;
int main(){
    int sum = 0;
    string S;
    vector<string> vec = {{"-1"},{"-1"},{"-1"},{"ABC"},{"DEF"},{"GHI"},{"JKL"},{"MNO"},{"PQRS"},{"TUV"},{"WXYZ"}};
    cin>>S;
    for(int i = 0; i < S.length(); i++)
        for(int j =0; j < vec.size(); j++)
            if(vec[j].find(S[i]) != string::npos)
                sum += j;
    cout<<sum;
}