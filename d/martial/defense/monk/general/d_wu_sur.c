
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
 if( !can_use(me, victim, weapon) ) return 0;
	return 5;
}

varargs int penetrate_modify(object me, object victim, object weapon)
{
	return 0;
}

varargs int damage_modify(object me, object victim, object weapon)
{
	return 1;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(7)];
}
