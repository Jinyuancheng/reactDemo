#wildcard把 指定目录 ./ 和 ../lib 下的所有后缀是cpp的文件全部展开。
SRCS = $(wildcard *.cpp) $(wildcard *.c) $

#OBJS将$(SRCS)下的.cpp文件转化为.o文件
OBJS = $(SRCS:%.cpp = %.o) $(SRCS:%.c = %.o) $(wildcard ./lib/*.a)

#代表所使用的编译器
CC = gcc 

#头文件查找路径
INCLUDES = -I ./libpcap-0.9.4/ -I ./

#链接库查找地址
#LIBS = -L./jpeg6/lib/ -l jpeg

#附加参数
CCFLAGS = -g -pthread -Wall -O0 -shared   

#输出程序名称
OUTPUT = ReadPcap   

all:$(OUTPUT)

$(OUTPUT) : $(OBJS)
	#$(CC) $^ -o $@ $(INCLUDES) $(LIBS)
	$(CC) $^ -o $@ $(INCLUDES)

%.o : %.c
	$(CC) -c $< $(CCFLAGS)

#清除中间文件及生成文件
clean:
	rm -rf *.out *.o    

.PHONY:clean
