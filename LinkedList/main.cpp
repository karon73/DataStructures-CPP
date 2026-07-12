#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    // Nested Struct: Kullanıcı düğümleri göremez, sadece veriyi yönetir.
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;
    size_t length;

public:
    LinkedList() : head(nullptr), length(0) {}

    // Destructor: Bellek sızıntısını önlemek için kritik
    ~LinkedList() {
        while (head != nullptr) {
            pop_front();
        }
    }

    // Rule of Three: Kopyalamayı engelle (Basitlik için delete ettik)
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void pop_front() {
        if (!head) throw std::out_of_range("List is empty");
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void pop_back() {
    if (!head) throw std::out_of_range("List is empty");
    if (head->next == nullptr) { // Sadece bir düğüm varsa
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->next->next != nullptr) { // Sondan bir öncekini bul
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    length--;
}
bool contains(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}
void clear() {
    while (head != nullptr) {
        pop_front();
    }
}
void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {        next = current->next; // Bir sonrakini kaydet
        current->next = prev; // Pointer'ı tersine çevir
        prev = current;       // İlerle
        current = next;
    }
    head = prev; // Head'i yeni başlangıca taşı
}


    // Araya eleman ekleme (Index tabanlı)
    void insert(size_t index, const T& value) {
        if (index > length) throw std::out_of_range("Index out of bounds");
        if (index == 0) {
            push_front(value);
            return;
        }

        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    size_t size() const { return length; }
};