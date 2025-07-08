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

void vsort(void *a,ull len,ull sz,ll (*cmp)(void*,void*)){
	char *p=(char*)(a);
	char *x,*y,*z,*f,*g,*h;
	char *tmp=(char*)malloc(len*sz);
	if(tmp==NULL){
		return;
	}	for(ull w=1;w<len;w<<=1)
	for(ull i=0;i<len;i+=w<<1){
		f=p+i*sz;
		g=p+cmin(i+w,len)*sz;
		h=p+cmin(i+(w<<1),len)*sz;
		x=f;
		y=g;
		z=tmp;
		while(x<g&&y<h){
			if(cmp(x,y)<=0){
				memcpy(z,x,sz);
				x+=sz;
			}else{
				memcpy(z,y,sz);
				y+=sz;
			}	z+=sz;
		}	while(x<g){
			memcpy(z,x,sz);
			x+=sz;
			z+=sz;
		}	while(y<h){
			memcpy(z,y,sz);
			y+=sz;
			z+=sz;
		}	memcpy(f,tmp,h-f);
	}	free(tmp);
}

void* bquery(void *k,void *a,ull len,ull sz,ll (*cmp)(void*,void*)){
	ull x=0,y=len,z;
	char *p=(char*)(a);
	while(x<y){
		z=x+y>>1;
		if(cmp(k,p+z*sz)<=0){
			y=z;
		}else{
			x=z+1;
		}
	}	return x<len?p+x*sz:NULL;
}

ull v2rk(ll *a,ll *b,ull len,ll (*cmp)(void*,void*),_Bool jqk){
	ll *val=b;
	if(jqk==0){
		memcpy(b,a,len*sizeof(ll));
	}	vsort(b,len,sizeof(ll),cmp);
	for(ull i=1;i<len;i++){
		if(b[i]!=b[i-1]){
			*++val=b[i];
		}
	}	for(ull i=0;i<len;i++){
		a[i]=(ll*)bquery(a+i,b,val-b+1,sizeof(ll),cmp)-b+1;
	}	return val-b+1;
}

ll cmp(void *x,void *y){
	return (*(ll*)(x)>*(ll*)(y))-(*(ll*)(x)<*(ll*)(y));
}

ull t,n,v;
ll a[N],b[N];

signed main(){
	scanf(" %llu",&t);
	while(t--){
		scanf(" %llu",&n);
		for(ull i=1;i<=n;i++){
			scanf(" %lld",a+i);
			b[i]=a[i];
		}	v=v2rk(a+1,b+1,n,cmp,1);
		for(ull i=1;i<=n;i++){
			printf("%lld%c",a[i],cend(n));
		}
	}	return 0;
}
