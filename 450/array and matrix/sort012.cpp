void sort012(int a[], int n)
    {
       int zero = 0 ;
       int one = 0 ; 
       int two = 0 ;
       
       for(int i = 0 ; i < n ; i++){
            
            if(a[i] == 0)
                zero++ ;
            else if(a[i] == 1)
                one++ ;
            else
                two++ ;
             
       }
      
       for(int i = 0 ; i < zero ; i++){
           a[i] = 0 ;
       }
       for(int i = 0 ; i < one ; i++){
           a[zero + i] = 1;
          
       }
       for(int i = 0 ; i < two ; i++){
           
           a[i + one + zero] = 2 ;
       }
       
        
    }
