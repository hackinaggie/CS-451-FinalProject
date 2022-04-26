
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    // brute force crack pasword for a_edit1.out using exec, fork, and a pipe
    int pid = fork();

    //setup pipe for IPC communcation
    int fd[2];
    pipe(fd);

    cout << "pid is " << getpid() << endl;
    if (pid == 0)
    {
        //child code:

        //redirect pipe output to stdin input
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        //exec jurrasic program to find password
        char *argv[] = {NULL};
        char *envp[] = {NULL};
        if (execve("./a.out", argv, envp) == -1)
            perror("Could not execve");

    }
    else
    {
        //parent code:
        char buf [32] = {"NEDRY\nMr. Goodbytes\n"};
        cout << "setting up pipes" << endl;
        //redirect stdout output to pipe input
        close(fd[0]);
        write(fd[1], buf, sizeof(buf));
        close(fd[1]);
            
        cout << "beginning to wait for " << pid << endl;
        waitpid(pid, NULL, 0);
        cout << "done waiting on " << pid << endl;
    }

    cout << "exit " << getpid() << endl;
}