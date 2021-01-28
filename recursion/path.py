"""
def path(i,j,m,n,a,result):
	
	if(i==m-1 and j==n-1):
		print(a);
		result= result + 1;
		return ;
	if(i<0 or j<0 or j>=n or i>=m):
		return ;
	a.append('R');
	path(i+1,j,m,n,a,result);
	a.pop();
	a.append('D');
	path(i,j+1,m,n,a,result);
	a.pop();
	return ;

a=[];	
result=0;
path(0,0,5,5,a,result);

print('total paths are : '+ str(result));

"""

# n cell linear path problem.



def path(i,n,a):
	if(i==n-1):
		print(a);
		return ;
	if(i>=n):
		
		return ;
	a.append(1);	
	path(i+1,n,a);
	a.pop();
	a.append(2);
	path(i+2,n,a);
	a.pop();
	a.append(3);
	path(i+3,n,a);
	a.pop();
	a.append(4);
	path(i+4,n,a);
	a.pop();
	a.append(5);
	path(i+5,n,a);
	a.pop();
	a.append(6);
	path(i+6,n,a);
	a.pop();
	return ; 

a=[];
path(0,6,a);
	
	

























