#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "ghost of Harold", "����µĹ��" );
	add( "id", ({ "ghost", "harold" }) );
	set_short( "����µĹ��" );
	set_long(
		"�㿴��һ�������ǳ��������ʿ����������������˼��\n"
	);
   set( "race", "undead" );
	set( "gender", "male" );
	set( "alignment", 10 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 50 );
	set( "natural_armor_class", 30 );
	set( "natural_weapon_class1", 12 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 11 );
	set( "unbleeding",1);
	set( "tactic_func", "my_tactic" );
	set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "alt_corpse", "/d/noden/house/obj/cellar_key" );
	set_c_verbs( ({"%s����ץ��%s"}) );
	set( "inquiry", ([
		"key" : "Կ�ף�ʲ��Կ�� .... ��û��Կ�� .... " 
	]) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers() ) || random(20)>5 ) return 0;
	tell_room( environment(this_object()), 
		"����Ӱ�ӱ��ģ����Ȼ���������������Ķ��ߴ���....\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "mental", 20 );
	return 1;
}

void die()
{
	tell_room( environment(this_object()), 
		query("c_cap_name") + "��Ӱ�ӻ���һ�ɰ��̣���ʧ�� .... ������ĳ���������ڵذ��ϡ�\n",
		this_object() );
	::die(1);
}

