//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int mod = 75461687;

class user{
    public:
        string name;
        long long sifre;
};

int StringHash(string yazi){
    int pow = 1;
    long long sum =0;

    for(int i = 0 ; i < yazi.length() ; i++){
        sum = (sum + ((yazi[i]-'a')*pow)%mod)%mod;
        pow = (pow*29)%mod;
    }
    return sum;
}

int main() {

    vector<user> v;

    int a = 1;

    srand(time(0));

    while(a){

        cout<<"Log in   - 1"<<"\n";
        cout<<"Register - 2"<<"\n";
        cout<<"Exit     - 3"<<"\n";
        cout<<"\n"<<"Seciniz : ";
        int secim;
        cin>>secim;

        if(secim == 1){

            cout<<"Kullanici adi giriniz: ";

            string ad;

            cin>>ad;

            int flag = 0;
            user buldum;

            for(int i = 0 ; i < v.size() ; i++){
                if(ad == v[i].name){
                    buldum = v[i];
                    flag = 1;
                }
            }
            if(flag == 0){
                cout<<"Kullanici yok"<<"\n";
            }
            else{
                cout<<"Sifre giriniz: ";
                string pas;
                cin>>pas;
                long long sayi = StringHash(pas);
                long long topla = sayi;

                int rastgele = rand()%500;
                rastgele += 500;

                long long ara = buldum.sifre;
                long long ariyom = ara;

                for(int i = 0 ; i < rastgele ; i++ ){
                    topla = (topla * sayi)%mod;
                    ariyom = (ariyom * ara)%mod; 
                }

                cout<<"Sunucuya gonderilen sayi: "<<topla<<"\n";

                if(ariyom == topla){
                    cout<<"Login basarili"<<"\n";
                }
                else{
                    cout<<"Error yanlis sifre"<<"\n"; 
                }


            }


        }


        else if(secim == 2){
            user cur;
            cout<<"Kullanici adi giriniz: ";
            
            cin>>cur.name;
            cout<<"\n"<<"Sifre seciniz : ";

            string sifre;

            cin>>sifre;

            cur.sifre=StringHash(sifre);

            v.push_back(cur);
        }


        else if(secim == 3){
            a = 0;
        }
    }

	return 0;
}
