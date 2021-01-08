class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        while(num >= 0) {
            if(num >= 1000) {
                for(int i=0; i<num/1000; i++) {
                    ret = ret + 'M';
                }
                num = num % 1000;
                continue;
            } else if(num >= 500) {
                if(num/100 == 9) { // if 9XX
                    ret = ret + "CM";
                    num -= 900;
                    continue;
                }
               
                ret = ret + 'D';
                num = num % 500;
                continue;
            } else if(num >= 100) {
                if(num/100 == 4) { // if 4XX 
                    ret = ret + "CD";
                    num -= 400;
                    continue;
                }
                for(int i=0; i<num/100; i++) {
                    ret = ret + 'C';
                }
                num = num % 100;
                continue;
            } else if(num >= 50) {
                if(num/10 == 9) { // if 9X
                    ret = ret + "XC";
                    num -= 90;
                    continue;
                }
                ret = ret + 'L';
                num = num % 50;
                continue;
            } else if(num >= 10) {
                if(num/10 == 4) { // if 4X
                    ret = ret + "XL";
                    num -= 40;
                    continue;
                }
                for(int i=0; i<num/10; i++) {
                    ret = ret + 'X';
                }
                num = num % 10;
                continue;
            } else if(num >= 5) {
                if(num == 9) { // if 9
                    ret = ret + "IX";
                    num -= 9;
                    continue;
                }
                ret = ret + 'V';
                num = num % 5;
                continue;
            } else {
                if(num == 4) { // if 4
                    ret = ret + "IV";
                    break;
                }
                for(int i=0; i<num; i++) {
                    ret = ret + 'I';   
                }
                break;
            }
            
        }
        
        return ret;
    }
};