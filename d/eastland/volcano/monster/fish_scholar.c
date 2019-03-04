#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "The Scholar", "�ĳ�" );
	add( "id", ({ "scholar" }) );
	set_short( "�ĳ�" );
	set_long(
		"�㿴��һλ�����׺��ӵ���ͷ����Ĺ��������������ѯ����\n"
	);
	set( "unit", "��" );
	set( "race", "monster" );
	set( "gender", "male" );
	set( "alignment",  800 );
        set( "likefish",1);
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set( "special_defense", ([ "all": 40, "none" : 20, ]) );
	set( "aim_difficulty", ([ "critical" : 35, "vascular" : 25, ]) );
	set_natural_armor( 53, 23 );
	set_natural_weapon( 5, 0, 10 );
	set( "wealth/gold", 10 );
	set( "tactic_func", "my_tactic" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "int", 28 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 23 );
	set_skill( "dodge", 90 );
        set("chat_chance",10);
        set("chat_output",({
         "�ĳ������������ü��������֪��������ʲ���¡�\n"
        }) );

	wield_weapon(OWEAPON"dagger03" );
	equip_armor( OARMOR"ring2" ); 
	equip_armor( OARMOR"cloth2" );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers()) ) return 0;
	if( random(20)>2 ) return 0;
	tell_room( environment(this_object()),
	  "�ĳ��������:������˳���������������һ�Ź�����\n"
          "�ĳ��������:�������˴���������ض���һ���С���\n"
	  "\nͻȻ�����ܵ�ˮ��ʼ���ٵ���ת����һ�����а�İ���������� !\n"
	, this_object()
	);
	for ( i=0; i < sizeof(victim) ; i++) {
	  victim[i]->receive_special_damage("divine", random(10));
          victim[i]->block_attack(5);
          victim[i]->set_temp("msg_stop_attack",
            "( �㱻ת�����ΰ��صģ�������ȫ���ܿ��� ! )\n");
        }
	return 1;
}
