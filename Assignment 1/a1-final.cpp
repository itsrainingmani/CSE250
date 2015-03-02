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
    return 'A';
}
int convert4tob10(int index){
    int base10 = 0;
    for (int i = 1; index != 0;i*=10){
        base10 += (index%4)*i;
        index = index/4;
    }
    return base10;
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

std::string b10tokmer(int n, int k){
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
    std::string lines;
    std::vector<std::string> numbers;
    //std::vector<int> kmer;
    std::vector<int> arr;
    int count1 = 0,n = 0;
    while (std::getline(fin, lines)){
        ++count1;
        std::istringstream is(lines);
        while( is >> n){
            arr.push_back(n);
        }
        if (count1 == 1)
            break;
        break;
    }
    count1 = 0;
    int ksize = pow(4,arr[0]);
    //int* dynarr = new int[ksize]();
    std::vector<int> dynarr(ksize,0);
    std::string emp = "";
    while (std::getline(fin, lines)){
        ++count1;
        numbers.push_back(lines);
        int lol = static_cast<int>(lines.length());
        //std::cout<<lol<<std::endl;
        int nok = lol - arr[0] +1;
        //std::cout<<nok<<std::endl;
        for (int j=0; j < nok;j++){
            for (int k=0; k<arr[0];k++){
                emp+= numbers[0][k+j];
            }
            //std::cout<<emp<<std::endl;
            //std::cout<<kmertob4(emp)<<std::endl;
            //kmer.push_back(kmertob4(emp));
            int b10 = kmertob4(emp);
            //std::cout<<b10<<std::endl;
            dynarr[b10]++;
            emp = "";
        }
        //kmer.erase(kmer.begin(),kmer.end());
        numbers.pop_back();
    }
    if ((arr[1] <= 1) || (arr[1] != count1)){
        std::cout<<"error"<<std::endl;
        std::exit(1);
    }
    if (arr[0] < 3 || arr[0] > 11){
        std::cout<<"error"<<std::endl;
        std::exit(1);
    }
    for (int i=0; i < dynarr.size();i++){
        //std::cout<<dynarr[i]<<std::endl;
        if (dynarr[i] > 0){
            std::cout<<b10tokmer(convert4tob10(i),arr[0])<<'\t'<<dynarr[i]<<std::endl;
        }
    }
    /*
    int totsize = static_cast<int>(numbers.size());
    if ((arr[1] <= 1) || (arr[1] != totsize)){
        std::cout<<"error"<<std::endl;
        std::exit(1);
    }
    if (arr[0] < 3 || arr[0] > 11){
        std::cout<<"error"<<std::endl;
        std::exit(1);
    }
    //int nok = totsize - arr[0] +1;
    //int kmer[nok];

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
    /*
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
    */
    //delete[] dynarr;
    return 0;
}
