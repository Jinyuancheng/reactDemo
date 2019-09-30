#include <stdio.h>
#include <stdlib.h>
#include "setjmp.h"
#include "./jpeg6/include/jpeglib.h"

int jpeg_decompress(unsigned char *inbuf, unsigned char *outbuf, unsigned int size)
{
	struct jpeg_decompress_struct cinfo;
	struct my_error_mgr jerr;
	JSAMPARRAY buffer;

	int row_stride;

	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = my_error_exit;

	if (setjmp(jerr.setjmp_buffer)) {
		jpeg_destroy_decompress(&cinfo);
		return 0;
	}

	jpeg_create_decompress(&cinfo);
	jpeg_mem_src(&cinfo, inbuf, size);
	jpeg_read_header(&cinfo, TRUE);

	jpeg_start_decompress(&cinfo);

	row_stride = cinfo.output_width * cinfo.output_components;//计算图片每行需要的内存大小，单位字节
	BMP_W = cinfo.output_width;
	BMP_H = cinfo.output_height;
	printf("output_width:%d\noutput_height:%d\noutput_components:%d\nrow_stride:%d\n", cinfo.output_width, cinfo.output_height, cinfo.output_components, row_stride);

	buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr)&cinfo, JPOOL_IMAGE, row_stride, 1);

	//以上这些都是固定的调用步骤，不知道每句的意思的话千万别改动

	/*

	解压时，libjpeg是以图片的一行为单位解压的，也就是图片水平的一条线，jpeg存储时左上角是坐标原点，bmp存储时左下角是原点，因此转化时要把上下顺序颠倒一下才是正确的，所以outbuf传入的是最后一个字节的地址，从最后一个字节往前顺序拷贝jpg解压缩出来的数据才能得到正确的图片。

	解压出来的bmp文件是24位图片，每个像素占用8位，因此如果图片大小为640*480，则outbuf大小应该为921654 = 640*480*3+54，其中54位为bmp文件头，则传入的outbuf应该是开辟的内存空间起始地址+921654，至于bmp头的制作我就不讲了，大家自己看吧，就那么点东西

	*/

	while (cinfo.output_scanline < cinfo.output_height)

	{
		outbuf -= row_stride;//指针前移一行
		jpeg_read_scanlines(&cinfo, buffer, 1); //解压出一行数据
			memcpy(outbuf, buffer[0], row_stride); //将解压出的数据拷贝至outbuf
	}

	//以上这些都是固定的调用步骤，不知道每句的意思的话千万别改动

	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	return 1;
}