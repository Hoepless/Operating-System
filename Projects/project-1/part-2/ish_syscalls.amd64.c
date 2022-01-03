long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    long res;

    __asm__ __volatile__ (
	"mov $0, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(file_descriptor), "S"(buffer), "d"(buffer_size)
	:
    );

    return res;
}

int ish_chdir(const char *path)
{
    int res = -1;
    __asm__ __volatile__ (
	"mov $80, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(path)
	:
    );

    return res;
}

void ish_exit(int status)
{
    __asm__ __volatile__ (
	"mov $60, %%rax;"
	"syscall;"
	:
	: "r"(status)
	: "%rax"
    );
}

int ish_stat(const char *path, void *stat_result)
{
    int res = -1;

    __asm__ __volatile__ (
	"mov $4, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(path), "S"(stat_result)
	:
    );
    return res;
}

int ish_open(const char *path, int flags)
{
    int res = -1;

    __asm__ __volatile__ (
	"mov $2, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(path), "S"(flags)
	: "%rdx"
    );

    return res;
}

int ish_creat(const char *path, unsigned int mode)
{
    int res = -1;
    __asm__ __volatile__ (
	"mov $85, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(path), "S"(mode)
	:
    );

    return res;
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    int res = -1;
    __asm__ __volatile__ (
	"mov $33, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(old_file_descriptor), "S"(new_file_descriptor)
	:
    );
    return res;
}

int ish_close(int file_descriptor)
{
    int res = -1;
    __asm__ __volatile__ (
	"mov $3, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(file_descriptor)
	:
    );
    return res;
}

int ish_fork()
{
    int res = -1;
    __asm__ __volatile__ (
	"mov $57, %%rax;"
	"syscall;"
	: "=a"(res)
	:
	:
    );

    return res;
}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
    int res = -1;
    __asm__ __volatile__ (
	"mov $59, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(path), "S"(arguments), "d"(environment)
	:
    );

    return res;
}

int ish_waitpid(int pid, int *status, int options)
{
    int res = -1;
    __asm__ __volatile__ (
	"mov $61, %%rax;"
	"xor %%r10, %%r10;"
	"syscall;"
	: "=a"(res)
	: "D"(pid), "S"(status), "d"(options)
	: "%r10"
    );

    return res;
}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{
    long res;
    __asm__ __volatile__ (
	"mov $1, %%rax;"
	"syscall;"
	: "=a"(res)
	: "D"(file_descriptor), "S"(buffer), "d"(buffer_size)
	:
    );
    return res;
}
