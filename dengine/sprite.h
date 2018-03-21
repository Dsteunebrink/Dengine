#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include <GL/glew.h>

class Sprite
{
	public:
		Sprite(); ///< @brief Constructor of the Sprite
		Sprite(std::string image_path);
		virtual ~Sprite();

		glm::vec3 spriteposition; ///< @brief Sprite position Point_t of the Sprite (only for Spritebatches)
		glm::vec3 spriterotation; ///< @brief Sprite rotation of the Sprite (only for Spritebatches)
		glm::vec3 spritescale; ///< @brief Sprite scale Point_t of the Sprite (only for Spritebatches)

		glm::vec2 pivot; ///< @brief Pivot Point_t of the Sprite
		glm::vec2 uvoffset; ///< @brief UVoffset Point_t of the Sprite (which part do we need to render)
		glm::vec2 uvdim; ///< @brief UVdim Point_t of the Sprite (uvwidth, uvheight. The size of the part we need to render)
		glm::vec2 size; ///< @brief size Point_t of the Sprite (width and height of the Sprite)

		glm::vec3 customParams[8]; ///< @brief custom Params that are sent to the shader

		unsigned int _width;
		unsigned int _height;

		GLuint texture() { return _texture; };
		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint uvbuffer() { return _uvbuffer; };

		unsigned int width() { return _width; };
		unsigned int height() { return _height; };

		/// @brief prepare Sprite for creation by ResourceManager
		/// @param filename path to the image.tga
		/// @param pivotx X component of Pivot Point_t of the Sprite
		/// @param pivoty Y component of Pivot Point_t of the Sprite
		/// @param uvwidth 1.0f=full texture, 0.5f=2x2 texture, 0.25f=4x4 texture etc.
		/// @param uvheight 1.0f=full texture, 0.5f=2x2 texture, 0.25f=4x4 texture etc.
		/// @return void
		void setupSprite(const std::string& filename, float pivotx, float pivoty, float uvwidth, float uvheight);

		/// @brief prepare Circle Sprite for creation by ResourceManager
		/// @param filename path to the image.tga
		/// @param radius of the circle
		/// @param segments of the circle
		/// @return void
		void setupCircleSprite(const std::string& filename, int radius, int segments);

		/// @brief prepare Circle Sprite for creation by ResourceManager
		/// @param filename path to the image.tga
		/// @param radius of the circle
		/// @param segments of the circle
		/// @param which which part of the circle
		/// @return void
		void setupSegmentSprite(const std::string& filename, int radius, int segments, int which);
	
		/// @brief prepare Sprite for creation by ResourceManager
		/// @param filename path to the image.tga
		/// @param pivotx X component of Pivot Point_t of the Sprite
		/// @param pivoty Y component of Pivot Point_t of the Sprite
		/// @param uvwidth 1.0f=full texture, 0.5f=2x2 texture, 0.25f=4x4 texture etc.
		/// @param uvheight 1.0f=full texture, 0.5f=2x2 texture, 0.25f=4x4 texture etc.
		/// @param filter filter of the Sprite Texture
		/// @param wrap wrapping of the Sprite Texture
		/// @return void
		void setupSprite(const std::string& filename, float pivotx, float pivoty, float uvwidth, float uvheight, int filter, int wrap);

		/// @brief set filter for this Sprite
		/// @return void
		void filter(int f) { _filter = f; };
		/// @brief get filter for this Sprite
		/// @return int _filter
		int filter() { return _filter; };
		/// @brief set wrap for this Sprite
		/// @return void
		void wrap(int w) { _wrap = w; };
		/// @brief get wrap for this Sprite
		/// @return int _wrap
		int wrap() { return _wrap; };

		/// @brief check if this Sprite uses culling
		/// @return int _useculling
		int useCulling() { return _useculling; };

		/// @brief use culling on this Sprite or not
		/// @return void
		void useCulling(int c) { _useculling = c; };

	private:
		GLuint loadTGA(const std::string& imagepath);

		GLuint _texture;
		GLuint _vertexbuffer;
		GLuint _uvbuffer;

		int _frame; ///< @brief the active frame of the SpriteSheet

		std::string _texturename; ///< @brief texturename (path to the file)

		std::string _fragmentshader; ///< @brief fragmentshader (path to the file)
		std::string _vertexshader; ///< @brief vertexshader (path to the file)

		bool _dynamic; ///< @brief dynamic or not

		int _filter; ///< @brief texture filtering
		int _wrap; ///< @brief texture wrapping

		int _circlemesh; ///< @brief are we a square Sprite (0), or a custom one (not 0)
		int _which; ///< @brief which segment

		int _useculling; ///< @brief use culling or not
};

#endif /* SPRITE_H */
