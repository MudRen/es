int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( !weapon || (string)weapon->query("type") != "blunt" )
		return 0;
	return 1;
}

string *defense_msg = ({
        "����һ��",
        "����һ��", 
        "�ٹ�����",
        "����˳��һƫ",
        "��%s��ͷ������һ��",
        "˫��ǰ�٣�΢һ��ת����",
});

varargs int hit_modify(object me, object victim, object weapon)
{
 int lvl;
 lvl = me->query("monk_gonfu/king-kong");
// if( !can_use(me, victim, weapon) ) return 0;
	return (lvl/5);
}

varargs int penetrate_modify(object me, object victim, object weapon)
{
   int lvl;
   lvl = me->query("monk_gonfu/king-kong");
	return (lvl/5);
}

varargs int damage_modify(object me, object victim, object weapon)
{
  int lvl;
  lvl = me->query("monk_gonfu/king-kong");
	return (lvl/5);
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(6)]+"���˹�\ʱ�Ե���������";        
//        return defense_msg[random(6)];
}
