// ��������ʮ������������ȷ���
inherit "/d/martial/attack/modify";

void special_attack(object ob1, object victim)
{
  int damage;
  damage = ob1->query("monk_gonfu/king-kong") + (ob1->query("min_damage1")+ob1->query("max_damage1"))/2 ;

  if ( !ob1->query_attackers() || !victim )
       return ;
  tell_object( victim,
       sprintf("%s���һ����¶����շ��񣬶�������һ����������ʹ�ѵ�\n\n",(string)ob1->query("c_name")) );
                           
  tell_room( environment(ob1),
       sprintf("\n\n%s���һ����¶����շ������㵱��������һ�ӽ�%s����ҡҡ�λΣ�վ��ס�š�\n\n",(string)ob1->query("c_name"),(string)victim->query("c_name")),
       ({ victim, ob1 }) );
                            
  tell_object( ob1,
       sprintf("\n\n���������ȷ��ľ�������%sһ���ɳ���\n\n",(string)victim->query("c_name")) );

  victim->block_attack(2);                          
  victim->set_temp("msg_stop_attack",
          "( ���ܵ�����ȷ���������һʱ�޷������� )\n)" );
  victim->receive_damage(damage);

  if (wizardp(ob1))
     printf("\n[ Receive_damage : %d ]\n\n",damage );
}

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) )
                    return 0;
           return 1;
}

string *attack_msg = ({
        "̤��һ����%s��%s��ȥ������ʮ��ǿ��",
        "ʹ��һ�С�ɨ��Ⱥħ����%s�ӵض�����ֱɨ%s",
        "�Ӷ�%s��һʱ�������������Ӱ͸��������%s",
        "���һ����%s�й�ֱ�룬�ȼ����һ�󾢷磬����%s",
        "˫�ֳ�%sʹ����ǿһʽ����շ�ħ������������ɽ����������ͷӿ��%s",
});

int *hits = ({ 30, 35, 30, 45, 50 });
int *pens = ({ 10, 22, 30, 40, 45 });
int *dams = ({ 7, 9, 12, 14, 17 });

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/king-kong");
	return ((hits[type-1] + random(lvl)/6)*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/king-kong");
	return  ((pens[type-1] + random(lvl)/6)*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/king-kong");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/king-kong", 3*type+random(2*type));
	if (random(350)<lvl) special_attack(me,victim);
	return ((dams[type-1]+lvl/3)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(5)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(5)];
}
