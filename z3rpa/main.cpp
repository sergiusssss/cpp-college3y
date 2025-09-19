//
// Created by Serhii Pustovit on 17.09.2025.
//
// 2 threads output > and < for the duration of a second
#include <iostream>
#include <thread>

int main() {
    std::vector<std::int64_t> thr;
    for (int i = 0; i < 200; ++i) {
        thr.push_back(i);
    }

    auto f1 = [&thr](std::int64_t begin, std::int64_t end) {
        for (auto i = begin; i < end; ++i) {
            thr[i] = thr[i]*thr[i];
        }
    };
    std::thread t1(f1, 0, 100);
    std::thread t2(f1, 100, 200);

    t1.join();
    t2.join();
    for (const auto& i : thr) {
        std::cout << i << " ";
    }

    return 0;
}