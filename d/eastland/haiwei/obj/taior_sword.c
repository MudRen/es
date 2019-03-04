#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Sword of Taior", "̫��֮��" );
	add( "id", ({ "taior", "sword" }) );
	set_short( "̫��֮��" );
	set_long(
	"����һ��������������ɫ������������ĹŽ��������Ͽ����ĸ�׭�֡�̫���񽣡���\n" 
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 100 );
	set( "weapon_class", 44 );
	set( "min_damage", 28 );
	set( "max_damage", 46 );
	set( "value", ({ 3250, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>=15 && sp > 20 ) {
		tell_object( owner, 
			"\n���̫��֮��ͻȻ����һ������ɫ�Ļ��⣬����������һ�����ɫ��\n\n"
			);
		tell_room( environment(owner), 
			"\n" + owner->query("c_name") + "��̫��֮��ͻȻ����һ������ɫ�Ļ��⣬����������һ�����ɫ��\n\n",
			owner );
		victim->receive_special_damage( "divine", intelligence * 3);
		owner->add( "spell_points", -20 );
		return intelligence * 3;
	}
}

int stop_wield( object player )
{
	if( (int)player->query("alignment") < 2000 ) {
		notify_fail( 
			"̫��֮���ƺ�����һ��������ʹ���޷���Ԧ����\n");
		return 1;
	}
	if( (int)player->query_skill("longblade") < 100 ) {
		notify_fail( 
			"̫��֮���ƺ�����һ��������ʹ���޷���Ԧ����\n");
		return 1;
	}
	return 0;
}
