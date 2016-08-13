//length为牛客系统规定字符串输出的最大长度，固定为一个常数
class Solution {
  public:
    void replaceSpace(char *str,int length) {
      int space_count = 0;
      int str_length = 0;
      char *ptr = str;
      while (*ptr != '\0') {
        if (*ptr == ' ') space_count++;
        ptr++;
        str_length++;
      }
      int newidx = str_length + 2 * space_count;
      if (newidx > length) return;
      ptr = str + str_length;
      while (ptr >= str) {
        if (*ptr == ' ') {
          str[newidx--] = '0';
          str[newidx--] = '2';
          str[newidx--] = '%';
        } else str[newidx--] = *ptr;
        ptr--;
      }
    }
};
