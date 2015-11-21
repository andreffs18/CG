//
//  project_4_entrega - Texture.h
//

#ifndef Texture_h
#define Texture_h

#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <GL\glut.h>
#elif __APPLE__
// Other kinds of Mac OS
#include <GLUT/glut.h>
#endif

class Texture{
private:
    GLsizei width = 512;
    GLsizei height = 512;
    int * imagedata;
    GLuint _gameover_texture;
    GLuint _pause_texture;
    GLuint _table_texture;
    
public:
    Texture();
    ~Texture();
    
    GLuint pauseTextureUint();
    GLuint gameoverTextureUint();
    GLuint tableTextureUint();

    void init();
    int * loadTexture(const char * filename);
};

#endif /* Texture_h */