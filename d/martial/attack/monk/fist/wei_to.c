// wei-to.c
// This is a attack skill that is only available for monk.
inherit "/d/martial/attack/modify";
int query_need_fp()
{
       return 3;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( weapon ) return 0;
	return 1;
}

string *attack_msg = ({
"%s���׺�ɣ�������\ʯ�á�����%s",
"%s������ǰ�������������չȻ�������ֱȡ%s",
"%s����һ�Σ����ơ��������֡���%sһ��",
"%s����һԾ��һ�ǡ���ͷ���ȡ���%s��������",
"%s������ȭ������ͷ�ǰ�������%s",
"%s��ȭ��Σ����Ƴû������������硻��%s",
"%s����ʹ������������������%s�ӳ�",
"%s���ֻ������ǿϮ%s��һ�С��������֡����",
"%s�������籩�꣬һ�С�����ǿϮ��������%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon, int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (54*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (32*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	me->add("force_points", -query_need_fp());
        return ((13+random(8))*monk_modify(victim)/100); 
}

varargs string query_attack_msg(object me, object victim, int type)
{
        if( !(type) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(9)];
} 
