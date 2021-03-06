// 少林寺武功「韦陀掌」 part3
// angel
// Jun 4 1994

varargs int can_use(object me, object victim, object weapon)
{
       
        if( weapon ) return 0;
        return 1;
}


// 各式战斗讯息
string *defense_msg = ({
        "%s双手圈住全身", 
        "%s双掌护身，顺势身形向左一闪",
        "%s前弓後箭，左手护额",
        "%s连退三步",
        "%s左手往前架住",
        "%s使出『散步于空』旋转身形，顺势向旁一闪",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 4;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
        return 6;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
        return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(6)];
}
