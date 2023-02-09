#include <stdio.h>

int main(){
    int score = 2;
    while (score > 1){
        //get user input
        printf("0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1)
            break;
        
        //kill program if inputted score <= 1

        /* point values:
         *
         * Safety: 2 points
         * Field Goal (FG): 3 points
         * Touchdown (TD): 6 points
         * TD + 1 point field goal: 7
         * TD + 2 point conversion: 8
         */

        printf("\n     TD + 2pt   TD + FGs   TDs        3pt FGs    Safeties\n");
        
        int running_score, count = 0;
        int sfty, fg, td, td1, td2;
        for (sfty = 0; sfty <= score/2; sfty++){
            for (fg = 0; fg <= score/3; fg++){
                for (td = 0; td <= score/6; td++){
                    for (td1 = 0; td1 <= score/7; td1++){
                        for (td2 = 0; td2 <= score/8; td2++){
                            running_score = sfty*2 + fg*3 + td*6
                                            + td1*7 + td2*8;
                            if (running_score == score){
                                count++;
                                printf("%3d) %-11d%-11d%-11d%-11d%-11d", count,
                                            td2, td1, td,  fg,  sfty );
                                
                                printf("\n");
                            }
                        }
                    }
                }
            }
        }

        printf("\n");

    }
    


    return 0;
}
