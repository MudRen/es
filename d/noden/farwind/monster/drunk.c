#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(2);
	set_name( "drunk", "��" );
   set_short( "��" );
	set_long(
		"You see a smelly drunk. He looks sad and down.\n",
		"һ������Ƴ�ζ����������ʧ���ʵ������ӣ���֪�����⵽ʲ�᲻��\n"
		"�����Ըʶ��䡣\n"
	);
	set_perm_stat( "str", 3 );
	set_skill( "dodge", 10 );
	set( "gender", "male" );
	set( "race", "human" );

	set( "alignment", -100 );
	
	ob1 = new( "/d/noden/farwind/items/coat" );
	ob1->move( this_object() );
	equip_armor( ob1 );
	
	ob2 = new( "/d/noden/farwind/items/bottle" );
	ob2->move( this_object() );
}
