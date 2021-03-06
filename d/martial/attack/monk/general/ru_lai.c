inherit "/d/martial/attack/modify";

void special_attack(object ob1, object victim)
{

  if ( !ob1->query_attackers() || !victim ) {
		return ;
	}
tell_object( victim, can_read_chinese(victim) ?
 (string)ob1->query("c_cap_name")+"使出『般若掌』的奥妙招数，一道诡异的内力震得你口吐鲜血！\n\n":
 (string)ob1->query("cap_name")+" stun you with konfu, you feel harm !\n" );

tell_room( environment(ob1), ({
 (string)ob1->query("cap_name")+" stun " + (string)victim->query("cap_name") + " by gunfu.\n",
 "\n\n"+(string)ob1->query("c_cap_name")+"突然长啸一声，拍出一道雄浑的内力把" + (string)victim->query("c_cap_name") + "打得口吐鲜血！\n"}),
({ victim, ob1 }) );

write( can_read_chinese() ?
"\n\n你长啸一声，趁机发出般若掌的绝招，强大的掌力把" + (string)victim->query("c_cap_name") +"打得鲜血狂喷！\n\n" :
"\n\nYou stun your emeny by bolo-fist ! \n\n");

victim->receive_damage( 5+(int)ob1->query("monk_gonfu/bolo-fist") );

}


int query_need_fp()
{ 
    return 7;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type, i, lvl;
	string last;

	if( weapon || undefinedp(lvl=(int)me->query("monk_gonfu/ru-lai")) )
		return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "ru1"  : type = 1;  break;
			case "ru2"  : type = 2;  break;
			case "ru3"  : type = 3;  break;
			case "ru4"  : type = 4;  break;
			case "ru5"  : type = 5;  break;
			case "ru6"  : type = 6;  break;
		 	case "ru7"  : type = 7;  break;
			case "ru8"  : type = 8;  break;
			default            : type = 0;  break;
		}
	i = type * 10 + lvl * 4 + 1;
	if( type > 0 && type < 8 && random(i) > type * 10 ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("ru"+type));
	return type;
}

string *attack_msg = ({
	"%s右手一掌攻向%s，使出第一招『佛光初现』", 
	"%s双手合十攻出，第二招『金顶佛灯』击向%s",
	"%s身形飞快前进，第三招『佛动山河』挟两道内劲劈向%s",
	"%s全身笼罩在真气之中，第四招『佛光普照』使出，大股内劲卷向%s",
	"%s神情平静详和，左掌凝聚内息，使出第五式『佛问迦叶』攻向%s",   
	"%s突然连劈数掌，一股逼人的劲力冲向%s，正是第六招『迎佛西天』",
	"%s凝神拍出一掌，气势恢宏，劲道威猛，击向%s",
	"%s使出最强一式『万佛朝宗』，但见风云变色日月无光，千百道真气涌向%s",
});

int *hits = ({  100, 90, 96, 142, 100, 140,  99, 194 });
int *pens = ({  78,  98, 80, 140, 120,  98,  144, 190 });
int *dams = ({  30, 35, 38, 55, 45, 55, 65, 80 });
// 机率:        1  .9  .75 .58 .41 .27 .17 .10   type*10+lvl(max 25)*4 

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (hits[type-1]*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon,int type)
{
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (pens[type-1]*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
   	me->add("gonfus_exp/ru-lai", 3*type+1+random(2*type));
//        if (random(37)<2) special_attack(me,victim); 
	return (dams[type-1]*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 8 ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[type-1]+"但是出手时显得内力不足"; 
	return attack_msg[type-1];
}
