/*
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.
*/

class Solution {
	Time: O(LogN) Space: O(1)
public:

string GetRomanCharacter(int digit, char one, char five, char ten)
{
  string result = "";

  switch(digit)
  {
    case 1:
      return result + one;
    case 2:
      return result +one+ one;
    case 3:
      return result + one + one + one;
    case 4:
      return result + one + five;
    case 5:
      return result + five;
    case 6:
      return result + five + one;
    case 7: 
      return result + five + one + one;
    case 8:
      return result + five + one + one + one;
    case 9:
      return result + one + ten;
    default:
      return result;
  }

  return result;
}

string GetRomanCharactersForDigit(int digit, int tens)
{
  if(digit == 0)
  {
    return "";
  }
  // every digits can be presented by 3 characters based on their position
  string result = "";
  switch(tens)
  {
    case 1:
      return GetRomanCharacter(digit, 'I', 'V', 'X');
    case 2:
      return GetRomanCharacter(digit, 'X', 'L', 'C');
    case 3:
      return GetRomanCharacter(digit, 'C', 'D', 'M');
    case 4:
    {
      for(int i = 0; i< digit; ++i)
      {
        result += 'M';
      }
      return result;
    }
    default:
      return "";
  }
}

    string intToRoman(int num) {
        int digit = 0;
        string result = "";
        for(int i = 3; i >=0; --i)
        {
            digit = num / pow(10,i);
            num -= digit * pow(10,i);
            result.append(GetRomanCharactersForDigit(digit, i+1));
        }

        return result;
    }
};
