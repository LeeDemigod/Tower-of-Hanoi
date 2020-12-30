#include<stdio.h>

int row = 3;
int p[3][3] = {{1,0,0},
               {2,0,0},
               {3,0,0}};

void show(int input){
    if(input == 0){
        printf("         ");
    }
    if(input == 1){
        printf("   |1|   ");
    }
    if(input == 2){
        printf("  | 2 |  ");
    }
    if(input == 3){
        printf(" |  3  | ");
    }
}

void display(){
    for(int i=0; i<row; ++i){
        for(int j=0; j<3; ++j){
            show(p[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("----1---- ");
    printf("----2---- ");
    printf("----3----\n");
}

void scan(){
    int n, d, move_flag = 1;
    scanf("%d%d",&n,&d);

    if (n>0 && n<row+1 && d>0 && d<4 && move_flag){
        move_flag = 1;
    }
    else{
        move_flag = 0;
    }


    if (move_flag) {
        for (int j = 1; j < row; ++j) {
            if (p[j][d - 1] != 0 && p[j][d - 1] < n) {
                move_flag = 0;
                break;
            }
        }
    }


    if(move_flag){
        for(int i=0; i<row; ++i){
            for(int j=0; j<3; ++j){
                if(p[i][j] == n && i != 0){
                    if(p[i-1][j] == 0){
                        p[i][j] = 0;
                    }
                    else{
                        move_flag = 0;
                    }
                }
                else if(p[i][j] == n && move_flag){
                    p[i][j] = 0;
                }
            }
        }
    }

    if(move_flag){
        p[0][d-1] = n;
    }

    //bottom
    int tmp_count = 0;
    for(int j=0; j<3; ++j){
        for(int i=row-1; i>=0; --i){
            if(p[i][j] == 0 && i != 0){
                tmp_count++;
            }
            if(p[i][j] != 0 && tmp_count != 0){
                p[i+tmp_count][j] = p[i][j];
                p[i][j] = 0;
            }
        }
        tmp_count = 0;
    }

    display();
}

int judge(){
    int tmp_count = 0;
    for(int i=1; i<3; ++i){
        for(int j=0; j<row; ++j){
            if(p[j][i] == j+1){
                tmp_count++;
            }
            else{
                tmp_count = 0;
                break;
            }
        }
        if(tmp_count == 3){
            break;
        }
    }

    if(tmp_count == 3){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    display();
    while(1){
        scan();
        if(judge()){
            printf("Done!\n");
            break;
        }
    }
}
