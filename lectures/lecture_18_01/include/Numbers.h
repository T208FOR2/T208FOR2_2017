

class Numbers {
public:
    Numbers();
    ~Numbers();
    Numbers( const Numbers& cloneme );

    void operator = ( const Numbers& sameasme );

    void append(int i);

    int *p;

    int n;
    int max_elements;

private:

    void double_size_of_array();
};
