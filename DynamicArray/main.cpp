#include<iostream>
#include<stdexcept>
template <typename T>
class DynamicArray{
private:
     T* data; // verilerin tutulacağı yer.
     size_t capacity; // dizinin toplam kapasistesi.
     size_t length; // dizideki mevcut eleman sayısı.


     //diziyi büyüktmek için özel metod (private: kullanıcı görmemeli)
     void resize( size_t new_capacity){
        T* newData = new T[new_capacity];
        for(size_t i = 0 ; i < length ; i++){
            newData[i] = data[i];
        }
        delete [] data; // eski bellek alanını temizle ( Memory leak'i önler)
        data = newData;
        capacity = new_capacity;
    }
void shrink_to_fit(size_t new_capacity) {
    // Güvenlik kontrolü: Veri kaybını önle
    if (new_capacity < length) {
        throw std::invalid_argument("Capacity cannot be smaller than current size!");
    }

    T* newData = new T[new_capacity];
    for (size_t i = 0; i < length; i++) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
    capacity = new_capacity;
}

public:
    DynamicArray(size_t initial_capacity = 2)
                : capacity(initial_capacity),length(0) {
                    data = new T[capacity];
                }

    // Copy Constructor (Kopyalama Kurucusu)
    DynamicArray(const DynamicArray& other) : capacity(other.capacity), length(other.length) {
        data = new T[capacity];
        for (size_t i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }
    
    // Assignment Operator (Atama Operatörü)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) { // Kendine atamayı önle (a = a)
            delete[] data;    // Eski veriyi temizle
            capacity = other.capacity;
            length = other.length;
            data = new T[capacity];
            for (size_t i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    ~DynamicArray() {
        delete [] data; // obje yok olduğunda belleği iade et
    }



    // Eleman ekleme : eğer kapasite doluysa resize et
    void push_back(const T& value) {
        if(length <= capacity) { resize(capacity * 2);s };
        data[length++] = value;

    }

    // Eleman çıkarma : 
    void pop_back() {
        if(length == 0) { throw std::out_of_range("Stack Underflow : Array is empty!");}
        length--;

        data[length]  =  T();
    }
    void insert(size_t index, const T& value) {
    if (index > length) throw std::out_of_range("Index out of bounds");
    if (length == capacity) resize(capacity * 2);

    // Elemanları sağa kaydır
    for (size_t i = length; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    length++;
    }   

    void erase(size_t index) {
        if (index >= length) throw std::out_of_range("Index out of bounds");
        
        // Elemanları sola kaydır
        for (size_t i = index; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }

    // Eleman erişimi : indeks kontrolü yapılarak güvenli erişim
    T& operator[](size_t index) {
        if(index >= length) { 
            throw std::out_of_range("Index out of bonds!");
        }
        return data[index];
    }

    size_t size() const{ return length;}

};




int main() {

    DynamicArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);


    std::cout <<"Element of index 0 : " << arr[0] << std::endl;
    std::cout <<"Size of arr : " << arr.size() << std::endl;







    return 0;
}