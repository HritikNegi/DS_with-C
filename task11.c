
#include <stdio.h>
#include <string.h>

void display( int *Stak, int top ){

	printf( "\nElements of Stack: " ) ;
	while( top >= 0 ){
	
		printf( "%d ", Stak[ top ] ) ;
		top-- ;
	}
	
	printf( "\n" ) ;
}

void push( int *Stak, int *top, int val ){
	
	*top += 1;
	Stak[ *top ] = val ;
}

void pop( int *Stak, int *top ){

	*top -= 1 ;
}

int peek( int *Stak, int top ){
	return Stak[ top ] ;
}

int prcdnc( char c ){
    
    switch( c ){
        
        case '+':
        case '-':   return 1 ;
        
        case '*':
        case '/':   return 2 ;
        
        case '^':   return 3 ;
        
        case '\0':
        case '(':   return -1 ; 
        case ')':   return -10 ; 
        
        default :   return 0 ;  
    }
}

int evl_pos( char s[] ){
    
	int stk [ strlen( s ) ] ;
	int top = -1 ;

    for( int i = 0; s[ i ] != '\0'; i++ ) {
        
        if( s[ i ] >= '0' && s[ i ] <= '9' ){  

            push( stk, &top, s[ i ] -'0' ) ;
            
        }
        else{
            int opr2 = peek( stk, top );
            pop( stk, &top ) ;

            int opr1 = peek( stk, top );
            pop( stk, &top ) ;
            
            int ans = 0 ;
            switch( s[ i ] ){
                
                case '+':   ans = opr1 + opr2 ;      break ;
                case '-':   ans = opr1 - opr2 ;      break ;
                case '*':   ans = opr1 * opr2 ;      break ;
                case '/':   ans = opr1 / opr2 ;      break ;
                case '^':   ans = opr1 ^ opr2 ;      break ;
            }
            push( stk, &top, ans ) ;
        }
    }
    
    return peek( stk, top ) ;
}

int main(){
    
    char s[ 50 ] ;
    printf("\nEnter Postfix Expression: ");
    scanf( "%s", s ) ;

    printf( "\nAns: %d\n", evl_pos( s ) ) ; 

	return 0 ;
}
