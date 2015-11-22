//
//  project_1_entrega - Cheerio.h
//
#ifndef __CHEERIO_H_INCLUDED__
#define __CHEERIO_H_INCLUDED__

#include "StaticObject.h"

class Cheerio : public StaticObject{
private:
    GLfloat amb[4]      = {1.0f, 0.53f, 0.49f, 1.0f};
    GLfloat diffuse[4]  = {1.0f, 0.55f, 0.07568f, 1.0f};
    GLfloat specular[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat shine       = 76.8f;
    
public:
    Cheerio();
    ~Cheerio();
    void draw();
    
    bool isInnerCheerio();
    bool isOuterCheerio();
};

#endif /* defined(__CHEERIO_H_INCLUDED__) */
