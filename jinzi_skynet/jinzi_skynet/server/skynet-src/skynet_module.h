#ifndef SKYNET_MODULE_H
#define SKYNET_MODULE_H

struct skynet_context;

typedef void * (*skynet_dl_create)(void);
typedef int (*skynet_dl_init)(void * inst, struct skynet_context *, const char * parm);
typedef void (*skynet_dl_release)(void * inst);
typedef void (*skynet_dl_signal)(void * inst, int signal);

/*\ ����ģ�� \*/
struct skynet_module {
	const char * name;			/*\ c��������ƣ�һ����c������ļ��� \*/
	void * module;				/*\ ����dl�ľ����ͨ��dlopen�����õ��þ�� \*/
	skynet_dl_create create;	/*\ �󶨶�̬�⣨.so���е�xxx_create��������dlsys�����õ������ø�create���ǵ���xxx_create\*/
	skynet_dl_init init;		/*\ �󶨶�̬���е�xxx_init���������ø�init���ǵ���xxx_init \*/
	skynet_dl_release release;	/*\ �󶨶�̬���е�xxx_release���������ø�release���ǵ���xxx_release \*/
	skynet_dl_signal signal;	/*\ �󶨶�̬���е�xxx_signal���������ø�signal���ǵ���xxx_signal \*/
};

void skynet_module_insert(struct skynet_module *mod);
struct skynet_module * skynet_module_query(const char * name);
void * skynet_module_instance_create(struct skynet_module *);
int skynet_module_instance_init(struct skynet_module *, void * inst, struct skynet_context *ctx, const char * parm);
void skynet_module_instance_release(struct skynet_module *, void *inst);
void skynet_module_instance_signal(struct skynet_module *, void *inst, int signal);

void skynet_module_init(const char *path);

#endif
