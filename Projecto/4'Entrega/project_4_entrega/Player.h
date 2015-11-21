//
//  Player.h
//  project_4_entrega
//
//  Created by André Silva on 11/19/15.
//
//

#ifndef __project_4_entrega__Player__
#define __project_4_entrega__Player__

class Player : public StaticObject{
private:
    int _lifes;
    
    void setupColor();
public:
    Player();
    ~Player();
    
    void draw();
    void drawLifeObject();

    int getLifes();
    void setLifes(int);
    void die();
    bool isDead();
};

#endif /* defined(__project_4_entrega__Player__) */
