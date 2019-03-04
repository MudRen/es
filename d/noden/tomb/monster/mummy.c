#include <mudlib.h>

inherit "/std/teacher";
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "mummy", "ľ����" );
   set_short( "ľ����" );
	set_long(
		"�㿴��һ��ȫ����������ļһ������������������������������\n"
		"�����ӣ���Ϊ�����ſ�˫�֣�������Ĳ��ӣ�"
	);
   set( "race", "undead" );
	set_perm_stat( "str", 20 );
	set( "max_hp", 200 );
	set( "hit_points", 200 );
	set( "natural_defense_bonus", 18 );
	set( "natural_weapon_class1", 17 );
	set( "natural_min_damage1", 9 );
	set( "natural_max_damage1", 24 );
	set( "alignment", -1000 );
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "tactic_func", "my_tactic" );
	set( "wealth/gold", 30 );

	set( "unit", "ֻ" );
	set_c_verbs( ({ "%s��ָ����������ץ��%s", "%s������Ŷ����һ�����ֱ�ͻȻ�䳤����%sץȥ",
		"%s�ս�ȭͷ��Ӳ���ض���%s�ӳ�һȭ" }) );
	set_lessons( ([
           "bandage": ({ 100, 60 })
	]) );
   set( "alt_corpse", "/d/noden/tomb/obj/mummy" );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<13 || !(victim = query_attackers()) ) return 0;
    tell_room( environment(),
            "ľ����������ѽ�ֽУ�ʹ��е�һ���޷����ܵĿֲ���\n" );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->run_away();
	return 1;
}

int check_trainee(object trainee)
{
   if( !present("spider ankh", trainee) )
   return notify_fail(
         "�����ҵ����\n" );
	if( (string)trainee->query("class")=="adventurer" 
	&& (int)trainee->query_level() > 4 )
		return 1;
	else
             return notify_fail( 
                    "ľ����˵��: ��ֻ�̹��ʸ��ð���ߣ�����������ϣ�\n" );
}

void init()
{
   teacher::init();
   npc::init();
}
