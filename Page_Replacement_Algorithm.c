/*the program simulates the Optimal Page Replacement algorithm to 
  determine the number of page faults based on the given reference string and number of frames.*/

#include<stdio.h>

int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);


    printf("Enter the number of pages in reference string: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page reference string: ");

    for(i = 0; i < no_of_pages; i++){
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < no_of_frames; i++){
        frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; i++){
        flag1 = flag2 = 0;

        for(j = 0; j < no_of_frames; j++){
            if(frames[j] == pages[i]){
                flag1 = flag2 = 1;
                break;
            }
        }
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            flag3 = 0;
            for(j = 0; j < no_of_frames; j++){
                temp[j] = -1;

                for(k = i + 1; k < no_of_pages; k++){
                    if(frames[j] == frames[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }

            for(j = 0; j < no_of_frames; ++j){
                if(temp[j] == -1){
                    pos = j;
                    flag3  = 1;
                    break;
                }
            }

            if(flag3 == 0){
                max = temp[0];
                pos = 0;

                for(j = 1; j < no_of_frames; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }        
        printf("\n");

        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal number of Page faults = %d\n", faults);

    return 0;
}