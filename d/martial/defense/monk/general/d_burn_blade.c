int query_need_fp()
{ 
    return 5;
}

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
 int lvl;
 lvl = me->query("monk_gonfu/burn-blade");
	return (lvl/5);
}

varargs int penetrate_modify(object me, object victim, object weapon)
{
   int lvl;
   lvl = me->query("monk_gonfu/burn-blade");
	return (lvl/5);
}

varargs int damage_modify(object me, object victim, object weapon)
{
 int lvl;
 lvl = me->query("monk_gonfu/burn-blade");
	return (lvl/5);
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
	if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(7)]+"但运功\时显得内力不足";        
        return defense_msg[random(7)];
}
