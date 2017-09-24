//小到大
sort(E,E+m,[](const edge &a,const edge &b){
	return a.w<b.w;
});