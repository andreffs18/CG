//
//  GameObjects.h
//  project_1_entrega
//
//  Created by André Silva on 9/27/15.
//
//

#ifndef __project_1_entrega__GameObjects__
#define __project_1_entrega__GameObjects__

#include <stdio.h>
#include <GLUT/glut.h>

class GameObjects{
private:
public:
    GameObjects();
    ~GameObjects();
    // foooling around - tests
    void customSolidCube();
    void customRedRectangle();
    void customGreenRectangle();
    void customWhiteSquare();
    void axis(GLdouble size = 2.0f);
};

#endif /* defined(__project_1_entrega__GameObjects__) */
