#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "drunk", "��" );
	set_short( "��" );
	set_long(
		"һ������Ƴ�����������ʧ���ʵ������ӣ���֪�����⵽ʲ�᲻��\n"
		"�����Ըʶ��䡣����׷����·�����Ҵ򣬺���ȫ������˶��Բ������Ƶġ�\n"
	);
		set("aggressive",1);
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
		set_skill( "parry", 60 );
		set_skill("blunt",60);
		set( "gender", "male" );
		set( "race", "orc" );
		set( "alignment", -400 );
        set_natural_armor( 46, 18 );
        set_natural_weapon( -7,1,4);
                        	
		equip_armor( Obj"coat" );
		wield_weapon(Obj"club");
}
