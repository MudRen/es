// �������书��̫�󵶷���
inherit "/d/martial/attack/modify";
int query_need_fp()
{ 
    return 1;
}

varargs int can_use(object me, object victim, object weapon)
{
        // ȷ����ʹ�������Ƿ���ȷ
        if( !weapon || (string)weapon->query("type") != "longblade" ) return 0;
        return 1;
}

string *attack_msg = ({
        "ǰ�������%s��%s����",
        "ʹ��̫�󵶷��С���ɨǧ������%s������ң��ῳ%s",
        "һ�����У�����֮%s����%s",
        "��%sЮ��һ�󾢷磬����%s",
        "ʹ��һ�С����سɷ𡻣�%s����%s",
        "������ǰ��%sȫ������%s",
        "����һ�䣬%s���ٵĿ���%s",
        "ʹ��̫�󵶷�������һʽ��%s����%s",
        "ͻȻ��ת����%s����%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/tai-zuo");
	lvl = 6 + lvl/5;
	return (( ((hit/5)>lvl) ? lvl : hit/5 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	return (4*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/tai-zuo");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/tai-zuo", lvl+7);
	return ((2 + random(lvl/5))*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(9)];
}
