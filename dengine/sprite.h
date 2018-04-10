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

	private:
		GLuint loadTGA(const std::string& imagepath);

		GLuint _texture;
		GLuint _vertexbuffer;
		GLuint _uvbuffer;

		int _frame; ///< @brief the active frame of the SpriteSheet

		std::string _texturename; ///< @brief texturename (path to the file)

		std::string _fragmentshader; ///< @brief fragmentshader (path to the file)
		std::string _vertexshader; ///< @brief vertexshader (path to the file)

		int _filter; ///< @brief texture filtering
		int _wrap; ///< @brief texture wrapping
};

#endif /* SPRITE_H */
