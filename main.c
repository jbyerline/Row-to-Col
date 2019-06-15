//
//  main.c
//  Caesar Block Cypher
//
//  Created by jbyerline on 10/20/18.
//  Copyright © 2018 hack25. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    
    char *str;
    int inputChar;
    int i, j, twoDimensionalArraySize;
    size_t size = 0;
    size_t len = 0;
    
    // Sets Memory to Null, Then allocates memory
    str = calloc(0, sizeof(char)*size);
    free(str);
    
    // While not end of file or new line, input inputChar from keyboard
    while((inputChar=fgetc(stdin)) != EOF){
        
        // If the character inputed is not in the alphabet or a '.' Then disregard it
        if((inputChar <= 122 && inputChar >= 97) || (inputChar <= 90 && inputChar >= 65) || inputChar == ' ' ){
            
            //Put the character read into the 1D array str[]
            str[len++] = inputChar;
            
        }
        
    }
    
    // Take the Square Root of the length of the 1D array
    double squareOfLen = sqrt(len);
    // Cast the result of the square root to a type int, to get rid of decimals
    int integerSquare = squareOfLen;
    // If the result is a perfect square then set it egual to the length of the 2D array
    if ( integerSquare *  integerSquare == len)
        
        twoDimensionalArraySize = squareOfLen;
    
    // If the result is not a perfect square then add one, to be sure all the components can fir into the 2D square array
    else  twoDimensionalArraySize = squareOfLen + 1 ;
    
    //Test Code
    /*printf("%lu String Length\n", len);
     printf("%.3lf Squar Root of String Length\n", squareOfLen);
     printf("%d Integer Squar Root of String Length\n", integerSquare);
     printf("%d X %d Array Size\n", twoDimensionalArraySize, twoDimensionalArraySize);*/
    
    //Declare the two 2D arrays, one for [ROW][COL] and the other for [COL][ROW]
    char twoDstr[twoDimensionalArraySize][twoDimensionalArraySize];
    char FINALtwoDstr[twoDimensionalArraySize][twoDimensionalArraySize];
    
    // Copy the 1D array into the 2D array
    memcpy(twoDstr, str, twoDimensionalArraySize * 2 * sizeof(int));
    
    // Test loop to make sure copy was correct
    for(i=0; i<twoDimensionalArraySize; i++){
     for(j=0; j<twoDimensionalArraySize; j++){
     printf("2D Array[%d][%d] = %c\n",i,j,twoDstr[i][j]);
     }
     }
    
    // Loop to read in 2nd 2D array
    for(i=0; i<twoDimensionalArraySize; i++){
        for(j=0; j<twoDimensionalArraySize; j++){
            // If an array value is empty, insert a ' '
            if(twoDstr[i][j] == 0){
                twoDstr[i][j] = ' ';
            }
            // Change from [ROW][COL] to [COL][ROW] order
            FINALtwoDstr[i][j] = twoDstr[j][i];
            
            // Test Code to ensure the arrays copied correctly
            /*printf("2D Array[%d][%d] = %c\n",i,j,FINALtwoDstr[i][j]);*/
            
            // If array value is 0, print a ' '
            if (FINALtwoDstr[i][j] == 0){
                
                printf(" ");
            }
            // Else, print array values
            else printf("%c",FINALtwoDstr[i][j]);
            
        }
    }
    // Print new line
    printf("\n");
    
    return 0;
    
}
