#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int ax,ay, bx,by, cx,cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	/*
		a^2 + b^2 = c^2
		ピタゴラスの定理で三辺の長さを求める
	*/
	long double ab = sqrtl(abs(ay - by) * abs(ay - by) + abs(ax - bx) * abs(ax - bx));
	long double ac = sqrtl(abs(ay - cy) * abs(ay - cy) + abs(ax - cx) * abs(ax - cx));
	long double bc = sqrtl(abs(by - cy) * abs(by - cy) + abs(bx - cx) * abs(bx - cx));
	/*
		*ヘロンの公式 三辺a,b,cの長さを用いる*
		s    = (a+b+c)/2
		ANS  = √(s * (s-a) * (s-b) * (s-c))
	*/
	long double s = (ab+ac+bc) / 2;
	long double ans = sqrtl(s * (s-ab) * (s-ac) * (s-bc));
	printf("%.1Lf\n", ans);

	/* 別解: 符号付面積 (0,0) (a,b) (c,d) => |ad - bc| / 2 */
	int a,b,c,d;
	a = bx - ax; b = by - ay;
	c = cx - ax; d = cy - ay;
	long double ans2 = (long double)abs(a*d - b*c) / 2;
	printf("%.1Lf\n", ans2);
	return (0);
}
