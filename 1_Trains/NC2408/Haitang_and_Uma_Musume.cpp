// #define D

// #define set unordered_set
// #define map unordered_map

// #pragma GCC optimize(2)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int INF = 1145141919810LL;
#define lop(i, a, b) for(int i = a; i < b ; i++) 
#define all(x) x .begin(), x .end()
#define ord(u, v) {min(u ,v ),max(u ,v )}
#define db double
using namespace std;


vector<vector<vector<int>>> base =  //[lv][type][x] (5,vector<vector<int>>(5,vector<int>(6)))
{
    {
        {10,0,5,0,0,2},
        {0,9,0,4,0,2},
        {0,5,8,0,0,2},
        {4,0,4,8,0,2},
        {2,0,0,0,9,4}
    },
    {
        {11,0,5,0,0,2},
        {0,10,0,4,0,2},
        {0,5,9,0,0,2},
        {4,0,4,9,0,2},
        {2,0,0,0,10,4}
    },
    {
        {12,0,5,0,0,2},
        {0,11,0,4,0,2},
        {0,6,10,0,0,2},
        {4,0,4,10,0,2},
        {3,0,0,0,11,4}
    },
    {
        {13,0,5,0,0,2},
        {0,12,0,4,0,2},
        {0,6,11,0,0,2},
        {0,4,0,11,0,2},
        {3,0,0,0,12,4}
    },
    {
        {14,0,5,0,0,2},
        {0,13,0,4,0,2},
        {0,7,12,0,0,2},
        {5,0,5,12,0,2},
        {4,0,0,0,13,4}
    }
};

map<string,int> v2i = {
    {"speed",0},
    {"sta",1},
    {"power",2},
    {"guts",3},
    {"wis",4},
    {"skill",5}
};

vector<double> coe = {-0.2,-0.1,0,0.1,0.2};

class SC{
public:
    int friends,drive_a,train;
    int speed_0, speed_a,
        sta_0,   sta_a,
        power_0, power_a,
        guts_0,  guts_a,
        wis_0,   wis_a,
        skill_0 = 0, skill_a = 0;

};


class UM{
public:
    int speed,sta,power,guts,wis,skill;
    int speed_0, speed_m,
        sta_0,   sta_m,
        power_0, power_m,
        guts_0,  guts_m,
        wis_0,   wis_m,
        skill_0 = 120, skill_m = 0;
    void init(vector<SC> &scs)
    {
        // speed = speed_0;sta = sta_0;power = power_0;guts = guts_0;wis = wis_0;skill = skill_0;

        // --- X ---
        // int sumX = this->X_0;
        // for(auto x:scs) sumX += x.X_0;
        // X = sumX;

        // --- speed ---
        int sumspeed = this->speed_0;
        for(auto x:scs) sumspeed += x.speed_0;
        speed = sumspeed;

        // --- sta ---
        int sumsta = this->sta_0;
        for(auto x:scs) sumsta += x.sta_0;
        sta = sumsta;

        // --- power ---
        int sumpower = this->power_0;
        for(auto x:scs) sumpower += x.power_0;
        power = sumpower;

        // --- guts ---
        int sumguts = this->guts_0;
        for(auto x:scs) sumguts += x.guts_0;
        guts = sumguts;

        // --- wis ---
        int sumwis = this->wis_0;
        for(auto x:scs) sumwis += x.wis_0;
        wis = sumwis;

        skill = 120;

        // // --- skill ---
        // int sumskill = this->skill_0;
        // for(auto x:scs) sumskill += x.skill_0;
        // skill = sumskill;

    }

    void print()
    {
        cout << speed << " "<< sta << " "<< power << " "<< guts << " "<< wis << " "<< skill << "\n";
    }
};



class TR{
public:
    int summer,weight,drive,type,lv;
    vector<pair<SC,bool>> sclist;

