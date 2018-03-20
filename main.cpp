#include <iostream>
#include <fstream>
#include <cstring>


using namespace std; //wiki 3pg: 1-paste eneunt 2-abordare 3-pas iterativ

struct stare
{
    struct tranzitie
    {
        int ndestinatii=0,destinatii[25]={0};
    }tranzitii[26];
    int ntranzitii=0;
    int final=0;
}stari[100];
/*

tranzitie-96=destinatie a==97

data.in:
nfinale
finale
total tranzitii
tranzitii
cuvant
*/

int rezolva(int stareCurenta,char cuvant[50],int lungimeCuvant)
{
    if(lungimeCuvant==strlen(cuvant))
    {
        //cout<<'\n';
        if(stari[stareCurenta].final)
            return 1;
        else
            return 0;
    }
    //cout<<stareCurenta<<" ";
    int i,tranzitieCitita=int((cuvant[lungimeCuvant])-96);
    for(i=0;i<=stari[stareCurenta].tranzitii[tranzitieCitita].ndestinatii;i++)
        if(rezolva(stari[stareCurenta].tranzitii[tranzitieCitita].destinatii[i],cuvant,lungimeCuvant+1))
            return 1;
    return 0;
}

int main()
{
    ifstream f("data.in");
    int nfinale,totalTranzitii,i,aux1,aux2;
    char link,cuvant[50];
    f>>nfinale;
    for(i=0;i<nfinale;i++)
    {
        f>>aux1;
        stari[aux1].final=1;
    }
    f>>totalTranzitii;
    for(i=0;i<totalTranzitii;i++)
    {
        f>>aux1>>link>>aux2;
        stari[aux1].tranzitii[int(link-96)].destinatii[stari[aux1].tranzitii[int(link-96)].ndestinatii++]=aux2;
        stari[aux1].ntranzitii++;
    }
    f>>cuvant;
    cout<<"1=apartine, 0=nu apartine: "<<rezolva(1,cuvant,0)<<'\n'<<'\n';
    /*
    for(i=1;i<=5;i++)
    {
        cout<<i<<'\n';
        cout<<stari[i].ntranzitii<<" tranzitii din el:\n";
        for(int j=1;j<=25;j++)
        {
            if(stari[i].tranzitii[j].ndestinatii==0)
                continue;
            cout<<stari[i].tranzitii[j].ndestinatii<<" cu "<<char(j+96)<<": \n";
            for(int l=0;l<stari[i].tranzitii[j].ndestinatii;l++)
                cout<<i<<" "<<char(j+96)<<" "<<stari[i].tranzitii[j].destinatii[l]<<'\n';
        }
        cout<<'\n';
    }
    */
    f.close();
}
