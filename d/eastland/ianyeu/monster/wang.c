#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "wang wuu", "����" );
   add( "id", ({ "wang", "wuu" }) );
   set_short( "����" );
	set_long(
        "һλ��Լ��ʮ, �����������ʵ���������.\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
   set_perm_stat( "dex", 8 );
   set_skill( "dodge", 50 );
   set( "natural_weapon_class1", 15 );
   set( "natural_min_damage1", 12 );
   set( "natural_max_damage1", 25 );
   set( "wealth/copper", 1 );
   set( "chat_chance", 12 );
   set( "chat_output", ({
        "����̾��: �ɻ���(burglar)�ֻ�����! ��֪���Ǽҹ���Ҫ�ܺ���!\n",
        "��������: �Һ�����δȢ��.\n"
	}) );
   set( "inquiry", ([
        "burglar" : "���������������, ��ȥ�������˼Ұ�!\n"
     ]) );
}
