#include <stdio.h>
#include <stdlib.h>

#include <time.h>

void tobeRed(){
    printf("\033[1;31m");
}

int tobeYellow(){
    printf("\033[1;33m");
}

int tobeWhite(){
    printf("\033[0m");
}

int main() {

    int **PACK = malloc(8 * sizeof(int*));

    for (int y = 0; y < 8; y++) {
        PACK[y] = malloc(8*sizeof(int));
        for (int x = 0; x < 8; x++) {
            PACK[y][x] = 0;

        }
    }


    for (;;){
        //生成//
        time_t t;
        time(&t);


        for (int i = 0; i < 4; i++){
            int addressX = rand()%8;
            int addressY = rand()%8;
            //printf("%d %d\n",addressY,addressX);
            if (PACK[addressY][addressX] == 0){
                PACK[addressY][addressX] = ((t%2+2)%2)*2;
            }
            else{
                i--;
            }
        }




        //畫面//
        for (int y = 0; y < 8; y++) {

            for (int x = 0; x < 8; x++) {
                if (PACK[y][x] != 0){
                    tobeRed();
                }else
                {
                    tobeWhite();
                }
                printf("-----   ", PACK[y][x]);
            }
            printf("\n");
            for (int x = 0; x < 8; x++) {
                if (PACK[y][x] != 0){
                    tobeRed();
                }else
                {
                    tobeWhite();
                }
                printf("| %d |   ", PACK[y][x]);
            }
            printf("\n");
            for (int x = 0; x < 8; x++) {
                if (PACK[y][x] != 0){
                    tobeRed();
                }else
                {
                    tobeWhite();
                }
                printf("-----   ", PACK[y][x]);
            }
            printf("\n");
            tobeWhite();
        }



        char in[3];
        scanf("%s", &in);

        //控制//

        if (in[0] == 'q') {
            break;
        }

        if (in[0] == 'a') {
            for (int y = 0; y < 8; y++) {
                int Count = 0;
                int lastCounted = 0;
                for (int x = 0; x < 8; x++) {
                    if (PACK[y][x] == 0) {}else{
                        int me = PACK[y][x];
                        PACK[y][x] = 0;
                        if (me == PACK[y][Count-1] && lastCounted!=1){
                            PACK[y][Count-1] = me*2;
                            lastCounted = 1;
                        }else{
                            PACK[y][Count] = me;
                            lastCounted=0;
                            Count++;
                        }
                    }
                }
            }
        }

        if (in[0] == 'd') {
            for (int y = 0; y < 8; y++) {
                int Count = 0;
                int lastCounted = 0;
                for (int x = 0; x < 8; x++) {
                    if (PACK[y][7-x] == 0) {}else{
                        int me = PACK[y][7-x];
                        PACK[y][7-x] = 0;
                        if (me == PACK[y][7-Count+1] && lastCounted!=1){
                            PACK[y][7-Count+1] = me*2;
                            lastCounted = 1;
                        }else{
                            PACK[y][7-Count] = me;
                            lastCounted=0;
                            Count++;
                        }
                    }
                }
            }
        }

        if (in[0] == 'w') {
            for (int x = 0; x < 8; x++) {
                int Count = 0;
                int lastCounted = 0;
                for (int y = 0; y < 8; y++) {
                    if (PACK[y][x] == 0) {}else{
                        int me = PACK[y][x];
                        PACK[y][x] = 0;
                        if (Count-1>=0&&me == PACK[Count-1][x] && lastCounted!=1){
                            PACK[Count-1][x] = me*2;
                            lastCounted = 1;
                        }else{
                            PACK[Count][x] = me;
                            lastCounted=0;
                            Count++;
                        }
                    }
                }
            }
        }

        if (in[0] == 's') {
            for (int x = 0; x < 8; x++) {
                int Count = 0;
                int lastCounted = 0;
                for (int y = 0; y < 8; y++) {
                    if (PACK[7-y][x] == 0) {}else{
                        int me = PACK[7-y][x];
                        PACK[7-y][x] = 0;
                        if (7-Count+1<=7&&me == PACK[7-Count+1][x] && lastCounted!=1){
                            PACK[7-Count+1][x] = me*2;
                            lastCounted = 1;
                        }else{
                            PACK[7-Count][x] = me;
                            lastCounted=0;
                            Count++;
                        }
                    }
                }
            }
        }
    }
}
