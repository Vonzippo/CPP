set<int> data;
8

pair<set<int>::iterator ,bool>ret;
for(int i= 0 ;i<100; i++){
int number=rand() % 100 ;
ret = data.insert(number);
if(!(ret.second)){
cout<<"Could not insert "<< number << endl;
}
}
cout<< data.size() << endl;1819set<int> : :iterator it;20for(it=data.begin( ) ;it! =data.end( ) ;it++)   {21cout<<it<<endl;
}