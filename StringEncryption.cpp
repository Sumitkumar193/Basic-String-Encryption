#include <iostream>
#include <string>
using namespace std;

int main() {
    string Alpha{"abcdefghijklmnopqrstuvwxyzABCDEFGH'IJKLMNOPQRSTUVWXYZ0123456789 +-@.,"}; //can be shuffled
    string Key{"Pm3OSJM9NWg'defnV0T87AjDXGUxBIcyrpL4FwqCuiKYot1EzZ2Ha5vsl6RkbQh $#*&!"}; //Used string shuffler here for stronger security if ANY! :P
    string words{},phrase{};
    int choice;
    
    restart:    //Restart the process again!
    cout << "-----------------------------------------"<< endl;
    cout << "Enter 1 to Encrypt message!" << endl << "Enter 2 to Decrypt message!" << endl;
    cout << "-----------------------------------------"<< endl << endl;
    cout << "Choose : ";
    cin >> choice;
    
    switch(choice){
        case 1:     //Case of Encryption
            cout << "Enter text to encrypt: ";
            cin.ignore();   //clear previous input buffer
            getline(cin, words);
            for(char word: words){
                    size_t position = Alpha.find(word); //Saving position of alphabet (using size_t because of unsigned int range)
                    
                    if(position != string::npos){     //Check if invalid character used (Not defined in Alpha)
                        char new_char { Key.at(position) };
                        phrase += new_char;
                    }
                    else{
                        phrase += word;
                    }
            }
            
            cout << "Encrypted phrase is: " << phrase << endl;
            
            //Want to continue?
            cout << "\n\n\nDo you want to continue? \n1> Yes\n2> No\nChoose: ";
            cin >> choice;
            if(choice == 1)
                goto restart;
            break;
        case 2:     //Case of Decryption
            cout << "Enter text to decrypt: ";
            cin.ignore();   //clear previous input buffer
            getline(cin, words);
            phrase.clear();     //Clear previous results
            for(auto word: words){
                    size_t position = Key.find(word);
                    if(position != string::npos){     //Check if invalid character given (Not defined in Key)
                        char new_char { Alpha.at(position) };
                        phrase += new_char;
                    }
                    else{
                        phrase += word;
                    }
            }
            
            cout << "Decrypted phrase is : \n" << phrase;
            
            //Want to continue?
            cout << "\n\n\nDo you want to continue? \n1> Yes\n2> No\nChoose: ";
            cin >> choice;
            if(choice == 1)
                goto restart;
            break;
        default:
            cout << "oops!! seems like you entered wrong number try again!!" << endl;
            break;
    }
    return 0;
}
