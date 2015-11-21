//
//  project_1_entrega - Track.h
//
#ifndef __TRACK_H_INCLUDED__
#define __TRACK_H_INCLUDED__

class Track : public StaticObject{
private:
    // track VERSION 1 is built with one giant cube, without normals
    // VERSION 2 with primitives and normalized vectors
    int VERSION = 2;
    // quality, the bigger the better,the heavier it gets
    int QUALITY = 1;
    GLfloat amb[4]      = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat diffuse[4]  = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat specular[4] = {0.64f, 0.64f, 0.64f, 1.0f};
    GLfloat shine       = 76.8f;
    
    void drawTrackModel();
    void drawV1();
    void drawV2();
public:
    Track();
    ~Track();

    void draw();
};

#endif /* defined(__TRACK_H_INCLUDED__) */
