// now i am doing the rabin-karp
long long hash_part=0;
long long hash_text=0, power=1;
int n=hash_part.size();
int m=hash_text.size();
for(int i=0;i<m;i++){
    hash_part=(hash_part*p+(pattern[i]-'a'+1))%mod;
    hash_text=(hash_text*p+(text[i]-'a'+1))%mod;
    if(i<m-1) power=power(power*p)%mod;
}
// sliding window
for(int i = 0; i <= n - m; i++){
    
    if(hash_txt == hash_pat){
        if(text.substr(i, m) == pattern)
            return true;
    }

    if(i < n - m){
        hash_txt = (hash_txt - (text[i] - 'a' + 1) * power % mod + mod) % mod;
        hash_txt = (hash_txt * p + (text[i + m] - 'a' + 1)) % mod;
    }
}
