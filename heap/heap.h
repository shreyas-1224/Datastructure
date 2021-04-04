
typedef struct node{
	
	int *arr ; 
	int size , rear ;
}heap ;

void init_heap(heap* , int ) ;
void insert_heap(heap* , int) ;
void traverse_heap(heap) ;
void delete_heap(heap* );
void swap(int* , int*);
void min_to_max(heap* );
void heapify(heap* , int);
void max_to_min(heap* );
void heapify_min(heap* , int);


