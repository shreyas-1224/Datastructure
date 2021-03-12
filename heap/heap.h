
typedef struct node{
	
	int *arr ; 
	int size , rear ;
}heap ;

void init_heap(heap* , int ) ;
void insert_heap(heap* , int) ;
void traverse_heap(heap) ;
void delete_heap(heap* );



