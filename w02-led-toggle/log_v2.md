# W2 LED toggle log

## 2025-12-09 v2 (fake /tmp/gpio)

Command:
```bash
strace -f ./gpio_led_toggle_mark 37 3 300
root@aewin:/home/aewin/test# strace -f ./gpio_led_toggle 37 3 300
execve("./gpio_led_toggle", ["./gpio_led_toggle", "37", "3", "300"], 0x7ffda8cafba0 /* 19 vars */) = 0
brk(NULL)                               = 0x59f7b3caf000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x796e16b70000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=23535, ...}) = 0
mmap(NULL, 23535, PROT_READ, MAP_PRIVATE, 3, 0) = 0x796e16b6a000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x796e16800000
mmap(0x796e16828000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x796e16828000
mmap(0x796e169b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x796e169b0000
mmap(0x796e169ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x796e169ff000
mmap(0x796e16a05000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x796e16a05000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x796e16b67000
arch_prctl(ARCH_SET_FS, 0x796e16b67740) = 0
set_tid_address(0x796e16b67a10)         = 324977
set_robust_list(0x796e16b67a20, 24)     = 0
rseq(0x796e16b68060, 0x20, 0, 0x53053053) = 0
mprotect(0x796e169ff000, 16384, PROT_READ) = 0
mprotect(0x59f7924a5000, 4096, PROT_READ) = 0
mprotect(0x796e16ba8000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x796e16b6a000, 23535)           = 0
openat(AT_FDCWD, "/tmp/gpio/export", O_WRONLY) = 3
write(3, "37", 2)                       = 2
close(3)                                = 0
openat(AT_FDCWD, "/tmp/gpio/gpio37/direction", O_WRONLY) = 3
write(3, "out", 3)                      = 3
close(3)                                = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}) = 0
getrandom("\xff\xd0\x86\x32\x0e\x89\x0d\xf8", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x59f7b3caf000
brk(0x59f7b3cd0000)                     = 0x59f7b3cd0000
write(1, "Do count:0\n", 11Do count:0
)            = 11
openat(AT_FDCWD, "/tmp/gpio/gpio37/value", O_WRONLY) = 3
write(3, "1", 1)                        = 1
close(3)                                = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=0, tv_nsec=300000000}, NULL) = 0
openat(AT_FDCWD, "/tmp/gpio/gpio37/value", O_WRONLY) = 3
write(3, "0", 1)                        = 1
close(3)                                = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=0, tv_nsec=300000000}, NULL) = 0
write(1, "Do count:1\n", 11Do count:1
)            = 11
openat(AT_FDCWD, "/tmp/gpio/gpio37/value", O_WRONLY) = 3
write(3, "1", 1)                        = 1
close(3)                                = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=0, tv_nsec=300000000}, NULL) = 0
openat(AT_FDCWD, "/tmp/gpio/gpio37/value", O_WRONLY) = 3
write(3, "0", 1)                        = 1
close(3)                                = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=0, tv_nsec=300000000}, NULL) = 0
write(1, "Do count:2\n", 11Do count:2
)            = 11
openat(AT_FDCWD, "/tmp/gpio/gpio37/value", O_WRONLY) = 3
write(3, "1", 1)                        = 1
close(3)                                = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=0, tv_nsec=300000000}, NULL) = 0
openat(AT_FDCWD, "/tmp/gpio/gpio37/value", O_WRONLY) = 3
write(3, "0", 1)                        = 1
close(3)                                = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=0, tv_nsec=300000000}, NULL) = 0
openat(AT_FDCWD, "/tmp/gpio/unexport", O_WRONLY) = 3
write(3, "37", 2)                       = 2
close(3)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++
root@aewin:/home/aewin/test# 
