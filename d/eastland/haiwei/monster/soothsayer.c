#include <mudlib.h>
#include <stats.h>
#include <races.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "soothsayer", "��������" );
	add( "id", ({ "sayer" }) );
	set_short( "��������" );
	set_long(@C_LONG
��λ����������Լ�ġ���ʮ�꣬������Ʋ���ֺ��ӣ�����������й�δ��
(future)���£�����ָ���Խ�
C_LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_natural_weapon( 3, 1, 5 );
	set_natural_armor( 6, 10 );
	set_perm_stat( "dex", 5 );
	set_perm_stat( "kar", 5 );
	set_skill( "dodge", 20 );
	set( "wealth/gold", 5 );
	set( "inquiry", ([
		"future" : 
			"��������ֻҪ��(pay)������ң��Ҿ��������㡣"
	]) );
}

void init()
{
	add_action( "do_fortell", "pay" );
}

int do_fortell(string arg)
{
	string who, type, race;
	int num, age;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
           return notify_fail( 
                   "��˭������Ǯ��\n" );
	if( !id(who ) ) return 0;
	if( type != "gold" ) {
           tell_room( environment(), 
               "��������˵��: �Բ�����ֻ�ս�ҡ�\n",
			this_object() );
		return 1;
	}
   if( !this_player()->debit(type, num) ) return notify_fail(
           "��û��������ҡ�\n" );
	if( num < 5 ) {
           write( 
              "���������������µش������㣬ҡһҡͷ����Ǯ�˻����㡣\n" );
		this_player()->credit(type, num);
		return 1;
	}
	if( this_player()->query_temp("payed_soothsayer") && num >= 1000 ) {
           tell_room( environment(), 
			"��������˵��: ����������Ե�ˣ�С��������ʶ���£������ϱ��������ĸ�����\n\n"
                   "��������˵��: С��ԸΪ���������������������١�\n" );
		this_player()->add("dead_count", -1);
		return 1;
	}
	race = this_player()->query("race");
	age = RACE_MASTER(race)->query_natural_life();
	age -= (int)this_player()->query("dead_count") * 2;
	age -= (int)this_player()->query("natural_age");
	age -= (int)this_player()->query_age() / 86400;
	if( age > 0 )
           tell_room( environment(), 
			"��������˵��: лл�����������Ƹ��ҡ�\n\n"
+ age + " �����٣�����Ϊ֮�ɡ�\n" );
   else tell_room( environment(), 
		"��������˵��: лл�����������Ƹ��ҡ�\n\n"
		"����������ϸ�ض�����һ�����Ȼ����������˵��: ���������Ѿ�����ǧ��\n"
           "    ���أ�����׹���ֻ��ܿࡣ\n" );
	if( num >=500 ) call_out( "my_special", 6, this_player() );
	return 1;
}

void my_special(object player)
{
	if( !present(player, environment()) ) return;
   tell_object(player, 
		"��������ѹ������˵��: ����������С������Ե�� .... �����������\n"
             "        �� 1000 ���ң�Ҳ��\ ....\n" );
	this_player()->set_temp("payed_soothsayer", 1 );
}
