/*********************
*  CString Classes  *
*********************/

class CString
{
    public:
        CString(char* str);
        CString(char c);
        CString();
        ~CString();
        static int nbrChaines();
        char* getString();
        CString plus(char c);
        bool plusGrandQue(const CString& cstr);
        bool infOuEgal(const CString& cstr);
        void operator = (const CString& cstr);

    private:
        char* str;
        int size;
        static int nb_string;
};

/************************
*  Definition Classes  *
************************/

class Definition
{
    public:
        Definition(char* key, char* def);
        ~Definition();
        char* getClef();
        char* getDef();

    private:
        CString *key;
        CString *def;
};
