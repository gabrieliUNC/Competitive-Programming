#include <bits/stdc++.h>
using namespace std;

int n, c, stow, d; 

void moveController(){
    if(d){
        if(c == n - 1){
            d = 0;
            moveController();
        } else{
            ++c;
        }
    } else{
        if(c == 0){
            d = 1;
            moveController();
        } else{
            --c;
        }
    }
}

int main(){

    cin >> n >> stow >> c;
    c--; stow--;
    string check1, check2; cin >> check1 >> check2;


    d = check2 == "head" ? 0 : 1;

    string path; cin >> path;


    for(int min = 0; min < path.size(); ++min){
        if(path[min] == '1'){
            if(min == path.size() - 1){
                cout << "Stowaway" << '\n';
                return 0;
            }

            moveController();

            if(d){
                if(c == 0){
                    stow = n - 1;
                } else{
                    stow = 0;
                }
            } else{
                if(c == n - 1){
                    stow = 0;
            } else{
                stow = n - 1;
            }
        }
    } else{
        if(stow > c){
            if(stow != n - 1) ++stow;
            moveController();
            if(stow == c){
                cout << "Controller " << min + 1 << '\n';
                return 0;
            }
        } else{
            if(stow != 0) --stow;
            moveController();
            if(stow == c){
                cout << "Controller " << min + 1 << '\n';
                return 0;
            }
        }
    }


    }

    return 0;
}