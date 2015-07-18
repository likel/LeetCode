class Solution {
public:
    int countDigitOne(int n) {
        int d[20][20];
        memset(d, 0, sizeof(d));

        int bits[20], k = 0, temp = n;
        while (temp) {
            bits[k++] = temp % 10;
            temp /= 10;
        }
        int ans = 0;

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j <= 9; j++) {
                if (j == 1) {
                    d[i][j] += pow(10, i - 1);
                }
                int t = 0;
                for (int q = 0; q <= 9; q++) {
                    t += d[i - 1][q];
                }
                d[i][j] += t;

                if (i == k) {
                    if (j < bits[k - 1]) {
                        ans += d[i][j];
                    } else if (j == bits[k - 1]) {
                        int x = n;
                        //if (j == 1) {
                        //    ans += n - pow(10, i - 1);
                        //}
                        for (int l = i - 1; l >= 1; l--) {
                            for (int p = 0; p < bits[l - 1]; p++) {
                                ans += d[l][p];
                            }

                           // cout << "X" <<  x << endl;
                            x -= pow(10, l) * bits[l];

                            if (bits[l] == 1) {
                                ans += x;
                            }
                        }
                        for (int l = 0; l < k; l++)
                           if (bits[l] == 1)ans++;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
private:
    int pow(int n, int c) {
        int t = 1;
        for (int j = 0; j < c ;j++)
            t *= n;
        return t;
    }
};


int getTest(int n) {
    int tt = 0;
    for (int i = 0; i <= n; i++) {
        int t = i;
        while (t) {
            if (t % 10 == 1)tt++;
            t /= 10;
        }
    }
    return tt;
}
