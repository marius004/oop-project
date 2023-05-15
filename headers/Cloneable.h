#ifndef OOP_CLONABLE_H
#define OOP_CLONABLE_H

#include <memory>

template<typename T>
class  Cloneable {
public:
    virtual std::shared_ptr<T> clone() const = 0;
    virtual ~Cloneable() = default;
};

#endif //OOP_CLONABLE_H