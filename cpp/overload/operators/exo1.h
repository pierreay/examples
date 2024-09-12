class CString
{
    public:
        CString(char* str);
        CString(char c);
        CString();
        ~CString();
        static int nbrChaines();
        char* getString();
        CString plus(const char c);
        bool plusGrandQue(const CString& cstr);
        bool infOuEgal(const CString& cstr);
        void operator=(const CString& cstr);
        CString operator+(const char c);
        bool operator>(const CString& cstr);
        bool operator<=(const CString& cstr);

    private:
        char* str;
        int size;
        static int nb_string;
};
