#include <iostream>

using namespace std;

 typedef struct PalindromeNode{
     string data;
     struct PalindromeNode *nextNode;
 }*palindromPtr;

 palindromPtr head = NULL, current = NULL;

 void ProduceStringList(string str){
        palindromPtr newStrNode = new PalindromeNode;
        newStrNode->data = str;
        if(head == NULL){
            newStrNode->nextNode = NULL;
            head = newStrNode;
            current = head;
        }
        else{
            newStrNode->nextNode = NULL;
            current->nextNode = newStrNode;
            current = newStrNode;
        }
}

string MakePalindrome(string str, int fIndex, int lIndex){
     string plindromStr = "";
     int i = 0;
     if(fIndex > lIndex){
        return str;
     }
     else if(str[fIndex] != str[lIndex]){
         if(str[fIndex + 1] == str[lIndex]){
            while(i <= str.length()){
                if(str[i] != str[fIndex]){
                   plindromStr += str[i];
                   i++;
                }
                else{
                    i++;
                }
            }
            cout << "Character removed: " << str[fIndex] << endl;
            return plindromStr;
         }
         else if(str[lIndex - 1] == str[fIndex]){
            while(i <= str.length()){
                if(str[i] != str[lIndex]){
                    plindromStr += str[i];
                    i++;
                }
                else{
                    i++;
                }
            }
            cout << "Character removed: " << str[lIndex] << endl;
            return plindromStr;
         }
     }
     else{
        return MakePalindrome(str, fIndex + 1, lIndex - 1);
     }
}

int IsPalindrom(string str, int i, int j){
    if(i > j){
        return 1;
    }
    else if(str[i] != str[j]){
        return -1;
    }
    else{
        return IsPalindrom(str, i + 1, j - 1);
    }
}

string Palindrom(string palinromchecker){
       int strSize = palinromchecker.length() - 1;
       int palindrome = IsPalindrom(palinromchecker, 0, strSize);

       if(palindrome == 1){
        cout << "String is Palindrome." << endl;
       }
       else{
          palinromchecker = MakePalindrome(palinromchecker, 0, strSize);
          return Palindrom(palinromchecker);
       }
}

void DisplayStrList(){
        palindromPtr displayStr = head;
        if(head == NULL){
            cout << "String List is Empty!!!" << endl;
        }
        else{
            cout << "String data: ";
            while(displayStr != NULL){
                cout << displayStr->data;
                displayStr = displayStr->nextNode;
            }
            cout << endl;
        }
}

int main()
{
    string str[] = {"L", "E", "A", "V", "E", "L"};
    int strSize = sizeof(str) / sizeof(str[0]);
    int i = 0;
    while(i < strSize){
        ProduceStringList(str[i]);
        i++;
    }
    string palinromchecker = "";
    palindromPtr pPtr = head;
       while(pPtr != NULL){
        palinromchecker += pPtr->data;
        pPtr = pPtr->nextNode;
       }
    DisplayStrList();
    Palindrom(palinromchecker);
    return 0;
}
