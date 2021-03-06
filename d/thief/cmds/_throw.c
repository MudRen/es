

//
// Created by Aquarius@EasternStory
// 
// can throw multi dagger, aim not finish
//
#include <mudlib.h>
inherit DAEMON;

int help();
int NumberOfDagger(object ob);
make_hurt(object me, object target, object weapon);

/* ************************************************
   return value : 
   0 : 失败
   1 : 一般
   2 以上 : special 
   必须确定 return value 小於身上带的 dagger

skill level  0..10 can throw max 1 dagger
       11..20		    1 dagger + aim g rate++
       21..35		    2 dagger + aim g rate++
       36..45		    3 dagger + aim g rate++
       46..48		    4 dagger + aim g rate++
       49..50		    5 dagger + aim g rate++
*/
// depend on skill
int attack_type(object me)
{
	int lv,rate,type = 0,aim_rate = -1,tmp;

	// rate = skill + 2*lv ; max= 100+100=200
	rate = (int)me->query_skill("throw-dagger");
	if ( rate <= 0 ) 
		return 0;
	lv = (int)me->query("thief_level/throw-dagger");
	rate += lv*2;
   	if ( random(rate) < rate/3 ) 
		return 0; 

	switch( (tmp = random( lv*10 )) ) {
		case 483..499 : 
			type++;
			aim_rate++;
		case 453..472 :
			type++;
			aim_rate++;
		case 343..452 :
			type++;
			aim_rate++;
		case 193..342 :
			type++;
			aim_rate++;
		case 93..192 :
			aim_rate++;
		case 0..92 :
			type++;
	    } /* end of switch */
	if ( wizardp(me) )
		tell_object(me,"可以射出" +type+"飞刀\ntmp:"+tmp+"\n");
/*
	tmp = NumberOfDagger(me);
	type = ( type > tmp ) ? tmp : type;
*/
	return type;
}

int NumberOfDagger(object ob)
{
	int i,num;
	object *inv;
	inv = all_inventory(ob);
	for (num=0,i=sizeof(inv)-1; i >= 0; i--) {
	    // the name of obj is "dagger" && can throw
 	    if ( (string) inv[i]->query("type") == "dagger" && 
		! (inv[i]->query("prevent_drop") || inv[i]->query("wielded") || inv[i]->query("equipped")) )
		num++;	
	}
	return num;
}

// depend on target dex & dodge
int hit(object me,object target)
{
	int rate1,rate2;
	// rate1 max 304
	rate1 = (int) me->query_skill("throw-dagger")*5/2;
	rate1 += (int) me->query_stat("dex")*2;

	if ( wizardp(me) )
	tell_object(me,"rate1 = "+rate1+"\n");
	// rate2 max 150
	rate2 = (int) target->query_stat("dex")*2;
	rate2 += (int) target->query_skill("dodge")/2;
	rate2 += (int) target->query_level()*3/2;
	rate2 += 10;
	if ( random(rate1) > rate2 )
		return 1;
	else 
		return 0;
#if 0
	int dex,rate;
	dex = me->query_stat("dex") - target->query_stat("dex");
	rate = (int)me->query_skill("throw-dagger")*2.5 - (int)target->query_skill("dodge");	
	rate += dex*5;
	return ( rate > random(150) );
#endif
}

// skip dagger which has been wielded, secured, etc 
object find_next_dagger(object who)
{
	int i;
	object *inv;
	inv = all_inventory(who);
	for ( i = sizeof(inv)-1; i >=0; i-- ) 
 	    if ( (string) inv[i]->query("type") == "dagger" && 
		! ( inv[i]->query("prevent_drop") || inv[i]->query("wielded") || inv[i]->query("equipped") || inv[i]->query("secure") ) )
		return inv[i];
	return 0;
}

calc_exp(object me,int dam)
{
	if ( dam )
		me->add("thief_exp/throw-dagger",dam/3);
	else 
		me->add("thief_exp/throw-dagger",1);
}

int cmd_throw(string arg)
{
	string tmp1,tmp2;
	object me,target,weapon,env;

	me = this_player();
	if ( (int)me->query_temp("throwing") == 1 )
		return notify_fail("你手上的飞刀还没射出去，急什麽。\n");
	if ( ! arg ) return notify_fail("你要投掷什麽?\n");
	if ( sscanf( arg,"%s at %s",tmp1,tmp2) != 2 ) return 0;
	if ( ! target = present(tmp2,(env=environment(me))))
		return notify_fail("这里没有叫"+tmp2+"的生物。\n");
	if ( ! living(target) )
		return notify_fail("这里没有叫"+tmp2+"的生物。\n");
	if ( ! (weapon = present(tmp1,me)) )
		return notify_fail("你没有带著叫"+tmp1+"的东东。\n");
	if ( target == me )
		return notify_fail("你不会拼suicide吗?\n");
	if ( target->query("no_attack") )
		return notify_fail("你不能攻击他。\n");
// 不能射 invisible 的 player
	if(!visible(target,me)||target->query("invisible_player") ) 
		return notify_fail("这里没有叫"+tmp2+"的生物。\n");
	if ( weapon && ( (string )weapon->query("type") != "dagger" || weapon->query("prevent_drop") || weapon->query("wielded") || weapon->query("equipped")))
		return notify_fail("这件东西不能当飞刀..\n");

	me->set_temp("throwing",1);
	tell_object( me,sprintf("你暗中拿了一%s%s, 等待适当的机会..\n",weapon->query("unit"),weapon->query("c_name")) );
	call_out("result",1,me,target,weapon,attack_type(this_player()) );

	return 1;
}


