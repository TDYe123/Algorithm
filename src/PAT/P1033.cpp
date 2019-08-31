#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
 
struct Station {
    double p, d;
} stations[510];
 
bool cmp(Station s1, Station s2) {
    return s1.d < s2.d;
}
 
int main() {
    double tank, d, d_avg;
    int n;
    // ����
    cin >> tank >> d >> d_avg >> n;
    for (int i = 0; i < n; i ++) {
        cin >> stations[i].p >> stations[i].d;
    }
    // ����
    sort(stations, stations+n, cmp);
    // �����ʼ��û�м���վ����ֱ���������������
    if (stations[0].d != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double ans = 0;
    double one_dis = tank * d_avg; // �������ߵ������
    double current_tank = 0; // ��¼��ǰʣ������
    int pos = 0; // ��¼��ǰ�ڵļ���վ�ı��
    while (1) {
        int target = pos; // ��¼�¸�Ҫ����ļ���վ������
        double tmp = stations[pos+1].p; // ��¼��С�ͼ�
        double farrest = current_tank * d_avg + stations[pos].d; // ��¼��ǰ�������ߵ���������
        // Ѱ�ҵ��г��ڱȵ�ǰ����վ�ͼ۵͵ĵ�һ������վ������Ҳ����������ͼ���͵ļ���վ
        for (int i = pos+1; i < n; i ++) {
            if (stations[i].d > stations[pos].d+one_dis) break;
            if (stations[i].p < stations[pos].p) {
                target = i;
                break;
            }
            if (stations[i].p <= tmp) {
                target = i;
                tmp = stations[i].p;
            }
        }
        // �����ǰ����վ����û�м���վ���ߺ���ļ���վ���ﲻ��
        if (target == pos) {
            // �ܵ����յ�
            if (stations[pos].d + one_dis >= d) {
                if (farrest < d) {
                    ans += stations[pos].p * (d-farrest) / d_avg;
                }
                printf("%.2lf\n",ans);
            }
            // ���ܵ����յ�
            else {
                printf("The maximum travel distance = %.2lf", stations[pos].d+one_dis);
            }
            break;
        }
        // ���Ŀ�����վ���ͼ۱ȵ�ǰ����վ�ͼ۸�
        if (stations[target].p >= stations[pos].p) {
            if (stations[pos].d + one_dis >= d) {
                if (farrest < d) {
                    ans += stations[pos].p * (d-farrest) / d_avg;
                }
                printf("%.2lf\n",ans);
                break;
            }
            else {
                ans += stations[pos].p * (tank-current_tank);
                current_tank = tank - (stations[target].d-stations[pos].d) / d_avg;
                pos = target;
            }
        }
        // �������������һ������վ
        else {
            if (farrest < stations[target].d) {
                ans += stations[pos].p * (stations[target].d-farrest) / d_avg;
                current_tank += (stations[target].d-farrest) / d_avg;
            }
            current_tank -= (stations[target].d-stations[pos].d) / d_avg;
            pos = target;
        }
    }
    return 0;
}
