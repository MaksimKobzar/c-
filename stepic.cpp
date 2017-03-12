#include <cstddef> // size_t

struct Sub;
struct String {
	String(const char *str = "");
	String(size_t n, char c);
	// String(const String &other);

	virtual ~String();

    String(const String &other);
    String &operator=(const String &other);

    Sub operator[](size_t index) {
    	return Sub(*this, index);
    }

	void append(const String &other);

	size_t size;
	char *str;
};

// String::String(const String &other)
// 	: size(other.size) {
// 		str = new char[size + 1];
// 		for (size_t i = 0; i != size; ++i) {
//         str[i] = other.str[i];
//     }
// 	}

struct Sub : String{

  Sub(const String &other, size_t index)
  	: String(other), save_low(index) { }
  ~Sub() {}

  Sub operator[](size_t index) {
  	Sub some();
		some.size = index - save_low;
		some.str = new char [some.size + 1];

		for (size_t i = 0; i < some.size; ++i)
			*(some.str + i + save_low) = *(String.str + i);
		*(some.str + size) = '\0';

		return some;
  }

  size_t save_low;
};