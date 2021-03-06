inherit "/d/martial/attack/modify";

void special_attack(object ob1,object victim)

// 拈花指的特攻为点穴, 原出现皆为 block_attack(4), 今更动为
// block_attack(lv/8 + random(lv/16)) 。
// 从最少 block_attack(0) 到 最多 block_attack(6)
// 与 keep_flower lv 成正相关....

{
    int lv,block_round;
        if ( ! ob1->query_attackers() || ! victim ) {
                return ;
	}

tell_object( victim,
 (string)ob1->query("c_name")+"使出『拈花指』点了你的穴道！\n\n");

tell_room( environment(ob1), 
 "\n\n"+(string)ob1->query("c_name")+"突然运气一指，点住了" + (string)victim->query("c_name") + "的穴道！\n",
({ victim, ob1 }) );

lv = ob1->query("monk_gonfu/keep-flower");
block_round = lv/8 + random(lv/16);
if (block_round < 2) return;
victim->block_attack(block_round);
victim->set_temp("msg_stop_attack", 
"( 你的穴道被点,一时之间无法动弹...... )\n" );

write(
"\n\n你的拈花指一弹，点住了" + (string)victim->query("c_name") +"的穴道！\n\n" );

    if( wizardp(ob1) )
       printf("\n[ Block_attack : %d ]\n",block_round);
}

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type, i, lvl;
	string last;

	if( weapon || undefinedp(lvl=(int)me->query("monk_gonfu/keep-flower")) )
		return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "keep-flower1"  : type = 1;  break;
			case "keep-flower2"  : type = 2;  break;
			case "keep-flower3"  : type = 3;  break;
			case "keep-flower4"  : type = 4;  break;
			case "keep-flower5"  : type = 5;  break;
			case "keep-flower6"  : type = 6;  break;
		 	case "keep-flower7"  : type = 7;  break;
			case "keep-flower8"  : type = 8;  break;
			default            : type = 0;  break;
		}
	i = type * 10 + lvl * 4 + 1;
	if( type > 0 && type < 8 && random(i) > type * 10 ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("keep-flower"+type));
	return type;
}

string *attack_msg = ({
	"%s手指点向%s", 
	"%s一指『静极便觉』弹向%s",
	"%s脸露微笑，一点指力飞向%s",
	"%s双眉微蹙，一记捻花指绝学『诸幻尽灭』使出，大股指力卷向%s",
	"%s神色温和，一招『无始无名』使出，一道指力攻向%s",   
	"%s态度平和自得，一记『花落莲成』，几点内劲击向%s",
	"%s双目微闭，一股强劲指力攻向%s",
	"%s运气於指，使出最强的『圆悟涅盘』一连三指挟强劲内力袭向%s",
});

int *hits = ({  90, 96, 99, 152, 122, 139, 140, 184 });
int *pens = ({  78, 90, 108, 154, 100, 118, 144, 185 });
int *dams = ({  27, 30, 30, 38, 39, 40, 49, 60 });
// 机率:        1  .9  .75 .58 .41 .27 .17 .10   type*10+lvl(max 25)*4 
// 期望值:      27  30  32  34  36  37  39  41  

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
        int lv;
        lv = me->query("monk_gonfu/keep-flower");
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
   	me->add("gonfus_exp/keep-flower", 3*type+1+random(type*2));
        if (random(350)<lv) special_attack(me,victim); 
	return (dams[type-1]*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 8 ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[type-1]+"但是出手时显得内力不足"; 
	return attack_msg[type-1];
}
