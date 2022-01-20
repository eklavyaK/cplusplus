int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        long long int x; cin>>x; long long int sum = 0l,count=0;
        while(true) {count++; sum += ((long long int)pow(2,count)-1)*(long long int)pow(2,count-1);if(sum==x)break; if(sum>x){count--;break;}}
        cout<<count<<endl;
    }
    return 0;
}