# W1 GPIO sysfs log

## 2025-12-02 v1 (fake /tmp/gpio)

Command:
```bash
strace ./gpio_sysfs 37

root@scb6915vs3:/tmp/gpio# gcc  gpio_sysfs.c -o gpio_sysfs
root@scb6915vs3:/tmp/gpio# ./gpio_sysfs 37
Read back value:1
root@scb6915vs3:/tmp/gpio# strace ./gpio_sysfs 37
execve("./gpio_sysfs", ["./gpio_sysfs", "37"], 0x7ffe14a7cf58 /* 20 vars */) = 0
brk(NULL)                               = 0x56550e08e000
arch_prctl(0x3001 /* ARCH_??? */, 0x7ffc5a14c9e0) = -1 EINVAL (Invalid argument)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f1757e1a000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=50108, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 50108, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f1757e0d000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\237\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
pread64(3, "\4\0\0\0 \0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0"..., 48, 848) = 48
pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0O{\f\225\\=\201\327\312\301P\32$\230\266\235"..., 68, 896) = 68
newfstatat(3, "", {st_mode=S_IFREG|0755, st_size=2220400, ...}, AT_EMPTY_PATH) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2264656, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f1757be4000
mprotect(0x7f1757c0c000, 2023424, PROT_NONE) = 0
mmap(0x7f1757c0c000, 1658880, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7f1757c0c000
mmap(0x7f1757da1000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x7f1757da1000
mmap(0x7f1757dfa000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x215000) = 0x7f1757dfa000
mmap(0x7f1757e00000, 52816, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f1757e00000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f1757be1000
arch_prctl(ARCH_SET_FS, 0x7f1757be1740) = 0
set_tid_address(0x7f1757be1a10)         = 4270
set_robust_list(0x7f1757be1a20, 24)     = 0
rseq(0x7f1757be20e0, 0x20, 0, 0x53053053) = 0
mprotect(0x7f1757dfa000, 16384, PROT_READ) = 0
mprotect(0x565503faa000, 4096, PROT_READ) = 0
mprotect(0x7f1757e54000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7f1757e0d000, 50108)           = 0
openat(AT_FDCWD, "/tmp/gpio/export", O_WRONLY) = 3
write(3, "37", 2)                       = 2
close(3)                                = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffc5a14c9d0) = 0
openat(AT_FDCWD, "/tmp/gpio/gpio37/direction", O_WRONLY) = 3
write(3, "out", 3)                      = 3
close(3)                                = 0
openat(AT_FDCWD, "/tmp/gpio/gpio37/value", O_WRONLY) = 3
write(3, "1", 1)                        = 1
close(3)                                = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffc5a14c9d0) = 0
openat(AT_FDCWD, "/tmp/gpio/gpio37/value", O_RDONLY) = 3
read(3, "1", 15)                        = 1
close(3)                                = 0
newfstatat(1, "", {st_mode=S_IFCHR|0600, st_rdev=makedev(0x4, 0x40), ...}, AT_EMPTY_PATH) = 0
ioctl(1, TCGETS, {B115200 opost isig icanon echo ...}) = 0
getrandom("\xe6\xf3\xe8\xea\x39\xfd\xe1\x8e", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x56550e08e000
brk(0x56550e0af000)                     = 0x56550e0af000
write(1, "Read back value:1\n", 18Read back value:1
)     = 18
exit_group(0)                           = ?
+++ exited with 0 +++
root@scb6915vs3:/tmp/gpio# strace -e open,read,write ./gpio_sysfs 37
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\237\2\0\0\0\0\0"..., 832) = 832
write(3, "37", 2)                       = 2
write(3, "out", 3)                      = 3
write(3, "1", 1)                        = 1
read(3, "1", 15)                        = 1
write(1, "Read back value:1\n", 18Read back value:1
)     = 18
+++ exited with 0 +++
root@scb6915vs3:/tmp/gpio#
