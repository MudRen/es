#include "../mad.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(8);
   set_name( "satyr", "ɫ��" );
   set_short( "ɫ��" );
	set_long(
          "�����һ����Ŀ���, һ������ļһ�, ��������а���Ц����\n" );
   set_perm_stat( "str", 12 );
   set_perm_stat( "int", 10 );
   set_perm_stat( "dex", 15 );
   set_perm_stat( "kar", 15 );
   set( "max_hp", 350 );
   set( "hit_points", 350 );
   set_skill( "dodge", 80 );
	set( "killer", 1 );
   set( "race", "daemon" );
	set( "gender", "male" );
   set( "alignment", -500 );
	set( "natural_armor_class", 40 );
   set( "natural_defense_bonus", 20 );
   set( "natural_weapon_class1", 20 );
   set( "natural_min_damage1", 8 );
   set( "natural_max_damage1", 15 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
           "ɫ��˵��: �ٺٺ� .... ���Ȼ�������ң��ͱ��������\n",
           "ɫ������¶��а���Ц�ݡ�\n",
	}) );
}

int my_tactic()
{
   object victim;

   if( random(20)>3 || !(victim=query_attacker()) ) return 0;
   if( victim->query("stop_attack") ) return 0;
   tell_object( victim,
          "ɫ���૵�������������ģ�������徹Ȼʯ����!\n",
        );
   victim->block_attack(6+random(4));
   victim->set_temp("msg_stop_attack", 
        "( ����Ŭ�������ͻ��ʯ��������, �޷������� )\n" );
   return 1;
}

void die()
{
   object heart;
   heart = new( IANOBJ"heart" );

   heart->move(this_object());
   ::die(1);
}
