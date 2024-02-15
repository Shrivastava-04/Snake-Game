#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

bool gameover;
int height=20;
int width=20;
int x,y,fruitx,fruity,score;
int tailx[100];
int taily[100];
int ntail;
enum edirection{ stop=0 , Left , Right , Up , Down};
edirection dir;


void setup(){
    gameover=false;
    dir=stop;
    x=width/2;
    y=height/2;
    fruity= rand()%height;
    fruitx=rand()%width;
    score=0;
}

void draw(){
    system("cls");
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0){
                cout<<"#";
            }
            if(i==y&&j==x){
                cout<<0;
            }
            else if(i==fruity&&j==fruitx){
                cout<<"F";
            }
            else{
                    bool printt=false;
                for(int k=0;k<ntail;k++){
                    if(tailx[k]==j&&taily[k]==i){
                        cout<<"o";
                        printt=true;
                    }
                }
                if(!printt){
                        cout<<" ";
                    }

            }
            if(j==width-1){
                cout<<"#";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"Score: "<<score<<endl;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                 dir = Left;
                break;
            case 'd':
                dir = Right;
                break;
            case 'w':
                dir = Up;
                break;
            case 's':
                dir = Down;
                break;
            case 'x':
                gameover=true;
                break;
        }
    }
}

void logic(){
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;taily[0]=y;
    for(int i=1;i<ntail;i++){
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(dir){
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
        case Up:
            y--;
            break;
        case Down:
            y++;
            break;
        default:
            break;
    }
    //if(x>width||x<0||y>height||y<0){
    //   gameover=true;
    //}
    if(x>=width)x=0;
    else if(x<0)x=width-1;
    if(y>=height)y=0;
    else if(y<0)y=height-1;
    for(int i=0;i<ntail;i++){
        if(tailx[i]==x&&taily[i]==y){
            gameover=true;
        }
    }
    if(x==fruitx&&y==fruity){
        score+=10;
        fruitx=rand()%width;
        fruity=rand()%height;
        ntail++;
    }

}

int main(){
    setup();

    while(!gameover){
        draw();
        input();
        logic();
        Sleep(50);
    }
    return 0;
}
