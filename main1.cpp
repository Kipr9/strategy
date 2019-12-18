#include <iostream>
#include <string>
using namespace std; 

class Compression{
  public:    
    virtual ~Compression() {}
    virtual void compress( const string & file ) = 0;
};
  
class Zip_Compression : public Compression{
	public:
		void compress( const string & file ){
			cout<< "Zip compression" <<endl;
		}
};
  
class Arj_Compression : public Compression{
  public:
    void compress( const string & file ) {
        cout << "ARJ compression" << endl;
    }
};
  
class Rar_Compression : public Compression{
  public:
    void compress( const string & file ) {
        cout << "RAR compression" << endl;
    }
};
  
class Compressor {
  public:
    Compressor( Compression* comp): p(comp) {}
   ~Compressor() { delete p; }
    void compress( const string & file ) {
      p->compress( file);
    }
  private:
    Compression* p;
};

int main(){
Compressor* p = new Compressor (new Zip_Compression);
p->compress("file.doc");
delete p;
return 0;
}
