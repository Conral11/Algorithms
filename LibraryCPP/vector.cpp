#include "vector.h"
#include <stdexcept>

struct Vector
{
    Data *data;
    size_t size;
    size_t capacity;
    
};

Vector *vector_create()
{
    Vector *vector = new Vector;
    vector->data = nullptr;
    vector->size = 0;
    vector->capacity = 0;
    return vector;
}

void vector_delete(Vector *vector)
{
    delete[] vector->data;
    delete vector; 
}

Data vector_get(const Vector *vector, size_t index)
{
    if (index >= vector->size) {
        throw std::out_of_range("Index out of range");
    }
    return (Data)0;
}

void vector_set(Vector *vector, size_t index, Data value)
{
    if (index >= vector->capacity) {
        vector_resize(vector, index + 1);
    }
    if (index >= vector->size) {
        vector->size = index + 1;
    }
    vector->data[index] = value;
}

size_t vector_size(const Vector *vector)
{
    return vector->size;
}

void vector_resize(Vector *vector, size_t size)
{
    if (size > vector->capacity) {
        size_t new_capacity = (size > vector->capacity * 2) ? size : vector->capacity * 2;
        Data *new_data = new Data[new_capacity];
        for (size_t i = 0; i < vector->size; ++i) {
            new_data[i] = vector->data[i];
        }
        delete[] vector->data;
        vector->data = new_data;
        vector->capacity = new_capacity;
    }
}