    void train(UM & um)
    {
        // // ------------- X ---------------
        // double dX = 1;
        // double sPresentX = base[lv-1][type][v2i["X"]];
        // for(auto x:sclist) sPresentX += x.fi.X_a;
        // double mFriendsX = 1;
        // for(auto x:sclist) if(x.second) mFriendsX *= (1+0.01*x.first.friends);
        // double sPresentTrainX = 1;
        // for(auto x:sclist) sPresentTrainX += 0.01*x.fi.train;
        // double sPresentDriveX = 1;
        // for(auto x:sclist) sPresentDriveX += 0.01*x.fi.drive_a;
        // sPresentDriveX *= coe[this->drive];
        // sPresentDriveX ++;
        // double tX = 1 + 0.01 * um.X_m;
        // double raddX = 1;
        // for(auto x:sclist) raddX += 0.05;

        // if("X" == "speed" && weight == 1) dX = 0;

        // um.X += (int)(dX * sPresentX * mFriendsX * sPresentTrainX * sPresentDriveX * tX * raddX );
        
        // if("X" != "skill") um.X = min(1200,um.X);
        // // ---------------end---------------


        // ------------- speed ---------------
        double dspeed = 1;
        double sPresentspeed = base[lv-1][type][v2i["speed"]];
        for(auto x:sclist) sPresentspeed += x.fi.speed_a;
        double mFriendsspeed = 1;
        for(auto x:sclist) if(x.second) mFriendsspeed *= (1+0.01*x.first.friends);
        double sPresentTrainspeed = 1;
        for(auto x:sclist) sPresentTrainspeed += 0.01*x.fi.train;
        double sPresentDrivespeed = 1;
        for(auto x:sclist) sPresentDrivespeed += 0.01*x.fi.drive_a;
        sPresentDrivespeed *= coe[this->drive];
        sPresentDrivespeed ++;
        double tspeed = 1 + 0.01 * um.speed_m;
        double raddspeed = 1;
        for(auto x:sclist) raddspeed += 0.05;

        if("speed" == "speed" && weight == 1) dspeed = 0;

        um.speed += (int)(dspeed * sPresentspeed * mFriendsspeed * sPresentTrainspeed * sPresentDrivespeed * tspeed * raddspeed );
        
        if("speed" != "skill") um.speed = min(1200LL,um.speed);
        // ---------------end---------------


        // ------------- sta ---------------
        double dsta = 1;
        double sPresentsta = base[lv-1][type][v2i["sta"]];
        for(auto x:sclist) sPresentsta += x.fi.sta_a;
        double mFriendssta = 1;
        for(auto x:sclist) if(x.second) mFriendssta *= (1+0.01*x.first.friends);
        double sPresentTrainsta = 1;
        for(auto x:sclist) sPresentTrainsta += 0.01*x.fi.train;
        double sPresentDrivesta = 1;
        for(auto x:sclist) sPresentDrivesta += 0.01*x.fi.drive_a;
        sPresentDrivesta *= coe[this->drive];
        sPresentDrivesta ++;
        double tsta = 1 + 0.01 * um.sta_m;
        double raddsta = 1;
        for(auto x:sclist) raddsta += 0.05;

        if("sta" == "speed" && weight == 1) dsta = 0;

        um.sta += (int)(dsta * sPresentsta * mFriendssta * sPresentTrainsta * sPresentDrivesta * tsta * raddsta );
        
        if("sta" != "skill") um.sta = min(1200LL,um.sta);
        // ---------------end---------------


        // ------------- power ---------------
        double dpower = 1;
        double sPresentpower = base[lv-1][type][v2i["power"]];
        for(auto x:sclist) sPresentpower += x.fi.power_a;
        double mFriendspower = 1;
        for(auto x:sclist) if(x.second) mFriendspower *= (1+0.01*x.first.friends);
        double sPresentTrainpower = 1;
        for(auto x:sclist) sPresentTrainpower += 0.01*x.fi.train;
        double sPresentDrivepower = 1;
        for(auto x:sclist) sPresentDrivepower += 0.01*x.fi.drive_a;
        sPresentDrivepower *= coe[this->drive];
        sPresentDrivepower ++;
        double tpower = 1 + 0.01 * um.power_m;
        double raddpower = 1;
        for(auto x:sclist) raddpower += 0.05;

        if("power" == "speed" && weight == 1) dpower = 0;

        um.power += (int)(dpower * sPresentpower * mFriendspower * sPresentTrainpower * sPresentDrivepower * tpower * raddpower );
        
        if("power" != "skill") um.power = min(1200LL,um.power);
        // ---------------end---------------


        // ------------- guts ---------------
        double dguts = 1;
        double sPresentguts = base[lv-1][type][v2i["guts"]];
        for(auto x:sclist) sPresentguts += x.fi.guts_a;
        double mFriendsguts = 1;
        for(auto x:sclist) if(x.second) mFriendsguts *= (1+0.01*x.first.friends);
        double sPresentTrainguts = 1;
        for(auto x:sclist) sPresentTrainguts += 0.01*x.fi.train;
        double sPresentDriveguts = 1;
        for(auto x:sclist) sPresentDriveguts += 0.01*x.fi.drive_a;
        sPresentDriveguts *= coe[this->drive];
        sPresentDriveguts ++;
        double tguts = 1 + 0.01 * um.guts_m;
        double raddguts = 1;
        for(auto x:sclist) raddguts += 0.05;

        if("guts" == "speed" && weight == 1) dguts = 0;

        um.guts += (int)(dguts * sPresentguts * mFriendsguts * sPresentTrainguts * sPresentDriveguts * tguts * raddguts );
        
        if("guts" != "skill") um.guts = min(1200LL,um.guts);
        // ---------------end---------------


        // ------------- wis ---------------
        double dwis = 1;
        double sPresentwis = base[lv-1][type][v2i["wis"]];
        for(auto x:sclist) sPresentwis += x.fi.wis_a;
        double mFriendswis = 1;
        for(auto x:sclist) if(x.second) mFriendswis *= (1+0.01*x.first.friends);
        double sPresentTrainwis = 1;
        for(auto x:sclist) sPresentTrainwis += 0.01*x.fi.train;
        double sPresentDrivewis = 1;
        for(auto x:sclist) sPresentDrivewis += 0.01*x.fi.drive_a;
        sPresentDrivewis *= coe[this->drive];
        sPresentDrivewis ++;
        double twis = 1 + 0.01 * um.wis_m;
        double raddwis = 1;
        for(auto x:sclist) raddwis += 0.05;

        if("wis" == "speed" && weight == 1) dwis = 0;

        um.wis += (int)(dwis * sPresentwis * mFriendswis * sPresentTrainwis * sPresentDrivewis * twis * raddwis );
        
        if("wis" != "skill") um.wis = min(1200LL,um.wis);
        // ---------------end---------------


        // ------------- skill ---------------
        double dskill = 1;
        double sPresentskill = base[lv-1][type][v2i["skill"]];
        for(auto x:sclist) sPresentskill += x.fi.skill_a;
        double mFriendsskill = 1;
        for(auto x:sclist) if(x.second) mFriendsskill *= (1+0.01*x.first.friends);
        double sPresentTrainskill = 1;
        for(auto x:sclist) sPresentTrainskill += 0.01*x.fi.train;
        double sPresentDriveskill = 1;
        for(auto x:sclist) sPresentDriveskill += 0.01*x.fi.drive_a;
        sPresentDriveskill *= coe[this->drive];
        sPresentDriveskill ++;
        double tskill = 1 + 0.01 * um.skill_m;
        double raddskill = 1;
        for(auto x:sclist) raddskill += 0.05;

        if("skill" == "speed" && weight == 1) dskill = 0;

        um.skill += (int)(dskill * sPresentskill * mFriendsskill * sPresentTrainskill * sPresentDriveskill * tskill * raddskill );
        
        if("skill" != "skill") um.skill = min(1200LL,um.skill);
        // ---------------end---------------



        // double 
    }

};

