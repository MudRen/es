// tanlo.c, the defense skill for scholars.

varargs int can_use(object me, object victim, object weapon)
{
	if( undefinedp(me->query("scholar_gonfu/tanlo")) ) return 0;
	return 1;
}

string *defense_msg = ({
	"%s����һ�Σ����ἱ�����߲�",
	"%s��������һԾ",
	"%s��̤Ǭ����ת��λ",
	"%sͻȻ����ǰ��",
});

int query_need_fp()
{
	return 2;
}

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
	int lvl;

	if( me->query("force_points") < query_need_fp() ) return -20;
	lvl = (int)me->query("scholar_gonfu/tanlo");
	me->add("gonfus_exp/tanlo", lvl+1);
	me->add("force_points", -query_need_fp());
	lvl = 5+lvl/2+random(lvl);
	return ( ((hit/3) > lvl) ? lvl : hit/3 );
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
	return 0;
}

varargs int damage_modify(int dam, object me, object victim, object weapon)
{
	return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
	return defense_msg[random(sizeof(defense_msg))];
}
