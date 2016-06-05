#include <vector>
using namespace std;

class Semi_Prod;
class Ingredient;
class Product {
	vector<Semi_Prod> sp;
	vector<Ingredient> it;
};

class Semi_Prod {
	vector<Semi_Prod> sp;
	vector<Ingredient> it;
};

class Ingredient {
	vector<Product> p;
	vector<Semi_Prod> sp;
};

struct Packet
{
	struct header {
		unsigned char req;
		unsigned char op;
		unsigned short key_length;
		unsigned char ext_length;
		unsigned char data_type;
		unsigned short reserved;
		unsigned total_body;
		unsigned opaque;
		unsigned long long CAS;
	};
	char text[LEN];
};
Packet* DeocdeBuffer(char *buffer, int32_t len)
{
}