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
        "%s����һ��",
        "%s����һ��", 
        "%s�ٵ�����",
        "%s����˳��һƫ",
        "%s�ٵ���ͷ������һ��",
        "%s�ᵶ����",
        "%s˫��ǰ�٣�΢һ��ת����",
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
        return defense_msg[random(7)]+"���˹�\ʱ�Ե���������";        
        return defense_msg[random(7)];
}
