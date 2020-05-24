#include "CreateParts.h"
#include <Siv3d.hpp>

#define f(x) (mas*x+pix*x)
#define ff(x) (mas*x+pix*(x-1))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int pix = 3;
int mas = 30;

void CreateParts::mapFrame(int y,int x) {
    //‘S‘Ì‚ÌŠO˜g
    Rect(50,150,ff(x),ff(y))
        .draw(Palette::White)
        .drawFrame(0, 4, Palette::Black);

    //c‚ÌFrame
    rep(i,x-1) {
        Line(80+f(i),151,80+f(i),149+ff(y))
            .draw(3, Palette::Gray);
    }

    //‰¡‚ÌFrame
    rep(i,y-1) {
        Line(51,180+f(i),49+ff(x),180+f(i))
            .draw(3, Palette::Gray);
    }
}