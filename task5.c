
#include <stdio.h>
#include <stdlib.h>

void display( char *Stak, int top ){

	printf( "\nElements of Stack: " ) ;
	while( top >= 0 ){
	
		printf( "%c ", Stak[ top ] ) ;
		top-- ;
	}
	
	printf( "\n" ) ;
}

void push( char *Stak, int *top, char val ){
	
	*top += 1;
	Stak[ *top ] = val ;
}

void pop( char *Stak, int *top ){
	*top -= 1 ;
}

char peek( char *p, int top ){
        
    return p[ top ] ;
}

int prcdnc( char c ){
    
    switch( c ){
        
        case '+':
        case '-':   return 1 ;
        
        case '*':
        case '/':   return 2 ;
        
        case '^':   return 3 ;
        
        default :   return 0 ;  
    }
}

void itp( char s[], char *stk, int *top ){
    int j = 0 ;
    
    for( int i = 0; s[ i ] != '\0'; i++ ){
        
        int x = prcdnc( s[ i ] ) ;
        
        if( s[ i ] == '(' || x > prcdnc( peek( stk, *top ) ) ){   
            push( stk, top, s[ i ] ) ;
        }
            
        else if( s[ i ] == ')' ) {  
            
            while( peek( stk, *top ) != '(' ){

            	s[ j ] = peek( stk, *top ) ;
                pop( stk, top ) ;
                j++ ;
            }
            pop( stk, top ) ; 
        }
        
        else if( x == 0 ){   
            s[ j ] = s[ i ] ;
            j++ ;
        }
   
        else{

             while( prcdnc( peek( stk, *top ) ) >= x  ){
             	s[ j ] = peek( stk, *top ) ;
                pop( stk, top ) ;
                j++ ;
            }
            
            push( stk, top, s[ i ] ) ;
        }
    }

    while( *top != -1 ){
    	s[ j ] = peek( stk, *top ) ;
        pop( stk, top ) ;
        j++ ;
    }
    
    s[ j ] = '\0' ;
}

int main(){
    char s[ 50 ] ;
    printf("Enter the infix expression: ");
    scanf( "%s", s ) ;
    int len= sizeof( s ) / sizeof( s[ 0 ] ) ;
    char sptr[len] ;
    int top = -1 ;
    itp( s, sptr, &top ) ;
    for( int i = 0; s[ i ] != '\0'; i++ ){
        printf( "%c", s[ i ] ) ;
    }
	printf( "\n" ) ;
	return 0 ;
}
