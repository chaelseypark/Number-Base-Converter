//Chaelsey Park
//Date Modified: 01.18.2021
//Number Base Converter C++
//Allows the user to enter a number in: binary, octal, decimal, or hex
//Outputs the number in all of the above bases

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

//function prototypes- declare functions
string decimalToBase(int decimalNum, int base);
int baseToDecimal(string num, int base);


int main(void) 
{
  string inNum; //number entered to be converted
  int inBase; //base of number entered

  cout << "Number Base Converter (by: Chaelsey Park)" << endl;
  cout << endl;

  //obtain num from user
  cout << "Enter number: ";
  cin >> inNum;
  cout << "Enter number-base: ";
  cin >> inBase; //base of inNum
  cout << endl;

  //output inNum converted to: binary, octal, decimal, and hex
  cout << "Binary (base-2): " << decimalToBase(baseToDecimal(inNum, inBase), 2) << endl;
  cout << "Octal (base-8): " << decimalToBase(baseToDecimal(inNum, inBase), 8) << endl;
  cout << "Decimal (base-10): " << baseToDecimal(inNum, inBase) << endl;
  cout << "Hexadecimal (base-16): " << decimalToBase(baseToDecimal(inNum, inBase), 16) << endl;

  cout << endl;
  cout << "Goodbye!" << endl;

  return 0;
}

//decimalNum- number in decimal (base-10)
//base- base of outputs (2, 8, 16)
//function converts decimal to binary, octal, decimal, and hex
string decimalToBase(int decimalNum, int base)
{
  string result = ""; //string containing decimalNum to base
  int rem; //remainder
  int currentNum = decimalNum; //copy of decimal number

  while(currentNum > 0)
  {
    rem = currentNum % base; //remainder of currentNum / base
    currentNum = currentNum / base;

    switch(rem)
    {
      case 10: //if remainder is 10...
      {
        result.insert(0, 1, 'A'); //replace result[0] (1 character) with 'A'
        break;
      }
      case 11: //if remainder is 11...
      {
        result.insert(0, 1, 'B'); //replace result[0] with 'B'
        break;
      }
      case 12: //if remainder is 12...
      {
        result.insert(0, 1, 'C'); //replace result[0] with 'C'
        break;
      }
      case 13: //if remainder is 13...
      {
        result.insert(0, 1, 'D'); //replace result[0] with 'D'
        break;
      }
      case 14: //if remainder is 14...
      {
        result.insert(0, 1, 'E'); //replace result[0] with 'E'
        break;
      }
      case 15: //if remainder is 15...
      {
        result.insert(0, 1, 'F'); //replace result[0] with 'F'
        break;
      }
      default: //if none of the above apply...
      {
        result.insert(0, 1, rem + 48); //replace result[0] with rem+48
        //add 48 to convert decimal rem to ASCII code character rem
        break;
      }
    }
  }

  return result;
}


//num- nummber in string format
//base- base of input number
//function converts given number in binary, octal, decimal, and hex to decimal
int baseToDecimal(string num, int base)
{
  int result = 0; //num to be converted to decimal (will be plugged into decimalToBase as decimalNum)

  //for loop that goes through each character in the string
  //num.length() is length of num, number of characters in num
  for(int i = 0; i < num.length(); ++i)
  {
    switch(num[i]) //num[i]- char (single character) from string num
    {
      case 'A':
      {
        result = result + (10 *(pow(base, (num.length() -1 -i) )));
        break;
      }
      case 'B':
      {
        result = result + (11 *(pow(base, (num.length() -1 -i) )));
        break;
      }
      case 'C':
      {
        result = result + (12 *(pow(base, (num.length() -1 -i) )));
        break;
      }
      case 'D':
      {
        result = result + (13 *(pow(base, (num.length() -1 -i) )));
        break;
      }
      case 'E':
      {
        result = result + (14 *(pow(base, (num.length() -1 -i) )));
        break;
      }
      case 'F':
      {
        result = result + (15 *(pow(base, (num.length() -1 -i) )));
        break;
      }
      default:
      {
        if(num[i] > 64) //when character num[i] is greater than 64, convert the ASCII code character to decimal code // otherwise A will be 65 in decimal, B is 66, etc.
        {
          result = result + (num[i] - 55) * (pow(base, (num.length() -1 -i) ));
          //convert character num[i] ascii code to decimal ascii code, subtract for difference (55)
        }
        else //when character num[i] is less than 64, convert ASCII code character to decimal code so that numbers 0 through 9 are worth 0-9 in decimal
        {
         result = result + (num[i] - 48) * (pow(base, (num.length() -1 -i) ));
         //convert character num[i] ascii code to decimal ascii code, subtract for difference (48)
        }
      }
    }
  }

  return result;
}