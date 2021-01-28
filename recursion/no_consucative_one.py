

def strings(a,n,k):
	if n==0:
		print(a);
		return ;
	a[n-1]=0;
	strings(a,n-1,k);
	
	
	a[n-1]=1;
	if((n!=k) and a[n]==0 ):
		strings(a,n-1,k);
	elif n==k :
		strings(a,n-1,k);
	return ;
	

a=[1,1,1];

strings(a,3,3);
