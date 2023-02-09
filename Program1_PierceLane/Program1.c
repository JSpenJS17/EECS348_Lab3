#include <stdio.h>
//imported for string to float conversion function
#include <stdlib.h>

//define months for the whole program
char *months[] = {"January", "February", "March", "April", "May", "June",
                  "July", "August", "September", "October", "November",
                  "December"};


int min(float *sales, int length){
    //find the min of a given array
    int min_index = 0;
    int i;
    for (i = 0; i < length; i++){
        if (sales[i] < sales[min_index])
            min_index = i;
    }
    return min_index;
}

int max(float *sales, int length){
    //find the max of a given array
    int max_index = 0;
    int i;
    for (i = 0; i < length; i++){
        if (sales[i] > sales[max_index]){
            max_index = i;
        }
    }
    return max_index;
}

float avg(float *sales, int start_ind, int end_ind){
    //find the average of an array between two indices
    //end_ind is exclusive, similar to range() in Python
    float sum = 0;
    int i;
    for (i = start_ind; i < end_ind; i++){
        sum += sales[i];
    }
    return sum/(end_ind-start_ind);
}

void print_sales(float *sales){
    //print the sales as they came
    printf("Month      Sales\n");
    int i;
    for (i = 0; i < 12; i++){
        printf("%-11s$%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

void print_stats(float *sales){
    //print the min, max, and average of sales
    int min_i = min(sales, 12);
    int max_i = max(sales, 12);
    printf("Minimum sales: $%.2f  (%s)\n", sales[min_i], months[min_i]);
    printf("Maximum sales: $%.2f  (%s)\n", sales[max_i], months[max_i]);
    printf("Average sales: $%.2f\n", avg(sales, 0, 12));
}

void six_month(float *sales){
    //print the six-month moving average report of sales
    printf("\nSix-Month Moving Average Report:\n\n");
    int mo_offset;
    for (mo_offset = 0; mo_offset <= 6; mo_offset++){
        printf("%-11s-   %-11s$%.2f\n",
                months[mo_offset],
                months[mo_offset+5], 
                avg(sales, mo_offset, mo_offset + 6));
    }
    printf("\n");
}

void print_sorted(float *sales){
    //print out sales sorted in descending order.
    char *months_cpy[12];
    float temp_sale;
    char *temp_mo;
    int i, j;

    //make a copy of months
    for (i = 0; i < 12; i++){
        months_cpy[i] = months[i];
    }

    //sort sales and copy the movements onto months_cpy
    //this is so that the months always correctly line up with their sale values
    for (i = 0; i < 11; i++){
        for (j = 0; j < 11; j++){
            if (sales[j] < sales[j+1]){
                //swap sale position
                temp_sale = sales[j];
                sales[j] = sales[j+1];
                sales[j+1] = temp_sale;

                //also swap month position
                temp_mo = months_cpy[j];
                months_cpy[j] = months_cpy[j+1];
                months_cpy[j+1] = temp_mo;
            }
        }
    }

    //finally, print the result to the user
    printf("Month      Sales\n");
    for (i = 0; i < 12; i++){
        printf("%-11s$%.2f\n", months_cpy[i], sales[i]);
    }
}

int main(){
    float sales[12];
    
    //get input file name
    char file_name[50];
    FILE *file;
    do {
        printf("Sales file name: ");
        scanf("%s", file_name);
        file = fopen(file_name, "r");
    } while (file == NULL);
    
    //load the values into sales
    char line[50];
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL){
        //needed to import stdlib to do this bit
        sales[i] = atof(line);
       i++;
    }
    printf("\n");
    
    /* Do the sales report */
    
    //print sales out
    print_sales(sales);
    printf("\n");

    //print max, min, and average values
    print_stats(sales);
    printf("\n");

    //print the six-month rolling averages
    six_month(sales);
    printf("\n");

    //print the sales sorted
    print_sorted(sales);

    return 0;
}
