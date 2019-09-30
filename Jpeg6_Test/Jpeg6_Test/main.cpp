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

	row_stride = cinfo.output_width * cinfo.output_components;//����ͼƬÿ����Ҫ���ڴ��С����λ�ֽ�
	BMP_W = cinfo.output_width;
	BMP_H = cinfo.output_height;
	printf("output_width:%d\noutput_height:%d\noutput_components:%d\nrow_stride:%d\n", cinfo.output_width, cinfo.output_height, cinfo.output_components, row_stride);

	buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr)&cinfo, JPOOL_IMAGE, row_stride, 1);

	//������Щ���ǹ̶��ĵ��ò��裬��֪��ÿ�����˼�Ļ�ǧ���Ķ�

	/*

	��ѹʱ��libjpeg����ͼƬ��һ��Ϊ��λ��ѹ�ģ�Ҳ����ͼƬˮƽ��һ���ߣ�jpeg�洢ʱ���Ͻ�������ԭ�㣬bmp�洢ʱ���½���ԭ�㣬���ת��ʱҪ������˳��ߵ�һ�²�����ȷ�ģ�����outbuf����������һ���ֽڵĵ�ַ�������һ���ֽ���ǰ˳�򿽱�jpg��ѹ�����������ݲ��ܵõ���ȷ��ͼƬ��

	��ѹ������bmp�ļ���24λͼƬ��ÿ������ռ��8λ��������ͼƬ��СΪ640*480����outbuf��СӦ��Ϊ921654 = 640*480*3+54������54λΪbmp�ļ�ͷ�������outbufӦ���ǿ��ٵ��ڴ�ռ���ʼ��ַ+921654������bmpͷ�������ҾͲ����ˣ�����Լ����ɣ�����ô�㶫��

	*/

	while (cinfo.output_scanline < cinfo.output_height)

	{
		outbuf -= row_stride;//ָ��ǰ��һ��
		jpeg_read_scanlines(&cinfo, buffer, 1); //��ѹ��һ������
			memcpy(outbuf, buffer[0], row_stride); //����ѹ�������ݿ�����outbuf
	}

	//������Щ���ǹ̶��ĵ��ò��裬��֪��ÿ�����˼�Ļ�ǧ���Ķ�

	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	return 1;
}