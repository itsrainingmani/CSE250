#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <math.h>

char swtchcs(char a){
    switch (a){
        case 'A':return '0'; break;
        case 'C':return '1'; break;
        case 'G':return '2'; break;
        case 'T':return '3';
    }
    return '0';
}

char swtchcs1(char a){
    switch (a){
        case '0': return 'A';break;
        case '1':return 'C';break;
        case '2':return 'G';break;
        case '3':return 'T';
    }
    return '0';
}
int convert10tob4(int index){
    int base4 = 0;
    for (int i = 1; index != 0;i*=10){
        base4 += (index%4)*i;
        index = index/4;
    }
    return base4;
}

int kmertob4(std::string s){
    int l = static_cast<int>(s.length());
    std::string b  = "";
    int b4 = 0;
    int l1 = l-1;
    for (int i=0; i<l;i++){
        b = swtchcs(s[i]);
        b4 += (std::atoi(b.c_str())*(pow(4,l1-i)));
    }
    return b4;
}

std::string b4tokmer(int n, int k){
    std::string s = "";
    std::string kmer = "";
    int len = 1;
    int x = n;
    while ( x/= 10)
        len++;
    std::stringstream ss;
    ss << n;
    s = ss.str();
    if ( len < k){
        for(int i=0; i<(k-len);i++){
        s.insert(i,1,'0');
        }
        for (int i = 0; i < k; i++){
            kmer += swtchcs1(s[i]);
        }
    }
    else{
        for (int i = 0; i < len; i++){
            kmer += swtchcs1(s[i]);
        }
    }
    return kmer;

}
int main(int argc, char *argv[]){
    /*if (argc < 2){
        std::cout<<"Please input the filename!\n"<<std::endl;
        return -1;
    }
    std::ifstream fin(argv[1]);
    if (!if){
     std::cout<<"file does not exist!\n"<<std::endl;
     return -2;

    } */
    std::ifstream fin("myfile.txt");
    std::string lines, lin[1];
    std::vector<std::string> numbers;
    std::vector<int> arr;
    int count1 = 0,n = 0;
    while ( std::getline(fin, lines)){
        ++count1;
        if (count1 == 1){
            lin[0] = lines;
            std::istringstream is(lin[0]);
            while( is >> n){
                arr.push_back(n);
            }
        }
        else{
        //std::cout<<lines<<std::endl;
        //totsize += static_cast<int>(lines.length());
        numbers.push_back(lines);
        }
    }
    int totsize = static_cast<int>(numbers.size());
    if ((arr[1] <= 1) || (arr[1] != totsize)){
        std::cout<<"error"<<std::endl;
        std::exit(1);
    }
    if (arr[0] < 3 || arr[0] > 11){
        std::cout<<"error"<<std::endl;
        std::exit(1);
    }
    /*
    for (int i=1; i<arr[1]; i++){
        numbers[0] += numbers[i];
    }
    for (int i=1; i<arr[1]; i++){
        numbers.pop_back();
    }
    */
    //int nok = totsize - arr[0] +1;
    //int kmer[nok];
    std::vector<int> kmer;
    /*
    for (int i=0; i < nok; i++){
        std::string emp = "";
        emp += numbers[0][i];
        for (int j=1; j < arr[0];j++){
            emp += numbers[0][j+i];
        }
        kmer[i] = kmertob4(emp);
        //std::cout<<kmer[i]<<std::endl;
    }
    */
    //for(int i=0;i < static_cast<int>(numbers.size());i++){
    //    std::cout<<numbers[i]<<std::endl;
    //}
    int sonum = static_cast<int>(numbers.size());
    int lol = 0;
    std::string emp = "";

    for (int i=0; i < sonum; i++){
        lol = static_cast<int>(numbers[i].length());
        //std::cout<<lol<<std::endl;
        int nok = lol - arr[0] +1;
        //std::cout<<nok<<std::endl;
        for (int j=0; j < nok;j++){
            for (int k=0; k<arr[0];k++){
                emp+= numbers[i][k+j];
            }
            //std::cout<<emp<<std::endl;
            kmer.push_back(kmertob4(emp));
            emp = "";
        }
    }
    numbers.clear();
    int ksize = pow(4,arr[0]);
    std::vector<int> dynarr(ksize, 0);
    for (int i=0;i<ksize;i++){
        for (int j=0;j < static_cast<int>(kmer.size());j++){
            if(i == kmer[j])
                dynarr[i]++;
            else
                dynarr[i] += 0;
        }
    }
    for (int i=0; i < ksize;i++){

        if (dynarr[i] > 0){
            std::cout<<b4tokmer(convert10tob4(i),arr[0])<<'\t'<<dynarr[i]<<std::endl;
        }
    }
    kmer.clear();
    dynarr.clear();
    return 0;
}
