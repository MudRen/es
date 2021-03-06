
varargs int can_use(object me, object victim, object weapon)
{
	if( !weapon || (string)weapon->query("type") != "longblade" )
		return 0;
	return 1;
}

string *defense_msg = ({
        "%s後退一步",
        "%s向後一闪", 
        "%s举刀护身",
        "%s身体顺势一偏",
        "%s举刀护头，身子一低",
        "%s横刀护身",
        "%s双手前举，微一旋转身形",
});

varargs int hit_modify(object me, object victim, object weapon)
{
	return 5;
}

varargs int penetrate_modify(object me, object victim, object weapon)
{
	return 0;
}

varargs int damage_modify(object me, object victim, object weapon)
{
	return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(7)];
}
