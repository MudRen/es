// 少林寺七十二绝技「燃木刀法」
inherit "/d/martial/attack/modify";
void special_attack(object ob1, object victim)
{
  int damage;
  damage = ob1->query("monk_gonfu/burn-blade") + (ob1->query("min_damage1")+ob1->query("max_damage1"))/2 ;

  if ( !ob1->query_attackers() || !victim )
        return ;
  tell_object( victim,
       sprintf("%s发出强烈的刀气，你觉得浑身上下都像著了火一般。\n\n",(string)ob1->query("c_name")) );
                           
  tell_room( environment(ob1),
       sprintf("\n\n%s散出炙热的刀气，使%s的周围陷入一片火海。\n\n",(string)ob1->query("c_name"),(string)victim->query("c_name")),
       ({ victim, ob1 }) );
                            
  tell_object( ob1,
       sprintf("\n\n你长啸一声，灌注强大的内力产生炙热的刀气，使%s受到强烈地灼伤！\n\n",(string)victim->query("c_name")) );
                            
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
        "用%s向%s砍去，刀劲中隐隐透出一股炙热的气息",
        "使出燃木刀法中『野火燎原』，赤红的%s砍向%s",
        "身形微侧，手上%s带著强大的炙热刀气斜劈%s",
        "使出『飞□满天』，手中%s散出满天刀气攻向%s",
        "凝聚功\力，大喝一声『破』，手中%s如火龙般劈向%s",
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
        return attack_msg[random(5)]+"但是出手时显得内力不足";
        return attack_msg[random(5)];
}
