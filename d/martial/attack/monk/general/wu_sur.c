// �������书����ɫ������
inherit "/d/martial/attack/modify";
int query_need_fp()
{ 
    return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( !weapon || (string)weapon->query("type") != "longblade" ) return 0;
	return 1;
}

string *attack_msg = ({
        "��%s��%s����������ȥ��ʮ��ǿ��",
        "ʹ����ɫ�����С���ɫ���Ρ���%s����%s",
        "���β���������%s���ƴ��͵�б��%s",
        "ʹ�����С���������������������������������������%s����%s",
        "������ǰ��ʹ������������������%s����%s",
        "����ʹ����������š������ư��ǰ�����ʽ�����е�%s����%s",
        "��������һ����������%s����%s",
        "ʹ����ɫ�����ġ���֮�����������е�%s������Ϣ����%sһ��",
        "�������ˣ�ͻȻһ�С�ɫ����ա������е�%s���䲻�⿳��%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/wu-sur");
	lvl = 12 + lvl/2 + random(lvl/4);
	return (( ((hit/4)>lvl) ? lvl : hit/4 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/wu-sur");
	lvl = 10 + random(lvl); 
	return  (lvl*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/wu-sur");
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/wu-sur", lvl/2+3);
	return  (4*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(9)];
}