result(object me,object target,object weapon,int type)
{
	// 只能有五招, 不然就要改 attack_type

	string *mm = ({ "",
		"%s摸出一把飞刀, 咻的一声射向%s!!\n",
		"%s射出两把飞刀, 直取%s双目!!\n",
		"%s的飞刀分作三路飞向%s!!\n",
		"%s连续射出四把飞刀,封住%s的全部退路!!\n",
		"%s一招满天花雨, 许多飞刀向%s飞去!!\n",
		});
	object env,dagger;
	int i,dam=0,aim;
	string msg;

	env = environment(me);
	if ( ! target || nullp(target) || target->query("hit_points") < 1 ) {
		write("那家伙已经死了。\n");
		me->set_temp("throwing",0);
		return 1;
	}
	if ( !present(target,env) ) {
		write(sprintf("%s已经溜走了!!\n",target->query("c_name")));
		me->set_temp("throwing",0);
		return 1;
	}

	if ( type != 0 )  {
	    tell_room(env,set_color(sprintf(mm[type],me->query("c_name"),target->query("c_name")),"HIY",me),({me,target}));
	    tell_object(target,set_color(sprintf(mm[type],me->query("c_name"),"你"),"HIR",target));
	    tell_object(me,set_color(sprintf(mm[type],"你",target->query("c_name")),"HIR",me));

	} else {
	    msg = "%s摸出一把飞刀, 咻的一声射向%s, 结果没中!!\n",
	    tell_room(env,set_color(sprintf(msg,me->query("c_name"),target->query("c_name")),"HIY",me),({me,target}));
	    tell_object(target,set_color(sprintf(msg,me->query("c_name"),"你"),"HIR",target));
	    tell_object(me,set_color(sprintf(msg,"你",target->query("c_name")),"HIR",me));
	}

	dagger = weapon;
        for ( dam = 0,i=1;objectp(dagger) && i <= type; i++,aim--){
/*
		if ( aim > 0)
			aim_target(me,target);
*/
		if ( hit(me,target) ){
                         if ( (dagger->move(target)) == 0 )
				dam += make_hurt(me,target,dagger);
			if ( ! target->query_attackers() || member_array(me,target->query_attackers()) == -1 ) 
			tell_room(env,
				sprintf("%s喊道 : %s你这个小人, 要我的命就来拿吧 !\n",target->query("c_name"),me->query("c_name")));
			target->kill_ob(me);
		} else {
			dagger->move(env);
			if ( random(me->query_stat("kar")*3) < target->query_stat("dex")){
			tell_room(env,
				sprintf("%s喊道 : %s你这个小人, 要我的命就来拿吧 !\n",target->query("c_name"),me->query("c_name")));
			target->kill_ob(me);
			}
		}
		dagger = find_next_dagger(me);
	}
	if ( type== 0)
		dagger->move(env);
	calc_exp(me,dam);
	me->set_temp("throwing",0);
}

make_hurt(object me, object target, object weapon)
{
	int dam,max,min,wc,db;
	string msg;
	if ( ! target ) return 0;
	if ( ! weapon) return 0;
	target->set("last_attacker",me);
	wc = weapon->query("weapon_class");
    	if ( wc ) {
		max = (int)weapon->query("max_damage");
		min = (int)weapon->query("min_damage");
		db = (int)target->query("defense_bonus");
		dam = min + random(max - min);
		dam = dam - db/10; 
		if ( dam <=0 ) 
			dam = random(min)+1;
		target->receive_damage(dam);
		me->gain_experience(dam);
		if ( wizardp(me)) 
			tell_object(me,"dam = "+dam+" \n");	
     		msg = "/adm/daemons/statsd"->status_string(target) ;
		tell_object(target,sprintf("( 你%s )\n",msg));
		tell_object(me,sprintf("( %s%s )\n",target->query("c_name"),msg));
    	} else { /* 毒刀 */
	}
	return dam;
}

int help()
{
	write (@HELP
Usage: throw <weapon> at <target>

射飞刀就是射出一把小刀，趁著敌人不小心的时候让他中标受伤，
这种飞刀的好处有两个，一来容易取得，二来如果成\功还可以回收，
当然是从敌人的□体上拔回来。飞刀的种类当然是匕首类等轻巧的
武器。
HELP
);
	return 1;
}

