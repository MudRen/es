// �������书���������ȡ�

int query_need_fp()
{ 
    return 1;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( undefinedp(me->query("monk_gonfu/bolo-mi")) ) return 0;
	return 1;
}

string *defense_msg = ({
        "%s����̤��һ�������˷���",
        "%sʹ������������һ�С��������ޡ��������������ƫ",
        "%s˫����ȭ�����������һ��",
        "%s��ת��������˳��һƫ",
        "%s˫�ֻ��أ�˫��ǰ�����",
        "%s�������ҷ�һ��",
        "%s������ǰһ��",
        "%sͻȻ������ת��������",
});

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -20;
   	lvl = (int)me->query("monk_gonfu/bolo-mi");
        me->add("gonfus_exp/bolo-mi", lvl+10);
        me->add("force_points", -query_need_fp() ); 
   	lvl = 20 + lvl/5; 
   	return ((hit/3) > lvl ? lvl : hit/3 );
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
   	return 0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
   	return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(8)]+"������ʱ�Ե���������";
        return defense_msg[random(8)];
}
