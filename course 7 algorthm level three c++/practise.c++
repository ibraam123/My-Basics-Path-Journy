#include <iostream>
#include <string>
#include <vector>
using namespace std;

void check(){

    vector <string> small = {"ibraam", "ibraw"};
    string word;
    string word2;
    int count = 0;

    for (int i = 0; i < small.size() - 1; i++)
    {
        word = small[i];
        word2 = small[i+1];
        count = 0;
        for (int j = 0; j < word2.length(); j++)
        {
            if (word[j] == word2[j])
            {
                count ++;
            }
        }

            if (count == word2.length())
            {
               cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
            
            
            
        
        
        
       
       
       
        
    }
    
    
}

int main(){
    check();
    return 0;
}
