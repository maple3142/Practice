#include<iostream>
#include<vector>
using namespace std;

struct Mage{
	int hp=0,atk=0,def=0;
	Mage(){
		
	}
	Mage(int a,int b,int c){
		hp=a;
		atk=b;
		def=c;
	}
};
struct Attack{
	int w,e;
	char x;
	Attack(int a,int b,char c){
		w=a;
		e=b;
		x=c;
	}
};
Mage our[10],enemy[10];
int main(void){
	ios::sync_with_stdio(false);
	int T,n,m,q;
	cin>>T;
	while(T--){
		cin>>n>>m>>q;
		int p,h,a,d;
		for(int i=1;i<=n;i++){
			cin>>p>>h>>a>>d;
			our[p]=Mage(h,a,d); 
		}
		for(int i=1;i<=m;i++){
			cin>>p>>h>>a>>d;
			enemy[p]=Mage(h,a,d);
		}
		
		bool what=false;
		int w,e;
		char x;
		vector<Attack> v;
		for(int i=1;i<=q;i++){
			Mage *OUR=our,*ENEMY=enemy;
			if(i%2==0)swap(OUR,ENEMY);
			int tmp=3;
			while(tmp--){
				cin>>w>>e>>x;
				v.emplace_back(w,e,x);
				if(OUR[w].hp==0)what=true;
			}
			if(what)continue;
			
			double attackB=1,attackPuellaCombo=1;
			if(v[0].w==v[1].w&&v[1].w==v[2].w)attackPuellaCombo=1.2;
			for(Attack act:v){
				Mage *a=&OUR[act.w];
				Mage *b=&ENEMY[act.e];
				double base=a->atk-b->def/3.0;
				if(act.x=='B')attackB=0.8;
				int dmg=max(base*attackB*attackPuellaCombo,0.0);
				if(act.x=='A'){
					b->hp=max(0,b->hp-dmg);
				}
				if(act.x=='B'){
					int st=act.e;
					if(st%3==0)st-=2;
					else st=3*(st/3)+1;
					for(int i=0;i<3;i++){
						int ob=i+st;
						ENEMY[ob].hp=max(0,ENEMY[ob].hp-dmg);
					}
				}
			}
		}
		if(what)cout<<"WHAT!?"<<endl;
		else{
			bool ouralive=false,enemyalive=false;
			for(int i=1;i<=9;i++){
				if(our[i].hp>0)ouralive=true;
			}
			for(int i=1;i<=9;i++){
				if(enemy[i].hp>0)enemyalive=true;
			}
			if(ouralive&&enemyalive)cout<<"Draw!"<<endl;
			else if(ouralive)cout<<"Win!";
			else cout<<"Lose!"<<endl;
		}
	}
	return 0;
}

