
n = int(input()) ;
d= [] ;
q = 0 ;

while(q != n) :
	
	
    s = list(input()) ;
    t = list(input()) ;
    q = q + 1 ;
    for i in range(0 , len(s)):
        if(s == t):
            print("PLUS");
            break ;
        if(i < len(t)):
            if(s[i] == t[i]):
            	if(i == len(s) - 1 and s != t):
            	    print("MINUS");
            	    break ;
            	pass ;	
               
            else :
                if(s[i] == "+" and t[i] == "-"):
                    print("MINUS");
                    break ;
                else :
                    if(i != len(s) ):
                        if( i + 1 < len(s) and s[i+1] == "-"):
                            s.pop(i) ;
                            s[i] = "+" ;
                    else :
                        print("MINUS");
                        break ;
                          
                        

        elif(i == len(t) and s != t) :
            print("MINUS");
            break ;
    
    
            
     
	
        

     
     
     
     
     
     
     
     
     
     
     
