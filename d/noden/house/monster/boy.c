#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "little boy", "С�к�" );
	add( "id", ({ "boy" }) );
	set_short( "С�к�" );
	set_long(
		"���С�к��к�ɫ������ͺ�ɫ��ͷ��������������������죬������¶��\n"
		"���µ�����\n"
	);
	set_skill( "dodge", 10 );
   set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 1000 );
	set( "alt_corpse", "/d/noden/house/monster/devil" );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"С�к�˵��: ��������Ϸ����\n",
		"С�к�����ش������㡣\n",
		"С�к����ض�����΢Ц��\n"
	}) );
	set( "inquiry", ([
		"name" : "��....û�����֣��ְ��������ҳ�����ʱ�������....\n" 
	]) );
}

void die()
{
	tell_room( environment(this_object()), 
		"С�к��ȳ�������Ѫ�����ڵ��� ....\n\n"
		"������һ��ɳ�Ƶ�������С�к���ʬ�巢��: ������Ϊ���������������룡��\n\n"
		"С�к���ʬ����վ��������\n\n" ,
		this_object() );
	::die(1);
}
