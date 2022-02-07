#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool checkI(int i, int rb, int rs, int rc, int nb, int ns, int nc, int pb, int ps, int pc, int r){
    //lets first use all the initial ingredients to make (i) hamburgers
        int nb_ = rb*i - nb; //nb_ consists how many breads we still require to make (i) hamburgers
        int ns_ = rs*i - ns; //ns_ consists how many sausages we still require to make (i) hamburgers
        int nc_ = rc*i - nc; //nc_ consists how many cheese we still require to make (i) hamburgers

        //if we do not require one or more ingredients in the recipe, the values (rb*i - nb) or (rs*i - ns)
        //or (rc*i - nc) might become negative. So we assign them back to 0, it wont affect the answer.
        //TEST CASE 2 - recipe - "BBC" and No of Sausage in Kitchen = 10 which is not required at all.
        if(nb_ < 0)
            nb_ = 0;
        if(ns_ < 0)
            ns_ = 0;
        if(nc_ < 0)
            nc_ = 0;

        //lets calculate the price (rubles) to buy the above required ingredients
        int pb_ = nb_ * pb; //pb_ stores the price to buy the required breads to make (i) hamburgers
        int ps_ = ns_ * ps; //ps_ stores the price to buy the required sausages to make (i) hamburgers
        int pc_ = nc_ * pc; //pc_ stores the price to buy the required cheese to make (i) hamburgers

        //lets calculate the total price (rubles) required
        int total = pb_ + ps_ + pc_;

        //if total price required is less than or equal to the rubles i have, then we can make (i) hamburgers
        //else we cannot make (i) or (i+1) or (i+2) ...... ∞ hamburgers and we break
        if(total <= r)
            return true;
        return false;
}

int solve(){
    //Taking Recipe string 
    string s;
    cin >> s;

    //Taking Initial ingredients in kitchen 
    int nb,ns,nc;
    cin >> nb >> ns >> nc;

    //Taking Price of each ingredients in the shop 
    int pb,ps,pc;
    cin >> pb >> ps >> pc;

    //Taking Rubles we have to invest 
    int r;
    cin >> r;

    //Counting the number of breads, sausages and cheese we need for the particular recipe
    int rb = 0, rs = 0, rc = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='B')
            rb++;
        else if(s[i]=='S')
            rs++;
        else
            rc++;
    }

    //it will store the maximum possible answer
    int ans = 0;

    /*
    //Brute Force approach - LINEAR SEARCH
    //Run a single for loop and check if to make (i) number of hamburgers do we have ingredients and rubles?
    //if yes, assign (i) to (ans), else break;
    for(int i = 0; i <= ∞; i++){
        if(checkI(i,rb,rs,rc,nb,ns,nc,pb,ps,pc,r)==true)
            ans = i;
        else    
            break;
    }
    */
    
    //Optimized approach - BINARY SEARCH
    int left = 0, right = 1e14;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(checkI(mid,rb,rs,rc,nb,ns,nc,pb,ps,pc,r)==true){
            ans = mid;
            left = mid+1;
        } else{
            right = mid-1;
        }
    }
    return ans;
}

int32_t main(){
    int ans = solve();
    cout << ans << endl;
    return 0;
}
