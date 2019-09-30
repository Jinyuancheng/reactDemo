#ifndef SKYNET_MODULE_H
#define SKYNET_MODULE_H

struct skynet_context;

typedef void * (*skynet_dl_create)(void);
typedef int (*skynet_dl_init)(void * inst, struct skynet_context *, const char * parm);
typedef void (*skynet_dl_release)(void * inst);
typedef void (*skynet_dl_signal)(void * inst, int signal);

/*\ 服务模块 \*/
struct skynet_module {
	const char * name;			/*\ c服务的名称，一般是c服务的文件名 \*/
	void * module;				/*\ 访问dl的句柄，通过dlopen函数得到该句柄 \*/
	skynet_dl_create create;	/*\ 绑定动态库（.so）中的xxx_create函数，（dlsys函数得到）调用该create就是调用xxx_create\*/
	skynet_dl_init init;		/*\ 绑定动态库中的xxx_init函数，调用该init就是调用xxx_init \*/
	skynet_dl_release release;	/*\ 绑定动态库中的xxx_release函数，调用该release就是调用xxx_release \*/
	skynet_dl_signal signal;	/*\ 绑定动态库中的xxx_signal函数，调用该signal就是调用xxx_signal \*/
};

void skynet_module_insert(struct skynet_module *mod);
struct skynet_module * skynet_module_query(const char * name);
void * skynet_module_instance_create(struct skynet_module *);
int skynet_module_instance_init(struct skynet_module *, void * inst, struct skynet_context *ctx, const char * parm);
void skynet_module_instance_release(struct skynet_module *, void *inst);
void skynet_module_instance_signal(struct skynet_module *, void *inst, int signal);

void skynet_module_init(const char *path);

#endif
