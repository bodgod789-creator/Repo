
#include <iostream>
using namespace std;

class Huffman {

    struct Node {
        char ch;
        int frequency;
        Node *left, *right;

        Node(char ch, int frequency) {
            this->ch = ch;
            this->frequency = frequency;
            left = right = nullptr;
        }
    };

    // Manual Min Heap
    class MinHeap {

        Node** heap;
        int size;
        int capacity;

    public:

        MinHeap(int capacity) {
            this->capacity = capacity;
            heap = new Node*[capacity];
            size = 0;
        }

        void insert(Node* node) {

            int i = size;
            heap[size] = node;
            size++;

            // Heapify upward
            while (i > 0) {

                int parent = (i - 1) / 2;

                if (heap[parent]->frequency <=
                    heap[i]->frequency)
                    break;

                swap(heap[parent], heap[i]);

                i = parent;
            }
        }

        Node* extractMin() {

            Node* minimum = heap[0];

            size--;

            if (size == 0)
                return minimum;

            heap[0] = heap[size];

            int i = 0;

            // Heapify downward
            while (true) {

                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int smallest = i;

                if (left < size &&
                    heap[left]->frequency <
                    heap[smallest]->frequency) {

                    smallest = left;
                }

                if (right < size &&
                    heap[right]->frequency <
                    heap[smallest]->frequency) {

                    smallest = right;
                }

                if (smallest == i)
                    break;

                swap(heap[i], heap[smallest]);

                i = smallest;
            }

            return minimum;
        }

        int getSize() {
            return size;
        }

        ~MinHeap() {
            delete[] heap;
        }
    };

    // Build Huffman Tree
    static Node* buildTree(char ch[], int freq[], int n) {

        MinHeap heap(2 * n + 1);

        for (int i = 0; i < n; i++) {
            heap.insert(new Node(ch[i], freq[i]));
        }

        while (heap.getSize() > 1) {

            Node* left = heap.extractMin();
            Node* right = heap.extractMin();

            Node* parent = new Node(
                '$',
                left->frequency + right->frequency
            );

            parent->left = left;
            parent->right = right;

            heap.insert(parent);
        }

        return heap.extractMin();
    }

    // Display Huffman Codes
    static void printCodes(Node* root, string code) {

        if (root == nullptr)
            return;

        if (root->left == nullptr &&
            root->right == nullptr) {

            if (code.length() == 0)
                code = "0";

            cout << root->ch << " : " << code << endl;
            return;
        }

        printCodes(root->left, code + "0");
        printCodes(root->right, code + "1");
    }

public:

    static void run() {

        int n;

        cout << "Enter number of characters: ";
        cin >> n;

        if (n <= 0 || n > 100) {
            cout << "Invalid input!" << endl;
            return;
        }

        char ch[n];
        int freq[n];

        cout << "Enter character and frequency:" << endl;

        for (int i = 0; i < n; i++) {

            cin >> ch[i] >> freq[i];

            if (freq[i] <= 0) {
                cout << "Frequency must be positive!" << endl;
                return;
            }
        }

        Node* root = buildTree(ch, freq, n);

        cout << "\nHuffman Codes:" << endl;

        printCodes(root, "");

    }
};

int main() {

    Huffman::run();

    return 0;
}
