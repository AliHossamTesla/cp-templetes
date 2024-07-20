void solve(){
	int days , items ; cin >> days >> items ;
	vector<vector<i64>>min_cost((1 << items),vector<i64>(days,inf)) ;
	vector<vector<int>>price(items,vector<int>(days)) ;
	for(int i = 0 ; i < items ; i ++)
		for(int j = 0 ; j < days ; j ++)
			cin >> price[i][j] ;
	for(int i = 0 ; i < days ; i ++)
		min_cost[0][i] = 0 ;
	for(int i = 0 ; i < items ; i ++)
		min_cost[1 << i][0] = price[i][0] ;
	for(int day = 1 ; day < days ;day ++){
		for(int mask = 0 ; mask < (1 << items) ; mask ++){
			min_cost[mask][day] = min_cost[mask][day - 1] ;
			for(int item = 0 ; item < items ; item ++){
				if(mask&(1 << item)){
					min_cost[mask][day] = min(min_cost[mask][day],
					                          min_cost[mask^(1 << item)][day - 1] + price[item][day]) ;
				}
			}
		}
	}
	cout << min_cost[(1 << items) - 1][days - 1] << '\n' ;
}