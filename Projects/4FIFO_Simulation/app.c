#include <stdio.h>

typedef struct
{
    char name[10];
    int cpu_time;
} Process;

#define MAX 10

Process fila[MAX];
int start = 0;
int end = 0;
int count = 0;

void enqueue(Process p)
{
    if (full_queue())
    {
        printf("Fila cheia! Processo %s descartado.\n", p.name);
        return;
    }

    fila[end] = p;
    end = (end+1)%MAX;
    count++;
}

Process dequeue()
{
    Process p = {"", 0};

    if (empty_queue())
    {
        printf("Fila Vazia!\n");
        return p;
    }

    p = fila[start];
    start = (start+1)%MAX;
    count--;

    return p;
}

int empty_queue()
{
    return count == 0;
}

int full_queue()
{
    return count == MAX;
}

int main()
{
    int real_time = 0;

    // Processes
    Process p1 = {"P1", 4};
    Process p2 = {"P2", 3};
    Process p3 = {"P3", 2};

    // Insert
    enqueue(p1);
    enqueue(p2);
    enqueue(p3);

    printf("FIFO Scheduler\n\n");

    while (!empty_queue())
    {
        Process current = dequeue();

        printf("Tempo %d -> Executando %s por %d unidades\n", real_time, current.name, current.cpu_time);

        real_time += current.cpu_time;

        printf("Tempo %d -> %s finalizado\n\n", real_time, current.name);
    }

    printf("Tempo total de execução: %d\n", real_time);
    
    return 0;
}
