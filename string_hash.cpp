class string_hash   {
    /*
        Note: This Class for string assumes that string starts from index 0
    */
    string str;
    LL mod1;
    LL mod2;
    LL base;
    int n;
    LL *pref1;
    LL *pref2;
    public:
    string_hash(string s , LL b = 31 , LL m1 = 1000000007 , LL m2 = 1000000009){
        mod1 = m1;
        mod2 = m2;
        str = s;
        base = b;
        n = str.length();
        pre_compute();
    }
    void pre_compute()  {
        pref1 = (LL *)malloc(str.length() * sizeof(LL));
        pref2 = (LL *)malloc(str.length() * sizeof(LL));
        pref1[0] = int(str[0]);
        pref2[0] = pref1[0];
        for(int i = 1; i < n; i++)  {
            pref1[i] = pref1[i - 1] * base + int(str[i]);
            pref1[i] %= mod1;
            pref2[i] = pref2[i - 1] * base + int(str[i]);
            pref2[i] %= mod2;
        }
    }
    LL get_hash1(int i , int j)    {
        assert(i <= j);
        assert(i >= 0);
        assert(j < str.length());
        LL hash_;
        if(i == 0)  {
            return pref1[j];
        }
        else{
            hash_ = pref1[j] - (pref1[i - 1] * pow(base , j - i + 1  , mod1)) % mod1;
            hash_ %= mod1;
            if(hash_ < 0)   {
                hash_ += mod1;
            }
            return hash_;
        }
    }

    LL get_hash2(int i , int j)   {
        assert(i <= j);
        assert(i >= 0);
        assert(j < str.length());
        LL hash_;
        if(i == 0)  {
            return pref2[j];
        }
        else{
            hash_ = pref2[j] - (pref2[i - 1] * pow(base , j - i + 1 , mod2)) % mod2;
            hash_ %= mod2;
            if(hash_ < 0)   {
                hash_ += mod2;
            }
            return hash_;
        }
    }
};
