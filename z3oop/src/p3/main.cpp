#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

class Engine {
public:
    virtual ~Engine() = default;

    virtual void start(){
        std::cout << get_info() << " is starting" << std::endl;
    }

    virtual void stop(){
        std::cout << get_info() << " is stopping" << std::endl;
    }

    std::string get_info(){
         return "Engine " + get_type() + std::to_string(get_count());
    }

private:
    virtual std::string get_type() = 0;
    virtual std::int64_t get_count() = 0;
};

class EngineHType : public Engine {
public:
    std::string get_type() override {
        return "H";
    }
};

class EngineVType: public Engine {
public:
    std::string get_type() override {
        return "V";
    }
};

class EngineWType: public Engine {
public:
    std::string get_type() override {
        return "W";
    }
};

class EngineIType: public Engine {
public:
    std::string get_type() override {
        return "I";
    }
};

class EngineV6: public EngineVType {
public:
    std::int64_t get_count() override {
        return 6;
    }
};

class EngineV8: public EngineVType {
public:
    std::int64_t get_count() override {
        return 8;
    }
};

class EngineV12: public EngineVType {
public:
    std::int64_t get_count() override {
        return 12;
    }
};

class EngineI4: public EngineIType {
public:
    std::int64_t get_count() override {
        return 4;
    }
};

class EngineI6: public EngineIType {
public:
    std::int64_t get_count() override {
        return 6;
    }
};

class EngineH4: public EngineHType {
public:
    std::int64_t get_count() override {
        return 4;
    }
};

class EngineW12: public EngineWType {
public:
    std::int64_t get_count() override {
        return 12;
    }
};

class GearBox {
public:
    virtual ~GearBox() = default;

    virtual void switch_up() = 0;
    virtual void switch_down() = 0;
    virtual std::string get_gear() = 0;
};

class ManualGearBox : public GearBox {
public:

    void switch_up() override {
        m_gear = std::min(7ll, m_gear + 1);
    }

    void switch_down() override {
        m_gear = std::max(-1ll, m_gear - 1);
    };

    std::string get_gear() override {
        if (m_gear == 0) { return "N"; }
        if (m_gear == -1) { return "R"; }
        return std::to_string(m_gear);
    }
private:
    std::int64_t m_gear = 0;
};

int main(){
    std::shared_ptr<Engine> engine = std::make_shared<EngineV12>();
    engine->start();
    engine->stop();
    std::shared_ptr<GearBox> gear_box = std::make_shared<ManualGearBox>();
    std::cout << gear_box->get_gear() << std::endl;
    gear_box->switch_down();
    std::cout << gear_box->get_gear() << std::endl;
    gear_box->switch_up();
    gear_box->switch_up();
    std::cout << gear_box->get_gear() << std::endl;
    gear_box->switch_up();
    gear_box->switch_up();
    gear_box->switch_up();
    gear_box->switch_up();
    gear_box->switch_up();
    gear_box->switch_up();
    std::cout << gear_box->get_gear() << std::endl;
    gear_box->switch_up();
    std::cout << gear_box->get_gear() << std::endl;
    gear_box->switch_down();
    gear_box->switch_down();
    gear_box->switch_down();
    gear_box->switch_down();
    gear_box->switch_down();
    gear_box->switch_down();
    gear_box->switch_down();
    std::cout << gear_box->get_gear() << std::endl;

    return 0;
}