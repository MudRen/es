#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(6);
   set_name( "liang mother", "��ĸ" );
   add( "id", ({ "liang", "mother" }) );
   set_short( "��ĸ" );
	set_long(@C_LONG
һλ��Լ��ʮ�����긾Ů������ע����ʱ, ���Ծ��������㲻���ø�,
���������̸�����š�
C_LONG
	);
	set( "race", "human" );
   set( "gender", "female" );
   set( "alignment", 350 );
   set_perm_stat( "str", 10 );
   set_perm_stat( "dex", 10 );
   set_perm_stat( "kar", 5 );
   set_skill( "dodge", 40 );
   set( "wealth/copper", 50 );
	set_natural_weapon( 8, 8, 8 );
   set_natural_armor( 40, 8 );

   set( "chat_chance", 15 );
   set( "chat_output", ({
        "��ĸ��: ��������! ������.\n"
        }) );
}
