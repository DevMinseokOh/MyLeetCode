
class Foo {
    int flag = 1;
    sem_t semFirst, semSecond;

public:
    Foo() {
        sem_init(&semFirst, 0, 0);
        sem_init(&semSecond, 0, 0);
    }

    ~Foo() {
        sem_destroy(&semFirst);
        sem_destroy(&semSecond);
    }

    void first(function<void()> printFirst) {
        printFirst();
        sem_post(&semFirst);
    }

    void second(function<void()> printSecond) {
        sem_wait(&semFirst);
        printSecond();
        sem_post(&semSecond);
    }

    void third(function<void()> printThird) {
        sem_wait(&semSecond);
        printThird();
    }
};