#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey mother", "������" );
   add( "id", ({ "guey", "mother" }) );
   set_short( "������" );
	set_long(
        "�㿴��һλ��Լ��ʮ�����긾��, �����ϵذ���̾��, ��֪Ϊ������.\n"
	);
   set( "gender", "female" );
	set( "race", "human" );
   set_perm_stat( "dex", 8 );
   set_skill( "dodge", 50 );
   set( "natural_weapon_class1", 15 );
   set( "natural_min_damage1", 12 );
   set( "natural_max_damage1", 25 );
   set( "wealth/copper", 10 );
   set( "chat_chance", 12 );
   set( "chat_output", ({
        "������̾��: �ҿ�����Ů��, ��������Ķ�������?\n",
        "����������: �ϵ�(dad)�ֳ�ȥ��!\n"
	}) );
   set( "inquiry", ([
        "sheaumei" : "��..........\n",
        "daughter" : "��..........\n",
        "dad" : "�ϵ������ȥŮ���ķ�ǰ��.\n"
     ]) );
}
