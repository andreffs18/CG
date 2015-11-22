//
//  project_4_entrega - Texture.cpp
//

#include "Texture.h"
#include <fstream>
#include "Game.h"

Texture::Texture(){}

Texture::~Texture(){}

GLuint Texture::pauseTextureUint(){
    return _pause_texture;
};
GLuint Texture::gameoverTextureUint(){
    return _gameover_texture;
};
GLuint Texture::tableTextureUint(){
    return _table_texture;
};
GLuint Texture::orangeTextureUint(){
    return _orange_texture;
};

void Texture::init(){
    glEnable(GL_TEXTURE_2D);
    
    imagedata = loadTexture("gameover.bmp");
    glGenTextures(1, &_gameover_texture);
    glBindTexture(GL_TEXTURE_2D, _gameover_texture);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, imagedata);
    free(imagedata);
    
    imagedata = loadTexture("pause.bmp");
    glGenTextures(1, &_pause_texture);
    glBindTexture(GL_TEXTURE_2D, _pause_texture);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, imagedata);
    free(imagedata);
    
    imagedata = loadTexture("table.bmp");
    glGenTextures(1, &_table_texture);
    glBindTexture(GL_TEXTURE_2D, _table_texture);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, imagedata);
    free(imagedata);
    
    imagedata = loadTexture("orange.bmp");
    glGenTextures(1, &_orange_texture);
    glBindTexture(GL_TEXTURE_2D, _orange_texture);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, imagedata);
    free(imagedata);
    
    glDisable(GL_TEXTURE_2D);
};


int * Texture::loadTexture(const char * filename) {
    std::cout << filename << std::endl;
    int * data;
    FILE * file = fopen(filename, "rb");
    if (file == NULL ) { logger.error("Error opening texture"); exit(0); };
    // allocate buffer
    
    int buffer_size = width * height * 3;
    data = (int *)malloc(buffer_size);
    // read texture data
    fread(data, buffer_size, 1, file);
    fclose(file);
    return data;
};

