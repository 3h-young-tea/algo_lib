#include<assert.h>
#include<math.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define lf double
#define us unsigned
#define ll long long
#define ull us ll
#define cend(x) " \n"[i==x]
#define cmax(x,y) ((x)>(y)?(x):(y))
#define cmin(x,y) ((x)<(y)?(x):(y))
#define cswp(x,y,tp) do{tp __tmp=x;x=y;y=__tmp;}while(0)
#define Inf 0x3f3f3f3f3f3f3f3fll
#define Mod 0x3b800001
#define N (1<<22)
#define M (1<<19)
#define SqN (1<<9)
#define LgN (21)

int n;
int a[N],f[N];
int stk[N],*tp=stk-1;

void solve(){
	for(int i=n;i;i--){
		while(stk<=tp&&a[*tp]<=a[i]){
			tp--;
		}	if(stk<=tp){
			f[i]=*tp;
		}	*++tp=i;
	}
}

signed main(){
	scanf(" %d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %d",a+i);
	}	solve();
	for(int i=1;i<=n;i++){
		printf("%d%c",f[i],cend(n));
	}	return 0;
}
