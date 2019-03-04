#include <mudlib.h>

inherit MONSTER;

void create()
{
	object obj1;

	::create();
	set_level(4);
	set_name( "Jeff", "�ܷ�" );
	set( "id", ({ "jeff", "sailor" }) );
   set_short( "��ˮ�ֽܷ�" );
	set_long(
		"�Ͻܷ������ʱ��������һ��ǿ׳�¸ҵ�ˮ�֣������������Ѿ�������\n"
		"������Ҳû�а취�����ˡ�\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 250 );

	set_perm_stat( "str", 6 );
	set( "wealth/silver", 20 );
	set( "max_hp", 150 );
	set( "hit_points", 150 );
	set( "wimpy", 80 );
	set( "tactic", "flank" );
	
	set_skill("dodge",30);
	set_skill("tactic",30);

	set_natural_armor( 23, 8 );
	set_natural_weapon( 5, 3, 8 );

	wield_weapon( "/d/noden/bluesand/item/stick" );
}

void die()
{
    tell_room( environment(),
		"�ܷ������Ѫ�����ڵ��ϡ�\n"
		"�ܷ�����૵������: �� ... ���� .... һ���Ḷ ... �����۵ģ�\n"
		"�ܷ�ӿڴ���ȡ��һ����ֵ��̻��ò������ֵ�ȼ�̻�������С�\n"
            "�����ͷ��ȥ���ܷ򣬷������Ѿ�һ��Ҳ���� .... ���ˡ�\n",
		this_object() );
	"/adm/daemons/event/pirate"->start_war();
	::die(1);
}
