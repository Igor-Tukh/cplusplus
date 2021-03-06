#include "my_vector.h"
#include <cassert>
#include <utility>
#include <cstdio>

MyVector::MyVector(){
    _cp = 2;
    _sz = 0;
    _data = new int[2];
}

MyVector::MyVector(std::size_t init_capacity){
    assert (init_capacity > 0 && "MyVector::MyVector: capacity is lower or eqaul zero"); 
    _cp = init_capacity;
    _sz = 0;
    _data = new int[init_capacity];
}

MyVector::~MyVector(){
    _cp = 0;
    _sz = 0;
    delete[]_data;    
}

void MyVector::set(std::size_t index, int value){
    assert (index < _sz && "MyVector::set: Index out of range"); 
    _data[index] = value;
}

int MyVector::get(std::size_t index){    
    assert (index < _sz && "MyVector::get: Index out of range");
    return _data[index];
}

std::size_t MyVector::size(){
    return _sz;
}

std::size_t MyVector::capacity(){
    return _cp;
}  


void MyVector::reserve(std::size_t new_capacity){
    if (new_capacity <= _cp)
        return;
        
    int * buf = new int[new_capacity];
    
    for(std::size_t i = 0; i < _sz; i++)
        buf[i] = _data[i];
    
    std::swap(buf, _data);
    delete[]buf;
    
    _cp = new_capacity;
}

void MyVector::push_back(int value){
    if (_sz == _cp) 
        reserve(2 * _cp);
    
    _data[_sz++] = value;
}
  
void MyVector::resize(std::size_t new_size){
    std::size_t newcp = _cp;
    
    while (new_size > newcp)
       newcp = newcp * 2;
        
    reserve(newcp);    
    
    for(int i = (int)_sz; i < (int)new_size; i++){
        _data[i] = 0;
    }
    
    _sz = new_size;
}

void MyVector::insert(std::size_t index, int value){
    assert (index <= _sz && "MyVector::insert: Index out of range"); 
   
    int cur = value;
    for(std::size_t i = index; i < _sz; i++){
        std::swap(cur, _data[i]);
    } 
    
    push_back(cur);
}

void MyVector::erase(std::size_t index){
    assert (index < _sz && "MyVector::erase: Index out of range"); 
    
    for(std::size_t i = index + 1; i < _sz; i++){
        std::swap(_data[i - 1], _data[i]);
    }
    _sz--;    
}
