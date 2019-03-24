long ipToVal(string ip) {
    long val = 0;
    int i = 0;
    for(int j=0; i<4 && j<ip.length; ++i){
        // 查找某一给定位置后的子串的位置
        auto nx = ip.find('.', j);
        if(nx == ip.npos){
            val = (val << 8) + atoi(ip.substr(j).c_str());
            ++i;
            break;
        }
        val = (val<<8) + atoi(ip.substr(j, nx - j).c_str());
        j = nx +1;
    
    }
    if(i!=4) throw "the ip is incorrect";
    return val;
}

string valToIp(long val){
    string ip = "";
    for(int i =0; i<4; ++i){
        ip = to_string(val % 256) + "." + ip;
        val /= 256;
    }
    ip.pop_back();
    return ip;
}

vector<string> range2cidr(string start, string end){
    long st = ipToVal(start), ed = ipToVal(end);
    vecto<string> ans;
    while(st <= ed) {
        int lastOne = st & (-st);
        int maxMask - 32 - int((log(startOne)/log(2)));
        int maxDiff = 32 - int(floor(log(ed-st+1)/log(2)));
        maxMAsk = max(maxMask, maxDiff);
        string ip = valToIp(st);
        ans.push_back(ip+'/'+to_string(maxMask));
        st += int(pow(2, 32-maxMask));
    }
    return ans;
}
