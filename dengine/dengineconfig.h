#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>

// screenwidth, screenheight
#define SWIDTH 1280 ///< The screen width
#define SHEIGHT 720 ///< The screen height

#define FULLSCREEN 0 ///< Fullscreen or not

#define WINDOWNAME "Dengine" ///< The window name

#define CLEARCOLOR_RED 0.1f ///< The red component of the color of the window
#define CLEARCOLOR_GREEN 0.1f ///< The green component of the color of the window
#define CLEARCOLOR_BLUE 0.1f ///< The blue component of the color of the window

// defaultshader for Renderer as fallback if Sprite has no shader defined
#define SPRITEVERTEXSHADER "shaders/sprite.vert" ///< vertexshader name
#define SPRITEFRAGMENTSHADER "shaders/sprite.frag" ///< fragmentshader name
#define AUTOGENWHITE "#autogen-white-TGA#" ///< auto generated Texture

#define VSYNC 0 ///< VSYNC on (1) or off (0)

#define DEFAULTFILTER 3 ///< texture filter
#define DEFAULTWRAP 1 ///< texture clamping (0=repeat, 1=mirror, 2=clamp)
#endif /* CONFIG_H */