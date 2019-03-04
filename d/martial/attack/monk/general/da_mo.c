// �������书����Ħ������
inherit "/d/martial/attack/modify";

int query_need_fp()
{ 
    return 1+random(2);
}

varargs int can_use(object me, object victim, object weapon)
{
        // ȷ����ʹ�������Ƿ���ȷ
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) )
            return 0;                
        return 1;
}

string *attack_msg = ({
        "����������%s��%s�Ҳ�����������ʹ������ţ���ء�",
        "ʹ����Ħ������һ�С�ҹ��ͨ�졻��%s��ǰ�ô򣬴���%s",
        "%sʹ�����Ʒɵ������������ɳ��ʯ��б��%s",
        "%s����һ�󾢷磬���軨����������%s",
        "�ҽŲ���أ�%s�����������������%s�����ǡ����Ǹ��¡�",
        "%s��Գ��Ϸ�ǡ�������ͷ���¡���ʽ�������ޱȻ���%s",
        "�������ҷ�һ����%sһ�С�ҹ�洩��������%s",
        "��Хһ����%sʹ������Ա�����������%s",
        "��%s��ǰ����ʣ�ͻȻ��������һ�С��ͻ�������������%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/da-mo");
	lvl = 8 + lvl/5;
	return (( ((hit/4)>lvl) ? lvl : hit/4 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	return (6*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/da-mo");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/da-mo", lvl/2+10);
	return (3*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(9)];
}
