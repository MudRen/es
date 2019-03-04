#include <mudlib.h>
inherit DAEMON;

int help();
make_hurt(object me, object target, object weapon);
int result(object me,object target,object weapon,int succeed);
/* return value : 
   0 : ʧ��
   1 : һ��
   2 ���� : special 
 */
int check_throw(object me,object target)
{
	int level,lv,kar,rate,skill,dex,rtn;

	skill = (int)me->query_skill("throw-dagger");
	if ( skill <= 0 ) 
		return 0;
	kar=(int)me->query_stat("kar")-(int)target->query_stat("kar");
	dex=(int)me->query_stat("dex")-(int)target->query_stat("dex");
	lv = (int)me->query("thief_level/throw-dagger");
	level = skill/5 - (int) target->query_level();
	rate = skill+lv*7+level*5+(kar+dex+dex)*2; 
	if ( rate > 600 ) rate = 600;
	if ( wizardp(me) )
		tell_object(me,"rate : " + rate + "/ 605 \n");
   	if ( rate > random(605) ) {
	    switch( random( (int)me->query("thief_level/throw-dagger")*10 ) ) {
		case 0..360 :
			rtn = 1;
			break;
		case 361..430 :
			rtn = 2;
			break;
		//	return 2;
		case 431..480 :
			rtn = 3;
			break;
		//	return 3;
		case 481..495 :
			rtn = 4;
			break;
		//	return 4;
		case 496..500 :
			rtn = 5;
			break;
		//	return 5;
	    } /* end of switch */
   	 } else {
		rtn = 0;
//   		return 0;
	}
	if ( wizardp(me) )
		tell_object(me,"rtn : " + rtn + "\n");
	return rtn;
}

calc_exp(object me,int dam)
{
	if ( dam )
		me->add("thief_exp/throw-dagger",dam/2);
	else {
		int i ;
		i = (int) me->query_skill("throw-dagger")/5 + 
		    (int) me->query("thief_level/throw-dagger");
		me->add("thief_exp/throw-dagger",random(i));
	}
}

int cmd_throw(string arg)
{
	string tmp1,tmp2;
	object me,target,weapon,env;

	me = this_player();
	if ( (int)me->query_temp("throwing") == 1 )
		return notify_fail("�����ϵķɵ���û���ȥ����ʲ�ᡣ\n");
	if ( ! arg ) return notify_fail("��ҪͶ��ʲ��?\n");
	if ( sscanf( arg,"%s at %s",tmp1,tmp2) != 2 ) return 0;
	if ( ! target = present(tmp2,(env=environment(me))))
		return notify_fail("����û�н�"+tmp2+"�����\n");
	if ( ! living(target) )
		return notify_fail("����û�н�"+tmp2+"�����\n");
	if ( ! (weapon = present(tmp1,me)) )
		return notify_fail("��û�д�����"+tmp1+"�Ķ�����\n");
	if ( target == me )
		return notify_fail("�㲻��ƴsuicide��?\n");
	if ( target->query("no_attack") )
		return notify_fail("�㲻�ܹ�������\n");
// ������ invisible �� player
	if(!visible(target,me)||target->query("invisible_player") ) 
		return notify_fail("����û�н�"+tmp2+"�����\n");
	if ( weapon && ( (string )weapon->query("type") != "dagger" || weapon->query("prevent_drop") || weapon->query("wielded") || weapon->query("equipped")))
		return notify_fail("����������ܵ��ɵ�..\n");

	me->set_temp("throwing",1);
	tell_object( me,sprintf("�㰵������һ%s%s, �ȴ��ʵ��Ļ���..\n",weapon->query("unit"),weapon->query("c_name")) );
	call_out("result",1,me,target,weapon,check_throw(this_player(),target) );

	return 1;
}

