#include "Includes.hpp"

static GLuint loadPNGTexture(const char* filename) {
	FILE *fp = fopen(filename, "rb");
	if (!fp) {
		std::cerr << RED "Error: cannot read file." << filename << RESET << std::endl;
		return 0;
	}

	// Vérification signature PNG
	png_byte header[8];
	fread(header, 1, 8, fp);
	if (png_sig_cmp(header, 0, 8)) {
		std::cerr << RED "Error: " << filename << " is not a PNG image." RESET << std::endl;
		fclose(fp);
		return 0;
	}

	// Structures libpng
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) { fclose(fp); return 0; }

	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) { png_destroy_read_struct(&png_ptr, NULL, NULL); fclose(fp); return 0; }

	if (setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		return 0;
	}

	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, 8);

	// Lecture info PNG
	png_read_info(png_ptr, info_ptr);

	int width = png_get_image_width(png_ptr, info_ptr);
	int height = png_get_image_height(png_ptr, info_ptr);
	png_byte color = png_get_color_type(png_ptr, info_ptr);
	png_byte depth = png_get_bit_depth(png_ptr, info_ptr);

	// Conversion en RGBA8 si nécessaire
	if (depth == 16) png_set_strip_16(png_ptr);
	if (color == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png_ptr);
	if (color == PNG_COLOR_TYPE_GRAY && depth < 8) png_set_expand_gray_1_2_4_to_8(png_ptr);
	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png_ptr);

	if (color == PNG_COLOR_TYPE_RGB || color == PNG_COLOR_TYPE_GRAY || color == PNG_COLOR_TYPE_PALETTE)
		png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);

	if (color == PNG_COLOR_TYPE_GRAY || color == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png_ptr);

	png_read_update_info(png_ptr, info_ptr);

	// Allocation buffer
	std::vector<png_byte> imageData(width * height * 4);
	std::vector<png_bytep> row_pointers(height);

	for (int y = 0; y < height; y++) {
		row_pointers[y] = imageData.data() + y * width * 4;
	}

	// Lecture pixels
	png_read_image(png_ptr, row_pointers.data());
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);

	// Création texture OpenGL
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
				 GL_RGBA, GL_UNSIGNED_BYTE, imageData.data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return textureID;
}

void	loadTextures(Game *game)
{
	vector<GLuint>	&textureIDs = game->get_textureIDs();

	textureIDs.push_back(loadPNGTexture("imgs/floor.png"));
	textureIDs.push_back(loadPNGTexture("imgs/celling.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint3.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint4.png"));
	textureIDs.push_back(loadPNGTexture("imgs/paint5.png"));
	textureIDs.push_back(loadPNGTexture("imgs/42_1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/42_2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor3.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor4.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor5.png"));
	textureIDs.push_back(loadPNGTexture("imgs/right_wall_corridor6.png"));
	textureIDs.push_back(loadPNGTexture("imgs/npc1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/npc2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/val.png"));
	textureIDs.push_back(loadPNGTexture("imgs/boom.png"));
	textureIDs.push_back(loadPNGTexture("imgs/0.png"));
	textureIDs.push_back(loadPNGTexture("imgs/1.png"));
	textureIDs.push_back(loadPNGTexture("imgs/2.png"));
	textureIDs.push_back(loadPNGTexture("imgs/3.png"));
	textureIDs.push_back(loadPNGTexture("imgs/4.png"));
	textureIDs.push_back(loadPNGTexture("imgs/5.png"));
	textureIDs.push_back(loadPNGTexture("imgs/6.png"));
	textureIDs.push_back(loadPNGTexture("imgs/7.png"));
	textureIDs.push_back(loadPNGTexture("imgs/8.png"));
	textureIDs.push_back(loadPNGTexture("imgs/9.png"));
	textureIDs.push_back(loadPNGTexture("imgs/lava.png"));
	textureIDs.push_back(loadPNGTexture("imgs/metal.png"));
	textureIDs.push_back(loadPNGTexture("imgs/galaxy.png"));
}
