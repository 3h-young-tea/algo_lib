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
#define N (1<<20)
#define M (1<<19)
#define SqN (1<<9)
#define LgN (21)

int n,k;
int a[N],f[N],g[N];
int que[N],*fr=que,*bk=que-1;

void solve(){
	fr=que,*(bk=que)=1;
	for(int i=1;i<=n;i++){
		while(fr<=bk&&*fr<=i-k){
			fr++;
		}	while(fr<=bk&&a[i]<=a[*bk]){
			bk--;
		}	*++bk=i;
		f[i]=a[*fr];
	}	fr=que,*(bk=que)=1;
	for(int i=1;i<=n;i++){
		while(fr<=bk&&*fr<=i-k){
			fr++;
		}	while(fr<=bk&&a[*bk]<=a[i]){
			bk--;
		}	*++bk=i;
		g[i]=a[*fr];
	}
}

signed main(){
	scanf(" %d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf(" %d",a+i);
	}	solve();
	for(int i=k;i<=n;i++){
		printf("%d%c",f[i],cend(n));
	}	for(int i=k;i<=n;i++){
		printf("%d%c",g[i],cend(n));
	}	return 0;
}
