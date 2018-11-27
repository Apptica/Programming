int z[1000001];
void zalgo(string s)    {
    z[0] = s.length();
    int L = 0 , R = 0;
    for(int i = 1; i < s.length(); i++){
        if(i > R)   {
            L = i;
            R = i;
            while(R < s.length() && s[R] == s[R - L]) {
                ++R;
            }
            z[i] = R - L;
            --R;
        }
        else{
            int k = i - L;
            if(z[k] <= R - i)    {
                z[i] = z[k];
            }
            else{
                L = i;
                while(s[R] == s[R - L]){
                    ++R;
                }
                z[i] =  R - L;
                --R;
            }
        }
    }
}
