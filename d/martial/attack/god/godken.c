// godken.c
// This is a attack skill that is only available for wizards.

int query_need_fp()
{
	return 0;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( weapon ) return 0;
	return 1;
}

string *attack_msg = ({
	"%sһ������%s",
	"%s����ǰ�������Ƴɻ�צ��ֱȡ%s",
	"%s����һ�Σ�������%sһ��",
	"%s����һԾ��һ������ԧ������%s��������",
	"%s������ȭ��һ�빥��%s",
	"%s��ȭ���һ�У����Ƴû�����%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon, int type)
{
	if( !type ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -50;
	return 100;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
	if( !type ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -50;
	return 100;
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
	if( !type ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	return 100;
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
	return attack_msg[random(sizeof(attack_msg))];
}
