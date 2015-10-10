//
//  project_1_entrega - Track.h
//

#ifndef __TRACK_H_INCLUDED__
#define __TRACK_H_INCLUDED__

//#include "StaticObject.h"
//#include <stdio.h>

class Track : public StaticObject{
private:
    // amount of cheerios in the inner circle
    int _qtd_cheerios;
    // inner and outter radious of the track
    GLdouble _inner_circle, _outer_circle;
    void drawTrackModel();
public:
    Track();
    Track(int qtd_cheerios,
          GLdouble inner_circle = 0.4,
          GLdouble outer_circle = 0.8);
    ~Track();
    void draw();
};

#endif /* defined(__TRACK_H_INCLUDED__) */
