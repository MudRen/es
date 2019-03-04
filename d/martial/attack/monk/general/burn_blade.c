// ��������ʮ��������ȼľ������
inherit "/d/martial/attack/modify";
void special_attack(object ob1, object victim)
{
  int damage;
  damage = ob1->query("monk_gonfu/burn-blade") + (ob1->query("min_damage1")+ob1->query("max_damage1"))/2 ;

  if ( !ob1->query_attackers() || !victim )
        return ;
  tell_object( victim,
       sprintf("%s����ǿ�ҵĵ���������û������¶������˻�һ�㡣\n\n",(string)ob1->query("c_name")) );
                           
  tell_room( environment(ob1),
       sprintf("\n\n%sɢ�����ȵĵ�����ʹ%s����Χ����һƬ�𺣡�\n\n",(string)ob1->query("c_name"),(string)victim->query("c_name")),
       ({ victim, ob1 }) );
                            
  tell_object( ob1,
       sprintf("\n\n�㳤Хһ������עǿ��������������ȵĵ�����ʹ%s�ܵ�ǿ�ҵ����ˣ�\n\n",(string)victim->query("c_name")) );
                            
  victim->receive_special_damage("fire",damage );

  if (wizardp(ob1))
     printf("\n[ Receive_damage : %d ]\n\n",damage);
}

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( !weapon || (string)weapon->query("type") != "longblade" ) return 0;
	return 1;
}

string *attack_msg = ({
        "��%s��%s��ȥ������������͸��һ�����ȵ���Ϣ",
        "ʹ��ȼľ�����С�Ұ����ԭ��������%s����%s",
        "����΢�࣬����%s����ǿ������ȵ���б��%s",
        "ʹ�����ɡ����졻������%sɢ�����쵶������%s",
        "���۹�\�������һ�����ơ�������%s�����������%s",
});

int *hits = ({ 35, 40, 45, 50, 55 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 8, 11, 14, 17, 20 });

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/burn-blade");
	return ((hits[type-1] + random(lvl)/6)*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/burn-blade");
	return  (lvl*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/burn-blade");
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/burn-blade", 3*type+random(2*type));
        if (random(350)<lvl) special_attack(me,victim);
	return  ((dams[type-1]+lvl/3)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(5)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(5)];
}