int result(object me,object target,object weapon,int succeed)
{
	object env;
	int dam=0;
	string message;
	me->set_temp("throwing",0);
	env = environment(me);
	if ( ! target || nullp(target) || target->query("hit_points") < 1 ) {
		write("�Ǽһ��Ѿ����ˡ�\n");
		return 1;
	}
	if ( !present(target,env) ) {
		write(sprintf("%s�Ѿ�������!!\n",target->query("c_name")));
		return 1;
	}
/*
	switch (succeed){
	    case 1 :
	    case 2 :
	    case 3 :
	    case 4 :
	    case 5 :
	    default :
		message = "%s����һ"+weapon->query("unit")+weapon->query("c_name")+", �ݵ�һ������%s, ���%s!!\n";
		tell_room(env,set_color(
		  sprintf(message,me->query("c_name"),target->query("c_name"),"û��"),"HIY",me),({me,target}));
		tell_object(target,set_color(
		  sprintf(message,me->query("c_name"),"��","����������"),"HIR",target));

		tell_object(me,
		sprintf(message,"��",target->query("c_name"),"û��"));
		weapon->move(env);
	}
*/

	if ( succeed ) {
		tell_room( environment(me),
		set_color(sprintf("\n%s����һ%s%s, �ݵ�һ��������%s!!\n",
		me->query("c_name"),weapon->query("unit"),weapon->query("c_name"),target->query("c_name")),"HIY"),
		({me,target}),
		);
		tell_object(target,sprintf("%s �������, ����ò���!! \n",me->query("c_name")) );
		tell_object(me,sprintf("%sһ��������, ������İ���!\n",target->query("c_name")));
		dam=make_hurt(this_player(),target,weapon);
		weapon->move(target);
	} else {
		tell_room(env,
		set_color(sprintf("%s����һ%s%s, �ݵ�һ������%s, ���û��.\n",
		me->query("c_name"),weapon->query("unit"),weapon->query("c_name"),target->query("c_name")),"HIY"),
		({me,target})
		);
		tell_object(target,sprintf("%s���һ�ѷɵ�, ������������ˡ�\n",me->query("c_name")));
		tell_object(me,
		sprintf("�����һ�ѷɵ�, �����%s������! %s���ڵ���...\n",target->query("c_name"),weapon->query("c_name")) );
		weapon->move(env);
	}


	if ( ! target->query_attackers() || member_array(me,target->query_attackers()) == -1 ) {
		tell_object(me,
		sprintf("%s���� : %s�����С��, Ҫ�ҵ��������ð� !\n",target->query("c_name"),me->query("c_name")));
	}
	target->kill_ob(me);
	calc_exp(me,dam);
}

make_hurt(object me, object target, object weapon)
{
	int dam,max,min,wc,ac;
	string msg;
	int exp;
	target->set("last_attacker",me);
	wc = weapon->query("weapon_class");
    	if ( wc ) {
		max = (int)weapon->query("max_damage");
		min = (int)weapon->query("min_damage");
		ac = (int)target->query("armor_class");
		dam = min + random(max - min);
		dam = dam - ac/6; 
		if ( dam <=0 ) 
			dam = random(min)+1;
		target->receive_damage(dam);
		me->gain_experience( dam+dam );
		if ( wizardp(me)) 
			tell_object(me,"dam = "+dam+ " exp = "+exp+"\n");	
     		msg = "/adm/daemons/statsd"->status_string(target) ;
		tell_object(target,sprintf("( ��%s )\n",msg));
		tell_object(me,sprintf("( %s%s )\n",target->query("c_name"),msg));
    	} else { /* ���� */
	}
	return dam;
}

int help()
{
	write (@HELP
Usage: throw <weapon> at <target>

��ɵ��������һ��С�����������˲�С�ĵ�ʱ�������б����ˣ�
���ַɵ��ĺô���������һ������ȡ�ã����������\�������Ի��գ�
��Ȼ�Ǵӵ��˵ġ����ϰλ������ɵ������൱Ȼ��ذ��������ɵ�
������
HELP
);
	return 1;
}

