//
//  Menu.h
//  project_4_entrega
//

#ifndef Menu_h
#define Menu_h

#include <stdio.h>

class Menu{
private:
    void drawPauseScreen();
    void drawGameOverScreen();
    void drawPlaneForTexture();
    
public:
    Menu();
    ~Menu();
    void draw();
};
#endif /* Menu_h */
