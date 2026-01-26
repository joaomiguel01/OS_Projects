#include <stdio.h>
#include <unistd.h>

void boot(const char *msg)
{
    printf("%s\n", msg);
    usleep(600000);
}

void fake_daemon(const char *msg)
{
    printf("[daemon] %s started\n", msg);
    usleep(300000);
}

void start_daemons()
{
    fake_daemon("networkd");
    fake_daemon("logd");
    fake_daemon("deviced");
    fake_daemon("audiod");
}

void init_process()
{
    printf("\n[init] PID 1 started\n");
    usleep(500000);
    start_daemons();
}

int main()
{
    boot("Booting FakeOS Kernel 0.1");
    boot("Initializing kernel...");
    boot("Setting up memory management");
    boot("Detecting CPU...");
    boot("Mounting root filesystem...");
    boot("Starting init...");
    boot("System ready.");

    init_process();

    // kernel loop
    while (1) {
        
    }
    return 0;
}