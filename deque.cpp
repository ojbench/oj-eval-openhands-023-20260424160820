#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;string&gt;
#include &lt;sstream&gt;

class Deque {
private:
    std::vector&lt;int&gt; data;
    int front_index;
    int back_index;
    int capacity;
    int size;

public:
    Deque() {
        capacity = 1000000;  // Large enough capacity
        data.resize(capacity);
        front_index = capacity / 2;
        back_index = capacity / 2;
        size = 0;
    }

    void push_front(int value) {
        if (front_index == 0) {
            // Resize if needed
            std::vector&lt;int&gt; new_data(capacity * 2);
            int new_front = capacity;
            int new_back = capacity;
            for (int i = 0; i &lt; size; i++) {
                new_data[new_front - 1 - i] = data[front_index + i];
            }
            data = new_data;
            front_index = new_front - size - 1;
            back_index = new_back;
            capacity *= 2;
        }
        data[--front_index] = value;
        size++;
    }

    void push_back(int value) {
        if (back_index == capacity) {
            // Resize if needed
            std::vector&lt;int&gt; new_data(capacity * 2);
            int new_front = capacity;
            int new_back = capacity;
            for (int i = 0; i &lt; size; i++) {
                new_data[new_front + i] = data[front_index + i];
            }
            data = new_data;
            front_index = new_front;
            back_index = new_back + size;
            capacity *= 2;
        }
        data[back_index++] = value;
        size++;
    }

    int pop_front() {
        if (size == 0) {
            throw std::runtime_error("Deque is empty");
        }
        int value = data[front_index++];
        size--;
        return value;
    }

    int pop_back() {
        if (size == 0) {
            throw std::runtime_error("Deque is empty");
        }
        int value = data[--back_index];
        size--;
        return value;
    }

    int front() {
        if (size == 0) {
            throw std::runtime_error("Deque is empty");
        }
        return data[front_index];
    }

    int back() {
        if (size == 0) {
            throw std::runtime_error("Deque is empty");
        }
        return data[back_index - 1];
    }

    int get_size() {
        return size;
    }

    bool is_empty() {
        return size == 0;
    }
};

int main() {
    Deque dq;
    std::string line;
    
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        
        if (command == "push_front") {
            int value;
            iss >> value;
            dq.push_front(value);
        } else if (command == "push_back") {
            int value;
            iss >> value;
            dq.push_back(value);
        } else if (command == "pop_front") {
            try {
                std::cout << dq.pop_front() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << "error" << std::endl;
            }
        } else if (command == "pop_back") {
            try {
                std::cout << dq.pop_back() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << "error" << std::endl;
            }
        } else if (command == "front") {
            try {
                std::cout << dq.front() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << "error" << std::endl;
            }
        } else if (command == "back") {
            try {
                std::cout << dq.back() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << "error" << std::endl;
            }
        } else if (command == "size") {
            std::cout << dq.get_size() << std::endl;
        } else if (command == "empty") {
            std::cout << (dq.is_empty() ? "1" : "0") << std::endl;
        }
    }
    
    return 0;
}