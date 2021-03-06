inherit "/d/martial/attack/modify";

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type, i, lvl;
	string last;

	if( weapon || undefinedp(lvl=(int)me->query("monk_gonfu/power-finger")) )
		return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "power-finger1"  : type = 1;  break;
			case "power-finger2"  : type = 2;  break;
			case "power-finger3"  : type = 3;  break;
			case "power-finger4"  : type = 4;  break;
			case "power-finger5"  : type = 5;  break;
			case "power-finger6"  : type = 6;  break;
			case "power-finger7"  : type = 7;  break;
			case "power-finger8"  : type = 8;  break;
			default            : type = 0;  break;
		}
	i = type * 10 + lvl * 4 + 1;
	if( type > 0 && type < 8 && random(i) > type * 15 ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("power-finger"+type));
	return type;
}

string *attack_msg = ({
		"%s力贯指尖，一指向%s点去", 
		"%s回身凝神，一记『力贯长虹』缓缓卷向%s",
		"%s侧劈一掌，划出一招『金刚伏虎』，攻向%s",
		"%s意守丹田，右手『飞鸿扬翼』气势恢宏，击向%s",
		"%s踏出右脚，双指自上而下攻出，一招『箭指连环』快速攻向%s",   
		"%s双目圆睁，一股强劲指力涌向%s，乃是『金刚怒目』",
		"%s仰天大喝一声，劈出『巨浪涛天』大股内劲卷向%s",
		"%s气贯全身，使出终极一式『金刚破魔』一大股内劲奔涌攻向%s",
});


int *hits = ({  75, 80, 96, 132, 92, 104,  95, 154 });
int *pens = ({  49, 88, 60, 115, 80,  85,  98, 130 });
int *dams = ({  27, 33, 34, 43, 40, 44, 50, 63 });
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
	return ((pens[type-1] + random((int)me->query("monk_gonfu/power-finger")/2))*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int lv;
        lv = me->query("monk_gonfu/power-finger");
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
   	me->add("gonfus_exp/power-finger", 3*type+1+random(2 * type));
        if (random(350)<lv) { 
           me->add("force_points", query_need_fp());
           this_player() -> continue_attack();   
           tell_object( me, set_color("你长啸一声，金刚指力发动首次进击! \n","HIR") ); 
        if (random(180)<lv) { 
           me->add("force_points", query_need_fp());
           this_player() -> continue_attack();   
           tell_object( me, set_color("你长啸一声，金刚指力发动再次进击! \n","HIR") );  
                            }  
                            }
	return (dams[type-1]*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 8 ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[type-1]+"惟出手时显得内力不足"; 
	return attack_msg[type-1];
}
