#ifndef __IMAGELOAD_H__
#define __IMAGELOAD_H__

#include <kos.h>

typedef enum
{
  IMG_FILE_GUESS,
  IMG_FILE_JPEG,
  IMG_FILE_PNG,
  IMG_FILE_BMP,
  IMG_FILE_PCX
} IMG_FILE;

typedef enum
{
  IMG_ALPHA_NONE,
  IMG_ALPHA_MASK,
  IMG_ALPHA_KEYED,
  IMG_ALPHA_FULL
} IMG_ALPHA;

typedef enum
{
  IMG_DITHER_NONE,
  IMG_DITHER_JITTER
} IMG_DITHER;


typedef struct
{
  IMG_FILE type;
  IMG_ALPHA alpha;
  uint32_t key;
  IMG_DITHER dither;
  uint32_t dither_width;
  uint32_t dither_height;
  uint32_t noise;
} IMG_INFO;

#define IMG_INFO_DEFAULTS {IMG_FILE_GUESS,IMG_ALPHA_NONE,0,IMG_DITHER_NONE,0,0,0}

/* At some point these functions will return success/failure */
int img_load_data(FILE *f, IMG_INFO *info, kos_img_t *img);

int img_load_file(const char *filename, IMG_INFO *info, kos_img_t *img);

/* Jitter Functions */

/* Call to initialize jitter table at runtime
 * if you run the makejitter program before you compile, you can
 * create a jitter table at compile time
 */
void jitter_init(void);
uint8 jitter(uint8_t c, uint8_t n, uint8_t shift, uint8_t noise, uint16_t x, uint16_t y);

/* Format specific loaders */

uint32 readbmp_init(FILE *infile);
uint8 *readbmp_get_image(uint32_t *pChannels, uint32_t *pRowbytes,
                         uint32_t *pWidth, uint32_t *pHeight);
void readbmp_cleanup(void);

uint32 readpng_init(FILE *infile);
uint8 *readpng_get_image(uint32_t *pChannels, uint32_t *pRowbytes,
                         uint32_t *pWidth, uint32_t *pHeight);
void readpng_cleanup(void);

uint32 readjpeg_init(FILE *infile);
uint8 *readjpeg_get_image(uint32_t *pChannels, uint32_t *pRowbytes,
                         uint32_t *pWidth, uint32_t *pHeight);
void readjpeg_cleanup(void);

uint32 readpcx_init(FILE *infile);
uint8 *readpcx_get_image(uint32_t *pChannels, uint32_t *pRowbytes,
			 uint32_t *pWidth, uint32_t *pHeight);
void readpcx_cleanup(void);
#endif
