struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr
{
    // реализуйте следующие методы:
    //
    explicit ScopedPtr(Expression *ptr = 0) {
        ptr_ = ptr;
    }
    ~ScopedPtr() {
        // if(ptr_ != -1)
            delete ptr_;
    }
    Expression* get() const {
        return ptr_;
    }
    Expression* release() {
        Expression *newptr_;
        newptr_ = ptr_;
        ptr_ = 0;
        return newptr_;
    }
    void reset(Expression *ptr = 0) {
        delete ptr_;
        ptr_ = ptr;
    }
    Expression& operator*() const {
        return *ptr_;
    }

    Expression* operator->() const {
        return ptr_;
    }

private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};