
n = int(input("enter the number"))
a = list(range(1 , n+1));

i = 1 ;
while (len(a) != 1):
	a.pop(i) ;
	i = i + 1 ;
	if(i > len(a)-1 ):
		i = 0 ;
	
print(a[0]);
