#pragma
#include <iostream>
#include <vector>
using namespace std;

class Clsfreelancer{
private:
    short _choosefrommainmenue;
public:
    void setchoose(short choose){
        _choosefrommainmenue = choose; 
    }
    short mainmenue(){
        short choose;
        do{
        cout << "_____________________________\n";
        cout << "\t Main menue \n";
        cout << "_____________________________\n";
        cout << "[1] Apps           [2]Webs \n";
        cout << "[3] Fullstack      [4]Marceting \n";
        cout << "[5] Mangement      [6]Virtal A \n";
        cout << "[7] Graphic design [8]AI/ML \n";
        cout << "[9] Transction     [10]Data Analysis \n";
        cout << "[11] Exit        \n";
        cout << "_____________________________\n";
        cout << "\n Choose what servise you want? " << endl;
        cin >> choose;
        setchoose(choose);
        afterchoose();
        } while(choose < 11);

        return choose;

    }

    void afterchoose(){
        char check;

        switch (_choosefrommainmenue)
        {
        case 1:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - small app (50) \n 2 - medium app (100) \n 3 - big app (150)" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;
            break;

        case 2:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - frontend (50) \n 2 - backend (100) " << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;
            break;
 
        case 3:
            system("cls");
            cout << "\t prices menue \n";
            cout << "200" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;        
            break;
 
        case 4:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - local area (50) \n 2 - wide area (100) \n 3 - more than one product (150)" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;
            break;
 
        case 5:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - small app (50) \n 2 - medium app (100) \n 3 - big app (150)" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;        
            break;
 
        case 6:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - small task (50) \n 2 - medium task (100) \n 3 - big task (150)" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;
            break;
 
        case 7:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - small image (50) \n 2 - medium image (100) \n 3 - big image (150)" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;        
            break;
 
        case 8:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - make botchat (50) \n 2 - generat image (100) \n 3 - make robot (150)" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;
            break;
 
        case 9:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - from english to arabic (50) \n 2 - from arabic to english (100) \n 3 - from germany to arabic (150)" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;
            break;
 
        case 10:
            system("cls");
            cout << "\t prices menue \n";
            cout << "1 - small app (50) \n 2 - medium app (100) \n 3 - big app (150)" << endl;
            cout << "Are you sure to make this action? Y/N? " << endl;
            cin >> check;
            cout << "\nthanks to use freelancer site! " << endl;
            break;   
        case 11:
            system("cls");
            cout << "exiting program" << endl;
            return;   
        default:
            break;
        }
    }

    

};