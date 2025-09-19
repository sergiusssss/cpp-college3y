#include <iostream>
#include <vector>
#include <random>

#include <tracy/Tracy.hpp>

void f1() {
    std::cout << "f1 start" << std::endl;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2(100,200);
    std::this_thread::sleep_for(std::chrono::milliseconds(dist2(rng)));
    std::cout << "----- f1 end -----" << std::endl;
}

void f2() {
    std::cout << "f2 start" << std::endl;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2(200,300);
    std::this_thread::sleep_for(std::chrono::milliseconds(dist2(rng)));
    std::cout << "----- f2 end -----" << std::endl;
}

void f4() {
    ZoneScopedNC("f4", tracy::Color::Red);
    std::cout << "f4 start" << std::endl;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2(1000,2000);
    std::this_thread::sleep_for(std::chrono::milliseconds(dist2(rng)));
    std::cout << "----- f4 end -----" << std::endl;
}

void f3() {
    std::cout << "f3 start" << std::endl;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2(0,500);
    std::this_thread::sleep_for(std::chrono::milliseconds(dist2(rng)));
    f4();
    std::this_thread::sleep_for(std::chrono::milliseconds(dist2(rng)));
    std::cout << "----- f3 end -----" << std::endl;
}

int main() {
    ZoneScopedN("Main");

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2k(100,2000);

    for (std::int32_t i = 0; i < 1000; i++) {
        ZoneScopedN("InWhile");
        {
            ZoneScopedN("f1");
            f1();
        }
        {
            ZoneScopedN("f2");
            f2();
        }
        {
            ZoneScopedN("f3");
            f3();
        }
    }

    return 0;
}
