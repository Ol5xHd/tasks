struct Node {
    Node( int _value, Node* _left, Node* _right ) : value( _value ), left( _left ), right( _right ) {}

    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
