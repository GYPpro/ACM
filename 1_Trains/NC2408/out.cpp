
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

        // --- skill ---
        int sumskill = this->skill_0;
        for(auto x:scs) sumskill += x.skill_0;
        skill = sumskill;
