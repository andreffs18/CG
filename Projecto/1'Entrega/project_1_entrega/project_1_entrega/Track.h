#pragma once
//
//  project_1_entrega - Track.h
//

#ifndef __project_1_entrega__Track__
#define __project_1_entrega__Track__

#include "Game.h"
#include "GameObject.h"
#include "Cheerio.h"
#include "Car.h"
#include <iostream>
#include <stdio.h>

class Track : public StaticObject{
private:
    // amount of cheerios in the inner circle
    int _qtd_cheerios;
    // inner and outter radious of the track
    GLdouble _inner_circle, _outer_circle;
public:
    Track();
    Track(int qtd_cheerios,
          GLdouble inner_circle = 0.4,
          GLdouble outer_circle = 0.8);
    ~Track();
    void draw();
};

#endif /* defined(__project_1_entrega__Track__) */
