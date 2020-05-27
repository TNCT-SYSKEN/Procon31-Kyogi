#include "CreateParts.h"
#include <Siv3d.hpp>

#define f(x) (mas*x)
#define ff(x) (mas*(x-1))

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int pix = 3;
int mas = 35;
int bx = 50;
int by = 175;

MatchInfo mh;

//Frame(横マス数,縦マス数)
void CreateMapParts::mapFrame(const int x,const int y) {

    //縦のFrame
    rep(i,x+1) {
        Line(bx+f(i),by,bx+f(i),by+f(y))
            .draw(pix, Palette::Black);
    }

    //横のFrame
    rep(i,y+1) {
        Line(bx,by+f(i),bx+f(x),by+f(i))
            .draw(pix, Palette::Black);
    }
}

//Status(x座標,y座標,0～4)
void CreateMapParts::mapStatus(const int x,const int y,TileStatus status) {
    Rect rect(bx+f(x),by+f(y),mas,mas);
    switch(status){
        case None:
            rect.draw(Palette::Gray);
            break;
        case FriendCastle:
            rect.draw(Palette::Blue);
            break;
        case FriendZone:
            rect.draw(Palette::Skyblue);
            break;
        case EnemyCastle:
            rect.draw(Palette::Red);
            break;
        case EnemyZone:
            rect.draw(Palette::Pink);
            break;

    }
}

//Agent(x座標,y座標,0～1)
void CreateMapParts::mapAgent(uint32_t x,uint32_t y,uint32_t teamID) {
    Circle circle(bx+ff(x)+17.5,by+ff(y)+17.5,15);
    if (mh.teamID == teamID) {
        circle.draw(Palette::Green);
    }
    else {
        circle.draw(Palette::Yellow);
    }
}


//const Font font(30);
//Point(x座標,y座標,Point)
/*void CreateMapParts::mapPoint(const int x,const int y,const int p) {
    if (p >= 0) {
       font(U"p").draw(bx+ff(x),by+ff(y),Palette::Black);
    } else {
       font(U"p").draw(bx+ff(x),by+ff(y),Palette::Black);
    }
}*/