void solve()
{
    UM um;
    cin >> um.speed_0 >> um.sta_0 >> um.power_0 >> um.guts_0 >> um.wis_0
        >> um.speed_m >> um.sta_m >> um.power_m >> um.guts_m >> um.wis_m;
    vector<SC> scs(6);
    for(auto &x:scs)
    {
        cin >> x.friends >> x.drive_a >> x.train 
            >> x.speed_0 >> x.sta_0 >> x.power_0 >> x.guts_0 >> x.wis_0
            >> x.speed_a >> x.sta_a >> x.power_a >> x.guts_a >> x.wis_a;
    }
    um.init(scs);
    int n;
    cin >> n;
    map<int,int> type2tice;

    auto lv = [&](TR tr) -> int
    {
        if(tr.summer) return 5LL;
        else return min(5LL,type2tice[tr.type]/4 +1);
    };

    // map<int,vector<int>> type2idx;
    // vector<TR> trs;
    while(n--)
    {
        TR tr;
        cin >> tr.summer >> tr.weight >> tr.drive >> tr.type;
        int s;
        cin >> s;
        lop(i,0,s)
        {
            int c;
            bool iffr;
            cin >> c >> iffr;
            c --;
            tr.sclist.pb({scs[c],iffr});
        }
        tr.lv = lv(tr);
        tr.train(um);
        if(!tr.summer) type2tice[tr.type] ++;
        um.print();
    }
}

signed main()
{
#ifndef D
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif
    int T = 1;
    // cin >> T;

    for (int i = 0; i < T; i++) solve();

    // system("pause");

    return 0;
}
