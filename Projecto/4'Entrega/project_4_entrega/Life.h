//
//  Life.h
//  project_4_entrega
//
//  Created by André Silva on 11/19/15.
//
//

#ifndef __project_4_entrega__Life__
#define __project_4_entrega__Life__

class Life : public StaticObject{
private:
    void setupColor();
public:
    Life();
    ~Life();
    void draw();
    void drawLifeObject();
};

#endif /* defined(__project_4_entrega__Life__) */
