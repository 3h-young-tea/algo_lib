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
	tree *ls,*rs;
	int l,r;
	ll v,t;
	_Bool in_rng(int,int);
	void upd(ll);
	void push_up();
	void push_down();
	void update(int,int,ll);
	ll query(int,int);
	void build(int,int,ll*);
	void squib();
};

_Bool tree::in_rng(int x,int y){
	return x<=l&&r<=y;
}

void tree::upd(ll k){
	t+=k;
	v+=k*(r-l+1);
}

void tree::push_up(){
	v=ls->v+rs->v;
}

void tree::push_down(){
	if(t==0){
		return;
	}	ls->upd(t);
	rs->upd(t);
	t=0;
}

void tree::update(int x,int y,ll k){
	if(in_rng(x,y)){
		return upd(k);
	}	push_down();
	if(x<=ls->r){
		ls->update(x,y,k);
	}	if(rs->l<=y){
		rs->update(x,y,k);
	}	push_up();
}

ll tree::query(int x,int y){
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

void tree::build(int x,int y,ll *a){
	l=x;
	r=y;
	t=0;
	if(x==y){
		v=a[x];
		return;
	}	int z=x+y>>1;
	ls=(tree*)malloc(sizeof(tree));
	ls->build(x,z,a);
	rs=(tree*)malloc(sizeof(tree));
	rs->build(z+1,y,a);
	push_up();
}

void tree::squib(){
	if(l==r){
		return;
	}	ls->squib();
	rs->squib();
	free(ls);
	free(rs);
	ls=rs=NULL;
}

int n,q;
ll a[N];
tree *rt;

signed main(){
	int x,y;
	ll z;
	scanf(" %d %d",&n,&q);
	rt=(tree*)malloc(sizeof(tree));
	for(int i=1;i<=n;i++){
		scanf(" %lld",a+i);
	}	rt->build(1,n,a);
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
	}	rt->squib();
	free(rt);
	rt=NULL;
	return 0;
}
