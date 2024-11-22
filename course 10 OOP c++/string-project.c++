#include <iostream> 
#include <vector> 
#include "class-string.h"
using namespace std;

int main(){
    clsString string1;
    clsString string2("ibraam");
    vector <string> words = {"ibraam" , "magdy" , "haliem"};

    string1.setstring("Magdy Haliem"); 

    cout << "String1 = " << string1.getstring() << endl;
    cout << "String2 = " << string2.getstring() << endl;

    cout << "Number of words: " << string1.printnumberofword() << endl;
    cout << "Number of words: " << clsString::printnumberofword("ibraam magdy haliem boles") << endl;

    cout << "Number of capital litters: " << string1.Count_Capitallitters() << endl;
    cout << "Number of capital litters: " << string1.Count_Capitallitters("IBraaM MAgdy") << endl;

    cout << "Number of litters: " << string1.Countletters() << endl;
    cout << "Number of litters: " << string1.Countletters("ibraam magdy") << endl;

    cout << "Number of small litters: " << string1.Count_Smaalletters() << endl;
    cout << "Number of small litters: " << string1.Count_Smaalletters("ibraam magdy") << endl;

    cout << "Number of sepacific litters: " << string1.CountSpesaficletter('m') << endl;
    cout << "Number of sepacific litters: " << string1.CountSpesaficletter("ibraam magdy" , 'm') << endl;

    cout << "Number of vowels litters: " << string1.CountVowels() << endl;
    cout << "Number of vowels litters: " << string1.CountVowels("ibraam magdy") << endl;

    cout << "Inverted string cases: " << string1.InvertALLlettercase() << endl;
    cout << "Inverted string cases: " << string1.InvertALLlettercase("ibrAAm maGdy") << endl;

    cout << "Inverted letter cases: " << string1.invert_lettercase('m') << endl;
    cout << "Inverted letter cases: " << string1.invert_lettercase("ibraam magdy" , 'm') << endl;

    cout << "String after join: " << string1.Joinstring(words) << endl;

    cout << "Remove puncuation: " << string1.Removepuncuation("ibraa'm ,ma;gdy.") << endl;

    cout << "lower first letter of each word: " << string1.Lowerfirstletter("Ibraam Magdy Haliem") << endl;

    cout << "reblace word of _value: " << string1.reblace("Boles") << endl;

    cout << "reverse string: " ; string1.reversestring("Boles magdy");
    cout << endl;


    return 0;
}