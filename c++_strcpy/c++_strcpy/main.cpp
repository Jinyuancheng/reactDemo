#include <iostream>
#include <fstream>
#include "jpeglib.h"
using namespace std;

typedef struct
{
	int id;
	char* Name;
}Student;

int main(int argc, char *argv[])
{
	const char* input_filename = "H:\\gif图\\jinzi.jpg";
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	FILE *input_file;
	//FILE *output_file;
	JSAMPARRAY buffer;
	int row_width;

	unsigned char *output_buffer = NULL;
	unsigned char *tmp = NULL;

	cinfo.err = jpeg_std_error(&jerr);

	if ((input_file = fopen(input_filename, "rb")) == NULL) {
		fprintf(stderr, "can't open %s\n", input_filename);
		return -1;
	}

	// Initialization of JPEG compression objects
	jpeg_create_decompress(&cinfo);

	/* Specify data source for decompression */
	jpeg_stdio_src(&cinfo, input_file);

	/* 1.设置读取jpg文件头部，Read file header, set default decompression parameters */
	(void)jpeg_read_header(&cinfo, TRUE);

	/* 2.开始解码数据 Start decompressor */
	(void)jpeg_start_decompress(&cinfo);

	row_width = cinfo.output_width * cinfo.output_components;

	/* 3.跳过读取的头文件字节Make a one-row-high sample array that will go away when done with image */
	buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr)&cinfo, JPOOL_IMAGE, row_width, 1);

	output_buffer = (unsigned char *)malloc(row_width * cinfo.output_height);
	memset(output_buffer, 0, row_width * cinfo.output_height);
	tmp = output_buffer;

	/* 4.Process data由左上角从上到下行行扫描 */
	while (cinfo.output_scanline < cinfo.output_height) {
		(void)jpeg_read_scanlines(&cinfo, buffer, 1);

		memcpy(tmp, *buffer, row_width);
		tmp += row_width;
	}

	//free(output_buffer);
	//std::cout << output_buffer << std::endl;
	(void)jpeg_finish_decompress(&cinfo);

	jpeg_destroy_decompress(&cinfo);
	FILE* file;
	file = fopen("./1.jpg", "wb");
	fwrite(output_buffer, 1, strlen((const char*)output_buffer), file);
	/* Close files, if we opened them */
	fclose(input_file);
	//fclose(output_file);
	system("pause");
	return 0;
}