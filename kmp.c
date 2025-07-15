#include<math.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define lf double
#define us unsigned
#define ll long long
#define endl(x) " \n"[i==x]
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define swap(x,y) tmp=x;x=y;y=tmp
#define Inf 0x3f3f3f3f3f3f3f3fll
#define Mod 0x3b800001
#define N (1<<20)
#define M (1<<19)
#define SqN (1<<9)
#define LgN (21)

void kmp(char *s,char *p){
	ll slen,plen,*pi;
	plen=strlen(p);
	if(plen==0){
		return;
	}	slen=strlen(s);
	if(slen==0){
		return;
	}	pi=(ll*)calloc(plen,sizeof(ll));
	if(pi==NULL){
		return;
	}	for(int i=1,j=0;i<plen;i++){
		while(j&&p[j]!=p[i]){
			j=pi[j-1];
		}	if(p[j]==p[i]){
			j++;
		}	pi[i]=j;
	}	for(int i=0,j=0;i<slen;i++){
		if(s[i]!=p[j]){
			while(j&&s[i]!=p[j]){
				j=pi[j-1];
			}
		}	if(s[i]==p[j]){
			j++;
		}	if(j==plen){
			printf("%lld\n",i-j+2);
			j=pi[j-1];
		}
	}	for(int i=0;i<plen;i++){
		printf("%lld%c",pi[i],endl(plen-1));
	}	free(pi),pi=NULL;
}

char s[N],p[N];

signed main(){
	scanf(" %s %s",s,p);
	kmp(s,p);
	return 0;
}
