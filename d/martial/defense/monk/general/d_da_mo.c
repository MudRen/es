
varargs int can_use(object me, object victim, object weapon)
{
	if( !weapon || (string)weapon->query("type") != "blunt" )
		return 0;
	return 1;
}

string *defense_msg = ({
        "����һ��",
        "����һ��", 
        "�ٹ�����",
        "����˳��һƫ",
        "��%s��ͷ������һ��",
        "˫��ǰ�٣�΢һ��ת����",
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
	return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(6)];
}
