#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

string readsentence(){
    string S1;
    cout << "please enter what is sentence? " << endl;
    getline(cin , S1);
    return S1;
}
void reverse_sent(string S1 , vector <string> &normal_sent){
    
    string word = "";
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            word += S1[i];
            
        }
        else
        {
            normal_sent.push_back(word);
            word = "";
        }
        
    }
    if (!word.empty()) {
        normal_sent.push_back(word);
    }

 
    for (int i = normal_sent.size() - 1; i >= 0 ; i--)
    {
        cout << normal_sent[i] << " " ;
    }
    
    
}
int main(){
    vector <string> normal_sent;
    string S1 = readsentence();
    reverse_sent(S1 , normal_sent);
    return 0;

}