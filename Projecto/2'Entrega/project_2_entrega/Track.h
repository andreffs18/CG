//
//  project_1_entrega - Track.h
//

#ifndef __TRACK_H_INCLUDED__
#define __TRACK_H_INCLUDED__

class Track : public StaticObject{
private:
    void drawTrackModel();
public:
    Track();
    ~Track();

    void draw();
};

#endif /* defined(__TRACK_H_INCLUDED__) */
