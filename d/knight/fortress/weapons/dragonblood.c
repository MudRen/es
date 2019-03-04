#include <mudlib.h>

inherit WEAPON;

string C_NAME="[37;1m��Ѫǹ[37;0m";

void create()
{
	seteuid(getuid());
	set_name( "lance of dragonblood", C_NAME );
	add( "id", ({ "lance", "dragonblood" }) );
	set_short( "��ǹ������֮Ѫ��" );
	set_long(
		"��������ŵ����ʿһ�������룬�����ĳ�ǹ������֮Ѫ������ѳ�ǹ\n"
		"��˵��������ǰһ���������ػ��ı��أ�����˶��������ǹ���֮��\n"
		"����(Ariah)���͸��˼���ΰ����ʿ������ ����ѳ�ǹ��������������\n"
		"�޼᲻�ݵ������ܴ���ʹ��������ʿ������ҫ��\n"
	);
	set( "unit", "��" );
	set( "type", "jousting" );
	set( "weapon_class", 48 );
	set( "min_damage", 25 );
	set( "max_damage", 52 );
	set( "weight", 120 );
	set( "hit_func", "weapon_hit" );
	set( "value", ({ 5600, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit(object victim, int damage)
{
	if( (string)victim->query("race")!="dragon" ) return 0;
	victim->receive_special_damage( "magic", damage );

	return damage;
}



