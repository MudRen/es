// �������书����ղ������񹦡�

void special_defense(object ob1)

// ԭ�������ع���ָ�ظ� hp , ����Ϊ�ƺ����ղ�����û��ʲ�����,
// ���ر�. ������д��������Ϊ�ع�, ���� player ������Ϊ����������
// ��������Ĵ�С.....
// ����Ŀǰ player �� inner-force skill<=95 & force_effect<=4
// 0 < return_dam < 53    0 < got_heal < 25
// ������ֵ���� body-def �� lv ��ֱ�����....

{
    int fp,lvl,return_dam,got_heal;
    object victim;
    
    victim = ob1->query_attacker();
    
    tell_object( ob1,
       sprintf("��Ѹ�ٵ������ܹĶ��������壬��%s�Ĺ��������ȥ���Լ�ȴҲ�ܵ������ļ���������������\n",
           victim->query("c_name") )
    );
    
    tell_room( environment(ob1),
       sprintf("\n%s������ͻȻ����һ����������ղ�����\�İ����ķ��ƺ����������������������\n\n",ob1->query("c_name")),
    ({ victim, ob1 }) );
    
    ob1->block_attack(4);

    tell_object( victim,
       sprintf("\n��ͻȻ�е����ԣ�%sǿ�����������ʹ����Ѫ��ӿ��һʱ�������á�\n",
           ob1->query("c_name") ) 
    );
    
    victim->block_attack(2);

    fp = ob1->query("force_points");
    lvl = ob1->query("monk_gonfu/body-def");
    return_dam = (fp/5) * lvl / 50;
    got_heal = 5 * lvl / 7;
    victim->receive_damage( return_dam );
    ob1->receive_healing( got_heal );
    
    if( wizardp(ob1) )
       sprintf("\n[ Return_damage : %d    Got_healing : %d ]\n",return_dam,got_heal);
}

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( undefinedp(me->query("monk_gonfu/body-def")) ) return 0;
	return 1;
}

string *defense_msg = ({
        "%s�˹�����һ������֮����סȫ��", 
        "%s˫�ƺ�ʮ����������ȫ��",
        "%s����˳��һ��",
        "%s�����ղ�������",
        "%s���̡��������������سɷ𡻣������ڹ�����",
        "%sĬ���񹦿ھ�... ˫Ŀ�������",
});

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -30;
   	lvl = (int)me->query("monk_gonfu/body-def");
        me->add("gonfus_exp/body-def", lvl/2+6);
        me->add("force_points", -query_need_fp() ); 
   	lvl = 25 + lvl/2; 
   	return ((hit/3) > lvl ? lvl : hit/3 );
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -20;
   	lvl = (int)me->query("monk_gonfu/body-def");
   	lvl = 20 +  random(lvl/2);
   	return ((pen/3) > lvl ? lvl : pen/4 );
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -10;
   	lvl = (int)me->query("monk_gonfu/body-def");

        if( random(350)<lvl ) special_defense(me);
        
   	lvl = 15 + lvl/5 + random(lvl/5);
   	return ((damage/3) > lvl ? lvl : damage/3 ); 
   	
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(6)]+"���˹�ʱ�Ե���������"; 
	return defense_msg[random(6)];
}
