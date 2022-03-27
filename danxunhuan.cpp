#include<cstdio>
using namespace std;
static int num,k,left,right;
void Schedule(int group,int frequency) {
    //k:每个队伍球队个数;group:队伍数;frequency:每个队伍比赛次数;
    for (int i = k; i > 0; i--) {
        printf("第%d轮:\n", k - i + 1);
        for (int t = 0; t < group; ++t) {//用了多边形轮转法(只写了奇数部分的，偶数的...因为不知道怎么分组，不来管了先。)
            left = (i + 1) % k ? (i + 1) % k : k;
            right = (i - 1) % k ? (i - 1) % k : k;
            for (int j = 0; j < frequency; j++) {//平行边数遍历
                printf("%c%d-%c%d;", (char) ((int) 'A' + t), left, (char) ((int) 'A' + t), right);
                left = (left + 1) % k ? (left + 1) % k : k;
                right = (right - 1) % k ? (right - 1) % k : k;
            }
            printf("%c%d轮空\n", (char) ((int) 'A' + t), i);
        }
    }
}
int main() {
    scanf("%d", &num);//球队个数
    //先默认除到奇数便停止分组
    //其他的再说。
    k = num;
    while (k % 2 == 0) k /= 2;//k:每个队伍球队个数；
    Schedule(num / k,k/2);//group:队伍数;frequency:每个队伍比赛次数;
    return 0;
}