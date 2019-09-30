#wildcard把 指定目录 ./ 和 ../lib 下的所有后缀是cpp的文件全部展开。
SRCS = $(wildcard *.cpp) \
		$(wildcard *.c) \

#OBJS将$(SRCS)下的.cpp文件转化为.o文件
OBJS = $(SRCS:%.cpp = %.o) \
		$(SRCS:%.c = %.o) \
		#$(wildcard /usr/lib/*.a)
		#$(wildcard ./lib/*.a)

#代表所使用的编译器
CC = g++

#输出程序名称
OUTPUT = boost_test   

#头文件查找路径
INCLUDES = -I ./ \
			-I /usr/include/boost/thread/
			#-I ./thread/ 

#链接库查找地址
#LIBS = -L /usr/local/boost/lib/ *.so

#附加参数
CCFLAGS = -g -pthread -Wall -O0 -shared   

all:$(OUTPUT)

$(OUTPUT) : $(OBJS)
	#$(CC) $^ -o $@ $(INCLUDES) $(LIBS)
	$(CC) $^ -o $@ $(INCLUDES) -lpthread 

%.o : %.c
	$(CC) -c $< $(CCFLAGS)

#清除中间文件及生成文件
clean:
	rm -rf *.out *.o    

.PHONY:clean
