
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n, rep = 0,count = 0 ;
    printf("Enter total number to be input: ");
	scanf( "%d", &n ) ;
	int *arr = (int*) malloc( sizeof(int) *n ) ;
    printf("Enter the elements: ");
	for( int i = 0; i < n; i++ )
		scanf( "%d", arr +i ) ;
	for( int i = 0; i < n; i++ ){
		for( int j = i +1; j < n; j++ ){
			if( arr[ i ] == arr[ j ] )
				count++ ;
		}
		if( count > 1 )
			rep++ ;
		if( rep == 3 ){
			rep = arr[ i ] ;
			break ;
		}
	}
	printf( "\n3rd Rep Element: %d\n", rep ) ;
	return 0;
}
