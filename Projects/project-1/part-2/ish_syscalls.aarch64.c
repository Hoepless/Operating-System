long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    register long res asm("x0");

    __asm__ __volatile__ (
	"mov x8, #63;"
	"svc #0;"
	: "=r"(res)
	: "r"(file_descriptor), "r"(buffer), "r"(buffer_size)
	: "x8"
    );


    return res;
}

int ish_chdir(const char *path)
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #49;"
	"svc #0;"
	: "=r"(res)
	: "r"(path)
	: "x8"
    );

    return res;
}

void ish_exit(int status)
{
    __asm__ __volatile__ (
	"mov x8, #93;"
	"svc #0;"
	:
	: "r"(status)
	: "x8"
    );
}

int ish_stat(const char *path, void *stat_result)
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #79;"
	"mov x3, #0;"
	"mov x2, x1;"
	"mov x1, x0;"
	"mov x0, #-100;"
	"svc #0;"
	: "=r"(res)
	: "r"(path), "r"(stat_result)
	: "x1", "x2", "x3", "x8"
    );

    return res;
}

int ish_open(const char *path, int flags)
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #56;"
	"mov x3, #0;"
	"mov x2, x1;"
	"mov x1, x0;"
	"mov x0, #-100;"
	"svc #0;"
	: "=r"(res)
	: "r"(path), "r"(flags)
	: "x1", "x2", "x8", "x3"
    );

    return res;
}

int ish_creat(const char *path, unsigned int mode)
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #56;"
	"mov x2, x1;"
	"mov x1, x0;"
	"mov x0, #-100;"
	"mov x2, #577;"
	"svc #0;"
	: "=r"(res)
	: "r"(path), "r"(mode)
	: "x1", "x2", "x8"
    );


    return res;
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #24;"
	"mov x2, #0;"
	"svc #0;"
	: "=r"(res)
	: "r"(old_file_descriptor), "r"(new_file_descriptor)
	: "x2", "x8"
    );

    return res;
}

int ish_close(int file_descriptor)
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #57;"
	"svc #0;"
	: "=r"(res)
	: "r"(file_descriptor)
	: "x8"
    );

    return res;
}

int ish_fork()
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #220;"
	"mrs x21, tpidr_el0;"
	"sub x5, x21, #0x700;"
	"add x4, x5, #0xd0;"
	"mov x3, #0;"
	"mov x2, #0;"
	"mov x1, #0;"
	"movk x0 #0x120, lsl #16;"
	"svc #0;"
	: "=r"(res)
	:
	: "x1", "x2", "x3", "x4", "x5", "x8", "x21"
    );

    return res;
}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #221;"
	"svc #0;"
	: "=r"(res)
	: "r"(path), "r"(arguments), "r"(environment)
	: "x8"
    );

    return res;
}

int ish_waitpid(int pid, int *status, int options)
{
    register int res asm("w0");

    __asm__ __volatile__ (
	"mov x8, #260;"
	"mov x3, #0;"
	"svc #0;"
	: "=r"(res)
	: "r"(pid), "r"(status), "r"(options)
	: "x3", "x8"
    );

    return res;
}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{
    register long res asm("x0");

    __asm__ __volatile__ (
	"mov x8, #64;"
	"svc #0;"
	: "=r"(res)
	: "r"(file_descriptor), "r"(buffer), "r"(buffer_size)
	: "x8"
    );

    return res;
}
