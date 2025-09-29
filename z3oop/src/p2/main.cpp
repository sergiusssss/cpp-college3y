#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

class animal {
public:
    virtual void eat() = 0;
};

class human: public animal {
public:
    void eat() override {
        std::cout << "Human eat" << std::endl;
    }
    virtual void clothes() = 0;
    virtual void work() = 0;
};

class woman: public human {
public:
    void clothes() override {
        std::cout << "Woman clothes wonderful" << std::endl;
    }

};

class man: public human {
public:
    void clothes() override {
        std::cout << "Man clothes good" << std::endl;
    }

};

class mother: public woman {
public:
    void work() override {
        std::cout << "Mother works" << std::endl;
    }
};

class father: public man {
public:
    void work() override {
        std::cout << "Father works" << std::endl;
    }
};

class son: public man {
public:
    void work() override {
        std::cout << "Son works" << std::endl;
    }
};

class daughter: public woman {
public:
    void work() override {
        std::cout << "Daughter works" << std::endl;
    }

    void clothes() override {
        std::cout << "Daughter clothes" << std::endl;
    }
};

class pet: public animal {
public:
    virtual void play() = 0;
};

class dog: public pet {
public:
    void eat() override {
        std::cout << "Dog eat" << std::endl;
    }

    void play() override {
        std::cout << "Dog play with ball" << std::endl;
    }
};

class cat: public pet {
public:
    void eat() override {
        std::cout << "Cat eat" << std::endl;
    }

    void play() override {
        std::cout << "Cat playing with a mouse" << std::endl;
    }
};

class family {
private:
    std::vector<std::shared_ptr<animal>> animals;
    std::vector<std::shared_ptr<woman>> women;
    std::vector<std::shared_ptr<man>> men;
    std::vector<std::shared_ptr<human>> humans;
    std::vector<std::shared_ptr<pet>> pets;

    public:
    void add_father () {
        std::shared_ptr<father> f = std::make_shared<father>();
        humans.push_back(f);
        animals.push_back(f);
        men.push_back(f);
    }

    void add_mother () {
        std::shared_ptr<mother> f = std::make_shared<mother>();
        humans.push_back(f);
        animals.push_back(f);
        women.push_back(f);
    }

    void add_son () {
        std::shared_ptr<son> f = std::make_shared<son>();
        humans.push_back(f);
        animals.push_back(f);
        men.push_back(f);
    }

    void add_daughter () {
        std::shared_ptr<daughter> f = std::make_shared<daughter>();
        humans.push_back(f);
        animals.push_back(f);
        women.push_back(f);
    }

    void add_cat () {
        std::shared_ptr<cat> f = std::make_shared<cat>();
        animals.push_back(f);
        pets.push_back(f);
    }

    void add_dog () {
        std::shared_ptr<dog> f = std::make_shared<dog>();
        animals.push_back(f);
        pets.push_back(f);
    }

    void day () {
        for (auto human : humans) {
            human->clothes();
        }

        for (auto animal : animals) {
            animal->eat();
        }

        for (auto pet : pets) {
            pet->play();
        }

        for (auto human : humans) {
            human->work();
        }
    }

};
int main() {

    family f;

    f.add_father();
    f.add_mother();
    f.add_son();
    f.add_daughter();
    f.add_cat();
    f.add_dog();
    f.day();


    return 0;
}


