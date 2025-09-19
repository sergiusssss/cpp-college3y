#include <iostream>
#include <chrono>
#include <shared_mutex>
#include <thread>

auto measure_time(std::function<void()> f) {
    auto begin = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    return duration;
}

int main() {

    auto f1 = []() {
        std::uint64_t global_sum = 0;

        for (std::uint64_t i = 0; i < 10000000000; i++) {
            global_sum += i;
        }

        std::cout << "Sum f1: " << global_sum << std::endl;
    };

    auto f2 = []() {
        std::uint64_t global_sum = 0;

        auto f1_part = [&global_sum](std::int64_t begin, std::int64_t end) {
            std::uint64_t s = 0;
            for (std::uint64_t i = begin; i < end; i++) {
                s += i;
            }
            global_sum += s;
            std::cout << "Finish -- " << begin << std::endl;
        };

        std::thread t1(f1_part, 0, 10000000000 / 4);
        std::thread t2(f1_part, 10000000000 / 4, 10000000000 / 2);
        std::thread t3(f1_part, 10000000000 / 2, 10000000000 - 10000000000 / 4);
        std::thread t4(f1_part, 10000000000 - 10000000000 / 4, 10000000000);

        t1.join();
        t2.join();
        t3.join();
        t4.join();

        std::cout << "Sum f2: " << global_sum << std::endl;
    };

    auto d1 = measure_time(f1);
    std::cout << "D1: " << d1.count() << " microseconds." << std::endl;

    auto d2 = measure_time(f2);
    std::cout << "D2: " << d2.count() << " microseconds." << std::endl;

    // bool is_working = true;
    // auto ff1 = [&is_working]() {
    //     while (is_working) {
    //         std::cout << "F - 1111111" << std::endl;
    //     }
    // };
    //
    // auto ff2 = [&is_working]() {
    //     while (is_working) {
    //         std::cout << "F - 2222222" << std::endl;
    //     }
    // };
    //
    // std::thread t1(ff1);
    // std::thread t2(ff2);
    //
    // std::this_thread::sleep_for(std::chrono::seconds(4));
    // is_working = false;
    //
    // t1.join();
    // t2.join();

    return 0;
}
