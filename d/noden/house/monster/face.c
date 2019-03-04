#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "ghostly face", "����" );
	add( "id", ({ "face" }) );
	set_short("����" );
	set_long(
		"�㿴��һ�Ź��Ȱ����������ǽ���ϣ���������а���Ц����\n"
	);
   set( "race", "undead" );
	set( "gender", "female" );
	set( "alignment", -300 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 30 );
	set("unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "my_tactic" );
	set( "wealth/silver", 70 );
	set_c_verbs( ({"%s�ӿ��������һֻ�֣�ץ��%s", "%s����һ�����Ľ�������%sһײ"}) );
	set_c_limbs( ({ "����", "�۾�", "����" }) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers() ) || random(20)>5 ) return 0;
	tell_room( environment(this_object()), 
		"����ͻȻ����ſ�����Ѫ���ڣ�����һ����̶��ļ������\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "mental", 15 );
	return 1;
}

