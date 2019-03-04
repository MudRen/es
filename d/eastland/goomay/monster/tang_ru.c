
#include <../goomay.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("tang ru", "����");
	add( "id", ({ "ru","tang" }) );
	set_short("����");
	set_long(
"������Զ���Ĵ�������÷�����СŮ���� �����ֻ��ʮ�塢��������ӣ�\n"+
"ʮ�ֻ��ÿɰ������ƺ����ٳ��ţ���һ���˿������ĵ��Ĵ���������...\n"  
	);
        set("race","human");
        set("gender","female");	
        set("wealth",(["silver":50])); 
        set( "unit", "λ" );
	set( "alignment", 200 );
	set_natural_armor( 35, 14 );
	set_natural_weapon( 11, 8, 17 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "dex", 9 );
	set_skill("dodge",35);
	set( "pursuing", 1 );
	set( "tactic_func", "emit_poison" );
	equip_armor(Obj"tang_ring");
} 

int emit_poison()
{
	object victim;

	if( random(25)>6 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
"���罿Ц�� �����������Ĵ����ŵ�����!!!��\n"
"����һ������ǰͻȻ����һ�ŷۺ�ɫ������, ��е�һ����ѣ��\n\n" 
 , 	 
	this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 7, 7 );
	return 1;
}
