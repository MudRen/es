// 少林寺武功「小洪拳」 part3
// angel
// Jun 4 1994


varargs int can_use(object me, object victim, object weapon)
{
        if (weapon) return 0;
        return 1;
}

string *defense_msg = ({
        "%s後退一步",
        "%s向後一闪", 
        "%s双掌护身",
        "%s身体顺势一偏",
        "%s举手护头，身子一低",
        "%s左手横架",
        "%s双手前举，微一旋转身形",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 5;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
        return 0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
        return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(7)];
}
