#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

#include "./jpeg6/include/jpeglib.h"
#include "./jpeg6/include/jerror.h"
#include "./jpeg6/include/jconfig.h"
#include "./jpeg6/include/jmorecfg.h"
int test()
{
	int quality = 90;
	struct jpeg_compress_struct cinfoDecodec;
	struct jpeg_error_mgr jerr;
	unsigned char* inImageBuffer;
	unsigned char* outbuffer;
	outbuffer = NULL;
	JSAMPROW row_pointer[1];
	int row_stride;
	unsigned long outSize = 0;

	inImageBuffer = inRgbImg.bufferPtr;
	JSAMPROW row_pointer[1];
	int row_stride;
	unsigned long outSize = 0;
	inImageBuffer = inRgbImg.bufferPtr;
	cinfoDecodec.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfoDecodec);
	jpeg_mem_dest(&cinfoDecodec, &outbuffer, &outSize);
	cinfoDecodec.image_width = inRgbImg.width;
	cinfoDecodec.image_height = inRgbImg.height;

	cinfoDecodec.input_components = 3;
	cinfoDecodec.in_color_space = JCS_RGB;
	jpeg_set_defaults(&cinfoDecodec);
	jpeg_set_quality(&cinfoDecodec, quality, true);
	jpeg_start_compress(&cinfoDecodec, TRUE);
	row_stride = inRgbImg.width * 3;
	while (cinfoDecodec.next_scanline < cinfoDecodec.image_height)
	{
		row_pointer[0] = &inImageBuffer[cinfoDecodec.next_scanline * row_stride];
		(void)jpeg_write_scanlines(&cinfoDecodec, row_pointer, 1);
	}
	jpeg_finish_compress(&cinfoDecodec);

	for (int i = 0; i < outSize; i++)
	{
	   (*pOutJpgImg).bufferPtr[i] = outbuffer[i];
	}
  (*pOutJpgImg).bufferSize = outSize;
	jpeg_destroy_compress(&cinfoDecodec);

	if (NULL != outbuffer)
	{
		free(outbuffer);
		outbuffer = NULL;
	}
}