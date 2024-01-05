class Solution {
public:
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }
    int LCM(long long a, long long b) {
        long long temp = (a / gcd(a, b)) * b;
        if (temp > INT_MAX) {
            return INT_MAX;
        } else {
            return temp;
        }
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int lcm = LCM(divisor1, divisor2);
        int ans = -1;
        int low = 1, high = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;
            int divBy1 = mid/divisor1, divBy2 = mid/divisor2;
            if(uniqueCnt1 + uniqueCnt2 <= mid-mid/lcm && uniqueCnt1 <= mid-divBy1 && uniqueCnt2 <= mid-divBy2){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};