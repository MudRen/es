// 少林寺七十二绝技「金刚杖法」
inherit "/d/martial/attack/modify";

void special_attack(object ob1, object victim)
{
  int damage;
  damage = ob1->query("monk_gonfu/king-kong") + (ob1->query("min_damage1")+ob1->query("max_damage1"))/2 ;

  if ( !ob1->query_attackers() || !victim )
       return ;
  tell_object( victim,
       sprintf("%s大喝一声，露出金刚法像，对你重重一击，令你疼痛难当\n\n",(string)ob1->query("c_name")) );
                           
  tell_room( environment(ob1),
       sprintf("\n\n%s大喝一声，露出金刚法像，镇摄当场，横杖一挥将%s击得摇摇晃晃，站不住脚。\n\n",(string)ob1->query("c_name"),(string)victim->query("c_name")),
       ({ victim, ob1 }) );
                            
  tell_object( ob1,
       sprintf("\n\n你运起金刚杖法的绝技，将%s一击飞出。\n\n",(string)victim->query("c_name")) );

  victim->block_attack(2);                          
  victim->set_temp("msg_stop_attack",
          "( 你受到金刚杖法的震汤，一时无法动弹！ )\n)" );
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
        "踏上一步，%s向%s击去，劲势十分强劲",
        "使出一招『扫荡群魔』，%s掠地而出，直扫%s",
        "挥动%s，一时尘土飞扬，三道杖影透出，扑向%s",
        "大喝一声，%s中宫直入，杖尖带著一阵劲风，攻向%s",
        "双手持%s使出最强一式『金刚伏魔』，内力如排山倒海般自杖头涌向%s",
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
        return attack_msg[random(5)]+"但是出手时显得内力不足";
        return attack_msg[random(5)];
}
