#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "scholar dagger", "ѧ��֮ذ" );
	add( "id", ({ "dagger" }) );
	set_short( "ѧ��֮ذ" );
	set_long(
                "����һ��ѧ��֮ذ�����������\��׭�ġ�\n" );
	set( "unit", "��" );
	set( "type", "dagger" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 100 );
	set( "weapon_class", 28 );
	set( "min_damage", 18 );
	set( "max_damage", 25 );
	set( "value", ({ 1500, "silver" }) );
}
/*
int weapon_hit( object victim, int damage )
{
	object owner;

	owner = environment();
	if( random(50)<20 ) {
		tell_object( owner, 
                "\n���ѧ��֮ذƮ��һ�ιŴ������﹥��"+victim->query("c_name")+"\n\n");
		tell_object( victim, 
                owner->query("c_name") + "��ѧ��֮ذƮ��һ�ιŴ������﹥���㡣\n");
		tell_room( environment(owner),
                        owner->query("c_name") + "��ѧ��֮ذƮ��һ�ιŴ������﹥��"+victim->query("c_name")+" !\n", ({victim, owner}) );
	victim->receive_special_damage( "energy", 20 );
	return 20;
	}
}
*/