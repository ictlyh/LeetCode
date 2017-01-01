class Solution {
  public:
    string numberToWordsHelper(int num) {
      string digits[] = { "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine" };
      string Tens[] = { "", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety" };
      string Tens1[] = { " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
      string hundered(" Hundred");
      string res;
      int digit = num % 10;
      num /= 10;
      int ten = num % 10;
      num /= 10;
      int hun = num % 10;
      res.append(hun > 0 ? digits[hun] + hundered : "");
      res.append(ten > 1 ? Tens[ten] : "");
      res.append(ten == 1 ? Tens1[digit] : "");
      res.append(ten != 1? digits[digit] : "");
      int idx = res.find_first_not_of(" ");
      return idx == -1 ? res : res.substr(idx);
    }

    string numberToWords(int num) {
      int a = num % 1000;
      num /= 1000;
      int b = num % 1000;
      num /= 1000;
      int c = num % 1000;
      num /= 1000;
      int d = num % 1000;
      string res;
      res.append(d > 0 ? numberToWordsHelper(d) + " Billion " : "");
      res.append(c > 0 ? numberToWordsHelper(c) + " Million " : "");
      res.append(b > 0 ? numberToWordsHelper(b) + " Thousand " : "");
      res.append(a > 0 ? numberToWordsHelper(a) : "");
      res.append(res.size() == 0 ? "Zero" : "");
      int idx = res.find_last_not_of(" ");
      return idx == -1 ? res : res.substr(0, idx + 1);
    }
};
