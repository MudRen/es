//#pragma save_binary
#define RATE ({ 5,20,32,41,47,50,53,59,68,80,95, })

#include <mudlib.h>

inherit DAEMON;
/*
void announce( string msg )
{
    object *usr;
    int i;
    usr = users();
    i = sizeof(usr);
    for( --i ; i >= 0; i-- ) {
    	if( !environment(usr[i]) ) continue;
        tell_object( usr[i], set_color(msg, "HIR", usr[i]) );
	}
}
*/
void remove_block(object me)
{
	me->delete_temp("block_command");
	return;
}

int steal_idle(object me,int succeed,object target,object item)
{
	mapping wealth;
	string type,*coins;
	int coin,i;
	me->set_temp("stealed",0);
	if ( !target || nullp(target) || (int)target->query("hit_points") < 1 ) {
		write("�治�ң��Ǽһ��Ѿ����� ...\n");
		return 1;
	}
	if ( !present(target,environment(me)) ) {
		write("��Ҫ͵�Ķ����Ѿ����������� !!\n");
		return 1;
	}
	tell_object(me,set_color(
		sprintf("����%s�������ʱ����С�ĵİѵ���ֻ������%s ...\n",
			target->query("c_name"),
			( !item ? target->query("c_name") : item->query("c_name")) )
			,"HIY") );
	
	if ( ! succeed ) {
	tell_object(me,set_color(
		sprintf("%sͻȻת��ͷ�ݺݵص�����һ�ۣ��޷޵��������� ...\n",
			target->query("c_name")),"HIM") );
	tell_object(target,set_color(
		sprintf("��ͻȻ�е��ֵֹģ�ԭ����%s����������ı������������� ..\n"
			,me->query("c_name")),"HIY") );
// announce ̫���ˣ���ˬ�����Լ����� :P)
/*
	if ( target->query("user") )
		announce(sprintf("%s(%s)�� : С͵ !! С͵ !! %s(%s)��С͵ !!!\n",
					target->query("c_name"),capitalize(target->query("name")),
					me->query("c_name"),capitalize(me->query("name"))) );
*/
	if ((int)target->query_level() > 5 ) {
		target->kill_ob(me);
		me->kill_ob(target);
        me->block_attack(4);
        me->set_temp("block_command",1);
        me->set_temp("msg_stop_attack",
       		"( ��ѽ ! ͵�����������ˣ���һ����æ���ң� )\n" );
       	call_out("remove_block",3,me);
		}
	} else {
		if ( item ) {
			if ( !item->move(me))
				tell_object(me,set_color("�ǺǺ� ... ������ ...\n","HIY"));
			else
				tell_object(me,set_color("�� .. ̫���ˣ��ò��� ...\n","HIC"));
		} else {
		if ( !wealth = target->query("wealth") ) {
			tell_object(me,"��Ŭ����������Ǯ�������� ... ������һëǮ���Ҳ��� ...\n");
			return 1;
		}
		coins = keys(wealth);
		type = coins[random(sizeof(coins))];
		coin = ( wealth[type] > 100 ? 100 - random(10) : random(wealth[type]+1) );
		if ( coin ) {
			tell_object(me,set_color("�� ! �̵��� ... ������ ... ��ݺݵ�����һ���Ǯ�� ...\n","HIY"));
			me->add("wealth/"+type,coin);
			target->add("wealth/"+type,-coin);
		} else
			tell_object(me,"� ~~ ���������ˣ���Ͽ������������û͵����ëǮ ...\n");
		}
	}
	return 1;
}
int check_steal(object me,object target)
{
	int level,iq,dex,kar,rate1,rate2;

	if ( target->query("no_steal") ) return 0;
//	level = (int)this_player()->query_level()*2-(int)target->query_level();
	iq = (int)me->query_stat("int")-(int)target->query_stat("int");
	dex = (int)me->query_stat("dex")-(int)target->query_stat("dex");
	kar = (int)me->query_stat("kar")-(int)target->query_stat("kar");
/*
	rate1 = level*level/8+kar+kar+dex+dex+iq;
   	rate1 = rate1*(int)me->query_skill("steal")/100;
   	rate1 = ( rate1 > 93 ? 93 : rate1 ) ;
	rate2 = level*level/6+kar+dex+iq;
   	rate2 = (rate2 + (int)me->query_skill("peep"))/2;
   	rate2 = ( rate2 > 93 ? 93 : rate2 ) ;
*/
	level = (int)me->query_skill("peep")/5 - (int)target->query_level() +5;
	level = ( level < 0 ? 0 : level);
	level = ( level > 10 ? 10 : level );
	rate1 = RATE[level] + iq + iq + dex + kar ;
	if ( random(120) > rate1 ) return 0;
	level = (int)me->query_skill("steal")/5 - (int)target->query_level() +5;
	level = ( level < 0 ? 0 : level);
	level = ( level > 10 ? 10 : level );
	rate1 = RATE[level] + iq + dex + dex + kar ;
	if ( random(120) > rate1 ) return 0;
	return 1;
/*
   	if ( (random(100) < rate1) && (random(100) < rate2 ))
   		return 1;
   	else
   		return 0;
*/
}
int help();
int cmd_steal(string arg)
{
	string tmp1,tmp2;
	object target,item;

	if ( this_player()->query_temp("stealed") )
		return notify_fail("��ֻ����ֻ�֣����ҵ���ֻ�Ѿ����ȥ�� ...\n");
	if ( ! arg )
		return notify_fail("��Ҫ͵˭�Ķ�����\n");

	if ( sscanf( arg,"%s from %s",tmp1,tmp2) != 2 ) return help();
		if ( ! target = present(tmp2,environment(this_player()) ) )
			return notify_fail("����û�н�"+tmp2+"�����\n");
		if ( ! living(target) )
			return notify_fail("����û�н�"+tmp2+"�����\n");
		if ( tmp1 != "money" && ! item = present(tmp1,target ) )
			return notify_fail(target->query("c_name")+"û�д�����"+tmp1+"�Ķ�����\n");

	if ( target == this_player() )
		return notify_fail("͵�Լ��Ķ�����ʲ�ᰡ?\n");
// Ԥ������͵����ʧ�ܹ��� no_attack mob
	if ( target->query("no_attack") )
		return notify_fail("�㲻��͵���Ķ�����\n");
// ����͵ invisible �� player
	if ( !visible(target,this_player()) || target->query("invisible_player") ) 
		return notify_fail("���뱳��˭��\n");

	if ( wizardp(target) ) {
		write("��������͵�Ϳ๦\�ߵ���ʦ�أ�..*puke*\n");
		return 1;
	}

	if ( item && (item->query("prevent_drop") || item->query("wielded") ||
			item->query("equipped")) ) 
	return notify_fail("��ɵ�� !! ���������͵���ߵ� ...\n");
	write(set_color(sprintf("�㿪ʼ���۽ǵ��Ź�͵͵����%s��һ��һ�� ...\n",
			target->query("c_name") ),"HIY"));
	this_player()->set_temp("stealed",1);
	call_out("steal_idle",5+random(4),this_player(),
			check_steal(this_player(),target),target,item );
	return 1;
}

int help()
{
	write (@HELP
Usage: steal <object> from <target>
	   steal money from <target>

���ָ����ʹ���ڱ��˺���֪���������͵����û��װ������Ʒ����Ǯ����
��������Ĵ��ӡ�������"��"���˵Ķ���֮ǰ����������ȹ۲�۲�ĺ�ϰ
�ߣ����������Ǻ����ױ����ֵġ�

HELP
);
	return 1;
}
