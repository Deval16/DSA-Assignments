// 4) String Related Programs 
// (a) Write a program to concatenate one string to another string. 
// (b) Write a program to reverse a string. 
// (c) Write a program to delete all the vowels from the string. 
// (d) Write a program to sort the strings in alphabetical order. 
// (e) Write a program to convert a character from uppercase to lowercase.

//a
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Deval ";
    string s2 = "Rohatgi!";
    s1 =s1+ s2;
    cout << "Concatenated string: " << s1 << endl;
    return 0;
}

//b#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str = "Hello";
    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
    return 0;
}

//d
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string words[] = {"Deval", "AAYUSH", "shrey", "pratham"};
    int n = 4;
    sort(words, words+n);
    cout << "Sorted strings: ";
    for (int i = 0; i < n; i++) cout << words[i] << " ";
    return 0;
}

//e
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str = "DEVAL ROHATGI";
    for (char &c : str) c = tolower(c);
    cout << "Lowercase: " << str << endl;
    return 0;
}
