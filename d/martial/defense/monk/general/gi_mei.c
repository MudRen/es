// �������书����������

int query_need_fp()
{ 
    return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( undefinedp(me->query("monk_gonfu/gi-mei")) ) return 0;
	return 1;
}

string *defense_msg = ({
        "%s��̤���ǣ����ٵ������߲�",
        "%sʹ��������Ϊ�֡�������ͻȻ��Ĳ����", 
        "%s˫�ƺ�ʮ�����������ݰ�Ĳ�ͣ��ת",
        "%s����˳�����ϰθ�",
        "%s���嶫����ת���ϱ�����",
        "%s����������գ������ռ������ο��ٵ������ȥ",
        "%s˫��Ʈ�ƣ���������׽��",
        "%s����һ��",
});

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -20;
   	lvl = (int)me->query("monk_gonfu/gi-mei");
        me->add("gonfus_exp/gi-mei", lvl+7);
        me->add("force_points", -query_need_fp() ); 
   	lvl = 20 + lvl/5 + random(lvl/2); 
   	return ((hit/3) > lvl ? lvl : hit/3 );
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
   	return  0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	return 3;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(8)]+"������ʱ�Ե���������";
        return defense_msg[random(8)];
}
