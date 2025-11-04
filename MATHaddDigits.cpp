// my solution - works
class Solution {
public:
    int addingDigits(int num) {
        int sum=0;
        // int digits=0;
        int rem;
        while(num!=0)
        {
            rem=num%10; //8
            num=num/10; //3
            sum+=rem;
        }
        return sum;
    }

    int digits(int num){
        int digit=0;
        while(num!=0)
        {
            num=num/10;
            digit++;
        }
        return digit;
    }

    int addDigits(int num) {
        if (num==0)
            return 0;
        int digit=digits(num);
        while(digit!=1)
        {
            num=addingDigits(num);
            digit=digits(num);
        }
        return num;
    }
};

// AI optimised - counting digits is done in the same function
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) { // while more than one digit
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

// Most optimised - constant time solution - only mathematical formula
// ans= 1+(num-1)%9
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};
