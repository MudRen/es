// �������书���Ⱥ��ն��񹦡�

int query_need_fp()
{ 
    return 3;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( undefinedp(me->query("monk_gonfu/chu-han")) ) return 0;
	return 1;
}

// ��ʽս��ѶϢ
string *defense_msg = ({
        "%s���ٵ���������",
        "%sʹ��������𡻣��˹�\����", 
        "%s˫�ƺ�ʮ�����̡�������Ϊ�����ڲ���Ϊ����",
        "%s����˳��һƫ",
        "%s˫�־����ͷ�����κ�Ȼһ��",
        "%s���̡��������ģ�Ӧ���ް����������ڹ�\����",
        "%s����һ�ܣ���������һ��",
        "%s˫��ǰ�٣�Ĭ����\�ھ����Ĳ�ס����������ͨ��",
});

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -20;
   	lvl = (int)me->query("monk_gonfu/chu-han");
        me->add("gonfus_exp/chu-han", lvl+5);
        me->add("force_points", -query_need_fp() ); 
   	lvl = 20 + lvl/5+ random(lvl/3); 
   	return ((hit/3) > lvl ? lvl : hit/3 );
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
   	return 0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	lvl = (int)me->query("monk_gonfu/chu-han");
   	lvl = 5 + random(lvl/3) ;
   	return ((damage/3) > lvl ? lvl : damage/3 );
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(8)]+"���˹�\ʱ�Ե���������";
        return defense_msg[random(8)];
}
