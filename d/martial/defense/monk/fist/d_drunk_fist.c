// 少林寺武功「醉拳」 part3
// angel
// Jun 4 1994

varargs int can_use(object me, object victim, object weapon)
{
        if(weapon) return 0;
        return 1;
}

// 各式战斗讯息
string *defense_msg = ({
        "%s使出『太白醉酒』身形飘浮", 
        "%s左掌护身，顺势身形一闪",
        "%s左手护额，使出『八仙醉坪』",
        "%s连退三步",
        "%s左手往前架住",
        "%s一招『醉仙拜天』顺势向下一闪",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 10;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
        return 4;
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
