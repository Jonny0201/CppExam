#include <iostream>
using namespace std;
class creature {
    friend class nature;
protected:
    int lifetime;
    int height;
    int weight;
public:
    creature(int lifetime, int height, int weight) noexcept : lifetime {lifetime}, height {height}, weight {weight} {}
    creature(const creature &) noexcept = default;
    creature(creature &&rhs) noexcept : lifetime {rhs.lifetime}, height {rhs.height}, weight {rhs.weight} {}
    virtual ~creature() noexcept = default;
public:
    creature &operator=(const creature &) = delete;
    creature &operator=(creature &&) noexcept = delete;
public:
    virtual void breathe() const & noexcept = 0;
};
class primate : public creature {
    friend class nature;
protected:
    struct primate_eyes {};
    struct primate_nose {};
    struct primate_mouse {};
    struct primate_ears {};
    struct primate_hand {};
    struct primate_foot {};
    struct primate_tail {};
    struct primate_hair {};
protected:
    primate_eyes eyes;
    primate_nose nose;
    primate_mouse mouse;
    primate_ears ears;
    primate_hand hand;
    primate_foot foot;
public:
    using creature::creature;
public:
    virtual void crawl() const & noexcept = 0;
};
class monkey : public primate {
    friend class nature;
protected:
    primate_tail tail;
    primate_hair hair;
public:
    using primate::primate;
public:
    void breathe() const & noexcept override {
        cout << "breathe" << endl;
    }
    void crawl() const & noexcept override {
        cout << "crawl" << endl;
    }
    void jump() const & noexcept {
        cout << "jump" << endl;
    }
};
class acient_ape : public monkey {
    friend class nature;
private:
    void degeneration() noexcept {
        cout << "degeneration" << endl;
    }
public:
    acient_ape(int lifetime, int height, int weight) : monkey(lifetime, height, weight) {
        this->degeneration();
    }
    acient_ape(const acient_ape &) noexcept = default;
    acient_ape(acient_ape &&) noexcept = default;
    ~acient_ape() override = default;
};
class ape : virtual public acient_ape {
    friend class nature;
public:
    using acient_ape::acient_ape;
};
class primitive : virtual public acient_ape {
    friend class nature;
public:
    using acient_ape::acient_ape;
public:
    void walk() const & noexcept {
        cout << "walk" << endl;
    }
    void run() const & noexcept {
        cout << "run" << endl;
    }
};
class human final : public ape, public primitive {
    friend class nature;
    friend class society;
private:
    string name;
public:
    human(int lifetime, int height, int weight, const string &name) : acient_ape(lifetime, height, weight), ape(lifetime, height, weight), primitive(lifetime, height, weight), name {name} {

    }
    human(const human &) = delete;
    human(human &&) = delete;
    ~human() noexcept = default;
public:
    void think() const & noexcept {
        cout << "human think" << endl;
    }
    void speak(const string &statement) const & noexcept {
        cout << statement << endl;
    }
    template <typename Thing>
    Thing create() const & {
        return Thing();
    }
};
