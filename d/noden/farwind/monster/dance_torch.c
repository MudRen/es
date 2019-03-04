#include "../farwind.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(1);
	set_name( "dancing torcher", "�����Ļ��" );
	add( "id", ({ "torcher" }) );
	set_short("�����Ļ��");
	set_long(@CLONG
����һ�����صĻ�ѣ����ǰ���³˹����ʱ�������еõ�����Ʒ,
�ľ����Ե����Ѿ����˰���³˹�ĳ����ˡ�
CLONG
               );
   set( "race", "undead" );
	set_natural_armor( 10, 7 );
	set_natural_weapon( 10, 2, 7 );
	set( "unbleeding", 1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
    set( "alt_corpse", "/obj/torch" );
    set_c_verbs(({ "%s��ͷ�ϵĻ�����%s", "%s������ײ%s" }));
    set_c_limbs(({ "����", "ͷ��" }));
    set("c_death_msg","%sͻȻ�������������ڵ���... �����ˡ�\n");
	set("moving", 1 );
	set("speed", 30 );
	set("patrol", ({ "north", "south", "west", "west", "east", "east",
		"south", "north" }) );
	set_perm_stat( "str", 3 );
	set_perm_stat( "dex", 4 );
	set_skill( "dodge", 40 );
	set( "special_defense", ([ "all": 20 ]) );
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
}

int stop_attack()
{
   object master, *tmp;

   master = present( "ebbruce", environment() );
   if( !master ) return 0;
   tell_room( environment(),
          "����³˹�ȵ�: �����۸��ҵĳ���! ��Ҫ����?\n" );
   tmp = query_temp( "protectors" );
   if( !tmp || member_array( master, tmp )==-1 ) {
        add_temp( "protectors", ({ master }) );
        master->add_temp( "protectees", ({ this_object() }) );
        }
        tmp = master->query_attackers();
   if( !tmp || member_array( this_player(), tmp )==-1 )
         master->kill_ob( this_player() );
}
