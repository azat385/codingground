#include <stdio.h>

int *get_arr(int value){
    int array[8];
    //int* array = malloc(sizeof(int) * 8);
    int j;
    for (j = 0; j < 8; j++) {
            array[j] = (value >> j) & 1;
            //printf("%d",array[j]);
            }
    return array;
}
void print_arr(int *array){
    int i;
    //printf("%d %d %d \n",sizeof(array),sizeof(array[0]),sizeof(array)/sizeof(array[0]));
    for (i=0;i<sizeof(array)/sizeof(array[0]);i++){
        printf("%u ",array[i]);}
    printf("\n");
    free(array); array=NULL;
}
int main()
{
    int i,updown,j;
    int set_coil_value = 0b00000001;
    int *array;

    for (i=0;i<20;i++) {
        printf("%d %d ",i,set_coil_value);
        array = get_arr(set_coil_value);
        for (j=0;j<8;j++){printf("%u ",array[j]);}printf("\n");
        //print_arr(array);
        //for (j = 0; j < 8; j++) {
        //    array[j] = (set_coil_value >> j) & 1;
        //    printf("%d",array[j]);}
        printf("\n"); 
        if (set_coil_value==1) updown=1;
        if (set_coil_value==128) updown=0;
        if (updown)
            set_coil_value<<=1; 
        else 
            set_coil_value>>=1;
        
    }
    
    return 0;
}

