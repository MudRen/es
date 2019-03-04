//#pragma save_binary

// Estimate command
// By Annihilator@Eastern.Stories

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int cmd_consider(string arg)
{
	int my_power, dest_power, diff;
	int alignment, ethics_skill;
	object dest, me;

	if( this_player()->query("stop_attack") > 0 )
		return notify_fail( 
			"( �㻹û�������һ���������޷������κι�� )\n");

	if( !arg || arg=="" )
		return notify_fail( 
			"ָ���ʽ: consider <������>\n");

	if( !dest= present( arg, environment(this_player()) ) )
		return notify_fail(
			"����û�����ֹ��\n");

	me = this_player();
	me->calc_weapon_class();
	my_power = ((int)me->query("weapon_class1") - (int)dest->query_stat("dex"))*3 + 50;
	if( my_power < 5 ) my_power = 5;
	if( my_power > 95 ) my_power = 95;
	my_power *= (((int)me->query("min_damage1") + (int)me->query("max_damage1"))/2
		- (int)dest->query("defense_bonus"));
		
	dest->calc_weapon_class();
	dest_power = ((int)dest->query("weapon_class1") - (int)me->query_stat("dex"))*3 + 50;
	if( dest_power < 5 ) dest_power = 5;
	if( dest_power > 95 ) dest_power = 95;
	dest_power *= (((int)dest->query("min_damage1") + (int)dest->query("max_damage1"))/2
		- (int)me->query("defense_bonus"));
	
	// Make bias with skill	
	my_power += 1000 * random(100-(int)me->query_skill("consider")) / 100;
	dest_power -= 1000 * random(100-(int)me->query_skill("consider")) / 100;

	diff = my_power - dest_power;
	if( diff < -3000 ) write( 
	    "����һ����ĳλ��ʦ��ϷŪ�㣬����ʮ��19����playerҲ�Ų�ס��һ�¹�����\n");
	else if( diff < -2000 ) write( 
		"��ɵ�ˣ�������һ�����ϵĻ�����һ�غ��ڱ�ɱ��\n");
	else if( diff < -1000 ) write( 
		"����㴩��ȫ����õĿ��ף��ֳ�ϡ�����������һ��ѻָ�ҩ����Ҳ��\....\n");
	else if( diff < -500 ) write( 
		"��Ӯ�Ļ���ܵͣ��Է��ĸ�������������ǿ�ܶࡣ\n");
	else if( diff < -200 ) write( 
		"���ֶ�������Ŀǰ���������ԣ��ƺ��е���ǿ��\n");
	else if( diff < -50 ) write( 
		"��������������Ҫ��Ӯ�����ĵ��˲����Ǻ��ѡ�\n");
	else if( diff < 50 ) write(
		"�Է������ǰ�����������൱��\n");
	else if( diff < 200 ) write( 
		"ֻҪ�㲻��ʲ���©�������ĵ��˺ܺöԸ���\n");
	else if( diff < 500 ) write( 
		"�Է��ĸ����������Ȳ����㣬���ص��ġ�\n");
	else if( diff < 1000 ) write(
		"���ֵ��˶�����ԣ���ȫ�������κ���в��\n");
	else if( diff < 2000 ) write(
		"����������������غ��ڰ���һ�ɵ���\n");
	else write( 
		"��ʵ˵���۸�������С����ʵ�����˷�ʱ�䡣\n");

	if( ethics_skill =me->query_skill("ethics") ) {
		alignment = (int)dest->query("alignment") 
			- random((100-ethics_skill)*20) + (100-ethics_skill) * 10;
		write(
			"����Ϊ���Ǹ���" + STATS_D->alignment_string(alignment) + "��֮���Ķ��֡�\n");
	}
	return 1;
}

int help()
{
	write( @HELP
ʹ�ø�ʽ: consider <��������>

���ָ��ж������ǿ����׼ȷ�̶��ܼ���Ӱ��.
�������������ܵȼ��ߣ������������׼ȷ��.
HELP
	);
	return 1;
}
