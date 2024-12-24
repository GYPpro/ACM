#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <future>
#include <csignal>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif

const std::string QUES_NAME = "E";

// 执行程序并监控其执行时间
int run_program(const std::string &path) {
#ifdef _WIN32
    // Windows 下使用 CreateProcess 运行程序
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (CreateProcess(
            nullptr, (LPSTR)path.c_str(), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi)) {
        // 等待程序运行结束，等待最多3秒
        if (WaitForSingleObject(pi.hProcess, 3000) == WAIT_TIMEOUT) {
            // 超时，强制结束进程
            TerminateProcess(pi.hProcess, 1);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            return -1; // TLE
        } else {
            // 正常退出
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            return 0;
        }
    } else {
        std::cerr << "Failed to start " << path << std::endl;
        return -1;
    }
#else
    // Unix/Linux/macOS 使用 fork 和 exec 来执行程序
    pid_t pid = fork();
    if (pid == 0) {
        // 子进程：执行程序
        execl(path.c_str(), path.c_str(), nullptr);
        exit(1); // 如果 exec 失败，退出
    } else if (pid > 0) {
        // 父进程：等待子进程
        int status;
        auto start_time = std::chrono::high_resolution_clock::now();
        while (true) {
            auto elapsed = std::chrono::high_resolution_clock::now() - start_time;
            if (std::chrono::duration_cast<std::chrono::seconds>(elapsed).count() >= 3) {
                // 超时，杀掉子进程
                kill(pid, SIGKILL);
                waitpid(pid, &status, 0);
                return -1; // TLE
            }
            // 检查子进程是否已经结束
            if (waitpid(pid, &status, WNOHANG) != 0) {
                return 0; // 正常退出
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 防止 CPU 过载
        }
    } else {
        std::cerr << "Failed to fork for " << path << std::endl;
        return -1;
    }
#endif
}

int main(int argc, char *argv[]) {
    // if (argc < 3) {
    //     std::cerr << "Usage: " << argv[0] << " <program1> <program2>" << std::endl;
    //     return 1;
    // }

    // std::string program1 = argv[1];
    // std::string program2 = argv[2];

    std::cout << "compiling...\n";
    system(("g++ " + QUES_NAME + ".ptc.cpp -o " + QUES_NAME + ".ptc.exe -std=c++2a -DFC").c_str());
    system(("g++ " + QUES_NAME + ".std.cpp -o " + QUES_NAME + ".std.exe -std=c++2a -DFC").c_str());
    system(("g++ " + QUES_NAME + ".gnc.cpp -o " + QUES_NAME + ".gnc.exe -std=c++2a -DFC").c_str());
    std::cout << "compile complete\n";

    int t = 1;
    while (++t) {
        std::future<int> result1 = std::async(std::launch::async, run_program, ".\\" + QUES_NAME + ".gnc.exe");
        std::future<int> result2 = std::async(std::launch::async, run_program, ".\\" + QUES_NAME + ".ptc.exe");
        std::future<int> result3 = std::async(std::launch::async, run_program, ".\\" + QUES_NAME + ".std.exe");

        // 检查超时和结果
        if (result1.get() == -1 || result2.get() == -1 || result3.get() == -1) {
            std::cout << "TLE at test:" << t-1 << "\n";
            system("pause");
            return 0;
        }

        system("cls"); // Windows 清屏
        // system("clear"); // Linux 清屏

        if (system(("fc " + QUES_NAME + ".A.std " + QUES_NAME + ".A.ptc").c_str())) {
            std::cout << "WA at test:" << t-1 << "\n";
            system("pause");
            return 0;
        } else {
            std::cout << "AC at test:" << t - 1 << "\n";
        }
    }
}
