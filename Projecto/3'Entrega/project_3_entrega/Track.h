//
//  project_1_entrega - Track.h
//
#ifndef __TRACK_H_INCLUDED__
#define __TRACK_H_INCLUDED__

class Track : public StaticObject{
private:
    void drawTrackModel();
    GLfloat amb[4] ={0.4f,0.2f,0.0f,1.0f};
    GLfloat diffuse[4]={0.3f,0.3f,0.3f,1.0f};
    GLfloat specular[4]={0.64f,0.64f,0.64f,1.0f};
    GLfloat shine=76.8f;
    
public:
    Track();
    ~Track();

    void draw();
};

#endif /* defined(__TRACK_H_INCLUDED__) */
