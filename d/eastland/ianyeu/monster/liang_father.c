#include "../mad.h"

inherit MONSTER;

void create()
{
   object key;

	::create();
   set_level(5);
   set_name( "poor scholar", "��������" );
   add( "id", ({ "scholar" }) );
   set_short( "��������" );
	set_long(
        "һ�������������������������, ����һ�����ڽ����������.\n"
	);
   set( "gender", "male" );
	set( "race", "human" );
   set( "alignment", -50 );
   set_perm_stat( "dex", 8 );
   set_skill( "dodge", 50 );
   set( "natural_weapon_class1", 15 );
   set( "natural_min_damage1", 12 );
   set( "natural_max_damage1", 30 );
   set( "wealth/copper", 10 );
   set( "chat_chance", 12 );
   set( "chat_output", ({
        "������������������һ����, Ȼ��һ������.\n",
        "������������: �����Ů�ֳ���, ��������˲�֪;\n"
        "              ����ë����ãã, Ī����������ɫ.\n"
	}) );
   set( "inquiry", ([
        "daughter" : "��..........\n",
     ]) );

   key = new( IANOBJ"key" );
   key->move(this_object());
}
