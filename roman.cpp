#include<iostream>
using namespace std;

int roman_to_number( string s )
{
    int output = 0;
    for( int i = 0 ; i < s.length() ; i++)
    {
        switch( s[i] )
        {
            case 'I':
                output++;
            break;
            case 'V':
                output += 5;
                if( s[i-1] == 'I' )
                    output -= 2;
            break;
            case 'X':
                output += 10;
                if( s[i-1] == 'I' )
                    output -= 2;
            break;
            case 'L':
                output += 50;
                if( s[i-1] == 'X' )
                    output -= 20;
            break;
            case 'C':
                output += 100;
                if( s[i-1] == 'X' )
                    output -= 20;
            break;
            case 'D':
                output += 500;
                if( s[i-1] == 'C' )
                    output -= 200;
            break;
            case 'M':
                output += 1000;
                if( s[i-1] == 'C' )
                    output -= 200;
            break;
        }
    }
    return output;
}
int main()
{
    string s;
    while( cin >> s )
    {
        cout << roman_to_number(s) << endl;
    }
    return 0;
}
