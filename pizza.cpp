#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int noOfClients;
bool a[10000][10000];
namespace pizza{
    struct Client{
        vector<string> likes;
        vector<string> dislikes;
    };
}
map<int, pizza::Client> mata; 
bool check(pizza::Client a, pizza::Client b){
    for(auto it:a.likes){
        for(auto it1:b.dislikes){
            if(it==it1)return false;
        }
    }
    for(auto it:b.likes){
        for(auto it1:a.dislikes){
            if(it==*it1)return false;
        }
    }
    return true;
}
void constructGraph(){
    for(int i=1;i<=noOfClients-1;i++){
        for(int j=i+1;j<=noOfClients;j++){
            if(check(mata[i], mata[j])){a[i][j]=a[j][i]=true;}
        }
    }
}
int main(){
    cin>>noOfClients;
    for(int i=1;i<=noOfClients;i++){
        int lLikes, lDislikes;
        cin>>lLikes;
        for(int j=1;j<=lLikes;j++){
            string local;
            cin>>local;
            mata[i].likes.push_back(local);
        }
        cin>>lDislikes;
        for(int j=1;j<=lLikes;j++){
            string local;
            cin>>local;
            mata[i].dislikes.push_back(local);
        }
    }
    for(auto it:mata){for(auto it1:it.second.likes)cout<<it1<<'\n';for(auto it2:it.second.dislikes)cout<<it2<<'\n';}
}