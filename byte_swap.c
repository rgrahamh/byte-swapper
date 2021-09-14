#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    if(argc == 1){
        printf("Please specify a file\n");
        return 1;
    }
    
    // Second argument is taken as the file name no matter what
    FILE* file = fopen(argv[1], "rb");
    if(file == NULL){
        fprintf(stderr, "File %s not found!\n", argv[1]);
        return 2;
    }

    int swap_size = 16;
    // Third argument is optional; a 16-bit swap will be used if nothing is passed in
    if(argc == 3){
        swap_size = atoi(argv[2]);
        printf("Doing a %i-bit swap.\n", swap_size);
    }

    if(swap_size % 8){
        printf("Please use proper byte alignment.\n");
        return 3;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char new_file_name[strlen(argv[1])+5];
    sprintf(new_file_name, "%s.rev", argv[1]);
    FILE* new_file = fopen(new_file_name, "wb");

    int swap_num = swap_size / 8;

    char char_buf[swap_num+1];
    char_buf[swap_num] = '\0';

    for(int i = 0; i < size; i++){
        int buf_itr = swap_num - (i % swap_num) - 1;
        char_buf[buf_itr] = getc(file);

        if(buf_itr == 0){
            for(int j = 0; j < swap_num; j++){
                fprintf(new_file, "%c", char_buf[j]);
            }
        }
    }

    for(int i = swap_num - (size % swap_num); i < swap_num; i++){
        fprintf(new_file, "%c", char_buf[i]);
    }

    fclose(new_file);
    fclose(file);

    return 0;
}