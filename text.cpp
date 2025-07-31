#include<iostream>
#include<fstream>
using namespace std;
//function prototype.
bool Letter(char ch);
bool Digit(char ch);
bool word(char ch);
int main()
{
    ifstream file("input.txt");
    int lineCount=0,wordCount=0,specialCharCount=0,letterCount=0;
    string line;
    while(getline(file,line))
    {
        lineCount++;
        bool inWord=false;
        for(int i=0;i<line.length();i++)
        {
            char ch=line[i];
            // Count letters.
            if(Letter(ch))
            {
                letterCount++;
            }
            // count words.
            if(word(ch))
            {
                if(!inWord)
                {
                    wordCount++;
                    inWord=true;
                }
            }
            else
            {
                inWord=false;
            }
            // Count special characters.
            if (!word(ch) && ch!=' ' && ch!='\t')
            {
                specialCharCount++;
            }
        }
    }
    file.close();
    cout<<"Total Lines:"<<lineCount<<endl;
    cout<<"Total Words:"<<wordCount<<endl;
    cout<<"Total Letters:"<<letterCount<<endl;
    cout<<"Special Characters:"<<specialCharCount<<endl;
    return 0;
}
// Helper to check if a letter (A-Z or a-z).
bool Letter(char ch)
{
    return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z');
}
// Helper to check if a digit (0-9).
bool Digit(char ch)
{
    return (ch>='0' && ch<='9');
}
// Helper to check if a letter or digit.
bool word(char ch)
{
    return Letter(ch) || Digit(ch);
}
