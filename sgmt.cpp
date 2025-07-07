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
#define N (1<<18)
#define M (1<<19)
#define SqN (1<<9)
#define LgN (21)

typedef struct _tree tree;

struct _tree{
	_tree *ls,*rs;
	int l,r;
	ll v,t;
	_Bool in_rng(int x,int y){
		return x<=l&&r<=y;
	}
	void upd(ll k){
		t+=k;
		v+=k*(r-l+1);
	}
	void push_up(){
		v=ls->v+rs->v;
	}
	void push_down(){
		if(t==0){
			return;
		}	ls->upd(t);
		rs->upd(t);
		t=0;
	}
	void update(int x,int y,ll k){
		if(in_rng(x,y)){
			return upd(k);
		}	push_down();
		if(x<=ls->r){
			ls->update(x,y,k);
		}	if(rs->l<=y){
			rs->update(x,y,k);
		}	push_up();
	}
	ll query(int x,int y){
		if(in_rng(x,y)){
			return v;
		}	push_down();
		ll s=0;
		if(x<=ls->r){
			s+=ls->query(x,y);
		}	if(rs->l<=y){
			s+=rs->query(x,y);
		}	return s;
	}
	void build(int x,int y,ll *a,tree **cntt){
		l=x;
		r=y;
		t=0;
		if(x==y){
			v=a[x];
			return;
		}	int z=x+y>>1;
		ls=(cntt!=NULL)?++*cntt:(tree*)malloc(sizeof(tree));
		ls->build(x,z,a,cntt);
		rs=(cntt!=NULL)?++*cntt:(tree*)malloc(sizeof(tree));
		rs->build(z+1,y,a,cntt);
		push_up();
	}
};

int n,q;
ll a[N];
tree tr[N<<2],*cntt=tr,*rt=tr;

signed main(){
	int x,y;
	ll z;
	scanf(" %d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf(" %lld",a+i);
	}	rt->build(1,n,a,&cntt);
	while(q--){
		scanf(" %d",&x);
		if(x==1){
			scanf(" %d %d %lld",&x,&y,&z);
			rt->update(x,y,z);
		}else if(x==2){
			scanf(" %d %d",&x,&y);
			printf("%lld\n",rt->query(x,y));
		}else{
			puts("~");
		}
	}	return 0;
}
