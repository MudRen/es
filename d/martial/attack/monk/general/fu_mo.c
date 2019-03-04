// �������书����ħ������
inherit "/d/martial/attack/modify";

int query_need_fp()
{ 
    return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) )
                    return 0;
	return 1;
}

string *attack_msg = ({
        "̤��һ����%s��%sֱ������������ʮ��ǿ��",
        "ʹ����ħ������һ�С����Ī������%s������ң���ɨ%s",
        "%sһ�������������ɳ��ʯ������%s",
        "������ȭ�����ֵ�%s����һ�󾢷磬����%s",
        "˫����ת��������%sʹ��һ�С�һ�򵱹ء�������%s",
        "%s������������������������ɷ��衻����������衻��ʽ������%s",
        "�������ҷ�һ����%s���˷����������ޱȵĴ���%s",
        "���һ����%sʹ����ħ�����ġ���Ӱ���Ρ�������%s",
        "��%s������ת�����������Ӱ��ͻȻһ�С���������������䲻��Ĺ���%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/fu-mo");
	lvl = 10 + lvl/2 + random(lvl/4);
	return (( ((hit/4)>lvl) ? lvl : hit/4 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/fu-mo");
	lvl = 10 + random(lvl);
	return  (lvl*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/fu-mo");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/fu-mo", lvl/2+3);
	return (4*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(9)];
}
